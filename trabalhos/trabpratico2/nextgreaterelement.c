int * NextGreaterElements( int *nums, int numsSize, int *returnSize ) {
	int *resposta = (int *)malloc( sizeof( int ) * numsSize );
 
	for ( int i = 0; i < numsSize; i++ ) {
		resposta[i] = -1;
 
		for ( int j = 1; j < numsSize; j++ ) {
			int x = ( i + j ) % numsSize;
			if ( nums[x] > nums[i] ) {
				resposta[i] = nums[x];
				break;
			}
		}
	}
 
	*returnSize = numsSize;
	return resposta;
}