# optimized - shifts instead of swapping		
def insertion_sort(Arr):
	for i in range(1, len(Arr)):
		curNum = Arr[i]
		pos = 0
		for j in range(i-1, -2, -1):
			pos = j
			if Arr[j] > curNum:
				Arr[j+1] = Arr[j]
			else:
				break
		Arr[pos+1] = curNum
	return Arr

if __name__=="__main__":
    test = [10,67,2,998,23,56,32,21,91,21,22]
    print(insertion_sort(test))
    
