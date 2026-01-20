CC = clang++
CFLAGS = -g `llvm-config --cxxflags --ldflags --system-libs --libs core`

all:
	$(CC) main.cpp $(CFLAGS) -o kaleidoscope_compiler

clean:
	rm -f kaleidoscope_compiler
