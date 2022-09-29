def combine_lists(names,ages):
    return dict(zip(names,ages))
NAMES = ['Alice','Bob','Cathy','Dan','Ed','Frank','Gary','Helen','Irene','Jack','Kelly','Larry']
AGES = [20,21,18,18,19,20,20,19,19,19,22,19]
d = combine_lists(NAMES,AGES)
print(d)
