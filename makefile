main:  main.o extarray.o
	g++ -g main.o extarray.o -o main

main.o: main.cpp
	g++ -Wall -g -c main.cpp


extarray.o: extarray.cpp
	g++ -Wall -g -c extarray.cpp

clean:
	rm -f *.o	
