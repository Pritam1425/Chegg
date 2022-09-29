conc_file = open('conc_H.csv',mode='r')
time = []
conc = []
for i,line in conc_file.readlines():
    if line:
        tmp = line.split(",")
        time.append(tmp[0])
        conc.append(tmp[1])

print(conc)
