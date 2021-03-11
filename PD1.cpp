#include<bits/stdc++.h>
using namespace std;
bool sprawdz(string wyraz)
{
    bool kropki = 0, minusy = 0;
    for(int i = 0; i < wyraz.size(); i++){
        if(wyraz[i] < '0' || (char)wyraz[i] > '9')
            if(wyraz[i] != '.' && (wyraz[i] != '-' && i == 0)){
                cout << "Podano bledny wyraz" << "\n";
                return 0;
            }
        if((wyraz[i] == '.' && kropki) || (wyraz[i] == '-' && minusy)){
            cout << "Podano bledny wyraz" << "\n";
            return 0;
        }
        if(wyraz[i] == '.')kropki = 1;
        if(wyraz[i] == '-')minusy = 1;
    }
    if(wyraz.size() == kropki + minusy){
        cout << "Podano bledny wyrazsss" << "\n";
        return 0;
    }
    return 1;
}
int main()
{
    cout << "Wpisz kolejne wyrazy ciagu, po ostatnim wyrazie wpisz 'koniec'" << "\n";
    string wyraz;
    cin >> wyraz;
    double liczba;
    double srednia = 0, mini = 1e9, maxi = -1e9;
    int ilosc = 0;
    while(wyraz != "koniec"){
        if(sprawdz(wyraz)){
        liczba = stod(wyraz);
        srednia += liczba;
        ilosc ++;
        mini = min(mini, liczba);
        maxi = max(maxi, liczba);
        }
        cin >> wyraz;
    }
    if(ilosc == 0){
        cout << "Brak dzialan do wykonania" << "\n";
        return 0;
    }
    cout << "Srednia ciagu: " << srednia / ilosc << "\n";
    cout << "Minimum ciagu: " << mini << "\n";
    cout << "Maximum ciagu: " << maxi << "\n";
}
