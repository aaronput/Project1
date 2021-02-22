//Aaron Puthan
//02/21/2021
/*The objective of your program is to read the three values representing the three
separate colors and produce a single hexadecimal value.

Each color is represented by a value in a range of [0,255]. Each of those numbers
is represented by exactly two hexadecimal symbols: RRGGBB.*/

#include <stdio.h>


int main(){
	int num_input = 0;
	if (scanf("%d",&num_input) < 1){ 
		return 0;
	}
	char hex_result[num_input][8]; //storing 7 bits and additional 1 for the terminating character
	for(int i = 0; i<num_input; i++){
		int red, green, blue;
		int result = scanf("%d,%d,%d",&red, &green, &blue); //Check that red, green, blue >0 and <255
		if(num_input>0 && red<=255 && red>=0 && 
		green<=255 && green>=0 && 
		blue<=255 && blue>=0){
	
		sprintf(hex_result[i],"#%.2x%.2x%.2x\n",red,green,blue); //print in the hex_result the hexadecimal for red, green and blue
		hex_result[i][7] = '\0'; //pointer to tell to the array to not go beyond num_input
		
		}	
		else{
			hex_result[i][0]= '$'; //handling invalid scenarios
			hex_result[i][1]= '\0';
		}
	}
	for(int i = 0; i<num_input; i++){ //printing hex result by iterating through num_input
		if(hex_result[i][0]=='$'){
			printf("INVALID\n");
		}
		else{
			printf("%s\n",hex_result[i]);
		}
	}
}





