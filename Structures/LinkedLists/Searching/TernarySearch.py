'''input
10
1
2
3
4
5
6
7
8
10
11
10
'''
size = int(input())

arr = []

for _ in range(size):
	element = int(input())
	arr.append(element)

value = int(input()) # value to be searched

lo = 0
hi = size - 1
print(arr)
flag = False
while lo <= hi:
	mid1 = lo + (hi-lo)//3
	mid2 = lo + 2*(hi-lo)//3

	if arr[mid1] == value:
		print("Value found at index {}".format(mid1))
		flag = True
		break
	if arr[mid2] == value:
		print("Value found at index {}".format(mid2))
		flag = True
		break

	if value < arr[mid1]:
		hi = mid1 - 1
	elif value > arr[mid1]:
		lo = mid2 + 1
	else:
		lo = mid1 + 1
		hi = mid2 - 1

if flag == False:
	print("Value Not Found")