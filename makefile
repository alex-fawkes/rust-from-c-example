all: test.exe

mylib.lib: mylib.rs
	rustc mylib.rs

test.exe: test.cpp mylib.lib
	clang++ -std=c++11 -o test.exe test.cpp mylib.lib

clean:
	del *.exe
	del *.lib
