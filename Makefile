BASEDIR	=	.
SOURCE_DIR = ./lib

CC	=	g++
CXX	=	g++
CPPFLAGS = -Wall -O2 -I ${BASEDIR}/include
CFLAGS =
LDFLAGS = -L ${BASEDIR}/lib
LDLIBS =	-lpthread

PROGRAMAS	=	main

all:	${PROGRAMAS}

clean:
	rm -f ${PROGRAMAS}
