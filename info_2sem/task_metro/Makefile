all: source.o
	gcc -m32 -o solution source.o
source.o: source.asm
	nasm -felf source.asm
clean:
	rm source.o || echo ""