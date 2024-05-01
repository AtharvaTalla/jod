import array as hashTable
#Create an empty array of size 7 and Initialize all index to -1
size=7
hashTable = hashTable.array('l',[-1]*size)

def initial():
    display() # Print empty hash table.
    
def display():
    for i in range(0,7):
        print("Index[",i,"]=", hashTable[i]) # Print hash table along with data.

def insertHash(value): #this function is used to insert values into hash table
    key = value % size 
    if(hashTable[key] == -1):
        hashTable[key] = value 
        print(value,"inserted at arr",key)
    else:
        print("Collision : arr",key,"has element",hashTable[key],"already!")
        i=0
        count=0
        while(i<7):
            if(hashTable[i]!=-1):
                count+=1
            i+=1
        if(count==7):#checking for the hash full
            print("Hash Table Is Full Hence ",value," Can not Be Inserted")
            display()
        else:
            
            for i in range(0, 7):
                key1=(key+i*i)%size  #Quadratic Probing formula
                if(hashTable[key1] == -1):
                    hashTable[key1] = value
                    print(value,"inserted at arr",key1)
                    break
        
def search(value): #this function is used to search value into hash table
    key = value % size
    if(hashTable[key]==value):
        print(value, "Found at", key,"th Index location")
    else:
        print(value, "Not Found at", key,"th Index location")
        
def delHash(value): #this function is used to delete value from hash table if present
    key = value % size
    if(hashTable[key]==value):
        print(value, "Sussfully deleted from hash table")
        hashTable[key]=-1
    else:
        print(value, "Not Found at", key,"th Index location")     

initial() #Actual code starting to execute from this line.            

#Code to read multiple numbers as per user want
#try for this data set 50, 700, 76, 85, 92, 73, 101
option=1
while(option==1):
    num=int(input("Enter Telephine number to insert into Hash table"))
    insertHash(num)
    display() # Print hash table along with data.
    option=int(input("Enter 0 to Exit and 1 to read more Telephine number=>"))
    
num=int(input("Enter Telephine number to search in Hash table"))
search(num) #searching operation in hash table

num=int(input("Enter Telephine number to deleted from Hash table"))
delHash(num) #delete operation in hash table

for i in range(0,7):
    print("Index[",i,"]=", hashTable[i]) # Print hash table along with data.