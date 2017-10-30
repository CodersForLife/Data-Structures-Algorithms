# Quick Sort Algorithm on Python
def Quicksort(array):
    less = []
    equal = []
    greater = []
    
    if len(array) > 1:
        # assign first element as pivot
        pivot = array[0]
        
        # add elements to less/equal/greater array
        for x in array:
            if x < pivot:
                less.append(x)
            elif x == pivot:
                equal.append(x)
            else:
                greater.append(x)
        
        # Recursion on less and greater array and concatenate sorted array
        return Quicksort(less) + equal + Quicksort(greater)
    else:
        # 1 or no element array
        return array

## Test
array = [12, 153, 326, 11, 564, 123]
newArray = Quicksort(array)

print("Tested: ", array)
print("Sorted: ", newArray)