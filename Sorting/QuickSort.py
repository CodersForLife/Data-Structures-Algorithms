# Quick Sort Function
def quickSort(alist): 
   quickSortHelper(alist,0,len(alist)-1)

# Quick Sort Helper
def quickSortHelper(alist,first,last):
   if first<last:

       splitpoint = partition(alist,first,last)

       quickSortHelper(alist,first,splitpoint-1)
       quickSortHelper(alist,splitpoint+1,last)

# Partition Function
def partition(alist,first,last):
   pivotvalue = alist[first] #Pivot

   leftmark = first+1
   rightmark = last

   done = False
   while not done:

       while leftmark <= rightmark and alist[leftmark] <= pivotvalue:
           leftmark = leftmark + 1

       while alist[rightmark] >= pivotvalue and rightmark >= leftmark:
           rightmark = rightmark -1

       if rightmark < leftmark:
           done = True
       else:
           temp = alist[leftmark]
           alist[leftmark] = alist[rightmark]
           alist[rightmark] = temp

   temp = alist[first]
   alist[first] = alist[rightmark]
   alist[rightmark] = temp


   return rightmark

# Test Implementation
alist = [54,26,93,17,77,31,44,55,20]
quickSort(alist)
print(alist)

