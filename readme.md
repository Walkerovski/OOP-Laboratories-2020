# Programowanie obiektowe (PROI 2020)

Repozytorium zawiera moje rozwiązania 4. zadań otrzymanych przeze mnie w ramach przedmiotu programowanie obiektowe oraz 2. sprawdzianów pisanych w ograniczonym czasie.

# PD1
Proszę napisać w C++ program wyznaczający średnią, minimum i maksimum ciągu liczb rzeczywistych o nieznanej z góry długości. Program powinien umożliwiać:  
wczytanie kolejnych elementów ciągu od użytkownika  
stwierdzenie, że zakończono podawanie elementów ciągu (zakończenie wczytywania po wpisaniu określonej wartości liczbowej, np. 0, nie jest dobrym pomysłem - 0 może być pełnoprawnym elementem takiego ciągu!)  
wyliczenie średniej, minimum i maksimum tego ciągu  
wyświetlenie wyników w sposób czytelny dla użytkownika  
w razie podania niepoprawnych danych wejściowych program powinien poinformować o niemożności wykonania operacji  

Uwaga: celem jest wyliczenie określonych wartości, a nie przechowanie całego wczytanego ciągu. Proszę przygotować takie rozwiązanie, które nie wymaga zapamiętywania wszystkich elementów ciągu.
# PD2
Proszę stworzyć narzędzie, które pomoże średniowiecznym kupcom w przeliczeniu jednostek miar długości (przy założeniu, że będą chcieli poznać również jednostki metryczne z przyszłości). Przelicznik powinien uwzględniać staropolskie handlowe jednostki miar długości (sztych, ćwierć, dłoń, palec, ziarno) oraz jednostki metryczne (milimetry, centymetry, decymetry, metry).  
  
Podpowiedź:  
1 sztych = 198, 51 m = 1,33 ćwierci = 2,66 dłoni = 8 palców = 63 ziarna
# PD3
Proszę zaimplementować klasę reprezentującą dział tematyczny w sklepie z płytami winylowymi. Dział składa się ze zbioru należących do niego płyt winylowych, cechuje się też m.in. nazwą, opisem, położeniem, liczbą regałów oraz opiekującym się pracownikiem itp. Możliwa jest m.in. modyfikacja parametrów działu oraz należących do niego płyt.
# PD4
Proszę przygotować szablon klasy reprezentującej kolejkę FIFO. Rozmiar kolejki nie jest z góry określony. Należy zaimplementować operacje:  
Wstawianie elementu na koniec kolejki  
Pobranie pierwszego elementu z kolejki (z usunięciem)  
Sprawdzanie, czy kolejka jest pusta  
Podanie rozmiaru kolejki  
Porównywanie dwóch kolejek  
Drukowanie kolejki  
# Spr1
Czas na rozwiązanie zadania: 30min  
Napisz funkcję wyznaczającą wartość pracy prądu elektrycznego o zadanych przez użytkownika parametrach. Napisz program wykorzystujący stworzoną funkcję. Wynik programu powinien wyświetlać równanie wraz z jednostkami.  
  
Wskazówka:  
W = U*I*t  
(U – napięcie, I – natężenie, t - czas)  
[1J] = [1V*1A*1s]

# Spr2
Czas na rozwiązanie zadania: 60min  
Proszę stworzyć klasę „Segregacja”. Klasa powinna posiadać:  
  
atrybuty: pojemnik na tworzywa sztuczne, pojemnik na śmieci zmieszane  
metody: opróżnij pojemnik na tworzywa sztuczne, wrzuć tworzywa sztuczne do pojemnika, opróżnij pojemnik na śmieci zmieszane, wrzuć śmieci zmieszane do pojemnika, stan pojemników.  
  
Proszę zaprojektować działanie obiektu stworzonego na bazie klasy "Segregacja". Konstruktor powinien pobierać dane o pojemności poszczególnych pojemników. Program powinien być odporny na przepełnienie pojemników.