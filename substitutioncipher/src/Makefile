CFLAGS = -Wall -I.
CXX = g++
TARGET = substitutioncipher
DEPS = substitution_encrypt.h substitution_decrypt.h
OBJ = substitution_encrypt.o substitution_decrypt.o main.o

all: $(TARGET)

.PHONY: clean distclean

clean:
	rm -f *~ *.o *.obj $(TARGET)

distclean: clean
	rm -f Makefile

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CFLAGS)

substitutioncipher: $(OBJ)
	$(CXX) -o $@ $^ $(CFLAGS)
