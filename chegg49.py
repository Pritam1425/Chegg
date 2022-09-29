class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    def setPoint(self, x, y):
        self.x = x
        self.y = y
    def getPoint(self):
        return self.x, self.y
class Line:
    def __init__(self):
        self.slope = 0
        self.offset = 0
    # Write this method
    def line_from_origin(self, p):
        x,y = p.getPoint()#get points (x,y)
        self.offset = 0 #for line from origin offset is 0
        self.slope = y/x #slope is ((y-0)/(x-0)) = (y/x)

    # Write this method
    def line_from_points(self, p1, p2):
        x1,y1 = p1.getPoint()
        x2,y2 = p2.getPoint()
        self.slope = (y2-y1)/(x2-x1) #slope is m = (y2-y1)/(x2-x1)
        self.offset = y1-self.slope*x1 # as y = mx+c and (x1,y1) is a point in line
        #solving this we get, y1 = m*x1+c, c = y1-m*x1
    def getSlope(self):
        return self.slope

    def getOffset(self):
        return self.offset
#testing
p1 = Point(2,2)
p2 = Point(3,4)
l1 = Line()
l1.line_from_origin(p1)
l2 = Line()
l2.line_from_points(p1,p2)
s1 = l1.getSlope()
o1 = l1.getOffset()
s2 = l2.getSlope()
o2 = l2.getOffset()
print("First line: \nslope: "+str(s1)+"\noffset:"+str(o1))
print("Second line: \nslope: "+str(s2)+"\noffset:"+str(o2))
