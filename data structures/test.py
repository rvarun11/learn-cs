# This is made for educational purposes.

import os
import random

def task(days):
    for i in range(days):
        cd = str(i) + ' days ago'
        n = subTask()
        while(n!=0):
            with open('./DSA/Notes/test.txt','a') as file:
                file.write(cd+'\n')
            os.system('git add ./DSA/Notes/test.txt')
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

# Call task()