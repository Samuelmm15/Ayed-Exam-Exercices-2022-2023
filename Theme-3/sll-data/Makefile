text0 =
text1 = Compilación del proyecto...
text2 = Modo de empleo:
text3 = ./main_sll
text4 = Se han eliminado el fichero ejecutable y los ficheros objetos.
text5 = clear; make clean; make; clear; ./main_sll

CC=g++
CXXFLAGS=-g -std=c++14

OBJS = main_sll.o

all: ${OBJS}
		@echo $(text0)
		@echo $(text1)
		$(CC) $(CXXFLAGS) -o main_sll ${OBJS}
		@echo $(text0)
		@echo $(text2)
		@echo $(text3)

clean:
	rm -rf *.o main_sll
	@echo $(text4)