//Aaron Puthan
//02/21/2021
/*The program should print N lines to the standard output. For each valid color
the program should print its corresponding hexadecimal value proceeded by a # symbol.
For each invalid color the program should print INVALID.*/

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
		hour >24 || hour <0 || 
		minute >60 || minute < 0||
		second >60 || second <0) {
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