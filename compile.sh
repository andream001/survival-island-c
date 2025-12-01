#!/bin/bash
cd build
echo "Compilando bibliotecas..."
gcc -Wall -Wextra -std=c99 -I../include -c ../src/inventory.c -o inventory.o
gcc -Wall -Wextra -std=c99 -I../include -c ../src/linked_list.c -o linked_list.o  
gcc -Wall -Wextra -std=c99 -I../include -c ../src/search.c -o search.o
gcc -Wall -Wextra -std=c99 -I../include -c ../src/escape_tower.c -o escape_tower.o

echo "Compilando main1..."
gcc -Wall -Wextra -std=c99 -I../include -c ../src/main.c -o main.o || exit 1
gcc -Wall -Wextra -std=c99 -o survival1 inventory.o linked_list.o search.o escape_tower.o main.o || exit 1

echo "Compilando main2..."
gcc -Wall -Wextra -std=c99 -I../include -c ../src/main2.c -o main2.o || exit 1
gcc -Wall -Wextra -std=c99 -o survival2 inventory.o linked_list.o search.o escape_tower.o main2.o || exit 1

echo "Compilando main3..."
gcc -Wall -Wextra -std=c99 -I../include -c ../src/main3.c -o main3.o || exit 1
gcc -Wall -Wextra -std=c99 -o survival3 inventory.o linked_list.o search.o escape_tower.o main3.o || exit 1

echo "Tudo compilado com sucesso!"
ls -lh survival*
