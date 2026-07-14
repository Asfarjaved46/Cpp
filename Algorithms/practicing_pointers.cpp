#include<iostream>
using namespace std;

struct node{
        int data;
        node* next;
};

class LinkedList{
    private:
        node* head;
    public:
        LinkedList(){
            head = nullptr;
        }
        void InsertStart(int num){
            node * newnode = new node;
            newnode->data = num;
            newnode->next = head;
            head = newnode;
        }
        void InsertLast(int val){
            node * newnode = new node;
            newnode->data =  val;
            newnode->next = nullptr;

            if(head == nullptr){
                head = newnode;
                return;
            }

            node *temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = newnode;
        }

        void display(){
            node* temp = head;
            while(temp!= nullptr){
                cout<<temp->data;
                cout<<"->";
                temp = temp->next;
            }
            cout<<"NULL";
            return;
        }

        void Search(int val){
            node* temp = head;
            int n;
            while(temp != nullptr){
                if(temp->data == val){
                    n = temp->data;
                    cout<<n;
                }
                temp = temp->next;
            
            }
            
        }

        void DeleteNode(int val){

            if (head == nullptr){
                cout << "List is empty.\n";
                return;
            }
    
            if (head->data == val){
                node* toDelete = head;
                head = head->next;
                delete toDelete;
                return;
    }

    
            node* temp = head;
            while(temp->next != nullptr){
                if(temp->next->data == val){
                    node *  toDelete = temp->next;
                    temp->next = temp->next->next;
                    delete toDelete;
                    return;
                }
                temp = temp->next;
            }
        
        }
};

int main(){
    LinkedList l;
    l.InsertStart(5);
    l.InsertLast(10);
    l.InsertStart(0);
    l.display();
    cout<<endl;
    l.Search(10);
    cout<<endl;
    l.InsertLast(20);
    l.DeleteNode(10);
    l.display();
}



