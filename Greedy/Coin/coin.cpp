#include <bits/stdc++.h>

using namespace std;

int main(){
  freopen("./input.txt","r",stdin);
  freopen("./output.txt","w",stdout);
  vector <int> coin;
  vector <int> no_of_coin_req;
  int no_of_coin, amount;
  cin>>no_of_coin;
  for(int i = 0; i < no_of_coin; i++){
    int temp;
    cin>>temp;
    coin.push_back(temp);
  }
  sort(coin.begin(), coin.end(), greater<int>());
  cin>>amount;
  for(auto it = coin.begin() ; it != coin.end(); it++){
    if(amount <= 0) break;
    int temp = amount / (int)*it;
    amount = amount % (int)*it;
    no_of_coin_req.push_back(temp);
  }
  int i = 0;
  for(auto it = no_of_coin_req.begin() ; it != no_of_coin_req.end(); it++){
    cout<<coin[i]<<":"<<*it<<"\n";
    i++;
  }
  return 0;
}
