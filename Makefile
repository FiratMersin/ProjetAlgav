all: main

main :  util.o fileReader.o tasTree.o test.o tasTab.o
	gcc -o main  util.o fileReader.o tasTree.o tasTab.o test.o -lm

util.o : util.c util.h
	gcc -c util.c
	
tasTab.o : tasTab.c tasTab.h
	gcc -c tasTab.c
	
fileReader.o : fileReader.c fileReader.h
	gcc -c fileReader.c

tasTree.o : tasTree.c tasTree.h
	gcc -c tasTree.c
	
test.o : test.c
	gcc -c test.c