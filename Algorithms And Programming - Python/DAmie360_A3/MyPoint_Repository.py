from MyPoint import *
from math import sqrt
from math import pow
import matplotlib.pyplot as plt
my_list=[]
my_final_list=[]


def add_point(x,y,color,p1):
    """
    <This function adds a point to the repo of given coordinates>
    x -  x coordinate
    y -  y coordinate
    color-  color
    """
    p1.set_x(x)
    p1.set_y(y)
    p1.set_color(color)
    
def add_to_list(p1,my_list):
    """
    <This function adds to the list a point>
    p1 - the point
    """
    my_list.append(p1)
    
def print_all_points(my_list):
    """
    <This function prints all the points>
    my_list - the list
    """
    i=0
    for i in range(len(my_list)):
        print(my_list[i])
def square(left_corner_up_X,left_corner_up_Y,length,my_list):
    """
    <This function gets all the points inside a given square>
    left_corner_up_X - x coord of square
    left_corner_up_Y - y coord of square
    lenght - lenght of square
    my_list - the list
    """
    right_corner_up_X=left_corner_up_X+length
    right_corner_up_Y=left_corner_up_Y
    left_corner_down_X=left_corner_up_X
    left_corner_down_Y=left_corner_up_Y-length
    right_corner_down_X=right_corner_up_X
    right_corner_down_Y=right_corner_up_Y-length
    i=0
    absolute_x_min=min(right_corner_up_X,left_corner_down_X,right_corner_down_X,left_corner_up_X)
    absolute_x_max=max(right_corner_up_X,left_corner_down_X,right_corner_down_X,left_corner_up_X)
    absolute_y_min=min(left_corner_up_Y,right_corner_up_Y,left_corner_down_Y,right_corner_down_Y)
    absolute_y_max=max(left_corner_up_Y,right_corner_up_Y,left_corner_down_Y,right_corner_down_Y)
    for i in range(len(my_list)):
        x=my_list[i].get_x()
        y=my_list[i].get_y()
        if(x>=absolute_x_min and x<=absolute_x_max and y>=absolute_y_min and y<=absolute_y_max):
            print(my_list[i])
            return 1
def min_lenght(x,y,x2,y2):
    """
    <calculates the minimum lenght between 2 points>
    """
    lenght=sqrt(pow((x2-x),2)+pow((y2-y),2))
    lenght=round(lenght,2)
    return lenght
def replace_coords(list_index,x2,y2,color2,my_list):
    """
    <replaces the coordinates at a given index>
    x2 - new x
    y2 - new y
    color2 - new color
    my_list - the list
    """
    my_list[list_index].set_x(x2)
    my_list[list_index].set_y(y2)
    my_list[list_index].set_color(color2)
    return(my_list[list_index])
def deletion(list_index,my_list):
    """
    <deletes a point at a given index>
    list_index - the index
    my_list - the list
    """
    del(my_list[list_index])
def square2(left_corner_up_X,left_corner_up_Y,length,my_list):
    """
    <This function deletes all the points inside a given square>
    left_corner_up_X - x coord of square
    left_corner_up_Y - y coord of square
    lenght - lenght of square
    my_list - the list
    """
    right_corner_up_X=left_corner_up_X+length
    right_corner_up_Y=left_corner_up_Y
    left_corner_down_X=left_corner_up_X
    left_corner_down_Y=left_corner_up_Y-length
    right_corner_down_X=right_corner_up_X
    right_corner_down_Y=right_corner_up_Y-length
    i=0
    absolute_x_min=min(right_corner_up_X,left_corner_down_X,right_corner_down_X,left_corner_up_X)
    absolute_x_max=max(right_corner_up_X,left_corner_down_X,right_corner_down_X,left_corner_up_X)
    absolute_y_min=min(left_corner_up_Y,right_corner_up_Y,left_corner_down_Y,right_corner_down_Y)
    absolute_y_max=max(left_corner_up_Y,right_corner_up_Y,left_corner_down_Y,right_corner_down_Y)
    i=0
    lenght_list=len(my_list)
    while(i<lenght_list):
        x=my_list[i].get_x()
        y=my_list[i].get_y()
        if(x>=absolute_x_min and x<=absolute_x_max and y>=absolute_y_min and y<=absolute_y_max):
            del(my_list[i])
            lenght_list-=1
        i+=1
def chart(my_list):
    """
    <This function charts all the coordinates in the list>
    my_list - the list
    """
    i=0
    x_list=[]
    y_list=[]
    color_list=[]
    for i in range(len(my_list)):
        x_list.append(float(my_list[i].get_x()))
        y_list.append(float(my_list[i].get_y()))
        color_list.append(my_list[i].get_color())
    plt.scatter(x_list,y_list,c=color_list)
    plt.show()
def distance_circle(x,y,radius,my_list):
    """
    <This function calculates all the points within a given circle>
    x - x of circle
    y - y of circle
    radius - radius of circle
    my_list - the list
    """
    i=0
    for i in range(len(my_list)):
        x2=my_list[i].get_x()
        y2=my_list[i].get_y()
        if(min_lenght(x,y,x2,y2)<=radius):
            return(my_list[i])
def get_color_index(color,my_list):
    """
    <this function returns how many points of a given color are there in the list>
    color - given color
    my_list - the list
    """
    i=0
    sum=0
    for i in range(len(my_list)):
        if(my_list[i].get_color()==color):
            sum+=1
    return sum
def remove_distance(x,y,lenght,my_list):
    """
    <this function removes all the points within a given distance of a point>
    x - x point
    y - y point
    lenght - lenght
    my_list - the list
    """
    i=0
    for i in range(len(my_list)-1):
        x2=my_list[i].get_x()
        y2=my_list[i].get_y()
        distance=min_lenght(x,y,x2,y2)
        if(distance<lenght):
            del(my_list[i])
def minimum_lenght(my_list):
    """
    <this function returns the minimum lenght between the points>
    my_list - the list
    """
    i=0
    array=[]
    for i in range(len(my_list)-2):
        j=i+1
        while(j<=len(my_list)-1):
            array.append(min_lenght(my_list[i].get_x(),my_list[i].get_y(),my_list[j].get_x(),my_list[j].get_y()))
            j+=1
    array.sort()
    return array[0]
def shift(value,my_list):
    """
    <this function shifts all the points on the X axis by a value>
    value - the value
    my_list - the list
    """
    i=0;
    for i in range(len(my_list)):
        oldx=my_list[i].get_x()
        my_list[i].set_x(oldx+value)