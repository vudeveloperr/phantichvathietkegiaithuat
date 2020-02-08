//
//  main.cpp
//  Bai18_BackTracking_Cái_túi
//
//  Created by nguyen van vu on 11/29/19.
//  Copyright © 2019 nguyen van vu. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#define n 6
#define b 19

using namespace std;

int x[n], luu[n] , gt=0;
struct Dovat{
    int cost ;
    int weight;
};

Dovat dv[n];

int KhoiLuong(){
    int kl =0;
    for (int i=0; i<n; i++) {
        if (x[i] != 0 ) {
            kl += dv[i].weight;
        }
    }
    return kl;
}

int GiaTri(){
    int gt = 0;
    for (int i =0; i<n; i++) {
        if (x[i] != 0 ) {
            gt += dv[i].cost;
        }
    }
    return gt;
}

void LuuKetQua(){
    for (int i=0 ; i<n; i++) {
        luu[i] = x[i];
    }
}

void xuat(){
    for (int i=0; i<n; i++) {
        if (luu[i] ==1) {
            cout << "Chon vat thu " << i << "\t" << dv[i].cost << "\t" << dv[i].weight << "\n";
        }
    }
}


void Try(int i){
    int j;
    for (j=0; j<=1; j++) {
        x[i] = j;
        if (i<n-1) {
            Try(i+1);
        }
        else if ((GiaTri() > gt) && (KhoiLuong() <= b)) {
                gt = GiaTri();
                LuuKetQua();
        }
    }
}


int main(int argc, const char * argv[]) {
    dv[0].weight=7; dv[0].cost=11;
    dv[1].weight=5; dv[1].cost=10;
    dv[2].weight=3; dv[2].cost=5;
    dv[3].weight=2; dv[3].cost=13;
    dv[4].weight=4; dv[4].cost=16;
    dv[5].weight=6; dv[5].cost=8;
    for (int i=0 ; i< 6; i++) {
        cout<<i+1<<": "<<dv[i].weight <<" "<<dv[i].cost<<endl;
    }
    
    Try(0);
    cout<<"gia tri toi uu : "<<gt<<endl;
    xuat();
    return 0;
}
