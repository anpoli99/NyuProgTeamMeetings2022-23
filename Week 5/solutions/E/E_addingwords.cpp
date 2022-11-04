#include <bits/stdc++.h>
using namespace std;

// Each string is a line of input
// You can split the line into strings using the stringstream class:
// stringstream ss(line);
// vector<string> words;
// string word;
// while(ss >> word) words.push_back(word);

#define UNKNOWN 0x7fffffff
vector<string> adding_words(vector<string>& lines){
    vector<string> result;
    unordered_map<string, int> variables; // We can use a map to store the variables
    unordered_map<int, string> values;
    for(auto line : lines){
        stringstream ss(line);
        string word;
        ss >> word;
        if(word == "clear"){
            variables.clear();
            values.clear();
        }else if(word == "def"){
            string var;
            ss >> var;
            int value;
            ss >> value;
            if(variables.count(var)){
                values.erase(values.find(variables[var]));
            }
            variables[var] = value;
            values[value] = var;
        }else{ // word == "calc"
            string equation = line.substr(5); // It wants the whole equation too, but that's just part of the original line
            bool sub = 0;
            int value = 0;
            string var, op;
            while(ss >> var >> op){
                if(!variables.count(var)){
                    value = UNKNOWN;
                    break;
                }
                if(sub){
                    value -= variables[var];
                }else{
                    value += variables[var];
                }
                sub = op == "-";
            }
            if(!values.count(value)){
                value = UNKNOWN;
            }
            if(value == UNKNOWN){
                result.push_back(equation + " unknown");
            }else{
                result.push_back(equation + " " + values[value]);
            }
        }
    }
    return result;
}
int main(){
    // Makes cin and cout faster by removing the synchronization between the C and C++ standard streams.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    vector<string> lines;
    while(getline(cin, line)){
        if(line == "#") break; // This is a useful way to debug
        lines.push_back(line);
    }
    vector<string> result = adding_words(lines);
    for(auto line : result){
        cout << line << '\n';
    }
}