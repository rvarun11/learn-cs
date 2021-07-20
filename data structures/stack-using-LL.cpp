// https://www.geeksforgeeks.org/implement-a-stack-using-singly-linked-list/

#include <bits/stdc++.h>
using namespace std;

// operations ->
// pop() and push(x)

class LLNode {
    public:
    int val;
    LLNode* link;
};

LLNode* top = NULL;

void push(int data) {
    LLNode* temp = new LLNode();
    temp->val = data;
    temp->link = top;
    top = temp;
}

bool isEmpty(){
    return top == NULL;
}

void pop() {
    if (isEmpty()) {
        cout << "Stack is empty" << endl;
    }
    else {
        LLNode* temp = top;
        top = top->link;
        
        // we have to do this because free() does change the value of the pointer.
        temp->link = NULL;
        free(temp);
    }
}

void display() {
    LLNode* temp;

    if (top == NULL) {
        cout << "Stack is empty" << endl;
    }
    else {
        temp = top;
        while (temp) {
            cout << temp->val << "->";
            temp = temp->link;
        }
        cout << endl;
    }
}

int main(){
    push(11);
    push(13);
    push(15);
    push(4);
    display();
    pop();
    display();

    return 0;
}