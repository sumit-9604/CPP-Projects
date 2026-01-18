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

📊 Complete Data Flow Diagram

[START]
   ↓
[USER INPUT]
├── File1 name ──→ readfile()
└── File2 name ──→ readfile()
   ↓
[PROCESSING PIPELINE] (Parallel for both files)
   ↓
└── removecomments()
    ↓
└── normalisecode()
    ↓
[Vector<string> A]    [Vector<string> B]
         ↓                    ↓
    calculatesimilarity()
         ↓
    [Similarity %] ──→ [Classification]
         ↓
[OUTPUT RESULT]
   ↓
[END]

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
