// Time-stamp: <Tue Nov 08 22:19:30 東京 (標準時) 2016>
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

double s2d(string s){
  stringstream ss(s);
  double x;
  ss >> x; return x;
}

int main(int argc, char **argv){
  vector<string> non;
  while(1){
    string A, R;
    string U, V;
    string s;
    getline(cin, s);

    stringstream ss(s);
    ss >> A >> U >> R;
    V = s.substr(A.size() + R.size() + U.size() + 3);
    
    if(s2d(A) < 0.0) break;
    if(s2d(A) / s2d(R) < 0.01) non.push_back(V);
    else
      printf("%s %.1f %s %.0f%%\n",
	     V.c_str(), s2d(A),
	     U.c_str(), (100.0 * s2d(A) / s2d(R)));
      // cout << V.c_str() << " " 
      // 	   << fixed << setprecision(1) << s2d(A) << " "
      // 	   << U.c_str() << " "
      // 	   << (int)(100.0 * s2d(A) / s2d(R)) << "%" << endl;
  }
  cout << "Provides no significant amount of:" << endl;
  for(int i = 0; i < non.size(); i++) cout << non[i] << endl;
  return 0;
}