from MyPoint_Repository import *
from MyPoint import *


def test_add_point():
    list_test=[]
    point_test=MyPoint(1,1,"red")
    add_point(4.0,4.0,"pink",point_test)
    add_to_list(point_test,list_test)
    assert(list_test[0].color=="pink")
    assert(float(list_test[0].coord_x==4.0))
    assert(float(list_test[0].coord_y==4.0))
    list_test=[]
def test_print_all_points():
    list_test=[]
    p1=MyPoint(1,1,"red")
    p2=MyPoint(2,2,"red")
    p3=MyPoint(3,3,"red")
    add_to_list(p1,list_test)
    add_to_list(p2,list_test)
    add_to_list(p3,list_test)
    list_test=[]
def test_square():
    list_test=[]
    p1=MyPoint(2,-1,"red")
    add_to_list(p1,list_test)
    p2=MyPoint(2,-1,"red")
    add_to_list(p2,list_test)
    p3=MyPoint(2,-1,"red")
    add_to_list(p3,list_test)
    assert(square(0,0,4,list_test)==1)
    assert(square(1,1,4,list_test)==1)
    list_test=[]
def test_replace_coords():
    list_test=[]
    p1=MyPoint(1.0,1.0,"red")
    list_test.append(p1)
    replace_coords(0,4.0,4.0,"pink",list_test)
    assert(list_test[0].get_x()==4.0)
    assert(list_test[0].get_y()==4.0)
    assert(list_test[0].get_color()=="pink")
    list_test=[]
def test_deletion():
    list_test=[]
    p1=MyPoint(1,1,"red")
    list_test.append(p1)
    p2=MyPoint(5,5,"pink")
    list_test.append(p2)
    deletion(1,list_test)
    deletion(0,list_test)
    assert(list_test==[])
    list_test=[]
def test_square_2():
    list_test=[]
    p1=MyPoint(1,1,"red")
    list_test.append(p1)
    p2=MyPoint(5,5,"pink")
    list_test.append(p2)
    square2(1,1,10,list_test)
    assert(list_test[0].get_x()==5)
    list_test=[]
def test_circle():
    list_test=[]
    p1=MyPoint(1,1,"red")
    list_test.append(p1)
    assert(distance_circle(0,0,5,list_test).get_x()==1)
    assert(distance_circle(0,0,5,list_test).get_y()==1)
    list_test=[]
def test_color():
    list_test=[]
    p1=MyPoint(1,1,"red")
    list_test.append(p1)
    p2=MyPoint(1,1,"red")
    list_test.append(p2)
    p3=MyPoint(1,1,"red")
    list_test.append(p3)
    assert(get_color_index("red",list_test)==3)
    p1=MyPoint(1,1,"pink")
    list_test.append(p1)
    p2=MyPoint(1,1,"pink")
    list_test.append(p2)
    p3=MyPoint(1,1,"red")
    list_test.append(p3)
    assert(get_color_index("pink",list_test)==2)
    list_test=[]
def test_minimum_length():
    list_test=[]
    p1=MyPoint(1,1,"red")
    list_test.append(p1)
    p2=MyPoint(2,2,"red")
    list_test.append(p2)
    p3=MyPoint(3,3,"red")
    list_test.append(p3)
    assert(minimum_lenght(list_test)==1.41)
    list_test=[]
def test_shift():
    list_test=[]
    p1=MyPoint(1,1,"red")
    list_test.append(p1)
    shift(2,list_test)
    assert(list_test[0].get_x()==3)
    p1=MyPoint(2,2,"red")
    list_test.append(p1)
    shift(4,list_test)
    assert(list_test[1].get_x()==6)
def test_all():
    test_add_point()
    test_print_all_points()
    test_replace_coords()
    test_deletion()
    test_square_2()
    test_circle()
    test_color()
    test_minimum_length()
    test_shift()