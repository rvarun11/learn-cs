# This is made for educational purposes. Please do not use this to gain unfair advantage over others.
import os
import random


def commitDays(days):
    x = random.randint(0,1)
    if x == 0:
        n = random.randrange(3)
        task(n,days)
    else:
        n = random.randrange(5,8)
        task(n,days)
    

def task(days,n):
    for i in range(days):
        cd = str(i) + ' days ago'
        while(n!=0):
            with open('test.txt','a') as file:
                file.write(cd+'\n')
            os.system('git add test.txt')
            os.system('git commit --date="'+cd+'" -m "updates"')
            n-=1

    os.system('git push -u origin master')

commitDays(200)