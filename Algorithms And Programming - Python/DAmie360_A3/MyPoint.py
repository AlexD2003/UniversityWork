class MyPoint:
    pass
    def __init__(self,coord_x,coord_y,color):
        self.coord_x=coord_x
        self.coord_y=coord_y
        self.color=color
    def get_x(self):
        return self.coord_x
    def get_y(self):
        return self.coord_y
    def get_color(self):
        return self.color
    def set_x(self,x):
        self.coord_x=x
    def set_y(self,y):
        self.coord_y=y
    def set_color(self,color):
        self.color=color
    def __str__(self):
        #return f"{self.coord_x},{self.coord_y},{self.color}"
        return "Point("+str(self.coord_x)+","+str(self.coord_y)+") of color: "+self.color