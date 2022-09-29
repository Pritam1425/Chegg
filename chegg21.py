def readMatrix(inputfilename):
# Open the file
    f = open(inputfilename, 'r')

    # Read the number of vertices from the first line of the file
    n = int(f.readline().strip())

    #reading all the elements of matrix as a string paragraph
    rest=f.read().strip().strip()
    adjMat=[] #initialization
    adjrow=[]
    n=rest.split("\n") #dividing the paragraph by line.
    a=[]
    for i in n:
    a.append(i.split(" ")) # spliting the line to get each term and append to a
    # matrix a has the ajacency matrix in string form

    for i in a:
    adjrow=[]
    for j in i:
    if j=="100":
    adjrow.append("INF") #appending each element to a separate sublist
    else:
    adjrow.append(int(j))
    adjMat.append(adjrow) #adding the sublist to the main list thus creating rows of matrix

    return adjMat #return

