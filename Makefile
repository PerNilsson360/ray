CC = g++
CFLAGS = -g -std=gnu++14 -pedantic -Werror -Wall

OBJECTS = Screen.o

LIBS = -lSDL2
INC = 

main : $(OBJECTS) $(UT_OBJ)
	$(CC) $(CFLAGS) $(OBJECTS) main.cc -o ray $(LIBS)

%.o : %.cc %.hh Makefile
	$(CC) $(CFLAGS) -c $<
clean :
	rm *.o
	rm TAGS
	rm *~

tags :
	find . -name "*.[chCH]" -print | etags -	
