// Time-stamp: <Sat Jan 28 03:43:32 東京 (標準時) 2017>
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

typedef pair<int,int> P;

#define REP(i,n,m) for(int i=n;i<m;i++)
#define rep(i,n) REP(i,0,n)

class State{
public:
  int a,b;
  vector<P> v;

  State(){}
  State(int _a,int _b,vector<P> _v){
    a = _a;
    b = _b;
    v = _v;
  }
};

int a,b,c;

void solve(){
  queue<State> open;
  bool closed[102][102];
  open.push(State(0,0,vector<P>()));
  memset(closed,0,sizeof(closed));

  vector<P> ans;

  while(!open.empty()){
    State st = open.front(); open.pop();
    if(closed[st.a][st.b]) continue;
    closed[st.a][st.b] = true;

    if(st.a == c || st.b == c){
      ans = st.v;
      break;
    }

    //FILL(1)
    int idx = st.v.size();
    st.v.push_back(P(0,1));
    open.push(State(a,st.b,st.v));

    //FILL(2)
    st.v[idx] = P(0,2);
    open.push(State(st.a,b,st.v));

    //DROP(1)
    st.v[idx] = P(0,-1);
    open.push(State(0,st.b,st.v));

    //DROP(2)
    st.v[idx] = P(0,-2);
    open.push(State(st.a,0,st.v));

    int A = st.a;
    int B = st.b;

    //POUR(1,2)
    st.v[idx] = P(1,2);
    open.push(State(max(0,A-(b-B)), min(b,B+A),st.v));

    //POUR(2,1)
    st.v[idx] = P(2,1);
    open.push(State(min(a,A+B), max(0,B-(a-A)),st.v));
  }

  if(ans.empty()){
    cout<<"impossible\n";
  }
  else{
    cout<<ans.size()<<endl;
    rep(i,ans.size()){
      if(ans[i].first > 0){
        printf("POUR(%d,%d)\n",ans[i].first,ans[i].second);
      }
      else if(ans[i].second > 0){
        printf("FILL(%d)\n",ans[i].second);
      }
      else{
        printf("DROP(%d)\n",-ans[i].second);
      }
    }
  }
}

int main(){
  cin>>a>>b>>c;
  solve();
}
