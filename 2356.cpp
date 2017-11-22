#include <iostream>
#include <algorithm>

using namespace std;

int a[10001];
int s[10001];

int main(){
  int N; cin >> N;
  int sum = 0;
  fill(s, s + N, -1);

  int i;
  for(i = 0; i < N; i++){
    cin >> a[i];
    sum += a[i];
    sum %= N;

    if(sum == 0){
      cout << i + 1 << endl;
      for(int j = 0; j <= i; j++)
	cout << a[j] << endl;
      break;
    }
    if(s[sum] == -1) s[sum] = i;
    else{
      cout << i - s[sum] << endl;
      for(int j = s[sum] + 1; j <= i; j++)
	cout << a[j] << endl;
      break;
    }
  }
  for(; i + 1 < N; i++) cin >> a[i];
}
