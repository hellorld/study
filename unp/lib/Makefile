
LIBNAME = unp
CC = g++
AR = ar
CPPFLAGS = -g -Wall -fPIC 
INC = -I../inc

CPPSRCS := $(wildcard *.cpp)
CPPOBJS := $(patsubst %.cpp,%.o,$(CPPSRCS))

CSRCS := $(wildcard *.c)
COBJS := $(patsubst %.c,%.o,$(CSRCS))

OBJS = $(CPPOBJS) $(COBJS)

all: $(LIBNAME)

$(LIBNAME): $(OBJS) 
	$(AR) -r lib$(@).a $(^)
	$(CC) -shared -o lib$(@).so $(^)
	ln -s lib$(@).so lib$(@).so.1

%.o: %.cpp
	$(CC) -o $(@) -c $(<) $(INC) $(CPPFLAGS)
%.o: %.c
	$(CC) -o $(@) -c $(<) $(INC) $(CPPFLAGS)

clean:
	@rm -f $(OBJS) lib$(LIBNAME).a lib$(LIBNAME).so*
