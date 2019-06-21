#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define TAM 1000

int main()
{
    int option;
    Employee arrayEmplyees[TAM];/*={{1,"Facundo", "arce", 55, 2, 1},
                               {2,"Hernan", "aguirre", 66, 2, 1},
                               {3,"Jhon", "zoc", 7, 1, 1},
                               {4,"Maria", "caravajal", 11, 1, 1}
    };*/
    initEmployees(arrayEmplyees, TAM);//Inicializa

    cargaDeDatos(arrayEmplyees, TAM);

    do{
        switch(option= opcionMenu())
        {
            case 1:

                if((altaEmpleado(arrayEmplyees, TAM))==0){
                    printf("\n      EMPLEADO GUARDADO CON EXITO\n\n");
                }
                system("pause");
                break;
            case 2:
                if((modificarEmpleado(arrayEmplyees, TAM))==0 ){
                   printf("\n      EMPLEADO MODIFICADO CON EXITO\n\n");
                }
                system("pause");
                break;
            case 3:
                if((bajaEmpelado(arrayEmplyees, TAM))==0 ){
                    printf("\n      EMPLEADO ELIMINADO CON EXITO\n\n");
                }
                system("pause");
                break;
            case 4:
                funcionInformar(arrayEmplyees, TAM);
                system("pause");
                break;
        }

    }while(option != 5);
    return 0;
}
