#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic -std=c++17

__start__: uklad_rownan 
	./uklad_rownan

uklad_rownan: obj/main.o obj/SWektor.o obj/LZespolona.o obj/SMacierz.o obj/SURL.o
	g++ -Wall -pedantic -o uklad_rownan obj/main.o obj/SWektor.o obj/LZespolona.o obj/SMacierz.o obj/SURL.o\

obj/main.o: src/main.cpp inc/UkladRownanLiniowych.hh\
        inc/rozmiar.h
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp


obj/SWektor.o: src/SWektor.cpp src/Wektor.cpp inc/Wektor.hh inc/rozmiar.h
	g++ ${CPPFLAGS} -o obj/SWektor.o src/SWektor.cpp

obj/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh
	g++ ${CPPFLAGS} -o obj/LZespolona.o src/LZespolona.cpp

obj/SMacierz.o: src/SMacierz.cpp src/Macierz.cpp inc/Macierz.hh 
	g++ ${CPPFLAGS} -o obj/SMacierz.o src/SMacierz.cpp

obj/SURL.o: src/SURL.cpp src/UkladRownanLiniowych.cpp inc/UkladRownanLiniowych.hh 
	g++ ${CPPFLAGS} -o obj/SURL.o src/SURL.cpp
clean:
	rm -f obj/*.o uklad_rownan
