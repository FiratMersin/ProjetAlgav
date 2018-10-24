all: main

main :  util.o fileReader.o tasTree.o test.o tasTab.o md5.o
	gcc -o main  util.o fileReader.o tasTree.o tasTab.o test.o md5.o -lm

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
	
md5.o : md5.c md5.h
	gcc -w -c md5.c