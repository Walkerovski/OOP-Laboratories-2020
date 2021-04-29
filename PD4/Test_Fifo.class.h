#include<bits/stdc++.h>
#include "Fifo.class.h"
using namespace std;

class Test_Fifo
{
    public:
    bool test_size()
    {
        Fifo<string> Queue;
        Queue.push_back("5e");
        Queue.push_back("6s");
        Queue.push_back("a7");
        assert(Queue.size() == 3);
        return 1;
    }
    bool test_size_2()
    {
        Fifo<string> Queue;
        for(int i = 1; i <= 10000; i++)
        {
            Queue.push_back("i");
            assert(Queue.size() == i);
        }
        return 1;
    }
    bool test_push_back()
    {
        Fifo<string> Queue;
        Queue.push_back("5e");
        assert(Queue.get_first() == "5e");
        Queue.push_back("6s");
        assert(Queue.get_first() == "6s");
        Queue.push_back("a7");
        assert(Queue.get_first() == "a7");
        assert(Queue.size() == 0);
        return 1;
    }
    bool test_push_back_2()
    {
        Fifo<string> Queue;
        for(int i = 1; i <= 10000; i++)
        {
            Queue.push_back("i");
        }
        assert(Queue.size() == 10000);
        return 1;
    }
    bool test_pop()
    {
        Fifo<string> Queue;
        Queue.push_back("5e");
        Queue.pop();
        assert(Queue.size() == 0);
        Queue.push_back("5e");
        assert(Queue.size() == 1);
        Queue.pop();
        assert(Queue.size() == 0);
        return 1;
    } 
    bool test_pop_2()
    {
        Fifo<string> Queue;
        for(int i = 1; i <= 10000; i++)
        {
            Queue.push_back("5e");
        }
        assert(Queue.size() == 10000);
        for(int i = 1; i <= 10000; i++)
        {
            Queue.pop();
            assert(Queue.size() == 10000 - i);
        }
        return 1;
    }
    bool test_get_first()
    {
        Fifo<string> Queue;
        Queue.push_back("5e");
        assert(Queue.get_first() == "5e");
        Queue.push_back("3e");
        assert(Queue.get_first() == "3e");
        assert(Queue.size() == 0);
        return 1;
    }
    bool test_get_first_2()
    {
        Fifo<string> Queue;
        for(int i = 1; i <= 10000; i++)
        {
            Queue.push_back(to_string(i));
        }
        assert(Queue.size() == 10000);
        for(int i = 1; i <= 10000; i++)
        {
            assert(Queue.get_first() == to_string(i));
        }
        return 1;
    }
    bool test_is_empty()
    {
        Fifo<string> Queue;
        assert(Queue.is_empty() == 1);
        Queue.push_back("5e");
        assert(Queue.is_empty() == 0);
        Queue.pop();
        assert(Queue.is_empty() == 1);
        return 1;
    }
    bool test_is_empty_2()
    {
        Fifo<string> Queue;
        for(int i = 1; i <= 10000; i++)
        {
            Queue.push_back(to_string(i));
            if(i % 2 == 0)
            {
                assert(Queue.is_empty() == 0);
                Queue.pop();
                assert(Queue.is_empty() == 0);
                Queue.pop();
                assert(Queue.is_empty() == 1);
            }
        }
        return 1;
    }
};

class Test_Fifo_Testing
{
    public:
    bool test_size()
    {
        Fifo<Testingclass> Queue;
        Testingclass obj(5, "5e");
        Queue.push_back(obj);
        Queue.push_back(obj);
        Queue.push_back(obj);
        assert(Queue.size() == 3);
        return 1;
    }
    bool test_size_2()
    {
        Fifo<Testingclass> Queue;
        Testingclass obj(1, "1");
        for(int i = 1; i <= 10000; i++)
        {
            obj.Value = i;
            obj.Name = to_string(i);
            Queue.push_back(obj);
            assert(Queue.size() == i);
        }
        return 1;
    }
    bool test_push_back()
    {
        Fifo<Testingclass> Queue;
        Testingclass obj(5, "5e");
        Queue.push_back(obj);
        assert(Queue.size() == 1);
        Queue.push_back(obj);
        assert(Queue.size() == 2);
        Queue.pop();
        assert(Queue.size() == 1);
        Queue.pop();
        assert(Queue.size() == 0);
        return 1;
    }
    bool test_push_back_2()
    {
        Fifo<Testingclass> Queue;
        Testingclass obj(1, "1");
        for(int i = 1; i <= 10000; i++)
        {
            obj.Value = i;
            obj.Name = to_string(i);
            Queue.push_back(obj);
        }
        assert(Queue.size() == 10000);
        return 1;
    }
    bool test_pop()
    {
        Fifo<Testingclass> Queue;
        Testingclass obj(5, "5e");
        Queue.push_back(obj);
        Queue.pop();
        assert(Queue.size() == 0);
        Queue.push_back(obj);
        assert(Queue.size() == 1);
        Queue.pop();
        assert(Queue.size() == 0);
        return 1;
    } 
    bool test_pop_2()
    {
        Fifo<Testingclass> Queue;
        Testingclass obj(1, "1");
        for(int i = 1; i <= 10000; i++)
        {
            obj.Value = i;
            obj.Name = to_string(i);
            Queue.push_back(obj);
        }
        assert(Queue.size() == 10000);
        for(int i = 1; i <= 10000; i++)
        {
            Queue.pop();
            assert(Queue.size() == 10000 - i);
        }
        return 1;
    }
    bool test_get_first()
    {
        Fifo<Testingclass> Queue;
        Testingclass obj1(5, "5e");
        Queue.push_back(obj1);
        Testingclass obj2 = Queue.get_first();
        assert(obj2 == obj1);
        Testingclass obj3(5, "3e");
        Queue.push_back(obj3);
        Testingclass obj4 = Queue.get_first();
        assert(obj4 == obj3);
        assert(Queue.size() == 0);
        return 1;
    }
    bool test_get_first_2()
    {
        Fifo<Testingclass> Queue;
        Testingclass obj(1, "1");
        for(int i = 1; i <= 10000; i++)
        {
            obj.Value = i;
            obj.Name = to_string(i);
            Queue.push_back(obj);
        }
        assert(Queue.size() == 10000);
        Testingclass obj2(1, "1");
        for(int i = 1; i <= 10000; i++)
        {
            obj.Value = i;
            obj.Name = to_string(i);
            obj2 = Queue.get_first();
            assert(obj == obj2);
        }
        return 1;
    }
    bool test_is_empty()
    {
        Fifo<Testingclass> Queue;
        Testingclass obj1(5, "5e");
        assert(Queue.is_empty() == 1);
        Queue.push_back(obj1);
        assert(Queue.is_empty() == 0);
        Queue.pop();
        assert(Queue.is_empty() == 1);
        return 1;
    }
    bool test_is_empty_2()
    {
        Fifo<Testingclass> Queue;
        Testingclass obj(1, "1");
        for(int i = 1; i <= 10000; i++)
        {
            obj.Value = i;
            obj.Name = to_string(i);
            Queue.push_back(obj);
            if(i % 2 == 0)
            {
                assert(Queue.is_empty() == 0);
                Queue.pop();
                assert(Queue.is_empty() == 0);
                Queue.pop();
                assert(Queue.is_empty() == 1);
            }
        }
        return 1;
    }
};