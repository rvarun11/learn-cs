### Notes 2: C++ Basics 

##### Tail Recursion
    - Recursive Call (RC) is made at last.
    - Since RC is at last, they are optimized by compiler because stack frame of current RC is not needed to be saved.
    - It can be converted directly into a loop.

##### Head Recursion
    RC is at the start. Not optimized because stack frame has to be used later. 

##### Tree Recursion
    RC is made more than once in the same function.

##### Indirect Recursion
    - Here, a recursive cycle is formed between different func.
    - For eg., for func A, B & C, A is calling B, B is calling C & C is calling A.

##### Nested Recursion
    The parameter of RC is a RC.
~~~c++
void func (int n){
if (__)
	func (func(n-1));
}
~~~