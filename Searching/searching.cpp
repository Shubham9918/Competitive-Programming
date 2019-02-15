#include <bits/stdc++.h>

using namespace std;

int main(){
  vector <int> int_vec = {10,20,13,15,-10,14};
  vector <string> str_vec = {"abc", "xyz", "mno"};
  freopen("output.txt", "w", stdout);
  auto int_pos  =  find(int_vec.begin(),int_vec.end(), -10);
  auto str_pos = find(str_vec.begin(), str_vec.end(), "xyz");
  cout<<int_pos-int_vec.begin()<<"\n";
  cout<<str_pos-str_vec.begin()<<"\n";
  cout<<"Good Bye....\n";
  return 0;
}
