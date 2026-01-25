1. ### PERSONAL EXPENSES TRACKER ###
A C++ console-based application for tracking income, expenses, budget planning, and smart spending analysis. Built with OOP principles using inheritance, polymorphism, and file I/O for persistent data storage.

📋 Features
Income & Expense Tracking: Record detailed transactions with categories and sources

Budget Planning: Set monthly limits and get real-time budget status

Smart Analysis: AI-driven spending trend analysis with high-spend alerts (>₹5000)

Data Persistence: Automatic save to data.txt on exit

User-Friendly Menu: Intuitive console interface for all operations

📁 File Structure
text
├── main.cpp          # Complete application
├── data.txt         # Auto-generated (on exit)
└── README.md        # This file

🛠️ Tech Stack
text
Language: C++11/14
Libraries: STL (vector, map, fstream)
Design: OOP (Inheritance, Polymorphism)
Storage: Text file (.txt)

below is the flow diagram :
<img width="4200" height="7200" alt="Personal_Expense_Tracker_-_Complete_Program_Flow" src="https://github.com/user-attachments/assets/eb58193b-58ea-4c57-9c8a-15aed3e84ac0" />

2. ### CODE PLAGIARISM ###
   A lightweight console-based tool that detects code similarity between two C++ source files by removing comments, normalizing whitespace, and calculating line-based similarity percentage. Perfect for academic integrity checks and assignment submissions.

📋 Features
Comment Removal: Handles both // single-line and /* */ block comments

Code Normalization: Removes all whitespace, empty lines for fair comparison

Similarity Scoring: Line-based matching with percentage output (0-100%)

Plagiarism Classification:

HIGH (≥70%)

MEDIUM (≥40%)

LOW (<40%)

File I/O: Reads any text files with error handling

                    ╔══════════════════════════════════════╗
                    ║              START                    ║
                    ╚══════════════════════════════════════╝
                                   │
                                   ▼
                    ╔══════════════════════════════════════╗
                    ║         USER INPUT                    ║
                    ║    File1: student1.cpp                ║
                    ║    File2: student2.cpp                ║
                    ╚═══════════╦═══════════╦═══════════════╝
                              │               │
                              ▼               ▼
                    ╔══════════════╗   ╔══════════════╗
                    ║   readfile   ║   ║   readfile   ║
                    ║  (file1)     ║   ║  (file2)     ║
                    ╚══════════════╝   ╚══════════════╝
                              │               │
                              ▼               ▼
                    ╔══════════════╗   ╔══════════════╗
                    ║removecomments║   ║removecomments║
                    ║  (strip //)  ║   ║  (strip //)  ║
                    ╚══════════════╝   ╚══════════════╝
                              │               │
                              ▼               ▼
                    ╔══════════════╗   ╔══════════════╗
                    ║ normalisecode║   ║ normalisecode║
                    ║(no space)    ║   ║(no space)    ║
                    ╚══════════════╝   ╚══════════════╝
                              │               │
                              ▼               ▼
                       ┌──────────────┐
                       │  Vector A    │◄──────────────┘
                       │["intmain"]   │
                       │["couthello"] │
                       └──────┬───────┘
                              │
                              ▼
                       ┌──────────────┐
                       │calculatesim()│
                       │unordered_set │
                       │A.count(B)    │
                       └──────┬───────┘
                              │
                              ▼
                       ┌──────────────┐
                       │Similarity %  │
                       │   85.2%      │
                       └──────┬───────┘
                              │
                              ▼
                       ┌──────────────┐
                       │Classification│
                       │HIGH PLAGIARISM│
                       └──────┬───────┘
                              │
                              ▼
                       ┌──────────────┐
                       │     END      │
                       └──────────────┘


🛠️ Tech Stack
text
Language: C++11
Libraries: iostream, fstream, sstream, vector, unordered_set, algorithm
Data Structures: stringstream, unordered_set (O(1) lookup)
Time Complexity: O(n + m) where n,m = file line counts

🤝 Testing Strategy
text
1. Identical files → 100% similarity
2. Same logic, different variables → Medium similarity  
3. Commented differences → Should normalize to high
4. Whitespace-only changes → 100% similarity
5. Non-code files → Low similarity

 TEST OUTPUT
$ ./plagiarism_detector
enter the first file: student1.cpp
enter the second file: student2.cpp

------------------------------------------------------------------------------------------------------
            CODE PLAGIARISM 
------------------------------------------------------------------------------------------------------
similarity : 85.2%
HIGH PLAGIARISM

3. ### DSA VISUALISER ###

   
A C++ console-based Data Structures & Algorithms visualization tool that demonstrates sorting, searching, stack, and queue operations with step-by-step animations using delays and highlighted elements. Perfect for B.Tech CSE students preparing for DSA exams and interviews.

✨ Features
Sorting Visualizations (Bubble, Selection, Insertion)

Shows comparisons with [highlighted] elements

Displays swaps step-by-step

500ms delays for clear visualization

Searching Visualizations (Linear, Binary)

Linear: Scans original array left→right

Binary: Auto-sorts + shows pivot narrowing (low <= high fixed)

Highlights current position/midpoint

Stack Operations (Push, Pop, Display)

Interactive menu-driven interface

Shows Top→Bottom order

Input buffer handling for smooth UX

Queue Operations (Enqueue, Dequeue, Display)

Front→Rear visualization

Clean interactive menu

🎮 Demo Output
text
========== DSA VISUALISATION ==========
1. Sorting  2. Searching  3. Stack  4. Queue
Choice: 1
enter the number of elements 5
enter the elements 
64 34 25 12 22
1.Bubble 2.Selection 3.Insertion
Choice: 1

BUBBLE SORT
[64][34] 
64 [34] 
swapped
[34][64] 
34 [64] 
Build & Run
bash
# Full features (with delays)
g++ -std=c++17 -pthread dsa_visualizer.cpp -o dsa_vis

# Windows MinGW (if pthread fails)
g++ -std=c++17 dsa_visualizer.cpp -o dsa_vis.exe

# Run
./dsa_vis    # Linux/macOS
dsa_vis.exe  # Windows

<screenshots>
<img width="1149" height="606" alt="Screenshot 2026-01-24 231233" src="https://github.com/user-attachments/assets/c8e195f7-ef09-49f1-956f-00193547d0ca" />
<img width="1153" height="605" alt="Screenshot 2026-01-24 231246" src="https://github.com/user-attachments/assets/cd22db0e-c94f-4ace-8620-7e0e8dc0859a" />


4. ### CPU SHEDULING SIMULATOR ###

A C++ console-based CPU Scheduling Algorithms visualizer that demonstrates FCFS, SJF, and Round Robin with Gantt charts and step-by-step execution. Perfect for Operating Systems coursework and technical interviews.

✨ Features
FCFS (First Come First Serve)

Simple arrival-order execution

Shows waiting time calculation

Complete TAT/WT metrics

SJF (Shortest Job First)

Non-preemptive shortest burst first

Idle time handling when no process ready

Dynamic process selection

Round Robin

Preemptive time quantum scheduling

Ready queue simulation

Remaining time tracking

Visualization

Step-by-step Gantt chart generation

500ms delays for clear animation

Average Waiting Time (AWT) & Turnaround Time (ATT)

🎮 Demo Output
text
ENTER THE PROCESS: 3

process p 1
arrival time : 0
burst time : 8
priority (lower = higher) : 2

CPU SCHEDULING ALGORITHMS
1. FCFS  2. SJF  3. Round Robin
Choice: 2

GANTT CHART
| P1 | P2 | P3 |
0    8   13   17


