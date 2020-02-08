//
//  main.cpp
//  Bai23_nhánh _cận_người_du_lịch
//
//  Created by nguyen van vu on 11/29/19.
//  Copyright © 2019 nguyen van vu. All rights reserved.
//


#include <iostream>
#include <stdio.h>
using namespace std;

const int size = 20;

int maxE = 100;
int maxC = size * maxE;
int C[size][size];  //Ma trận chi phí
int X[size+1];  //X đểthửcác khảnăng, BestWay đểghi nhận nghiệm
int T[size];  //T[i] đểlưu chi phí đi từX[1] đến X[i]
int BestWay[size+1];  //, BestWay để ghi nhận nghiệm
bool FREE[size];  //Free để đánh dấu, Free[i]= True nếu chưa đi qua tp i
int minSpending;  //Chi phí hành trình tối ưu
int M,N;

void input()
{

    int i,j,k;
    cin >> N;   //Nhap so thanh pho
    cin >> M;   //Nhap so duong
    for ( i = 1; i <= N; i++ )  //Khởi tạo bảng chi phí ban đầu
    {
        for ( j = 1; j <= N; j++ )
        {
            if ( i == j ) C[i][j] = 0;
            else C[i][j] = maxC;
        }
    }

    for ( int k = 1; k <= M; k++ )
    {
        cin >> i;  //Nhap thanh pho bat dau
        cin >> j;  //Nhap thanh pho den
        cin >> C[i][j];  //Nhap gia di tu thanh pho i den j
        C[j][i] = C[i][j];  //Chi phí như nhau trên 2 chiều
    }
}

void init()
{
    for ( int i = 0; i <= N; i++ )
        FREE[i] = true;
    FREE[1] = false;  //Các thành phố là chưa đi qua ngoại trừ thành phố 1
    X[1] = 1;  //xuat phat tu thanh pho 1
    T[1] = 0;  //Chi phí tại thành phố xuất phát là 0
    minSpending = maxC;
}

void output()
{
    if ( minSpending == maxC )
        cout << "NO SOLUTION ";
    else
    {
        for ( int i = 1; i <= N; i++ )
            cout << BestWay[i] << "->";
        cout << "1" << endl;
        cout << "Cost : " << minSpending;
    }
}

void tim(int i)  //Thử các cách chọn xi
{
    for ( int j = 2; j <= N; j++ )  //Thử các thành phố từ 2 đến n
    {
        if (FREE[j])   //Nếu gặp thành phố chưa đi qua
        {
            X[i] = j;
            T[i] = T[i-1] + C[X[i-1]][j];  //Chi phí = Chi phí bước trước + chi phí đường đi trực tiếp
            if ( T[i] < minSpending )   //Hiển nhiên nếu có điều này thì C[x[i - 1], j] < +∞ rồi
            {
                FREE[j] = false;  //Đánh dấu thành phố vừa thử
                if(i == N)
                {
                    if ( ( T[N] + C[X[N]][1] ) < minSpending )  // Từx[n] quay lại 1 vẫn tốn chi phí ít hơn trước
                    {
                        for ( int i = 0; i <= N; i++ )  // Cập nhật BestConfig
                            BestWay[i] = X[i];
                        minSpending = T[N] + C[X[N]][1];
                    }
                }
                else tim( i + 1 );  //  Tìm các khả năng chọn x[i+1]
                FREE[j] = true;  // Bỏ đánh dấu
            }
        }
    }
}

int main()
{
    input();
    init();
    tim(2);
    output();
}
/*
 4 6
 1 2 3
 1 3 2
 1 4 1
 2 3 1
 2 4 2
 3 4 4
 */
