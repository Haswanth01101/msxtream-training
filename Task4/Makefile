PKG_NAME=libmyjsonmethods
PKG_VERSION=0.1.8
PKG_DEPENDS= libubacjsonparser-1.2.8
OBJ_NAME=$(PKG_NAME).so.$(PKG_VERSION)
install_include_dir = /usr/local/include/jsonapp
LIBS= -lyajl -l:libubacjsonparser.so.1.2.8
CPP = g++
CPPFLAGS = -g --shared -Wall -fPIC
SRCDIR = src
INCLUDE = -Iinclude
BIN=bin
SRC=$(SRCDIR)/*.cpp
OBJ=$(BIN)/$(OBJ_NAME)
all:
	$(CPP) $(SRC) $(INCLUDE) $(CPPFLAGS) $(LIBS) -o $(OBJ)
install-bin:
	cp $(OBJ) /usr/local/lib
	ldconfig /usr/local/lib
install-dev:
	test -d $(install_include_dir) || mkdir $(install_include_dir)
	cp -r include/* $(install_include_dir)/
install: install-bin install-dev
clean:
	rm -f $(BIN)/*
