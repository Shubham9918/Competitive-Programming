#include <bits/stdc++.h>

#define PUB(vec,val) vec.push_back(val)
#define POB(vec) vec.pop_back()

using namespace std;

int compute_output(){
  int n,k,temp;
  vector <int> Ai;
  vector <int> AiC;
  cin>>n>>k;
  for(int i = 0; i < n; i++){
    cin>>temp;
    PUB(Ai,temp);
  }
  sort(Ai.begin(),Ai.end());
  int i = 0, u = 0;
  int size = (int)Ai.size();
  while(i < size){
    int t = Ai[i];
    int c = count(Ai.begin(), Ai.end(), t);
    int r = t * k - u - c;
    if(r>=0)
      u += c;
    else
      u += k;
    i += c;
  }
  return u;
}

int main(){
  int nt;
  cin>>nt;
  for(int i = 0; i < nt; i++){
    int count = compute_output();
    cout<<"Case #"<<i+1<<": "<<count;
    if(i != nt-1)
      cout<<"\n";

  }
  return 0;
}
