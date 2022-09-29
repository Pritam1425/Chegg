#include <stdio.h>//In c header file for I/O is stdio.h. So we include that
#include <stdlib.h>
unsigned int ackermann(unsigned int m, unsigned int n) {
	if (m == 0) {
		return n + 1;
	}
	if (n == 0) {
		return ackermann(m - 1, 1);
	}
	return ackermann(m - 1, ackermann(m, n - 1));
}

int main(int argc,char** argv) {
	unsigned int m,n;//In c, We can't declare variable inside for loop. So we declare before the loop.
	if(argc!=3){
		printf("Syntax error: ./ackermann m n\n");
		exit(0);
	}
	sscanf(argv[1], "%i",&m);
	sscanf(argv[2],"%i",&n);
	printf("A(%i, %i) = %i\n",m,n,ackermann(m,n));
}
