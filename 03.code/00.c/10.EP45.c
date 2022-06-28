/*************************************************************************
    > File Name: 10.EP45.c
    > Author: Apricity
    > Mail:  
    > Created Time: Sat 05 Dec 2020 07:53:48 AM CST
 ************************************************************************/

#include<stdio.h>
typedef long long int1;
int1 Triangle(int1 n){
	return n * (n + 1) / 2;
}
int1 Pentagonal(int1 n){
	return n * (3 * n - 1) /2;
}
int1 Hexagonal(int1 n){
	return n * (2 * n - 1);
}
int1 binary_search(int1 (*num)(int1), int1 n, int1 x) {
		int1 head = 0;
		int1 tail = n - 1;
		int1 mid;
		while (head <= tail) {
			if (mid < 0) printf("error\n");
			mid = (head + tail) / 2;
			if (num(mid) == x) return mid;
			if (num(mid) < x) head = mid + 1;
			else tail = mid - 1;
		}
		return -1;
}
int main(int argc,const char* argv[]){
	int1 n = 285;
	while (1) {
		n++;
		int1 temp = Triangle(n);
		if (binary_search(Pentagonal, temp, temp) == -1) continue;
		if (binary_search(Hexagonal, temp, temp) != -1) continue;
		printf("%lld\n", temp);
		break;
		
	}
	return 0;
}
