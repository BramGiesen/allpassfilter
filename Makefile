CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++1z
LDFLAGS= -ljack

all: allPass

allPass : jack_module.o allpass.o main.o
	$(CC) -o $@ $(CFLAGS) jack_module.o allpass.o main.o $(LDFLAGS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f example
