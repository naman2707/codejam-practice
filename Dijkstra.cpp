/*
 * HousePancakes.cpp
 *
 *  Created on: Apr 10, 2015
 *      Author: ngoyal
 */

#include<iostream>
#include<cstring>
#define MAX 10005
using namespace std;

char* multiply(char a, char b) {
	if (a == '1') {
		char temp[2];
		temp[0] = b;
		return temp;
	}
	if (b == '1') {
		char temp[2];
		temp[0] = a;
		return temp;
	}
	if (a == b)
		return "-1";
	if (a == 'i' && b == 'j')
		return "k";
	if (a == 'i' && b == 'k')
		return "-j";
	if (a == 'j' && b == 'i')
		return "-k";
	if (a == 'j' && b == 'k')
		return "i";
	if (a == 'k' && b == 'i')
		return "j";
	if (a == 'k' && b == 'j')
		return "-i";
}

int solve(char *str) {
	char forward[MAX];
	int sign = 1;
	int firstSplit = -1, secondSplit = -1;
	for (int i = 0; i < strlen(str); i++) {
		if (i > 0) {
			char *result = multiply(forward[i - 1], str[i]);
			int digitPosition = 0;
			if (result[0] == '-'){
				sign = sign * -1;
				digitPosition++;
			}
			forward[i] = result[digitPosition];
		} else
			forward[i] = str[i];
		if (forward[i] == 'i' && sign == 1) {
			firstSplit = i;
			break;
		}
	}

	if(firstSplit==-1)
		return -1;

	sign=1;
	for (int i = firstSplit+1; i <strlen(str); i++) {
		if (i > firstSplit+1) {
			char *result = multiply(forward[i - 1],str[i]);
			int digitPosition = 0;
			if (result[0] == '-'){
				sign = sign * -1;
				digitPosition++;
			}
			forward[i] = result[digitPosition];
		} else
			forward[i] = str[i];
		if (forward[i] == 'j' && sign==1) {
			secondSplit = i;
			break;
		}
	}

	int success=-1;
	sign=1;
	if (firstSplit != -1 && secondSplit != -1) {
		for (int i = secondSplit+1; i < strlen(str); i++) {
			if (i > secondSplit+1) {
				char *result = multiply(forward[i - 1], str[i]);
				int digitPosition = 0;
				if (result[0] == '-'){
					sign = sign * -1;
					digitPosition++;
				}
				forward[i] = result[digitPosition];
			} else
				forward[i] = str[i];
		}
		if (forward[strlen(str)-1]=='k' && sign == 1) {
			success=1;
		}
	}
	return success;
}

int main() {
	int T;
	cin >> T;
	int caseNo = 1;
	while (T--) {
		int L, X;
		cin >> L;
		cin >> X;
		char str[10005]="", final[10005]="";
		cin >> str;
		for (int i = 0; i < X; i++) {
			strcat(final, str);
		}
		int result = solve(final);
		if (result == 1) {
			cout << "Case #" << caseNo << ": YES\n";
		} else {
			cout << "Case #" << caseNo << ": NO\n";
		}
		caseNo++;
	}
}

