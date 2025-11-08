#include <iostream>
#include <queue>
using namespace std;
int main(){
  queue<pair<string,int>> q;
  int t,n;
  cin>>t>>n;
  for(int i=0;i<n;i++){
    string p;
    int m;
    cin>>p>>m;
    q.push({p,m});
  }
  int count=1,tcur=0;
  while(q.size()!=0){
    if(q.front().second<=t){
      tcur+=q.front().second;
      cout<<q.front().first<<' '<<tcur<<' '<<count<<endl;
      q.pop();
    }
    else{
      q.front().second-=t;
      tcur+=t;
      pair<string,int> cur=q.front();
      q.pop();
      q.push(cur);
    }
    count+=1;
  }
}
