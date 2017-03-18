# Swig diag

PYTHONINCLUDES := $(shell python-config --cflags)
PYTHONLIBS := $(shell python-config --ldflags)

all: main.cpp
	g++ -std=c++14 -c main.cpp -fPIC -o main.o $(PYTHONINCLUDES)
	g++ -std=c++14 main.o  $(PYTHONLIBS)

test: all
	python ./test_py_only.py
	./a.out
