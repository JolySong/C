//
//  main.cpp
//  CircleLinkList
//
//  Created by song on 2021/3/1.
//

#include <iostream>
using namespace std;

template<class T>
struct Node{
    T Data;
    struct Node *Next;
};

class YsfQuesion
{
public:
    Node<int> *head = new Node<int>;
    int sum = 41;
    struct Node<int> *Creat(int x){
        Node<int> *phead = new Node<int>;
        phead->Data = x;
        phead->Next = head;
        return phead;
    }
    void CreatYsf(){
        Node<int> *p = new Node<int>;
        p = head;
        for (int i = 1; i<=sum; i++) {
            p->Next = Creat(i);
            p = p->Next;
        }
        delete p;
    }
    void Print(){
        Node<int> *p = new Node<int>;
        p = head->Next;
        
        while(p->Next!=head){
            cout<<p->Data<<" ";
            p = p->Next;
        }
        cout<<p->Data<<endl;
    }
    void Delete(Node<int> *p){
        Print();
        if(p->Next==head){
            cout<<"Kill: "<<p->Next->Next->Data<<endl;
            head->Next = head->Next->Next;
            p = p->Next->Next;
        }else{
            cout<<"Kill: "<<p->Next->Data<<endl;
            p->Next = p->Next->Next;
        }
    }
    void KillNode(){
        Node<int> *p = new Node<int>;
        p = head;
        while(sum!=2){
            for (int i=1; i<3; i++) {
                if(p->Next==head){
                    i--;
                }
                p = p->Next;
                if (i==2) {
                    Delete(p);
                    sum--;
                }
            }
        }
        delete p;
    }
};
int main(int argc, const char * argv[]) {
    YsfQuesion list;
    list.CreatYsf();
    list.KillNode();
    cout<<"存活的是: "<<endl;
    list.Print();
    return 0;
}
