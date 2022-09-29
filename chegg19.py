import test

def gcd(m, n):
    while m % n != 0:
        oldm = m
        oldn = n

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

    def __mul__ (self, f):
    # Add the method for *
        common = computeGCD(self.num*f.num,self.den*f.den)#Compute gcd for the numerator and denominator
        #Here self is the first fraction and f is the second fraction self = (a/b) and f = (c/d)
        ans = Fraction(self.num*f.num//common,self.den*f.den//common)#(a/b)*(c/d) = (a*c)/(b*d)
        return ans
# Example test case
f1 = Fraction(6,5)
f2 = Fraction(5,14)
f3 = f1 * f2#f1*f2 = (6/5)*(5*14) = (30/70) = ((30/10)/(70/10)) = (3/7)
print(f3)
test.testEqual(f3.__str__(), Fraction(3, 7).__str__())
