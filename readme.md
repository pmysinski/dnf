# DNF

Implementacja algorytmu przekszta³cajacego wyrazenia do postaci DNF.

## Pseudo kod

```
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
```


## License
[MIT](https://choosealicense.com/licenses/mit/)