all: main mainFileBinomiale

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
	
mainFileBinomiale: mainFileBinomiale.o fileBinomiale.o tournoisBinomial.o util.o fileReader.o
	gcc -o mainFileBinomiale mainFileBinomiale.o fileBinomiale.o tournoisBinomial.o util.o fileReader.o -lm

mainFileBinomiale.o: mainFileBinomiale.c tournoisBinomial.h fileBinomiale.h util.h fileReader.h
	gcc -c mainFileBinomiale.c

tournoisBinomial.o: tournoisBinomial.c tournoisBinomial.h
	gcc -c tournoisBinomial.c

fileBinomiale.o: fileBinomiale.c fileBinomiale.h
	gcc -c fileBinomiale.c

test.o : test.c
	gcc -c test.c

	
md5.o : md5.c md5.h
	gcc -w -c md5.c

