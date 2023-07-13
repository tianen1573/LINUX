libTest.so: myprint.o mymath.o
	gcc -shared mymath.o myprint.o -o libTest.so
mymath.o:mymath.c
	gcc -fPIC -c mymath.c -o mymath.o
myprint.o:myprint.c
	gcc -fPIC -c myprint.c -o myprint.o

.PHONY:output
output:
	mkdir -p output/lib
	mkdir -p output/include
	cp -rf *.h output/include
	cp -rf *.so output/lib
	rm -r *.o *.so

.PHONY:clean
clean:
	rm -rf *.o libTest.a output