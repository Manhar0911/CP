#include<iostream>
#include<algorithm>
using namespace std;

#define f(i,n,m) for(int i=n;i<m;i++)

class Job
{
    public:
    int profit;
    int deadline;

    Job(int profit,int deadline)
    {
        this->profit = profit;
        this->deadline = deadline;
    }
};

bool cmp(Job* a, Job* b)
{
   return (a->profit > b->profit);
}

int MaxProfitJobSheduling(int n, Job* job[])
{
    int maxd = 0;
    int res = 0;
    f(i,0,n)
    {
        maxd = max(maxd,job[i]->deadline);
    }

    bool slot[maxd];
    f(i,0,maxd)
    {
       slot[i] = false;
    }
    sort(job,job+n,cmp);

    f(i,0,n)
    {
       for(int j=job[i]->deadline;j>0;j--)
       {
          if(slot[j]==false)
          {
              res = res + job[i]->profit;
              //cout<<res<<" "<<j<<endl;
              slot[j] = true;
              break;
          }
       }
    }
    return res;
}

int main()
{
    int n;
    cin>>n;
    int profit[n],deadline[n];
    f(i,0,n)
    {
        cin>>profit[i];
    }
    f(i,0,n)
    {
        cin>>deadline[i];
    }
    Job* job[n];
    f(i,0,n)
    {
        job[i] = new Job(profit[i],deadline[i]);
    }

    cout<<MaxProfitJobSheduling(n, job)<<endl;
    return 0;
}