#include<bits/stdc++.h>
#include "Node.class.h"
using namespace std;

struct EmptyQueue : public exception {
   const char* what () const throw () {
      return "The queue is empty!";
   }
};
template<class N>
class Fifo
{
    private:
        bool created; //flaga okreslająca, czy w kolejce cos już się pojawiło
        int begin, end; //początek i koniec kolejki (indexy)
        node<N> *first_node, *actual_node, *last_node; //pierwszy node, aktualny node, ostatni node

    public:
        Fifo()
        {
            begin = 0;
            end = 0;
            created = 0;
        }
        ~Fifo() //zwolnienie pamięci dla elementów kolejki
        {
            while(end != begin)
            {
                actual_node = first_node; //ustawienie aktualnego noda na pierwszego
                first_node = first_node -> next; //ustawienie pierwszego na kolejnego
                delete actual_node; //usunięcie aktualnego noda
                begin++;	
            }
            if(created)
                delete first_node; //usuniecie wskaznika pierwszego noda
        }
        int size()
        {
            return end - begin; //liczba elementów w kolejce
        }
        void push_back(N set_value)   //dodanie elementu na koniec kolejki
        {
            if(!created)    //pierwszy element trafiający do kolejki
            {
                last_node = new node<N>;    //utworzenie elementu ostatniego
                last_node -> value = set_value; //przypisanie do niego wartosci
                first_node = new node<N>; 		//utworzenie elemntu pierwszego
                first_node -> next = last_node;  //element pierwszy wskazuje na ostatni
                created = 1;
            }
            else
            {
                actual_node = new node<N>; //utworzenie nowego elementu kolejki
                actual_node -> value = set_value;   //przypisanie do niego wartosci
                last_node -> next = actual_node;    //ostatni dotychczasowy element wskazuje na utworzony
                last_node = actual_node;    //utworzony elementstaje się ostatnim
            }
            end++;
        }
        void pop()  //usunięcie pierwszego elementu z kolejki
        {
            if(end == begin)    //gdy nie ma nic w kolejce zwracamy blad
            {
                throw EmptyQueue();
            }
            actual_node = first_node; //ustawienie aktualnego noda na pierwszego
            first_node = first_node -> next; //przejscie na następny element kolejki
            delete actual_node;	//usunięcie pierwszego elementu w kolejce
            begin++;
        }
        int get_first() //zwrócenie pierwszego elementu w kolejce
        {
            if(!is_empty())
            {
                int msg = first_node -> next -> value;
                pop();
                return msg;
            }
            throw EmptyQueue();
        }
        int get_last() //wyznaczenie ostatniego elementu w kolejce
        {
            if(!is_empty())
                return last_node -> value;
            throw EmptyQueue();
        }
        bool is_empty()
        {
            return end == begin; //zwrócenie informacji o stanie kolejki
        }
        friend ostream& operator<<(ostream& os, Fifo& obj)
        {
            int i = obj.begin;
            obj.actual_node = obj.first_node -> next;   //ustawiamy wskaznik na 1 element kolejki
            while(i != obj.end)
            {
                os << obj.actual_node -> value << " ";  //wypisujemy
                obj.actual_node = obj.actual_node -> next;  //skaczemy do nastepnego elementu
                i++;    //az dojdziemy do konca
            }
            return os;
        }
        friend bool operator==(Fifo& obj1, Fifo& obj2)
        {
            int i = obj1.begin;
            if(obj2.size() != obj1.size())  //sprawdzamy dlugosci kolejek
                return 0;
            obj1.actual_node = obj1.first_node -> next; //ustawiamy wskaznik na 1 element 1. kolejki
            obj2.actual_node = obj2.first_node -> next; //ustawiamy wskaznik na 1 element 2. kolejki
            while(i != obj1.end)
            {
                if(obj1.actual_node -> value != obj2.actual_node -> value)  //porownujemy wartosci poszczegolnych nodów kolejek
                    return 0;
                obj1.actual_node = obj1.actual_node -> next;    //skaczemy do nastepnego elementu kol 1.
                obj2.actual_node = obj2.actual_node -> next;    //skaczemy do nastepnego elementu kol 2.
                i++;    //az dojdziemy do konca
            }
            return 1;
        }
};