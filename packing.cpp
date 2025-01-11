#include <cstdio>

using namespace std;
// packing problem:
// two boats, dead weight capacity is c1, c2 respectively,
// n containers, weight wi, total weight is less than c1+c2, 
// ensure that whether boats can load all of containers.


int c1, c2, n;
int w[100]; //contains' weight
int cw; //c1 current loading weight
int r;  //surplus containers' weight
int bestw; //c1 current best weight
int x[100]; //current solution
int bestx[100]; //current best solution

void BackTrack (int i) {
    if ( i>n ) {
        if (cw > bestw) { //current solution is better than bestw, update it
            for (int j=1; j<=n; j++)
                bestx[j] = x[j];
            bestw = cw;
            }
        return;
        }
    r -= w[i];
    if (cw+w[i] <= c1) {  //if i can be put in c1, then put it
        x[i] = 1;
        cw += w[i];
        BackTrack(i+1); // recursive next one 
        cw -= w[i];
        }//if
    if (cw+r > bestw) { // 
        x[i] = 0;
        BackTrack(i+1);
        }
    r += w[i];
    }//BackTrack

int main() {
    while(scanf("%d %d %d", &c1, &c2, &n) && n) {
        cw = 0;
        r = 0;
        bestw = 0;
        for(int i=1; i<=n; i++) {
            scanf("%d", &w[i]);
            r += w[i];   // r is total weight
            }
        BackTrack(1);   // begin at first one
        if (r-bestw <= c2)  // remained box can be put 
            printf("Yes");
        else
            printf("No");
        }
    return 0;
    }
