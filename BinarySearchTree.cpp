#include<iostream>
using namespace std;

struct Tree{
    int data;
    struct Tree* left;
    struct Tree* right;
};

struct Tree* makeTree(int data){
    struct Tree* tempTree = (struct Tree*)malloc(sizeof(struct Tree));
    tempTree->data = data;
    tempTree->left=tempTree->right= NULL;
    return tempTree;
} 

struct Tree* insert(struct Tree* current, int data){
    if(current==NULL){
        return makeTree(data);
    }
    if(data < current->data)
        current->left = insert(current->left, data);
    else if(data > current->data)
        current->right = insert(current->right, data);    

    return current;
}
void printPreOrder(struct Tree* node){
    if(node == NULL)
        return;
    
    cout<<node->data<<"\n";
    printPreOrder(node->left);
    printPreOrder(node->right);
}

int main(){
    struct Tree* root = NULL;
    root = insert(root,3);
    insert(root,4);
    insert(root,1);
    insert(root,20);

    cout<<"Printing the preOrder of tree:"<<"\n";
    printPreOrder(root);

}