#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
/** El programa inicia con un menú en el cual se selecciona la operación deseada.
 * 1. Ingresar 1er operando (A=x)
 * 2. Ingresar 2do operando (B=y)
 * 3. Calcular todas las operaciones
 * 4. Informar resultados
 * 5. Salir
 * Al Seleccionar la opción de 3 se calcularan las siguientes operaciones :
 * a) Calcular la suma (A+B)
 * b) Calcular la resta (A-B)
 * c) Calcular la división (A/B)
 * d) Calcular la multiplicación (A*B)
 * e) Calcular el factorial (A!) y (B!)
 * La opción 4 mostrar por pantalla todos los resultados de las operaciones.
 * Con la opción 5 el programa finalizara.
 */

int main()
{   // Declaracion de variables
    int op;
    int numeroA=0;
    int numeroB=0;
    int sumar, restar, multiplicacion, factorialA, factorialB,verificarDivi=0;
    float division=0;
    // Incio de el menú
    do{
        printf("\n1. Ingresar 1er operando (A=%d)", numeroA);
        printf("\n2. Ingresar 2do operando (B=%d)", numeroB);
        printf("\n3. Calcular todas las operaciones");
        printf("\n4. Informar resultados");
        printf("\n5. Salir\n");
        printf("Ingrese el numero de una operacion  :");
            scanf("%d", &op);

        switch(op){

            case 1:// Opción 1
                printf(" Ingresar 1er operando : ");
                scanf("%d", &numeroA);
                break;
            case 2:// Opción 2
                printf(" Ingresar 2do operando : ");
                scanf("%d", &numeroB);
                break;
            case 3:// Opción 3
                sumar= suma(numeroA,numeroB);

                restar= resta(numeroA,numeroB);

                if(!(numeroA==0 || numeroB==0) ){
                    division= dividir(numeroA,numeroB);
                        verificarDivi=1;
                }

                multiplicacion= multiplicar(numeroA,numeroB);

                factorialA= factoriar(numeroA);
                factorialB= factoriar(numeroB);

                printf("\n Operaciones completadas.\n");
                break;
            case 4:// Opción 4
                printf("\n El resultado de A+B es: %d\n", sumar);
                printf(" El resultado de A-B es: %d\n", restar);
                    if(verificarDivi==0){
                        printf(" El resultado de A/B es: Error no se puede dividir por cero!\n");
                    }
                    else{
                        printf(" El resultado de A/B es: %.2f\n", division);
                    }
                printf(" El resultado de A*B es: %d\n", multiplicacion);
                printf(" El factorial de A es: %d y El factorial de B es: %d\n", factorialA, factorialB);
                break;
            case 5://Opcion 5
                printf("\n Fin.\n");
                break;
            default :
                printf("\n Error ese operador es invalido\n");
        }

    }while(op!=5);// Opción 5
    // Fin del menú
    return 0;
}
