#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

struct Point
{
    ll x, y;

    static ll ccw(Point a, Point b, Point c)
    {
        return a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x;
    }

    int sbm() const
    {
        if (x >= 0 && y >= 0) return 1;
        if (y >= 0) return 2;
        if (x <= 0) return 3;
        return 4;
    }

    bool operator<(const Point& r) const
    {
        if (this->sbm() != r.sbm()) return this->sbm() < r.sbm();
        return ccw({0, 0}, *this, r) > 0;
    }

    bool operator==(const Point& r) const
    {
        return x == r.x && y == r.y;
    }
};

vector<Point> v;
int n;

bool is_in(Point p)
{
    int idx = lower_bound(v.begin(), v.end(), p) - v.begin();
    if (Point::ccw({0, 0}, p, v[(idx) % n]) == 0) idx += 1;
    Point a = v[(idx) % n], b = v[(idx - 1 + n) % n];
    if (a == p || b == p) return true;
    ll cv = Point::ccw(b, a, p);
    if (cv > 0) return true;
    if (cv == 0)
    {
        return abs(p.x) <= max(abs(a.x), abs(b.x)) && abs(p.y) <= max(abs(a.y), abs(b.y));
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q, x = 0;
    cin >> n >> q;
    Point w, p;
    vector<Point> view;
    view.reserve(n);
    v.reserve(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p.x >> p.y;
        view.push_back(p);
        if (p < view[x]) x = i;
    }
    for (int i = 0; i < n; i++)
    {
        v.push_back(view[(i + x) % n]);
    }

    int la = 0;
    for (int i = 0; i < q; i++)
    {
        cin >> p.x >> p.y;
        if (i)
        {
            if (la)
            {
                p.x += p.x - w.x;
                p.y += p.y - w.y;
            }
            else
            {
                long long dx2 = p.x + w.x;
                long long dy2 = p.y + w.y;
                if (dx2 % 2)
                {
                    if (dx2 > 0) p.x = dx2 / 2;
                    else p.x = (dx2 + 1) / 2;
                }
                else p.x = dx2 / 2;
                if (dy2 % 2)
                {
                    if (dy2 > 0) p.y = dy2 / 2;
                    else p.y = (dy2 + 1) / 2;
                }
                else p.y = dy2 / 2;
            }
        }
        w = p;
        la = is_in(p) ? 1 : 0;
        cout << la << '\n';
    }
    return 0;
}
