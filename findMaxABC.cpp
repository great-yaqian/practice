#include <iostream> 
#include <algorithm> 

using namespace std;

void findMaxABC(int N) {
    int maxA = 0, maxB = 0, maxC = 0;
    bool found = false;
    for (int C = 0; C <= N; ++C) {
        if ((N - C) % 7 == 0) {
            int AB = N - C;
            for (int B = 0; B <= AB; ++B) {
                int A = AB - B;
                if ((A + B) % 3 == 0 && (B + C) % 5 == 0){
                    maxA = A;
                    maxB = B;
                    maxC = C;
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
    }
    if (found) 
        cout << "A: " << maxA << ", B: " << maxB << ", C: " << maxC << endl; 
    else 
        cout << "No solution found." << endl;
}

int main() {
    int N;
    cout << "Enter the value of N: ";
    cin >> N;

    if (N % 7 == 0) {
        findMaxABC(N);
    } else {
        cout << "N must be a multiple of 7." << endl;
    }

    return 0;
}

