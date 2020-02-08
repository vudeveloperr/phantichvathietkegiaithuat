//
//  main.cpp
//  Bai7_Greedy_Dijkstra
//
//  Created by nguyen van vu on 11/29/19.
//  Copyright © 2019 nguyen van vu. All rights reserved.
//

#include <stdio.h>
#include <curses.h>
#include <iostream>
#define max 10
using namespace std;

int n=10;
int VC =1000;
int a[max][max]={
//    {0 , 20, 15,VC , 80, VC },
//    {40, 0 , VC,VC , 10, 15},
//    {20, 4 , 0 ,VC , VC, 10},
//    {36, 18, 15, 0 , VC, VC},
//    {VC, VC, 90, 15, 0 , VC},
//    {VC, VC, 45, 4 , 10, 0 },
    {0 ,6 ,24,VC,16,VC,22,VC,19,VC},
    {VC,0 ,11,21,15,13,VC,24,VC,17},
    {7 ,6 ,0 ,VC,12,14,23,11,14,VC},
    {11,VC,16,0 ,13,VC,13,5 ,24,VC},
    {22,VC,VC,13,0 ,14,11,22,VC,15},
    {11,2 ,6 ,VC,VC,0 ,11,4 ,21,8 },
    {8 ,13,VC,16,9 ,11,0 ,21,VC,11},
    {21,15,VC,11,VC,5 ,11,0 ,VC,25},
    {VC,16,12,VC,VC,24,13,16,0 ,12},
    {VC,17,18,22,24,21,VC,11,12,0 }
    
};


void xuatdd(int s , int k , int Ddnn[max]){
    int i ;
    cout<<"\nduong di ngan nhat tu "<<s+1<<" den "<<k+1<<"la: ";
    i=k;
    while(i!=s){
        cout<<i+1<<"<--";
        i = Ddnn[i];
    }
    cout<<s+1;
}

void dijiktra(int s){
    int Ddnn[max];//chua duong di ngan nhat tu dinh s den t tai moi buoc
    int i , k = 0 , Dht , Min;
    int DaXet[max];// danh dau cac dinh da dua vao S
    int L[max];
    
    for (i =1 ; i<=n; i++) {
        DaXet[i]=0;
        L[i] = VC;
    }
    // dua dinh s vao tap dinh S da xet
    DaXet[s] =1;
    L[s] = 0;// nhan dinh L
    Dht = 0;
    int h=0;// dem moi buoc cho du n-1 buoc
    while (h<=n-2) {
        Min = VC;
        for (i = 1; i<n; i++) {
            if (!DaXet[i]) {
                if (L[Dht] + a[Dht][i] < L[i]) {//tinh lai nhan
                    L[i] = L[Dht] + a[Dht][i];
                    Ddnn[i] = Dht;
                    // gan dinh hien tai la dinh truoc dinh i tren lo trinh
                }
                if (L[i] < Min) {// chon dinh k
                    Min = L[i];
                    k = i;
                }
            }
        }
        // tai buoc h : tim duoc duong di ngan nhat yu s den k : Ddnn[]
        xuatdd(s, k, Ddnn);
        cout<<"\nTrong so :"<<L[k];
        Dht = k;// khoi dong lai dht
        DaXet[Dht] =1;// dua nut k vao tap nut da xet
        h++;
    }
}

int main(){
    dijiktra(0);
    cout<<endl;
}
