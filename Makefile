# https://github.com/renanbmx123/TF_TCS

GCCFLAGS = -g -Wall -Wfatal-errors 
ALL = identifier
GCC = gcc

all: 
	make -C Crypt

clean:
	make clean -C Crypt


