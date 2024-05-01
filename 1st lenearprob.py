import array as hashTable
#Create an empty array of size 7 and Initialize all index to -1
size=7
hashTable = hashTable.array('i',[-1]*size)

def initial():
    print(hashTable) # Print empty hash table.

def insertHash(value): #this function is used to insert values into hash table
    key = value % size
    if(hashTable[key] == -1):
        hashTable[key] = value
        print(value,"inserted at arr",key)
    else:
        print("Collision : arr",key,"has element",hashTable[key],"already!")
        print("Unable to insert", value, "into hash table")
        i=0
        count=0
        while(i<size):
            if(hashTable[i]!=-1):
                count+=1
            i+=1
        if(count==size):#checking for the hash full
            print("Hash Table Is Full Hence ",value," Can not Be Inserted")
            print(hashTable)
        else:  #logic of linear probiing
            i=key
            for i in range(key, size):
                key1=(i+1)%size  #calculating next empty location address using linear probing formula
                if(hashTable[key1] == -1): #if location is empty insert data 
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
insertHash(7) 
insertHash(10)
insertHash(40)
insertHash(14)
insertHash(21)
insertHash(28)
insertHash(32)
insertHash(5)

print(hashTable) # Print hash table along with data.

search(13) #searching operation in hash table
search(25)

delHash(13) #delete operation in hash table
for i in range(0,7):
    print("Index[",i,"]=", hashTable[i]) # Print hash table along with data.