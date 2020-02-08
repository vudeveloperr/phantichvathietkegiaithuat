//
//  main.cpp
//  Bai2_DivideNConque_MergeSort
//
//  Created by nguyen van vu on 11/29/19.
//  Copyright © 2019 nguyen van vu. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

void Merge(int a[] , int l , int m , int r){
    int i , j ,k;
    int n1 = m-l+1;//so luong phan tu trong mach 1 n1 = m-l+1
    int n2 = r-m;// so luong phan tu trong mach 2 n2 = r-m
    int L[n1]; //mach 1
    int R[n2]; // mach 2
    // gan gia tri cho mang 1
    for (i=0; i<n1; i++) {
        L[i] = a[l+i];
    }
    // gan gia tri cho mang 2
    for (j=0; j<n2; j++) {
        R[j] = a[m+1+j];
    }
    
    i=0;         //index phan tu dau tien mach 1
    j=0;         //index phan tu dau tien mach 2
    k=l;         // index phan tu dau tien mach tron
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i<n1) {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j<n2) {
        a[k] = R[j];
        j++;
        k++;
    }
}
void MergeSort(int a[], int l , int r){
    if (l<r) {
        int m = l+(r-l)/2;
        MergeSort(a, l, m);
        MergeSort(a, m+1, r);
        
        Merge(a, l, m, r);
    }
}

void printArray(int a[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main(){
    int arr[] = {12, 11, 13, 5, 6, 7, 23, 54, 1, 34, 65, 8, 14, 87};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    
    printf("Given array is \n");
    printArray(arr, arr_size);
    
    MergeSort(arr, 0, arr_size - 1);
    
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
