TARGET:../bin/main

../bin/main.o:../src/main.cpp
	g++ -std=c++17 -c -I main -o ../bin/main.o ../src/main.cpp

../bin/test.o:../src/test.cpp
	g++ -std=c++17 -c -I test -o ../bin/test.o ../src/test.cpp

../bin/main:../bin/main.o ../bin/test.o
	g++ -std=c++17 -L. -o ../bin/main ../bin/main.o ../bin/test.o -lgtest -lgtest_main -pthread

remove:
	rm -f ../bin/*.o
clean:
	make remove
	rm -f ../bin/main

run:
	./../bin/main