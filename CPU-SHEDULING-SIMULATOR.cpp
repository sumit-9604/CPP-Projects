#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<thread>
#include<chrono>
#include<queue>

using namespace std;

void delay(int ms = 500){
    this_thread::sleep_for(chrono::milliseconds(ms));
}

struct process{
    int pid;
    int arrival;
    int burst;
    int remaining;
    int priority;
    int start = -1;
    int completion = 0;
    int waiting = 0;
    int turnaround = 0; 
};


void printgantt(const vector<pair<int,int>> &gantt){
    cout << "\n" << string(50, '=') << "\n";
    cout << "          GANTT CHART\n";
    cout << string(50, '=') << "\n";
    
    // Time scale
    cout << " 0";
    for (auto &g : gantt) {
        cout << setw(5) << g.second;
    }
    cout << "\n";
    
    // Process blocks (aligned)
    cout << "|";
    for (auto &g : gantt) {
        cout<<" p" <<setw(3) <<g.first<<"|";

    }
    cout << "\n\n";
    
    cout << "Total time: " << gantt.back().second<< " units\n";
    cout << string(50, '=') << "\n";
    delay(1000);
}


void FCFS(vector<process> p){
    sort(p.begin(),p.end(),[](auto &a, auto &b){
        return a.arrival < b.arrival;
    });

    int time = 0;
    vector<pair<int,int>> gantt;

    for (auto &pr : p)
    {
        if (time<pr.arrival){
            time = pr.arrival;}

        pr.start = time;
        time += pr.burst;
        pr.completion = time;
        pr.turnaround = pr.completion-pr.arrival;
        pr.waiting = pr.turnaround-pr.burst;

        gantt.push_back({pr.pid,time});
        delay();
        
    }

    printgantt(gantt);

    double aw = 0, at = 0;
    cout<<"PID AT BT WT TAT\n";
    for(auto&pr : p){
        cout << pr.pid << "  "
         << pr.arrival << "  "
         << pr.burst << "  "
         << pr.waiting << "  "
         << pr.turnaround << "\n";
        
        aw += pr.waiting;
        at += pr.turnaround;
    }
    
    cout<<"\naverage waiting time: "<<aw/p.size();
    cout<<"\naverage turnaround time: "<<at/p.size()<<"\n";

}


void SJF(vector<process> p){
    int time = 0, completed = 0;
    vector<pair<int,int>> gantt;
    vector<bool> done(p.size(),false);

    while(completed <p.size()){
        int idx = -1;
        int minBT = 1e9;

        for (int i = 0; i < p.size(); i++){
            if (!done[i] && p[i].arrival <= time && p[i].burst < minBT){
                minBT = p[i].burst;
                idx = i;}}

        if (idx == -1){
            time++;
            continue;}

        p[idx].start = time;
        time += p[idx].burst;
        p[idx].completion = time;
        p[idx].turnaround = time - p[idx].arrival;
        p[idx].waiting = p[idx].turnaround-p[idx].burst;

        done[idx] = true;
        completed++;
        gantt.push_back({p[idx].pid,time});
        delay();
    }
    printgantt(gantt);
}



void roundrobin(vector<process> p , int quantum){
    queue<int> q;
    int time = 0;
    vector<pair<int,int>> gantt;

    for (auto &pr : p){
        pr.remaining = pr.burst;}


    q.push(0);
    vector<bool> inqueue(p.size(),false);
    inqueue[0] = true;

    while (!q.empty()){
        int i = q.front();
        q.pop();

        if (p[i].start == -1){
            p[i].start = time;}

        int exec = min(quantum,p[i].remaining);
        time += exec;
        p[i].remaining -= exec;

        gantt.push_back({p[i].pid,time});
        delay();

        for (int j = 0; j < p.size(); j++){
            if (!inqueue[j] && p[j].arrival <= time && p[j].remaining > 0){
                q.push(j);
                inqueue[j] = true;}}

            if (p[i].remaining > 0){
                q.push(i);

            }else{
                p[i].completion = time;
                p[i].turnaround = time - p[i].arrival;
                p[i].waiting = p[i].turnaround-p[i].burst;}}

    printgantt(gantt);
    
}

int main(){
    int n;
    cout<<"ENTER THE PROCESS: ";
    cin>>n;

    vector<process> p(n);

    for(int i = 0;i<n;i++){
        p[i].pid = i+1;
        cout<<"\nprocess p "<<i+1 <<"\narrival time : ";
        cin>>p[i].arrival;
        cout<<"burst time :";
        cin>>p[i].burst;
        cout<<"priority (lower = higher) : ";
        cin>>p[i].priority;
    }

    int choice;
    cout<<"\nCPU SHEDULING ALGORITHMS\n";
    cout << "1. FCFS\n2. SJF\n3. Round Robin\nChoice: ";
    cin >> choice;

    if(choice == 1) {FCFS(p);}
    else if(choice == 2) {SJF(p);}
    else if(choice == 3){
        int q;
        cout<<"enter the time quantum: ";
        cin>>q;
        roundrobin(p,q);
    }
    return 0;
}