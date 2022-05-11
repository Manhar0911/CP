#include<iostream>
#include<algorithm>
using namespace std;

#define f(i,n,m) for(int i=n;i<m;i++)

class Item
{
  public:
  int profit;
  int wt;

  Item(int profit,int wt)
  {
      this->profit = profit;
      this->wt = wt;
  }
};

bool cmp(Item* a,Item* b)
{
    double r1 = (double)a->profit/(double)a->wt;
    double r2 = (double)b->profit/(double)b->wt;
    return r1>r2;
}

double fractional_knapsack(int n,int w,Item* arr[])
{
   sort(arr,arr+n,cmp);
   double f[n];
   double ans = 0;
   f(i,0,n)
   {
       if(w>=arr[i]->wt)
       {
           w = w - arr[i]->wt;
           f[i] = 1.0;
       }
       else
       {
           f[i] = (double)w/(double)arr[i]->wt;
           w = 0;
           break;
       }
   }
   f(i,0,n)
   {
       ans = ans + f[i]*arr[i]->profit;
       //cout<<ans<<endl;
   }
   return ans;
}

int main()
{
    int n;
    cin>>n;
    int profit[n],wt[n];
    f(i,0,n)
    {
        cin>>profit[i];
    }
    f(i,0,n)
    {
        cin>>wt[i];
    }
    Item* Item1[n];
    f(i,0,n)
    {
        Item1[i] = new Item(profit[i],wt[i]);
    }
    int cap;
    cin>>cap;
    cout<<fractional_knapsack(n,cap,Item1)<<endl;
}