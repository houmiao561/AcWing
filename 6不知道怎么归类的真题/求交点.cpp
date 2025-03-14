#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct PDD {
    double x, y;
}PDD;
const int MIN = 1e-8;

double Cross(PDD a, PDD b) {
    return a.x * b.y - a.y * b.x;
}


// 模拟的思路我写不出来
int main() {
    PDD p,v,q,u;
    scanf( "%lf %lf %lf %lf", &p.x, &p.y, &v.x, &v.y );
    scanf( "%lf %lf %lf %lf", &q.x, &q.y, &u.x, &u.y );
    
    v.x -= p.x;
    v.y -= p.y;
    u.x -= q.x;
    u.y -= q.y;
    
    if( abs( Cross(u,v) ) <= MIN ) {
        cout << "Parallel or coincident" << endl;
    } else {
        PDD w = {p.x - q.x, p.y - q.y};
        double t = Cross(w,u) / Cross(u,v);
        PDD res = {p.x + t*v.x, p.y + t*v.y};
        printf("%.2lf %.2lf", res.x, res.y);
    }

    return 0;
}