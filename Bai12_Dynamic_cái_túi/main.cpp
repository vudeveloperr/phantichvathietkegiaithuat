//
//  main.cpp
//  Bai12_Dynamic_cái_túi
//
//  Created by nguyen van vu on 11/29/19.
//  Copyright © 2019 nguyen van vu. All rights reserved.
//
//
#include <iostream>
#include <stdio.h>

struct MONDO{
    int cost;
    int weight;
};

using namespace std;

int MAXV[100][100];

void Enter(MONDO a[] ,int n , int b){
    for (int i = 1 ; i<=n; i++) {
        cout<<"Pack "<<i <<":";
        cout<<"weight , cost :";cin>>a[i].weight; cin>>a[i].cost;
    }
}

int Bag_Best(MONDO a[] ,int n , int b){
    int L ;
    int i ;
    for (L=0; L<=b ;L++) {
        MAXV[0][L]=0;
    }
    for (i=0; i<=n; i++) {
        MAXV[i][0]=0;
    }
    for (i=1; i <= n ; i++) {
        for (L=1; L <= b; L++) {
            MAXV[i][L] = MAXV[i-1][L];
            if ((L > a[i].weight) && (MAXV[i-1][L - a[i].weight]+a[i].cost > MAXV[i-1][L])){
                MAXV[i][L] = MAXV[i-1][L-a[i].weight] + a[i].cost;
            }
        }
    }
    return MAXV[n][b];
}


void Trace(MONDO a[] ,int n , int b){
    cout<<"Max value : "<< MAXV[n][b];cout<<endl;
    while (n != 0) {
        if (MAXV[n][b] != MAXV[n-1][b] ) {
            cout<<"pack : "<<n<<" w: "<<a[n].weight <<" v: "<<a[n].cost;cout<<endl;
            b = b-a[n].weight;
        }
        n--;
    }
}

int main(int argc, const char * argv[]) {
    int n;
    int b;
    cout<<"nhap so luong mon do : ";cin>>n;
    cout<<"nhap khoi luong cua tui: ";cin>>b;
    MONDO a[n];
    Enter(a, n, b);
    Bag_Best(a, n, b);
    Trace(a, n, b);
    return 0;
}
