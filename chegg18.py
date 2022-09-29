import test

def gcd(m, n):
    while m % n != 0:
        oldm = m
        oldn = n
        print(oldm,oldn)
    m = oldn
    n = oldm % oldn
    return n
def computeGCD(x, y):#New gcd program as the earlier was not working
  
   while(y):
       x, y = y, x % y
  
   return x

class Fraction:

    def __init__(self, top, bottom):

        self.num = top # the numerator is on top
        self.den = bottom # the denominator is on the bottom

    def __str__(self):
        return str(self.num) + "/" + str(self.den)

    def simplify(self):
        common = gcd(self.num, self.den)

        self.num = self.num // common
        self.den = self.den // common

    def __add__(self,otherfraction):

        newnum = self.num*otherfraction.den + self.den*otherfraction.num
        newden = self.den * otherfraction.den

        f = Fraction(newnum, newden)
        f.simplify()
        return( f )

    def __truediv__ (x,y):
        temp = computeGCD(x.num*y.den,x.den*y.num)
        print(temp)
        ans = Fraction(x.num*y.den//temp,x.den*y.num//temp)
        
        return ans
    '''
    Implementation for / operator
    '''

# Make test cases here
obj1 = Fraction(2,3)
obj2 = Fraction(4,9)
obj3 = obj1/obj2
print(obj3)
