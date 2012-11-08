#
# Makefile for UN*X-like systems
#

# Change this line if you want a different compiler
CXXC = g++ -Wall -W -Werror -I. -I../src

TESTGEN = /usr/bin/cxxtestgen

TARGETS = error_printer
TESTS = *.h
OBJ = ../src/ceasar_encrypt.o ../src/ceasar_decrypt.o


all: $(TARGETS)

.PHONY: clean
clean:
	rm -f *~ *.o *.obj $(TARGETS)
	rm -f tests.cpp error_printer.cpp

.PHONY: distclean
distclean: clean
	rm -f Makefile

.PHONY: run
run: error_printer
	./error_printer

error_printer.cpp: $(TESTS)
	$(TESTGEN) -o $@ --error-printer $(TESTS)

tests.cpp: $(TESTS)
	$(TESTGEN) -o $@ $(TESTS)

%: %.cpp $(OBJ)
	$(CXXC) -o $@ $< $(OBJ)

