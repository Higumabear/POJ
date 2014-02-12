#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
  double a, b, c;
  while(cin >> a >> b >> c){
    if(a == 0 && b == 0 && c == 0) break;

    vector<string> ans;
    
    if(a <= 4.5 && b >= 150 && c >= 200)
      ans.push_back("Wide Receiver");
    if(a <= 6.0 && b >= 300 && c >= 500)
      ans.push_back("Lineman");
    if(a <= 5.0 && b >= 200 && c >= 300)
      ans.push_back("Quarterback");

    if(ans.empty())
      cout << "No positions" << endl;
    else{
      int i = 0; 
      for(i = 0; i < ans.size() - 1; i++){
	cout << ans[i] << " ";
      }
      cout << ans[i] << endl;
    }
  }
}