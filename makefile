output: main.o resolve.o
	g++ -o resolve main.o resolver.o
	sh info.sh

main.o: main.cpp
	g++ -c main.cpp

resolve.o: resolver.cpp
	g++ -c resolver.cpp

clean:
	rm *.o resolve
