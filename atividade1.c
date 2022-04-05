
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void codificador(char frase[]){
    int j=0;
    int i;
    char novafrase[1500]="";
    char letras[]="ABCDEFGHIJ";
    char temp;
    int contador=1;
    char frasefinal[1500]="";
    for (i=0; i<strlen(frase); i++){
        if (frase[i]<48 || frase[i]>57){
            if(frase[i]!= 'Z'){
                novafrase[j++] = frase[i];
                novafrase[j] = '\0';
            } else {
                strcat(novafrase, "ZZ");
                j=strlen(novafrase);
            }
                
               
        } else {
            novafrase[j++] = 'Z';
            novafrase[j++] = letras[(int)frase[i]-'0'];
            novafrase[j] = '\0';
        }
    } 
    temp = novafrase[0];
    j=0;
    for(i=1; i<strlen(novafrase); i++){
       
       if(novafrase[i] == temp){
           contador++;
           if(i==strlen(novafrase)-1){
               
           if(contador > 1){
               frasefinal[j++] = contador+'0';
               
           }
           frasefinal[j++] = temp;
           
           frasefinal[j] = '\0';
       }
       } else{
           
           if(contador > 1){
               frasefinal[j++] = contador+'0';
               
           }
           frasefinal[j++] = temp;
           if(i==strlen(novafrase)-1){
               frasefinal[j++]=novafrase[i];
           }
           frasefinal[j] = '\0';
           contador = 1;
           temp = novafrase[i];
           
       }
    }
    
    
    printf("%s", frasefinal);
}
void decodificador(char frase[]) {
    int i, w, j = 0;
    char novafrase[1500] = "";

    for (i = 0; i < strlen(frase); i++) {
        if (frase[i] >= '0' && frase[i] <= '9') {
            if (frase[i+1] == 'Z') {
                for (w = 0; w < (frase[i] - '0') / 2; w++) {
                    novafrase[j++] = 'Z';
                }
                if ((frase[i] - '0') % 2 == 0) {
                    i = i+1;
                }
            } else {
                for (w = 0; w < frase[i] - '0'; w++) {
                    novafrase[j++] = frase[i+1];
                }
                i = i+1;
            } 
            novafrase[j] = '\0';
        } else {
            if (frase[i] == 'Z') {
                novafrase[j++] = (frase[i+1] - 'A') + '0';
                i = i+1;
            } else {
                novafrase[j++] = frase[i];
            }
            novafrase[j] = '\0';
        }
    }
    printf("%s\n", novafrase);
}

int validador(char frase[]) {
    int i;
    for (i = 0; i < strlen(frase); i++) {
        if (frase[i] >= 48 && frase[i] <= 57) {
            if (i == strlen(frase) - 1) {
                return 0;
            }
            if (frase[i+1] >= 48 && frase[i+1] <= 57) {
                return 0;
            }
            if (frase[i+1] == 'Z' && ((frase[i] - '0') % 2 != 0)) {
                if (i < strlen(frase) - 2) {
                    if (frase[i+2] < 'A' || frase[i+2] > 'J') {
                        return 0;
                    }
                } else {
                    return 0;
                }
            }
        } else {
            if (i < strlen(frase) - 1) {
                if (frase[i] == frase[i+1]) {
                    return 0;
                }
            } else {
                if (frase[i] == 'Z') {
                    if (frase[i-1] < 48 || frase[i-1] > 57) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

int main()
{
    char opt;
    char frase[1500];
    scanf("%c", &opt);
    scanf("%s", frase);

    if (opt == 'C'){
        codificador(frase);
    }
    else if(opt == 'D'){
        if (!validador(frase)) {
            return 0;
        }
        decodificador(frase);
    }
    return 0;
    
    
    
    return 0;
}
