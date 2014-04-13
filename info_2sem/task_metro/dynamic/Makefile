liblibrary.so: library.asm
	nasm -felf library.asm
	gcc -m32 -shared -o liblibrary.so library.o

clean:
	rm -f *.o *.so