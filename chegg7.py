#1. Default Parameters:

def function1(a=1,b=2,c=3):
    print(a+b+c)
function1()
#prints 6 if only function() is called.

#2. Keyword parameters:

def function2(a,b=2,c=3):
    print(a+b+c)
function2(b=3,c=2,a=1)
# Using the keyword of parameters to pass, so we don't need to maintain order of the parameters
# function(b=3,c=2,a=1) prints 6.

#3. Postional Parameters:

def function3(a,b,c):
    print(a+b+c)
function3(1,2,3)
# All parameters are passed as positional arguments.
# So when function(1,2,3) is called, 1 is assigned to a, 2 is assigned to b and 3 is assigned to c

#4. Variable Length parameters:

# This can be of two types:
# a. arbitrary positional arguments
# b. arbitrary keyword arguments

# a. arbitrary positional arguments:
def function4(*a):
    ans=0
    for i in a:
        ans += i
    return ans
print(function4(1,2,3,4,5,6))
# for this an asterisk(*) is placed before parameter. This can hold non-keyword variable length arguments.
# The arguments are wrapped in tuple.
#Outputs: 21

# b. arbitrary keyword arguments:
def function5(**a):
    for i in a.items():
        print(i)
function5(a=1,b="register",c=5.99)

# For this we need to place double asterisk before the argument. This can hold keyword variable-length arguments.
# Outputs:
#('a',1)
#('b','register')
#('c',5.99)
