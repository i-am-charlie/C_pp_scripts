#include <iostream>
#include <stdio.h>

using namespace std;

unsigned long algo(unsigned long n){
	unsigned long count = 1;
	while(n != 1){
		if (n%2 ==0) n/=2;
		else n = 3*n+1;
		count += 1;
	}
	return count;
}

int main(){
	int i, j, first, last;
	while(cin>>i>>j){
		unsigned long max_cycle = 1;
		first = min(i,j);
		last = max(i,j);
		for(int i=first; i <= last; ++i){
			unsigned long temp = algo(i);
			if(temp > max_cycle) max_cycle = temp;
		}
		cout << i << ' ' << j << ' ' << max_cycle << endl;
	}
	return 0;
}
