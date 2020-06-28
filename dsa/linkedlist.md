### [Linked List](https://www.geeksforgeeks.org/data-structures/linked-list/)

##### Binary Search in a LL
    Memory allocation for the singly linked list is dynamic and non-contiguous, which makes finding the middle element difficult.

##### [Insertion in LL](https://www.geeksforgeeks.org/linked-list-set-2-inserting-a-node/)

##### [Find Middle Element of LL](https://www.geeksforgeeks.org/write-a-c-function-to-print-the-middle-of-the-linked-list/)
    - The first method is to use count the total elements. find the position and search.
    - The second is to use two pointers: 
        - The first one will traverse one place at a time and the second will traverse two places.
        - By the time second pointer reaches the end, the first ptr will reach the middle.

##### [Get Nth Element](https://www.geeksforgeeks.org/write-a-function-to-get-nth-node-in-a-linked-list/?ref=lbp)
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