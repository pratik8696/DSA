# intro to list
from scipy import stats
from statistics import mean
import random
import matplotlib.pyplot as plt
shopping = ["Bread", "Jam", "Tea"]
print(shopping)

# loop
for i in range(len(shopping)):
    print(i)

for i in range(len(shopping)):
    print(shopping[i])

for item in shopping:
    print(item)

# append function
shopping.append("Curd")

print(shopping)

# insert function (index,"content")
shopping.insert(1, "Oil")

print(shopping)

ages = [1, 2, 3, 4, 5, 6, 1, 2, 4, 5, 1, 2, 3, 4, 1, 2, 3, 1, 2, 1]

# using the count function
print(ages.count(5))
print(ages.count(0))

# using the len function
print(len(ages))

# using the sort function
ages.sort()
print(ages)

# using the REVERSE function
ages.reverse()
print(ages)

students = ["Arun", "Rajesh", "Harish", "Alankita", "Lakshmi", "Menika"]
students.sort()
print(students)

students.insert(2, "Ankita")
print(students)

# using SLICING
print(students[:])
print(students[2:3])
print(students[3:6])
print(students[2:4])
print(students[-1:])
print(students[-2:])
# piche se start hoga aur -1 ka jump hoga
print(ages[::-1])
# piche se start hoga aur -2 ka jump hoga
print(ages[::-2])
# piche se start hoga aur -5 ka jump hoga
print(ages[::-5])
# pichse se (-10+n)%n se start hoga aur end tk jayega
print(ages[-10::])
print(ages[-8::])
# reverse loop hai ye
for i in range(80, 10, -20):
    print(i)


# def create kro
def fizzbuzz(r):
    for i in range(1, r):
        if (i % 3 == 0 and i % 5 == 0):
            print(str(i)+" = FizzBuzz")
        elif (i % 3 == 0):
            print(str(i)+" = Fizz")
        elif (i % 5 == 0):
            print(i, " = Buzz")


fizzbuzz(100)

# estimates = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
#              16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30]
# estimates.sort()
# m = stats.trim_mean(estimates, 0.1)
# print(m)

# # using matplotlib
# y = []
# for i in range(len(estimates)):
#     y.append(10)

# plt.plot(estimates, y, 'r--')

# using random


# def choose():
#     words = ['rainbow', 'computer', 'programming',
#              'player', 'condition', 'reverse', 'water', 'board']
#     pick = random.choice(words)
#     return pick


# def jumble(s):
#     a = random.sample(s, len(s))
#     return a


# def play():
#     p1name = input("Enter name of player 1")
#     p2name = input("Enter name of player 2")
#     pp1 = 0
#     pp2 = 0
#     turn = 0
#     while (1):
#         picked_word = choose()
#         qn = jumble(picked_word)
#         if (turn % 2 == 0):
#             print("Your turn ", p1name)
#         else:
#             print("Your turn second player ", p2name)
#         c = int(input("Do you wish to continue"))
#         if (c == -1):
#             break
#         turn += 1

# # play()


# # some coding problem
# a, b = 1, 0
# print(a)
# print(b)

# n = int(input("ENter the size of the stairs"))

# for i in range(1, n+1):
#     print(end="\n")
#     for j in range(1, i+1):
#         print('*', end=" ")


# # fibonacci find krna

# def fibo(x):
#     if (x < 0):
#         return 0
#     if (x <= 1):
#         return 1
#     return fibo(x-1)+fibo(x-2)

# for i in range(10):
#     print(fibo(i),end=" ")

# # printing the square
# for i in range(n):
#     for j in range(n):
#         print('*',end="")
#     if(i!=n-1):
#         print()

# file handling 

# with open("myfile.txt","r+") as myfile:
#     print(myfile.read())
#     myfile.write("I am fine")
# myfile.close()

# now use of random numbers

import random

# both inclusive
print(random.randint(7,8))
# left<= and right<
print(random.randrange(7,8))
# random.random from 0 to 1
print(random.random())
# randrange with steps
print(random.randrange(1,10,2))
# random.choice ek list se hi lega random number
array=[1,2,3,4,5,6,7]
print(random.choice(array))

gene=[]
for i in range(20):
    if(i%7==0):
        gene.append(1)
    else:
        gene.append(0)

# agr yhi code koi file se lete then pura list ek char array hota

print(gene)
    
def evolve(x):
    idx=random.randint(0,len(x)-1)
    prob=random.randint(1,10)
    if(prob==1):
        if(x[idx]==0):
            x[idx]=1
        else:
            x[idx]=0

for i in range(10000):
    evolve(gene)

print(gene)