#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int song[2000];

int main(int argc, char **argv){
  int N, T;
  cin >> N >> T;
  for(int i = 0; i < N; i++) cin >> song[i];
  int prev = 100000000;
  for(int i = 0; i < T; i++){
    int maxrate = 0;
    for(int j = 0; j < N; j++){
      if(j != prev && maxrate < song[j]){
	prev = j;
	maxrate = song[j];
      }
    }
    song[prev] = 0;
    cout << prev + 1 << endl;
    int rem = maxrate % (N - 1);
    int dist = maxrate / (N - 1);
    for(int j = 0; j < N; j++){
      if(prev != j) song[j] += dist;
    }

    int j = 0;
    while(rem--){
      if(prev == j) rem++;
      else song[j]++;

      j++;
    }
  }
  return 0;
}