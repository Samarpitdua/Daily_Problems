class Solution {
public:int index;
	long get(string s){
		if(index>=s.size()) return 0;
		long res=0;
		char sign='+';
		while(index<s.size()){
			long cur=0;
		if(s[index]=='('){
			index++;
			cur=get(s);
		}
		else{
			while(index<s.size() && s[index]>='0' && s[index]<='9'){
				cur=(cur*10+s[index]-'0');
				index++;
			}
		}
			if(sign=='+'){
				res+=cur;
			}
			if(sign=='-'){
				res-=cur;
			}
			if(s[index]==')'){
			index++;
			break;
		}
			if(index<s.size()){
				sign=s[index];}
			index++;
		}
		return res;
	}
	int calculate(string s) {
		string ss;
		for(int i=0;i<s.size();i++){
			if(s[i]==' ')continue;
			ss+=s[i];}
		index=0;
		long ans=get(ss);
		return ans;
	}
};