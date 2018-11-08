BASEDIR	=	.

CC	=	g++
CXX	=	g++
CPPFLAGS = -Wall -O2 -std=c++11	-I ${BASEDIR}/include
CFLAGS =
LDFLAGS = -L ${BASEDIR}/lib
LDLIBS =	-lsystem_tools	-lsocket4L	-lmraa

all:	main

main:	controller.h	controller.cpp

build:
	cd	src/tools	&&	${MAKE}	install
	cd	src/socket	&&	${MAKE}	install

clean:
	rm -f main	*.o
	cd	src/tools	&&	${MAKE}	clean
	cd	src/socket	&&	${MAKE}	clean
