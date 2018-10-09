BASEDIR	=	../..

CC	=	g++
CXX	=	g++
CPPFLAGS = -Wall -O2 -I ${BASEDIR}/include
CFLAGS =
LDFLAGS = -L ${BASEDIR}/lib
LDLIBS =

GENERATED	=	teste_clock

all:	${GENERATED}

${GENERATED}:	libsystem_tools.a

libsystem_tools.a:	system_tools.o
	ar r $@ $?

system_tools.o:	system_tools.cpp	system_tools.h

install:	libsystem_tools.a
	cp -f libsystem_tools.a ${BASEDIR}/lib
	cp -f system_tools.h ${BASEDIR}/include

clean:
	rm -f ${GENERATED}
