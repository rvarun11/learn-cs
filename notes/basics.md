### N1: Basics

##### [Segments](https://www.geeksforgeeks.org/memory-layout-of-c-program/)
    Main memory is divide into manageable pieces called segments. Each segment is divided into 3 sections, Code, Stack and Heap sections.

##### Stacks & Heaps
    - Variables are stored inside the stack in the main memory segment. The portion of stack is called **activation record/ stack frame**. Topmost activation record belongs to the function currently being executed. Stacks are used during static memory allocation.
    - **Heaps** are used in dynamic memory allocation. To access anything in heap, a *pointer* has to be used.

##### Physical & Logical DS
    - *PDS*: Arrays & LL
    - *LDS*: Stacks (LIFO), Queues (FIFO), Trees, Graphs & Hash Table. LDS are implemented using PDS.

##### ADT
    Any Data Type has its set of Operations and Representation.

##### Time Complexity
    TC can be defined by the function of time needed by an algorithm to complete, for different inputs. It helps in analyzing how good an aglorithm is. Read desc of {TC}(https://www.youtube.com/watch?v=fZc3ijGM0aM)

#### Pointers
    - Pointers help in accessing resources which are outside the program (heap, files, etc.) and parameter passing.
    - Pointer takes same amout of space as taken by integer datatype.
    - To create an alias/reference for a varialble use &. For eg.
~~~c
  main(){
      int a = 10;
      int &r = a;
 }
 ~~~ 

#### Functions
    - Monolithic Program : Writing code without using functions.
    - Modular/Procedular Program : Using functions to write your code. It improves resuability.
    - When a function is called, its own activation record is created in the main memory.
    - Parameter Functions Passing in Functions:
        - Pass by Value
        - Pass by Address
        - Pass by Reference (in C++)

##### [Basic IO](https://www.geeksforgeeks.org/basic-input-output-c/)
