
//45. 跳跃游戏 II
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

你的目标是使用最少的跳跃次数到达数组的最后一个位置。

示例:

输入: [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
说明:

假设你总是可以到达数组的最后一个位置。


//滑动窗口 
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int s=0;
        for(int i=0;i<n;){
            int res=0;
            int k=i+1;
            for(int j=1;j<=nums[i];j++){//以[2,3,1,1,4]为例，当i=0时，选出跨1步或者2步的时候哪一个走的更远，这里是走1步，在选出走1,2,3步，哪一个走的最远，以此类推
                if(i+j<n&&res<nums[i+j]+i+j){
                    res=nums[i+j]+i+j;//能到达最远下标，窗口右端
                    k=i+j;	//窗口左端
                }
                if(i+j==n-1)return s+1;  //如果已经走到了，就退出，
            }  
            i=k;
            s++;
        }
        return 0;
    }
};


//这道题不能用反向推，因为无法直接求出n个数的最小值，如果硬求会增加时间复杂度，超时