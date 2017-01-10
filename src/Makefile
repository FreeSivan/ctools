CXX = g++
CC = gcc

BIN_PATH = ../bin

all : moveFilter movenFilter

moveFilter : moveFilter.o
	${CC} $^ -o ${BIN_PATH}/$@
	@rm $^

movenFilter : movenFilter.o
	${CXX} $^ -o ${BIN_PATH}/$@
	@rm $^

clean:
	@rm -f *.o ${BIN_PATH}/*
