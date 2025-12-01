# survival-island-c

Mini game de sobrevivência em C: gerencia inventário, usa listas encadeadas e vetores, implementa busca, ordenação e uma "torre de fuga" como mecânica de progresso.

**Requisitos**
- `gcc` com suporte a C99
- `make` (opcional — há `compile.sh`)
- Sistema testado: Ubuntu 24.04

**Build**
Na raiz do projeto:

```bash
make
# ou alternadamente
./compile.sh
```

Os artefatos compilados ficam em `build/`.

**Executáveis gerados**
- `build/survival1` — cenário/fase 1
- `build/survival2` — cenário/fase 2
- `build/survival3` — cenário/fase 3

**Como executar**
Exemplo simples:

```bash
./build/survival1
./build/survival2
./build/survival3
```

Se quiser compilar e executar automaticamente (modo rápido):

```bash
./compile.sh && ./build/survival1
```

**Testes rápidos**
- Após `make`, verifique a saída dos binários para as fases:
	- `FASE 1 - Teste`
	- `FASE 2 - Teste`
	- `FASE 3 - Teste`

**Alterações recentes**
- Corrigido problema de escape de strings em `src/escape_tower.c` (commit: `cc03de8`), que impedia a compilação em ambientes que exigem ASCII/escapes válidos.

**Contribuição**
- Abra um issue para discutir mudanças ou envie pull requests. Siga as convenções já usadas no repositório.

---
Arquivo gerado/atualizado automaticamente pelo assistente de desenvolvimento para facilitar build e execução.
# survival-island-c
Mini game de sobrevivência em ilha hostil com inventário, listas encadeadas/vetores, busca binária, Selection Sort e torre de fuga.
