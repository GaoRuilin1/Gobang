FLAGS = -pedantic-errors -std=c++11 

body.o: body.cpp body.h	
	g++ $(FLAGS) -c $<

main.o: main.cpp body.h
	g++ $(FLAGS) -c $<

main: body.o main.o
	g++ $(FLAGS) body.o main.o -o main

clean:
	rm -f main main.o body.o saved_board.txt

tar:
	tar main main.o body.o saved_board.txt

.PHONY: clean tar
