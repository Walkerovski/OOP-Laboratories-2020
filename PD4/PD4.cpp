#include<bits/stdc++.h>
#include "Fifo.class.h"
using namespace std;
int main()
{
    Fifo<string> Queue;
    Queue.push_back("5e");
    Queue.push_back("6s");
    Queue.push_back("a7");
    Fifo<string> Queue2;
    Queue2.push_back("5e");
    Queue2.push_back("6s");
    Queue2.push_back("a7");
    cout << Queue << " " << Queue2 << " ";
    cout << (Queue == Queue2) << "\n";
}