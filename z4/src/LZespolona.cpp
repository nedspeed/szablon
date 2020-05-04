#include "LZespolona.hh"
#include <cmath>
#include <climits>
using std::cout;
using std::endl;
using std::cin;
using std::showpos;
using std::noshowpos;

double abs(LZespolona L){
  return abs(L.re);
}

LZespolona operator * (LZespolona Skl1, int Skl2){
  Skl1.re = Skl1.re * Skl2;
  Skl1.im = Skl1.im * Skl2;
  return Skl1;
}
/*
 * Realizuje przeciazenie operatora =
 * dla liczby zespolonej.
 */
LZespolona & LZespolona::operator = (double Skl1){
  this->im = 0;
  this->re = Skl1;
  return *this;
}

/*
 * Realizuje przeciazenie operatora +=
 * dla liczby zespolonej.
 */
LZespolona operator += (LZespolona & Skl1, LZespolona Skl2){
  Skl1 = Skl1 + Skl2;
  return Skl1;
}
/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik odejmowania,
 *    Skl2 - drugi skladnik odejmowania.
 * Zwraca:
 *    Roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator - (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnozenia,
 *    Skl2 - drugi skladnik mnozenia.
 * Zwraca:
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator * (LZespolona Skl1, LZespolona Skl2)
{
  
  LZespolona Wynik;
  Wynik.re = Skl1.re * Skl2.re;
  Wynik.im = Skl1.im * Skl2.im;
  return Wynik;
}

/*!
 * Realizuje sprzezenie liczby zespolonej.
 * Argumenty:
 *    Skl2 -  skladnik sprzegany.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona Sprzezenie(LZespolona Skl2)
{
  LZespolona Wynik;
  Wynik.re = Skl2.re;
  Wynik.im = -Skl2.im;
  return Wynik;
}

/*!
 * Realizuje obliczenie modulu liczby zespolonej z mianownika.
 * Argumenty:
 *    skl -  skladnik przekazany,
 * Zwraca:
 *    Modul skladnika przekazanego jako parametr.
 */
double Modul2(LZespolona skl)
{
  double m = (sqrt((skl.re * skl.re) + (skl.im * skl.im)));
    return m;
}

/*!
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dzielenia,
 *    Skl2 - drugi skladnik dzielenia.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator / (LZespolona Skl1, LZespolona Skl2)
{
    LZespolona wynik;
    double m;
    LZespolona kopia;

    kopia = Sprzezenie(Skl2);

    m = Modul2(Skl2);

    if(m>0){
        wynik = (Skl1*kopia)/(m*m);
    }
    else
        std::cout << "Modul z tej liczby zespolonej to 0, brak mozliwosci dzielenia." << std::endl;


    return wynik;
}

/*!
 * Realizuje dzielenie liczby zespolonej przez liczbe rzeczywista.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dzielenia,
 *    Skl2 - drugi skladnik dzielenia.
 * Zwraca:
 *    Iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator / (LZespolona Skl1, double Skl2)
{
  LZespolona Wynik;
  if(Skl2 > 0)
  {
  Wynik.re = Skl1.re/Skl2;
  Wynik.im = Skl1.im/Skl2;
  }
  else
    std::cout << "Nie mozna dzielic przez 0." << std::endl;
  
  return Wynik;
}


/*!
 * Realizuje przeciazanie operatora dla wczytywania liczby zespolonej.
 * Argumenty:
 *    str - strumien wejscia
 *    lz - argument, ktory funkcja ma wczytac,
 *Zwraca:
 *      Referencje do obiektu istream
 */
std::istream & operator >> (std::istream & str, LZespolona & lz){
    char t[3];
    str >> t[0] >> lz.re >> lz.im >> t[1] >> t[2];
    for (int i=2;((t[0]!='('||t[1]!='i'||t[2]!=')')&&(i>0));i--){

        std::cout << "Blad wprowadzenia liczby. Liczba pozostalych prob: " << i << " Sprobuj jeszcze raz:";
        std::cin.clear();
        std::cin.ignore(INT_MAX,'\n');
        str >> t[0] >> lz.re >> lz.im >> t[1] >> t[2];
    }
    return str;
}


/*!
 * Realizuje przeciazanie operatora dla wyswietlania liczby zespolonej.
 * Argumenty:
 *    str - strumien wyjscia
 *    lz - argument, ktory funkcja ma wyswietlic,
 *Zwraca:
 *      Referencje do obiektu ostream
 */
std::ostream & operator << (std::ostream & str, const LZespolona lz){

    return str << "(" <<lz.re << std::showpos << lz.im << "i)" << std::noshowpos;
}

/*
 * Realizuje sprawdzenie, czy odpowiedz jest poprawna
 * Argumenty:
 *    p - prawidlowa odpowiedz
 *    u  - odpowiedz uzytkownika
 * Zwraca:
 *   0-gdy odpowiedz jest poprawna
 *   1-gdy odpowiedz nie jest poprawna
 */

int Sprawdz (LZespolona p, LZespolona u){
    int r;
    if(Modul2(p-u) < 0.000000000000000000000000000001){
        std::cout << "Poprawna odpowiedz." << std::endl;
        r = 0;
    }
    else {
        std::cout << "Zla odpowiedz." << std::endl;
        r = 1;
    }
    return r;
}
