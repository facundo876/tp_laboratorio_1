#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option;

    LinkedList* listaEmpleados = ll_newLinkedList();


    do{
        switch(option= opcionMenu())
        {
            case 1:
                if(controller_loadFromText("data.csv",listaEmpleados)==0){
                    printf("\n    ARCHIVO CARGADO CON EXITO.\n\n\n");
                }
                system("pause");
                break;
            case 2:
                if(controller_loadFromBinary("data.bin",listaEmpleados)==1){
                    printf("\n    ARCHIVO CARGADO CON EXITO.\n\n\n");
                }
                system("pause");
                break;
            case 3:
                if((controller_addEmployee(listaEmpleados))==1){
                    printf("\n    EMPLEADO CARGADO CON EXITO.\n\n\n");
                }
                system("pause");
                break;
            case 4:
                if((controller_editEmployee(listaEmpleados))==1){
                    printf("\n    EMPLEADO MODIFICADO CON EXITO.\n\n\n");
                }
                system("pause");
                break;
            case 5:
                if((controller_removeEmployee(listaEmpleados))==1){
                    printf("\n    EMPLEADO REMOVIDO CON EXITO.\n\n\n");
                }
                system("pause");
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                system("pause");
                break;
            case 7:
                controller_sortEmployee(listaEmpleados);
                system("pause");
                break;
            case 8:
                if((controller_saveAsText("data2.csv",listaEmpleados))== 1){
                    printf("\n  EL ARCHIVO FUE GUARDADO CON EXITO\n\n");
                }
                system("pause");
                break;
            case 9:
                if((controller_saveAsBinary("data.bin",listaEmpleados))== 1){
                    printf("\n  EL ARCHIVO FUE GUARDADO CON EXITO\n\n");
                }
                system("pause");
                break;
        }

    }while(option != 10);
    return 0;
}
