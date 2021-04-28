#include<bits/stdc++.h>
using namespace std;

class Segregation
{
    int plastics;
    int rubbish;
    int plastics_capacity;
    int rubbish_capacity;
    
    public:
    Segregation(int plastics_capacity_IN, int rubbish_capacity_IN)
    {
       plastics_capacity = plastics_capacity_IN;
       rubbish_capacity = rubbish_capacity_IN;
       plastics = 0;
       rubbish = 0;
    }

    int get_plastics()
    {
        return plastics;
    }
    
    int get_rubbish()
    {
        return rubbish;
    }

    void add_plastics(int amount)
    {
        if(check_plastics_capacity(amount))
            plastics += amount;
    }

    bool check_plastics_capacity(int amount)
    {
        if(plastics + amount > plastics_capacity)
        {
            cout << "Tworzywa sztuczne nie mieszczą się w pojemniku\n";
            return 0;
        }
        return 1;
    }
    
    void add_rubbish(int amount)
    {
        if(check_rubbish_capacity(amount))
            rubbish += amount;
    }

    bool check_rubbish_capacity(int amount)
    {
        if(rubbish + amount > rubbish_capacity)
        {
            cout << "Śmieci zmieszane nie mieszczą się w pojemniku\n";
            return 0;
        }
        return 1;
    }

    void clean_plastics()
    {
        plastics = 0;
    }
    
    void clean_rubbish()
    {
        rubbish = 0;
    }
};

bool check(string wyraz)
// funkcja sprawdzajaca poprawnosc wpisanych danych
{
    bool kropki = 0, minusy = 0;
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

int main()
{
    cout << "Aby utworzyć pojemnik wpisz jego pojemnosc: [tworzywa sztuczne] [zmieszane]\n";
    string plastics_IN, rubbish_IN;
    cin >> plastics_IN >> rubbish_IN;
    int plastics, rubbish;
    if(check(plastics_IN) && check(rubbish_IN))
    {
        plastics = stod(plastics_IN);
        rubbish = stod(rubbish_IN);
    }
    else return 0;
    if(plastics < 0 || rubbish < 0)
    {
        cout << "Pojemnosc nie moze byc < 0\n";
        return 0;
    }
    // Tworzymy kontener o pojemnosciach zarowno dla plastiku jak i smieci
    // Jesli ma byc dla smieci jednego rodzaju wystarczy dac 0 przy drugim
    Segregation Bin(plastics, rubbish);
    Bin.get_plastics();
    Bin.get_rubbish();
    cout << "Aby dodać śmieci do pojemnika podaj ich ilość: [tworzywa sztuczne] [zmieszane]\n";
    cin >> plastics_IN >> rubbish_IN;
    if(check(plastics_IN) && check(rubbish_IN))
    {
        plastics = stod(plastics_IN);
        rubbish = stod(rubbish_IN);
    }
    else return 0;
    if(plastics < 0 || rubbish < 0)
    {
        cout << "Ilość śmieci nie moze byc < 0\n";
        return 0;
    }
    Bin.add_plastics(plastics);
    Bin.add_rubbish(rubbish);
    cout << "Aktualny stan pojemników:\n";
    cout << "Tworzywa: " << Bin.get_plastics() << " Zmieszane: " << Bin.get_rubbish() <<"\n";
}