#include<bits/stdc++.h>
using namespace std;
template<class N>
class node
{
    public:
    N value;
    node<N> *next;
};

class Testingclass
{
    public:
    int Value;
    string Name;
    Testingclass(int value_Input, string name_Input)
    {
        Value = value_Input;
        Name = name_Input;
    }
    friend bool operator==(Testingclass& obj1, Testingclass& obj2)
    {
        if(obj1.Value != obj2.Value)
            return 0;
        if(obj1.Name != obj2.Name)
            return 0;
        return 1;
    }
};