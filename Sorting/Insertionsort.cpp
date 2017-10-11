//
// Created by Tay on 10/11/17.
//

void insertionSort(int table[], int size) {
    int key, j;
    for (int i = 1; i < size; i++) {
        key = table[i];
        j = i - 1;
        while (j >= 0 && table[j] > key) {
            table[j + 1] = table[j];
            j--;
        }
        table[j + 1] = key;
    }
}

int main() {
    int table[] = {13, 32, 43, 14, 25};
    insertionSort(table, 5);
    return 0;
}

