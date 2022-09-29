class Car:
    def __init__(self, in_color, in_model):
        self.color = in_color
        self.model = in_model
    def __str__(self):#__str__() method represents the class objects as string. It makes easier to print the members of a class
        return self.color+" "+self.model

car1 = Car("red","Miata")#First car red Miata: object created car1
car2 = Car("blue","Pinto")#Second car blue Pinto: object created car2
car3 = Car("yellow","Tundra")#Third car yellow Tundra: object created car3

cars = [car1,car2,car3]#cars list to store all the previous objects
for i in cars:#printing the objects
    print(i)#when you print(i), i, an object, calls __str__() method and it returns a string with color and its model.
