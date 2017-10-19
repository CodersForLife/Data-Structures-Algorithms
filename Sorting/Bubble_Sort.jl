# Bubble Sort Program
# Author: James Burgess --> https://github.com/James-Burgess
# Link to Jupyer Notebook --> https://github.com/James-Burgess/MonthOfJulia/blob/master/notebooks/moj_07_bubble-sort.ipynb

###################
#### Method #######
###################

function bubble_sort(Array_Orig)

        # Bubble Sort takes an array as an input and returns the sorted array by default in ascending order.
        #   Pre-Conditions - Array must contain elements of integer type only.
        #                  - By default ascending order is given 

        # Bubble_Sort(Array_Orig) --> Standard Function Call

    #create a new array so we don't destroy the old one.
    Array = Array_Orig

    #set count to 1 to start at first element of the array
    count = 1 
    
    #iterate through the list until we reach the end.
    while (count < length(Array))
        if (Array[count] > Array[(count+1)])
            Array[count], Array[count+1] = Array[count+1], Array[count]
            count = 1 #resets index to the beginning
        else
            count += 1 #sorted already, moving ahead to the next pair.
        end
    end
    
    #return the sorted array after the loop is done.
    return(Array)
end


###################
#### Testing ######
###################

#starting with a simple list of ints
myList = [2,5,6,3,4,3,5,7,8,9,5,3,6,8,9,0,6,9]
println(bubble_sort(myList))


#lets compare to the builtin method sorted
using Base.Test
println(@test bubble_sort(myList) == sort(myList))
#> Test Passed

# create an array of 128 random Float64's
myList = rand(128)
#> 64-element Array{Float64,1}

println(@time(bubble_sort(myList)))
#> 0.000259 seconds (4 allocations: 160 bytes)

println(@time(sort(myList)))
#> 0.000006 seconds (6 allocations: 1.375 KiB)

println(@test bubble_sort(myList) == sort(myList))
#> Test Passed
