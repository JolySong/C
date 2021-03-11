//
//  main.cpp
//  Latin_Policy
//
//  Created by song on 2021/3/1.
//

#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *Next;
};

class Latin
{
private:
    Node *rear = new Node;
public:
    void init(){
        rear->data = 0;
        rear->Next = NULL;
    }
    struct Node *Creat(int x){
        Node *p = new Node;
        p->data = x;
        p->Next = rear;
        return p;
    }
    void CreatLatin(int n){
        init();
        Node *p = new Node;
        for(int i=1;i<=n;i++){
            p->Next =  Creat(i);
            if (i==1) {
                rear->Next = p->Next;
            }
            p = p->Next;
        }
        delete p;
        
    }
    void PrintList(Node *r){
        Node *p = new Node;
        p = r;
        while(p->data){
            cout<<p->data<<" ";
            p = p->Next;
        }cout<<endl;
    }
    int getlenght(){
        int cnt = 0;
        Node *p = new Node;
        p = rear->Next;
        while (p->data) {
            cnt++;
            p = p->Next;
        }
        delete p;
        return cnt;
    }
    void PrintLatin(){
        Node *p = new Node;
        int len = getlenght();
        Node *temp = new Node;
        temp = rear;
        for (int i=0; i<len; i++) {
            p = temp->Next;
            for (int j=0;j<len; j++) {
                if(p->data){
                 cout<<p->data<<" ";
                }else{
                    j--;
                }
                p = p->Next;
            }cout<<endl;
            temp = temp->Next;
        }
        delete p;
    }

};
int main(int argc, const char * argv[]) {
    Latin list;
    int num;
    cout<<"Please enter number(2~9): "; cin>>num;
    list.CreatLatin(num);
    list.PrintLatin();
    return 0;
}
