..\cw\mwcceppc -I- -i ../k_stdlib -Cpp_exceptions off -enum int -O4,s -use_lmw_stmw on -fp hard -rostr -sdata 0 -sdata2 0 -c -o options.o options.cpp -maxerrors 1
..\Kamek\bin\Debug\Kamek options.o -externals=../symbols.txt -versions=../versions.txt -dynamic -output-kamek=$KV$.bin