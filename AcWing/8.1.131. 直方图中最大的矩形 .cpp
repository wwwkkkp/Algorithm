

直方图是由在公共基线处对齐的一系列矩形组成的多边形。 
矩形具有相等的宽度，但可以具有不同的高度。 
例如，图例左侧显示了由高度为2,1,4,5,1,3,3的矩形组成的直方图，矩形的宽度都为1：
 
通常，直方图用于表示离散分布，例如，文本中字符的频率。 
现在，请你计算在公共基线处对齐的直方图中最大矩形的面积。 
图例右图显示了所描绘直方图的最大对齐矩形。

输入格式
输入包含几个测试用例。 
每个测试用例占据一行，用以描述一个直方图，并以整数n开始，表示组成直方图的矩形数目。
然后跟随n个整数h1，…，hn。 
这些数字以从左到右的顺序表示直方图的各个矩形的高度。 
每个矩形的宽度为1。
同行数字用空格隔开。
当输入用例为n=0时，结束输入，且该用例不用考虑。

输出格式
对于每一个测试用例，输出一个整数，代表指定直方图中最大矩形的区域面积。
每个数据占一行。
请注意，此矩形必须在公共基线处对齐。
数据范围
1≤n≤100000
0≤hi≤1000000000
输入样例：
7 2 1 4 5 1 3 3
4 1000 1000 1000 1000
0
输出样例：
8
4000



//单调栈
#include<iostream>
using namespace std;

const int N=100010;

typedef long long ll;

int n;
int h[N],l[N],r[N];//l[i]表示以第i数的高度为准，,向左第一个比h[i]低的数的位置，r[N]表示以第i数的高度为准，向右第一个比h[i]低的数的位置，h[N]是高度集
int q[N];//单调栈，储存的是位置，h[q[i]]表示高度，h[q[i]]是单调递增的， 当遍历第j个数的时候，在栈中找到第一个低于h[j]的值，同时更新q,q[i+1]=j;前面大于h[j]的数都作废了，h[j]成为新的阈值，低于该阈值可以通过，高于该阈值不能通过
//以 2 1 4 3 1 3 3 中的第4个数3为例，向左可以延伸到头或者是左边某个高度低于3，显然1是低于3的，所以l[4]=2;同理r[i]=5,那以3位高度的延伸长度就是5-2-1=2；

int main(){
    while(cin>>n,n){
        for(int i=1;i<=n;i++)cin>>h[i];
        h[0]=h[n+1]=-1;
        
        int tt=0;//单调栈计数
        q[0]=0; //左端点，最多只能到编号0，
        for(int j=1;j<=n;j++){  //每个点左边延伸长度
            while(h[q[tt]]>=h[j]) tt--;  //寻找第一个比h[j]第的数，
            l[j]=q[tt];
            tt++;
            q[tt]=j;//更新单调栈
        }
        tt=0;
        q[0]=n+1; //开始位置是n+1,
        for(int i=n;i>=1;i--){ //每个点右边的延伸长度
            while(h[q[tt]]>=h[i])tt--;  //和左边同理
            r[i]=q[tt];
            tt++;
            q[tt]=i;
        }
        ll res=0;//大于10^9,就不能用int，要用long long
        for(int i=1;i<=n;i++)
            res=max(res,(ll)h[i]*(r[i]-l[i]-1));  //算最大面积，即每个结点总延伸长度*该结点高度
        cout<<res<<endl;
    }
}
