#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH
#include "Wektor.hh"
#include "Macierz.hh"
#include <iostream>

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
template <typename T, int Wymiar>
class UkladRownanLiniowych {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
  Macierz<T, Wymiar> Wsp; //macierz wspolczynnikow
  Wektor<T, Wymiar> Wol; //Wol - wektor wyrazow wolnych
   //Rozw - rozwiazan, Blad - wektor bledu, Wyzn - wyznacznikow posrednich
   //WzG - WyznacznikGlowny, L - dlugosc wektora
  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */    
  UkladRownanLiniowych();  //konstruktor domyslny
  UkladRownanLiniowych(Macierz<T, Wymiar> AA, Wektor<T, Wymiar> BB); //konstruktor

  Wektor<T, Wymiar> WyznKram();
  Wektor<T, Wymiar> RozwUkl() const;
  Wektor<T, Wymiar> LiczBlad(Wektor<T, Wymiar> Rozw);
  const Wektor<T, Wymiar> wez_wektor()const;
  const Macierz<T, Wymiar> wez_macierz() const;
  void zmien_wektor(Wektor<T, Wymiar> Wej);
  void zmien_macierz(Macierz<T, Wymiar> We);
  void zmien_kolumne(int i, Wektor<T, Wymiar> We, Macierz<T, Wymiar> W) const;
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
template <typename T, int Wymiar> 
istream& operator >> (istream &Strm, UkladRownanLiniowych<T, Wymiar> &UklRown);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
template <typename T, int Wymiar> 
ostream& operator << (ostream &Strm, const UkladRownanLiniowych<T, Wymiar> &UklRown);


#endif
