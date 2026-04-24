#include <string.h>
#include <stdlib.h>

char * sortSentence(char * s){
  int numero;
  int inicio = 0; //pra achar o inicio da palavra
  int total_palavras = 0; //conta o total de palavras
  char *palavras[9]; //array de no maximo nove palavras.

  int fim = strlen(s);
  char *resultado = (char*)malloc(fim + 1);//aloco memoria sobre a string inicial, ja q n pode ser maior

    for ( int i = 0; s[i] != '\0'; i++){
        if ( s[i] == ' ' ){
            numero = s[ i - 1 ] - '0'; //vou pegar o numero (ultimo caracter antes do espaco ou do fim)
            // e uso essa tecnica de transformar o numero de string para int usando ascii

            s[ i - 1 ] = '\0'; //corto o numero da string, pra depois colocar no array

            palavras[numero - 1] = &s[inicio]; //aponto pro endereco do comeco da palavra

            inicio = i + 1; //marca o inicio da palavra
            total_palavras++; //incremento o contador
        }//if
    }//for

  //processo a ultima palavra
  numero = s[fim - 1] - '0';
  s[fim - 1] = '\0';
  palavras[numero - 1] = &s[inicio];
  total_palavras++; //conto a ultima palavra

    //depois de inserir ordenadamente as palavras no array, faço um loop pra colocar no resultado
    for ( int i = 0; i < total_palavras; i++){
      //se for a primeira palavra...
      if( i == 0 ){
        strcpy (resultado, palavras[i]); //coloco a primeira palavra, depois so concateno
      } else {
        strcat(resultado, " "); //coloco o espaco pra separar
        strcat(resultado, palavras[i]); //sigo colocando as palavras
      }

    }

    return resultado;
}