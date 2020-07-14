

//123. 买卖股票的最佳时机 III
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:

输入: [3,3,5,0,0,3,1,4]
输出: 6
解释: 在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
     随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
示例 2:

输入: [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。   
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。   
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
示例 3:

输入: [7,6,4,3,1] 
输出: 0 
解释: 在这个情况下, 没有交易完成, 所以最大利润为 0。


//
class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=p.size();
        if(n<=1)return 0;
        int left[50010],right[50010];
        left[n-1]=0;
        int maxl=p[n-1];
        for(int i=n-2;i>=0;i--){
            left[i]=max(left[i+1],maxl-p[i]); //第i天买入所获得的最大利润
            maxl=max(maxl,p[i]);
        }
        right[0]=0;
        int minl=p[0];
        for(int i=1;i<n;i++){
            right[i]=max(right[i-1],p[i]-minl); //第i天卖出所获得的最大利润
            minl=min(minl,p[i]);
           
        }
        int res=0;
        for(int i=0;i<n;i++){
            if(i==0)res=max(res,left[0]);
            if(i==n-1)res=max(res,right[n-1]);
            else{
                res=max(res,left[i+1]+right[i]);	//最大利润就是左边+右边的最大值
            }
        
        }
        return res;
    }
};