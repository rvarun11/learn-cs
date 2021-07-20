### N2: Arrays

##### Declaring & Accessing
    Apart from normal ways, an array element can be called using
~~~c++    
int A{5};
cout << *(A+2);
cout << 2{A};
~~~

##### Static & Dynamic Allocation
    Static allocation is done inside the Stack block & Dynamic allocation is done inside the Heap block.

##### Array Size
    - It can't be increased or decreased because array requires *contiguous* memory blocks.
    - Formula for address of an element of array. *s* is the size of data type.
    `addr(A{i}) = base addr + (index * s)`

##### 2D Arrays
~~~c++
// Declaration
int A{2}{3} = {{1,2,3},{4,5,6}};
// For putting each element in heap:
int *B{2};
B{0} = new int{3};
B{1} = new int{3};
// For putting the complete array in heap:
int **C{2};
C = new int*{3};
C{0} = new int{3};
C{1} = new int{3};
~~~
    - Row Major Mapping of a 2D array of  *R x C* size*:* `addr(A{i}{j}) = base_addr + (i*C + j)* s` where, *s* is the size of data type.
    - Column Major Mappying: `addr(A{i}{j}) = base_addr + (j*R + j)* s`
    - C/C++  uses Row Major Mapping for storing elements in 2D