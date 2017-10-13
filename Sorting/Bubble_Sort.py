# Bubble Sort Program
""" Bubble Sort takes an array as an input and returns the sorted array by default in ascending order without changing the orignal array.
	Pre-Conditions - Array must contain elements of integer type only.
				   - By default ascending order is given for reverse order set Reverse = True.

	Bubble_Sort(Array_Orig, Reverse = False) --> Standard Function Call

	Example:

	List = [1, 3, 5, 3, 2, 8, 2, 4]

	Bubble_Sort(List) returns --> [1, 2, 2, 3, 3, 4, 5, 8]
	Bubble_Sort(List, Reverse = False) returns --> [1, 2, 2, 3, 3, 4, 5, 8]
	Bubble_Sort(List, Reverse = True) returns --> [8, 5, 4, 3, 3, 2, 2, 1]

"""

def Bubble_Sort(Array_Orig, Reverse = False):

	# Copy of Array so that changes made are not reflected
	Array = list(Array_Orig)

	for i in range(len(Array)):
		Max = Array[i]
		Pos = i
		for j in range(i, len(Array)):
			if not Reverse:
				if Max > Array[j]:
					Max = Array[j]
					Pos = j
			elif Reverse:
				if Max < Array[j]:
					Max = Array[j]
					Pos = j

		# Swapping the positions
		Array[i],Array[Pos] = Array[Pos],Array[i]
	return Array