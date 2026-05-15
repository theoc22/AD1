/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
  int cont = 0;
  int jaexiste = 0;

  int *resultado = (int*)malloc(nums1Size * sizeof(int));
    //percorro o primeiro array
    for ( int i = 0; i < nums1Size; i++){
      jaexiste = 0; //reseto o ja existe
      //percorro o segundo array
      for ( int j = 0; j < nums2Size; j++){
        //percorro o resultado, vendo se nn tem numeros ja adicionados
        for ( int k = 0; k < cont; k++){
          if ( resultado[k] == nums1[i] ){
            jaexiste = 1;
            
            break;
          }
        }
        //se for igual e o numero ja n existir...
        if ( nums1[i] == nums2[j] && jaexiste == 0 ){
          resultado[cont] = nums1[i];
          
          cont++;

          break;
        }
      }
    }
    *returnSize = cont; //o valor do retorno vai ser o tamanho do contador

    return resultado; // retorno o resultado mallocado
}