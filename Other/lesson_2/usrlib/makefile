libTest.a: myprint.o mymath.o
	ar -rc libTest.a mymath.o myprint.o
mymath.o:mymath.c
	gcc -c mymath.c -o mymath.o
myprint.o:myprint.c
	gcc -c myprint.c -o myprint.o

.PHONY:output
output:
	mkdir -p output/lib
	mkdir -p output/include
	cp -rf *.h output/include
	cp -rf *.a output/lib
	rm -r *.o *.a

.PHONY:clean
clean:
	rm -rf *.o libTest.a output