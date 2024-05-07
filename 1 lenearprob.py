import array as hashTable
size=7
hashTable = hashTable.array('i',[-1]*size)

def initial():
    print(hashTable) 

def insertHash(value): 
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
        if(count==size):
            print("Hash Table Is Full Hence ",value," Can not Be Inserted")
            print(hashTable)
        else: 
            i=key
            for i in range(key, size):
                key1=(i+1)%size  
                if(hashTable[key1] == -1): 
                    hashTable[key1] = value
                    print(value,"inserted at arr",key1)
                    break
        
        

def search(value): 
    key = value % size
    if(hashTable[key]==value):
        print(value, "Found at", key,"th Index location")
    else:
        print(value, "Not Found at", key,"th Index location")
        
def delHash(value):
    key = value % size
    if(hashTable[key]==value):
        print(value, "Sussfully deleted from hash table")
        hashTable[key]=-1
    else:
        print(value, "Not Found at", key,"th Index location") 

initial()             
insertHash(7) 
insertHash(10)
insertHash(40)
insertHash(14)
insertHash(21)
insertHash(28)
insertHash(32)
insertHash(5)

print(hashTable) 

search(13)
search(25)

delHash(13) 
for i in range(0,7):
    print("Index[",i,"]=", hashTable[i]) 











# ALGORITHM:
# Function linear_probe(key, value):
# i = key
# for i in range(key, size):
# key1 = (i + 1) % size # Calculating next empty location address using linear probing formula
# if hashTable[key1] == -1: # If location is empty, insert data
# hashTable[key1] = value
# print(value, &quot;inserted at arr&quot;, key1)
# break

# Function quadratic_probe(key, value):
# for i in range(key, size):
# key1 = (key + i*i) % size # Quadratic Probing formula
# if hashTable[key1] == -1:
# hashTable[key1] = value
# print(value, &quot;inserted at arr&quot;, key1)
# break

# Main Function :
# size = 7
# hashTable = array(&#39;i&#39;, [-1] * size)

# # Example usage of linear probing
# key = &lt;some_key&gt;
# value = &lt;some_value&gt;
# linear_probe(key, value)

# # Example usage of quadratic probing
# key = &lt;some_key&gt;
# value = &lt;some_value&gt;
# quadratic_probe(key, value)
