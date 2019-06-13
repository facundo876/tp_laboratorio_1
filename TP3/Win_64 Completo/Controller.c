#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "input.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f;
    int rta;

    f = fopen(path, "r");
    if(f == NULL){
        printf("\n      NO SE PUEDO ABRIR EL ARCHIVO\n\n\n");
        return 1;
    }

    //parseo
    rta = parser_EmployeeFromText(f, pArrayListEmployee);

    fclose(f);

    return rta;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* f;
    int rta;

    f = fopen(path, "rb");
    if(f == NULL){
        printf("\n      NO SE PUEDO ABRIR EL ARCHIVO\n\n\n");
        return 1;
    }

    //parseo
    rta = parser_EmployeeFromBinary(f, pArrayListEmployee);

    fclose(f);

    return rta;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int rta=0;
    Employee* nuevoEmpleado;
    char buffer[4][20];
    int id;
    char nombre[128];
    int horasTrabajadas;
    float sueldo;
    //pedir id
    if((utn_getInt(&id, "Ingresar ID: ", "Error! Ingrese ID: ", 1, 10000))==0 ){
        if((utn_getString(nombre, "Ingresar Nombre: ", "Error! Ingresar Nombre: ", 1, 128))==0 ){
            if((utn_getInt(&horasTrabajadas, "Ingresar Horas trabajadas: ", "Error! Ingresar Horas Trabajadas: ", 1, 100))==0 ){
                if((utn_getFloat(&sueldo, "Ingresar Sueldo: ", "Error! Ingresar Sueldo: ", 1, 100000))==0){

                    sprintf(buffer[0], "%d", id);
                    sprintf(buffer[1], "%d", horasTrabajadas);
                    sprintf(buffer[2], "%.2f", sueldo);
                    nuevoEmpleado = employee_newParametros(buffer[0], nombre, buffer[1], buffer[2]);
                    ll_add(pArrayListEmployee, nuevoEmpleado);

                }
            }
        }

        rta = 1;

    }





    return rta;//0 error, 1 ok
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int rta = 0;
    int id;
    int idBuscador;
    int opcion;

    int idNueva;
    char nombreNuevo[128];
    int horasNueva;
    float sueldoNuevo;

    Employee* empleado;
    system("cls");

    if(pArrayListEmployee != NULL){
        if((utn_getInt(&idBuscador, "\nIngrese ID de Empelado: ", "\nError! Ingrese ID de Empleado: ", 1, 10000))==0 ){

            for(int i=0;i<ll_len(pArrayListEmployee);i++)
            {
                empleado = (Employee*) ll_get(pArrayListEmployee,i);
                employee_getId(empleado,&id);
                if (id==idBuscador)
                {
                    rta=1;
                    break;
                }
            }
            if(rta==1){
            do{
                switch(opcion = opcionMenuModificar(empleado)){
                    case 1:
                        if(utn_getInt(&idNueva, "\nIngresar Nuevo ID: ", "Error! Ingresar Nuevo ID: ", 1, 10000)==0){
                            employee_setId(empleado, idNueva);
                        }

                        system("pause");
                        break;
                    case 2:
                        if(utn_getString(nombreNuevo, "\nIngresar Nuevo Nombre: ", "Error! Ingresar Nuevo Nombre: ", 1, 128)==0){
                            employee_setNombre(empleado, nombreNuevo);
                        }
                        system("pause");
                        break;
                    case 3:
                        if(utn_getInt(&horasNueva, "\nIngresar Horas nuevas: ", "Error! Ingresar Nuevo ID: ", 1, 10000)==0){
                            employee_setHorasTrabajadas(empleado, horasNueva);
                        }
                        system("pause");
                        break;;

                   case 4:
                        if(utn_getFloat(&sueldoNuevo, "\nIngresar Nuevo Sueldo: ", "Error! Ingresar Nuevo ID: ", 1, 10000)==0){
                            employee_setSueldo(empleado, sueldoNuevo);
                        }

                        system("pause");
                        break;
                }
            }while(opcion !=5);

            }

        }
    }

    return rta;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int rta = 0;
    int id;
    int index;
    char opcion;
    int i;
    Employee* empleado;
    system("cls");

    if(pArrayListEmployee != NULL){
        if((utn_getInt(&index, "\nIngrese ID de Empelado: ", "\nError! Ingrese ID de Empleado: ", 1, 10000))==0 ){

            for( i=0;i<ll_len(pArrayListEmployee);i++)
            {
                empleado = (Employee*) ll_get(pArrayListEmployee,i);
                employee_getId(empleado,&id);
                if (id==index)
                {
                    rta=1;
                    break;
                }
            }
            system("cls");
            mostrarEmpleados2(empleado);
                utn_getChar(&opcion, "    Desea remover este empelado? [S/N]: ", "    Error! Desea remover este empelado? [S/N]: ", 1,10);
            if(opcion == 's'){
                ll_remove(pArrayListEmployee, i);
                rta=1;
            }
            else{
                printf("\n    NO SE ROMOVIO EL EMPLEADO.\n\n\n");
                rta = 0;
            }
        }
    }
    return rta;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int rta;
    Employee* auxPunteroEmpledo;
    char nombre[30];
    int id;
    int sueldo;
    int horasTrabajadas;

    if(pArrayListEmployee != NULL){
        rta = 0;
        system("cls");
        printf("    ***Listar Empleados***\n\n");
         printf("  Id       Nombre      Horas Trabajadas    Sueldo\n\n");
            for(int i=0; i<ll_len(pArrayListEmployee); i++){

                auxPunteroEmpledo=ll_get(pArrayListEmployee, i);
                employee_getId(auxPunteroEmpledo, &id);
                employee_getNombre(auxPunteroEmpledo, nombre);
                employee_getHorasTrabajadas(auxPunteroEmpledo, &horasTrabajadas);

                employee_getSueldo(auxPunteroEmpledo, &sueldo);
                printf(" %04d   %10s   %10d  %15d\n", id, nombre, horasTrabajadas, sueldo);

            }
        printf("\nCantidad de empleados : %d\n\n",ll_len(pArrayListEmployee));

    }

    return rta;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;

    if(pArrayListEmployee != NULL){

        ll_sort(pArrayListEmployee, OrdenPorNombre ,1);

        controller_ListEmployee(pArrayListEmployee);

        printf("\n    EMPLEADOs ORDENADOS POR NOMBRE.\n\n\n");
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 1;
    Employee* pEmpleado;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;


    FILE* f = fopen(path, "w");
    if(f == NULL){
        printf("Error al abrir el archivo");
        todoOk = 0;
        return todoOk;
    }

    if(pArrayListEmployee != NULL){
        //fprintf(f, "id,nombre,sueldo,horastrabajas");

        for(int i=0; i<ll_len(pArrayListEmployee); i++){
            pEmpleado = ll_get(pArrayListEmployee,i);
            employee_getId(pEmpleado,&id);
            employee_getNombre(pEmpleado,nombre);
            employee_getHorasTrabajadas(pEmpleado,&horasTrabajadas);
            employee_getSueldo(pEmpleado,&sueldo);
            printf("%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);
            fprintf(f,"%d,%s,%d,%d\n", id, nombre, horasTrabajadas, sueldo);
            //consola

        }
    }
    fclose(f);
    return todoOk;//0 error y 1 ok
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int todoOk = 1;
    Employee* pEmpleado;

    FILE* f = fopen(path, "wb");
    if(f == NULL){
        printf("Error al abrir el archivo");
        todoOk = 0;
        return todoOk;
    }

    if(pArrayListEmployee != NULL){
        //fprintf(f, "id,nombre,sueldo,horastrabajas");

        for(int i=0; i<ll_len(pArrayListEmployee); i++){
            pEmpleado = ll_get(pArrayListEmployee,i);
            fwrite(pEmpleado, sizeof(Employee), 1, f);

        }
    }
    fclose(f);
    return todoOk;//0 error y 1 ok
}

int opcionMenu(void){
    int opcion;
    int todoOk = 0;
    system("cls");
    printf("    ***ABM Empleados***\n\n");
    printf(" 1)Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
    printf(" 2)Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n");
    printf(" 3)Alta de Empleado\n");
    printf(" 4)Modificar Empleado\n");
    printf(" 5)Baja de Empleados\n");
    printf(" 6)Listar Empleados\n");
    printf(" 7)Ordenar Empleados\n");
    printf(" 8)Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
    printf(" 9)Guardar los datos de los empleados en el archivo data.csv (modo binario)\n");
    printf(" 10) Salir\n");
    printf(" Ingresar opcion : ");

    do{
        fflush(stdin);
        scanf("%d", &opcion);
        if(opcion < 0 || opcion > 10){
              printf("Error! Ingreser opcion : ");
            todoOk = 1;
        }
        else{
            todoOk = 0;
        }

    }while(todoOk == 1);

    return opcion;
}

void mostrarEmpleados(int id, char* nombre, int horasTrabajadas, int sueldo){

    printf(" %5d   %10s   %20s  %8.2f\n", id, nombre, horasTrabajadas, sueldo);

}
