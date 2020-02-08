//
//  main.cpp
//  Bai6_Greedy_ngườidulịch
//
//  Created by nguyen van vu on 11/29/19.
//  Copyright © 2019 nguyen van vu. All rights reserved.
//

#include <iostream>
#define max 5
#define VC 9999
using namespace std;

int a[max][max]={
    { 0, 1, 2, 7, 5},
    { 1, 0, 4, 4, 3},
    { 2, 4, 0, 1, 2},
    { 7, 4, 1, 0, 3},
    { 5, 3, 2, 3, 0}
};
int TOUR[max];

int GTS (int a[max][max], int n, int TOUR[max], int Ddau){

    int v, //Dinh dang xet
    k, //Duyet qua n dinh de chon
    w = 0; //Dinh duoc chon trong moi buoc
    int mini; //Chon min cac canh(cung) trong moi buoc
    int COST; //Trong so nho nhat cua chu trinh
    int daxet[max]; //Danh dau cac dinh da duoc su dung
    for(k = 1; k <= n; k++){
        daxet[k] = 0; //Chua dinh nao duoc xet
    }
    COST = 0; //Luc dau, gia tri COST == 0

    int i; // Bien dem, dem tim du n dinh thi dung
    v = Ddau; //Chon dinh xuat phat la 1
    i = 0;
    TOUR[i] = v; //Dua v vao chu trinh
    daxet[v] = 1; //Dinh v da duoc xet
    while(i < n){
        mini = VC;
        for (k = 1; k <= n; k++)
            if(!daxet[k])
                if(mini > a[v][k])
                {
                    mini = a[v][k];
                    w = k;
                }
        v = w;
        i++;
        TOUR[i] = v;
        daxet[v] = 1;
        COST += mini;
    }
    
    COST += a[v][Ddau];
    return COST;

}


int main(int argc, const char * argv[]) {
    cout<<"chi phi nho nhat : "<<GTS(a, 4,TOUR , 0)<<endl;
    return 0;
}
