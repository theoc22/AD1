#include <stdlib.h>
#include <stdbool.h>

typedef struct no_s {
	int					valor;
	int					tamanho;
	int					altura;
	struct no_s *		esq;
	struct no_s *		dir;
} no_t;

/*
====================
Altura
====================
*/
static int Altura( const no_t *n ) {
	return n ? n->altura : 0;
}

/*
====================
Tamanho
====================
*/
static int Tamanho( const no_t *n ) {
	return n ? n->tamanho : 0;
}

/*
====================
Atualizar
====================
*/
static void Atualizar( no_t *n ) {
	int		he;
	int		hd;

	he = Altura( n->esq );
	hd = Altura( n->dir );
	n->altura = ( he > hd ? he : hd ) + 1;
	n->tamanho = 1 + Tamanho( n->esq ) + Tamanho( n->dir );
}

/*
====================
RotacaoDireita
====================Inserir
*/
static no_t *RotacaoDireita( no_t *y ) {
	no_t *	x;

	x = y->esq;
	y->esq = x->dir;
	x->dir = y;
	Atualizar( y );
	Atualizar( x );
	return x;
}

/*
====================
RotacaoEsquerda
====================
*/
static no_t *RotacaoEsquerda( no_t *x ) {
	no_t *	y;

	y = x->dir;
	x->dir = y->esq;
	y->esq = x;
	Atualizar( x );
	Atualizar( y );
	return y;
}

/*
====================
FatorBalanceamento
====================
*/
static int FatorBalanceamento( const no_t *n ) {
	return Altura( n->esq ) - Altura( n->dir );
}

/*
====================
Rebalancear
====================
*/
static no_t *Rebalancear( no_t *n ) {
	int		fb;

	Atualizar( n );
	fb = FatorBalanceamento( n );

	if ( fb > 1 ) {
		if ( FatorBalanceamento( n->esq ) < 0 ) {
			n->esq = RotacaoEsquerda( n->esq );
		}
		return RotacaoDireita( n );
	}
	if ( fb < -1 ) {
		if ( FatorBalanceamento( n->dir ) > 0 ) {
			n->dir = RotacaoDireita( n->dir );
		}
		return RotacaoEsquerda( n );
	}
	return n;
}

/*
====================
Inserir_r

	Essa funcao insere um valor na arvore e retorna a nova raiz.
====================
*/
no_t *Inserir_r( no_t *raiz, int valor ) {
	no_t *	n;

	if ( !raiz ) {
		n = malloc( sizeof( no_t ) );
		n->valor = valor;
		n->tamanho = 1;
		n->altura = 1;
		n->esq = NULL;
		n->dir = NULL;
		return n;
	}
	if ( valor < raiz->valor ) {
		raiz->esq = Inserir_r( raiz->esq, valor );
	} else {
		raiz->dir = Inserir_r( raiz->dir, valor );
	}
	return Rebalancear( raiz );
}

/*
====================
Liberar_r
====================
*/
void Liberar_r( no_t *n ) {
	if ( !n ) {
		return;
	}
	Liberar_r( n->esq );
	Liberar_r( n->dir );
	free( n );
}

/*
====================
isIdealPermutation

	RESOLVER ESSA FUNCAO USANDO ARVORE AVL PARA CONTAR O NUMERO DE INVERSOES GLOBAIS.

====================
*/
bool isIdealPermutation( int *nums, int numsSize ) {

	no_t *raiz;
	no_t *atual;

	long long global;
	long long local;
	int i;

	raiz = NULL;

	global = 0;
	local = 0;

	for ( i = 0; i < numsSize; i++){
		atual = raiz;

		while ( atual ){
			if ( nums[i] < atual->valor ){
				global += Tamanho( atual-> dir ) + 1;
				atual = atual->esq;
			} else {
				atual = atual->dir;
			}
		}

		raiz = Inserir_r (raiz, nums[i]);

		if ( i + 1 < numsSize && nums[i] > nums[i + 1] ){
			local++;
		}
	}

	Liberar_r( raiz );

	return global == local;
}
