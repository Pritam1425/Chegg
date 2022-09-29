def mergeDictionaries(d1):
    ans1 = {}#Merged dictionary
    ans2 = {}#Exception dictionary
    for i in d1:#Loop to iterate through all the dictionaries in the list d1
        for j in i:#loop to iterate through all the keys of dictionary i
            if ans2.get(j) is not None:#if ans2 has values with key j, we append the new value
                ans2[j].append(i[j])
            elif ans1.get(j) is None:#if ans1 does not contain value with key j, we include it is ans1
                ans1[j] = i[j]
            elif ans1.get(j) is not None:#If ans1 already has value with key j,we remove from ans1 and store in ans2. also the current key value
                lst = []
                if ans2.get(j) is not None:
                    lst = ans2[j]
                lst.append(i[j])
                lst.append(ans1[j])
                ans2[j]=lst
                ans1.pop(j)
    for i in ans2:#sorting the list inside ans2
        ans2[i] = sorted(ans2[i])
    return (ans1,ans2)
            
