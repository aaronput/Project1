//Aaron Puthan
//02/21/2021

/*The program has to read multiple values of `n` and, for each, produce two values
`an` and `bn` where `0 ≤ i1 < i2 < ... < ik` be the indices of the bits (with
the least significant bit having index 0) in `n` that are 1. Then the indices of the bits
of `an` that are 1 are `i1` , `i3` , `i5` , ... and the indices of the bits of `bn`
that are 1 are `i2` , `i4` , `i6` ,  ...*/

#include<stdio.h>
#include<stdbool.h>

int main(){

	int num = 0;
	int num_input = 0;

//	if (scanf("%d",&num_input) < 1){ //reads the number of inputs
//		return 0;
//	}

	int a[100]; 
	int b[100];

//	for(int i = 0; i<num_input; i++){
	int i = 0;
	
	while (true) {
		int result = scanf("%d",&num);
		if(num == 0){
			num_input = i;
			break; //break if num is 0
		}
		a[i] = 0;
		b[i] = 0;
		bool was_aset = false;
		for(int j = 0; j<31;j++){
			bool bitset = (num&(1<<j))!=0; //checks whether jth bit in num is set or not
			if(bitset){
				if(was_aset){ 
				b[i]|= (1<<j); //Set the jth bit in b[i]
				}
				else{
					a[i]|= (1<<j); //Set the jth bit in a[i]	
				}
				was_aset^=1; //flip the was_aset
			}
		}
		i++;
	}
	for(int i = 0; i<num_input;i++){ //iterates through array to print a[i] and b[i]
		printf("%d %d\n", a[i], b[i]);
	}
}
