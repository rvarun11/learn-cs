# This is made for educational purposes. Please do not use this to gain unfair advantage over others.

import os
import random

def task(days):
    for i in range(days):
        cd = str(i+2) + ' days ago'
        n = subTask()
        while(n!=0):
            with open('test.txt','a') as file:
                file.write(cd+'\n')
            os.system('git add test.txt')
            os.system('git commit --date="'+cd+'" -m "updates"')
            n-=1

def subTask():
    x = random.random()
    if x<=0.2:
        n=0
    elif (x>0.2 and x<0.55):
        n = random.randrange(1,3)
    else:
        n = random.randrange(4,9)
    return n
    
task(250)