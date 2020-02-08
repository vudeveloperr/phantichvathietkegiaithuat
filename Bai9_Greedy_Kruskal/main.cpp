//
//  main.cpp
//  Bai9_Greedy_Kruskal
//
//  Created by nguyen van vu on 11/29/19.
//  Copyright © 2019 nguyen van vu. All rights reserved.
//

#include <iostream>
#include <stdio.h>

using namespace std;
typedef struct Canh{
    int start ;
    int end;
    int lenght;
}Canh;
Canh dscanh[12], T[7];

int TPLT[8]={1,2,3,4,5,6,7,8};

void input(Canh dscanh[] , int n){
    for (int i=0; i<n; i++) {
        cin>>dscanh[i].start; cin>>dscanh[i].end; cin>>dscanh[i].lenght;
    }
}
void output(Canh dscanh[] , int n){
    for (int i=0; i<n; i++) {
        cout<<dscanh[i].start<<"-"<<dscanh[i].end<<" : "<<dscanh[i].lenght<<endl;
    }
}


void sapxep(Canh dscanh[] , int n){
    for (int i =0 ; i<n; i++) {
        for (int j = i+1; j<n; j++) {
            if (dscanh[i].lenght > dscanh[j].lenght) {
                Canh temp = dscanh[i];
                dscanh[i] = dscanh[j];
                dscanh[j] = temp;
            }
        }
    }
}


void kruskal(Canh dscanh[], int e , int n){
    int i = 0 ;
    int count=0;
    while (count < e ) {
        if (TPLT[dscanh[i].start] != TPLT[dscanh[i].end]) {
            T[count] = dscanh[i];count++;
            TPLT[dscanh[i].end] = TPLT[dscanh[i].start];
            for (int j=0; j<n; j++) {
                if (TPLT[j] == TPLT[dscanh[i].start]) {
                    TPLT[j] = TPLT[dscanh[i].end];
                }
            }
        }
        i++;
    }
    cout<<endl;
    if (count < e-1) {
        cout<<"do thi khong lien thong";
    }else{
        cout<<"canh lay duoc :"<<endl;
        output(dscanh, e-1);
    }
}


int main(int argc, const char * argv[]) {
    Canh dscanh[100];
    int n ,e;
    cout<<"nhap e, n: ";cin>>e; cin>>n;
    input(dscanh, n);
    sapxep(dscanh, n);
    cout<<"sap xep"<<endl;
    output(dscanh, n);
    kruskal(dscanh,e, n);
    return 0;
}
/*
 8 12
 1 3 2
 0 2 8
 0 1 1
 4 6 6
 2 3 3
 6 7 5
 3 5 3
 0 6 4
 1 7 5
 7 5 4
 4 5 3
 2 4 7
 
 */

