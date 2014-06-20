.PHONY: all clean

CC = gcc
CFLAG = -g -Wall
INC = -I../inc

CSRCS = $(wildcard *.c)
COBJS = $(patsubst %.c, %.o, $(CSRCS))

EXEC = $(patsubst %.c, %, $(CSRCS))

all: $(EXEC)

$(EXEC): $(COBJS) 
	$(CC) -o $(@) $(<)

%.o: %.c
	$(CC) -o $(@) -c $(<) $(INC) $(CFLAG)

clean:
	rm -f $(EXEC) $(COBJS)
