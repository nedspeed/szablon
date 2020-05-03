#include <iostream>
#include <tgmath.h>
#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
using std::istream;
using std::ostream;
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
  LZespolona & operator = (double Skl1);
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */
LZespolona operator += (LZespolona & Skl1, LZespolona Skl2);
LZespolona operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona operator - (LZespolona Skl1, LZespolona Skl2);
LZespolona operator * (LZespolona Skl1, LZespolona Skl2);
LZespolona Sprzezenie(LZespolona Skl2);
double Modul2(LZespolona Skl2);
LZespolona operator / (LZespolona Skl1, LZespolona Skl2);
LZespolona operator / (LZespolona Skl1, double Skl2);
std::istream & operator >> (istream & str, LZespolona & lz);
std::ostream & operator << (ostream & str, const LZespolona lz);
int Sprawdz (LZespolona p, LZespolona u);
#endif
