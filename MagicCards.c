#include <iostream>
using namespace std;
//declare global variable 
int k = 0, Something;
const int deck_size = 21;
const int split_size = (deck_size/3);
int cards[deck_size]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int card1[split_size], card2[split_size], card3[split_size];
//for printing from an array for x# of value per line
void PrintArray(int n,int x, int id){
  switch(id){
    case 1: cout <<card1[k]; break;
    case 2: cout <<card2[k]; break;
    case 3: cout <<card3[k]; break;
    case 4: cout <<cards[k]; break;
  }
  for (int i =1; i< x; i++){
  ++k;
    switch(id){
    case 1: cout <<", "<<card1[k]; break;
    case 2: cout <<", "<<card2[k]; break;
    case 3: cout <<", "<<card3[k]; break;
    case 4: cout <<", "<<cards[k]; break;
    }
  }
  cout <<endl;
  ++k;
  if(k<n){
    PrintArray(n, x, id);
  }else{
    k = 0;
  }
}
//Press 0 to begin
void Begin(){
  int n;
  cout <<"Press 0 to begin"<<endl;
  cin >> n;
  if (n==0){
    return;
  }else{
    Begin();
  }
}
//Split the deck into 3
void Split(){
  int e=0, f = 1, g = 2; // e start 0, then 3- f 1,4 - g 2,5//
  for(int i=0; i<7; i++){
    card1[i]=cards[e];
    card2[i]=cards[f];
    card3[i]=cards[g];
    e=e+3;
    f=f+3;
    g=g+3;
  }
}
int main() {
  PrintArray(deck_size , 7, 4);
  cout <<"Think of a number from the displayed values"<<endl;
  Begin();
  Split();
  for(int l = 0; l < 3; l++){
    cout <<"Pile 1"<<endl;
    PrintArray(split_size , 7, 1);
    cout <<"Pile 2"<<endl;
    PrintArray(split_size , 7, 2);
    cout <<"Pile 3"<<endl;
    PrintArray(split_size , 7, 3);
    cout <<"Which pile is the number in?"<<endl;
    cin >> Something;
    if (Something > 0 && Something <= 3){
      switch(Something){
        case 1:
        for(int i = 0; i < 21; i++){
            if(i<=6) cards[i]=card3[i];
            else if(i>13) cards[i]=card2[i-14];
            else cards[i]=card1[i-7];
        
        };break;
        case 2:
          for(int i = 0; i < 21; i++){
            if(i<=6) cards[i]=card1[i];
            else if(i>13) cards[i]=card3[i-14];
            else cards[i]=card2[i-7];
          };break;
        case 3:
          for(int i = 0; i < 21; i++){
            if(i<=6) cards[i]=card1[i];
            else if(i>13) cards[i]=card2[i-14];
            else cards[i]=card3[i-7];
          };break;
      }
    }else{
      cout <<"Only pick piles that exist!"<<endl;
      cout <<"Enter again"<<endl;
      l--;
    } 
  Split();
  }
  cout <<"Your number is "<< cards[10]<<endl; 
}