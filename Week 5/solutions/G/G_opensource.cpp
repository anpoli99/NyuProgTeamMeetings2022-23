#include <bits/stdc++.h>
using namespace std;

vector<pair<string,int>> opensource(vector<string>& lines){
    vector<pair<string,int>> ans;
    // We'll use this to store the users for each projects:
    unordered_map<string, unordered_set<string>> members;
    // We'll use this to store how many projects each user is in:
    unordered_map<string, int> user_projects;

    vector<string> projects = {lines[0]};
    string current = lines[0];
    for(int i = 1; i < lines.size(); i++){
        bool is_new_project = false;
        for(char c : lines[i]){
            is_new_project |= isupper(c);
        }
        if(is_new_project){
            current = lines[i];
            projects.push_back(current);
        }else if(!members[current].count(lines[i])){
            members[current].insert(lines[i]);
            user_projects[lines[i]]++;
        }
    }
    for(string s : projects){
        int ct = 0;
        for(string t : members[s]){
            ct += user_projects[t] == 1;
        }
        ans.push_back({s, ct});
    }
    sort(ans.begin(), ans.end(), [](pair<string,int> a, pair<string,int> b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second > b.second;
    });
    return ans;
}

int main(){
    string s;
    vector<string> lines;
    while(true){
        getline(cin, s);
        if(s == "1"){
            auto ans = opensource(lines);
            for(auto p : ans){
                cout << p.first << ' ' << p.second << '\n';
            }
            lines.clear();
        }else if(s == "0"){
            break;
        }else{
            lines.push_back(s);
        }
    }
}