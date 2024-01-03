class Package():
    def __init__(self,serial,destination,weight):
        self.__serial=serial
        self.__destination=destination
        self.__weight=weight
    def get_serial(self):
        return self.__serial
    def get_destination(self):
        return self.__destination
    def get_weight(self):
        return self.__weight
    def set_serial(self,serial):
        self.__serial=serial
    def set_destination(self,destination):
        self.__destination=destination
    def set_weight(self,weight):
        self.__weight=weight
    def __str__(self):
        return "Package serial:"+str(self.__serial)+" destination:"+str(self.__destination)+" weight:"+str(self.__weight)