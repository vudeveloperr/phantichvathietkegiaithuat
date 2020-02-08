//
//  main.cpp
//  Bai3_DnC_dãyconliêntiếpcótổnglớnnhất
//
//  Created by nguyen van vu on 11/29/19.
//  Copyright © 2019 nguyen van vu. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

int MaxLeftVector(int a[] , int i , int j){
    int MaxSum = a[j];
    int Sum = a[j];
    for (int k = j-1; k>=i; k--) {
        Sum+=a[k];
        if (Sum > MaxSum) {
            MaxSum = Sum ;
        }
    }
    return MaxSum;
}

int MaxRightVector(int a[] , int i , int j){
    int MaxSum = a[i];
    int Sum = a[i];
    for (int k = i+1; k<=j; k++) {
        Sum+=a[k];
        if (Sum > MaxSum) {
            MaxSum = Sum ;
        }
    }
    return MaxSum;
}

int MaxSubVector(int a[] , int i , int j){
    int WL , WR , WM ;
    if (i==j) {
        return a[i];
    }
    else{
        int m = (i+j)/2;
        WL = MaxSubVector(a, i, m);
        WR = MaxSubVector(a, m+1, j);
        WM = MaxLeftVector(a, i, m) + MaxRightVector(a, m+1, j);
        return (max(WM, max(WL, WR)));
    }
}


int main(int argc, const char * argv[]) {
    
    int a[] = { 13,-45 , 25 , -9 , 20 , 19 , -8 ,-15};
    
    cout<<MaxSubVector(a , 0, 8);
    
    return 0;
}
