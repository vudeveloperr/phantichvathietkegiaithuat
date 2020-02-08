//
//  main.cpp
//  Bai1_DivideNConque_QuickSort
//
//  Created by nguyen van vu on 11/29/19.
//  Copyright © 2019 nguyen van vu. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#define MAX 8

int Array[MAX] = {66,33,27,10,35,19,42,44};

using namespace std;

// ham de trao doi gia tri
void swap(int num1,int num2){
    int temp = Array[num1];
    Array[num1] = Array[num2] ;
    Array[num2] = temp;
}
void display(){
    int i;
    cout<<"[ ";
    for (i=0 ; i< MAX; i++) {
        cout<<Array[i];
    }
    
    cout<<"]";
}

void QuickSort(int left , int right){
    int i , j ;
    if (left < right) {
        i= left +1;
        j = right;
        do {
            while (Array[i] <= Array[left] && i<right) {
                i++;
            }
            while (Array[j] > Array[left]) {
                j--;
            }
            if (i < j) {
                swap(i,j);
                cout<<"\ntrao doi ["<<Array[j]<<", "<<Array[i]<<"]";
                display();
            }
        } while (i < j);
        swap(left,j);
        cout<<"\ntrao doi ["<<Array[j]<<", "<<Array[left]<<"]";
        display();

        if (left<j-1) {
            QuickSort(left, j-1);
        }
        if (j+1<right) {
            QuickSort(j+1 ,right);
        }
    }
}


int main(int argc, const char * argv[]) {
    cout<<"mang du lieu dau vao";
    display();
    cout<<"\n";
    QuickSort(0,MAX-1);
    cout<<"\nMang sau sap xep";
    display();
    
    return 0;
}
