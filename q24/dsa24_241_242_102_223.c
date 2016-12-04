#include <stdio.h>
#include <stdlib.h>
	
int canDo(int pos[], int k, int range, int n) {
	
	int covered[n],i;
	for (i = 0; i < n; i++)
		covered[i] = 0;
	int cur = 0;

	while (cur < n) {
		if (k == 0)
			return 0;
		int max = pos[cur] + range + range;
		while (cur < n && pos[cur] <= max)
			covered[cur++] = 1;
			4k--;
	}

	return 1;
}

void merge(int a[], int start, int end) {
	
	int copy[end - start + 1],i;
	int mid = (start + end) / 2;
	int p = start, q = mid + 1;
	
	for (i = 0; i < end - start + 1; i++)
		if (p > mid)
			copy[i] = a[q++];
		else if (q > end)
			copy[i] = a[p++];
		else if (a[p] < a[q])
			copy[i] = a[p++];
		else
			copy[i] = a[q++];

	for (i = start; i <= end; i++)
		a[i] = copy[i - start];
}
	
void mergeSort(int a[], int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort(a, start, mid);
		mergeSort(a, mid + 1, end);
		merge(a, start, end);
	}

}

int main() {
	int n, k,i;
	scanf("%d %d", &n, &k);
	int pos[n];
	for (i = 0; i < n; i++)
		scanf("%d", &pos[i]);
		mergeSort(pos, 0, n-1);
		int prev = 999999999;
		int start = 0, end = 10000000;
	while (1) {
		if (start > end)
		break;
	
		int mid = (start + end) / 2;
		int done = start == end;
		if (canDo(pos, k, mid, n) == 1) {
			if (mid < prev)
				prev = mid;
			end = mid - 1;
		}
		
		else
			start = mid + 1;
		
		if (done)
			break;
	}
	printf("%d\n", prev);
}
