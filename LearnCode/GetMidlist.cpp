//
//  main.cpp
//  GetMidlist
//  //随即创建10个元素的链表
//  Created by song on 2021/2/25.
//

#include <iostream>
#include <ctime>
using namespace std;

struct Node
{
    int data;
    struct Node *Next;
};

class linklist
{
public:
    Node *head = new Node;
    void Init(){
        head->Next = NULL;
    }
    bool IsEmpty(){
        if(!head->Next){
            cout<<"该链表为空链表,请先创建一个链表。"<<endl;
            return false;
        }
        else return true;
    }
    void getlength(){
        if (!IsEmpty()){
            return;
        }
        Node *m = head->Next;
        int cnt = 0;
        while(m){
            cnt++;
            m = m->Next;
        }
        cout<<"链表的长度为: "<<cnt<<endl;
    }
    void Print(){
        if (!IsEmpty()){
            return;
        }
        Node *m = head->Next;
        while(m){
            cout<<m->data<<" ";
            m = m->Next;
        }cout<<endl;
    }
    void getMidValue(){
        if (!IsEmpty()){
            return;
        }
        Node *search,*mid;
        mid = search = head;
        while (search->Next != NULL) {
            if(search->Next->Next != NULL){
                search = search->Next->Next;
                mid = mid->Next;
            }else{
                search = search->Next;
            }
        }
        cout<<"中间节点值为: "<<mid->data<<endl;
    }
    void Creat(){
        if (IsEmpty()){
            char sel;
            cout<<"当前已有存在的链表，确定要创建(y/n): "; cin>>sel;
            if(sel == 'n'){
                cout<<"操作已取消"<<endl;
                return;
            }else if(sel == 'y'){
                Node *p = head;
                for(int i=0;i<10;i++){
                    int random = rand()%100+1; //随机数
                    struct Node *t = new Node;
                    t->data = random;
                    t->Next = NULL;
                    p->Next = t;
                    p = p->Next;
                }cout<<"链表已经创建完成，元素为: "<<endl;
                Print();
            }else{
                cout<<"你的输入有误，返回主界面"<<endl;
                return;
            }
        }else{
            Node *p = head;
            for(int i=0;i<10;i++){
                int random = rand()%100+1; //随机数
                struct Node *t = new Node;
                t->data = random;
                t->Next = NULL;
                p->Next = t;
                p = p->Next;
            }cout<<"链表已经创建完成，元素为: "<<endl;
            Print();
        }
    }
    void Findx(){
        if (!IsEmpty()){
            return;
        }
        int x;
        cout<<"请输入你要查找节点的值: "; cin>>x;
        Node *p = head->Next;
        int cnt = 0;
        while(p){
            cnt++;
            if(p->data == x){
                cout<<"节点位置在第 "<<cnt<<" 个"<<endl;
                return;;
            }
            p = p->Next;
        }
        cout<<"No find it!"<<endl;
    }
    void clear()
    {
        if (!IsEmpty()){
            return;
        }
        char sel;
        cout<<"确定清空链表(y/n): "; cin>>sel;
        if (sel == 'y') {
            head->Next = NULL;
            cout<<"已经清空"<<endl;
        }else{
            cout<<"操作已取消"<<endl;
            return;
        }
    }
    void Menu()
    {
        cout<<"*************************"<<endl;
        cout<<"***** 1.  查看链表    *****"<<endl;
        cout<<"***** 2.  创建链表    *****"<<endl;
        cout<<"***** 3.  链表长度    *****"<<endl;
        cout<<"***** 4.  中节点值    *****"<<endl;
        cout<<"***** 5.  查找节点    *****"<<endl;
        cout<<"***** 6.  清空链表    *****"<<endl;
        cout<<"***** 0.  退  出     *****"<<endl;
        cout<<"*************************"<<endl;
        cout<<"*************************"<<endl;
        cout<<"Please enter your select(0~6): ";
    }
   
};
int main(int argc, const char * argv[]) {
    //随机数种子
    srand((unsigned int) time(NULL));
    linklist list;
    list.Init();
    while(1){
        int sel;
        list.Menu();
        cin>>sel;
        switch (sel) {
            case 1: list.Print(); break;
            case 2: list.Creat(); break;
            case 3: list.getlength(); break;
            case 4: list.getMidValue();break;
            case 5: list.Findx(); break;
            case 6: list.clear(); break;
            case 0: exit(0); break;
            default: cout<<"你的输入有误，程序结束"<<endl; exit(0);
        }
    }
    return 0;
}
