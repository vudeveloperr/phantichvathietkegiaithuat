//
//  main.cpp
//  Bai11_Greedy_khoảng_0_giao_nhau
//
//  Created by nguyen van vu on 11/29/19.
//  Copyright © 2019 nguyen van vu. All rights reserved.
//


#include <iostream>
#include <stdio.h>
using namespace std;

//struct CongViec{
//    int start;
//    int end;
//};
//// tham lam 1
//int main(int argc, const char * argv[]) {
//    int n ,i;
//    cout<<"nhap so luong cong viec: ";cin>>n;
//    CongViec a[n];
//    for (i=0; i<n; i++) {
//        cin>>a[i].start;cin>>a[i].end;
//    }
//    // sap xep
//    cout<<"sap xep"<<endl;
//    for (i=0; i<n; i++) {
//        for (int j =i+1; j<n; j++) {
//            if (a[i].start > a[j].start) {
//           CongViec temp = a[i];
//                    a[i] = a[j];
//                    a[j] = temp;
//            }
//        }cout<<a[i].start<<","<<a[i].end<<endl;
//    }
//    cout<<"danh sach cong viec duoc chon : "<<endl;
//    cout<<a[0].start<<","<<a[0].end<<endl;
//    for (int i=0; i<n; i++) {
//        if (a[i].end <= a[i+1].start) {
//            cout<<a[i].start<<","<<a[i].end<<endl;
//        }
//    }
//}
/*
 8
 2 6
 4 8
 1 9
 10 15
 7 18
 9 20
 19 23
 16 21
 */

// tham lam 2
struct CongViec{
    int start;
    int end;
    int length;
};

void init( int n ,CongViec cv[n]){
    for (int i=0; i<n; i++) {
        cin>>cv[i].start ; cin>>cv[i].end; cin>>cv[i].length;
    }
}

void sortCV( int n ,CongViec cv[n] ){
    
    CongViec temp;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            cv[i].length = cv[i].end-cv[i].start;
            cv[j].length = cv[j].end-cv[j].start;
            if (cv[i].length>cv[j].length) {
                temp = cv[i];
                cv[i] = cv[j];
                cv[j] = temp;
            }
        }cout<<cv[i].start<<","<<cv[i].end<<","<<cv[i].length<<endl;
    }
}

void greedyCV2( int n ,CongViec cv[n]){
     cout<<"danh sach cong viec duoc chon : "<<endl;
    for (int i=0; i<n; i++) {
        if (cv[i].end <= cv[i+1].start) {
             cout<<cv[i].start<<","<<cv[i].end<<","<<cv[i].length<<endl;
        }
    }
}


int main(int argc, const char * argv[]) {
    int n;
    cout<<"nhap so luong cong viec: ";cin>>n;
    CongViec cv[n];
    init(n ,cv);
    cout<<"Sau khi sort "<<endl;
    sortCV(n ,cv);
    greedyCV2(n,cv);
    return 0;
}
/*
 8
 2 6 4
 4 8 4
 1 9 8
 10 15 5
 7 18 11
 9 20 11
 19 23 4
 16 21 5
 */

