import numpy as np

def peak_time(zeta,r,p):
    g = 9.81
    H = np.sqrt(3.07*g/r-zeta**2.2)
    return 2*p*np.pi/H
print(peak_time(0.5,0.1,5))

def peak_numb(a,zeta,r,p):
    return a*np.exp(-1*zeta*peak_time(zeta,r,p))
print(peak_numb(0.35,0.5,0.1,3))

def swing_time(a,zeta,r,yn):
    p=0
    while True:
        if peak_numb(a,zeta,r,p)<yn/2:
            return peak_time(zeta,r,p)
        p+=1
print(swing_time(0.7,0.4,0.25,0.01))
