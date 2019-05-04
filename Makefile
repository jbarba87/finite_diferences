CC = g++
CFLAGS = -I.

DEPS = Wave.h Vector.h Heat.h

LIBS=-lm -lncurses


%.o: %.c $(DEPS) 
	$(CC) -c -o $@ $< $(LIBS) 

test_wave: test.o Wave.o Vector.o Heat.o $(LIBS) 
	$(CC) -o test test.o Wave.o Vector.o Heat.o $(LIBS) 

clean:
	rm -f *.o test
