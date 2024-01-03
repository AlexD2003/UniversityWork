from package import *


class package_repo(Package):
    def __init__(self):
        self.__repo=[]
    def add_package(self,package):
        serial_check=package.get_serial()
        cond=1
        for elem in self.__repo:
            if(elem.get_serial()==serial_check):
                cond=0
                print("Serial already exists")
        if(cond==1):
            try:
                self.__repo.append(package)
            except ValueError as ex:
                print(ex)
    def get_all(self):
        print("Current package:")
        for elem in self.__repo:
            print(elem)
        print("\n")
    def average(self,destination):
        array=[]
        for elem in self.__repo:
            if(elem.get_destination()==destination):
                array.append(elem.get_weight())
        s=0
        for elem in array:
            s+=elem
        return(s/len(array))
        
    def test(self):
        repo1=package_repo()
        p1=Package(5423,"Cluj-Napoca",2.5)
        p2=Package(4321,"Targu-Mures",5.5)
        p3=Package(4357,"Cluj-Napoca",1)
        repo1.add_package(p1)
        repo1.add_package(p2)
        repo1.add_package(p3)
        assert(repo1.average("Cluj-Napoca")==1.75)
        repo2=package_repo()
        repo2.add_package(p1)
        repo2.add_package(p3)
        assert(repo1.average("Cluj-Napoca")==1.75)
    def sort(self):
        for i in range (len(self.__repo)-1):
            j=i+1
            for j in range(len(self.__repo)):
                if(int(self.__repo[i].get_serial())%10<int(self.__repo[j].get_serial()%10)):
                    aux=self.__repo[i]
                    self.__repo[i]=self.__repo[j]
                    self.__repo[j]=aux
    