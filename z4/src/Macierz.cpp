#include "Macierz.hh"
#include <cmath>
#include <complex>
#define ERR 0.0000001
/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz<T, Wymiar>, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

/*
 * Przeciazenie operatora indeksowania [] dla Macierzy
 * typu const.
*/
template <typename T, int Wymiar> 
    const Wektor<T, Wymiar> & Macierz<T, Wymiar>::operator[] (int indeks) const{
        if (indeks < 0 || indeks > ROZMIAR)
  {
    cerr << "Blad, zly indeks wektora";
    exit(1);
  }
  return kol[indeks];
  }
/*
 * Przeciazenie operatora indeksowania [] dla Macierzy
 * dowolnego typu.
*/
template <typename T, int Wymiar> 
    Wektor<T, Wymiar> & Macierz<T, Wymiar>::operator[] (int indeks){
        if (indeks < 0 || indeks > ROZMIAR)
  {
    cerr << "Blad, zly indeks wektora";
    exit(1);
  }
  return kol[indeks];
  }


/*
 * Metoda wyliczajaca wyznacznik macierzy
 *  za pomoca metody Gaussa-Jordana.
 */
template <typename T, int Wymiar>
void Macierz<T, Wymiar>::Przekatna(int &z) {
    //sprawdzenie czy na przekątnej znajduje sie 0
    for (int i = 0; i < ROZMIAR; i++) {
        if (abs(kol[i][i])<ERR) { //jesli tak zamiana wierszy
            for (int j = i; j < ROZMIAR; j++) { //szukamy wiersza z ktorym mozemy zamienic
                if (abs(kol[j][i])>ERR) {
                    z = z * -1;
                    for (int k = 0; k < ROZMIAR; k++) {
                        swap(kol[i][k], kol[j][k]);
                    }
                }
            }
        }
    }
}

/* !
* Realizuje zerowanie wierszy macierzy metoda eliminacji Gaussa
*/
template <typename T, int Wymiar>
void Macierz<T, Wymiar>::Gauss(T &det) {
    T s; //zmienna potrzebna przy zerowaniu wierszy
    for (int j = 0; j < ROZMIAR - 1; j++) { //dla liczenia stalej matrix[i][j]/matrix[j][j]
        if (abs(kol[j][j])>ERR) { //sprawdzenie aby uniknac dzielenia przez 0
            for (int i = j + 1; i < ROZMIAR; i++) { //porusza sie po wierszach
                s = (kol[i][j] / kol[j][j]);
                for (int k = 0; k < ROZMIAR; k++) { //porusza sie po kolumnach
                    kol[i][k] = kol[i][k] - kol[j][k] * s;
                }
            }
        } else
            det = kol[j][j];
    }
}


/*!
* Realizuje wyliczenie wyznacznika macierzy
*/
template <typename T, int Wymiar>
T Macierz<T, Wymiar>::Wyznacznik() const {
    T det;
    Macierz<T, Wymiar> tmp;
    tmp = *this;
    int z = 1; //zmienna potrzebna do zmiany znaku jesli zamienimy wiersze
    tmp.Przekatna(z); //sprawdzenie czy na przekatnej nie ma zera
    tmp.Gauss(det); //zerowanie wierszy


        for (int i = 0; i < ROZMIAR; i++) {
            if (i == 0) {
                det = tmp[i][i];
            }
            else {
                det = det * tmp[i][i];
            }
        }
        det = det * z;

        return det;
}


/*
 * Metoda sluzy do transponowania Macierzy.
 */
template <typename T, int Wymiar> 
   Macierz<T, Wymiar> Macierz<T, Wymiar>::transpozycja() const{
    Macierz<T, Wymiar> tmp;
      for( int i = 0; i < ROZMIAR; i++ ){
        for( int j = 0; j < ROZMIAR; j++ )

          tmp[i][j] = this->kol[j][i];
        }
      return tmp;
  }

/*
 * Metoda jest przeciazeniem operacji dodawania
 * do siebie dwoch Macierzy, zwraca kopie.
 */
template <typename T, int Wymiar> 
  Macierz<T, Wymiar> Macierz<T, Wymiar>::operator + (const Macierz<T, Wymiar> & M) const{
      Macierz<T, Wymiar> Wynik;
      for( int i = 0; i < ROZMIAR; i++ ){
        for( int j = 0; j < ROZMIAR; j++)

        Wynik[i][j] = this->kol[i][j] + M[i][j];
        }
        return Wynik;
  }

/*
 * Metoda jest przeciazeniem operacji odejmowania
 * od siebie dwoch Macierzy, zwraca kopie.
 */
template <typename T, int Wymiar> 
   Macierz<T, Wymiar> Macierz<T, Wymiar>::operator - (const Macierz<T, Wymiar> & M) const{
      Macierz<T, Wymiar> Wynik;
      for( int i = 0; i < ROZMIAR; i++ ){
        for( int j = 0; j < ROZMIAR; j++)
        
        Wynik[i][j] = this->kol[i][j] - M[i][j];
        }
        return Wynik;
  }

/*
 * Metoda jest przeciazeniem operacji mnozenia 
 * przez siebie dwoch Macierzy, zwraca kopie.
 */
template <typename T, int Wymiar> 
    Macierz<T, Wymiar> Macierz<T, Wymiar>::operator * (const Macierz<T, Wymiar> & M) const{
        Macierz<T, Wymiar> Wynik;
     for( int h = 0; h < ROZMIAR; h++ ){
      for( int i = 0; i < ROZMIAR; i++ )
        for( int j = 0; j < ROZMIAR; j++ )

        Wynik[h][i] += this->kol[h][j] * M[i][j];
        }
        return Wynik;
    }

/*
 * Metoda jest przeciazeniem operacji mnozenia
 * przez siebie Macierzy i wektora, zwraca kopie.
 */
template <typename T, int Wymiar> 
     Wektor<T, Wymiar> Macierz<T, Wymiar>::operator * (const Wektor<T, Wymiar> & W) const{
         Wektor<T, Wymiar> Wynik;
      for( int i = 0; i < ROZMIAR; i++ ){
        for( int j = 0; j < ROZMIAR; j++)

        Wynik[i] = this->kol[i][j] * W[j];
        }
        return Wynik;
     }

/*
 * Funkcja przeciazajaca operator 
 * przesuniecia bitowego w prawo.
 */
template <typename T, int Wymiar> 
     istream& operator >> (istream &Strm, Macierz<T, Wymiar> &Mac){
         for ( int i = 0; i < ROZMIAR; i++ ){
            for ( int j = 0; j < ROZMIAR; j++ )

            Strm >> Mac[i][j];
            }
            return Strm;
     }

/*
 * Funkcja przeciazajaca operator
 * przesuniecia bitowego w lewo.
 */
template <typename T, int Wymiar> 
     ostream& operator << (ostream &Strm, const Macierz<T, Wymiar> &Mac){
         for ( int i = 0; i < ROZMIAR; i++ ){
           Strm << endl;
            for ( int j = 0; j < ROZMIAR; j++ ){
                Strm << Mac[i][j];
                Strm << ' ';
            }}
            return Strm;
     }