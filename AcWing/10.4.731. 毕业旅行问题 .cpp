
//10.4.731. 毕业旅行问题 
小明目前在做一份毕业0.的规划。
打算从北京出发，分别去若干个城市，然后再回到北京，每个城市之间均乘坐高铁，且每个城市只去一次。
由于经费有限，希望能够通过合理的路线安排尽可能的省些路上的花销。
给定一组城市和每对城市之间的火车票的价钱，找到每个城市只访问一次并返回起点的最小车费花销。
注意：北京为1号城市。
输入格式
城市个数n。
城市间的车票价钱n行n列的矩阵 m[n][n]
输出格式
输出一个整数，表示最小车费花销。
数据范围1<n≤20,包括北京
车票价格均不超过1000元。
输入样例：
4
0 2 6 5
2 0 4 4
6 4 0 2
5 4 2 0
输出样例：
13
说明
共4个城市，城市1和城市1的车费为0，城市1和城市2之间的车费为2，城市1和城市3之间的车费为6，城市1和城市4之间的车费为5，以此类推。
假设任意两个城市之间均有单程票可买，且价格均在1000元以内，无需考虑极端情况。

//有限集的最优化问题:在有限集合中寻找最优路径

#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N=20,M=1<<N;

int n;
int a[N][N];//记录矩阵
int f[M][N]；//访问过M这些点后，最终停留在N点的最短路径，如f[10111][2]:已经访问过 1 2 3 5 这些城市，最终的位置在城市2的最短路径

int main(){
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    
    memset(f,0x3f,sizeof f);
    
    f[1][0]=0;
    
    for(int i=1;i<(1<<n);i+=2){//初始值是1，每次+2，因为是从0点出发，所以1永远是已经访问过的，每次+2保证最低位永远是1
        for(int j=0;j<n;j++){  //遍历最终位置  注意：j的初始值是可以是1(因为城市0是起点，j不会在没有访问完其他城市就访问0)，但是k的初始值必须是0(城市j可以由城市0走来)
            if(i>>j&1){  //最终位置在访问过的城市中
                for(int k=0;k<n;k++){//在f[i][j]中寻找一个点k，k在i 访问过的城市中，k!=j，要使得f+a[k][j]最小,
                    if(i-(1<<j)>>k&1){
                        f[i][j]=min(f[i][j],f[i-(1<<j)][k]+a[k][j]);//因为 i>=i-(1<<j) 所以当遍历到i时，i-(1<<j)已经遍历过了
                    }
                }
            }
        }
    }
    int res=0x3f3f3f;
    for(int i=0;i<n;i++)res=min(res,f[(1<<n)-1][i]+a[i][0]);//所有位置都访问过了，最终停留在i点，遍历一遍所有的i，求其中最小值
    cout<<res<<endl;
    return 0;
}