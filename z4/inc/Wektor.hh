#ifndef WEKTOR_HH
#define WEKTOR_HH
#include "rozmiar.h"
#include <iostream>
#include <cmath>
#include "LZespolona.hh"
using namespace std;
/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
template <typename T, int Wymiar> 
class Wektor{
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
T dane[Wymiar];
//int x,y,z;
//int wymiar;
//double *dane;
  public:
  Wektor<T, Wymiar>() {
    for(int i; i < ROZMIAR; i++)
    dane[i] = 0;
  }
  Wektor<T, Wymiar>(T dane[Wymiar]); //konstruktor od kolekcji
  T operator *(const Wektor<T, Wymiar> &W2) const;  //przeciazenie mnozenia wektor razy wektor
  Wektor<T, Wymiar> operator + (const Wektor<T, Wymiar> &W2) const; //przeciazenie dodawania wektorow
  Wektor<T, Wymiar> operator - (const Wektor<T, Wymiar> &W2) const; //przeciazenie odejmowania wektorow
  const T & operator [] (int indeks) const; //przeciazenie operatora indeksowania dla wektora typu const
  T & operator [] (int indeks); //przeciazenie operatora indeksowania dla wektora dowolnego typu
};
/*Wektor W;
W[2];
const Wektor Wc;
Wc.dlugosc();
Wc[2]=2;
double b = Wc[2]; */
/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 * Przeciazenie operatora przesuniecia bitowego w prawo,
 * za pierwszy argument bierze dana komende(np. cin) ze
 * strumienia wejsciowego z biblioteki std, 
 * a za drugi argument bierze podana macierz.
 */
template <typename T, int Wymiar> 
istream& operator >> (istream &Strm, Wektor<T, Wymiar> &W);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 * Przeciazenie operatora przesuniecia bitowego w lewo,
 * za pierwszy argument bierze dana komende(np. cout) ze
 * strumienia wyjsciowego biblioteki std,
 * a za drugi argument bierze podana macierz.
 */
template <typename T, int Wymiar> 
ostream& operator << (ostream &Strm, const Wektor<T, Wymiar> &W);

#endif
