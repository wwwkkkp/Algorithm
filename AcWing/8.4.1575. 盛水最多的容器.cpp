
//8.4.1575. 盛水最多的容器
给定 n个非负整数 a1,a2,…,an，表示平面上有 n条竖线，第 i条竖线的两个端点是(i,ai)和(i,0)。请找出两条竖线，使得它们与 x轴组成的容器能盛最多的水。
注意：不可以把线倾斜，并且 n≥2。
输入格式
第一行包含整数 n。第二行包含n个非负整数。

输出格式
输出一个整数，表示容器的最大盛水量。
数据范围
1≤n≤10^5
1≤ai≤10^4

输入样例：
9
1 8 6 2 5 4 8 3 7
输出样例：
49


//双指针法，从左右两边开始向中间遍历，当左边高度小于右边右边的时候，左边挪动一格，否则右边挪动一格，注意：当相等的时候，左右挪哪个都可以
/**
现在说明为什么双指针法就可以得到最大值，假设在i,k之间取得最大值( sm=min(hi,hk)*(i-k) )，并且左指针已经指向i,右指针在j,j>k,
如果h[i]<=h[j],那移动的就是i,就意味着取不到最大值了，但是当h[i]<=h[j]时，面积为s=hi*(i-k) ,s>sm,也就是说i,k不是最大值，相矛盾，
所以，如果i,k之间是最大值，那h[i]必然大于h[j]，移动j,直到k,所以，双指针法一定会选到最大值。
*/
#include<iostream>
using namespace std;

const int N=100010;

int n;
int f[N];
int l,r;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>f[i];
    l=1;r=n;
    int res=0;
    for(;l<r;){
        res=max(res,(r-l)*min(f[r],f[l]));
        if(f[r]>f[l]) l++;
        else r--;
    }
    cout<<res<<endl;
    return 0;
}