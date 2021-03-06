


//15.3.1262. 鱼塘钓鱼 


有 
N
个鱼塘排成一排，每个鱼塘中有一定数量的鱼，例如：
N=5
 时，如下表：
鱼塘编号                                				1             2                 3              4             5
第1分钟能钓到的鱼的数量（1..1000）      				10           14                20              16            9
每钓鱼1分钟钓鱼数的减少量（1..100)     				    2             4					6				5			 3
当前鱼塘到下一个相邻鱼塘需要的时间（单位：分钟）        3			  5					4				4			 

即：在第 1个鱼塘中钓鱼第 1分钟内可钓到 10条鱼，第 2分钟内只能钓到 8条鱼，……，第 5分钟以后再也钓不到鱼了。
从第 1个鱼塘到第 2个鱼塘需要 3分钟，从第 2个鱼塘到第 3个鱼塘需要 5分钟，……
给出一个截止时间 T，设计一个钓鱼方案，从第 1个鱼塘出发，希望能钓到最多的鱼。假设能钓到鱼的数量仅和已钓鱼的次数有关，且每次钓鱼的时间都是整数分钟。

输入格式
共 5行，分别表示：第 1行为 N；
第 2行为第 1分钟各个鱼塘能钓到的鱼的数量，每个数据之间用一空格隔开；
第 3行为每过 1分钟各个鱼塘钓鱼数的减少量，每个数据之间用一空格隔开；
第 4行为当前鱼塘到下一个相邻鱼塘需要的时间；
第 5行为截止时间 T。

输出格式
一个整数（不超过2^31−1），表示你的方案能钓到的最多的鱼。

数据范围
1≤N≤100
1≤T≤1000
输入样例：
5
10 14 20 16 9   //鱼塘每分钟可钓的鱼
2 4 6 5 3       //每分钟的减少
3 5 4 4         //到下一个鱼塘的时间
14				//总时间
输出样例：
76


//其实是一个多路归并问题，采用枚举的方法，例题为例，分别求出前1个鱼塘，前2个鱼塘...前5个鱼塘的最多可钓的鱼，求最大，注意，增加一个鱼塘，意味着在路上的时间增加，可钓鱼的时间减少，//注意：为了尽量减少在路上的时间，我们认定每段路只走一次，在某个鱼塘钓够以后，再去下一个鱼塘。

#include<iostream>
#include<queue>

using namespace std;

const int N=110;

int n,t;
int a[N],b[N],c[N];

int work(int x,int y){  //x:前x个鱼塘可使用，y：总时间-在路上的时间
    priority_queue<pair<int,int>>pq;
    for(int i=1;i<=x;i++){
        pq.push({a[i],i}); 
    }
    int res=0;
    while(y>0){
        auto w=pq.top();
        pq.pop();
        res+=w.first;//求当前鱼塘的最大值
        int k=max(0,w.first-b[w.second]); //选择的鱼塘减去每分钟减少额，重新放到堆中，
        pq.push({k,w.second});
        y--;
    }
    return res;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>b[i];
    for(int i=1;i<=n-1;i++)cin>>c[i],c[i]+=c[i-1]; //c[i]；第i个鱼塘到第一个鱼塘所用时间，
    cin>>t;
    
    int res=0;
    for(int i=0;i<=n-1;i++){
        res=max(res,work(i+1,t-c[i]));
    }
    cout<<res<<endl;
    return 0;
}