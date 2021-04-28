#include<bits/stdc++.h>
using namespace std;
bool sprawdz(string wyraz)
// funkcja sprawdzajaca poprawnosc wpisanych danych
{
    bool kropki = 0, minusy = 0;
    // nasze flagi sprawdzajace wystapienie minusa i kropki
    for(int i = 0; i < wyraz.size(); i++){
        // iterujemy sie po kazdym charze ze stringa
        if(wyraz[i] < '0' || wyraz[i] > '9'){
            // jezeli char nie jest z przedzialu [0, 9]
            if(wyraz[i] != '.' && (wyraz[i] != '-' || i != 0)){
                // ani nie jest kropka lub minusem na pierwszym miejscu
                cout << "Podano bledny wyraz" << "\n";
                return 0;
                // wypisujemy blad i zwracamy falsz
            }
        }
        if((wyraz[i] == '.' && kropki) || (wyraz[i] == '-' && minusy)){
            // jezeli char jest kropka lub minusem na pierwszym miejscu
            // sprawdzamy czy flaga nie jest juz przypadkiem odpalona
            cout << "Podano bledny wyraz" << "\n";
            return 0;
            // jesli jest zwracamy blad i falsz
            // liczba nie moze posiadac dwoch . ani -
        }
        if(wyraz[i] == '.')kropki = 1;
        if(wyraz[i] == '-')minusy = 1;
        //odpalamy flagi przy wystapieniu odpowiednich znakow
    }
    if(wyraz.size() == kropki + minusy){
        // jezeli nasz wyraz to sama . lub - lub ich dowolne polaczenie
        // nie mamy zadnej liczby, musimy zdecydowac jak ja interpretowac
        // mozna jako 0, ja uznaje za blad
        cout << "Podano bledny wyraz" << "\n";
        return 0;
        // wypisujemy blad i zwracamy flasz
    }
    return 1;
    // jesli dotarlismy az tutaj oznacza to ze po drodze nie znalezlismy bledu
    // oznacza to ze wszystkie chary z tablicy stringa sa poprawna interpretacja doubla
    // zwracamy prawde
}
int main()
{
    cout << "Wpisz kolejne wyrazy ciagu, po ostatnim wyrazie wpisz 'koniec'" << "\n";
    string wyraz;
    cin >> wyraz;
    double liczba;
    double srednia = 0, mini = 1e9, maxi = -1e9;
    // minimum jest nieskonczonoscia by kazda liczba byla mniejsza
    // maxi analogiczne
    int ilosc = 0;
    // ustawiamy licznik wyrazow (do sredniej)
    while(wyraz != "koniec"){
        // petla aktualizuje zmienne i pobiera dane az do wczytania "koniec"
        if(sprawdz(wyraz)){
            // tutaj wywolujemy sprawdzenie i jesli dostaniemy prawde zajmujemy sie wyrazem
            liczba = stod(wyraz);
            // korzystajac z gotowej funkcji konwertujemy poprawnego juz stringa na doubla
            // w przypadku nie sprawdzenia stringa i przejscia do konwersji
            // program wyrzucilby wyjatek i przerwal sie
            // ponowne wpisywanie ciagu przez przypadkowa pomylke jest nie zbyt fajne
            srednia += liczba;
            ilosc ++;
            mini = min(mini, liczba);
            maxi = max(maxi, liczba);
            // aktualizujemy nasze zmienne z przekonwertowanym wyrazem i zwiekszamy licznik
        }
        cin >> wyraz;
    }
    if(ilosc == 0){
        // jesli nie mamy zadnej liczby informujemy uzytkownika
        // dodatkowo uciekamy od dzielenia przez zero ;)
        cout << "Brak dzialan do wykonania" << "\n";
        return 0;
        // koniec pracy programu
    }
    cout << "Srednia ciagu: " << srednia / ilosc << "\n";
    cout << "Minimum ciagu: " << mini << "\n";
    cout << "Maximum ciagu: " << maxi << "\n";
    // wypisujemy dane dla uzytkownika
}