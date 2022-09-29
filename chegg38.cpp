#include<iostream>
#include<ctype.h>//header file for tolower() function
#include<cstring>
using namespace std;
int dp[1001][1001];
int main()
{
	char s1[1001],s2[1001],result[1001];
	cin.getline(s1,1001);//getline takes string with spaces
	//cin.ignore();//After the previous getline(), newline is stored in the buffer.
	//So to remove that we use cin.ignore()
	cin.getline(s2,1001);
	int l = 0,s=-1;//l will be our length of the common substring,s =starting point of our substring
	for(long unsigned i=0;i<=strlen(s1);i++){
		for(long unsigned j=0;j<=strlen(s2);j++){
			if(i==0||j==0){//there are 0 length substring. so the common substring will be having 0 length
				dp[i][j] = 0;
			}
			//if the strings have char in common, we increase the length
			else if(tolower(s1[i-1])==tolower(s2[j-1])){
				
				dp[i][j] = dp[i-1][j-1]+1;
				
				if(l<dp[i][j]){//storing max length l and s;
					l = dp[i][j];
					s = i-l;
				}
				
			}
			else
				dp[i][j] = 0;
		}
	}
	int k = 0;
	if(l==0){//If the length is 0, there exists no common substring
		cout<<"There exists no common substring.\n";
	}
	else{//storing our result
		for(int i=s;i<s+l;i++){
			result[k++] = s1[i];
		}
		result[k] = '\0';
		cout<<result<<endl;
	}
	
	return 0;
}
