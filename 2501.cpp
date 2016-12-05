// Time-stamp: <Sat Nov 12 12:12:06 東京 (標準時) 2016>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>
#include <iomanip>

typedef long long ll;
#define INF 1 << 29
#define LLINF 1LL << 60
#define EPS 1e-6
#define ALL(c) (c).begin(), (c).end()
#define CNT(c,x) count(ALL(c),x)
#define dump(x)  cerr << #x << " = " << (x) << endl;
template<typename A, size_t N, typename T>
void FILL(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

using namespace std;

int main(int argc, char **argv){
  string s;
  double velocity;
  int ph = 0, pm = 0, ps = 0;
  double sum = 0;
  while(getline(cin, s)){
    stringstream ss(s);
    vector<string> data;
    while(ss >> s) data.push_back(s);
    
    int h, m, s;
    sscanf(data[0].c_str(), "%d:%d:%d", &h, &m, &s);
    sum += (((h - ph) * 60 + (m - pm)) * 60 + (s - ps)) * velocity / 3600.0;
    if(data.size() == 2)
      sscanf(data[1].c_str(), "%lf", &velocity);
    else{
      printf("%s %.2f km\n", data[0].c_str(), sum);
      //cout << data[0] << " " << setprecision(2) << sum << " km" << endl;
    }
    ph = h, pm = m, ps = s;
  }
  return 0;
}
