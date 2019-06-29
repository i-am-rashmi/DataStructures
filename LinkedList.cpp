#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
};
//Print Linked List
void printList(Node* head){
    while(head!=NULL){
        cout<<head->data<<"\n";
        head = head->next;
    }
}
int lengthOfList(Node* head){
    int count = 0;
    Node* current = head;
    while(current!=NULL){
        count++;
        current = current->next;
    }
    return count;
}
//Function to insert at the beginning 
void insertBeginning(Node** head,int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
//Function to insert at the end
void append(Node** head, int data){
     Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    Node* last = *head;
    if(head!=NULL){
        while(last->next !=NULL){
            last = last->next;
        }
            last->next = newNode;
            return;

    }else{
        *head = newNode;
        return;
    }
   
}
void insertAfterANode(Node* currentPos, int data){
    if(currentPos!=NULL){
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = currentPos->next;
        currentPos->next = newNode;
    }

}
void insertAtPosition(Node**  head,int pos, int data){
    //check if position is greater than length
    if(pos> lengthOfList(*head)){
        cout<<"Index out of bound";
    }else{
        //if not traverse to that position and then insert 

        int count = 0;
        Node* current = *head;
        while(count<pos-2){
            count++;
            cout<<"Position is:"<<count<<"\n";
            current = current->next;
            cout<<"Current data:"<<current->data<<"\n";
        }
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = current->next;
        current->next = newNode;
    }
}

//Delete node at beginning
void deleteHead(Node** head){
    if(head==NULL){
        cout<<"List is empty";
        return;
    }
    Node* temp = *head;
    *head = temp->next;
    free(temp);

}
//Delete node at end
void deleteTail(Node** head){
    if(head==NULL){
        cout<<"List is empty";
        return;
    }
    Node* temp = *head;
    while(temp!=NULL){
        if(temp->next->next==NULL){
            free(temp->next);
            temp->next = NULL;
            return;
        }
        temp = temp->next;
    }
    
}
//delete node at a particular position 
void deleteNodeOfPosition(Node** head, int position){
    if(position> lengthOfList(*head)){
        cout<<"Index out of bound";
    }else{
        //if not traverse to that position and then insert 

        int count = 0;
        Node* current = *head;
        while(count<position-2){
            count++;
            current = current->next;
            cout<<"Current data:"<<current->data<<"\n";
            
        }
        Node* nodeToDelete = current->next;
        current->next = nodeToDelete->next;
             free(nodeToDelete);

        
    }

}

//delete node of particular key 
void deleteNodeOfValue(Node** head, int key){
    if(head==NULL){
        cout<<"List empty";
    }
    
    Node* current = *head;
    if(current->data == key){
        //Head has the key
        *head = current->next;
        free(current);
        return;
    }
    while(current!=NULL){
        if(current->next->data == key){
            Node* nodeToDelete = current->next;
            current->next = nodeToDelete->next;
            free(nodeToDelete);
        }
    }
}


//Driver function
int main(){
    Node* head = NULL;
    cout<<"Length of list"<<lengthOfList(head)<<"\n";
    insertBeginning( &head , 2); 
    cout<<"Length of list"<<lengthOfList(head)<<"\n";
    printList(head);

    append(&head,4);
    cout<<"Length of list"<<lengthOfList(head)<<"\n";
    printList(head);

    insertAtPosition(&head,2,12);
    cout<<"Length of list"<<lengthOfList(head)<<"\n";
    printList(head);

    // deleteHead(&head);
    // cout<<"Length of list"<<lengthOfList(head)<<"\n";
    // printList(head);

    // deleteTail(&head);
    // cout<<"Length of list"<<lengthOfList(head)<<"\n";
    // printList(head);
    
    // deleteNodeOfPosition(&head,2);
    // cout<<"Length of list"<<lengthOfList(head)<<"\n";
    // printList(head);

    deleteNodeOfValue(&head,2);
    cout<<"Length of list"<<lengthOfList(head)<<"\n";
    printList(head);


    
    return 0;
}
