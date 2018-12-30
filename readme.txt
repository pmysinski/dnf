# DNF

Implementacja algorytmu przekszta�cajacego wyrazenia do postaci DNF.

## Pseudo kod

```
algorytm (DNF):
D = zbi�r danych
P = przyk�ady pozytywne w D
h = false
p�tla a� P b�dzie puste
r= true
N = przyk�ady negatywne w D
p�tla a� N b�dzie puste
je�li wszystkie cechy s� w r to pora�ka
w przeciwnym przypadku wybierz cech� fj i dodaj do r
r = r & fj
N = N � (przypadki w N, dla kt�rych fj==0)
h = h || r
pokrycie = przyk�ady w P pokryte przez r
je�li pokrycie jest puste to pora�ka
w innym przypadku P = P � pokrycie
end
```


## License
[MIT](https://choosealicense.com/licenses/mit/)