default: dist/gcd

dist/gcd: dist build/main.o build/GCD.o
	gcc -o dist/gcd build/main.o build/GCD.o

build/main.o: build src/main.c
	gcc -o build/main.o -c src/main.c

build/GCD.o: build src/GCD.c
	gcc -o build/GCD.o -c src/GCD.c

build:
	mkdir build

dist:
	mkdir dist

clean:
	rm -r build
	rm -r dist
