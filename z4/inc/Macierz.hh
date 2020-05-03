#ifndef MACIERZ_HH
#define MACIERZ_HH

#include <iostream>
#include "Wektor.hh"
#include <cmath>
/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
template <typename T, int Wymiar>
class Macierz {   
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
    Wektor<T, Wymiar> kol[Wymiar]; //wk-wiersze kolumny
  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */    
  Macierz<T, Wymiar>() = default; //domyslny konstruktor
  Macierz<T, Wymiar>( Wektor<T, Wymiar> kol[Wymiar] ); //konstruktor

  const Wektor<T, Wymiar> & operator[] (int indeks) const; //przeciazenie indeksow dla macierzy typu const
  Wektor<T, Wymiar> & operator[] (int indeks); //przeciazenie indeksow dla macierzy dowolnego typu
  T Wyznacznik () ; // liczenie wyznacznika Gauss-Jordan
  Macierz<T, Wymiar> transpozycja() const; // transponowanie macierzy
  Macierz<T, Wymiar> operator + (const Macierz<T, Wymiar> & M) const; // przeciazenie operatora dodawania dwoch macierzy
  Macierz<T, Wymiar> operator - (const Macierz<T, Wymiar> & M) const; // przeciazenie operatora odejmowania dwoch macierzy
  Macierz<T, Wymiar> operator * (const Macierz<T, Wymiar> & M) const; // przeciazenie operatora mnozenia dwoch macierzy
  Wektor<T, Wymiar> operator * (const Wektor<T, Wymiar> & W) const; //przeciazenie operatora mnozenia macierzy i Wektor<T, Wymiar>a
};


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
istream& operator >> (istream &Strm, Macierz<T, Wymiar> &Mac);

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
ostream& operator << (ostream &Strm, const Macierz<T, Wymiar> &Mac);


#endif
