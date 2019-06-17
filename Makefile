CFLAGS=-Wall -std=c++11
# nume necesar (build)
build: build-p1 build-p2 build-p3 build-p4

build-p1:
	g++ $(CFLAGS) src/p1.cpp -o p1

build-p2:
	g++ $(CFLAGS) src/p2.cpp -o p2

build-p3:
	g++ $(CFLAGS) src/p3.cpp -o p3

build-p4:
	g++ $(CFLAGS) src/p4.cpp -o p4

run-p1:      # nume necesar
	./p1

run-p2:      # nume necesar
	./p2

run-p3:      # nume necesar 
	./p3

run-p4:      # nume necesar 
	./p4

clean:		 # nume necesar
	rm -f p1 p2 p3 p4