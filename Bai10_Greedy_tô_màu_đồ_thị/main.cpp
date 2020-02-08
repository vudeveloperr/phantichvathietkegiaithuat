//
//  main.cpp
//  Bai10_Greedy_tô_màu_đồ_thị
//
//  Created by nguyen van vu on 11/29/19.
//  Copyright © 2019 nguyen van vu. All rights reserved.
//


#include <iostream>
#include <stdio.h>

using namespace std;

// kiem tra dinh i co to dcuoc mau c hay ko
int toDuoc(int a[][10] , int i , int n ,int v[], int c){
    for (int j=0; j<n; j++) {
        if (a[i][j] && v[j]==c) {// kiem tra a[i][j]co dinh duong noi tu i sang j,a[i][j] = 1 la true va ngc lai
            return 0;//dinh j da duoc to bang mau c
        }
    }
    return 1;  //1 to duoc con 0 la khong to duoc
}
//ham lay 1 mau to cho cac dinh co the to , ham tra ve so dinh da duoc to
//mang v luu so thu tu cua mau da dc to
int To1Mau(int a[][10] , int n , int v[] , int color){
    int count=0;
    for (int i=0; i<n; i++) {
        if (!v[i] && toDuoc(a, i, n, v, color)) {//v[i]=0 la chua dc to
            v[i]=color;
            count++;
        }
    }
    return count;           // tra ve son dinh da duoc to
}
// ham to het cac dinh tra ve so mau it nhat can de to cac dinh ,
// mau duoc luu trong mang v[], dinh nao mau gi luu vao mang v[]
int toMau(int a[][10] , int n, int v[]){
    for (int i =0; i<n; i++) {
        v[i]=0;
    }
    int somau=0;
    int count=0;// so luong dinh da duoc to sau moi mau
    while (count<n) {
        somau++;
        count+=To1Mau(a, n, v, somau);
    }
    return somau;
}
//
int main(int argc, const char * argv[]) {
    int a[10][10];
    int n;
    int v[10];
    FILE *file;
    file = fopen("tomaudothi.txt", "r");
    fscanf(file, "%d",&n);
    for (int i=0; i<n; i++) {
        for (int j=0;j<n ; j++) {
            fscanf(file, "%d" ,&a[i][j]);
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0;j<n ; j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    fclose(file);
    
    cout<<"so mau to duoc : "<<toMau(a, n, v)<<endl;
    for (int i=0; i<n; i++) {
        cout<<"dinh "<<i+1<<" "<<v[i]<<endl;
    }
    return 0;
}

