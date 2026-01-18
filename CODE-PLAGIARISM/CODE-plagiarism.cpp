#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<unordered_set>
#include<string>
#include<algorithm>

using namespace std;

string readfile(const string& filename){
    ifstream file(filename);
    if (!file.is_open()){
        cout<<"errror opening file : "<< filename<<endl;
        exit(1);}

    stringstream buffer;
    buffer<<file.rdbuf();
    return buffer.str();
}

string removecomments(const string& code){
    string result;
    bool inblock = false;

    for (int i = 0; i < code.size(); i++){
        //start of block comment

        if (!inblock && i+1 < code.size() && code[i] == '/' && code[i+1] == '*'){
            inblock = true;
            i++;}
        
        //end of block comment
        else if (inblock && i+1 < code.size() && code[i] == '*' && code[i+1] == '/'){
            inblock = false;
            i++;}

        //single line comment
        else if (inblock && i+1<code.size() && code[i] == '/' && code[i+1] == '/'){
            while (i<code.size() && code[i] != '\n'){
                i++;}}

        //normal code
        else if(!inblock){
            result += code[i];}}


    return result;
}


vector<string> normalisecode(const string& code){
    vector<string> lines;
    stringstream ss(code);
    string line;

    while(getline(ss,line)){
        line.erase(remove_if(line.begin(),line.end(),::isspace),line.end());

    if (!line.empty()){
        lines.push_back(line);}}

    return lines;
}


double calculatesimilarity(const vector<string>& a , const vector<string>& b){
    unordered_set<string> setA(a.begin(),a.end());
    int matched = 0;

    for (const auto& line : b){
        if(setA.count(line)) matched++;}

    int total = max(a.size(),b.size());

    if (total == 0)return 0;

    return (double)matched / total * 100.00;
}


int main(){
    string file1;
    cout<<"enter the first file\n";
    cin>> file1;
    string file2;
    cout<<"enter the second file\n";
    cin>> file2;

    string codeA = readfile(file1);
    string codeB = readfile(file2);

    codeA = removecomments(codeA);
    codeB = removecomments(codeB);

    vector<string> normA = normalisecode(codeA);
    vector<string> normB = normalisecode(codeB);

    double similarity = calculatesimilarity(normA,normB);

    cout<<"------------------------------------------------------------------------------------------------------\n";
    cout<<"\tCODE PLAGIARISM \n";
    cout<<"------------------------------------------------------------------------------------------------------\n";
    cout<<"similarity : "<<similarity<<"%\n";

    if (similarity >= 70){
        cout<<"HIGH PLAGIARISM\n";

    }else if(similarity >= 40){
        cout<<"MEDIUM PLAGIARISM \n";

    }else{
        cout<<"LOW PLAGIARISM\n";}

        
    return 0;
    
}