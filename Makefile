all:
	gcc -Wall --pedantic -lm src/*.c -o bin/gauss

test: all
	bin/gauss dane/A dane/b
test2: all
	bin/gauss dane/A2 dane/b2
test3: all
	bin/gauss dane/A3 dane/b3
test4: all
	bin/gauss dane/A4 dane/b4
test5: all
	bin/gauss dane/A5 dane/b5
zeraNaPrzekatnej: all
	bin/gauss dane/zeraNaPrzekatnejA dane/zeraNaPrzekatnejb
	
