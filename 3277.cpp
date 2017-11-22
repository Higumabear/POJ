#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

class RMQ{
  int N;
  vector<ll> min_dat, max_dat;

public:
  RMQ(int n) : N(1) {
    while(N < n) N *= 2;
    //min_dat.assign(2 * N - 1, -1 + (1LL << 31));
    max_dat.assign(2 * N - 1, 0);
  }
  RMQ(vector<int> &arr) : N(1) {
    while(N < arr.size()) N *= 2;
    min_dat.assign(2 * N - 1, -1 + (1LL << 31));
    max_dat.assign(2 * N - 1, 1 - (1LL << 31));
    copy(arr.begin(), arr.end(), min_dat.begin() + N - 1);
    copy(arr.begin(), arr.end(), max_dat.begin() + N - 1);
    for(int i = N - 2; i >= 0; i--){
      min_dat[i] = min(min_dat[2 * i + 1], min_dat[2 * i + 2]);
      max_dat[i] = max(max_dat[2 * i + 1], max_dat[2 * i + 2]);
    }
  }

  void update(int a, int b, int val){ update(a, b, 0, 0, N, val); }
  void update(int a, int b, int k, int l, int r, ll val){
    if(r <= a || b <= l) return;
    if(a <= l && r <= b){
      //min_dat[k] = min<ll>(min_dat[k], val);
      max_dat[k] = max(max_dat[k], val);
      return;
    }
    update(a, b, 2 * k + 1, l, (l + r) / 2, val);
    update(a, b, 2 * k + 2, (l + r) / 2, r, val);
    return;
  }
  int min_query(int a, int b){ return min_query(a, b, 0, 0, N); }
  int min_query(int a, int b, int k, int l, int r){
    if(r <= a || b <= l) return -1LL + (1LL << 31);
    if(a <= l && r <= b) return min_dat[k];
    return min(min_query(a, b, 2 * k + 1, l, (l + r) / 2),
	       min_query(a, b, 2 * k + 2, (l + r) / 2, r));
  }
  ll max_query(int a, int b){ return max_query(a, b, 0, 0, N); }
  ll max_query(int a, int b, int k, int l, int r){
    if(r <= a || b <= l) return 1LL - (1LL << 31);
    if(a <= l && r <= b) return max_dat[k];
    return max(max_query(a, b, 2 * k + 1, l, (l + r) / 2),
	       max_query(a, b, 2 * k + 2, (l + r) / 2, r));
  }
  ll query(int k){
    k += N - 1;
    ll ret = max_dat[k];
    while(k > 0){
      k = (k - 1)/2;
      ret = max(ret, max_dat[k]);
    }
    return ret;
  }
};


vector<int> num;
//map<int, int> enc;
int f[40001], s[40001], h[40001];

int enc(int a){
  return lower_bound(num.begin(), num.end(), a) - num.begin();
}

int main(int argc, char **argv){
  int N;
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    scanf("%d %d %d", f + i, s + i, h + i);
    num.push_back(f[i]);
    num.push_back(s[i]);
  }

  sort(num.begin(), num.end());
  num.erase(unique(num.begin(), num.end()), num.end());
  //for(int i = 0; i < num.size(); i++) enc[num[i]] = i;
  
  RMQ rmq(80001);
  for(int i = 0; i < N; i++)
    rmq.update(enc(f[i]), enc(s[i]), h[i]);

  long long ans = 0LL;
  for(int i = 0; i < num.size() - 1; i++){
    //printf("%d %d %lld\n", num[i], num[i + 1], rmq.max_query(i, i + 1));
    ans += (num[i + 1] - num[i]) * rmq.query(i);
  }
  printf("%lld\n", ans);
  return 0;
}

