try:
    print (int('aasadd')) # xtipaei 
except:
    print ('error')
finally: # tha ektelesti outos i allos
    print ('finally')
    
print ('\n')
#Regular Expresion
import re
s = 'purple alice-b@google.com monkey dishwasher'
emails = re.findall(r'[\w\.-]+@[\w\.-]+', s) #findall girnaei ta substrings pou teriazoun
print (emails)

s = 'purple alice-b@google.com monkey dishwasher'
emails = re.match(r'[\w\.-]+@[\w\.-]+', s) #cheackarei olo to string an einai match ap tin arxi
print (emails) #girnaei null giati to exei k purple monkey

s = 'alice-b@google.com sdfg'
emails = re.search(r'[\w\.-]+@[\w\.-]+', s) #cheackarei olo to string
print (emails)

print ('\n')
#Requests
"""import requests
r = requests.get('http://www.google.gr', proxies={"http": "http://173.194.65.94:8080"})
print (r.text)"""


# Open a file 
fo = open("foo.txt", "r+") 
str = fo.read(10)
# Close opened file 
fo.close()
"""
fo = open("foo.txt", "wb")
fo.write(“Nokia is a great company!\nYeah its great!!\n"); 
fo.close()
"""

contents = """
    <Companies>
    <Company name="Nokia" emplyees="700">NSN</Company>
    </Companies>
"""
from xml.etree.cElementTree import parse
import io
stream= io.StringIO(contents)

tree = parse(stream)
#Get root element from the xml file
element = tree.getroot()

nodes = element.findall("Company")
for node in nodes:
    print (node.attrib.get('name'))
    print (node.text)
    print (element.find("Company").text)


#
print ('\n')
import os
print (os.getcwd())
#print (os.system("ping 173.194.65.103"))

import subprocess
print (subprocess.getstatusoutput("ping 173.194.65.103")) 





