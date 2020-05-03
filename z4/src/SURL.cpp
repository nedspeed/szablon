#include "UkladRownanLiniowych.cpp"

template  class UkladRownanLiniowych<double, ROZMIAR>;
template istream& operator >> (istream &Strm, UkladRownanLiniowych<double, ROZMIAR> &UklRown); 
template ostream& operator << (ostream &Strm, const UkladRownanLiniowych<double, ROZMIAR> &UklRown);

template class UkladRownanLiniowych<LZespolona, ROZMIAR>; 
template istream& operator >> (istream &Strm, UkladRownanLiniowych<LZespolona, ROZMIAR> &UklRown);
template ostream& operator << (ostream &Strm, const UkladRownanLiniowych<LZespolona, ROZMIAR> &UklRown);