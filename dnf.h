#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
class dnf {
public:
 void wczytaj(string);   
 void wyswietl(void);   
 void oblicz();
private:
  int czyPuste(int *v);
  void przykladyPozytywne(int *v);
  void przykladyNegatywne(int *v);
  void zeruj(int *v, int n);
  void zeruj(double *v, int n);
  
  int wybierzCeche(int *P, int *N, int *r);

  void ustawCeche(int *r, int f);
  
  void usunNegatywne(int *N, int f);
  
  void generujHipoteze(string &h,int *r);
  
 int usunPozytywne(int *P,int *r);
  
  int czyWszystkieCechy(int *r);
 
private:
        int wiersze;
        int kolumny;
        int **tab;
};
