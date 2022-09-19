
all:	
	
	gcc -Wall -g -std=c90 -c -Wall libpilha.c
	gcc -Wall -g -std=c90 -c -Wall liblista.c
	gcc -Wall -g -std=c90 -c -Wall libfila.c
	gcc -Wall -g -std=c90 -c -Wall ru_na_pandemia.c

	gcc -Wall -g -std=c90 ru_na_pandemia.o libpilha.o liblista.o libfila.o -o ru_na_pandemia

 
run:
	./ru_na_pandemia
	

clean:
	rm *.o ru_na_pandemia
	
	
