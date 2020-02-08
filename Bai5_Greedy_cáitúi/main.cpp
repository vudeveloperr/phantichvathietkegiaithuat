//
//  main.cpp
//  Bai5_Greedy_cáitúi
//
//  Created by nguyen van vu on 11/29/19.
//  Copyright © 2019 nguyen van vu. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct MONDO{
    int w;
    int v;
    int num;
}MONDO;
//1 doc du lieu tu file
void docfile(char fname[] , MONDO a[] , int &n);
// 2 in thong tin mon do
void inmondo(MONDO m);

void docfile(char fname[] , MONDO a[] , int &n){
    FILE *fp = fopen(fname,"r");
    if (fp == NULL) {
        cout<<"khong mo duoc file ";

    } else {
        fscanf(fp,"%d",&n);
        for (int i =0 ; i<n; i++) {
            fscanf(fp, "%d" , &a[i].w);
            fscanf(fp, "%d" , &a[i].v);
            fscanf(fp, "%d" , &a[i].num);
        }
    }
    fclose(fp);
}

void inmondo(MONDO m){
    cout<<"( "<<m.w<<" ,"<<m.v<<" ,"<<m.num<<" )";
}

void swap(MONDO &a,MONDO &b){
    MONDO t = a ;
            a=b;
            b=t;
}
// sap xep theo tang dan khoi luong.
void sapxep1(MONDO a[] , int n){
    for (int i=0; i<n-1; i++) {
        for (int j =i+1; j<n; j++) {
            if (a[i].w > a[j].w) {
                swap(a[i], a[j]);
            }
        }
    }
}

//Giảm dan theo gia tri
void sapxep2(MONDO a[] , int n){
    for (int i=0; i<n-1; i++) {
        for (int j =i+1; j<n; j++) {
            if (a[i].v < a[j].v) {
                swap(a[i], a[j]);
            }
        }
    }
}

void sapxep3(MONDO a[] , int n){
    for (int i =0 ; i<n; i++) {
        for (int j =i; j < n; j++) {
            if (((float)(a[i].v)/a[i].w) < ((float)(a[j].v) / a[j].w)) {
                swap(a[i], a[j]);
            }
        }
    }
}
/*
 w = suc chua toi da cua cai tui
 soluong la mang 1 chieu luu so luong moi vat dc chon
 */
int greedy1(MONDO a[] , int n , int w ,int soluong[]){
    // sap xep cac do vat uu tien lay truoc
    int tonggt[n] , temp =0;
    sapxep1(a, n);
    // duyet qua tung loai do vat va lay so luong can thiet .
    for (int i=0; i<n; i++) {
        inmondo(a[i]);
        soluong[i] = w/a[i].w; //uu tien lay het do vi tri 0
        w -= soluong[i]*a[i].w;
        cout<<soluong[i]<<"  ";cout<<a[i].v;
        cout<<endl;
        tonggt[i] = soluong[i]*a[i].v;cout<<tonggt[i];
        temp += tonggt[i];
        cout<<endl;
    }
    return temp;
}

int greedy2(MONDO a[] , int n , int w ,int soluong[]){
    // sap xep cac do vat uu tien lay truoc
    int tonggt[n] , temp =0;
    sapxep2(a, n);
    for (int i=0; i<n; i++) {
        inmondo(a[i]);
        soluong[i] = w/a[i].w; //uu tien lay het do vi tri 0
        w -= soluong[i]*a[i].w;
        cout<<soluong[i]<<"  ";cout<<a[i].v;
        cout<<endl;
        tonggt[i] = soluong[i]*a[i].v;cout<<tonggt[i];
        temp += tonggt[i];
        cout<<endl;
        
    }
    return temp;
}

int greedy3(MONDO a[] , int n , int w ,int soluong[]){
    // sap xep cac do vat uu tien lay truoc
    int tonggt[n] , temp =0;
    sapxep3(a, n);
    // duyet qua tung laoi do vat va lay so luong can thiet .
    for (int i=0; i<n; i++) {
        inmondo(a[i]);
        soluong[i] = w/a[i].w; //uu tien lay het do vi tri 0
        w -= soluong[i]*a[i].w;
        cout<<soluong[i]<<"  ";cout<<a[i].v;
        cout<<endl;
        tonggt[i] = soluong[i]*a[i].v;cout<<tonggt[i];
        temp += tonggt[i];
        cout<<endl;
    }
    return temp;
}

int main(int argc, const char * argv[]) {
    MONDO a[20];
    int n ,w ;
    cout<<"nhap khoi luong tui: ";
    cin>>w;
    cout<<"khoi luong / gia tri / so luong "<<endl;
    int soluong[20];
    docfile("CAITUI.txt", a, n);
    cout<<"tong Gia tri: "<<endl<< greedy2(a, n, w,soluong);
    
    return 0;
}
