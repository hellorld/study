.PHONY: all clean

CC = g++
CPPFLAG = -g -Wall

CPPSRCS = $(wildcard *.cpp)
CPPOBJS = $(patsubst %.cpp, %.o, $(CPPSRCS))

EXEC = $(patsubst %.cpp, %, $(CPPSRCS))

all: $(EXEC)

#$(EXEC): $(CPPOBJS)
#	$(CC) -o $(@) $(<) $(CPPFLAG)

%.o: %.cpp
	$(CC) -o $(@) -c $(<) $(CPPFLAG)

clean:
	rm -f $(EXEC) $(CPPOBJS)
