# Instruções de compilação

No terminal, navegue até a pasta onde está o arquivo `.c` e use o comando:

`gcc -Wall -o Problema_x Problema_x.c`

Ou, alternativamente:

`gcc -Wall -o Problema_x Problema_x.c -lm` para problemas que usam a `math.h`.

Note que alguns problemas usam a vírgula como separador decimal nas entradas devido ao uso da `locale.h`.
