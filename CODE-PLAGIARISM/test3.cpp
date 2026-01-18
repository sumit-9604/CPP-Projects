#include<iostream>
#include<unordered_map>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;


int fib(int n){           // O(2n)
    if (n==0 || n==1){
        return n;}
    
    return fib(n-1)+fib(n-2);}




int binary(vector<int>&arr , int st , int end , int t){
    int n = arr.size()-1;     //O(logn) , O(logn)
    int mid = st +(end-st)/2;

    if(st<=end){    
        if(arr[mid] == t){
        return mid;

        }else if(arr[mid]>t){
        binary(arr,st,mid-1,t);

        }else{
        binary(arr,mid+1,end,t);}}}





bool issorted(vector<int> &arr , int n){//O(n)

    if (n == 0 || n == 1){
        return true;}
    return arr[n-1] >= arr[n-2] && issorted(arr,n-1);} // n-1 n-2 true hoga tabhi recursion chalega



void ps(vector<int>&a , vector<int>&ans , int i ){//O(2n*n)
    int n = a.size();
    if(i == a.size()){
        for(int v:ans){
        cout<<"{"<<v<<"}";}
        cout<<endl;
        return;
    }
    ans.push_back(a[i]);   // inclusion
    ps(a,ans,i+1);          //  recalll and updation
    ans.pop_back();         // backtracking
    ps(a,ans,i+1);
}

// void ps1(vector<int>&a , vector<int>&ans , int i ,vector<vector<int>> subset){//O(2n*n)
//     int n = a.size();
//     vector<int> subset;
//     if(i == a.size()){
//         subset.push_back({ans});
//         return;
//     }
//     ans.push_back(a[i]);   // inclusion
//     ps1(a,ans,i+1,subset);          //  recalll and updation
//     ans.pop_back();         // backtracking
//     ps1(a,ans,i+1,subset);
// }


void subset(vector<int> &a , vector<int> ans , int i , vector<vector<int>> allsubset){// subsets banayega

    int n = a.size();
    if (i == n)
    {
       allsubset.push_back(ans);              
       return;
    }
    ans.push_back(a[i]);
    subset(a,ans,i+1,allsubset);
    ans.pop_back();
    int idx = i+1;
    while (i<n && a[idx] == a[idx-1]) idx++;
    subset(a,ans,idx,allsubset);    

}



    
    



void getpermutations(vector<int> &a ,vector<vector<int>> &ans, int i){
    int n = a.size();         // O(n * n!) , O(n!)
    if (i == n){
        ans.push_back({a});
        return;}
    
    for (int j = i; j < n; j++){
        swap(a[i],a[j]);
        getpermutations(a,ans,i++);
        swap(a[i],a[j]);       // backtracking
}}

bool issafe(vector<string>&board , int row , int col, int n){ //O(n)

    for (int i = 0; i < n; i++){
        if (board[i][col] == 'Q') return false;}

    for (int j = 0; j < n; j++){
        if (board[row][j] == 'Q') return false;}

    for (int i = row,j=col;i>= 0 ,j>= 0 ; i--,j--){
        if (board[i][j] == 'Q') return false;}

    for (int i = row,j=col;i>= 0 ,j>= 0 ; i--,j++){
        if (board[i][j] == 'Q') return false;}
    
    return true;}

void nqueens(vector<string>&board,int row , int n , vector<vector<string>> &ans){  // O(n!)

    for (int i = 0; i < n; i++){
        if(issafe(board,row,i,n)){
            board[row][i]  = 'Q';
            nqueens(board,row++,n,ans);
            board[row][i] = '.'; //backtracking
            
}}}



    
    
vector<vector<int>> subsets(vector<int> &a){ //store carega  main calliski lagegi orrr subset ka kaam bina call ke hoga iski call hi mani jayegi, recursion isme nahi lagega subset me hi lagega 
    sort(a.begin(),a.end());
    vector<vector<int>> allsubsets;
    vector<int> ans;
    subset(a,ans,0,allsubsets);
    return allsubsets;}

    
vector<vector<string>> storenqueens(int n){
    vector<string> board(n , string(n,'.'));
    vector<vector<string>> ans;
    nqueens(board,0,n,ans);}


vector<vector<int>> permutations(vector<int>&a){
    vector<vector<int>> ans;
    getpermutations(a,ans,0);}

    
bool issafesudoku(vector<vector<char>>& board , int row ,int col , char dig){
    for (int i = 0; i < 9; i++){
        if (board[i][col] == dig) return false;}

    for (int j = 0; j < 9; j++){
        if (board[row][j] == dig) return false;}

    int sr = (row/3)*3;
    int sc = (col/3)*3;                        //  checking the grid of the board.
    for (int i = sr; i < sr+2; i++){
        for (int j = sc; j < sc+2; j++){
            if (board[i][j] == dig) return false;}}
        
    return true;}
bool sudoku(vector<vector<char>> &board , int row , int col){
    int nrow = row;
    int ncol = col+1;
    if (ncol == 9 ){
        nrow = row+1;
        ncol = 0;}
    
    if(row==9) return true;  // base case

    if(board[row][col] != '.'){
        return sudoku(board , nrow , ncol);


    for (char dig = '1'; dig < '9'; dig++){
        if(issafesudoku(board , row ,col , dig)){
            board[row][col] = dig;
            if(sudoku(board,nrow,ncol)){
                return true;}
            board[row][col] = '.';}}}}






//////////////////////////////////////////////////////////////////////////

void ratinmaze(vector<vector<int>>&maze ,int r ,int c , string path , vector<string>&ans , vector<vector<bool>> &vis){
    int n = maze.size();

    if (r<0 || c<0 || r>=n || c>=n || maze[r][c] == 0 || vis[r][c] == true){return;} // boundry + basecase
    
    if (r == n-1 && c == n-1){
        ans.push_back(path);
        return;}
    vis[r][c] = true;

    ratinmaze(maze,r+1,c,path+"D",ans , vis);
    ratinmaze(maze,r-1,c,path+"U",ans , vis);
    ratinmaze(maze,r,c-1,path+"L",ans , vis);
    ratinmaze(maze,r,c+1,path+"R",ans , vis);
    vis[r][c] = false;     // backtracking


}
vector<string> findpath(vector<vector<int>> &maze){
    int n = maze.size();
    vector<string> ans;
    string path = "";
    vector<vector<bool>> vis(n,vector<bool>(n,false));
    ratinmaze(maze,0,0,path,ans,vis);
}
 
void combinationsum(vector<int> &arr , int tar , int idx , vector<int> &comb , vector<vector<int>> &ans){

    set<vector<int>> answerset;

    if (tar==0){
        if (answerset.find(comb) == answerset.end()){
            ans.push_back(comb);
            answerset.insert(comb);}}



    if(idx==arr.size())  {return;}                  // basecase
    if(tar<0)            {return;}

    comb.push_back(arr[idx]);                       
    combinationsum(arr,tar-arr[idx],idx+1,comb,ans);// single
    combinationsum(arr,tar-arr[idx],idx,comb,ans);  // multiple
    comb.pop_back();  // backtracking'
    combinationsum(arr,tar,idx+1,comb,ans);}        // exclusion




vector<vector<int>> combsum(vector<int> &arr , int tar){
    vector<vector<int>> ans;
    vector<int> comb;}


void palindromepartioning(string s , vector<string>&partitions,vector<vector<string>> &ans){

    if (s.size() == 0){
        ans.push_back(partitions);
        return;}
    

    for (int i = 0; i < s.size(); i++){
        string part = s.substr(0,i+1);
        if (ispalindrome(part)){
            partitions.push_back(part);
            palindromepartioning(s.substr(i+1),partitions,ans);
            partitions.pop_back();}}}



bool ispalindrome(string s){
    string s2 = s;
    reverse(s2.begin(),s2.end());
    if(s == s2)    return true;}


void nightstour(vector<string> &board , int n){}



int main(){



}