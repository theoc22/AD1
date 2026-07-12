# 4Sum (LeetCode 18)

**Aluno:** Theo Chatkin  
**Disciplina:** AED I  
**Turma:** M1

---

Dado um array `nums` de `n` inteiros e um valor `target`, encontrar todas as quadruplas únicas `[nums[a], nums[b], nums[c], nums[d]]` tais que `nums[a] + nums[b] + nums[c] + nums[d] == target`, onde `a`, `b`, `c` e `d` são índices distintos.

A solução ordena o array com `qsort` e usa dois loops externos com a técnica de dois ponteiros internos para encontrar as quadruplas em O(n³). Somas são feitas com `long long` para evitar overflow. Duplicatas são eliminadas pulando valores repetidos em cada nível.

Exemplo:

```
Entrada: nums = [1, 0, -1, 0, -2, 2], target = 0
Saída:   [[-2,-1,1,2], [-2,0,0,2], [-1,0,0,1]]
```
