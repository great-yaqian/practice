#include <iostream> 
#include <algorithm> 

using namespace std;

void findMaxABC(int N){
    int A, B, C;
    bool found = false;
    for( C=0; C<=N; C++){
        int AB = N - C;
        if( AB % 3 == 0){
            for( B=0; B<=AB; B++)
                if( (B+C) %5 == 0 ){
                    A = AB - B;
                    found = true;
                    break;
                    }
            if ( found )
                break;
            }
        }
    if( found )
        cout << A << " " << B << " " << C << endl;
    }
            
int main() {
    int N;
    cin >> N;
    if ( N % 7 == 0)
        findMaxABC(N);
    return 0;
}



