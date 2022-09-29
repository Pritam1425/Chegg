def egcd(a, b):
   if b == 0:
       return (1, 0)
   else:
       # Calculate q
       q = a // b
       # Calculate r
       r = a % b
       # Calculate (s, t) by calling egcd(b, r)
       (s,t) = egcd(b, r)
       return (t, s-q*t)

# Problem 2: Multiplicative Inverse
def multinv(a, n):
    g = egcd(a, n)
    return g[0] % n

# Problem 3: Decrypt a Single Value

def decrypt(c, m, k):
    ainv = multinv(m,256)
    #first calculate the a inverse of 256
    #then multiply with each (cipher value-k). then take mod 256
    ans = ''.join([chr((ainv*(c[i]-k))%256) for i in range(0,len(c))])
    return ans
#If it helps, the previous assignment had us create cipher functions:

# Shift cipher

# Shift a single plaintext byte by k (mod 256)
def shift(b, k):
   return (ord(b) + k) % 256
  
# Shift a whole byte string by k, returning an array of numbers
def shiftstring(plaintext, k):
   return [ shift(p, k) for p in plaintext ]
  
# Shift a whole byte string by k, returning a byte string
def shiftcipher(plaintext, k):
   return bytes( shiftstring(plaintext, k) )
  
### Write the three functions to implement the linear cipher below

def linear(b, m, k):
    return (ord(b) * m + k) % 256
  
def linearstring(plaintext, m, k):
    return [linear(p, m, k) for p in plaintext]
  
def linearcipher(plaintext, m, k):
    return bytes(linearstring(plaintext,m,k))
cipher = linearcipher("hello",17,3)
plain = decrypt(cipher,17,3)
print(cipher)
print(plain)
