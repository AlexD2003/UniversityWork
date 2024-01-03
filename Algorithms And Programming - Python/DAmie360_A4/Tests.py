from Vector import *
from VectorRepo import *


def test_vector_class():
    v = Vector("random name", "blue", 10, [-1,5,15])
    
    assert v.get_vector_id() == "random name"
    assert v.get_color() == "blue"
    assert v.get_type() == 10
    assert v.get_values() == [-1,5,15]
    v.set_vector_id(-5)
    assert v.get_vector_id() == -5
    v.set_vector_id("red")
    assert v.get_vector_id() == "red"
    v.set_color("magenta")
    assert v.get_color() == "magenta"
    v.set_color("pink")
    assert v.get_color() == "pink"
    v.set_type(5)
    assert v.get_type() == 5
    v.set_type(1)
    assert v.get_type() == 1
    v.set_values([3,9,2])
    assert v.get_values() == [3,9,2]
    v.set_values([4,4,4])
    assert v.get_values() == [4,4,4]