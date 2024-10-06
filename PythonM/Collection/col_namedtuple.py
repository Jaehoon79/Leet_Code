#ref url : https://www.geeksforgeeks.org/namedtuple-in-python/

from collections import namedtuple

def main():
    StudentType = namedtuple('Student', ['name', 'age', 'DOB'])
    s = StudentType('Jaehoon Kim', '45', '19790228')

    myList = ['Eunjeong Kim', '43', '19811027']
    print(s)
    
    s = StudentType._make(myList)
    print(s)
    print(s._asdict())
    
    myDict = {'name':'Taeyoung', 'age':'11', 'DOB':'20130308'}
    print(StudentType(**myDict))
    
    #_fields(): get all keynames of the namespace declared.
    print(f"Get all keynames: {s._fields}")
    
    #_replace(): 
    replaced_S = s._replace(name="Dauen kim")
    print(s)
    print(replaced_S)
    
if __name__ == "__main__":
    main()