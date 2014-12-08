CC=g++
CFLAGS=-Wall

all:
	$(CC) assignment5_good.cpp $(CFLAGS) -DPRETTY -o assignment5-pretty
	$(CC) assignment5_good.cpp $(CFLAGS) -DNOTPRETTY -o assignment5-notpretty
	$(CC) assignment5_good.cpp $(CFLAGS) -o assignment5-default

pretty:
	$(CC) assignment5_good.cpp $(CFLAGS) -DPRETTY -o assignment5

notpretty:
	$(CC) assignment5_good.cpp $(CFLAGS) -DNOTPRETTY -o assignment5

default:
	$(CC) assignment5_good.cpp $(CFLAGS) -o assignment5

clean:
	rm assignment5-* assignment5 -f

