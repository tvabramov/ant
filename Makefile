CXX=g++
CXXFLAGS=-I./src/ -std=c++17
DEPS = src/counters/brute_counter.h
OBJS = src/ant.o src/counters/brute_counter.o

all: ant

%.o: %.c $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

ant: $(OBJS)
	$(CXX) -o $@ $^ $(CXXFLAGS)

.PHONY: clean

test: all
	python test.py

clean:
	rm *.o ant
