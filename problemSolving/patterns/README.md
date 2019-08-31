
#### P1: [List Pattern](https://github.com/rvarun11/learn-cs/blob/master/problemSolving/patterns/solutions/p1.py)
Given a list:  [-2,2,3,4,-4]
~~~
   $$$
     $$$
     $$$$
     $$$$$
 $$$$$
~~~
~~~python
li = list(map(int(input().split())))
n = len(li)
new = [abs(x) for x in li]
l_e = max(new)

for i in li:
    if i == abs(i):
        w = l_e
    else:
        w=l_e - abs(i)
    
    print(w*" ", (abs(i)+1)*"$")
~~~

#### P2: [Half, Full & Pyramid](https://github.com/rvarun11/learn-cs/blob/master/problemSolving/patterns/solutions/p2.py)

~~~
Half pyramid...

*
**
***
****
*****

Full pyramid...

    *
   ***
  *****
 *******
*********

Inverted pyramid...

*********
 *******
  *****
   ***
    *
~~~

~~~python
def half_pyramid(rows):
    print('Half pyramid...\n')
    for i in range(rows):
        print('*' * (i+1))

def full_pyramid(rows):
    print('\nFull pyramid...\n')
    for i in range(rows):
        print(' '*(rows-i-1) + '*'*(2*i+1))

def inverted_pyramid(rows):
    print('\nInverted pyramid...\n')
    for i in reversed(range(rows)):
        print(' '*(rows-i-1) + '*'*(2*i+1))

half_pyramid(5)
full_pyramid(5)
inverted_pyramid(5)
~~~