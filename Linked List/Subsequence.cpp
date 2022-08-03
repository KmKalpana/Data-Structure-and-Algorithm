#include <iostream>
#include <string.h>
using namespace std;
/*GFG
vector<string>subsequence(vector<string>&v,string p,string s)
	{
	    if(s.empty())
	    {
	             v.push_back(p);
	             return v;
	    }
	    char c=s[0];
	    v=subsequence(v,p+c,s.substr(1));
	   v= subsequence(v,p,s.substr(1));
	    return v;
	}
		vector<string> AllPossibleStrings(string s)
		{
		   vector<string>v;
		   v=subsequence(v,"",s);
		   sort(v.begin(),v.end());
		   v.erase(v.begin());
		   return v;
		}
*/
void subsequence(string p, string s)
{
    if(s.empty())
    {
        cout<<p<<endl;
        return ;
    }
    char ch=s[0];
    subsequence(p,s.substr(1));
    subsequence(p+ch,s.substr(1));
    
}
int main()
{
    string s="abc";
    subsequence("",s);
}