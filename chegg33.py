class Vehicle:
    def __init__(self):
        self.x = 0
        self.y = 0
    def moveUp(self):
        self.y+=1
    def moveDown(self):
        self.y-=1
    def moveRight(self):
        self.x+=1
    def moveLeft(self):
        self.x-=1
    def __str__(self):
        return '('+str(self.x)+' , '+str(self.y)+')'
#write your code here
class Vehicle2010(Vehicle):#inherited classes are defined as class inheritedClass(parentClass):
    
    def __init__(self):#init for the inherited class. As there are no changes in init, you could remove this also
        Vehicle.__init__(self)
        
    def equals(self,obj):#equals function to check if the object calling this function is equal to obj
        if (self.x==obj.x) and (self.y==obj.y):#If they have same x and y, return True
            return True
        return False
    def moveUpperRight(self):#upper right (x+1,y+1)
        self.x+=1
        self.y+=1
    def moveUpperLeft(self):#upper left (x-1,y+1)
        self.x-=1
        self.y+=1
    def moveLowerRight(self):#lower right (x+1,y-1)
        self.x+=1
        self.y-=1
    def moveLowerLeft(self):#lower left (x-1,y-1)
        self.x-=1
        self.y-=1

#testing
print('Part 1')
print('------')
car = Vehicle()
print(car)
car.moveUp()
print(car)
car.moveLeft()
print(car)
car.moveDown()
print(car)
car.moveRight()
print(car)
print('------')
print('Part 2')
print('------')
car1 = Vehicle2010()
print(car1)
car1.moveLowerLeft()
print(car1)
car2 = Vehicle2010()
car2.moveLeft()
print(car1.equals(car2))
car2.moveDown()
print(car1.equals(car2))
