CFLAGS = -Wall -I.
CXX = g++
TARGET = ceasarcipher
# SOURCES = ceasar_encrypt.cpp ceasar_decrypt.cpp main.cpp
DEPS = ceasar_encrypt.h ceasar_decrypt.h
OBJ = ceasar_encrypt.o ceasar_decrypt.o main.o

all: $(TARGET)
clean:
	rm -f *~ *.o *.obj $(TARGET)

distclean: clean
	rm -f Makefile

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS)

ceasarcipher: $(OBJ)
	$(CXX) -o $@ $^ $(CFLAGS)
