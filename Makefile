basedir = .
incl = ${basedir}/include
obj = ${basedir}/obj
src = ${basedir}/src
lib = ${basedir}/lib
bin = ${basedir}/bin

CXX = g++

LDLIBS = -lstdc++ -lsfml-window -lsfml-system -lsfml-graphics -lBox2D

LDFLAGS = -L${lib}

source = $(wildcard ${src}/*.cc)

objects = $(patsubst ${src}/%.cc, ${obj}/%.o, $(source))

Mailman : ${objects}
	${CXX} ${objects} -o ${bin}/Mailman -L${lib} ${LDFLAGS} ${LDLIBS} 

${obj}/%.o : ${src}/%.cc
	${CXX} $^ -c -ggdb -o $@ 

.PHONY: print

print :
	@echo $(source)  
	@echo $(objects)

.PHONY: clean
	
clean :
	rm -i ${bin}/Mailman ${objects}
