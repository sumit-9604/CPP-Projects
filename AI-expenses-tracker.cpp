#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<fstream>
#include<iomanip>
#include<stdexcept>
using namespace std;

class Transaction{

    protected:
    float amount; string catagory , date; 

    public:
    Transaction() : amount(0) {}
    void setdetails(float amt , string dt, string cat){

        amount = amt;
        date = dt;
        catagory = cat;}

    float getamount() const {return amount;}
    string getdate() const {return date;}
    string getcatagory() const {return catagory;}

};

class Income : public Transaction{

    string source;

    public:
    void recordincome(float amt,string dt,string cat,string src){
        setdetails(amt,dt,cat);
        source = src;}
};

class Expense : public Transaction{

    string type;

    public:
        void setexpence(float amt, string dt, string cat, string tp){
            setdetails(amt,dt,cat);
            type = tp;}
};

class budgetplanner{

    float ttlincome;
    float ttlexpence;
    float monthlylimit;

    public:
        budgetplanner() : ttlincome(0) , ttlexpence(0) , monthlylimit(0){}

        void setbudget(float inc , float expence , float limit){
            ttlincome = inc;
            ttlexpence = expence;
            monthlylimit = limit;}

        void calculatebudget(){

            cout<<"\n#### BUDGET REPORT ####\n"<<endl;
            cout<<"your total income is Rs: "<<ttlincome<<endl;
            cout<<"your total expences Rs: "<<ttlexpence<<endl;
            cout<<"your monthly limit is Rs: "<<monthlylimit<<endl;
            
            if(ttlexpence > monthlylimit){
                cout<<"BUDGET EXCEEDING the limit by Rs: "<<ttlexpence - monthlylimit<<endl;
            }else if (ttlexpence == monthlylimit){
                cout<<"youre in budget"<<endl;
            }else{
                cout<<"congrats you are saving amount Rs: "<<monthlylimit-ttlexpence<<endl;}}

        float operator-(const budgetplanner &b){
            return b.ttlincome - b.ttlexpence;}

};

class filemanager{
    public:
        void savefile(const vector<Expense> & expence ,const vector<Income> &income){
            ofstream file("data.txt");
            for (const auto &e : expence){
                file << "E " << e.getamount() << " " << e.getdate() << " " << e.getcatagory()<<endl;}


            for (const auto &i : income){
                file << "I " << i.getamount() << " " << i.getdate() << " " << i.getcatagory()<<endl;}
            file.close();}
};

class SmartAnalyser{
    public:
        void analysetrends(const vector<Expense> &Expenses){
        map <string,float> categoryspend;
        for (const auto &e : Expenses){
                categoryspend[e.getcatagory()] += e.getamount();}

        cout << "\n--- Smart Suggestions ---\n";
        
        for (const auto& pair : categoryspend){
            string cat = pair.first;
            float amt = pair.second;
            if (amt > 5000){
                cout<< "HIGH SPEND ON " << cat << " of rs:"<< amt << "please consider to reduce it \n" <<endl;}}}
};

int main(){
    vector<Expense> expences;
    vector<Income> income;
    budgetplanner planner;
    filemanager filesystem;
    SmartAnalyser AI;
    int choices;

    while (true)
    {
        cout << "\n--- Personal Expense Tracker ---\n";
        cout << "1. Add Income\n2. Add Expense\n3. Plan Budget\n4. SmartSuggestions\n5.Exit\nEnter choice : ";
        cin >> choices;

        switch (choices)
        {
        case 1:{  // adding income
            float amt ; string dt , cat , src;
            cout<<"AMOUNT: "; cin >> amt;
            cout<<"date (dd-mm-yyyy): "; cin >> dt;
            cout<<"category: "; cin >> cat;
            cout<<"source: "; cin >> src;
            Income temp;
            temp.recordincome(amt,dt,cat,src);
            income.push_back(temp);
            break;}

        case 2:{  // adding amount
            float amt;
            string dt,cat,tp;
            cout<<"AMOUNT: "; cin >> amt;
            cout<<"date (dd-mm-yyyy): "; cin >> dt;
            cout<<"category: "; cin >> cat;
            cout<<"type: "; cin >> tp;
            Expense temp;
            temp.setexpence(amt,dt,cat,tp);
            expences.push_back(temp);}

        case 3:{
            float incomes = 0, expenses = 0, limit;
            for(const auto &i : income){
                incomes += i.getamount();}

            for(const auto &e : expences){
                expenses += e.getamount();}

            cout<<"enter monthly limit : ";
            cin>>limit;
            planner.setbudget(incomes,expenses,limit);
            planner.calculatebudget();
            break;}

        case 4:{
            AI.analysetrends(expences);
            break;}
        
        case 5:{
            filesystem.savefile(expences,income);
            cout<< "data saved . exiting .\n";
            return 0;}

        default:
            cout<< "invalid input\n";}}

            
    return 0;
}