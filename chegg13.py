def combine_files(f1,f2,f3):#Combines the f1 and f2 into f3

    #Opening 1.txt and 2.txt as read and 3.txt as write
    with open(f1,'r') as file1, open(f2,'r') as file2, open(f3,'w') as file3:
        #For simultaneously reading file1 and file2
        for x,y in zip(file1,file2):
            file3.write(x.strip()+" ")#Writing the path first into 3.txt
            print(y)
            #To remove the duplicates we store each objects in a dictionary with key as objects and None as value
            #Then we access the keys using fromkeys() and store it in a list
            arr = list(dict.fromkeys(y.replace(',','').split()))
            print(arr)
            for i in range(len(arr)):#we then write each object into file 3 with comma and space
                if i==len(arr)-1:#To write the last obj, we dont need comma and space
                    file3.write(arr[i])
                else:
                    file3.write(arr[i]+", ")#Write the objects into file3
            file3.write("\n")#Writing newline
            #CLosing the files
    file1.close()
    file2.close()
    file3.close()
    
combine_files("1.txt","2.txt","3.txt")
