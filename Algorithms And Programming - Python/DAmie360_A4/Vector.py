class Vector:
    pass
    def __init__(self,vector_id,color,typeV,values):
        """
        <Constructor>
        """
        self.__vector_id=vector_id
        self.__color=color
        self.__typeV=typeV
        self.__values=values
    def get_vector_id(self):
        """
        <Vector id getter>
        """
        return self.__vector_id
    def get_type(self):
        """
        <Vector type getter>
        """
        return self.__typeV
    def get_color(self):
        """
        <Vector color getter>
        """
        return self.__color
    def get_values(self):
        """
        <Vector values getter>
        """
        return self.__values
    def set_vector_id(self,vector_id):
        """
        <Vector id setter>
        """
        self.__vector_id=vector_id
    def set_type(self,typeV):
        """
        <Vector type setter>
        """
        self.__typeV=typeV
    def set_color(self,color):
        """
        <Vector color setter>
        """
        self.__color=color
    def set_values(self,values):
        """
        <Vector values setter>
        """
        self.__values=values
    def __str__(self):
        """
        <String form return>
        """
        return "Vector id:"+str(self.__vector_id)+" color:"+str(self.__color)+" type:"+str(self.__typeV)+" of values: "+str(self.__values)
    def add_scalar(self,scalar):
        """
        <This function adds a scalar to the vector>
        temp_list-temporary list to store values
        self.__values-private attribute that holds values
        """
        for i in range(len(self.__values)):
            self.__values[i] += scalar
    def add_2_vectors(self,vector2):
        """
        <This functions performs the addition of 2 vectors>
        temp_list-temporary list to store values
        self.__values-private attribute that holds values
        vector2-the second vector
        """
        temp_list=vector2.get_values()
        for i in range(len(vector2.get_values())):
            temp_list[i]+=self.__values[i]
        self.set_values(temp_list)
    def subtract_2_vectors(self,vector2):
        """
        <This functions performs the subtraction of 2 vectors>
        temp_list-temporary list to store values
        self.__values-private attribute that holds values
        vector2-the second vector
        """
        temp_list=vector2.get_values()
        for i in range(len(vector2.get_values())):
            temp_list[i]-=self.__values[i]
        self.set_values(temp_list)
    def multiply_2_vectors(self,vector2):
        """
        <This functions performs the multiplication of 2 vectors>
        temp_list-temporary list to store values
        self.__values-private attribute that holds values
        vector2-the second vector
        """
        temp_list=vector2.get_values()
        for i in range(len(vector2.get_values())):
            temp_list[i]*=self.__values[i]
        self.set_values(temp_list)
    def sum_of_elements(self):
        """
        <This function returns the sum of each element in the vector with one another>
        self.__values-private attribute that holds values
        sum-the sum
        """
        sum=0
        for i in range(len(self.__values)):
            sum+=self.__values[i]
        return sum
    def product_of_elements(self):
        """
        <This function returns the product of each element in the vector with one another>
        self.__values-private attribute that holds values
        product-the product
        """
        product=1
        for i in range(len(self.__values)):
            product*=self.__values[i]
        return product
    def average_of_vector(self):
        """
        <This function returns the average of the vector>
        sum-sum of the elements
        """
        sum=self.sum_of_elements()
        return sum/len(self.__values)
    def minimum_of_vector(self):
        """
        <This function returns the minimum of a vector>
        """
        return min(self.__values)
    def maximum_of_vector(self):
        """
        <This function returns the maximum of a vector>
        """
        return max(self.__values)