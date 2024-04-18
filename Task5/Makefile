
COMPILER=g++
CPPFLAGS= -g -Wall
LIBS= -l:libubacsbu2webapp.so.1.5.6 -l:libmyjsonmethods.so.0.1.8 -l:libubacipc.so.1.4.4 -l:libubacjsonparser.so.1.2.8

INCLUDE=-Iinclude
SRCDIR=src
BINDIR=bin
SRC=$(SRCDIR)/*.cpp
BIN=$(BINDIR)/httpserver

all:
	$(COMPILER) $(CPPFLAGS) -o $(BIN) $(SRC) $(INCLUDE) $(LIBS)

run:
	./$(BIN)

remove:
	rm -f $(BINDIR)/*
