#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "input.h"

int opcionMenu(void){
    int opcion;
    int todoOk = 0;
    system("cls");
    printf("    ***ABM Empleados***\n\n");
    printf(" 1)Alta de Empleado\n");
    printf(" 2)Modificar Empleado\n");
    printf(" 3)Baja de Empleado\n");
    printf(" 4)Informar\n");
    printf(" 5)Salir\n");

    printf(" Ingresar opcion : ");

    do{
        fflush(stdin);
        scanf("%d", &opcion);
        if(opcion < 0 || opcion > 5){
              printf("Error! Ingreser opcion : ");
            todoOk = 1;
        }
        else{
            todoOk = 0;
        }

    }while(todoOk == 1);

    return opcion;
}

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len)
{
    int retorno = -1;

    if(list != NULL && len > 0){

        for(int i=0; i<len; i++){
               (list+i)->isEmpty = 0;
        }

        retorno = 0;
    }

return retorno;
}

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/

int addEmployee(Employee* list, int len, int id, char name[], char lastName[],float salary,int sector)
{
    int retorno=-1;
    int indice;



    if(list != NULL && len >= 0){

        indice = buscarLibre(list, len);

        if(indice >= 0){

            list[indice].id = indice+1;

            strcpy(list[indice].name, name);

            strcpy(list[indice].lastName, lastName);

            list[indice].salary = salary;

            list[indice].sector = sector;

            list[indice].isEmpty = 1;

        }
        else{
            printf("\n    NO HAY ESPACIO");
            retorno =0;
        }


    }

return retorno;
}

int buscarLibre(Employee* list, int len){

    int indice =-1;

    for(int i=0; i<len; i++){

        if((list+i)->isEmpty == 0){
            indice = i;
            break;
        }
    }

    return indice;
}

int altaEmpleado(Employee* list, int len){

    int retorno = -1;
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;

    if(list != NULL && len > 0){
        id = buscarLibre(list, len);

        if(id >= 0){
                system("cls");
            printf("        *** Alta Empleado ***\n");
            if(utn_getString(name, "\nIngresar nombre: ", "Error! Ingresar Nombre: ", 1, 51) == 0){
                if(utn_getString(lastName, "\nIngresar Apellido: ", "Error! Ingresar Apellido: ", 1, 51)==0){
                    if(utn_getFloat(&salary, "\nIngresar Salario: ", "Error! Ingresar Salario: ",1, 100000 )==0){
                        if(utn_getInt(&sector, "\nIngresar Sector: ", "Error! Ingresar Sector. ", 1, 100)==0){

                            addEmployee(list, len, id, name, lastName, salary, sector);
                                retorno=0;
                        }
                    }
                }
            }
        }
    }



return retorno;
}

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*/

int findEmployeeById(Employee* list, int len,int id)
{
    int retorno = -1;

    for(int i=0; i<len; i++){

        if(id == list[i].id){
            mostrarEmpleado(list[i]);
            retorno=0;
            break;
        }

    }

    return retorno;// retorno 0 si encuentra -1 no existe
}

void mostrarEmpleado(Employee empleado){

    printf("\n  %d       %7s            %7s        %.2f       %4d ", empleado.id, empleado.name, empleado.lastName, empleado.salary, empleado.sector);
}

/*void listarEmpleados(Employee* empleado, int len){
printf("id, name, lasname, salary, sector\n\n");
    for(int i=0; i<len; i++){
        if(empleado[i].isEmpty == 1){
            mostrarEmpleado(empleado[i]);
        }

    }
}*/

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id)
{
    int retorno = -1;

     for(int i=0; i<len; i++){

        if(id == list[i].id){

            list[i].isEmpty = 0;
            retorno=0;
            break;
        }

    }

    return retorno;
}

int bajaEmpelado(Employee* list, int len){

    int retorno=-1;
    int id;
    char opcion;
        system("cls");

        if(utn_getInt(&id, "Ingrese ID del Empleado: ", "Error! Ingrese ID del Empleado: ", 0, 1000)==0){

            for(int i=0; i<=len; i++){

            if(id == list[i].id && list[i].isEmpty == 1 ){

                printf("ID       NOMBRE         APELLIDO       SUELDO   SECTOR");
                mostrarEmpleado(list[i]);
                    utn_getChar(&opcion, "\n\n Desea eliminar este empleado? [S/N]: ", "Error!\n Desea eliminar este empleado? [S/N]: ", 1, 2);

                if(opcion=='s'){
                    removeEmployee(list, len, id);
                    retorno=0;

                }
                break;
            }
            else if(i == len){
            printf("\n      NO EXISTE EMPLEADO CON ESA ID\n\n");
            }

        }



    }
    return retorno;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order)
{
    int retorno =-1;
    Employee aux;

    for(int i=0; i<len-1; i++){
        for(int j=i+1; j<len; j++){
            if(order == 1){//Mayor a menor

            if((list[i].sector > list[j].sector) && (strcmp(list[i].name, list[j].name) )>0){

                aux = list[i];
                list[i] = list[j];
                list[j] = aux;
            }

            }
            else if(order == 0){//Menor a mayor

                if((list[i].sector < list[j].sector) && (strcmp(list[i].name, list[j].name) )<0){

                aux = list[i];
                list[i] = list[j];
                list[j] = aux;
            }
            }

        }
    }


    return retorno;
}

int sortEmployeesSector(Employee* list, int len, int order)
{
    int retorno =-1;
    Employee aux;

    for(int i=0; i<len-1; i++){
        for(int j=i+1; j<len; j++){
            if(order == 1){//Mayor a menor
                if(list[i].sector < list[j].sector) {

                aux = list[i];
                list[i] = list[j];
                list[j] = aux;
            }

            }
            else if(order == 0){//Menor a mayor

                if(list[i].sector > list[j].sector){

                aux = list[i];
                list[i] = list[j];
                list[j] = aux;
            }
            }

        }
    }


    return retorno;
}


/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee* list, int length)
{
    int retorno=-1;
    //printf("id, name, lasname, salary, sector\n\n");
    printf("  ID       NOMBRE         APELLIDO       SUELDO         SECTOR");
    for(int i=0; i<length; i++){
        if(list[i].isEmpty == 1){
            mostrarEmpleado(list[i]);
        }

    }

    retorno=0;
return retorno;
}


int modificarEmpleado(Employee* list, int len){

    int retorno=-1;
    int id;
    char option;
        system("cls");

        if(utn_getInt(&id, "Ingrese ID del Empleado: ", "Error! Ingrese ID del Empleado: ", 0, 1000)==0){

            for(int i=0; i<=len; i++){

            if(id == list[i].id && list[i].isEmpty == 1 ){

            do{
                    system("cls");
                  printf("  ID       NOMBRE         APELLIDO       SUELDO   SECTOR");
                    mostrarEmpleado(list[i]);
            switch(option= opcionMenuModificar())
            {
                case 1:
                    cambiarNombre(&list[i]);
                    system("pause");
                    break;
                case 2:
                    cambiarApellido(&list[i]);
                    system("pause");
                    break;
                case 3:
                    cambiarSueldo(&list[i]);
                    system("pause");
                    break;
                case 4:
                    cambiarSector(&list[i]);
                    system("pause");
                    break;
            }

        }while(option != 5);

        }
        else if(i == len){
                    printf("\n      NO EXISTE EMPLEADO CON ESA ID\n\n");
            }
    }


}

return retorno;
}
int opcionMenuModificar(void){
    int opcion;
    int todoOk = 0;

    printf("\n\n 1)Modificar Nombre\n");
    printf(" 2)Modificar Apellido\n");
    printf(" 3)Modificar Sueldo\n");
    printf(" 4)Modificar sector\n");
    printf(" 5)Salir\n");

    printf(" Ingresar opcion : ");

    do{
        fflush(stdin);
        scanf("%d", &opcion);
        if(opcion < 0 || opcion > 5){
              printf("Error! Ingreser opcion : ");
            todoOk = 1;
        }
        else{
            todoOk = 0;
        }

    }while(todoOk == 1);

    return opcion;
}

void cambiarNombre(Employee* empleado){
    char nombreNuevo[51];
    if((utn_getString(nombreNuevo, "\nIngresar Nuevo nombre: ", "Error! Ingresar Nuevo nombre: ", 1, 51))==0){

            strcpy(empleado->name, nombreNuevo);
            printf("\n      NOMBRE CAMBIAMDO CON EXITO\n\n");
    }
    else{
        printf("\n      ERROR\n\n");
    }

}

void cambiarApellido(Employee* empleado){
    char apellidoNuevo[51];
    if((utn_getString(apellidoNuevo, "\nIngresar Nuevo Apellido: ", "Error! Ingresar Nuevo Apellido: ", 1, 51))==0){

            strcpy(empleado->lastName, apellidoNuevo);
            printf("\n      APELLIDO CAMBIAMDO CON EXITO\n\n");
    }
    else{
        printf("\n      ERROR\n\n");
    }

}

void cambiarSueldo(Employee* empleado){
    int sueldoNuevo;
    if((utn_getInt(&sueldoNuevo, "\nIngresar Nuevo Sueldo: ", "Error! Ingresar Nuevo Sueldo: ", 1, 100000))==0){

            empleado->salary = sueldoNuevo;
            printf("\n      SUELDO CAMBIAMDO CON EXITO\n\n");
    }
    else{
        printf("\n      ERROR\n\n");
    }

}


void cambiarSector(Employee* empleado){
    int sectorNuevo;
    if((utn_getInt(&sectorNuevo, "\nIngresar Nuevo Sector: ", "Error! Ingresar Nuevo Sector: ", 1, 100))==0){

            empleado->sector = sectorNuevo;
            printf("\n      SECTOR CAMBIAMDO CON EXITO\n\n");
    }
    else{
        printf("\n      ERROR\n\n");
    }

}

int funcionInformar(Employee* list, int len){
    int retorno=-1;
    int option;
    do{
            system("cls");
            switch(option= opcionMenuInformar())
            {
                case 1:
                    sortEmployeesSector(list, len, 0);
                    sortEmployees(list, len, 0);

                    printEmployees(list, len);
                    printf("\n\n");
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    printf("Total y promedio de los salarios: %d\n\n", promedioSueldo(list, len));
                    noSuperaElSalario(list, len);
                    printf("\n\n");
                    system("pause");
                    break;
            }

        }while(option != 3);

        retorno=0;
    return retorno;
}

int opcionMenuInformar(void){
    int opcion;
    int todoOk = 0;

    printf("        ***Informes***");
    printf("\n 1)Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n");
    printf(" 2)Total y promedio de los salarios, y empleados superan el salario promedio.\n");
    printf(" 3)Salir\n");

    printf(" Ingresar opcion : ");

    do{
        fflush(stdin);
        scanf("%d", &opcion);
        if(opcion < 0 || opcion > 3){
              printf("Error! Ingreser opcion : ");
            todoOk = 1;
        }
        else{
            todoOk = 0;
        }

    }while(todoOk == 1);

    return opcion;
}

int promedioSueldo(Employee* list, int len){

    int promedio=0;
    int contador=0;

    for(int i=0; i<len; i++){

        if(list[i].isEmpty == 1){
           promedio += list[i].salary;
           contador++;
        }

    }

    promedio = promedio/contador;

    return promedio;
}

void noSuperaElSalario(Employee* list, int len){
    int promedio;
    promedio = promedioSueldo(list, len);
        printf("Empleados que Superan el promedio de sueldo: \n");
        for(int i=0; i<len; i++){
            if(promedio < list[i].salary && list[i].isEmpty==1){
            mostrarEmpleado(list[i]);
        }
    }


}

void cargaDeDatos(Employee *list,int len)
{
    int id[5]= {100,101,102,103,104};
    char name[5][51]= {"Juan","Jorge","Carlos","Marta","Hernan"};
    char lastName[5][51]= {"Carabajal","Ramirez","Gonzales","Arce","Aquino"};
    float salary[5]= {20000,30000,40000,51000,10000};
    int sector[5]= {1,1,2,2,3};

    int i;
    for(i=0; i<5; i++)
    {
        list[i].id = id[i];
        strcpy(list[i].name, name[i]);
        strcpy(list[i].lastName, lastName[i]);
        list[i].salary = salary[i];
        list[i].sector = sector[i];
        list[i].isEmpty = 1;
    }
}
