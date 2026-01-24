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
    cout<<"\nGANTT CHART\n|";
    for (auto &g : gantt){
        cout<<" P"<<g.first<<" |";
        cout<<"\n0";}

    for (auto &g : gantt){
        cout<<setw(4)<<g.second;
        cout<<"\n\n";}
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