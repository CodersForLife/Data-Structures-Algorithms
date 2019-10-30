// Quick Sort in Go (Golang)
package main
 
import (
    "fmt"
    "math/rand"
    "time"
)
 //main function
func main() {
 
    slice := generateSlice(15) //number of random numbers you want to be generated
    fmt.Println("\nUnsorted\n", slice)
    quicksort(slice)
    fmt.Println("\nSorted\n", slice, "\n")
}
 
// Generates a slice of random numbers of size specified at line 12
func generateSlice(size int) []int {
 
    slice := make([]int, size, size)
    rand.Seed(time.Now().UnixNano())
    for i := 0; i < size; i++ {
        slice[i] = rand.Intn(999) - rand.Intn(999)
    }
    return slice
}

//quick sort function
func quicksort(a []int) []int {
    if len(a) < 2 {
        return a
    }
      
    left, right := 0, len(a)-1
      
    pivot := rand.Int() % len(a)
      
    a[pivot], a[right] = a[right], a[pivot]
      
    for i, _ := range a {
        if a[i] < a[right] {
            a[left], a[i] = a[i], a[left]
            left++
        }
    }
      
    a[left], a[right] = a[right], a[left]
      
    quicksort(a[:left])
    quicksort(a[left+1:])
      
    return a
}