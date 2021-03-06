//22.30. 正则表达式匹配 
	

请实现一个函数用来匹配包括'.'和'*'的正则表达式。
模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。
在本题中，匹配是指字符串的所有字符匹配整个模式。
例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配。
样例
输入：

s="aa"
p="a*"

输出:true


class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size(),m=p.size();
		vector<vector<bool>> v(n+1,vector<bool>(m+1,false));  //v[i][j]，s的前i个数 和 p的前j个数 是否匹配
		s=' '+s,p=' '+p;
		v[0][0]=1;
		for(int i=0;i<=n;i++){
			for(int j=1;j<=m;j++){
			
				if(j+1<=m && p[j+1]=='*')continue;//如果下一个是数是*，当前数就不做处理，
				 
				if(p[j]!='*')  //如果当前数不是星，就是正常的比较
					v[i][j]=i>0&&(v[i-1][j-1] && (s[i]==p[j] || p[j]=='.'));
					
				else if( p[j]=='*' ){ //如果当前数是星，则要看 * 代表了多少个数，有可能是0个，有可能是1个.....
				    
					v[i][j]=v[i][j-2]||(i>0&&v[i-1][j]&&(s[i]==p[j-1]||p[j-1]=='.'));
				
				}
			}
		}
		return v[n][m];
    }
};


// 我们把  b* 格式的数当成一个数，一起处理
分析当 p[j]=='*' 的情况，
如果*代表0个数，那就是  v[i][j]=v[i][j-2]
如果代表1个数，v[i][j]=v[i-1][j-2] && s[i]==p[j-1]
如果代表2个数，v[i][j]=v[i-2][j-2] && s[i]==p[j-1]  && s[i-1]==p[j-1]
如果代表3个数，v[i][j]=v[i-3][j-2] && s[i]==p[j-1]  && s[i-1]==p[j-1]  &&  s[i-2]==p[j-1]
以此类推，
上面各式子中，只要有一个满足，那v[i][j]就等于真，所以是或的关系

v[i][j]=v[i][j-2] || v[i-1][j-2] && s[i]==p[j-1] || v[i-2][j-2] && s[i]==p[j-1] && s[i-1]==p[j-1] || v[i-3][j-2] && s[i]==p[j-1] && s[i-1]==p[j-1] && s[i-2]==p[j-1]..

简化上述式子
由上述式子可以推出
v[i-1][j]= v[i-1][j-2] ||  v[i-2][j-2] && s[i]==p[j-1] ||  v[i-3][j-2] && s[i]==p[j-1] && s[i-1]==p[j-1]...
所以
原式
v[i][j]= v[i][j-2] || (v[i-1][j]&&(s[i]==p[j-1]||p[j-1]=='.'));




