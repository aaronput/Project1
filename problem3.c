// implement your program here
#include<stdio.h>
#include<stdbool.h>

// We define the operation of splitting a binary number `n` into two numbers
// `an`, `bn` as follows. Let `0 ≤ i1 < i2 < ... < ik` be the indices of the bits (with
// the least significant bit having index 0) in `n` that are 1. Then the indices of the bits
// of `an` that are 1 are `i1` , `i3` , `i5` , ... and the indices of the bits of `bn`
// that are 1 are `i2` , `i4` , `i6` ,  ...

// For example, if `n` is `110110101` in binary then, again in binary, we have `a =
// 010010001` and `b = 100100100`.

// __Input__

// The program has to read multiple values of `n` and, for each, produce two values
// `an` and `bn` as described above.

// Each test case consists of a single integer
// `n` between 1 and 2^(31) - 1 (i.e. any positive integer within the range of the int type)
// written in standard decimal (base 10) format on a single line.
// Input is terminated by a line containing ‘0’ which should not be processed.

// __Output__

// The output for each test case consists of a single line, containing the integers
// `an` and `bn` separated by a single space. Both `an` and `bn` should be written in decimal format
// (base 10).

// 110 .. even bits 100 odd bit 10

int main(){

	int num = 0;
	int num_input = 0;
	if (scanf("%d",&num_input) < 1){
		return 0;
	}

	int a[num_input]; //initializes to 0
	int b[num_input];

	for(int i = 0; i<num_input; i++){
		int result = scanf("%d",&num);
		if(num == 0){
			num_input = i;
			break;
		}
		a[i] = 0;
		b[i] = 0;
		// printf("num%d\n",num);
		// printf("%d\n",(num&(1<<2))!=0); //second and first bit should be set
		// printf("%d\n",(num&(1<<1))!=0);
		bool was_aset = false;
		for(int j = 0; j<31;j++){
			bool bitset = (num&(1<<j))!=0;
			// printf("%d %d\n",(num&(1<<j))!=0,j);
			// printf("%d\n",j);
			if(bitset){
				// printf("%d\n",was_aset);
				if(was_aset){

				 //checks whether jth bit in num is set or not
					// printf("%d\n",j);

				b[i]|= (1<<j); //set jth bit in b[i]
				// was_aset = false;
				}
				else{
					a[i]|= (1<<j);	
					// was_aset = true;
				}
				was_aset^=1;
			}

		}
	}
	
	for(int i = 0; i<num_input;i++){
		printf("%d %d\n", a[i], b[i]);
	}
}
