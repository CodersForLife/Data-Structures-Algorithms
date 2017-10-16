#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int a[], int s) {
    for (int i = 1; i < s; i++) {
        bool swapped = false;

        for (int j = 0; j < s - i; j++) {
            if (a[j] > a[j + 1]) {
                std::swap(a[j], a[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) {
            return;
        }
    }
}

void main(){
	int a[]={13,32,43,14,25};
	bubbleSort(a,5);
}