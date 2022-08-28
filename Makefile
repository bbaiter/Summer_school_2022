FLAGS=-Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wmissing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -D_DEBUG -D_EJUDGE_CLIENT_SIDE


all: a.exe start

a.exe: main.o solver.o test.o
	g++ main.o solver.o test.o $(FLAGS)

main.o: main.cpp
	g++ main.cpp -c $(FLAGS)

solver.o: solver.cpp
	g++ solver.cpp -c $(FLAGS)

test.o: test.cpp
	g++ test.cpp -c $(FLAGS)


clean:
	rm main.o solver.o test.o

start:
	a.exe



