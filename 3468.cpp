/*
  Segment Tree (interval add, interval sum)

  Complexity : O(logn)
  Verified : POJ 3468
 */

#include <stdio.h>
#include <vector>
using namespace std;

template<typename T>
class segment_tree{
public:
  segment_tree(int N) : N(N),
			data((1 << 18) - 1, 0),
			datb((1 << 18) - 1, 0) {}

private:
  int N;
  vector<T> data, datb;

  void __add(T x, int idx, int a, int b, int l, int r){
    if(a <= l && r <= b) data[idx] += x;
    else if(l < b && a < r){
      datb[idx] += (min(b, r) - max(a, l)) * x;
      __add(x, 2 * idx + 1, a, b, l, (l + r) / 2);
      __add(x, 2 * idx + 2, a, b, (l + r) / 2, r);
    }
  }
  
  T __sum(int idx, int a, int b, int l, int r){
    if(b <= l || r <= a) return (T)0;
    else if(a <= l && r <= b){
      return data[idx] * (r - l) + datb[idx];
    }else{
      T res = (min(b, r) - max(a, l)) * data[idx];
      res += __sum(idx * 2 + 1, a, b, l, (l + r) / 2);
      res += __sum(idx * 2 + 2, a, b, (l + r) / 2, r);
      return res;
    }
  }

public:
  // [l, r)
  void add(T x, int l, int r){ __add(x, 0, l, r, 0, N); }
  T sum(int l, int r){ return __sum(0, l, r, 0, N); }
};

int main(){
  int N, Q;
  scanf("%d %d", &N, &Q);

  segment_tree<long long> seg(N);
  
  for(int i = 0; i < N; i++){
    int A;
    scanf("%d", &A);
    seg.add(A, i, i + 1);
  }
  getchar();

  for(int i = 0; i < Q; i++){
    char q;
    int l, r, c;
    scanf("%c", &q);
    if(q == 'Q'){
      scanf("%d %d", &l, &r);
      printf("%lld\n", seg.sum(l - 1, r));
    }else{
      scanf("%d %d %d", &l, &r, &c);
      seg.add(c, l - 1, r);
    }
    getchar();
  }
  return 0;
}
