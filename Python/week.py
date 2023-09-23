import numpy as np

x = np.array([[1, 2], [3, 4], [5, 6]])
y = np.array([[4, 3], [1, 9], [2, 4]])

print(x)
print(x.T)
print(np.sqrt(x))
print(np.divide(x, y))
print(np.sum(x))
print(np.sum(x, axis=0))
print(np.sum(x, axis=1))

s = "ankur loves parul"
s.replace('parul', 'shruti')
print(s)

a = np.array([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14])
print(a.reshape(7, 2))

b = [1, 2, 3, 4, 5]
b.extend(b)
print(b)

a = (1, 2, 3)
for i in range(10):
    a += (i,)

print(a)

# dictionary does not allow duplicates
thisdict = {
    "ankur": "parul",
    "sandhya": "randi",
    "patle": "bull"
}

print(thisdict["ankur"])
# ye dega keys
print(thisdict.keys())
# ye dega value
print(thisdict.values())
# ye dega dono
print(thisdict.items())
# check function for dictionary
if "ankur" in thisdict:
    print("ANkur loves parul")
thisdict.update({"ankur": "shruti"})
print(thisdict.items())
thisdict["raj"] = "more"
# delete functions are pop,popitem,del
# use of pop
# thisdict.pop("ankur")
# print(thisdict.items())
# thisdict.popitem()
# print(thisdict.items())
# del thisdict["sandhya"]
# print(thisdict.items())
# print(len(thisdict))

for x in thisdict:
    print("The key is ", x, " and the value is ", thisdict[x])
for x, y in thisdict.items():
    print("The key is ", x, " and the value is ", y)
