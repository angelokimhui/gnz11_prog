#include<stdio.h>
#include<stdlib.h>
#define x 9
#define y 9

int main(){
	srand(time(NULL));
	int x_counter,y_counter;
	int table[x][y];
	for (x_counter=0;x_counter<x;x_counter++){
		for(y_counter=0;y_counter<y;y_counter++){
			table[x_counter][y_counter]=rand()%2;
			printf("This is table [%d][%d] = %d \n",x_counter,y_counter,table[x_counter][y_counter]);
		}
	}
}
