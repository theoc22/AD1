int removeElement(int* nums, int numsSize, int val) {
  int k = 0;
    for ( int i = 0; i < numsSize; i++){
      // vai percorrer todo o array, vendo o valor
      if ( nums[i] != val ){
        //se o nums[i] for diferente do val, armazena no
        //nums[k] e acremento o k.
        
        nums[k] = nums[i];
        k++;
      }
      return k;
    }
}