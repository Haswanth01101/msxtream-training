
COMPILER=g++
CPPFLAGS=-Wall -g
SRCDIR=src
LIB=-l:libubacipc.so.1.4.4
INCLUDE=-Iinclude
BINDIR=bin
OBJ=client
BIN=$(BINDIR)/$(OBJ)
SRC=$(SRCDIR)/*.cpp
client1=$(COMPILER) $(CPPFLAGS) -o $(BIN)1 $(SRC) $(INCLUDE) $(LIB)
client2=$(COMPILER) $(CPPFLAGS) -o $(BIN)2 $(SRC) $(INCLUDE) $(LIB)
client3=$(COMPILER) $(CPPFLAGS) -o $(BIN)3 $(SRC) $(INCLUDE) $(LIB)
all:
	$(client1)
	$(client2)
	$(client3)

run1:
	./$(BIN)1
run2:
	./$(BIN)2
run3:
	./$(BIN)3
remove:
	rm -f $(BIN)1
	rm -f $(BIN)2
	rm -f $(BIN)3
