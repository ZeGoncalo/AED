#include <iostream>
using namespace std;

long long digitSum(long long x){
  long long sum=0;
  while(x>0){
    sum += x%10;
    x/=10;
  }
  return sum;
}

int main(){
  long long t;
  cin>>t;
  while(t--){
    long long n,k;
    cin>>n>>k;
    n++;
    while(true){
      long long s = digitSum(n);
      if(s==k){
        cout<<n<<endl;
        break;
      }
      if(s<k){
        long long diff = k-s;
        long long factor=1;
        long long temp=n;
        while(temp>0 && diff>0){
          long long d = temp%10;
          long long add = min(9-d, diff);
          n += add*factor;
          diff -= add;
          temp/=10;
          factor*=10;
        }
        if(diff>0) n += diff*factor;
      } else {
        long long factor=1;
        while((n/factor)%10==9) factor*=10;
        n = ((n/factor)+1)*factor;
      }
    }
  }
  return 0;
}





