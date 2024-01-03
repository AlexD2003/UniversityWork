from UI import *
from VectorRepo import *
from Tests import *



test_vector_class()
repo=VectorRepository()
ui=UI(repo)
UI.printMenu()
ui.start_program()