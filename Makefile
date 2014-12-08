CC=g++
winCC=x86_64-w64-mingw32-g++
winCFLAGS=-static
CFLAGS=-Wall
A=_

#USE THIS WITH:
# $ make A=assignmentno
# where assignmentno is some number.
# It will create the directory and initialize it with all the required files.


default:
	mkdir -p assignment$(A)
	touch assignment$(A)/assignment$(A){.cpp,}
	(cat Makefile|head -n 5; cat Makefile|tail -n 6)|sed 's/A=_/A=$(A)/g;s/default/init/g;s/build/default/g' > assignment$(A)/Makefile

fill:
	(cat Makefile|head -n 5; cat Makefile|tail -n 6)|sed 's/A=_/A=$(A)/g;s/default/init/g;s/build/default/g' > assignment$(A)/Makefile



build:
	$(CC) -o assignment$(A) assignment$(A).cpp $(CFLAGS)
windows:
	$(winCC) -o assignment$(A).exe assignment$(A).cpp $(winCFLAGS)
run:
	$(CC) -o assignment$(A) assignment$(A).cpp $(CFLAGS) && ./assignment$(A)
