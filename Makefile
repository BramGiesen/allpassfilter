CC = g++
CFLAGS = -I/usr/local/include -Wall -std=c++11
LDFLAGS= -ljack

all: allpass

allpass : jack_module.o allpassFilter.o audioProcess.o main.o
	$(CC) -o $@ $(CFLAGS) jack_module.o allpassFilter.o audioProcess.o main.o $(LDFLAGS)

.cpp.o:
	$(CC) -c $< $(CFLAGS)

clean:
	rm -f *.o
	rm -f allpass
