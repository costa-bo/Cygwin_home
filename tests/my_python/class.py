class A(object):
    def foo(self,x): # thelei panta instance
        print ("executing foo(%s,%s)" %(self,x))
    @classmethod
    def class_foo(cls,x): 
        print ("executing class_foo(%s,%d)" %(cls,x))
        
    @staticmethod
    def static_foo(y):
        print ()
        
a= A() # instance

a.foo(1)
A.class_foo(1)
a.static_foo(1)


#
s= "hello, kosta"
s.split(',')

a = ['hello', 'smap', 100, 'no']
a[0:2] = [1,12]
print (a)


#Lists
b = ['xt', 2, 'monster']
b.append('nokia')
#b.sort()
if 'xt' in b:
    print ('xt in b\n\n')
print (b)

squares = [x*2 for x in range(10)]
print (squares, '\n\n')


#Dictionaries
d = {'db': 3,'database': 'master'}
d['database'] = 'yamaha'
for x in d.keys():
    d[x]= 'none'
del d['db'] # diagrafeis ena key kai automatos diagrafete k to value(pane mazi)
print ('#dictionaries\n','database' in d.keys()) # return true or fauls
d.get('database') 
print (d.values(), '\n\n')


#tuples
t = ('sss', 'xaxa')
#t[0] = 1 # den ginete na allaksoun
t = list(t) # to ekana lista ara mporo na tp allakso mporo k t antitheto me ta: (tup, list, dic)


basket = ['apple', 'orange', 'apple', 'pear', 'orange', 'banana'] 
bask = set(basket) #diagrafei ta idia
rm = set(['pear', 'rrrrr'])
print ( set(basket) ) # create a set without duplicates
print (bask - rm, 'tuples end \n\n')

# zip function
"""knights = {'gallahad': 'the pure', 'robin': 'the brave'} 
for k, v in knghts.iteritems(): # iteritem perneis mazi t key kai t value
    print k, v knights.iteritems(): 
   """ 
questions = ['name', 'quest', 'favorite color']
answers = ['lancelot', 'the holy grail', 'blue'] 

for q, a in zip(questions, answers): 
    print ('What is your {0}? It is {1}.'.format(q, a)) 


# sorted(strs, key= len(), reverse=True)

