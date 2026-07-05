# Global and Local Inversions

**Aluno:** Theo Chatkin  
**Disciplina:** AED I  
**Turma:** M1

---

Dado um array `nums` de tamanho `n` que representa uma permutação dos inteiros de `0` a `n - 1`, contar o número de inversões globais e locais e retornar `true` se forem iguais.

- **Inversão global:** par `(i, j)` com `i < j` e `nums[i] > nums[j]`.
- **Inversão local:** índice `i` com `nums[i] > nums[i + 1]`.

A solução usa uma **árvore AVL** para contar as inversões globais em `O(n log n)`, mantendo a árvore balanceada a cada inserção.

Exemplo:

```
Entrada:  [1, 0, 2]
Saída:    true
```

- `1 > 0` → 1 inversão global e 1 inversão local
- Globais = Locais → `true`

```
Entrada:  [1, 2, 0]
Saída:    false
```

- `1 > 0` e `2 > 0` → 2 inversões globais
- `2 > 0` → 1 inversão local
- Globais ≠ Locais → `false`
