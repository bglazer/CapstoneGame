basedir = .
incl = ${basedir}/include
obj = ${basedir}/obj
src = ${basedir}/src
lib = ${basedir}/lib
bin = ${basedir}/bin

CXX = gcc

LDLIBS = -lstdc++ -lmingw32 -lSDLmain -lSDL -lSDL_image -lchipmunk -lSDL_ttf \
    -lSDL_mixer

LDFLAGS = -L${lib}

objects = $(addprefix ${obj}/, GameObject.o PhysicalObject.o \
Terrain.o Timer.o main.o ImageLoader.o Player.o Block.o StaticBlock.o)

Cyborg : ${objects}
	${CXX} ${objects} -o ${bin}/Cyborg.exe -L${lib} ${LDFLAGS} ${LDLIBS}

${obj}/%.o : ${src}/%.cc
	${CXX} $^ -c -g -o $@ 

.PHONY: clean
	
clean :
	rm ${bin}/Cyborg.exe ${objects}