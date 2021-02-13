#include<fstream>
#include<iostream>
#include<string.h>
#include<set>
#include<map>
#include<unordered_map>
#include<vector>
using namespace std;

#define INTERMEDIATE string("./intermediate/")
#define EPSILON string("epsilon")

void eliminate_left_recursion(map<string, vector<string>> &non_terminals){
    ofstream ofs;
    ofs.open((INTERMEDIATE+"left_recursion_eliminated.txt"), fstream::out);

    map<string, vector<string>> finals;
    for(auto it = non_terminals.begin(); it != non_terminals.end(); ++it){
        string non_terminal = it->first;
        vector<string> productions = it->second;
        vector<string> alpha;
        vector<string> beta;
        bool left_recursive = false;
        for(int i = 0; i < productions.size(); ++i){
            if(productions[i].find(non_terminal) == 0){
                alpha.push_back(productions[i].substr(non_terminal.length()));
                left_recursive = true;
            }
            else{
                beta.push_back(productions[i]);
            }
        }
        if(left_recursive){
            finals[non_terminal+"\'"].push_back("epsilon");
            if(beta.size() == 0){
                finals[non_terminal].push_back(non_terminal+"\'");
            }
            for(int i = 0; i < beta.size(); i++){
                finals[non_terminal].push_back(beta[i]+non_terminal+"\'");
            }
            for(int i = 0; i < alpha.size(); i++){
                finals[non_terminal+"\'"].push_back(alpha[i]+non_terminal+"\'");
            }
        }
        else{
            finals[non_terminal] = productions;
        }
    }
    non_terminals = finals;

    for(auto it = non_terminals.begin(); it != non_terminals.end(); ++it){
        vector<string> v = it->second;
        ofs << it->first << ":";
        for(int i = 0; i < v.size()-1;++i){
            ofs << v[i] << "|";
        }
        ofs << v[v.size()-1] << ";\n";
    }
    ofs.close();
}

void eliminate_left_factoring(map<string, vector<string>> non_terminals){
    ofstream ofs;
    ofs.open((INTERMEDIATE+"left_recursion_eliminated.txt"), fstream::out);

    
}

void getFirst(map<string, set<string>> &first, map<string, vector<string>> non_terminals, string current){
    for(auto it = non_terminals.begin(); it != non_terminals.end(); ++it){
        string x = it->first;
        vector<string> productions = it->second;
        if(productions[0].compare(EPSILON)){
            first[x].insert(EPSILON);
        }
    }
}

void acceptGrammar(map<string, vector<string>> non_terminals, string current){

}

void getGrammarToken(map<string, vector<string>> &non_terminals){
    ifstream ifs;
    ifs.open((INTERMEDIATE+"trimmed.txt"), fstream::in);
    char c;
    string s = "", non_terminal;
    while(ifs.get(c)){
        if(c=='\n') continue;
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
    ifs.close();
}

void trim(){
    ifstream ifs;
    ifs.open(("grammar.txt"), fstream::in);
    ofstream ofs;
    ofs.open((INTERMEDIATE+"trimmed.txt"), fstream::out);
    char c;
    while(ifs.get(c)){
        if(!isspace(c)||c=='\n')
            ofs << c;
    }
    ifs.close();
    ofs.close();
}

int main(){
    map<string, vector<string>> non_terminals;
    map<string, set<string>> first;
    trim();
    getGrammarToken(non_terminals);
    eliminate_left_recursion(non_terminals);

    return 0;
}