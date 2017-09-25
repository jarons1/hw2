all: freq encode_bits decode_bits bits.h getnum getnum.h

getnum: getnum.o
	gccx -o getnum getnum.o -lm

getnum.o: getnum.c getnum.h
	gccx -c getnum.c

decode_bits: decode_bits.o 
	gccx -o decode_bits decode_bits.o -lm

decode_bits.o: decode_bits.c bits.h
	gccx -c decode_bits.c

encode_bits: encode_bits.o
	gccx -o encode_bits encode_bits.o -lm

encode_bits.o: encode_bits.c bits.h
	gccx -c encode_bits.c

bits.h: encode_bits.c decode_bits.c
	gccx  bits.h -lm

freq: freq.o
	gccx -o freq freq.o

freq.o: freq.c
	gccx -c freq.c

clean:
	rm -f *.o freq encode_bits decode_bits bits getnum
