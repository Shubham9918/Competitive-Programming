#include <bits/stdc++.h>

using namespace std;

int main(){
    int nts;
    cin>>nts;
    for(int i = 0; i < nts; i++){
      string input;
      cin>>input;
      int temp = 0;
      int len = input.size();
      while(temp < len){
        int n = (int)input[temp] - 48;
        if(n % 2 == 1){
          break;
        }
        temp++;
      }
      if( temp >= len){
        cout<<"Case "<<i+1<<"#: "<<0;
      }
      else{
        string input1 {input};
        string input2 {input};
        if(input1[temp] == '9'){
          while(temp<len){
            input1[temp] = '8';
            temp +=1;
          }
          cout<<"Case "<<i+1<<"#: "<<abs(stoi(input)-stoi(input1));
        }
        else{
          int n = (int)input1[temp] - 48;
          int temp2 {temp};
          input1[temp] = (char)(n-1+48);
          temp +=1;
          while(temp<len){
            input1[temp] = '8';
            temp+=1;
          }
          input2[temp2] = (char)(n+1+48);
          temp2 +=1;
          while(temp2<len){
            input2[temp2] = '0';
            temp2+=1;
          }
          cout<<"Case "<<i+1<<"#: "<<min(abs(stoi(input)-stoi(input1)),abs(stoi(input)-stoi(input2)));
        }
      }
      if(i != nts-1)
        cout<<"\n";
    }
}

// stoi
