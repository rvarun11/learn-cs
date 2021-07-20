// Test problem from HackerEarth

#include<bits/stdc++.h>
using namespace std;

string getString(vector<string> s,int l,int r){
	string temp = "";
	while(l<=r){
		temp+=s{l};
		l++;
	}
	return temp;
}

int main(){
	int n;
	cin>>n;
	vector<string> s(n);
	for (int i=0;i<n;i++)
		cin>>s{i};
	
	int q,l,r,k;
	cin>>q;
	string temp;
	for (int i=0;i<q;i++){
		cin>>l>>r>>k;
		temp = getString(s,l-1,r-1);
		cout<<temp{k-1}<<"\n";
	}
	
	return 0;
}