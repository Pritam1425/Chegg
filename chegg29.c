#include<stdio.h>
#include<inttypes.h>
#include<stdlib.h>
static int64_t linkin_park[] = {91446,55558,84029,49941,74739,64008};
const static int N = sizeof(linkin_park)/sizeof(*linkin_park);
static void fail(){
	puts("Nope!");
	exit(EXIT_FAILURE);
}
static void the_rolling_stones(int64_t a,int64_t r,int64_t d){
	if(a-d/7+3*r/11)
		fail();
}
static void green_day(int u,int64_t e){
	int64_t z = e;
	for(;u<N;++u){
		if((u%2)==0)
		continue;
		z+=linkin_park[u];
	}
	if(z!=120928)
		fail();
}
static void led_zeppelin(int f,int64_t s){
	if(f<N){
		if(f%2)
			led_zeppelin(++f, s);
			else {
				led_zeppelin(f+1,s*linkin_park[f]);
				
			}
	}
	else if(s!=592908624)
		fail();
}
int main()
{
	int64_t t,v,g;
	printf("Please enter the right three numbers: ");
	fflush(stdout);
	if(scanf("%" SCNd64 " %" SCNd64 " %" SCNd64,&t,&v,&g)!=3)
		fail();
	linkin_park[0] = t;
	linkin_park[5] = v;
	linkin_park[4] = g;
	green_day(0,13141);
	led_zeppelin(1,7);
	the_rolling_stones(t,v,g);
	puts("Exactly! Good job.");
}
