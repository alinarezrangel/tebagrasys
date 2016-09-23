# Build target
TARGET=basicenv
# Directory with the source files
SRCDIR=src
# Directory with the header files
INCDIR=include
# Warning detect
WARN=-Wall
# Optimization
OPT=-O0
# C Standard to use
STD=-std=c11
# Libraries
LIBS=-lm -lgpm
# Compiler flags
CFLAGS=$(STD) $(WARN) $(OPT) -I$(INCDIR)
# Linker flags
LDFLAGS=$(LIBS)
# Object files
OBJC=main.o mousehandler.o
# C Compiler
CC=gcc
# C Linker
LD=gcc

all: $(OBJC)
	$(LD) $(OBJC) $(LDFLAGS) -o $(TARGET)

main.o: $(SRCDIR)/main.c
	$(CC) -o main.o -c $(SRCDIR)/main.c $(CFLAGS)

mousehandler.o: $(SRCDIR)/mousehandler.c
	$(CC) -o mousehandler.o -c $(SRCDIR)/mousehandler.c $(CFLAGS)

clean:
	rm *.o $(TARGET)
