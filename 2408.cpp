#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef set <string> tSet;        // group members
typedef tSet::iterator tSetIt;

typedef map <string, tSet> tMapSet;  // string: unique identifier for group
typedef tMapSet::iterator tMapSetIt;

typedef map <string, int> tMapInt;   // nr of words
typedef tMapInt::iterator tMapIntIt;

typedef pair <int, string> tPair; // nr of element, smallest element in group
typedef vector <tPair> tVecAna;

tMapSet ms;
tMapInt mi;
tVecAna a;

int main() {
  string s, ss;
  while (cin >> s) {
    ss = s;
    sort(ss.begin(), ss.end());

    if (ms.find(ss) == ms.end()) { // new anagram group
      ms[ss].insert(s);
      mi[ss] = 1;
      continue;
    }

    if (ms[ss].find(s) == ms[ss].end()) // new element for existing group
      ms[ss].insert(s);
    
    mi[ss]++;
  }

  // prepare for sorting (note the -, so I can use the std sort)
  for (tMapSetIt it = ms.begin(); it != ms.end(); it++ )
    a.push_back( tPair( -mi[(*it).first] , *((*it).second.begin())) );
 
  // sort according to prob set
  sort(a.begin(), a.end());

  for (int i=0; i<5 && i < a.size(); i++) {
    cout << "Group of size " << -a[i].first << ": ";
    ss = a[i].second;
    sort(ss.begin(), ss.end()); // get back unique id
    for (tSetIt jt = ms[ss].begin(); jt != ms[ss].end(); jt++)
      cout << (*jt) << " ";
    cout <<"." << endl;
  }

  return 0;
}
