#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(int argc, char **argv){
  vector<int> sum(102, 0);
  string a;
  while(cin >> a, a != "0"){
    int N = a.length();
    for(int i = 0; i < N; i++){
      int sumdigit = sum[i] + (a[N - i - 1] - '0');
      sum[i] = sumdigit % 10;
      sum[i + 1] += sumdigit / 10;
      for(int j = 0; j < 100; j++){
	sum[j + 1] += sum[j] / 10;
	sum[j] %= 10;
      }
    }
  }
  int pos;
  for(pos = 101; pos >= 0; pos--) if(sum[pos] != 0) break;
  for(int i = pos; i >= 0; i--){
    cout << sum[i];
  }
  cout << endl;
  return 0;
}