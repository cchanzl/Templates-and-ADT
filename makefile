main:  main.o extarray.o sortedlist.o map.o
	g++ -g main.o extarray.o sortedlist.o map.o -o main

main.o: main.cpp
	g++ -Wall -g -c main.cpp


extarray.o: extarray.cpp
	g++ -Wall -g -c extarray.cpp

sortedlist.o: sortedlist.cpp
	g++ -Wall -g -c sortedlist.cpp

map.o: map.cpp
	g++ -Wall -g -c map.cpp


clean:
	rm -f *.o	
