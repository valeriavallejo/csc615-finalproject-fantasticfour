ROOTNAME=line
CC=gcc
CFLAGS= -g -I.
WFLAGS= -lwiringPi
PFLAGS = -pthread
LIBS =
DEPS = 
OBJ = $(ROOTNAME).o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) $(WFLAGS) $(PFLAGS)  $(LIBS)
           
$(ROOTNAME): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)  $(WFLAGS) $(PFLAGS)  $(LIBS)

clean:
	rm *.o $(ROOTNAME)

run: $(ROOTNAME)
	./$(ROOTNAME)