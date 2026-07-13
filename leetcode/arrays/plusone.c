/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
  int cont = 0;
  int aumento = 0;

  for ( int i = digitsSize - 1; i >= 0; i--){
    if ( digits[i] == 9 ){
      digits[i] = 0;
      cont++;
      }
    }

    if (cont == digitsSize) aumento = 1;
  
    int *resposta = malloc(sizeof(int) * (digitsSize + aumento));

    *returnSize = digitsSize + aumento;

  if (digits[digitsSize - 1] != 9){
    for (int i = 0; i < digitsSize - 1; i++){
      resposta[i] = digits[i];
    }
    resposta[digitsSize - 1] = digits[digitsSize - 1] + 1;

    return resposta;
  }
    return resposta;
}
