#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

template<typename A, size_t N, typename T> inline void FILL(A (&array)[N], const T &val){ std::fill( (T*)array, (T*)(array+N), val );}

bool sieve[10100];

int main(int argc, char **argv){
  FILL(sieve, true);
  sieve[0] = sieve[1] = false;
  for(int i = 2; i <= 10000; i++)
    for(int j = 2 * i; j <= 10000; j += i)
      sieve[j] = false;

  vector<int> p;
  p.push_back(0);
  for(int i = 0; i <= 10000; i++)
    if(sieve[i]) p.push_back(i);
  for(int i = 1; i < p.size(); i++)
    p[i] += p[i - 1];
  
  int n;
  while(cin >> n, n){
    int cnt = 0;
    for(int i = 0; i < p.size(); i++)
      for(int j = 0; j < i; j++)
	if(p[i] - p[j] == n) cnt++;
    cout << cnt << endl;
  }
}