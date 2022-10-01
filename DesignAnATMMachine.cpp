class ATM {

     vector<long long> v={0,0,0,0,0};
     vector<int> v1={20,50,100,200,500};
public:
    ATM() {
       
    }
    
    void deposit(vector<int> banknotesCount) {
        for(int i=0;i<banknotesCount.size();i++)
            v[i]+=banknotesCount[i];
        for(int i=0;i<5;i++) cout<<v[i]<<" ";
        cout<<"\n";
    }
    
    vector<int> withdraw(int amount) {
        vector<int> ans(5,0);
        cout<<"bb";
        for(int i=4;i>=0;i--)
        {   
            long long x=(amount)/v1[i];
            cout<<x<<" "<<v1[i]<<" ";
            ans[i]=min(x,v[i]);
            amount-=(ans[i]*v1[i]);
        }
        if(amount) {
            vector<int> ans1(1);
            ans1[0]=-1;
            return ans1;    
        }
        for(int i=0;i<5;i++) v[i]-=ans[i];
        cout<<"\n";
        return ans;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
