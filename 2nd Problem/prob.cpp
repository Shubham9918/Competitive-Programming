#include <bits/stdc++.h>

using namespace std;

int main(){
  int no_of_dig;
  vector <int> digits;
  freopen("./input.txt","r",stdin);
  freopen("./output.txt","w",stdout);
  cin>>no_of_dig;
  for(int i = 0; i < no_of_dig; i++){
    int temp;
    cin>>temp;
    digits.push_back(temp);
  }
  sort(digits.begin(), digits.end());
  int sum = 0;
  for(int x = 1; x < no_of_dig; x++){
    int i,j;
    int no_of_sub = pow(2,x-1);
    for(i = 0, j = x; j < no_of_dig;i++,j++){
      sum += (no_of_sub * abs(digits[j]-digits[i]));
    }
  }
  cout<<"Sum subset : "<<sum;
}
