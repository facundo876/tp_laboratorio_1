#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"


/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int utn_getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int rta;
    int reintentos=3;
    int numero;
    printf(message);
    while(reintentos > 0){

        if(getInt(&numero)){
            if(numero<=hiLimit && numero>=lowLimit){
                break;
            }

        }
        fflush(stdin);

        reintentos--;
        printf(eMessage);//error

    }

    if(reintentos==0){
        rta=-1;
    }
    else{
        rta=0;
        *input = numero;
    }

    return rta;//0 ok , -1 error
}
//obetnomos por cadena
int getInt(int* pResultado){
    char buffer[64];
    int rta=-1;
    fflush(stdin);
    fgets(buffer,sizeof(buffer),stdin);
    buffer[strlen(buffer)-1]='\0';

    if(esNumerica(buffer)){
         *pResultado = atoi(buffer);
         rta=1;
    }

    return rta;
}
//validamos la cadena
int esNumerica(char* cadena)
 {
     int ret=-1;
     int i=0;

     if(cadena!=NULL)
     {
         while(cadena[i]!='\0')
         {
             if(cadena[i]<'0' || cadena[i]>'9')
             break;
             i++;
        }
         if(cadena[i]=='\0')
         ret=1;
     }
     return ret;
 }


/**
* \brief Solicita un número al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [-1]
*
*/
int utn_getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit)
{
    int rta;
    int reintentos=3;
    float numero;
    printf(message);
    while(reintentos > 0){

        if(getFloat(&numero)){
            if(numero<=hiLimit && numero>=lowLimit){
                break;
            }

        }
        fflush(stdin);

        reintentos--;
        printf(eMessage);//error

    }

    if(reintentos==0){
        rta=-1;
    }
    else{
        rta=0;
        *input = numero;
    }

    return rta;//0 ok , -1 error
}

int getFloat(float* pResultado){
    char buffer[64];
    int rta=-1;
    fflush(stdin);
    fgets(buffer,sizeof(buffer),stdin);
    buffer[strlen(buffer)-1]='\0';

    if(esFlotante(buffer)){
         *pResultado = atof(buffer);
         rta=1;
    }

    return rta;
}

int esFlotante(char* cadena)
 {
     int ret=-1;
     int i=0;

     if(cadena!=NULL)
     {
         while(cadena[i]!='\0')
         {
             if(cadena[i]<'0' || cadena[i]>'9' || cadena[i]=='.')
             break;
             i++;
        }
         if(cadena[i]=='\0')
         ret=1;
     }
     return ret;
 }

/**
* \brief Solicita un caracter al usuario y lo valida
* \param input Se carga el caracter ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el caracter [0] si no [-1]
*
*/
int utn_getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit)
{
    int ok=0;
    char letras;
   printf(message);

   do{

    scanf("%c", &letras);
    letras = tolower(letras);

    if(letras == 's'){
        ok=1;
        *input = 's';
    }
    else if(letras=='n'){
        ok=1;
        *input='n';
    }
    else{
        printf(eMessage);
    }
   }while(ok==0);

    return 0;
}


/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga el string ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [-1]
*
*/
int utn_getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int rta;
    int reintentos=3;
    char nombre[128];
    printf(message);
    while(reintentos > 0){

        if(getString(nombre)==1){

            if(strlen(nombre)<=hiLimit && strlen(nombre)>=lowLimit){
                break;
            }

        }
        fflush(stdin);

        reintentos--;
        printf(eMessage);//error

    }

    if(reintentos==0){
        rta=-1;
    }
    else{
        rta=0;
        //*input = nombre;
        nombre[0] = toupper(nombre[0]);
        strcpy(input, nombre);
    }

    return rta;//0 ok , -1 error
}

int getString(char* pResultado){
    char buffer[64];
    int rta=-1;
    fflush(stdin);
    fgets(buffer,sizeof(buffer),stdin);
    buffer[strlen(buffer)-1]='\0';

    if(esSoloLetras(buffer)==1){
         //*pResultado = buffer;
         strcpy(pResultado, buffer);
         rta=1;
    }

    return rta;
}

int esSoloLetras(char cadena[]){
    int i=0;

    while(cadena[i] != '\0'){// se detendra cuando encuentre un contrabarra 0;

        if((cadena[i]!=' ') && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z') ){
            return 0;
        }
      i++;
    }
    return 1;
}
