// Time-stamp: <Thu Feb 02 22:46:49 東京 (標準時) 2017>
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


string in;
int pos;
bool ok;

void expo(){
  if(pos==in.size()){
    ok=false;
    return;
  }
  
  if(in[pos]=='+' || in[pos]=='-')++pos;

  if(pos==in.size()){
    ok=false;
    return;
  }
  while(pos<in.size() && isdigit(in[pos]))++pos;

  if(pos==in.size())return;
  ok=false;
}


void decimal(){
  if(pos==in.size()){
    ok=false;
    return;
  }
  if(!isdigit(in[pos])){
    ok=false;
    return;
  }
  
  while(pos<in.size() && isdigit(in[pos]))++pos;
  if(pos==in.size())return;

  if(in[pos]=='e' || in[pos]=='E'){
    ++pos;
    expo();
  }else ok=false;
}

void check(){
  if(in[pos]=='-' || in[pos]=='+')++pos;

  if(!isdigit(in[pos])){
    ok=false;
    return;
  }
  while(pos<in.size() && isdigit(in[pos]))++pos;
  if(pos==in.size()){
    ok=false;
    return;
  }

  if(in[pos]!='.' && in[pos]!='e' && in[pos]!='E'){
    ok=false;
    return;
  }

  if(in[pos]=='.'){
    ++pos;
    decimal();
  }else{
    ++pos;
    expo();
  }
}

int main(){
  while(getline(cin,in)){
    if(in=="*")break;
    while(in.size() && in[0]==' ')in=in.substr(1);
    cout<<in<<" is ";

    pos=0;
    ok=true;
    check();
    if(ok)cout<<"legal."<<endl;
    else cout<<"illegal."<<endl;
  }
}
