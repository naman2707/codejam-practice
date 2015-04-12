/*
 * GBusCount.cpp
 *
 *  Created on: Apr 11, 2015
 *      Author: ngoyal
 */

#include<iostream>
#include<cstring>
using namespace std;

int main(){
	int T;
	cin>>T;
	int caseNo=1;
	while(T--){
		int N;
		cin>>N;
		int a[5010],b[5010];
		int main[5010], cummulative[5010];
		int max=-1;
		memset(main,0,sizeof(main));
		for(int i=0;i<N;i++){
			cin>>a[i];
			cin>>b[i];
			main[a[i]]+=1;
			main[b[i]+1]-=1;
			if(b[i]>max)
				max=b[i];
		}
		memset(cummulative,0,sizeof(cummulative));
		cummulative[0]=main[0];
		for(int i=1;i<max;i++){
			cummulative[i]=cummulative[i-1]+main[i];
		}
		int P;
		cin>>P;
		cout<<"Case #"<<caseNo<<": ";
		for(int i=0;i<P;i++){
			int x;
			cin>>x;
			cout<<cummulative[x]<<" ";
		}
		caseNo++;
		cout<<"\n";
	}

}

