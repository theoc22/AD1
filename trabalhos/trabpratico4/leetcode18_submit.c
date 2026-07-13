static int CompararInt( const void *a, const void *b ) {
	int		x;
	int		y;

	x = *( const int * )a;
	y = *( const int * )b;
	return ( x > y ) - ( x < y );
}

int **fourSum( int *nums, int numsSize, int target,
			   int *returnSize, int **returnColumnSizes ) {
	int		cap;
	int **	res;
	int		i;
	int		j;
	int		esq;
	int		dir;
	long long soma;

	*returnSize = 0;

	if ( numsSize < 4 ) {
		*returnColumnSizes = NULL;
		return NULL;
	}

	qsort( nums, numsSize, sizeof( int ), CompararInt );

	cap = 64;
	res = malloc( sizeof( int * ) * cap );

	for ( i = 0; i < numsSize - 3; i++ ) {

		if ( i > 0 && nums[i] == nums[i - 1] ) {
			continue;
		}
		for ( j = i + 1; j < numsSize - 2; j++ ) {

			if ( j > i + 1 && nums[j] == nums[j - 1] ) {
				continue;
			}
			esq = j + 1;
			dir = numsSize - 1;
			while ( esq < dir ) {
				soma = (long long)nums[i] + nums[j] + nums[esq] + nums[dir];
				if ( soma == target ) {

					if ( *returnSize == cap ) {
						cap *= 2;
						res = realloc( res, sizeof( int * ) * cap );
					}
					res[*returnSize] = malloc( sizeof( int ) * 4 );
					res[*returnSize][0] = nums[i];
					res[*returnSize][1] = nums[j];
					res[*returnSize][2] = nums[esq];
					res[*returnSize][3] = nums[dir];
					( *returnSize )++;

					while ( esq < dir && nums[esq] == nums[esq + 1] ) {
						esq++;
					}
					while ( esq < dir && nums[dir] == nums[dir - 1] ) {
						dir--;
					}
					esq++;
					dir--;
				} else if ( soma < target ) {
					esq++;
				} else {
					dir--;
				}
			}
		}
	}

	*returnColumnSizes = malloc( sizeof( int ) * ( *returnSize ) );
	for ( i = 0; i < *returnSize; i++ ) {
		( *returnColumnSizes )[i] = 4;
	}

	return res;
}
