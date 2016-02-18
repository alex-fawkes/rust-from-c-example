all: test.exe

mylib.lib: mylib.rs
	rustc mylib.rs

test.exe: test.cpp fawkes/math.cpp mylib.lib
	clang++ -std=c++11 -I. -o test.exe test.cpp fawkes/math.cpp mylib.lib

clean:
	del *.exe 2>NUL
	del *.lib 2>NUL
