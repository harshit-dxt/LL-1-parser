#include<fstream>
#include<iostream>
#include<string.h>
#include<set>
#include<map>
#include<vector>
using namespace std;

void getGrammarToken(map<string, vector<string>> &non_terminals, string INTERMEDIATE){
    ifstream ifs;
    ifs.open((INTERMEDIATE+"trimmed.txt"), fstream::in);
    char c;
    string s = "", non_terminal;
    while(ifs.get(c)){
        if(c==';'){
            non_terminals[non_terminal].push_back(s);
            s = "";
        }
        else if(c==':'){
            non_terminal = s;
            non_terminals[s] = vector<string>();
            s = "";
        }
        else if(c=='|'){
            non_terminals[non_terminal].push_back(s);
            s ="";
        }
        else{
            s+=c;
        }
    }
    
}

void trim(string INTERMEDIATE){
    ifstream ifs;
    ifs.open(("grammar.txt"), fstream::in);
    ofstream ofs;
    ofs.open((INTERMEDIATE+"trimmed.txt"), fstream::out);
    char c;
    while(ifs.get(c)){
        if(!isspace(c))
            ofs << c;
    }
}

int main(){
    string INTERMEDIATE = "./intermediate/";
    map<string, vector<string>> non_terminals;
    trim(INTERMEDIATE);
    getGrammarToken(non_terminals, INTERMEDIATE);
    for(auto it = non_terminals.begin(); it != non_terminals.end(); ++it){
        vector<string> v = it->second;
        for(int i = 0; i < v.size(); ++i){
            cout << v[i] << endl;
        }
    }
    return 0;
}