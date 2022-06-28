/*************************************************************************
    > File Name: 2.EP45.c
    > Author: Apricity
    > Mail:  
    > Created Time: Tue 01 Dec 2020 08:45:37 PM CST
 ************************************************************************/

#include<stdio.h>
int Triangle(int n){
	return n * n(n + 1) / 2;
}
int Pentagonal(int n){
	return n * (3 * n - 1) /2;
}
int Hexagonal(int n){
	return n * (2 * n - 1);
}
int binary_search(int (*num)(int), int n, int x){
	int head = 0;
	int tail = n - 1;
	int mid;
	while (head <= tail) {
		mid = (head + tail) >> 1;
		if(num(mid) == x) return mid;
		if(num(mid) < x) head = mid + 1;
		else tail = mid - 1;
	}
	return -1;
}

int main(int argc,const char* argv[]){
	int n=285;
	while (1) {
		n++;
		int val = Triangle(n);
		if (binary_search(Pentagonal, val, val) == -1) continue; 
		if(binary_search(Hexagonal, val ,val) != -1) continue;
		
		printf("%d\n", val);
	}
	return 0;
}















