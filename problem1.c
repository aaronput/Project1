// implement your program here
#include <stdio.h>

int compress(int month, int day, int hour, int minute, int second) {
	int second_one = second%10;
	int second_ten = second/10;
	int minute_one = minute%10;
	int minute_ten = minute/10;
	int hour_one = hour%10;
	int hour_ten = hour/10;
	int day_one = day%10;
	int day_ten = day/10;
	int month_one = month%10;
	int month_ten = month/10;

	int compress = 0;

	compress |= (second_one & 0xf) << 0; //Shifting left argument 0 bits to left
	compress |=  (second_ten & 0x7) << 4;
	compress |=  (minute_one & 0xf) << 7;
	compress |= (minute_ten & 0x7 )<< 11;
	compress |= (hour_one & 0x3) << 14; 
	compress |=  (hour_ten & 0x7) << 18;
	compress |= (day_one & 0xf) << 20; 
	compress |= (day_ten & 0x3) << 24;
	compress |=  (month_one & 0xf) << 26;
	compress |=  (month_ten & 0x1) << 30;
	//compress initiatlized to 0, don't have to specify 31
	// printf("second_one %d\n",second_one);
	// printf("second_ten %d\n",second_ten);
	// printf("minute_one %d\n",minute_one);
	// printf("minute_ten %d\n",minute_ten);
	// printf("hour_one %d\n",hour_one);
	// printf("hour_ten %d\n",hour_ten);
	// printf("day_one %d\n",day_ten);
	// printf("day_ten%d\n",day_ten);
	// printf("month_one %d\n",month_one);
	// printf("month_ten %d\n",month_ten);
	// printf("Compress %d\n",compress);
	return compress;
}

int main(){
	int num_input = 0;
	if (scanf("%d", &num_input) < 1) {
		return 0;
	}
 	int array[num_input];
	for(int i = 0; i<num_input; i++){
		int month, day, hour, minute, second;
		int result = scanf("%d/%d %d:%d:%d",&month, &day,&hour,&minute,&second);
		// printf("Result = %d\n", result);
		if(result != 5 ||
		month >12 || month <1 || 
		day <1 || day >31 || 
		hour >24 || hour <1 || 
		minute >60 || minute < 1||
		second >60 || second <1) {
			array[i] = -1;
		}
		else{
			array[i] = compress(month, day, hour, minute, second);
		}
	}
	for(int i = 0; i<num_input; i++){
		if(array[i]== -1){
			printf("INVALID\n");

		}
		else{
			printf("%d\n",array[i]);
		}
	}	
	return 0;
}