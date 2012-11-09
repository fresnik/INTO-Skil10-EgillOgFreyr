CFLAGS = -Wall -I.
CXX = g++
TARGET = ceasarcipher
DEPS = ceasar_encrypt.h ceasar_decrypt.h
OBJ = ceasar_encrypt.o ceasar_decrypt.o main.o

all: $(TARGET)

.PHONY: clean distclean

clean:
	rm -f *~ *.o *.obj $(TARGET)

distclean: clean
	rm -f Makefile

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS)

ceasarcipher: $(OBJ)
	$(CXX) -o $@ $^ $(CFLAGS)
