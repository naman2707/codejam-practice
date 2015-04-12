/*
 * StandingOvation.cpp
 *
 *  Created on: Apr 10, 2015
 *      Author: ngoyal
 */

#include<iostream>
#include<cstring>
#define MAX 1005
using namespace std;
int solve(int shymax,char * shyCount){
	int stoodPeople=0;
	int newPeopleNow=0;
	int newPeopleTotal=0;
	for(int i=0;i<strlen(shyCount);i++){
		newPeopleNow=0;
		int shyPeopleCount=shyCount[i]-'0';
		if(shyPeopleCount!=0 && i>stoodPeople){
			newPeopleNow=(i-stoodPeople);
		}
		stoodPeople+=(newPeopleNow+shyPeopleCount);
		newPeopleTotal+=newPeopleNow;
	}
	return newPeopleTotal;
}

int main(){
	int T;
	int caseNum=1;
	cin>>T;
	while(T){
		int shyMax;
		char shyCount[MAX];
		cin>>shyMax;
		cin>>shyCount;
		int result=solve(shyMax,shyCount);
		cout<<"Case #"<<caseNum<<": "<<result<<"\n";
		caseNum++;
		T--;
	}
}

