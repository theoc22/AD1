# Agenda em C — Gerenciamento de Memória Manual com pBuffer

Trabalho prático da disciplina de Algoritmos e Estruturas de Dados I.  
O objetivo é implementar uma agenda de contatos em C **sem declarar variáveis** — todos os dados são armazenados manualmente dentro de um buffer de memória alocado dinamicamente.

---

## Regras do Trabalho

- Nenhuma variável pode ser declarada. Apenas ponteiros que apontam para dentro do `pBuffer`.
- Não é permitido usar `struct`.
- As strings armazenadas no buffer devem ter exatamente o tamanho do texto (sem espaço fixo).
- Um único buffer de rascunho de tamanho fixo é permitido para receber a entrada do `scanf`.

---

## Funcionalidades

| Opção | Função |
|-------|--------|
| 1 | Adicionar pessoa (nome, email, idade) |
| 2 | Remover pessoa pelo nome |
| 3 | Buscar pessoa pelo nome |
| 4 | Listar todas as pessoas |
| 5 | Sair |

---

## Layout do Buffer

O buffer é dividido em duas partes: um **cabeçalho fixo** e uma **área de dados dinâmica**.

```
[0..3]    → quantidade de pessoas (int, 4 bytes)
[4..7]    → tamanho atual do buffer (int, 4 bytes)
[8..11]   → opção do menu (int, 4 bytes)
[12..15]  → contador auxiliar para loops (int, 4 bytes)
[16..65]  → rascunho do nome — buffer fixo para scanf (50 bytes)
[66..115] → rascunho do email — buffer fixo para scanf (50 bytes)
[116..]   → dados das pessoas (tamanho dinâmico)
```

Cada pessoa é armazenada assim:

```
[nome\0][idade int 4 bytes][email\0]
```

Como cada string ocupa exatamente o espaço necessário, as pessoas têm tamanhos diferentes no buffer.

---

## Como Navegar pelo Buffer

Como não há tamanho fixo por pessoa, a navegação usa `strlen` para pular campo a campo:

```c
char *pCursor = pBuffer + OFF_PESSOAS;

pCursor += strlen(pCursor) + 1;  // pula nome
pCursor += 4;                     // pula idade (int fixo)
pCursor += strlen(pCursor) + 1;  // pula email
// pCursor agora aponta para a próxima pessoa
```

---

## Como Compilar

```bash
gcc -g agenda.c -o agenda
```

Com AddressSanitizer:
```bash
gcc -fsanitize=address -g agenda.c -o agenda
```

Com Valgrind:
```bash
valgrind --leak-check=full ./agenda
```

---

## Decisões de Implementação

**Por que `char *pBuffer`?**  
`char` tem 1 byte, permitindo navegação precisa byte a byte. Outros tipos como `int *` avançariam 4 bytes por vez, impossibilitando o controle fino da memória.

**Por que `realloc`?**  
O buffer cresce ao adicionar pessoas e encolhe ao remover. O `realloc` é chamado após cada operação e o ponteiro `pBuffer` é sempre atualizado no `main`.

**Por que `memmove` na remoção?**  
Como as pessoas têm tamanhos diferentes, não é possível simplesmente copiar a última para o lugar da removida (poderia sobrescrever dados de outras pessoas). O `memmove` desloca todo o bloco de dados após a pessoa removida para a esquerda, preenchendo o buraco corretamente.

**Por que recalcular ponteiros após `realloc`?**  
O `realloc` pode mover o buffer para um novo endereço. Todos os ponteiros calculados antes ficam inválidos e precisam ser recalculados a partir do novo `pBuffer`.

---

## Autor

Theo — AED I
