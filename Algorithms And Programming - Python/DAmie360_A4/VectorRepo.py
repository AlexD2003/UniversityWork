from Vector import *

class VectorRepository():
    def __init__(self):
        """
        <Constructor>
        """
        self.__data=[]
    def get_data(self):
        """
        <This function returns the data of a vector>
        """
        return self.__data
    def add_vector(self,vector2):
        """
        <This function adds a vector to the repo>
        vector2-the vector
        """
        self.__data.append(vector2)
    def get_vector_at_index(self,index):
        """
        <This function prints all the vectors at a given index>
        """
        print(self.__data[index])
    def update_vector_at_index(self,index,id2,color2,typeV2,values2):
        """
        <This function updates a vector at a given index>
        index-the index
        id2,color2,typeV2,values2-new values for the vector
        """
        self.__data[index].set_vector_id(id2)
        self.__data[index].set_color(color2)
        self.__data[index].set_type(typeV2)
        self.__data[index].set_values(values2)
    def update_vector_by_id(self,id,color2,typeV2,values2):
        """
        <This function updates a vector by id>
        id-the id
        color2,typeV2,values2-new values for the vector
        """
        for x in self.__data:
            if x.get_vector_id() == id:
                x.set_color(color2)
                x.set_type(typeV2)
                x.set_values(values2)
    def delete_vector_at_index(self,index):
        """
        <This function deletes a vector at a given index>
        index-the index
        """
        del self.__data[index]
    def delete_vector_by_id(self,id):
        """
        <This function deletes a vector by id>
        id-the id
        """
        for x in self.__data:
            if str(x.get_vector_id()) == str(id):
                self.__data.remove(x)