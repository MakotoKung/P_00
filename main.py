class rectangle:
    def __init__ (self,w=0, h=0):
        self.w = w
        self.h = h 
    def area(self):
        return self.w * self.h
    
    def __str__(self):
        return "w:%s, h:%s , area:%s"%(self.w, self.h, self.area())

y = rectangle(5,7)
print(y)