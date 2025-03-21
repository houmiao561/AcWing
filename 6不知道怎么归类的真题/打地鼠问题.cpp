#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
const int MAXLEN = 100010;
long long n,d;
long long arr[MAXLEN];
stack<long long> st;

int main() {
    cin >> n >> d;
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr+n);
    st.push(arr[0]);
    for ( int i = 1; i<n; i++ ) {
        if (arr[i] - st.top() >=d || st.top() - arr[i] >=d) {
            st.push(arr[i]);
        }
    }
    
    cout << st.size();
}