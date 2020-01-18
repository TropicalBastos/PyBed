
CXX_COMPILER = g++
CXX_FLAGS = -std=c++11
LINKER_OPTIONS = -L ../build/ -lPyBed -lpython2.7
INCLUDE_OPTIONS = -I../include/ -I${PYTHON_PATH}

OUTPUT = -o test.out
SOURCES = test.cpp

test.out: 
	$(CXX_COMPILER) $(CXX_FLAGS) $(OUTPUT) $(SOURCES) \
	$(INCLUDE_OPTIONS) $(LINKER_OPTIONS)

clean: 
	rm test.out

.PHONY: clean