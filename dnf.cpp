#include "dnf.h"

    void dnf::wczytaj(string nazwa) {
         ifstream plik(nazwa.c_str());
         plik >> wiersze >> kolumny;
         cout << wiersze << " " << kolumny << endl;
         
         tab = new int *[wiersze];
             for (int i=0; i<wiersze; i++)
                 tab[i] = new int [kolumny];
         
         for (int i=0; i<wiersze; i++)
             for (int j=0; j<kolumny; j++)
                 plik >> tab[i][j];
         
         plik.close();
         }
           
    void dnf::wyswietl() {
    	cout << "\nDane:\n";
         for (int i=0; i<wiersze; i++) {
             for (int j=0; j<kolumny; j++)
                 cout << tab[i][j] << " ";
              cout << endl; 
              }
         }
            
    void dnf::oblicz() {
         
         int *P = new int [wiersze];
         int *N = new int [wiersze];
         int *r = new int [kolumny-1];
         string h="";
         int f;
         int porazka = 0;
         
         przykladyPozytywne(P);
         
	         while(czyPuste(P) && porazka == 0){
				zeruj(r,kolumny-1);
				przykladyNegatywne(N);
				
				while(czyPuste(N) && porazka == 0){
					f = wybierzCeche(P,N,r);
					ustawCeche(r,f);
					usunNegatywne(N, f);
					if(czyWszystkieCechy(r)){
						porazka = 1;
					}
					
					
				}
				
				if(usunPozytywne(P,r) == 0)
					porazka = 1;
				generujHipoteze(h,r);
	         }
         
        
         	

        delete N,P,r;
        if(porazka == 0 )
			cout << "\n\nHipoteza:"  << h << endl;
		else
			cout << "\n\nPorazka"  << endl;

}

    int dnf::czyPuste(int *v) {
    	for(int i=0;i<wiersze;i++)
    		if(v[i] == 1)
    			return 1;
		return 0;
}

    void dnf::przykladyPozytywne(int *v) {
    	for(int i=0;i<wiersze;i++)
			v[i] = tab[i][kolumny-1];

}
    void dnf::przykladyNegatywne(int *v) {
    	for(int i=0;i<wiersze;i++)
    		if(tab[i][kolumny-1] == 0)
				v[i] = 1;
			else
				v[i] = 0;
}
    void dnf::zeruj(int *v, int n) {
    	for(int i=0;i<n;i++)
			v[i] = 0;
}
    void dnf::zeruj(double *v, int n) {
    	for(int i=0;i<n;i++)
			v[i] =  0;
}

    int dnf::wybierzCeche(int *P, int *N , int *r) {
    	
    	double p,n;
    	double *f = new double [kolumny-1];
    	zeruj(f,kolumny-1);
    	
         for (int i=0; i<kolumny-1; i++) {
         	p = n = 0; 
             for (int j=0; j<wiersze; j++){
				
					if(P[j] && tab[j][i]==1) p++; 
					if(N[j] && tab[j][i]==1) n++;
					
					
				}

            
              
              if(r[i] == 0)
	              f[i] = p / max(n, 0.001);
              else 
					f[i] = -1;
             
         }
         
         double max = f[0];
         int index = 0;
         
         for(int i=1;i<kolumny-1;i++)
         	if(f[i] > max)
         		max = f[i], index = i;
         
         delete f;
         return index;
   	
	
}


    void dnf::ustawCeche(int *r, int f) {
    	
    	r[f] = 1;
	
}

    void dnf::usunNegatywne(int *N, int f) {
    	for (int i=0; i<wiersze; i++)
    		if(tab[i][f] == 0)
    			N[i] = 0;
    	
	
}
    void dnf::generujHipoteze(string &h,int *r) {
    char buffer [10];
	if(h.length() !=0)
		h += " v ";
	
	int k=0;
	for(int i=0;i < kolumny -1;i++)
		if(r[i] == 1){
			itoa(i+1,buffer,10);
			if(k != 0 )
				 h += "^";
			h += "f" + string(buffer);
			k++;
		}
	
	
}
    int dnf::usunPozytywne(int *P,int *r) {
    	
    	bool test;
    	int ilePokrytych=0;
    	
    	for (int i=0; i<wiersze; i++) {
			test = true;
             for (int j=0; j<kolumny -1; j++){
					if(r[j] == 1)
						test = test && tab[i][j];
				}
			if(test){
				P[i] = 0;
				ilePokrytych++;
			}
				
             
         }
 	return ilePokrytych;
	
}
int dnf::czyWszystkieCechy(int *r){
	
		for(int i=0;i < kolumny-1;i++){

			if(r[i] == 0)
				return 0;
		}
		return 1;
	
	
	
}



/*
algorytm (DNF):
D = zbiór danych
P = przyk³ady pozytywne w D
h = false
pêtla a¿ P bêdzie puste
r= true
N = przyk³ady negatywne w D
pêtla a¿ N bêdzie puste
jeœli wszystkie cechy s¹ w r to pora¿ka
w przeciwnym przypadku wybierz cechê fj i dodaj do r
r = r & fj
N = N – (przypadki w N, dla których fj==0)
h = h || r
pokrycie = przyk³ady w P pokryte przez r
jeœli pokrycie jest puste to pora¿ka
w innym przypadku P = P – pokrycie
end
*/
