int minElement(int* nums, int numsSize) {
    int somas[numsSize];
    int menor = 100000;

    for ( int i = 0; i < numsSize; i++){
        int soma = 0;
        
        while ( nums[i] != 0 ){
            soma += nums[i] % 10;
            nums[i] /= 10;
        }
        somas[i] = soma;
    }

    for ( int i = 0; i < somas; i++){
        if ( somas[i] < menor){
            menor = somas[i];
        }
    }

    return menor;

}