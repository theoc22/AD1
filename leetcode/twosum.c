#include  <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    //dois fors pra percorrer todo o array
  for (int i = 0; i < numsSize; i++){
    for (int j = i + 1; j < numsSize; j++){
      if (nums[i] + nums[j] == target){
        //malloco o resultado. vezes dois pq sao dois numeros
        int *resultado = (int*)malloc(2 * sizeof(int));

        resultado[0] = i;
        resultado[1] = j;

        //aviso q to retornando 2 numeros
        *returnSize = 2;

        return resultado;

      }
    }
  }
  //so por seguranca
  *returnSize = 0;
  return NULL;

}