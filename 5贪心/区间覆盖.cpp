// #include <iostream>
// #include <algorithm>
// using namespace std;
// const int MAXLEN = 100010;

// int n;
// int startLeft, startRight;
// int res = 0;
// struct Range {
//     int l,r;
//     bool operator < (const Range &W) const {
//         return l<W.l ? true : false;
//     }
// } Range[MAXLEN];
// bool success = false;

// int main() {
//     cin >> startLeft >> startRight;
//     cin >> n;
//     for (int i = 0; i<n; i++) cin >> Range[i].l >> Range[i].r;
//     sort(Range, Range+n);
//     // 初始化完成
    
//     for (int i = 0; i<n; i++) {
//         int l = i, r = -2e9;
//         while ( l < n && Range[l].l <= startLeft ) {
//             r = max(r,Range[i].r);
//             l++;
//         } 
//         if( r < startLeft ) {
//             res = -1;
//             break;
//         }
//         res ++;
//         if( r >= startRight ) {
//             success = true;
//             break;
//         } 
//         startLeft = r;
//         i = l-1;
//     }
//     if ( !success ) {
//         res = -1;
//     }
//     cout << res;
// }

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

int n;
struct Range
{
    int l, r;
    bool operator< (const Range &W)const
    {
        return l < W.l;
    }
}range[N];

int main()
{
    int st, ed;
    scanf("%d%d", &st, &ed);
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ )
    {
        int l, r;
        scanf("%d%d", &l, &r);
        range[i] = {l, r};
    }

    sort(range, range + n);

    int res = 0;
    bool success = false;
    for (int i = 0; i < n; i ++ )
    {
        int j = i, r = -2e9;
        while (j < n && range[j].l <= st)
        {
            r = max(r, range[j].r);
            j ++ ;
        }

        if (r < st)
        {
            res = -1;
            break;
        }

        res ++ ;
        if (r >= ed)
        {
            success = true;
            break;
        }

        st = r;
        i = j - 1;
    }

    if (!success) res = -1;
    printf("%d\n", res);

    return 0;
}