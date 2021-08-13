#include <iostream>
#include <cmath>
#define PI 3.1415926535
#define G 10.00

using namespace std;

int main(){

    long double V = 0, a = 0, K = 0;
    cin>>V>>a>>K;

    long double energy = 0.5 * V * V;
    long double distance = 0;
    long double angle = a * PI / 180.0;

    while(energy > 0.0000000000001){
        distance = (V * V * sin(2.0 * angle) / G) + distance;
        energy = (energy / K);
        V = sqrt(energy*2.0);
    }
    printf("%.2f\n", distance);
    return 0;
}
