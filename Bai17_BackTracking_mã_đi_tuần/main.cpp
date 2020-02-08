//
//  main.cpp
//  Bai17_BackTracking_mã_đi_tuần
//
//  Created by nguyen van vu on 11/29/19.
//  Copyright © 2019 nguyen van vu. All rights reserved.
//


#include <iostream>
#include <stdio.h>
using namespace std;
#define n 5

int q[8]={1,2,2,1,-1,-2,-2,-1};
int w[8]={2,1,-1,-2,-2,-1,1,2};
int  a[20][20] , c=0 ;

void init(){
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            a[i][j] = 0;
        }
    }
}
void print(){
    for (int i =0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout<<a[i][j]<<" ";
        }cout<<endl;
    }
}

void Try(int i , int x , int y){
    int e,r;
    for (int k=1; k<=8; k++) {
        e = x + q[k];
        r = y + w[k];
        
        if ((0<=e)&& (e<=n-1) && (0<=r) && (r<=n-1) && (a[x][r]==0)) {
            a[x][r] = i;
            if (i < n*n) {
                Try(i+1, e, r);
            } else {
                c++;
                cout<<"pa :" << c<<endl;
                print();
            }
            a[x][r]=0;
        }
    }
}

int main(int argc, const char * argv[]) {
    init();
    a[1][2]=1;Try(2, 1, 2);
    
    return 0;
}
