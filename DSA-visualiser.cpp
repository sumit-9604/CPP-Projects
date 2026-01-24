// thread and chrono is used onlyfor visualisation and time delay for better visualisation
#include <iostream> 
#include <vector>
#include <queue>
#include <stack>
#include <thread>
#include <chrono>
#include <algorithm>
#include<limits>

using namespace std;

void delay(int ms = 500)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void printarray(const vector<int> &arr, int a = -1, int b = -1)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == a || i == b)
        {
            cout << "[" << arr[i] << "]";
        }
        else
        {
            cout << arr[i] << " ";
        }
    }

    cout << endl;
    delay(); // FOR VISUALISATION
}

// ALL SORTING ALGORITHMS

void bubblesort(vector<int>& arr)
{
    cout << "\nBUBBLE SORT\n";
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            printarray(arr, j, j + 1);
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                cout << "swapped\n";
                printarray(arr, j, j + 1);
            }
        }
    }
}

void selectionsort(vector<int> arr)
{
    cout << "\nSELECTION SORT\n";
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        int mid = i;
        for (int j = i + 1; j < n; j++)
        {
            printarray(arr, mid, j);
            if (arr[j] < arr[mid])
            {
                mid = j;
            }

            swap(arr[i], arr[mid]);
            printarray(arr, i, mid);
        }
    }
}

void insertionsort(vector<int> arr)
{
    cout << "\nINSERTION SORT\n";
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            printarray(arr, j, j + 1);
            j--;
        }
        arr[j + 1] = key;
        printarray(arr, j, j + 1);
    }
}

void linearsearch(vector<int> arr, int t)
{
    cout << "\nLINEAR SEARCH\n";
    for (int i = 0; i < arr.size(); i++)
    {
        printarray(arr, i);
        if (arr[i] == t)
        {
            cout << "element found at index " << i << endl;
            return;
        }
    }

    cout << "element not found\n";
}

void binarysearch(vector<int> arr, int t)
{
    cout << "\nBINARY SEARCH\n";
    sort(arr.begin(), arr.end());
    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        printarray(arr, mid);
        if (arr[mid] == t)
        {
            cout << "element found at index " << mid << endl;
            return;
        }

        if (arr[mid] < t)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << "element not found\n";
}

void stackvisualiser()
{
    stack<int> st;
    int choice, val;

    do
    {
        cout << "\nSTACKMenu\n1.Push\n2.Pop\n3.Display\n0.Exit\nChoice:";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        if (choice == 1)
        {
            cout << "Enter value: ";
            cin >> val;
            st.push(val);
        }

        else if (choice == 2)
        {
            if (!st.empty())
            {
                cout << "Popped: " << st.top() << endl;
                st.pop();
            }
            else
            {
                cout << "Stack Empty\n";
            }
        }

        else if (choice == 3)
        {
            stack<int> temp = st;
            cout << "Stack (Top → Bottom): ";
            while (!temp.empty())
            {
                cout << temp.top() << " ";
                temp.pop();
            }
            cout << endl;
        }
    }while(choice!= 0);
}


void queuevisualisation(){
    queue<int> q;
    int choice , val;

    do{
        cout << "\nQueue Menu\n1.Enqueue\n2.Dequeue\n3.Display\n0.Exit\nChoice: ";
        cin>>choice;

        if(choice == 1){
            cout<<"enter the value: ";
            cin>>val;
            q.push(val);
        }else if(choice == 2){
            if(!q.empty()){
                cout<<"dequeued " << q.front()<<endl;
                q.pop();
            }else{
                cout<<"queue is empty";
            }
        }else if(choice == 3){
            queue<int> temp = q;
            cout<<"queue(front -> rare): ";
            while(!temp.empty()){
                cout<<temp.front()<<" ";
                temp.pop();
            }
            cout<<endl;
        }
    }while(choice != 0 );
}



int main(){
    int choice;
    cout<<"\n========== DSA VISUALISATION ==========\n";
    cout<<"1. Sorting\n2. Searching\n3. Stack\n4. Queue\nChoice:";
    cin>>choice;

    if(choice == 1){
        int n, algo;
        cout<<"enter the number of elements ";
        cin >> n;

        vector<int> arr(n);
        cout<<"enter the elements \n";
        for (int i = 0; i < n; i++){
            cin>>arr[i];}

        cout<<"1.Bubble 2.Selection 3.Insertion\nChoice: ";
        cin>>algo;

        if (algo == 1){bubblesort(arr);}
        else if(algo == 2) {selectionsort(arr);}
        else if(algo == 3) {insertionsort(arr);}
        
        
    }else if(choice == 2){
        int n,t,algo;
        cout<<"enter the number of elements ";
        cin>>n;

        vector<int> arr(n);
        cout<<"enter the elements ";
        for (int i = 0; i < n; i++){
            cin>>arr[i];}

        cout<<"enter the target ";
        cin>>t;

        cout<<"1.Linear 2.Binary\nChoice:";
        cin>>algo;

        if (algo == 1){
            linearsearch(arr , t);
        }else{binarysearch(arr,t);}

    }else if(choice == 3){
        stackvisualiser();
    }else if(choice == 4 ){
        queuevisualisation();
    }
    return 0;

}

