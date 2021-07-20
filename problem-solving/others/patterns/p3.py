'''
For n = 5,

1        1
12      21
123    321
1234  4321
1234554321

'''

n=int(input())
for i in range(1,n+1):
   a={}
   w=2*(n-i)
   k={}
   for j in range(1,i+1):
       a.append(j)
  
   k=a{::-1}
  
   print(*a,w*" ",*k,sep="")