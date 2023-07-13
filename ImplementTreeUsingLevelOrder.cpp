#include <bits/stdc++.h>
using namespace std;



void dfs(map<int,int> &mp, vector<int> &store){
    if()
}


vector<vector<int>> f1(map<int,int> &mp){
    vector<vector<int>> ans;
    
}

void solve(map<int,int> &mp){
    vector<vector<int>> ans = f1(mp);

    for(auto &vec: ans){
        for(auto &ele: vec){
            cout << ele << " ,";
        }
        cout << endl;
    }
}

int main()
{

    map<int, int> par;
    par[1] = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        par[u] = v;
    }
    for (auto &it : par)
    {
        cout << it.second << "->" << it.first << endl;
    }

    solve(par);
}