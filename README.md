325 CD, Corcodel Denisa

# Task 1 
-	Input-ul acestui task este N si sirul de numere. Rezolvarea acestui task presupune sortarea elementelor si realizarea unei sume in care calculez diferenta maxima a celor doi. La final returnez suma. Se aplica metoda Greedy, iar complexitatea este
```
O (n * log n)
```

:heavy_check_mark: 
# Task 2 
-
	Input-ul acestui task este N ( = numarul de numere ), ( K = numarul numerelor pe care le elimiana pentru a maximiza scorul) si sirul de numere. 
Am considerat diferenta maxima obtinuta din primele i numere sortate descrescator selectam exact j din ele ca fiind dp[i][j],matrice dp de dimensiune n + 1 x n - k + 1

In functie de paritatea lui j va alege advesarul, iar costul va scadea. Daca pot selecta j elemente din primele i - 1, voi considera ca fiind o solutie buna. 
La fiecare pas aleg intre solutia care il include pe elementul anterior din vector, sau cea fara elementul anterior dar cu elementul curent, 
```
dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] +/- v[i - 1]) 
```
returneaza dp[n][n-k], adica diferenta maxima din intreaga multime selectand n - k numere 

```O ( n^2 *log n )```

:heavy_check_mark:
# Task 3
-
	Input-ul acestui task este acelasi cu cel de la primul task, insa strategia se schimba deoarece el trebuie sa elimine ori cel mai din dreapta ori cel mai
din stanga element. 
	Cazul de baza este reprezentat de un sir ce contine un singur element.
	Calculez maximul elementului cel mai din stanga, deoarece vreau scorul cat mai mare si minimul restului de vector pentru ca din doua elemente ramase oponentul
il va lua pe cel mai mare. Folosesc o matrice de dimensiune n * n, in care diagonala principala contine elementele din vector. Pentru a extinde se foloseste formula
dp[i][j] = max ( min (dp[i+1][j-1], dp[i+2][j])  + a[i] , min(dp[i+1][j-1],dp[i][j-2]) + a[j]) )
	Daca voi considera ca a[i] este elementul cel mai din stanga, iar a[j] elementul cel mai din dreapta,  se va considera cazul de baza. Tzugu a obtinut scorul  maxim dp[0][n-1],iar oponentului i-a ramas suma vectorului. 

```
O (n^2)
```
:heavy_check_mark: 


# Rulare:
	
- local:
		./check.sh
		
	* sursele + Makefile trebuie sa se afle in directorul curent

Run time error = eroare aparuta in timpul rularii unui test
TLE = time limit exceeded (s-a depasit limita de timp a testului curent)
WA = wrong answer (valoarea din fisierul .out difera de cea din .ref)

Timpi de executie problema $id:
	
- C/C++:
	
		- _utils/timeout/c.timeout$id

-  Java:
 		
		- _utils/timeout/java.timeout$id

Checker coding style:
	
- C/C++: 
		- utils/coding_style/check_cpp.py
		- sursa: https://google.github.io/styleguide/cppguide.html

-  Java: 
		- utils/coding_style/check_java.jar
		- sursa: http://checkstyle.sourceforge.net/google_style.html

Exemplu debug
	Rulez `./check.sh` si obtin WA la problema gigel, pe testul 4.
		Decomentez urmatoarea linie din checker.sh
			# DEBUG=on
			(activez DEBUG - by default fisierele de out sunt sterse)

Ma uit in fisierele:
	```	- public_test/gigel/input/4-gigel.in   // ce input am
		- public_test/gigel/out/4-gigel.out    // ce raspuns gaseste algoritmul meu
		- public_test/gigel/ref/4-gigel.ref    // care este raspunsul corect (asteptat) ```
