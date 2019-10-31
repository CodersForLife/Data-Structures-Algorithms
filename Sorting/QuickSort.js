/* QuickSort works by picking a pivot and dividing the list in relation to that pivot: 
all elements greater than the pivot go to the right of the pivot, 
and all elements less than or equal to the pivot go to the left of the pivot.
Elements on both sides are quick sorted, and this is repeated until the complete list is sorted.
*/

function quickSort(list) {
    if (list.length <= 1) { 
        return list
    } else {
        const left = []
        const right = []
        const sorted = []
        const pivot = list.pop() // we're picking the last item to act as the pivot
        const length = list.length

        for (let i = 0; i < length; i++) {
            if (list[i] <= pivot) {
                left.push(list[i])
            } else {
                right.push(list[i])
            }
        }

        return sorted.concat(quickSort(left), pivot, quickSort(right))
    }
}

const list = [0,85,64,21,36]
const sorted = quickSort(list)
console.log(sorted)
