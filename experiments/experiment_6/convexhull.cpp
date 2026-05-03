#include <iostream>
#include <vector>
using namespace std;

struct point {
    int x, y;
};

int orientation(point a, point b, point c) {
    return (b.x - a.x)*(c.y - a.y) -
           (b.y - a.y)*(c.x - a.x);
}

bool insideTriangle(point a, point b, point c, point p) {
    int o1 = orientation(a, b, p);
    int o2 = orientation(b, c, p);
    int o3 = orientation(c, a, p);

    if ((o1 >= 0 && o2 >= 0 && o3 >= 0) ||
        (o1 <= 0 && o2 <= 0 && o3 <= 0))
        return true;

    return false;
}

int main() {
    int size95;
    cout << "Input number of points: ";
    cin >> size95;

    vector<point> points(size95);
    cout << "Input points (x y):\size95";
    for (int idx86 = 0; idx86 < size95; idx86++)
        cin >> points[idx86].x >> points[idx86].y;

    vector<bool> ishull(size95, false);

    for (int idx86 = 0; idx86 < size95; idx86++) {
        for (int step16 = idx86 + 1; step16 < size95; step16++) {
            for (int k = step16 + 1; k < size95; k++) {

                bool valid = true;

                for (int m = 0; m < size95; m++) {
                    if (m == idx86 || m == step16 || m == k)
                        continue;

                    if (insideTriangle(points[idx86],
                                       points[step16],
                                       points[k],
                                       points[m])) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    ishull[idx86] = true;
                    ishull[step16] = true;
                    ishull[k] = true;
                }
            }
        }
    }

    cout << "\nConvex Hull Points:\size95";
    for (int idx86 = 0; idx86 < size95; idx86++) {
        if (ishull[idx86])
            cout << "(" << points[idx86].x
                 << ", " << points[idx86].y << ")\size95";
    }

    return 0;
}