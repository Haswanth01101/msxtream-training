CXX = g++
INCLUDE = -Iinclude

BINDR = bin
OBJ = Array
BIN = $(BINDR)/$(OBJ)
SRCDIR=src
SRC = $(SRCDIR)/*.cpp

all:
	$(CXX) -o $(BIN) $(SRC) $(INCLUDE)

run:
	./$(BIN)

remove:
	rm -f $(BIN)
