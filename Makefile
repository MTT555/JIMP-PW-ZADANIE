all:
	gcc -Wall --pedantic src/*.c -o bin/gauss

test: all
	bin/gauss dane/A dane/b
test2: all
	bin/gauss dane/A2 dane/b2
