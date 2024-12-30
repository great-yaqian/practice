#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

void RGBtoHSL(vector<int> rgb ){
    auto result = minmax_element(rgb.begin(), rgb.end());
	//cout <<typeid(result).name() << endl;
    vector<int>::const_iterator min = result.first;
    vector<int>::const_iterator max = result.second;
    //cout << min << max << endl;
    float h, s, l;
    if(max == min)
        h = 0;
    else if(*max == rgb[0] && rgb[1]>=rgb[2])
        h = 60*(rgb[1] -rgb[2])/(*max - *min);
    else if(*max == rgb[0] && rgb[1]<rgb[2])
        h = 60*(rgb[1] -rgb[2])/(*max - *min) + 360;
    else if(*max == rgb[1])
        h = 60*(rgb[2] -rgb[0])/(*max - *min) + 120;
    else 
        h = 60*(rgb[0] -rgb[1])/(*max - *min) + 240;
    l = (*min + *max)/2;
    if(l == 0 || max== min)
        s = 0;
    else if(l< 0.5 && l>0)
        s = (*max - *min)/(*max + *min);
    else
        s = (*max - *min)/(2 - 2*l);
    cout << h << " " << s <<  " " <<  l << "\n" ;
}

int main() {
    int r, g, b;
    vector<int> rgb(3);
    cin >> rgb[0] >> rgb[1] >> rgb[2];
    RGBtoHSL(rgb);
    return 0;
    }
