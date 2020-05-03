#include "UkladRownanLiniowych.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy UkladRownanLiniowych, ktore zawieraja 
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

/*
 *
 */
template <typename T, int Wymiar> 
UkladRownanLiniowych<T, Wymiar>::UkladRownanLiniowych()
{
  Wsp = Macierz<T, Wymiar>();
  Wol = Wektor<T, Wymiar>();
}
template <typename T, int Wymiar> 
UkladRownanLiniowych<T, Wymiar>::UkladRownanLiniowych(Macierz<T, Wymiar> AA, Wektor<T, Wymiar> BB)
{
  Wsp = AA;
  Wol = BB;
}

template <typename T, int Wymiar>
    const Wektor<T, Wymiar> UkladRownanLiniowych<T, Wymiar>::wez_wektor() const{
    return this->Wol;
    }

    template <typename T, int Wymiar>
    const Macierz<T, Wymiar> UkladRownanLiniowych<T, Wymiar>::wez_macierz() const{
    return this->Wsp;
    }

    template <typename T, int Wymiar>
      void UkladRownanLiniowych<T, Wymiar>::zmien_wektor(Wektor<T, Wymiar> Wej){
      Wol = Wej;
    }

    template <typename T, int Wymiar>
      void UkladRownanLiniowych<T, Wymiar>::zmien_macierz(Macierz<T, Wymiar> We){
      Wsp = We;
    }

    template <typename T, int Wymiar>
      void UkladRownanLiniowych<T, Wymiar>::zmien_kolumne(int i, Wektor<T, Wymiar> We, Macierz<T, Wymiar> W) const
    {
    for (int j = 0; j < ROZMIAR; j++)
    {
        swap(W[i][j],We[j]);
    }
}
/*
 *
 */
template <typename T, int Wymiar>
    Wektor<T, Wymiar> UkladRownanLiniowych<T, Wymiar>::WyznKram() {
        Wektor<T, Wymiar> Wyzn;
        UkladRownanLiniowych<T, Wymiar> kopia = *this;
        Wektor<T, Wymiar> tmp = kopia.wez_wektor();
        Macierz<T, Wymiar> tm = kopia.wez_macierz();
        for(int i = 0; i < ROZMIAR; i++){
            kopia.zmien_kolumne(i, tmp, tm);
            Wyzn[i] = tm.Wyznacznik();
            kopia.zmien_kolumne(i, tmp, tm);
        }
        return Wyzn;
    }
/*
 *
 */
template <typename T, int Wymiar>
    Wektor<T, Wymiar> UkladRownanLiniowych<T, Wymiar>::RozwUkl() const{
        UkladRownanLiniowych<T, Wymiar> kopia = *this;
        Macierz<T, Wymiar> tm = kopia.wez_macierz();
        T WzG = tm.Wyznacznik();
        Wektor<T, Wymiar> Wyzn = kopia.WyznKram();
        Wektor<T, Wymiar> Rozw;
        for( int i = 0; i < ROZMIAR; i++){
        Rozw[i] = Wyzn[i]/WzG;
        }
        cout << endl;
        for( int k = 0; k < ROZMIAR; k++){
        cout << Rozw[k];
        cout << ' ';
        }
        cout << endl;
    return Rozw;
    }

template <typename T, int Wymiar>
    Wektor<T, Wymiar> UkladRownanLiniowych<T, Wymiar>::LiczBlad(Wektor<T, Wymiar> Rozw){
        Wektor<T, Wymiar> Blad, tmp;
        UkladRownanLiniowych<T, Wymiar> kopia = *this;
        tmp = kopia.wez_macierz() * Rozw;
        Blad = tmp - kopia.wez_wektor();
        return Blad;
    }

  /*
   *
   */
  template <typename T, int Wymiar>
  istream& operator >> (istream &Strm, UkladRownanLiniowych<T, Wymiar> &UklRown){
     Wektor<T, Wymiar> Wej;
     Macierz<T, Wymiar> We;
     Strm >> We;
     Strm >> Wej;
     UklRown.zmien_wektor(Wej);
     UklRown.zmien_macierz(We);
     return Strm;
     }
  /*
   *
   */
  template <typename T, int Wymiar>
  ostream& operator << (ostream &Strm, const UkladRownanLiniowych<T, Wymiar> &UklRown){
         Wektor<T, Wymiar> Wyj;
         Wyj = UklRown.wez_wektor();
         Macierz<T, Wymiar> Wy;
         Wy = UklRown.wez_macierz();
         for ( int i = 0; i < ROZMIAR; i++ ){
            for ( int j = 0; j < ROZMIAR; j++ ){

            Strm << Wy[i][j];
            Strm << ' ';
            }
            Strm << endl;
            }
            for ( int k = 0; k < ROZMIAR; k++){
            Strm << Wyj[k];
            Strm << ' ';
            }
            Strm << endl;
            return Strm;
     }
     