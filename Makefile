all: main mainFileBinomiale menu tmain FBConsIter FBAjout FBSupprMin FBUnion tasTabAjout tasTabSupMin clean

#executables

tasTabAjout: util.o fileReader.o tasTab.o tasTabAjout.o 
	gcc -o tasTabAjout  util.o fileReader.o tasTab.o tasTabAjout.o -lm
	
tasTabSupMin: util.o fileReader.o tasTab.o tasTabSupMin.o 
	gcc -o tasTabSupMin  util.o fileReader.o tasTab.o tasTabSupMin.o -lm

FBConsIter: util.o fileReader.o tasTree.o tasTab.o md5.o AVL.o fromFile.o FBConsIter.o fileBinomiale.o tournoisBinomial.o
	gcc -o FBConsIter.exe  util.o fileReader.o tasTree.o tasTab.o md5.o AVL.o fromFile.o fileBinomiale.o tournoisBinomial.o FBConsIter.o -lm

FBAjout: util.o fileReader.o tasTree.o tasTab.o md5.o AVL.o fromFile.o FBAjout.o fileBinomiale.o tournoisBinomial.o
	gcc -o FBAjout.exe  util.o fileReader.o tasTree.o tasTab.o md5.o AVL.o fromFile.o fileBinomiale.o tournoisBinomial.o FBAjout.o -lm

FBSupprMin: util.o fileReader.o tasTree.o tasTab.o md5.o AVL.o fromFile.o FBSupprMin.o fileBinomiale.o tournoisBinomial.o
	gcc -o FBSupprMin.exe  util.o fileReader.o tasTree.o tasTab.o md5.o AVL.o fromFile.o fileBinomiale.o tournoisBinomial.o FBSupprMin.o -lm

FBUnion: util.o fileReader.o tasTree.o tasTab.o md5.o AVL.o fromFile.o FBUnion.o fileBinomiale.o tournoisBinomial.o
	gcc -o FBUnion.exe  util.o fileReader.o tasTree.o tasTab.o md5.o AVL.o fromFile.o fileBinomiale.o tournoisBinomial.o FBUnion.o -lm

tmain : util.o fileReader.o tasTree.o tasTab.o md5.o AVL.o fromFile.o grpmain.o fileBinomiale.o tournoisBinomial.o
	gcc -o tmain  util.o fileReader.o tasTree.o tasTab.o md5.o AVL.o fromFile.o fileBinomiale.o tournoisBinomial.o grpmain.o -lm

menu :  util.o fileReader.o tasTree.o tasTab.o md5.o AVL.o fromFile.o menu.o
	gcc -o menu  util.o fileReader.o tasTree.o tasTab.o md5.o AVL.o fromFile.o menu.o -lm

main :  util.o fileReader.o tasTree.o test.o tasTab.o md5.o AVL.o fromFile.o
	gcc -o main  util.o fileReader.o tasTree.o tasTab.o test.o md5.o AVL.o fromFile.o -lm
	
mainFileBinomiale: mainFileBinomiale.o fileBinomiale.o tournoisBinomial.o util.o fileReader.o
	gcc -o mainFileBinomiale mainFileBinomiale.o fileBinomiale.o tournoisBinomial.o util.o fileReader.o -lm
	
#.o

tasTabAjout.o: tasTabAjout.c
	gcc -c tasTabAjout.c

tasTabSupMin.o: tasTabSupMin.c
	gcc -c tasTabSupMin.c

FBConsIter.o: FBConsIter.c
	gcc -c FBConsIter.c

FBAjout.o: FBAjout.c
	gcc -c FBAjout.c

FBSupprMin.o: FBSupprMin.c
	gcc -c FBSupprMin.c

FBUnion.o: FBUnion.c
	gcc -c FBUnion.c

unionMain.o : unionMain.c
	gcc -c unionMain.c

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

