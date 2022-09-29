import random

def which_hand(cards):
    a,b,c = cards#a = 1st hand, b = 2nd hand, c = 3rd hand
    
    if a[1]==b[1] and b[1] == c[1]:#flush checking condition
        lst = sorted([ord(a[0]),ord(b[0]),ord(c[0])])
        if lst[0] == lst[1]-1 and lst[1] == lst[2]-1:#straight flush
            return 'straight-flush'
        else:#flush
            return 'flush'
    elif a[0]==b[0] and a[0]==c[0]:#if three of the cards have same rank
        return 'three-of-a-kind'
    elif a[0]==b[0] or a[0]==c[0] or b[0]==c[0]:#if any two of the card have same rank
        return 'pair'
    else:
        return 'other'

counts = {'other':0,'flush':0,'three-of-a-kind':0,'straight-flush':0,'pair':0}
trials = 80000
cards = [r+s for r in '123456789' for s in 'SCDH']

for _ in range(trials):
    random.shuffle(cards)
    result = which_hand(cards[:3])
    counts[result]+=1

for k in counts:
    counts[k]/=trials/100
expected = {'other':70.4,'flush':4.4,'three-of-a-kind':0.5,'straight-flush':0.4,'pair':24.3}
for k in sorted(expected.keys()):
    print(f'{(k.capitalize()+":"):17s} {counts[k]:4.1f}%     Expected: {expected[k]:4.1f}%')
