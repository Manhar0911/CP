#include<bits/stdc++.h>
using namespace std;


template<typename T,typename U>
class Stack
{
   private:
   vector<T>v;
   vector<U>v1;
   public:
   void push(T data)
   {
       v.push_back(data);
   }
   void pop()
   {
       if(v.size()>0)
       v.pop_back();
   }
   T top()
   {
       return v[v.size()-1];
   }
   bool empty()
   {
       return v.size()==0;
   }
};

int main()
{
   Stack<int,int>s;

   for(int i=1;i<=5;i++)
   {
       s.push(i*i);
   }
   while(!s.empty())
   {
       cout<<s.top()<<endl;
       s.pop();
   }
   return 0;
}