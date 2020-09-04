flex wordcount.l
gcc -lfl lex.yy.c -o wordc.o
./wordc.o wordcount.l
