CC=gcc
CFLAGS=-I. -I/opt/intel/intel-sdk/include -L/opt/intel/intel-sdk/lib64 -v
DEPS=pgm.h
OBJ=07_fftImg.o
LIBS=-lm -lOpenCL

%.o : %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

fft.out: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -rf *.o *.out 
