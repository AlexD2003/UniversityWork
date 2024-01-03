def color_check(color,color_array):
    check=False
    for i in range(len(color_array)):
        if(color==color_array[i]):
            check=True
            break
    return check
def type_check(type):
    check=False
    try:
        if(type>=1):
            check=True
    except ValueError:
        return check
    return check
def check_array_lenght(array1,array2):
    lenght1=len(array1)
    lenght2=len(array2)
    if(lenght1!=lenght2):
        return False
    else:
        return True
 