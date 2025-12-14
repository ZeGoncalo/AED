#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs_distance(vector<int>& v, int r, int c, int p, int t) {
  vector<int> dist(r*c, -1);
  queue<int> q;
  dist[p] = 0;
  q.push(p);
  while (!q.empty()) {
    int x=q.front(); q.pop();
    if (x==t) return dist[x];
    int row=x/c;
    int col=x%c;
    int dr[4]={1, -1, 0, 0};
    int dc[4]={0, 0, 1, -1};
    for (int i=0;i<4;i++) {
      int nr=row+dr[i];
      int nc=col+dc[i];
      if (nr<0||nr>=r||nc<0||nc>=c) continue;
      int np=nr*c+nc;
      if (v[np]==-1) continue;
      if (dist[np]!=-1) continue;
      dist[np]=dist[x]+1;
      q.push(np);
    }
  }
  return -1;
}

int main() {
  int n;
  cin>>n;
  while (n--) {
    int r, c, p, t;
    cin>>r>>c;
    vector<int> v(r*c);
    char s;
    for (int i=0;i<r*c;i++) {
      cin>>s;
      if (s=='#') v[i]=-1;
      else v[i] = 0;
      if (s == 'P') p=i;
      if (s == 'T') t=i;
    }
    cout<<bfs_distance(v, r, c, p, t)<<endl;
  }
}
