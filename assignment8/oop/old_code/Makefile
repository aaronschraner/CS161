CC=g++
winCC=x86_64-w64-mingw32-g++
winCFLAGS=-static -std=c++11 -DAA -DWINDOWS
CFLAGS=-Wall -std=c++11 
A=8
default:
	$(CC) -o assignment$(A) assignment$(A).cpp $(CFLAGS)
windows:
	$(winCC) -o assignment$(A).exe assignment$(A).cpp $(winCFLAGS)
run:
	$(CC) -o assignment$(A) assignment$(A).cpp $(CFLAGS) && ./assignment$(A)
