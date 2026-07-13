int majorityElement(int* nums, int numsSize) {
  //um for pra passadas, um for pra comparar vizinhos
  //ele sempre vai ser maior q a metade do array, ent posso ordenar e retornar o do meio
     for ( int i = 0; i < numsSize; i++){
        for ( int j = 0; j < numsSize - 1; j++){
          if ( nums[j] > nums[j + 1]){
            int temp = nums[j];

            nums[j] = nums[j + 1];

            nums[j + 1] = temp;
          }
        }
      }

      return nums[numsSize / 2];
}