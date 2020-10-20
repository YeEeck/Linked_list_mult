#include <iostream>
using namespace std;

class Lnode_list{
private:

public:
    typedef struct Lnode{
        int data;
        Lnode *next;
    };
    Lnode * head;

    Lnode_list(){
        head = new Lnode;
        head -> next = nullptr;
        head -> data = 0;
    }

    void insert_list(int list[], int num){
        for (int i = 0; i < num; i++){
            insert_list(list[i]);
        }
    }
    void insert_list(int e){
        auto *s = new Lnode;
        s -> data = e;
        s -> next = nullptr;
        Lnode *p = head;
        for(;;){
            if(p -> next == nullptr){
                p -> next = s;
                break;
            }
            p = p->next;
        }
    }
    void print(){
        Lnode *p;
        p = head;
        if(p -> next == nullptr){
            return;
        }
        p = p-> next;
        while(p != nullptr){
            cout << p -> data;
            if (p->next != nullptr){
                cout << ",";
            }
            p = p -> next;
        }
        cout << endl;
    }

    int even_number(){
        Lnode *p = head;
        int number = 0;
        if(p -> next == nullptr){
            return 0;
        }

        p = p -> next;
        while(p){
            if(p -> data % 2 == 0){
                number++;
            }
            p = p -> next;
        }
        return number;
    }
    void delete_same(){
        Lnode *p = head;
        Lnode *pr, *prr;
        if (p ->next == nullptr){
            return;
        }

        while((p = p -> next) != nullptr){
            pr = p;
            while(pr -> next){
                prr = pr;
                pr = pr -> next;
                if(pr -> data == p -> data){
                    prr -> next = pr -> next;
                    delete pr;
                    pr = prr;
                }
            }
        }
    }

    int del_x(int x){
        Lnode *p = head;
        Lnode *pr;
        int flag = 0;
        while(p -> next){
            pr = p;
            p = p -> next;
            if(p -> data == x){
                pr -> next = p -> next;
                delete p;
                p = pr;
                flag = 1;
            }
        }
        return flag;
    }

    int mult(Lnode_list *mult1){
        int sum = 0, numt;
        Lnode *p, *r;
        p = head, r = mult1->head;
        while (p->next != nullptr){
            p = p->next;
            numt = p -> data;
            while(r != nullptr){
                sum += p->data * r->data;
                r = r->next;
            }
            r = mult1->head;
        }
        return sum;
    }
};

int main(){
    Lnode_list Lnode1;
    Lnode_list Lnode2;
    int list1[] = {2,4,6,8};
    int list2[] = {5,2,6,7};
    Lnode1.insert_list(1);
    Lnode1.insert_list(9);
    Lnode1.insert_list(list1, 4);
    Lnode2.insert_list(list2, 4);
    Lnode2.insert_list(7);
    cout << "初始化链表，打印:" << endl;
    cout << "多项式1：" << endl;
    Lnode1.print();
    putchar('\n');
    cout << "多项式2：" << endl;
    Lnode2.print();
    putchar('\n');
    cout <<  "多项式运算结果为："  << Lnode1.mult(&Lnode2) << endl;
    getchar();
    return 0;
}


