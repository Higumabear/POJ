#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define INF 1 << 29

int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};

int main(int argc, char **argv){
  vector<vector<int> > d(8 * 8, vector<int>(8 * 8, INF));
  for(int i = 0; i < 64; i++) d[i][i] = 0;
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      for(int k = 0; k < 8; k++){
	int ny = i + dy[k], nx = j + dx[k];
	if(0 <= ny && ny < 8 && 0 <= nx && nx < 8)
	  d[i * 8 + j][ny * 8 + nx] = 1;
      }
    }
  }
  for(int k = 0; k < 64; k++)
    for(int i = 0; i < 64; i++)
      for(int j = 0; j < 64; j++)
	d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

  string s, t;
  while(cin >> s >> t){
    int to = (s[0] - 'a') * 8 + s[1] - '1';
    int from = (t[0] - 'a') * 8 + t[1] - '1';
    cout << "To get from " << s << " to " << t << " takes "
	 << d[to][from] << " knight moves." << endl;
  }
  return 0;
}