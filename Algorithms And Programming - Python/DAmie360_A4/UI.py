from Vector import *
from VectorRepo import *
from logic import color_check
from logic import type_check
from logic import check_array_lenght

color_array=["r","g","b","y","m"]


class UI():
    """
    <UI as a class>
    """
    def __init__(self, repo):
        """
        <Constructor>
        """
        self.__repo = repo
    def printMenu():
        """
        <Print function>
        """
        print("Menu:")
        print("1.Add a vector")
        print("2.Get all vectors")
        print("3.Return a vector by index")
        print("4.Update a vector at a given index")
        print("5.Update a vector identified by name_id")
        print("6.Delete a vector by index")
        print("7.Delete a vector by name_id")
        print("-1.Break")
    def print_all(self):
        """
        <This function prints all the vectors in the repo using the print function in the vector class>
        """
        for x in self.__repo.get_data():
            print(x)
    def read_vector():
        """
        <Function for reading the vector>
        id-id
        color-color
        typeV-type of vector
        v1,v2,v3-values
        value_array-array of values
        """
        print("Enter id:")
        try:
            id=input()
            print("Color:")
            color=input()
            if(color_check(color,color_array)==True):
                print("Type:")
                try:
                    typeV=int(input())
                    if(typeV>=1):
                        value_array=[]
                        print("How many values?:")
                        number_of_values=int(input())
                        for i in range(number_of_values):
                            print("Value:")
                            try:
                                value=int(input())
                                value_array.append(value)
                            except ValueError as ex:
                                return ex
                        return Vector(id,color,typeV,value_array)
                    else:
                        print("Invalid type!")
                except ValueError as ex:
                    return ex
            else:
                print("Invalid color!")
        except ValueError as ex:
            return ex
        value_array=[]
    def start_program(self):
        option=-2
        while(option!=-1):
            print("Index of option:")
            option=int(input())
            if(option<-1 or option>8):
                print("Option out of range!")
            else:
                if(option==1):
                    vector2=UI.read_vector()
                    self.__repo.add_vector(vector2)
                elif(option==2):
                    self.print_all()
                elif(option==3):
                    print("Index:")
                    index=int(input())
                    try:
                        print(self.__repo.get_vector_at_index(index))
                    except ValueError as ex:
                        return ex
                elif(option==4):
                    value_array=[]
                    print("Index:")
                    index=int(input())
                    print("New id:")
                    id2=input()
                    print("New color:")
                    color2=input()
                    if(color_check(color2)==True):
                        print("New type:")
                        typeV2=int(input())
                        if(type_check(typeV2)==True):
                            print("Number of values:")
                            number_of_values=int(input())
                            for i in range(number_of_values):
                                try:
                                    print("Value:")
                                    value=int(input())
                                    value_array.append(value)
                                except ValueError as ex:
                                    return ex
                            try:
                                self.__repo.update_vector_at_index(index,id2,color2,typeV2,value_array)
                            except ValueError as ex:
                                return ex
                        else:
                            print("Invalid type!")
                    else:
                        print("Invalid color!")
                    value_array=[]
                elif(option==5):
                    value_array=[]
                    print("Index:")
                    index=int(input())
                    print("New id:")
                    id2=input()
                    print("New color:")
                    color2=input()
                    if(color_check(color2)==True):
                        print("New type:")
                        typeV2=int(input())
                        if(type_check(typeV2)==True):
                            print("Number of values:")
                            number_of_values=int(input())
                            for i in range(number_of_values):
                                try:
                                    print("Value:")
                                    value=int(input())
                                    value_array.append(value)
                                except ValueError as ex:
                                    return ex
                            try:
                                self.__repo.update_vector_by_id(index,id2,color2,typeV2,value_array)
                            except ValueError as ex:
                                return ex
                        else:
                            print("Invalid type!")
                    else:
                        print("Invalid color!")
                    value_array=[]
                elif(option==6):
                    print("Index:")
                    try:
                        index=int(input())
                        self.__repo.delete_vector_at_index(index)
                    except ValueError as ex:
                        return ex
                elif(option==7):
                    print("Id:")
                    try:
                        id=int(input())
                        self.__repo.delete_vector_by_id(id)
                    except ValueError as ex:
                        return ex