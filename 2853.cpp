#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    int n, i, j, sum, cnt, tc, ans;
    cin >> tc;
    while (tc--){ 
        cin >> cnt >> n;
        ans = 0;
        for (i = 2; i*(i+1)/2 <= n; i++){
            if ((n-i*(i+1)/2)%i == 0)
                ans++; 
        } 
        cout << cnt << " " << ans << endl;
    } 
    
}