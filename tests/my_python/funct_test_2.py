def sumaryd(x):
    return 'einai' , x+x

y = sumaryd(5)
print ("sinolo:", y)


#function oristma se function
def greet(name):
    return "hello " + name

def call_func(func):
    other_name ="kostas"
    return func(other_name)

print (call_func(greet))


#keyword arguments panta sto telos
def parrot(voltage, state='a stiff'\
"""to keyword argument state prepei na exei default state!""",\
action='voom', type='Norwegian blue'):
    print ("action: ", action)
    print ("voltage: ", voltage)
    
parrot(1000)
parrot(action='Vooom', voltage=10)

#ektos apo keywords argument uparxoun kai ta argument
def print_everything(*args):
    print (args)
    for count, thing in enumerate(args):
        print ('{0}. {1}'.format(count, thing))
        
print_everything('ela', 'katse', 'siko', 'fige')




#keywords args
def print_everything2(**kwargs):
    for name, value in kwargs.items(): #dictionaries
        print ('{0}= {1}'.format(name, value))
        
print_everything2(sira1='ela', sira2='katse', sira3='siko', sira4='fige')



#mlkies
def mlkies(*args, **kwargs):
    print (args)
    print (kwargs)

mlkies(10, 30, 'kostas', type='xriso', yfi='bamvakero')




#Lambda= anonymous functions
def make_incrementor (n):
    return lambda x: x + n 
    #den mporei na gine to x print giati einai esoteriko
    
f = make_incrementor(42)
print (f(0))
print (f(3))



#

