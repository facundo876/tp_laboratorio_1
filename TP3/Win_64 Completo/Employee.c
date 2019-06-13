#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Employee.h"

//escribir sueldo
int employee_setSueldo(Employee* this,int sueldo){

    int todoOk = 0;

    if(this != NULL){

        this->sueldo = sueldo;
        todoOk = 1;
    }

    return todoOk;
}
//leer sueldo
int employee_getSueldo(Employee* this,int* sueldo){

    int todoOk = 0;

    if(this != NULL && sueldo != NULL){

        *sueldo = this->sueldo;
        todoOk = 1;
    }
    return todoOk;
}
//escribir Id
int employee_setId(Employee* this,int id){

    int todoOk = 0;

    if(this != NULL && id > 0){

        this->id = id;
        todoOk = 1;
    }

    return todoOk;
}
//leer id
int employee_getId(Employee* this,int* id){

    int todoOk = 0;

    if(this != NULL && id != NULL){

        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}
//escribir nombre
int employee_setNombre(Employee* this,char* nombre){

    int todoOk = 0;
    int i = 0;

    while(*(nombre+i) != '\0'){

         if(this != NULL){
            todoOk = 1;
        }
        i++;
    }
    //si todos los carracters son correctos
    if(this != NULL && todoOk == 1){
        strcpy(this-> nombre, nombre);
    }

    return todoOk;
}
//leer nombre
int employee_getNombre(Employee* this,char* nombre){

    int todoOk = 0;

    if(this != NULL && nombre != NULL){

       // *nombre = this->nombre;
       strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;
}

//escribir horasTrabajadas
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){

    int todoOk = 0;

    if(this != NULL ){

        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }

    return todoOk;
}
//leer horasTrabajadas
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){

    int todoOk = 0;

    if(this != NULL){

        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}

Employee* employee_new(){

    Employee* emp = (Employee*)malloc( sizeof(Employee));

    if(emp != NULL){
        emp->id = 0;
        strcpy(emp->nombre, "");
        emp->horasTrabajadas = 0;
        emp->sueldo = 0;

    }
    return emp;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr){

    int todoOk = 0;
    Employee* emp = (Employee*)malloc( sizeof(Employee));

    if(emp != NULL){
            if(employee_setId(emp, atoi(idStr)) == 1 ){
                if(employee_setSueldo(emp, atoi(sueldoStr)) ==1){
                    if(employee_setNombre(emp, nombreStr) ==1){
                        if(employee_setHorasTrabajadas(emp, atoi(horasTrabajadasStr)) ==1){

                                emp->id = atoi(idStr);
                                strcpy(emp->nombre, nombreStr);
                                emp->horasTrabajadas = atoi(horasTrabajadasStr);
                                emp->sueldo = atoi(sueldoStr);
                                todoOk = 1;
                        }
                    }
                }
            }

        //hubo error en la carga de datos
        if(todoOk == 0){
            free(emp);
            emp = NULL;
        }
    }
    return emp;

}

void mostrarEmpleados2(Employee* empleado){

printf("    ID      NOMBRE      HORAS TRABAJADAS        SUELDO");
printf("\n %5d   %10s   %8d               %8d \n", empleado->id, empleado->nombre, empleado->horasTrabajadas, empleado->sueldo);
}

int OrdenPorNombre(void* empleadoA, void* empleadoB){

    int rta;


    rta = strcmp(((Employee*)empleadoA)->nombre, ((Employee*)empleadoB)->nombre);

    return rta;
}

int opcionMenuModificar(Employee* empleado){
    int opcion;
    int todoOk = 0;
    system("cls");
        mostrarEmpleados2(empleado);
    printf("\n    ***Modificar Empleado***\n\n");
    printf(" 1)Moficar ID: .\n");
    printf(" 2)Moficar Nombre.\n");
    printf(" 3)Modificar Horas Trabajadas.\n");
    printf(" 4)Modificar Sueldo.\n");
    printf(" 5) Salir\n");
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
