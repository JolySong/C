//
//  main.cpp
//  加号运算符重载
//
//  Created by song on 2020/12/16.
//

#include <iostream>
using namespace std;

class Person
{
public:
    Person AddPerson(Person &p)
    {
        Person temp;
        temp.m_A = this->m_A + p.m_A;
        temp.m_B = this->m_B + p.m_B;
        return temp;
    }
public:
    int m_A;
    int m_B;
};

Person operator+(Person &p1,Person p2)
{
    Person temp;
    temp.m_A = p1.m_A + p2.m_A;
    temp.m_B = p2.m_B + p2.m_B;
    return temp;
}

void test01()
{
    Person p1;
    p1.m_A = 10;
    p1.m_B = 10;
    
    Person p2;
    p2.m_A = 10;
    p2.m_B = 10;
    
    Person p3 = p1.AddPerson(p2);
    //Person p3 = p1 + p2;
    
    cout << "p3.m_A = " <<p3.m_A <<endl;
    cout << "p3.m_B = " <<p3.m_B <<endl;
}

int main()
{
    test01();
    return 0;
}
