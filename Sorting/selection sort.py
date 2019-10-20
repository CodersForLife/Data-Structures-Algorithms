#Sorting a list in Ascending Order using Selection Sort

#Selection sort function
def selection_sort(alist):
    for i in range(0, len(alist) - 1):
        small = i
        for j in range(i + 1, len(alist)):
            if alist[j] < alist[small]:
                small = j
        alist[i], alist[small] = alist[small], alist[i]

#  Taking a list of space seperated numbers from user  
alist = input('Enter the list of numbers: ').split()
alist = [int(x) for x in alist]
selection_sort(alist)
print('Sorted list: ', end='')
print(alist)
