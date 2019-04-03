#include "funciones.h"
//Desarrollo de funciones aritmética.
    int suma(int y,int x){
        int resultado;

        resultado=y+x;
        return resultado;
    }
    int resta(int y,int x){
        int resultado;
        if(y==0){
            return x;
        }
        resultado=y-x;
        return resultado;
    }
    float dividir(int y,int x){
        int resultado;
        resultado=y/x;

        return resultado;
    }
    int multiplicar(int y,int x){
        int resultado;

        resultado=y*x;
        return resultado;
    }
    int factoriar(int y){
        if (y==0){// Si se factoriza por 0.
            return 0;
        }
        int resultado=1, i;
        for(i=1; i<=y; i++){
            resultado*= i;
        }

        return resultado;
    }

