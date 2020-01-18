
CXX_COMPILER = g++
CXX_FLAGS = -std=c++11
LINKER_OPTIONS = -L ../ -lPyBed -lpython2.7
INCLUDE_OPTIONS = -I../include/ -I${PYTHON_PATH}

OUTPUT = -o test.out
SOURCES = test.cpp

test.out: 
	$(CXX_COMPILER) $(CXX_FLAGS) $(OUTPUT) \
	$(INCLUDE_OPTIONS) $(LINKER_OPTIONS) $(SOURCES)

clean: 
	rm test.out

.PHONY: clean