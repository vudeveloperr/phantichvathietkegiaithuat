//
//  main.cpp
//  Bai16_BackTracking_xếp_tám_hậu
//
//  Created by nguyen van vu on 11/29/19.
//  Copyright © 2019 nguyen van vu. All rights reserved.
//


#include <stdio.h>
#include <curses.h>

int a[20] , n , b[50], c[50] ,d[20];

void khoitao(){
    printf("nhap n: ");scanf("%d",&n);
    
    for (int i=2; i <=2*n; i++) {
        b[i] = true;
    }
    for (int j=1-n; j<=n-1; j++) {
        c[j] = true;
    }
    for (int t = 1; t<=n; t++) {
        d[t] = true;
    }
}
void PrintArray(){
    for (int i =1 ; i<=n; i++) {
        printf("{%d,%d} ",i,a[i]);
    }
    printf("\n");
}

void xephau(int i){
    
    for (int j=1; j<=n; j++) {
        if (d[j] && b[i+j] && c[i-j] ) {
            d[j] =false;
            b[i+j] =false ;
            c[i-j] =false ;
            a[i] =j;
            if (i == n) {
                PrintArray();
            } else {
                xephau(i+1);
            }
            d[j] = true;
            b[i+j] =true ;
            c[i-j] = true ;
        }
    }
}

int main(){
    khoitao();
    xephau(1);
    return 0;
}
