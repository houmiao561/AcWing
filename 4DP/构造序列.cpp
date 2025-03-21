#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXLEN = 1010;
int n,E;
int arr[MAXLEN];
int f[MAXLEN][MAXLEN]; // 所有只考虑前i项，且总和是j的情况，存的数就是方案数
//f[i][j]代表从前i个数里面选，总体积等于j的选法数量
//f[i][j]代表从前i个数里面选，总体积等于j的选法数量
//f[i][j]代表从前i个数里面选，总体积等于j的选法数量
//f[i][j]代表从前i个数里面选，总体积等于j的选法数量
//f[i][j]代表从前i个数里面选，总体积等于j的选法数量
//f[i][j]代表从前i个数里面选，总体积等于j的选法数量
//f[i][j]代表从前i个数里面选，总体积等于j的选法数量
//f[i][j]代表从前i个数里面选，总体积等于j的选法数量
vector<vector<int>> sumTemp;

int main () {
    cin >> n;
    for (int i = 1; i<=n; i++) cin >> arr[i];
    cin >> E;
    // 初始输入完成
    
    if (arr[1] * 1 == E) {
        f[1]++;
        sumTemp.push_back({arr[1]});
    }
    if (arr[1] * (-1) == E){
        f[1]++;
        sumTemp.push_back({arr[1]});
    } 
    // cout << sumTemp[0][0];
    
    for (int i = 0; i<=n; i++) {
        for (int j = 0; j<sumTemp[i-1].size(); j++) {
            if ( E-arr[i] == sumTemp[j] ) {
                f[i]++;
            }
            if ( E+arr[i] == sumTemp[j] ) {
                f[i]++;
            }
        }
    }
    // cout << f[1];
    
}





#include<iostream>
using namespace std;
#include<algorithm>
#include<cstring>
const int mod=1e9+7;
int main(){
    int n,E,S=0;
    cin>>n;
    int a[n+1];
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++) cin>>a[i],S+=a[i];
    cin>>E;
    if((S+E)%2==1||S+E<0){//如果不能整除2或者S+E是负数（比如E给了一个-999999）就无解，返回0
        cout<<"0"<<endl;
        return 0;
    }
    
    int V=(E+S)/2;//V背包容量
    
    int f[n+1][V+1];//f[i][j]代表从前i个数里面选，总体积等于j的选法数量
    memset(f,0,sizeof(f));
    f[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=V;j>=0;j--){//注意j要从0开始，因为有可能给的(E+S)/2恰好等于0
            if(j<a[i]) f[i][j]=f[i-1][j];
            else f[i][j]=(f[i-1][j]+f[i-1][j-a[i]])%mod;
        }
    }

    cout<<f[n][V];

    return 0;
}


f[i][j]表示只在前i个数中选，选中的这些数的和必须正好等于j，所有选法的集合
它的值（也就是状态属性）是选法集合中的选法数量
状态转移：f[i][j]分为两种情况：一种是我们虽然可以在前i个数中选，但是我们不选i






作者：Baitlo
链接：https://www.acwing.com/solution/content/225022/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
