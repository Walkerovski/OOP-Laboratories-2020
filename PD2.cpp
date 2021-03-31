#include<bits/stdc++.h>
using namespace std;
//nasz slowniczek z wywolaniem log(n)
map<string, double> dictionary = {
    {"m", 1},
    {"dm", 10},
    {"cm", 100},
    {"mm", 1000},
    {"sztych", 198.51},
    {"ćwierć", 198.51/1.33},
    {"dłoń", 198.51/2.66},
    {"palec", 198.51/8},
    {"ziarno", 198.51/63}
};

//funkcja sprawdzajaca mozliwosc konwersji z str na double
bool check(string wyraz)
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
                cout << "Podano bledną liczbę \n";
                return 0;
                // wypisujemy blad i zwracamy falsz
            }
        }
        if((wyraz[i] == '.' && kropki) || (wyraz[i] == '-' && minusy)){
            // jezeli char jest kropka lub minusem na pierwszym miejscu
            // sprawdzamy czy flaga nie jest juz przypadkiem odpalona
            cout << "Podano bledną liczbę \n";
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
        cout << "Podano bledną liczbę \n";
        return 0;
        // wypisujemy blad i zwracamy flasz
    }
    return 1;
    // jesli dotarlismy az tutaj oznacza to ze po drodze nie znalezlismy bledu
    // oznacza to ze wszystkie chary z tablicy stringa sa poprawna interpretacja doubla
    // zwracamy prawde
}

//funkcja konwertujaca jednostki
void conversion(double value, string type){
    //sprowadzamy do bazowej
    value /= dictionary[type];
    //zamieniamy on-line i wypluwamy wyniki do 15 cyfr
    for(auto it = dictionary.begin(); it != dictionary.end(); it ++)
    {
        cout << setprecision(15) << it -> first << " " << it -> second * value << "\n";
    }
}
int main()
{
    string in1, in2;
    while(1)
    {
        cout << "Proszę podać wartość, aby przerwać wprowadź 'end' \n";
        cin >> in1;
        //zakonczenie pracy programu
        if(in1 == "end")
        {
            cout << "ciao!";
            return 0;
        }
        cout << "Proszę wpisać jednostkę: ";
        cin >> in2;
        //sprawdzenie poprawnosci danych, wywolanie funkcji 
        if(check(in1) and dictionary[in2])conversion(stod(in1), in2);
        //jesli nie znamy jednostki informujemy o tym
        if(!dictionary[in2]) cout << "brak jednostki\n";
    }
}