// コンパイル : c++ distance.cpp
// 実行 : ./a.out

#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

const int ArraySize = 10;
// テニスコート, 1-6号館, 正門, 東門 = 9?

int main(void) {
  int n;
  double dist[ArraySize][ArraySize];
  int start=ArraySize*2, relay=ArraySize*2, end=ArraySize*2;
  set<int> relayS;

  // Input
  cout<<"施設数 : ";
  cin>>n;
  if(n>ArraySize) {
    cout<<"施設数は  "<<ArraySize<<" 以下です."<<endl;
  }
  //cout<<n<<endl;

  for(int i=0; i<n; i++) {
    for(int j=i; j<n; j++) {
      if(i == j) {
	dist[i][j] = 0.0;
      }
      else {
	printf("distance[%d][%d] = ", i, j);
	cin>>dist[i][j];
	if(i!=j) {
	  dist[j][i] = dist[i][j];
	}
      }
    }
  }

  // どこからどこまでどこ経由で
  cout<<"経由施設のある場所 (-1で終了) : ";
  int tmp;
  cin>>tmp;
  do {
    if(tmp < n) {
      relayS.insert(tmp);
    }
    else {
      cout<<"範囲外の施設番号です. 入力を無効とします."<<endl;
    }
    cin>>tmp;
  } while(tmp>=0);
  do {
    cout<<"開始位置 : ";
    cin>>start;
  }while(start>n);
  do {
    cout<<"目的地 : ";
    cin>>end;
  }while(end>n);

  // Calc
  int cut = -10;
  int distMin = 999999;
  for(int i=0; i<ArraySize; i++) {
    if(relayS.find(i)!=relayS.end()) {
      if(dist[start][i]+dist[i][end] < distMin) {
	cut = i;
	distMin = dist[start][i]+dist[i][end];
      }
    }
  }
  if(cut == -10) {
    cout<<"error"<<endl;
  }
  else {
    cout<<start<<" から "<<end<<" までは "<<cut<<" 経由が最短です."<<endl;
  }

}
