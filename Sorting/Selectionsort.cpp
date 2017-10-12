//
// Created by Tay on 10/10/17.
//

void selectionSort(int table[], int size) {
    int min, tmp;
    for (int i = 0; i < size - 1; i++) {
        min = i;
        for (int j = i + 1; j < size; j++) {
            if (table[j] < table[min]) {
                min = j;
            }
        }
        if (min != i) {
            tmp = table[i];
            table[i] = table[min];
            table[min] = tmp;
        }
        for (int a = 0; a < 7; a++) {
            std::cout << table[a] << " ";

        }
        std::cout << std::endl;
    }
}

int main() {
    int table[] = {13, 32, 43, 14, 25};
    selectionSort(table, 5);
    return 0;
}