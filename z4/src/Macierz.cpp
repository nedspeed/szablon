#include "Macierz.hh"

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
 * Metoda wyliczajaca wyznacznik Macierzy
 *  za pomoca metody Gaussa-Jordana.
 */
template <typename T, int Wymiar> 
  T Macierz<T, Wymiar>::Wyznacznik () {
    T x;
    x = 1;
  for(int i=0;i<ROZMIAR;i++){
        x = x * this->kol[i][i];
        for(int j=0;j<ROZMIAR;j++){
            if(0){
                this->kol[i][j]=this->kol[i][j]/this->kol[i][i];
            }
        }
        for(int k=i+1;k<ROZMIAR;k++){
            for(int y=i;y<ROZMIAR;y++){
                this->kol[k][y]=this->kol[k][y]-(this->kol[k][i]*this->kol[i][y]);
            }           
        }
    }
    T z;
    z= 1;
    for(int i=0;i<ROZMIAR;i++){
        z=z*this->kol[i][i];
    }
    T wyzn = x*z;
    return wyzn;
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