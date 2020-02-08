//
//  main.cpp
//  Bai8_Greedy_Prim
//
//  Created by nguyen van vu on 11/29/19.
//  Copyright © 2019 nguyen van vu. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

int G[20][20] , dinh , canh ;

void Accept(int G[20][20] , int dinh , int canh){
    int cost , src , dest;
    for (int i = 0; i<canh; i++) {
        cout<<"src , dest , cost : ";
        cin>>src >> dest >> cost;
        G[src][dest] = cost;
        G[dest][src] = cost;
    }
    
}

void Display(int G[20][20] , int dinh , int canh){
    for (int i = 0; i < dinh ; i++) {
        for (int j=0; j<dinh; j++) {
            cout<<"\t"<<G[i][j];
        }
        cout<<endl;
    }
}

void Prims(int G[20][20] , int dinh , int canh){
    int visited[20] , src , dest =0;
    int  tong=0;
    for (int i=0; i<dinh; i++)
    {
        for (int j =0; j<dinh; j++)
        {
            if (G[i][j]==0)
            {
                G[i][j] = 9999;
            }
        }
    }
    
    for (int i=0; i<dinh; i++) {
        visited[i]=0;
    }
    
    cout<<"Bat dau tu dinh :";
    cin>>src;
    
    visited[src]=1;
    canh = 0;
    
    while (canh < dinh - 1) {
        int min = 9999;
        for (int i =0 ; i<dinh; i++)
        {
            if (visited[i] == 1)
            {
                for (int j =0; j < dinh; j++)
                {
                    if (visited[j] !=1)
                    {
                        if (min > G[i][j])
                        {
                            min = G[i][j];
                            src = i;
                            dest =j;
                        }
                    }
                }
            }
        }
        visited[dest] = 1;
        tong = tong + G[src][dest];
        cout<<"\n Cạnh = "<<src <<"...."<<dest<<"Cost : "<<min;
        canh++;
    }
    cout<<"\n Total Cost :"<<tong;
}

int main(int argc, const char * argv[]) {
    cout<<"Đinh va canh :";cin>>dinh>>canh;
    Accept(G, dinh , canh);
    Display(G, dinh, canh);
    Prims(G, dinh, canh);
    return 0;
}
