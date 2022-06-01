/*
 * THIS IS SUPPOSED TO BE THE ONE WITH THE ENUMERATION OF BOMBS AROUND THE OPENED BLOCK
 * BUT I'M DUMB SO I GOT LOST WHILE DOING THE NESTED IF ELSE LOL.
 */

#include<stdio.h>
#include<stdlib.h>
#define x 8
#define y 8

int main(){
	srand(time(NULL));
	int x_counter,y_counter;
	int table[x][y],record[x][y],bomb[x][y],tmp=0;
	for (x_counter=0;x_counter<x;x_counter++){
		for(y_counter=0;y_counter<y;y_counter++){
			table[x_counter][y_counter]=rand()%2;
			record[x_counter][y_counter]=0;
			//printf("This is table [%d][%d] = %d \n",x_counter,y_counter,table[x_counter][y_counter]);
		}
	}
	
	//fill bomb counter 0
	for (x_counter=0;x_counter<x;x_counter++){
		for(y_counter=0;y_counter<y;y_counter++){
			bomb[x_counter][y_counter]=0;
		}
	}
	
	for (x_counter=0;x_counter<x;x_counter++){
		for(y_counter=0;y_counter<y;y_counter++){
			printf("%d ",table[x_counter][y_counter]);
			if(y_counter==7){
				printf("\n");
			}
		}
	}
	
	int userx,usery;
	do {
		//system("clear");
		char userchoice;
		printf("Minesweeper\n\n");
		printf("   0  1  2  3  4  5  6  7\n");
		for (x_counter=0;x_counter<x;x_counter++){
			for(y_counter=0;y_counter<y;y_counter++){
				//printf("%d ",table[x_counter][y_counter]);
				if(y_counter==0){
					printf("%d ",tmp);
					tmp++;
					if(record[x_counter][0]==0){
						printf("[?]");	
					}
					else if (record[x_counter][0]==1){
						if(table[x_counter][0]==0){
							if(table[x_counter+1][0]==1){
								bomb[0][0]++;
							}
							if(table[x_counter][1]==1){
								bomb[0][0]++;
							}
							if(table[x_counter+1][1]==1){
								bomb[0][0]++;
							}
						}
						printf("[%d]",bomb[0][0]);
					}
					
				}
				else {
					if(record[x_counter][y_counter]==0){
						printf("[?]");	
					}
					else if (record[x_counter][y_counter]==1){
						/*if(x_counter==0){
							if(table[0][y_counter+1]==1){
								bomb[0][y_counter]++;
							}
							if(table[0][y_counter-1]==1){
								bomb[0][y_counter]++;
							}
							if(table[1][y_counter]==1){
								bomb[0][y_counter]++;
							}
							if(table[1][y_counter-1]==1){
								bomb[0][y_counter]++;
							}
						}
						else if (y_counter==0){
							if(table[x_counter+1][0]==1){
								bomb[x_counter][0]++;
							}
							if(table[x_counter-1][0]==1){
								bomb[x_counter][0]++;
							}
							if(table[x_counter+1][1]==1){
								bomb[x_counter][0]++;
							}
							if(table[x_counter][1]==1){
								bomb[x_counter][0]++;
							}
							if(table[x_counter-1][1]==1){
								bomb[x_counter][0]++;
							}
							
						}
						else {
							if(table[x_counter+1][y_counter]==1){
								bomb[x_counter][y_counter]++;
							}
							if(table[x_counter-1][y_counter]==1){
								bomb[x_counter][y_counter]++;
							}
							if(table[x_counter][y_counter+1]==1){
								bomb[x_counter][y_counter]++;
							}
							if(table[x_counter][y_counter-1]==1){
								bomb[x_counter][y_counter]++;
							}
							
							if(table[x_counter+1][y_counter+1]==1){
								bomb[x_counter][y_counter]++;
							}
							if(table[x_counter+1][y_counter-1]==1){
								bomb[x_counter][y_counter]++;
							}
							if(table[x_counter-1][y_counter+1]==1){
								bomb[x_counter][y_counter]++;
							}
							if(table[x_counter-1][y_counter-1]==1){
								bomb[x_counter][y_counter]++;
							}
							
						}*/
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
		//printf("Value of X : %d\n",userx);
		printf("Y coordinate : ");
		scanf(" %d",&usery);
		//printf("Value of Y : %d\n",usery);
		record[userx][usery]=1;
		//printf("%d",record[userx][usery]);
	}while (record[userx][usery]!=table[userx][usery]);
	
	//system("clear");
	printf("Minesweeper\n\n");
	printf("   0  1  2  3  4  5  6  7\n");
		for (x_counter=0;x_counter<x;x_counter++){
			for(y_counter=0;y_counter<y;y_counter++){
				//printf("%d ",table[x_counter][y_counter]);
				if(y_counter==0){
					printf("%d ",tmp);
					tmp++;
					if(record[x_counter][0]==0){
						printf("[?]");	
					}
					else if (record[x_counter][0]==1){
						
						printf("[*]");
					}
					
				}
				else {
					if(record[x_counter][y_counter]==0){
						printf("[?]");	
					}
					else if (record[x_counter][y_counter]==1){
						
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
