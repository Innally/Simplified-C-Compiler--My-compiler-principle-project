h1: hw1.y
	bison -d hw1.y
	gcc hw1.tab.c -o hw1
h2: hw2.y
	bison -d hw2.y
	gcc hw2.tab.c -o hw2
h3: hw3.y
	bison -d hw3.y
	gcc hw3.tab.c -o hw3