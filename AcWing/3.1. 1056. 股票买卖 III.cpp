//13. 1056. 股票买卖 III  

/*
给定一个长度为 N的数组，数组中的第 i 个数字表示一个给定股票在第 i天的价格。
设计一个算法来计算你所能获取的最大利润。你最多可以完成两笔交易。
注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

输入格式
第一行包含整数 N，表示数组长度。
第二行包含N个不大于 10^9的正整数，表示完整的数组。
输出格式
输出一个整数，表示最大利润。
数据范围

1≤N≤10^5
输入样例1：
8
3 3 5 0 0 3 1 4
输出样例1：
6
输入样例2：
5
1 2 3 4 5
输出样例2：
4
输入样例3：
5
7 6 4 3 1
输出样例3：
0
样例解释
样例1：在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。共得利润 3+3 = 6。
样例2：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
样例3：在这种情况下, 不进行任何交易, 所以最大利润为 0。

*/




#include<iostream>
#include <algorithm>

using namespace std;

const int N=1e5+10;

int  list[N],in[N],out[N];
int n;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>list[i];
	}
	out[1]=0;
	int minv=list[1];
	for(int i=2;i<=n;i++){   //第i天卖出的最大收益
		out[i]=max(out[i-1],list[i]-minv);
		minv=min(list[i],minv);
	}
	
	in[n]=0;
	int maxv=list[n];
	for(int i=n-1;i>0;i--){  //第i天买入的最大收益
		in[i]=max(in[i+1],maxv-list[i]);
		maxv=max(maxv,list[i]);
	}

	int  res=0;
	for(int i=2;i<=n;i++){
		res=max(res,out[i]+in[i+1]);   //以第i天为分界的最大收益
	}
	cout<<res<<endl;
	return 0;
}

//这道题的核心思想是预处理，in[i]和out[i],分别表示第i天买入和卖出的最大利润，因为不能同时持有股票，所以以第i天为节点，第i天以前和第i天以后都交易了一个股票，两次的最大收益之和就是第i天的当前的最大收益，然后遍历一遍i，就是最大收益