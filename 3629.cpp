#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int main(int argc, char **argv){
  int N, K, P;
  cin >> N >> K >> P;

  queue<int> Q;
  for(int i = 1; i <= K; i++) Q.push(i);
  
  vector<int> Bessie;
  for(int i = 1; i <= K; i++){
    int t = Q.front(); Q.pop();
    if(i % N == 0){
      Bessie.push_back(t);
    }

    for(int p = 0; p < P; p++){
      int tmp = Q.front(); Q.pop();
      Q.push(tmp);
    }
  }
 
  sort(Bessie.begin(), Bessie.end());
  for(int i = 0; i < (int)Bessie.size(); i++) cout << Bessie[i] << endl;
  return 0;
}