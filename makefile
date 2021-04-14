main:  main.o extarray.o sortedlist.o
	g++ -g main.o extarray.o sortedlist.o -o main

main.o: main.cpp
	g++ -Wall -g -c main.cpp


extarray.o: extarray.cpp
	g++ -Wall -g -c extarray.cpp

sortedlist.o: sortedlist.cpp
	g++ -Wall -g -c sortedlist.cpp


clean:
	rm -f *.o	
