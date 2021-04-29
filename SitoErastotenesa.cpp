// Sito Erastotenesa
// Stoper - mierzenie czasu wykonania funkcji
/*
funkcja clock() zwraca liczbę tyknięc zegara od  momentu, w którym program zaczął 
się uruchamiać.
Aby zobaczyć wynik w sekundach trzeba podzielić to przez stałą CLOCKS_PER_SEC -
zobaczymy wtedy ile czasu program już działa
typ clock_t to również long int
*/


#include <iostream>
#include <time.h>
using namespace std;

int sito(bool tabPrimeNumber[], int size) {
    for (int i = 0; i < size; i++) {
            tabPrimeNumber[i] = 1;
        }
    tabPrimeNumber[0] = 0;
    tabPrimeNumber[1] = 0;
    for (int i = 2; i*i < size; i++) {
       if (tabPrimeNumber[i])
           for (int j = 2; i * j < size; j++) {
               tabPrimeNumber[i * j] = 0;
           }
    }
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (tabPrimeNumber[i]) count++;
    }
    return count;
}

int main()
{
    const unsigned int rozmiar = 1000001;
    //wypełniamy tablicę 1 -> zakładamy, że wszysteki liczby w tablicy są pierwsze.
    bool tabPrimeNumber[rozmiar];
    //indeks w tej tablicy to liczba, która może być pierwsza, albo złożona
    //jeżeli tabPrimeNumber[i] == 1 dla 0<=i<1000 to i jest liczbą pierwszą
    //for (int i = 0; i < 1000; i++) {
    //    tabPrimeNumber[i] = 1;
    //}
    //tabPrimeNumber[0] = 0;
    //tabPrimeNumber[1] = 0;
    //for (int i = 2; i*i < 1000; i++) {
    //    if (tabPrimeNumber[i])
    //        for (int j = 2; i * j < 1000; j++) 
    //            tabPrimeNumber[i * j] = 0;//wykreślamy krotności liczb pierwszych
    //}
    clock_t start = clock();
    cout << "znaleziono: " << sito(tabPrimeNumber, rozmiar) << " liczb pierwszych" << endl;
   
    for (int i = 2; i < rozmiar; i++) {
        if (tabPrimeNumber[i])
            cout << i << ",";
    }
    cout << endl;
    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;
    cout << elapsed << end;


}
//zad Napisz funkcje wyznaczającą sito i zwracająca liczbę liczb pierwszych z podanego przedziału.
