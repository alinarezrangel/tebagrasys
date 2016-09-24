# Build target
TARGET=basicenv.out
# Build target lib
TARGETLIB=libtebagrasys.a
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
OBJC=mousehandler.o common.o geometry.o mousearea.o
# Test
TEST=main.o
# C Compiler
CC=gcc
# C Linker
LD=gcc
# Library Maker
AR=ar
# AR options
ARFLAGS=-cvq

all: $(OBJC) $(TEST)
	$(AR) $(ARFLAGS) $(TARGETLIB) $(OBJC)
	$(LD) $(TEST) $(TARGETLIB) $(LDFLAGS) -o $(TARGET)

main.o: $(SRCDIR)/main.c
	$(CC) -o main.o -c $(SRCDIR)/main.c $(CFLAGS)

mousehandler.o: $(SRCDIR)/mousehandler.c $(INCDIR)/mousehandler.h
	$(CC) -o mousehandler.o -c $(SRCDIR)/mousehandler.c $(CFLAGS)

common.o: $(SRCDIR)/common.c $(INCDIR)/common.h
	$(CC) -o common.o -c $(SRCDIR)/common.c $(CFLAGS)

geometry.o: $(SRCDIR)/geometry.c $(INCDIR)/geometry.h
	$(CC) -o geometry.o -c $(SRCDIR)/geometry.c $(CFLAGS)

mousearea.o: $(SRCDIR)/mousearea.c $(INCDIR)/mousearea.h
	$(CC) -o mousearea.o -c $(SRCDIR)/mousearea.c $(CFLAGS)

clean:
	rm *.o $(TARGET)
