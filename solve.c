#include <stdio.h>
#include <math.h>

int n;

int min(int *arr, int size) {
	int min = *arr;
	for(int i = 0; i < size; i++) {
		if( *(arr+i) < min)
			min = *(arr + i);
	}
	return min;
}

int main() {
	scanf("%d", &n);
	int r[n + 1], g[n + 1], b[n + 1];
	
	
	for(int i = 1; i <= n; i++) {
		int rr, gg, bb;
		scanf("%d %d %d", &rr, &gg, &bb);
		
		r[i] = rr;
		g[i] = gg;
		b[i] = bb;
	} 
	
		printf("           [i] [i] [i + 1] result\n");
	for(int i = 1; i < n; i++) {
		int rd[2] = {g[i], b[i]};
		printf("r : [%d] min(%d, %d) + %d = %d \n", i + 1, g[i], b[i], r[i + 1], min(rd, 2) + r[i + 1]);
		r[i + 1] += min(rd, 2);
		
		int gd[2] = {r[i], b[i]};
		printf("g : [%d] min(%d, %d) + %d = %d\n", i + 1, r[i], b[i], g[i + 1], min(gd, 2) + g[i + 1]);
		g[i + 1] += min(gd, 2);
		
		int bd[2] = {g[i], r[i]};
		printf("b : [%d] min(%d, %d) + %d = %d\n", i + 1, g[i], r[i], b[i + 1], min(bd, 2) + b[i + 1]);
		b[i + 1] += min(bd, 2);
	}
	
	int data[3] = {r[n], g[n], b[n]};
	
	
	printf("%d", min(data, 3));
	
	
	
	
	return 0;
}
