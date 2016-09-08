#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

template<typename A, size_t N, typename T> inline void FILL(A (&array)[N], const T &val){ std::fill( (T*)array, (T*)(array+N), val );}

bool sieve[1000001];

int main(int argc, char **argv){
  FILL(sieve, true);
  sieve[0] = sieve[1] = false;
  for(int i = 2; i <= 1000000; i++)
    for(int j = 2 * i; j <= 1000000; j += i)
      if(sieve[i]) sieve[j] = false;

  int a, d, n;
  while(cin >> a >> d >> n, a + d + n){
    int t = a;
    while(1){
      if(sieve[t]) n--;
      if(n == 0) break;
      else t += d;
    }
    cout << t << endl;
  }
}
