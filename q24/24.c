    #include <stdio.h>
    #include <stdlib.h>
     
    int longintcmp(const void *v1, const void *v2){
    	if ((*(long *)v1) > (*(long *)v2))	return 1;
    	else if ((*(long *)v1) == (*(long *)v2))	return 0;
    	else	return -1;
    }
     
    int check_distance(long* pos_array, long n , long k, long dist){
    	long curr_index = 0; long interval_start; long interval_end;
    	for (long interval_num = 1; interval_num <= k; interval_num++){
    		interval_start = pos_array[curr_index];
    		interval_end = pos_array[curr_index] + (2*dist);
    		while ((pos_array[curr_index] <= interval_end)){
    			curr_index++;
    			if (curr_index >= n)	return 1;
    		}
    	}
    	if (curr_index < n)	return 0;
    }
     
    int binary_search_least(long* array, long n , long k, long start, long end){
    	long mid;
    	if (start > end)	return 0;
    	else{
    		mid = (start+end)/2;
    		if (check_distance(array, n, k, mid) == 0){
    			return (binary_search_least(array, n, k, mid+1, end));
    		}
    		else if (check_distance(array, n, k, mid-1) == 0)	return mid;
    		else return (binary_search_least(array, n, k, start, mid-1));
    	}
    }
     
    int main(){
    	long num_temples; long k; long pos_array[100005]; long opt_distance;
    	scanf("%ld%ld", &num_temples, &k);
    	for(long i=0; i<num_temples;i++)		scanf("%ld", pos_array+i);
    	qsort(pos_array, num_temples, sizeof(long), longintcmp);
    	if (check_distance(pos_array, num_temples, k, 1) == 1)	opt_distance = 1;
    	else	opt_distance = binary_search_least(pos_array, num_temples, k, 2, pos_array[num_temples-1]);
    	printf("%ld\n", opt_distance);
    	return 0;
    }

