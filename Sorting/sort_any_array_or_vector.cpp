#include <bits/stdc++.h>

using namespace std;

int main(){
  int array[] {12,3,15,20,-10,17,-5,7};
  vector <int> vec = {12,3,15,20,-10,17,-5,7};
  vector <string> str_vec = {"xyz","abc","mno","pqr"};
  // For Soting any array/vector use built in function sort()
  sort(array,array+8);
  sort(vec.begin(), vec.end());
  sort(str_vec.begin(), str_vec.end());
  cout<<"Sorted array :\n";
  for(auto x : array)
    cout<<x<<" ";
  cout<<"\nSorted int vector : \n";
  for(auto x : vec)
    cout<<x<<" ";
  cout<<"\nSorted string vector : \n";
  for(auto x : str_vec)
    cout<<x<<" ";
  cout<<"\nGood Bye...\n";
}
