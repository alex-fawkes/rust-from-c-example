all: test.exe

mylib.lib: mylib.rs
	rustc mylib.rs

test.exe: test.c mylib.lib
	clang -o test.exe test.c mylib.lib

clean:
	del mylib.lib
	del test.exe
