# Date : 13-08-2024
# Author : Yash Deshpande
# Tutor : Love Babbar OS Series

from threading import *

lock = Lock()
count =0

def task():
    # lock.acquire()
    global count
    for i in range (1000000):
        count += 1
    # lock.release()


if __name__ == '__main__':
    t1 = Thread(target = task)
    t2 = Thread (target = task)

    t1.start()
    t2.start()

    t1.join()
    t2.join()

    print(count)