#include<bits/stdc++.h>
#include "Trie.hpp"
using namespace std;



vector<int> filter(string pattern, string text, int k, int n){
    vector<int> res;
    int len=n/(k+1);
    // divide n into k+1 parts


    // create Trie for the text
    Trie* MyTrie = new Trie();
    MyTrie->create(text);

    // trie created now search for exact matcches of substrings of size l
    // cout << pattern.length()-l << "\n";
    for(int i=0;i<pattern.length()-len+1;i++){
        //i is starting index for pattern substring
        // cout << i << " " << l << "\n";
        cout << pattern.substr(i,len) << "\n";

        for(int it: MyTrie->search(pattern.substr(i,len))){
            for(int j=max(0,it+len-n);j<min(int(text.length()),it+n);j++){
                res.push_back(j);
            }
        }
    }
    return res;
}

void ApproxPatternMatching(string p, string t, int k, vector<int> filtered, int n, int isnotFiltered){
    vector<pair<int,string>> v;
    if(isnotFiltered){
        int n = p.length();
        int m = t.length();
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
            cout << v[i].first << " " << v[i].second << "\n";
        }
    }
    else{
        // same matching algo

        set<string> st;
        for(int i=0;i<filtered.size();i++){
            if(filtered[i]+n>=t.length()){
                continue;
            }
            // 
            // t is text
            // string is okay and can be matched
            for(int start=0;start<p.length()-n+1;start++){
                // cout << "Currently matching " << p.substr(start,n) << "\n";
                for(int j=0;j<n;j++){
                    int dist=0;
                    if(p[start+j]!=t[filtered[i]+j]){
                        dist++;
                    }
                    if(dist<=k){
                        st.insert(t.substr(filtered[i],n));
                    }

                }
            }
        }
        cout << "Matches\n";    
        for(auto it:st){
            cout << it << "\n";
        }    
    }
}

void QueryMatching(string pattern, string text, int k, int n){
    int m = pattern.length();
    for(int i=0;i<m-n+1;i++){
        string sample = pattern.substr(i,n);
        cout << "Currently matching substring " << sample << " in query string\n";
        ApproxPatternMatching(sample,text,k,vector<int>(),n,1);
    }

}


int main(){
    int k,n;
    string pattern,text;
    cin >> pattern;
    cin >> text;
    cin >> k >> n;
    QueryMatching(pattern,text,k,n);
    vector<int> temp = filter(pattern,text,k,n);
    // for(auto it:temp) cout << it << "\n";
    ApproxPatternMatching(pattern,text,k,temp,n,0);

    // Trie* MyTrie = new Trie();
    // MyTrie->create(text);

    // vector<int> ans = MyTrie->search("asd");
    // for(int i=0;i<ans.size();i++) cout << ans[i] << " ";
    // cout << "\n";
    //  MyTrie->search("hi");

}