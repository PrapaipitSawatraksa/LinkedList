all : main.o LinkedList.o ../ChainNode/ChainNode.o
	g++ main.o LinkedList.o -o LinkedList ../ChainNode/ChainNode.o
main.o : main.cpp 
	g++ -c main.cpp -o main.o
LinkedList.o : LinkedList.cpp
	g++ -c LinkedList.cpp -o LinkedList.o
../ChainNode/ChainNode.o : 
	g++ -c ../ChainNode/ChainNode.cpp -o ../ChainNode/ChainNode.o
clean :
	rm -f *.o LinkedList ../ChainNode/ChainNode.o


