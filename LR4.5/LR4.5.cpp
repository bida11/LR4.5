// Біда О. М., ІК-12. ЛР 4.5, варіант 1. Два сектори кола.
#include <iostream>
#include <iomanip>
#include <cmath>
#include <random>
using namespace std;

bool hit(double x, double y, double R)
{
    // Межа мішені належить області; hypot уникає переповнення.
    return hypot(x, y) <= R &&
        ((x >= 0 && y >= x) || (x <= 0 && y <= x));
}

int main()
{
    double R, x, y;
    cout << "R: ";
    if (!(cin >> R) || !isfinite(R) || R <= 0) {
        cerr << "Require R > 0\n"; return 1;
    }
    cout << "Enter 10 pairs x y\n";
    for (int i = 1; i <= 10; ++i) {
        if (!(cin >> x >> y) || !isfinite(x) || !isfinite(y)) {
            cerr << "Invalid point\n"; return 1;
        }
        cout << i << ": " << (hit(x, y, R) ? "hit" : "miss")
            << '\n';
    }
    // Незалежні координати з інтервалу [-R; R].
    mt19937 generator(random_device{}());
    uniform_real_distribution<double> value(-R, R);
    cout << "RANDOM SHOTS\n" << setw(4) << "No"
        << setw(12) << "x" << setw(12) << "y"
        << setw(10) << "result" << '\n';
    cout << fixed << setprecision(6);
    for (int i = 1; i <= 10; ++i) {
        x = value(generator); y = value(generator);
        cout << setw(4) << i << setw(12) << x << setw(12) << y
            << setw(10) << (hit(x, y, R) ? "hit" : "miss")
            << '\n';
    }
}
