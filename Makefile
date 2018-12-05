all: main mainFileBinomiale menu tmain

#executables

tmain : util.o fileReader.o tasTree.o tasTab.o md5.o AVL.o fromFile.o grpmain.o fileBinomiale.o tournoisBinomial.o
	gcc -o tmain  util.o fileReader.o tasTree.o tasTab.o md5.o AVL.o fromFile.o fileBinomiale.o tournoisBinomial.o grpmain.o -lm

menu :  util.o fileReader.o tasTree.o tasTab.o md5.o AVL.o fromFile.o menu.o
	gcc -o menu  util.o fileReader.o tasTree.o tasTab.o md5.o AVL.o fromFile.o menu.o -lm

main :  util.o fileReader.o tasTree.o test.o tasTab.o md5.o AVL.o fromFile.o
	gcc -o main  util.o fileReader.o tasTree.o tasTab.o test.o md5.o AVL.o fromFile.o -lm
	
mainFileBinomiale: mainFileBinomiale.o fileBinomiale.o tournoisBinomial.o util.o fileReader.o
	gcc -o mainFileBinomiale mainFileBinomiale.o fileBinomiale.o tournoisBinomial.o util.o fileReader.o -lm
	
#.o

grpmain.o : grpmain.c
	gcc -c grpmain.c

util.o : util.c util.h
	gcc -c util.c
	
tasTab.o : tasTab.c tasTab.h
	gcc -c tasTab.c
	
fileReader.o : fileReader.c fileReader.h
	gcc -c fileReader.c

tasTree.o : tasTree.c tasTree.h
	gcc -c tasTree.c
	
mainFileBinomiale.o: mainFileBinomiale.c tournoisBinomial.h fileBinomiale.h util.h fileReader.h
	gcc -c mainFileBinomiale.c

tournoisBinomial.o: tournoisBinomial.c tournoisBinomial.h
	gcc -c tournoisBinomial.c

fileBinomiale.o: fileBinomiale.c fileBinomiale.h
	gcc -c fileBinomiale.c

test.o : test.c
	gcc -c test.c
	
menu.o : menu.c
	gcc -c menu.c

md5.o : md5.c md5.h
	gcc -w -c md5.c


AVL.o : AVL.c AVL.h
	gcc -c AVL.c

fromFile.o : fromFile.c fromFile.h
	gcc -c fromFile.c

clean:
	rm -f *.o

