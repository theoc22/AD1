# Agenda — AED I

Agenda de contatos em C de Théo Chatkin - M1 sem declarar variáveis. Todos os dados ficam dentro de um `void *pBuffer` alocado dinamicamente com `malloc` e `realloc`. O buffer cresce ao adicionar pessoas e encolhe ao remover. A navegação entre contatos é feita campo a campo usando `strlen`, já que cada string ocupa exatamente o tamanho do texto. Para compilar: `gcc -g agenda.c -o agenda`.
