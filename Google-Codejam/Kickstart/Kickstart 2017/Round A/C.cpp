#include <iostream>
#include <iomanip>

using namespace std;
int ball[2010][4];
int q;
bool vs[2010];

bool cover(int xs, int xe, int ys, int ye, int zs, int ze) {
    int e = xe - xs;
    for (int i = 1; i <= q; i++) {
        if (ball[i][0] - ball[i][3] >= xs && ball[i][0] + ball[i][3] <= xe
            && ball[i][1] - ball[i][3] >= ys && ball[i][1] + ball[i][3] <= ye
            && ball[i][2] - ball[i][3] >= zs && ball[i][2] + ball[i][3] <= ze)
            vs[i] = true;
        else vs[i] = false;
    }
    int minx = 300000000, maxx = -300000000;
    int miny = 300000000, maxy = -300000000;
    int minz = 300000000, maxz = -300000000;
    for (int i = 1; i <= q; i++) {
        if (!vs[i]) {
            minx = min(minx, ball[i][0] - ball[i][3]);
            maxx = max(maxx, ball[i][0] + ball[i][3]);
            miny = min(miny, ball[i][1] - ball[i][3]);
            maxy = max(maxy, ball[i][1] + ball[i][3]);
            minz = min(minz, ball[i][2] - ball[i][3]);
            maxz = max(maxz, ball[i][2] + ball[i][3]);
        }
    }
    if (maxx-minx <= e && maxy-miny <= e && maxz-minz <= e) return true;
    else    return false;
}

int main()
{
    freopen("/Users/fushanshan/Downloads/C-small-practice.in","r",stdin);
    freopen("/Users/fushanshan/Downloads/C-small-attempt2.out","w",stdout);
    int num;
    cin >> num;
    for (int t = 0; t < num; t++) {
        cout << "Case #" << t+1 << ": ";
        cin >> q;
        int minx = 300000000, maxx = -300000000;
        int miny = 300000000, maxy = -300000000;
        int minz = 300000000, maxz = -300000000;
        for (int i = 1; i <= q; i++)
            for (int j = 0; j < 4; j++)
                cin >> ball[i][j];
        for (int i = 1; i <=q; i++) {
            minx = min(minx, ball[i][0] - ball[i][3]);
            maxx = max(maxx, ball[i][0] + ball[i][3]);
            miny = min(miny, ball[i][1] - ball[i][3]);
            maxy = max(maxy, ball[i][1] + ball[i][3]);
            minz = min(minz, ball[i][2] - ball[i][3]);
            maxz = max(maxz, ball[i][2] + ball[i][3]);
        }
        int rs = 0, re = 500000000;
        while (rs < re) {
            int r = (rs + re) / 2;
            if (cover(minx, minx+r, miny, miny+r, minz, minz+r)
                || cover(minx, minx+r, miny, miny+r, maxz-r, maxz)
                || cover(minx, minx+r, maxy-r, maxy, minz, minz+r)
                || cover(minx, minx+r, maxy-r, maxy, maxz-r, maxz)
                || cover(maxx-r, maxx, miny, miny+r, minz, minz+r)
                || cover(maxx-r, maxx, miny, miny+r, maxz-r, maxz)
                || cover(maxx-r, maxx, maxy-r, maxy, minz, minz+r)
                || cover(maxx-r, maxx, maxy-r, maxy, maxz-r, maxz))
                re = r;
            else
                rs = r+1;
        }
        cout << rs << endl;
    }
    return 0;
}

