#include<iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

class Tree{
    private:
        node* root;
        node* insert(node* current,int val){
            if (current == nullptr){
        
            node* newNode = new node;
            newNode->data = val;
            newNode->left = nullptr;
            newNode->right = nullptr;

            return newNode;
        }

      
        if (val < current->data)
        {
            current->left = insert(current->left, val);
        }
        else if (val > current->data)
        {
            current->right = insert(current->right, val);
        }

        return current;
    }
    public:
        Tree (){
            root = nullptr;
        }
        void insert(int val){
            root = insert(root,val);
        }
};