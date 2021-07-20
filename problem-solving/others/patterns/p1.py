'''
Pattern 1:  List Pattern
Given a list of integers produces a unique pattern.
Identify the pattern and solve the problem.

Given list: {-2,2,3,4,-4}

Output:

   $$$
     $$$
     $$$$
     $$$$$
 $$$$$

 Given list: {-1,2,5,6,-2}

 Output:

       $$
       $$$
       $$$$$$
       $$$$$$$
     $$$

'''

li = list(map(int(input().split())))
n = len(li)
new = {abs(x) for x in li}
l_e = max(new)

for i in li:
    if i == abs(i):
        w = l_e
    else:
        w=l_e - abs(i)
    
    print(w*" ", (abs(i)+1)*"$")