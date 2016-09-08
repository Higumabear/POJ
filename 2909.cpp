#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

template<typename A, size_t N, typename T> inline void FILL(A (&array)[N], const T &val){ std::fill( (T*)array, (T*)(array+N), val );}

bool sieve[1 << 16];

int main(int argc, char **argv){
  FILL(sieve, true);
  sieve[0] = sieve[1] = false;
  for(int i = 2; i <= 1 << 15; i++)
    for(int j = 2 * i; j <= 1 << 15; j += i)
      sieve[j] = false;

  int n;
  while(cin >> n, n){
    int cnt = 0;
    for(int i = 2; i <= n - i; i++)
      cnt += (sieve[i] && sieve[n - i]);
    cout << cnt << endl;
  }
}
