#include<bits/stdc++.h>
#define author "1114"
using namespace std;


class Solution{
public:
    void FCFS(vector<string>&process,vector<int>&arrivalTime,vector<int>&burstTime,int n){
        vector<int>prefixSum(n);

        int sum=0;
        for(int i=0; i<n; i++){
            sum+=burstTime[i];
            int temp=sum-burstTime[i];
            if(temp<arrivalTime[i]){
                prefixSum[i]=arrivalTime[i]+burstTime[i];
                sum=prefixSum[i];
            }
            else{
                prefixSum[i]=sum;
            }
            
        }
        cout<<"Completion Time: "<<endl;
        for(int i=0; i<n; i++){
            cout<<process[i]<<": "<<prefixSum[i]<<endl;
        }
        cout<<endl;

        cout<<"Turn Arround Time: "<<endl;
        float avgT=0;
        for(int i=0; i<n; i++){
            int tAt=prefixSum[i]-arrivalTime[i];
            avgT+=tAt;
            cout<<process[i]<<": "<<tAt<<endl;
        }
        cout<<"Average Turn Arround Time: "<<setw(2)<<avgT/n<<endl;
        cout<<endl;
        
        cout<<"Waiting Time: "<<endl;
        float avgW=0;
        for(int i=0; i<n; i++){
            int wt=(prefixSum[i]-arrivalTime[i])-burstTime[i];
            avgW+=wt;
            cout<<process[i]<<": "<<wt<<endl;
        }
        cout<<"Average Waiting Time: "<<setw(2)<<avgW/n<<endl;
    }

};



int main(){

    cout<<"Please enter the Number of Processes: "<<endl;
    int n;cin>>n;

    vector<string>process;
    for(int i=0; i<n; i++){
        string x='P'+to_string(i+1);
        process.push_back(x);
    }
    vector<int>arrivalTime;
    cout<<"Enter the Arrival Time: "<<endl;
    for(int i=0; i<n; i++){
        int x;cin>>x;
        arrivalTime.push_back(x);
    }
    vector<int>burstTime;
    cout<<"Enter the burst Time: "<<endl;
    for(int i=0; i<n; i++){
        int x;cin>>x;
        burstTime.push_back(x);
    }
    cout<<endl;

    cout<<"Solution: "<<endl;
    Solution sln;
    sln.FCFS(process,arrivalTime,burstTime,n);

    return 0;
}