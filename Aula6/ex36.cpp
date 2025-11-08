#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

bool left_turn(Point &p0,Point &p1,Point &p2) {
    int x0 = p0.x, x1 = p1.x, x2 = p2.x;
    int y0 = p0.y, y1 = p1.y, y2 = p2.y;
    return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0) > 0;
}


Point p1;

bool compPolar(Point &p, Point &q) {
    return left_turn(p1,p,q);
}

int bottomVertex(vector<Point> & pts) {
    int bottom = 0;
    for(int i=1; i < (int)pts.size(); i++) {
        if (pts[i].y < pts[bottom].y ||
            (pts[i].y == pts[bottom].y && pts[i].x < pts[bottom].x)) {
            bottom = i;
            }
    }
    return bottom;
}

void output(stack<Point> & s){
    if (!s.empty()){
        Point p = s.top();
        s.pop();
        output(s);
        cout << p.x << " " << p.y << endl;
    }
}

void GrahamScan(vector<Point> & pts) {
    int bottom = bottomVertex(pts);
    swap(pts[0],pts[bottom]);
    p1 = pts[0];
    sort(pts.begin()+1, pts.end(), compPolar);
    stack<Point> s;
    s.push(pts[0]);
    s.push(pts[1]);
    int k = 2;
    while (k < (int)pts.size()) {
        Point top = s.top(); s.pop();
        Point next_to_top = s.top();
        if (left_turn(next_to_top, top, pts[k])){
            s.push(top);
            s.push(pts[k]);
            k++;
        }
    }
    cout<<s.size()<<endl;
    output(s);
}

int main() {
    int n;
    cin >> n;
    vector<Point> pts(n);
    for(int i=0; i< n; i++){
        cin >> pts[i].x >> pts[i].y;
    }
    GrahamScan(pts);
    return 0;
}
