#include<stdio.h>
#include<time.h>
int main(){
	time_t s;
	s=time(NULL);
	printf("%ld",s);
}