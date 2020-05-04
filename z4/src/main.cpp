#include <iostream>
#include "UkladRownanLiniowych.hh"


int main()
{

UkladRownanLiniowych<double, 5> R;
 
  cout << endl << " Start programu " << endl << endl;
  cout << "Podaj plik dla liczb rzeczywistych" << endl;
  cin >> R;
  cout << "Uklad rownan to" << endl;
  cout << R;
  cout << "Macierz wspolczynnikow to" << endl;
  cout << R.wez_macierz() << endl;
  cout << "Wektor wyrazow wolnych to:" << endl;
  cout << R.wez_wektor() << endl;
    cout << "Rozwiazania ukladu rownan to:";
      cout << endl;
        for( int j = 0; j < ROZMIAR; j++){
            cout << 'x';
            cout << j+1;
            cout << ' ';
        }
        cout << endl;
  Wektor<double, 5> Rozw = R.RozwUkl();
    cout << "Wektor bledu to:" << endl;
    Wektor<double, 5> Blad = R.LiczBlad(Rozw);
    cout << Blad << endl;
      
      UkladRownanLiniowych<LZespolona,5> Z;
      cout << "Podaj plik dla liczb zespolonych" << endl;
  cin >> Z;
  cout << "Uklad rownan to" << endl;
  cout << Z;
  cout << "Macierz wspolczynnikow to" << endl;
  cout << Z.wez_macierz() << endl;
  cout << "Wektor wyrazow wolnych to:" << endl;
  cout << Z.wez_wektor() << endl;
    cout << "Rozwiazania ukladu rownan to:";
      cout << endl;
        for( int j = 0; j < ROZMIAR; j++){
            cout << 'x';
            cout << j+1;
            cout << ' ';
        }
        cout << endl;
  Wektor<LZespolona, 5> Roz = Z.RozwUkl();
    cout << "Wektor bledu to:" << endl;
    Wektor<LZespolona, 5> Bl = Z.LiczBlad(Roz);
    cout << Bl << endl;
return 0;
}
