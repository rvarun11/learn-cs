### N3: {Linked List}(https://www.geeksforgeeks.org/data-structures/linked-list/)

##### Binary Search in a LL
    Memory allocation for the singly linked list is dynamic and non-contiguous.
    It makes finding the middle element difficult.

##### {Insertion in LL}(https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/)

##### {Find Middle Element of LL}(https://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/)
    - The first method is to use count the total elements. find the position and search.
    - The second is to use two pointers: 
        - The first one will traverse one place at a time and the second will traverse two places.
        - By the time second pointer reaches the end, the first ptr will reach the middle.
    - Delete the middle element
~~~c++
Node* delMid(Node* head, int data){
    if (head == NULL)
        return NULL;
    if (head->next == NULL){
        delete head;
    }
    Node *prev, *slow_ptr,*fast_ptr;
    while (fast_ptr != NULL){
        fast_ptr = fast_ptr->next->next;
        prev = slow_ptr->next;
        slow_ptr = slow_ptr->next
    }
    prev->next = slow_ptr->next;
    delete slow_ptr
    return head;
}
~~~

##### {Reverse a LL}(https://www.youtube.com/watch?v=Tk_fi5l8cag)
~~~c++
Node *reverseLL(Node* head){
    // we need 3 ptrs. 
    Node *prev, *current, *nxt;
    prev = NULL;
    current = head;
    nxt = head->next;
    while (nxt!= NULL){
        current->next = prev; // making the next pointer point to the previous node
        // iterate all 3 ptrs forward
        prev = current; 
        current = nxt;
        nxt = nxt->next;
    }
}
~~~

##### {Get Nth Element}(https://www.geeksforgeeks.org/write-a-function-to-get-nth-node-in-a-linked-list/?ref=lbp)
~~~c++
int GetNth(Node* head, int index)  
{  
      
    Node* current = head;  

    int count = 0;  
    while (current != NULL)  
    {  
        if (count == index)  
            return(current->data);  
        count++;  
        current = current->next;  
    }  
~~~

##### {Flattening a LL}(https://www.geeksforgeeks.org/flattening-a-linked-list/)
~~~c++
Node* merge( Node* a, Node* b ) 
{ 
    // If first list is empty, the second list is result 
    if (a == NULL) 
        return b; 
  
    // If second list is empty, the second list is result 
    if (b == NULL) 
        return a; 
  
    // Compare the data members of head nodes of both lists and put the smaller one in result 
    Node* result;
    if (a->data < b->data) 
    { 
        result = a; 
        result->down = merge( a->down, b ); 
    } 
    else
    { 
        result = b; 
        result->down = merge( a, b->down ); 
    } 
  
    result->right = NULL; 
    return result; 
}
~~~
