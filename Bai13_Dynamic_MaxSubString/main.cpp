//
//  main.cpp
//  Bai13_Dynamic_MaxSubString
//
//  Created by nguyen van vu on 11/29/19.
//  Copyright © 2019 nguyen van vu. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;


int n=9;
int MaxE[9];
int MaxS[9];
//int a[10] = {-98 ,54 ,67 ,65 ,-879 ,78 ,65 ,21 ,-6 ,67 };
int a[9] = {13, -15, 2, 18, 4, 8, 0, -5, -8};

void subMax(){
    MaxE[1] = a[1];
    MaxS[1] = a[1];
    int s=1, e=1, s1=1;
    for (int i=2 ; i <= n; i++) {
        if (MaxE[i-1] > 0 ) {
            MaxE[i] = MaxE[i-1] + a[i];
        }
        else{
            MaxE[i] = a[i];
            s1 = i;
        }
        if (MaxE[i] > MaxS[i-1]) {
            MaxS[i] = MaxE[i];
            e=i;
            s=s1;
        }
    }
}

void Trace(){
    int i=1;
    int sum=0;
    while (i<=n) {
        if (MaxE[i]>0 && MaxE[i] > MaxE[i-1]) {
            sum += MaxE[i];
            cout<<a[i]<<" ";
        }
        i++;
    }
}

int main(int argc, const char * argv[]) {
    subMax();
    Trace();
    
    return 0;
}
