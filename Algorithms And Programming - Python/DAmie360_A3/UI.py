from MyPoint import *
index=-2
from Tests import *
from MyPoint_Repository import *
from matplotlib.colors import is_color_like
p1=MyPoint(1.0,1.0,"red")
add_to_list(p1,my_list)
p1=MyPoint(-1.0,4.0,"pink")
add_to_list(p1,my_list)
p1=MyPoint(2.0,2.0,"red")
add_to_list(p1,my_list)
p1=MyPoint(3.0,3.0,"green")
add_to_list(p1,my_list)
p1=MyPoint(7.0,8.0,"purple")
add_to_list(p1,my_list)
def menu():
    print("1.Add a point")
    print("2.Print all points")
    print("3.Print a certain point")
    print("4.Get all points of a given color")
    print("5.Get all points inside a given square")
    print("6.Get the min distance between 2 points")
    print("7.Update a point at a given index")
    print("8.Delete a point by index")
    print("9.Delete all points inside a given square")
    print("10.Plot all points in a chart")
    print("11.Get all points inside a given circle")
    print("14.Get the number of points of a given color")
    print("17.Shift all points on the Y axis")
    print("20.Delete all points within a given distance of the point")
    print("21.Show menu")
    print("-1.Stop")   
menu()
test_all()
while(index!=-1):
    print("Index:")
    try:
        index=int(input())
        if(index==1):
            print("X coordinate:")
            try:
                x=float(input())
                print("Y coordinate:")
                y=float(input())
                print("Color:")
                color=str(input())
                if(is_color_like(color)==1):
                    p1=MyPoint(x,y,color)
                    add_to_list(p1,my_list)
                else:
                    print("Invalid color!")
            except ValueError as ex:
                print(ex)
        if(index==2):
            print_all_points(my_list)
        if(index==3):
            print("Index:")
            list_index=int(input())
            print(my_list[list_index])
        if(index==4):
            print("Color:")
            color=input()
            if(is_color_like(color)==1):
                for i in range (len(my_list)):
                    if(my_list[i].get_color()==color):
                        print(my_list[i])
            else:
                print("Invalid color!")
        if(index==5):
            print("Index X of upper-left corner:")
            try:
                left_corner_up_X=float(input())
                print("Index Y of upper-left corner:")
                left_corner_up_Y=float(input())
                print("Lenght:")
                length=int(input())
                square(left_corner_up_X,left_corner_up_Y,length,my_list)
            except ValueError as ex:
                print(ex)
        if(index==6):
            print("Minimum lenght:",minimum_lenght(my_list)) #work on indexes
        if(index==7):
            try:
                print("Index:")
                list_index=int(input())
                if(list_index<0 or list_index>len(my_list)):
                    print("Index out of range")
                else:
                    print("New X:")
                    x2=float(input())
                    print("New Y:")
                    y2=float(input())
                    print("New color:")
                    color2=input()
                    if(is_color_like(color2)==1):
                        replace_coords(list_index,x2,y2,color2,my_list)
                    else:
                        print("Invalid color!")
            except ValueError as ex:
                print(ex)
        if(index==8):
            try:
                print("Index:")
                list_index=int(input())
                if(list_index<0 or list_index>len(my_list)):
                    print("Index out of range")
                else:
                    deletion(list_index,my_list)
            except ValueError as ex:
                print(ex)
        if(index==9):
            try:
                print("Index X of upper-left corner:")
                left_corner_up_X=float(input())
                print("Index Y of upper-left corner:")
                left_corner_up_Y=float(input())
                print("Lenght:")
                length=float(input())
                square2(left_corner_up_X,left_corner_up_Y,length,my_list)
            except ValueError as ex:
                print(ex)
        if(index==10):
            if(len(my_list)>0):
                chart(my_list)
            else:
                print("No elements in list")
        if(index==11):
            try:
                print("X center:")
                x=float(input())
                print("Y center:")  
                y=float(input())
                print("Radius:")
                radius=float(input())
                print(distance_circle(x,y,radius,my_list))
            except ValueError as ex:
                print(ex)
        if(index==14):
            print("Color:")
            color=str(input())
            if(is_color_like(color)==1):
                print(get_color_index(color,my_list))
            else:
                print("Invalid color!")
        if(index==17):
            print("Value:")
            try:
                value=int(input())
                shift(value,my_list)
            except ValueError as ex:
                print(ex)
        if(index==20):
            try:
                print("X point:")
                x=int(input())
                print("Y point:")
                y=int(input())
                print("Distance:")
                lenght=int(input())
                remove_distance(x,y,lenght,my_list)
            except ValueError as ex:
                print(ex)
        if(index==21):
            menu()
    except ValueError as ex:
        print(ex)