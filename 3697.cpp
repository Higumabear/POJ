#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "cmath"
#include "cctype"
#include "vector"
#include "set"
#include "map"
#include "string"
#include "algorithm"
#include "stack"
#include "queue"

#define INF 0x7fffffffffffffff
#define reset(a) memset(a, 0, sizeof(a))
#define copy(a, b) memcpy(a, b, sizeof(b))
#define FMAX (1E300)
#define MAX 1000000000
#define feq(a, b) (fabs((a)-(b))<1E-6)
#define flq(a, b) ((a)<(b)||feq(a, b))
#define MAXN 10005
#define BASE 137
#define PASS puts("pass")
#define filein freopen("test.in", "r", stdin)
#define fileout freopen("test.out", "w", stdout)
#define eps 1e-4
#define max2(a, b) ((a) > (b) ? (a) : (b))
#define min2(a, b) ((a) < (b) ? (a) : (b))

using namespace std;

//set<int> con[10001];
priority_queue<int, vector<int>, greater<int> > con[10001];
set<int> ns;
set<int>::iterator it;
bool vis[10001];
queue<int> Q;

void init(int n){
    ns.clear();
    while (Q.size())
        Q.pop();
    Q.push(1);
    for (int i = 2; i <= n; i++){
        while (con[i].size())
            con[i].pop();
        //con[i].clear();
        vis[i] = false;
        ns.insert(i);
    }
    while (con[1].size())
        con[1].pop();
    //con[1].clear();
    vis[1] = true;
    //PASS;
}

int main(){
    //filein;
    int Case = 0;
    int n, m;
    int a, b;

    while (~scanf("%d%d", &n, &m) && (m || n)){
        init(n);
        //PASS;
        while (m--){
            scanf("%d%d", &a, &b);
            con[a].push(b);
            con[b].push(a);
        }
        //PASS;
        while (Q.size()){
            int cur = Q.front();

            Q.pop();
            //PASS;
            for (it = ns.begin(); it != ns.end();){
                int i = *it;

                while (con[cur].size() && con[cur].top() < i)
                    con[cur].pop();
                //if (!con[cur].count(i)){
                if (!con[cur].size() || i != con[cur].top()){
                    if (!vis[i]){
                        Q.push(i);
                        vis[i] = true;
                    }
                    ns.erase(it++);
                }
                else
                    it++;
            }
        }

        int cnt = 0;

        for (int i = 2; i <= n; i++)
            cnt += vis[i];

        printf("Case %d: %d\n", ++Case, cnt);
    }

    return 0;
}