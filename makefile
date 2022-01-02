all: teste
teste: main.o funçoes_basicas.o instruçoes_01.o show_things.o
	gcc -o teste main.o funçoes_basicas.o instruçoes_01.o show_things.o
main.o: main.c heade.h
	gcc -o main.o main.c -c -W 
funçoes_basicas.o: funçoes_basicas.c heade.h
	gcc -o funçoes_basicas.o funçoes_basicas.c -c
instruçoes_01.o: instruçoes_01.c heade.h
	gcc -o instruçoes_01.o instruçoes_01.c -c
show_things.o: show_things.c heade.h
	gcc -o show_things.o show_things.c -c
clean:
	rm -rf *.o *~ teste