#include<stdio.h>
#include<stdlib.h>
#define x 8
#define y 8

int main(){
	srand(time(NULL));
	int x_counter,y_counter;
	int table[x][y],record[x][y],tmp=0;
	for (x_counter=0;x_counter<x;x_counter++){
		for(y_counter=0;y_counter<y;y_counter++){
			table[x_counter][y_counter]=rand()%2;
			record[x_counter][y_counter]=0;
		}
	}
	int userx,usery;
	do {
		system("clear");
		char userchoice;
		printf("\tMinesweeper\n\n");
		printf("   0  1  2  3  4  5  6  7\n");
		for (x_counter=0;x_counter<x;x_counter++){
			for(y_counter=0;y_counter<y;y_counter++){
				if(y_counter==0){
					printf("%d ",tmp);
					tmp++;
					if(record[x_counter][0]==0){
						printf("[?]");	
					}
					else if (record[x_counter][0]==1){
						printf("[ ]");
					}
					
				}
				else {
					if(record[x_counter][y_counter]==0){
						printf("[?]");	
					}
					else if (record[x_counter][y_counter]==1){
						printf("[ ]");
					}
					if(y_counter==7){
						printf("\n");
					}
				}
			}
		}
		tmp=0;
		
		printf("\n\nEnter the x and y coordinate for the block you want to reveal.\n");
		printf("Type ''E'' in X coordinate to exit.\n");
		printf("X coordinate : ");
		scanf(" %c",&userchoice);
		if (userchoice == 'e' || userchoice == 'E'){
			system("clear");
			printf("Exiting Minesweeper..\n");
			exit(3);
		}
		else {
			userx=(int)userchoice-48;
		}
		printf("Y coordinate : ");
		scanf(" %d",&usery);
		record[userx][usery]=1;
	}while (record[userx][usery]!=table[userx][usery]);
	
	system("clear");
	printf("\tMinesweeper\n\n");
	printf("   0  1  2  3  4  5  6  7\n");
		for (x_counter=0;x_counter<x;x_counter++){
			for(y_counter=0;y_counter<y;y_counter++){
				if(y_counter==0){
					printf("%d ",tmp);
					tmp++;
					if(record[x_counter][0]==0){
						printf("[?]");	
					}
					else if (record[x_counter][0]==1&&table[x_counter][0]==0){
						
						printf("[ ]");
					}
					else if (record[x_counter][0]==1&&table[x_counter][0]==1){
						
						printf("[*]");
					}
					
				}
				else {
					if(record[x_counter][y_counter]==0){
						printf("[?]");	
					}
					else if (record[x_counter][y_counter]==1&&table[x_counter][y_counter]==0){	
						printf("[ ]");
					}
					else if (record[x_counter][y_counter]==1&&table[x_counter][y_counter]==1){	
						printf("[*]");
					}
					
					if(y_counter==7){
						printf("\n");
					}
				}
			}
		}
	printf("\n\tGame Over!\n\n");
	exit(3);
}
