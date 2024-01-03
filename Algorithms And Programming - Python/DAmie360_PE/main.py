from package_repo import *

repo=package_repo()

p1=Package(5423,"Cluj-Napoca",2.5)
p2=Package(4321,"Targu-Mures",5.5)
p3=Package(4357,"Cluj-Napoca",1)
p4=Package(2222,"Piatra-Neamt",10)
p5=Package(1313,"Piatra-Neamt",20)

repo.add_package(p1)
repo.add_package(p2)
repo.add_package(p3)
repo.add_package(p4)
repo.add_package(p5)

repo.get_all()

p6=Package(6666,"Constanta",10.5)
repo.add_package(p6)

repo.get_all()

destination="Cluj-Napoca"
print("Average:")

print(repo.average(destination))
print("\n")

repo.sort()
repo.get_all()
repo.test()