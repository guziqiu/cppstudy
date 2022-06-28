/*************************************************************************
    > File Name: 119.c
    > Author: Apricity
    > Mail:  
    > Created Time: Thu 03 Dec 2020 11:51:11 AM CST
 ************************************************************************/

#include<stdio.h>
int main(int argc,const char* argv[]){
	int year,mouth,day;
	scanf("%d%d%d", &year, &mouth, &day);

     int y, m, d;
	 y = year;
 	 m = mouth;
     d = day;
	 if(d == 1){
	 if ( m ==2  || m == 4 || m == 6 || m == 9 || m== 11 || m == 1 ){
		 //1 3 5 7 8 10 12
		 //2 4 6 9 11 1
		d = 31;
		m -= 1;
		if(m ==1) m = 12;
	 }else if(m == 3){
		m = 2;
		d = 28;
		if ((m % 4 == 0 && m % 100) || y % 400 == 0) d += 1;
	 }else{
		d = 30;
		m -= 1;
	 }}
	 d -= 1;
	 printf("%d %d %d", y, m, d);

	 y = year;
	 m = mouth;
	 d = day;
	 if(d == 30) if(m ==2  || m == 4 || m == 6 || m == 9 || m== 11) {m++;d=1;}
	 if(d == 31 ) if (m ==1  || m == 3 || m == 5 || m == 7 || m== 8 || m == 10 || m == 12) {m++;d=1;}
	 if(d == 29 && m == 2) {m++;d=1;}
	 if(d ==28){
		 if((m % 4 == 0 && m % 100 != 0) || y % 400 == 0) continue; 
		 else{
			d = 1;
			m++;
		 }
	 }
	 d++;
	 printf("%d %d %d", y, m, d);
	return 0;
}
