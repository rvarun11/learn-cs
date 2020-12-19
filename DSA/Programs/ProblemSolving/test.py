
n = int(input())
li = []
for i in range(n):
    li.append(input())

q = int(input())
ans = []

for i in range(q):
    l,r,k = input().split()
    l,r,k = int(l),int(r),int(k)
    
    sub = ''
    for i in range(l-1,r):
        sub+=(li[i])
    sub = sorted(sub)
    ans.append(sub[k-1])

for i in ans:
    print(i)
    

