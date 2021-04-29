#include<bits/stdc++.h>
#include "Test_Fifo.class.h"
using namespace std;
int main()
{
    Test_Fifo Test;
    if(!Test.test_get_first())
        cout << "test_get_first";
    if(!Test.test_get_first_2())
        cout << "test_get_first_2";
    if(!Test.test_is_empty())
        cout << "test_is_empty";
    if(!Test.test_is_empty_2())
        cout << "test_is_empty_2";
    if(!Test.test_pop())
        cout << "test_pop";
    if(!Test.test_pop_2())
        cout << "test_pop_2";
    if(!Test.test_push_back())
        cout << "test_push_back";
    if(!Test.test_push_back_2())
        cout << "test_push_back_2";
    if(!Test.test_size())
        cout << "test_size";
    if(!Test.test_size_2())
        cout << "test_size_2";
    Test_Fifo_Testing Test2;
    if(!Test2.test_get_first())
        cout << "test_get_first";
    if(!Test2.test_get_first_2())
        cout << "test_get_first_2";
    if(!Test2.test_is_empty())
        cout << "test_is_empty";
    if(!Test2.test_is_empty_2())
        cout << "test_is_empty_2";
    if(!Test2.test_pop())
        cout << "test_pop";
    if(!Test2.test_pop_2())
        cout << "test_pop_2";
    if(!Test2.test_push_back())
        cout << "test_push_back";
    if(!Test2.test_push_back_2())
        cout << "test_push_back_2";
    if(!Test2.test_size())
        cout << "test_size";
    if(!Test2.test_size_2())
        cout << "test_size_2";
    
    Fifo<int> Out;
    Out.push_back(1);
    Out.push_back(2);
    Out.push_back(3);
    Out.push_back(4);
    cout << "Out: " << Out << "\n";
    cout << "Out.first: " << Out.get_first() << "\n";
    Out.push_back(5);
    cout <<"Out: " <<  Out << "\n";    
    
    Fifo<int> Out2;
    Out2.push_back(1);
    Out2.push_back(2);
    Out2.push_back(3);
    Out2.push_back(4);
    cout << "Out2: " << Out2 << "\n";
    cout << "Out2.first: " << Out2.get_first() << "\n";
    Out2.push_back(5);
    cout << Out2 << "\n";

    cout << "Out == Out2: " << (Out == Out2) << "\n";

    Out2.push_back(6);
    Out2.pop();
    cout << "Out == Out2: " << (Out == Out2) << "\n";
}