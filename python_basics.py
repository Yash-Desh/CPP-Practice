#LIST#
#like vectors, grow and shrink as needed
#sequence, sortable
x = 'horse' + 'shoe'
print (x)

x = ['pig' , 'cow'] + ['horse']
print (x)

x = x * 3
print (x)


#Check if item is in list
print ('cow' in x)

#Iterating in list
x = [1,2,2,3,4,5]
print(len(x))
for item in x:
    print (item)

#sort

x.sort(reverse=True)
print(x)


#find minimum/maximum in list
print(min(x))
print(max(x))


#sum of all elements or some items
print(sum(x))
print(sum(x[0:2]))


#count of items
print (x.count(2))


#index of first occurence of item
print(x.index(2))

#Above was SEQUENCE, LIST IS LIKE AN ADDITION TO SEQUENCE

#delete item @ index 2 from the list
del x[2]
print(x)
#append
x.append(100)
x.append(x)
#insert at index
x.insert(0,999)
#delete last
x.pop()
#remove first instance of item
x.remove(999)
#sort and reverse
x.reverse()
x.sort()

print(x)

#List constructor using for loops

y = [i**2 for i in range(10) if i>5]
print(y)

##################################################################################

#TUPLE#
#immutable (can't add/change) like static vectors
#albeit items inside tuple are
#useful for fixed data
#faster than lists
#sequence

t = tuple(y)
print(t)



##################################################################################

#SET#
#store non-duplicate items
#fast access vs list
#unordered

s = {1,2,3,81}
se = set(t)
st = {i**2 for i in range(10) if i>5}
print(st)
print(s,se)


#add item in set
st.add(9999)
st.remove(81)
print(st)

#check item in set
print(81 in st)

#clear set
st.clear()
print(st)

#Mathematical operator
#Intersection of 2 sets
print(s & se)
#Union of 2 sets
print(s | se)
#Symmetric Difference, items in s but not se , items in se not in s
print(s ^ se)
#Difference, items in s but not in se
print(s - se)
#Subset check of sets s contains se
print(s >= se)
##################################################################################

#DICT#
#Key/Value pairs
#Associative array, HashMap
#Unordered

mp = {'pork':25, 'beef':35, 'chicken':15}
print(mp)

#change key value
mp['beef'] = 50

#remove item, like erase in cpp
del mp['chicken']
print(mp)


#check item in dict
print('pork' in mp)


#get list of keys in x
print(mp.keys())

#get list of values in x
print(mp.values())

#get list of {key,value}s 
print(mp.items())

for i in mp.keys():
    if(i == 'pork'):
        print('Success')

##################################################################################
#Reorder a list
l = [1,2,2,3,4,5]



#Invert the key and value in dictionary

inv_mp = {v:k for k,v in mp.items()}
print(inv_mp)

#Use regex to remove all special characters from a string
text = "Hello!@#$ World."
import re
cleaned_text = re.sub(r'[^a-zA-Z0-9\s]','', text)

print(text,cleaned_text)


#File handling 

f = open('arrays.sv','r')
#readfirst line, ptr incremnts in line granularity
print(f.readline())
#write file
f1 = open('abc.txt', 'w')
f1.write("ECE552 written")
#append mode, do not overwrite
f1.close()
f1 = open('abc.txt', 'a')
f1.write("EXTRA ApPENDED STUFF")


#write everything from f to f1
for data in f:
    f1.write(data)

#check presence of text in string
print('Hello' in cleaned_text)
#uppercase
print(cleaned_text.upper())
#index of World substring
print(cleaned_text.find("World"))
#replace 
print(cleaned_text.replace("World", "Earth"))
