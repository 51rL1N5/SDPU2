BASEDIR	=

CC	=	g++
CXX	=	g++
CPPFLAGS = -Wall -O2 -I ${BASEDIR}/include
CFLAGS =
LDFLAGS = -L ${BASEDIR}/lib
LDLIBS =	-lsystem_tools	-lsocket_linux

GENERATED	=	main	#programas_outros


all:	${GENERATED}

build:
	cd	src/tools	&&	${MAKE}	install
	cd	src/socket	&&	${MAKE}	install

clean:
	rm -f ${GENERATED}
