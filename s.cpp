
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"enter your name";
    string name;
    cin>>name;
    cout<<"enter your group size";
    int gs;
    cin>>gs;
    vector<string> v1(gs-1);
    vector<string>::iterator it; 

    for(int i=0;i<gs-1;i++){
        cout<<"enter the name of member no."<<i+2;
        cin>>v1[i];
    }
   
    vector<float> balance(gs-1);
    int bal=0;
    while(1){
     int n;
    cout<<"enter 1 for recording a expence"<<endl;
    cout<<"enter 2 for summary"<<endl;
    cout<<"enter 3 for settelment"<<endl;
    cin>>n;
    if(n==1){
        //record a expence
        cout<<"who paid?";
        string pay;
        cin>>pay;
        int payid;
        if(pay=="me")
           payid=0;
        else{
            it = find (v1.begin(), v1.end(), pay);
            if (it != v1.end()) 
                payid= it - v1.begin();
           
        }
        float payamount;
         cout<<"how much?";
         cin>>payamount;
         
         float share = payamount/gs;
         if(payid==0)
         {
             bal+=payamount-share;
             for(int i=0;i<gs-1;i++){
                 balance[i]-=share;
                 }
             
         }
         else{
              bal-=share;
              balance[payid]+=share;
             }
        
    }
    else if(n==2){
        cout<< "your net balance is "<< bal<<endl;
        for(int i=0;i<gs-1;i++){
            if(balance[i]<0)
                cout<<"you lent "<<v1[i]<<" "<<abs(balance[i])<<endl;
            else if(balance[i]>0)
                cout<<"you owe "<<v1[i]<<" "<<abs(balance[i])<<endl;
            else
                cout<<"you and "<<v1[i]<<"are clear"<<endl;
        }
        
        }
    else if(n==3){
        cout<<"enter the other name"<<endl;
        string s1,s2;
        cin>>s1;
        it = find (v1.begin(), v1.end(), s1);
        int id;
        if (it != v1.end()) 
            id = it - v1.begin();
        
        if(balance[id]<0)
        {    
            cout<<v1[id]<<" should pay you"<<abs(balance[id])<<endl;
            cout<<"how much he paid? ";
            float inb;
            cin>>inb;
            balance[id]+=inb;
        }
        else if(balance[id]>0)
        {    
            cout<<"you should pay "<<v1[id]<<" "<<abs(balance[id])<<endl;
            cout<<"how much You paid? ";
            float ob;
            cin>>ob;
            balance[id]-=ob;
        }
        else
            cout<<"you and "<<v1[id]<<"are clear and no need of settelment"<<endl;
        
    }
    }
}
