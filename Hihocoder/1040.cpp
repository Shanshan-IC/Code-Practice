#include <iostream>
#include <set>

using namespace std;
struct point {
    int x, y;
    bool operator<(const point& p2)const
    {
        //优先判断横坐标
        if(x<p2.x||(x==p2.x&&y<p2.y))
            return true;
        return false;
    }
    bool operator==(const point& p2) const
    {
        return (x==p2.x&&y==p2.y);
    }
};
struct line {
    point p1;
    point p2;
    
};

bool fourPoints(line lines[4]) {
    set<point> s;
    for (int i=0; i<4; i++) {
        s.insert(lines[i].p1);
        s.insert(lines[i].p2);
    }
    return s.size()==4;
}

bool isValid(line lines[4]) {
    for (int i=1; i<4; i++) {
        if ((lines[i].p1.x-lines[i].p2.x)*(lines[0].p1.x-lines[0].p2.x) ==
            (lines[i].p1.y-lines[i].p2.y)*(lines[0].p1.y-lines[0].p2.y))
            continue;
        if ((lines[i].p1.x-lines[i].p2.x)*(lines[0].p2.y-lines[0].p1.y) ==
            (lines[0].p1.x-lines[0].p2.x)*(lines[i].p1.y-lines[i].p2.y))
            continue;
        return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    line lines[4];
    while (n--) {
        for (int i=0; i<4; i++) {
            cin >> lines[i].p1.x >> lines[i].p1.y >> lines[i].p2.x >> lines[i].p2.y;
        }
        if (!fourPoints(lines))
            cout << "NO" << endl;
        else {
            if (!isValid(lines))
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
        
    }
    
    return 0;
}