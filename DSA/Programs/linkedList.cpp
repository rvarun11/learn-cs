#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
};

void push(Node** head, int data){
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void insertAfter(Node *prev_node, int data){
    if (prev_node == NULL){
    cout << "No previous node";
    return;
    }

    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = prev_node->next;
    prev_node->next = new_node->next;
}

void append(Node** head, int data){
    Node* new_node = new Node();
    Node* last = *head;
    new_node->data = data;
    // since appending at last so next is NULL
    new_node->next = NULL;

    while (last->next!= NULL)
        last = last->next;

    last->next = new_node;
    return;
}

void printList(Node* n){
    while (n!=NULL){
        cout << n->data << " ";
        n = n->next;
    }
}

void deleteNode(Node**head, int position){
    Node* temp = *head;

    while (temp!=NULL ){
        
    }

}


/* Driver code*/
int main()  
{  
    /* Start with the empty list */
    Node* head = NULL;  
      
    push(&head, 7);  
      
    // Insert 1 at the beginning.  
    // So linked list becomes 1->7->6->NULL  
    push(&head, 1);  
      
    // Insert 4 at the end. So  
    // linked list becomes 1->7->6->4->NULL  
    append(&head, 4);  
      
    // Insert 8, after 7. So linked  
    // list becomes 1->7->8->6->4->NULL  
    insertAfter(head->next, 8);  
      
    cout<<"Created Linked list is: ";  
    printList(head);  
      
    return 0;  
}  