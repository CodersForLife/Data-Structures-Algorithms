package main

import (
	"fmt"
)

func bubbleSort(arrayItem []int) {

	for i := 0; i < len(arrayItem)-1; i++ {
		for j := 0; j < len(arrayItem)-i-1; j++ {
			if arrayItem[j] > arrayItem[j+1] {
				temp := arrayItem[j]
				arrayItem[j] = arrayItem[j+1]
				arrayItem[j+1] = temp
			}
		}
	}

}

func main() {

	arrayItem := []int{2, 4, 1, 8, 3, 5, 9}
	fmt.Println("Original: ", arrayItem)
	bubbleSort(arrayItem)
	fmt.Println("Sorted: ", arrayItem)

}
