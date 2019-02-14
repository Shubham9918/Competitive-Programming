#include <bits/stdc++.h>
#include <time.h>


using namespace std;

long calculate_output(int len, vector<int> input){
  long best = 0;
  for(int a = 0; a < len; a++){
    long sum = 0;
    for(int b = a; b < len; b++){
      sum += input[b];
      best = max(best,sum);
    }
  }
  return best;
}

int main(){
  freopen("input.txt","r", stdin);
  freopen("output.2.txt","w", stdout);
  vector<int> input;
  int input_len;
  cout<<"Algorithm 2\n";
  cin>>input_len;
  for(int i = 0; i < input_len; i++){
    int temp;
    cin>>temp;
    input.push_back(temp);
  }
  clock_t s_time = clock();
  long max_sum = calculate_output(input_len, input);
  cout<<"Max_Subarray_Sum : "<<max_sum<<"\n";
  clock_t e_time = clock();
  cout<<"Time taken : "<<(double)(e_time-s_time)/CLOCKS_PER_SEC<<"\n";
  return 0;
}
