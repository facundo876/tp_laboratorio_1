#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char buffer[4][20];
    int rta;
    Employee* pEmpleado;

    do{
       fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);
        //printf("%s   %s    %s    %s\n\n", buffer[0], buffer[1], buffer[2], buffer[3]);

    //carga en struc
       pEmpleado =  employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

        if(pEmpleado != NULL){
            rta =0;
            ll_add(pArrayListEmployee, pEmpleado);
        }


    }while(!feof(pFile));

    return rta;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int rta=1;

    while(!feof(pFile)){

       Employee* nuevoEmpleado = employee_new();
       if(nuevoEmpleado == NULL){
            printf("\n NO SE PUDO CARGAR EL ARCHIV");
            rta = 0;
       }

        fread(nuevoEmpleado, sizeof(Employee), 1, pFile);

        ll_add(pArrayListEmployee, nuevoEmpleado);
    }

    return rta;
}
