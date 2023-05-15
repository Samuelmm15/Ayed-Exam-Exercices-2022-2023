text0 =
text1 = Compilación del proyecto...
text2 = Modo de empleo:
text3 = ./exercice-6
text4 = Se han eliminado el fichero ejecutable y los ficheros objetos.
text5 = clear; make clean; make; clear; ./exercice-6

CC=g++
CXXFLAGS=-g -std=c++14

OBJS = exercice-6.o

all: ${OBJS}
		@echo $(text0)
		@echo $(text1)
		$(CC) $(CXXFLAGS) -o exercice-6 ${OBJS}
		@echo $(text0)
		@echo $(text2)
		@echo $(text3)

clean:
	rm -rf *.o exercice-6
	@echo $(text4)