# Q. https://practice.geeksforgeeks.org/problems/longest-common-substring/0
# A. https://www.geeksforgeeks.org/longest-common-substring-dp-29/

t = int(input())

for c in range(t):
    n,m = input().split()
    n,m = int(n),int(m)
    x = input()
    y = input()
    
    xlist = {}

    for i in range(n):
        for j in range(i,n):
            xlist.append(x{i:j+1})

    max = 0    
    for i in xlist:
        if i in y:
            if len(i) > max:
                max = len(i)

    print(max)

