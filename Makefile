basedir = .
incl = ${basedir}/include
obj = ${basedir}/obj
src = ${basedir}/src
lib = ${basedir}/lib
bin = ${basedir}/bin

CXX = gcc

LDLIBS = -lstdc++ -lsfml-window -lsfml-system -lsfml-graphics 

LDFLAGS = -L${lib}

source = $(wildcard ${src}/*.cc)

objects = $(patsubst src/%.cc, obj/%.o, $(source))

Mailman : ${objects}
	${CXX} ${objects} -o ${bin}/Mailman -L${lib} ${LDFLAGS} ${LDLIBS}

${obj}/%.o : ${src}/%.cc
	${CXX} $^ -c -g -o $@ 

.PHONY: clean
	
clean :
	rm -i ${bin}/Mailman ${objects}
