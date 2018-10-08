BASEDIR	=	../..

CC	=	g++
CXX	=	g++
CPPFLAGS = -Wall -O2 -I ${BASEDIR}/include
CFLAGS =
LDFLAGS = -L ${BASEDIR}/lib
LDLIBS =	-lpthread

GENERATED	=	#teste_Socket4L

all:	${GENERATED}	libsocket_linux.a

install:	libsocket_linux.a
	cp -f libsocket_linux.a ${BASEDIR}/lib
	cp -f socket_linux.h ${BASEDIR}/include

libsocket_linux.a:	socket_linux.o

socket_linux.o:	socket_linux.cpp	socket_linux.h

clean:
	rm -f ${GENERATED}
