//
// Created by myungki cho on 2024/02/11.
//
/*
#include<iostream>
#include<algorithm>

using namespace std;

int arr[10];
void debug() {
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void partition(int left, int right) {
    if (left >= right) return;
    int pivot = left;
    int low = left + 1;
    int high = right;

    while (low < high) {
        while (arr[low] <= arr[pivot] && low <= high) low++;
        while (arr[high] > arr[pivot] && low <= high) high--;

        if(low < high) {
            swap(arr[low], arr[high]);
        }
    }
    swap(arr[high], arr[pivot]);
    partition(left, high-1);
    partition(high+1, right);
}

int main() {
    arr[0] = 10;
    arr[1] = 9;
    arr[2] = 8;
    arr[3] = 7;
    arr[4] = 6;
    arr[5] = 5;
    partition(0,5);
    debug();
    return 0;
}*/
