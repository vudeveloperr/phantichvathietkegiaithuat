//
//  main.cpp
//  Bai19_BackTracking_người_du_lịch
//
//  Created by nguyen van vu on 11/29/19.
//  Copyright © 2019 nguyen van vu. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#define n 5
#define Start 0
using namespace std;
int a[n] ,b[n], luu[n] , gttu =100000,s=0;

int A[n][n] = {
    { 0 ,1 ,2 ,7 ,5 },
    { 1 ,0 ,4 ,4 ,3 },
    { 2 ,4 ,0 ,1 ,2 },
    { 7 ,4 ,1 ,0 ,3 },
    { 5 ,3 ,2 ,3 ,0 }
};

void init(){
    for (int i=0; i<n; i++) {
        b[i] = 1;
    }
    a[0] = Start;
    b[Start]=0;
}

void luuKq(){
    for (int i=0; i<n; i++) {
        luu[i] = a[i];
        
    }
}

void xuat(){
    cout<<"gia tri toi uu = "<<gttu<<endl;
    for (int i=0; i<n; i++) {
        cout<<luu[i]<<" ";
    }
    cout<<Start;
}

int giatri(){
    int S=0 , start = Start;
    for (int i=1 ; i<n ; i++) {
        S+= A[start][a[i]];
        start = a[i];
    }
    S+= A[start][a[0]];
    return S;
}

void Try(int i){
    int j ;
    for (j =0 ; j<n; j++) {
        if (b[j] == 1) {
            a[i] = j;
            cout<<a[i]<<" ";
            b[j] = 0;
            if (i == n-1) {
                cout<<"= "<<giatri()<<endl;
                if (giatri() < gttu) {
                    gttu = giatri();
                    luuKq();
                    cout<<"= "<<giatri()<<endl;
                }
            } else {
                Try(i+1);
            }
            b[j]=1;
        }
    }
}

int main(int argc, const char * argv[]) {
    init();
    Try(1);
    xuat();
    cout<<endl;
    return 0;
}
