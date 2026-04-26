
int *FindDiagonalOrder( int **mat, int matSize, int *matColSize, int *returnSize ) {

    // verifico se a matriz ta vazia, se estiver retorno nulo
    if ( matSize == 0 || matColSize[0] == 0 ) {
        *returnSize = 0;
        return NULL;
    }

    // numero de linhas
    int tamanho = matSize;

    // numero de colunas
    int colunas = matColSize[0];

    // meu return size sempre vai ser o tamanho total
    *returnSize = tamanho * colunas;

    // a resposta vai ter o tamanho do return size vezes o tamanho do int
    int *resposta = (int *)malloc( ( *returnSize ) * sizeof( int ) );
    if ( resposta == NULL ) {
        printf( "erro ao alocar memoria" );
        return NULL;
    }

    int i = 0; // indice pra preencher com a resposta

    // vai percorrer todas as diagonais
    for ( int j = 0; j < tamanho + colunas - 1; j++ ) {

        // se o j for par, eu vou pra cima, else pra baixo
        if ( j % 2 == 0 ) {

            // vou pra cima
            int linha = j;

            if ( linha >= tamanho ) {
                linha = tamanho - 1;
            }

            int coluna = j - linha;

            while ( linha >= 0 && coluna < colunas ) {
                resposta[i] = mat[linha][coluna];
                i++;
                linha--;
                coluna++;
            }

        } else {

            // vou pra baixo
            int coluna = j;

            if ( coluna >= colunas ) {
                coluna = colunas - 1;
            }

            int linha = j - coluna;

            while ( coluna >= 0 && linha < tamanho ) {
                resposta[i] = mat[linha][coluna];
                i++;
                linha++;
                coluna--;
            }
        }
    }

    return resposta;
}