proj6.x: proj6.o
	g++ -o proj6.x proj6.o -std=c++11
proj6.o: proj6.cpp
	g++ -c proj6.cpp -std=c++11

clean:
	rm *.o
