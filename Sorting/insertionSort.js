/**
 * 
 * @param {[]} vet
 * Insertion Sort: Sorts the array in ascending order
 * Time Complexity: O(N^2)
 */

const insertionSort = (vet = []) => {
    for (let i = 0; i < vet.length; i++) {
        let aux = vet[i];
        let j = i;
        while ((j > 0) && (vet[j-1] > aux)) {
            vet[j] = vet[j-1];
            j -= 1;
        }
        vet[j] = aux;
    }
    return vet;
}

let result = [1, 2, 30, 4, 8, 3, 110, 8, 8, 7, 3, 6, 15];
console.log(insertionSort(result)); 