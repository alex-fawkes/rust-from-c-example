compiler_cpp=clang++
compiler_cpp_flags=-std=c++11 -I.
compile_cpp=$(compiler_cpp) $(compiler_cpp_flags)

all: bin bin/test_cpp.exe bin/test_rust.exe

bin:
	if not exist bin mkdir bin

bin/test_cpp.exe: test.cpp bin/math_cpp.lib
	$(compile_cpp) -o bin/test_cpp.exe test.cpp bin/math_cpp.lib

bin/test_rust.exe: test.cpp bin/math_rust.lib bin/mylib.lib
	$(compile_cpp) -o bin/test_rust.exe test.cpp bin/math_rust.lib bin/mylib.lib

bin/math_cpp.lib: fawkes/math_cpp.cpp
	$(compile_cpp) -c -o bin/math_cpp.lib fawkes/math_cpp.cpp

bin/math_rust.lib: fawkes/math_cpp.cpp
	$(compile_cpp) -c -o bin/math_rust.lib fawkes/math_rust.cpp

bin/mylib.lib: mylib.rs
	rustc --out-dir bin mylib.rs

clean:
	del /q bin >nul 2>&1
