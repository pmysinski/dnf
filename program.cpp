using namespace std;
#include "dnf.h"

using namespace std;

int main(int ile, char *parametry[]) {
 
 dnf DNF;
 DNF.wczytaj("dane.dat");   
 DNF.wyswietl();   
 DNF.oblicz();
 system("PAUSE");
 
 return 0;   
}



