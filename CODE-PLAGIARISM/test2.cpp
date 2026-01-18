#include<iostream>
#include<vector>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<algorithm>
using namespace std;

vector<int> twosum(vector<int> &arr ,int t){
    unordered_map<int,int> m;
    vector<int> ans;
    for (int i = 0; i <arr.size(); i++)
    {
        int first = arr[i];
        int sec = t-first;
        if (m.find(sec) != m.end()){
            ans.push_back(i);
            ans.push_back(m[sec]);
            break;}
        m[first] = i;}
    return ans;
}

vector<vector<int>> threesum_bf(vector<int> &arr){//i!=j!=k  and i+j+k = 0 { O(n3 * logn)}
    //brute force
    vector<vector<int>> ans;
    set<vector<int>> s;               // only unique triplets
    for (int i = 0; i <arr.size(); i++){
        for (int j = i+1; j <arr.size(); j++){
            for (int k = j+1; k <arr.size(); k++){
                if (arr[i]+arr[j]+arr[k] == 0){
                   vector<int> trip = {arr[i],arr[j],arr[k]};    // all triplets
                   sort(trip.begin(),trip.end());
                   if (s.find(trip) == s.end()){// time complexicity of this is O(logn)
                        s.insert(trip);
                        ans.push_back(trip);}}}}}
    return ans;
}

vector<vector<int>> threesum_hashing(vector<int> &arr){
    int n = arr.size();
    vector<vector<int>> ans;
    set<vector<int>> uset;


    for (int i = 0; i < n; i++){
        int tar = -arr[i];
        set<int> s;
        for (int j = i+1; j < n; j++)
        {
            int third = tar - arr[j];
            if (s.find(third) != s.end()){
                vector<int> trip = {arr[i],arr[j],third};
                sort(trip.begin(),trip.end());
                uset.insert(trip);}
            s.insert(arr[j]);}}
            
    return ans;
}



vector<vector<int>> threesum_twoptr(vector<int> &arr){//O(nlogn +n2)
    sort(arr.begin(),arr.end());  
    int n=  arr.size();
    vector<vector<int>> ans;
    for (int i = 0; i <n; i++){
        if (i>0 && arr[i] == arr[i+1]) continue;
        int j = i+1 , k=n-1;
        while(j<k){
            int sum = arr[i]+arr[j]+arr[k];
            if (sum>0){k--;}
            else if (sum<0){j++;}
            else{
                ans.push_back({arr[i],arr[j],arr[k]});
                j++;
                k--;
                while (j<k && arr[j] == arr[j-1]) j++;}}}
    return ans;}


vector<vector<int>> foursum(vector<int> &arr){//O(n3* nlogn)
    vector<vector<int>> ans;
    int n = arr.size();

    sort(arr.begin(),arr.end());
    for (int i = 0; i < n; i++){
        if (i>0 && arr[i] == arr[i+1]) continue;
        for (int j = i+1; j < n;){
            int p = j+1;
            int q = n-1;
            while(p<q){
                int sum = arr[i]+arr[j]+arr[p]+arr[q];
                if (sum>0){q--;}
                else if (sum<0){p++;}
                else{
                    ans.push_back({arr[i],arr[j],arr[p],arr[q]});
                    p++; q--;
                    while(p<q && arr[p] == arr[p-1])
                    p++;}}
        j++;
        while(j<n && arr[j] == arr[j+1]) j++;}}

    return ans;
}

vector<int> mising_repeating(vector<vector<int>> & grid){
    vector<int> ans;
    unordered_set<int> s;
    int a,b;
    int actsum =0;
    int n = grid.size();
    int nn = n*n;
    int expsum = (nn * (nn+1))/2;


    for (int i = 0; i < n; i++){
        for (int j = 0; j <n; j++){
            actsum += grid[i][j];

            if (s.find(grid[i][j]) !=s.end()){
                a=grid[i][j];
                ans.push_back(a);}

            s.insert(grid[i][j]);}}
    b = expsum + a - actsum;
    ans.push_back(b);
    return ans;
}

int duplicate(vector<int> & arr){//slow fast ptr approach
    int slow = arr[0];
    int fast = arr[0];
    do
    {
        slow = arr[slow];          // update by 1
        fast = arr[arr[fast]];
    } while (slow != fast);
    slow = arr[0];
    while (slow != fast){
        slow = arr[slow];
        fast = arr[fast];}
    return slow;}






int main(){
    vector<int> arr ={5,2,7,11,15};
    vector<vector<int>>grid = {{1,3},{2,2}};     
    vector<int>ans = mising_repeating(grid);
    
    for (int nm : ans)
    {
        cout<<nm<<" ";
    }

}