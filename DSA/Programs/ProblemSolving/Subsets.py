# https://practice.geeksforgeeks.org/problems/subsets/0/
# A. 

arr = [1,2,3]

for i in range(0,len(arr)):
    if i==0:
        print("()",end=" ")
    print("(",end="")
    print(arr[i], end=" ")
    print(")",end=" ")