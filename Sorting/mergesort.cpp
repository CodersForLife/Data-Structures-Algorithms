#include <iostream>

#define NX 500010

int N, A[NX], B[NX];

void mergeSort(int left, int right) {
    int middle = (left + right) >> 1, i, j, k;

    if (left == right) {
        return;
    }

    mergeSort(left, middle);
    mergeSort(middle + 1, right);

    for (i = left, j = middle + 1, k = left; i <= middle || j <= right;) {
        if (j > right || (i <= middle && A[i] < A[j])) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }
    for (k = left; k <= right; k++) {
        A[k] = B[k];
    }
}

int main() {
    int i;

    std::cin>>N;
    for (i = 1; i <= N; i++)
        std::cin>>A[i];

    mergeSort(1, N);

    for (i = 1; i <= N; i++)
        std::cout<<A[i]<<" ";

    return 0;
}