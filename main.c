#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int suma(y,x);
int resta(y,x);
int dividir(y,x);
int multiplicar(y,x);
int factoriar(y);

int main()
{
    int numeroA, numeroB, sumar, restar, multiplicacion, factorialA, factorialB;
    float  division;
    char salir;

        do{
            printf("Ingresar 1er operando : ");
                scanf("%d", &numeroA);
            printf("(A=%d)",numeroA);
            printf("\nIngresar 2er operando : ");
                scanf("%d", &numeroB);
            printf("(B=%d)\n",numeroB);

            sumar= suma(numeroA,numeroB);// A)

            restar= resta(numeroA,numeroB);

            division= dividir(numeroA,numeroB);

            multiplicacion= multiplicar(numeroA,numeroB);

            factorialA= factoriar(numeroA);
             factorialB= factoriar(numeroB);


            printf("El resultado de A+B es: %d\n", sumar);
            printf("El resultado de A-B es: %d\n", restar);
            printf("El resultado de A/B es: %.2f\n", division);
            printf("El resultado de A*B es: %d\n", multiplicacion);
            printf("El factorial de A es: %d y El factorial de B es: %d\n", factorialA, factorialB);

            do{
                printf("Salir : [s/n]");
                fflush(stdin);
                scanf("%c",&salir);
                salir= tolower(salir);

            }while(salir!='s'&& salir!='n');
        }while(salir=='n');

    return 0;
}

int suma(y,x){
    int resultado;

    resultado=y+x;
    return resultado;
}
int resta(y,x){
    int resultado;

    resultado=y-x;
    return resultado;
}
int dividir(y,x){
    float resultado;

    resultado=y/x;
    return resultado;
}
int multiplicar(y,x){
    int resultado;

    resultado=y*x;
    return resultado;
}
int factoriar(y){
    int resultado, i;

    for(i=1; i<=y; i++){
        resultado= y*i;
    }

    return resultado;
}
