#include "Wektor.hh"
using namespace std;

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Wektor, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
/*
 * Metoda klasy wektor obliczajaca 
 * dlugosc danego wektora.
 */
template <typename T, int Wymiar> 
T Wektor<T,Wymiar>::dlugosc() const{
  T Wynik;
  T tmp;
  for( int i = 0; i < Wymiar; i++){
  tmp += this->dane[i]*this->dane[i];
}
Wynik = sqrt(tmp);
return Wynik;
}
  
/*
 * Metoda przeciazajaca operacje
 * mnozenia wektora przez wektor.
 */
template <typename T, int Wymiar> 
  T Wektor<T,Wymiar>::operator * (const Wektor<T,Wymiar> &W2) const{
      T Wynik = 0;
for(int i = 0; i < Wymiar; i++)
    Wynik += this->dane[i] * W2.dane[i];
return Wynik;
  }

/*
 * Metoda przeciazajaca operacje
 * dodawania do siebie dwoch wektorow.
 */
template <typename T, int Wymiar> 
  Wektor<T,Wymiar> Wektor<T,Wymiar>::operator + (const Wektor<T,Wymiar> &W2) const{
      Wektor<T,Wymiar> Wynik;
for(int i = 0; i < Wymiar; i++)
    Wynik.dane[i] = this->dane[i] + W2.dane[i];
return Wynik;
  }
  
/*
 * Metoda przeciazajaca operacje
 * odejmowania od siebie dwoch wektorow.
 */
template <typename T, int Wymiar> 
  Wektor<T,Wymiar> Wektor<T,Wymiar>::operator - (const Wektor<T,Wymiar> &W2) const{
      Wektor<T,Wymiar> Wynik;
for(int i = 0; i < Wymiar; i++)
    Wynik.dane[i] = this->dane[i] - W2.dane[i];
return Wynik;
  }

/*
 * Metoda przeciazajaca operator []
 * indeksowania dla wektora typu const.
 */
template <typename T, int Wymiar> 
  const T & Wektor<T,Wymiar>::operator [] (int indeks) const{
  if (indeks < 0 || indeks > Wymiar)
  {
    cerr << "Blad, zly indeks wektora";
    exit(1);
  }
    return dane[indeks];
  }

/*
 * Metoda przeciazajaca operator []
 * indeksowania dla wektora dowolnego typu.
 */
template <typename T, int Wymiar> 
  T & Wektor<T,Wymiar>::operator [] (int indeks){
  if (indeks < 0 || indeks > Wymiar)
  {
    cerr << "Blad, zly indeks wektora";
    exit(1);
  }
    return dane[indeks];
  }


/*
 * Funkcja przeciazajaca operator
 * przesuniecia bitowego w prawo.
 */
template <typename T, int Wymiar> 
  std::istream& operator >> (std::istream &Strm, Wektor < T, Wymiar>  &W){
      for(int i = 0; i < ROZMIAR; i++){
        Strm>>W[i];
      }

      return Strm;
  }

/*
 * Funkcja przeciazajaca operator
 * przesuniecia bitowego w lewo.
 */
template <typename T, int Wymiar> 
  std::ostream& operator << (std::ostream &Strm, const Wektor < T, Wymiar>  &W){
      for(int i = 0; i < ROZMIAR; i++){
        Strm << W[i];
        Strm << ' ';
        }
        return Strm;
  }