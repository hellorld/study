.PHONY: all clean

CC = gcc
CFLAG = -g -Wall

CSRCS = $(wildcard *.c)
COBJS = $(patsubst %.c, %.o, $(CSRCS))

EXEC = $(patsubst %.c, %, $(CSRCS))

all: $(EXEC)

#$(EXEC): $(COBJS)
#	$(CC) -o $(@) $(<) $(CFLAG)

%.o: %.c
	$(CC) -o $(@) -c $(<) $(CFLAG)

clean:
	rm -f $(EXEC) $(COBJS)
