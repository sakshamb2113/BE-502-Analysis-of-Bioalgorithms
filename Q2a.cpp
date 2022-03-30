#include<bits/stdc++.h>
using namespace std;


void ApproxPatternMatching(string p, string t, int k){
    int n = p.length();
    int m = t.length();
    vector<pair<int,string>> v;
    for(int i=0;i<m-n+1;i++){
        int dist=0;
        for(int j=0;j<n;j++){
            if(t[i+j]!=p[j]){
                dist=dist+1;
            }
        }
        if(dist<=k){
            v.push_back({i,t.substr(i,n)});
        }

    }

    cout << "Matches:\n";
    for(int i=0;i<v.size();i++){
        cout << v[i].first+1 << " " << v[i].second << "\n";
    }
}

int main(){
    string pattern, text;
    int k;
    cin >> text;
    cin >> pattern;
    cin >> k;
    ApproxPatternMatching(pattern, text, k);
}