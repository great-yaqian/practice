#include <iostream>

using namespace std;

int gcd(int x, int y){ // euclidean algorithm 
    if(y == 0)
        return x;
    else
        return gcd(y, x % y); //recursive gcd
}

int main() {
    int x, y;
    cin >> x >> y;
    cout << gcd(x, y) << endl;
}
