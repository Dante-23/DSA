TARGET:../bin/main

../bin/main.o:../main.cpp
	g++ -std=c++17 -c -I main -o ../bin/main.o ../main.cpp

../bin/sqrt_decom.o:../src/sqrt_decomposition.cpp
	g++ -std=c++17 -c -I test -o ../bin/sqrt_decom.o ../src/sqrt_decomposition.cpp

../bin/main:../bin/main.o ../bin/sqrt_decom.o
	g++ -std=c++17 -L. -o ../bin/main ../bin/main.o ../bin/sqrt_decom.o -pthread

remove:
	rm -f ../bin/*.o
clean:
	make remove
	rm -f ../bin/main

run:
	./../bin/main