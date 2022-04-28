/*
 *  Basic Minesweeper in C Language
 *  Author :  Angelo Kim Hui Lim(GNz11)
 *  Purpose : School Assignment
 *  Last Modified : April 27, 2022 4:23PM
 */

#include<stdio.h>
#include<stdlib.h>
#define x 80
#define y 25
#define num_bombs 5
#define max_hp 3
#define max_moves 10

int main(){
	srand(time(NULL));
	int x_counter,y_counter,curr_hp=max_hp,avail_moves=max_moves;
	int table[x][y],record[x][y],bombx[num_bombs],bomby[num_bombs],tmp=0;

	//make sure arrays contains zeroes only (seems like some index' before have -3xxxxx value)
	for (x_counter=0;x_counter<x;x_counter++){
		for(y_counter=0;y_counter<y;y_counter++){
			record[x_counter][y_counter]=0;
			table[x_counter][y_counter]=0;
		}
	}
	//end fill arrays with zeroes

	//generate bombs (mark 1) and get their coordinates
	for (int tmp_ctr=0;tmp_ctr<num_bombs;tmp_ctr++){
        table[bomby[tmp_ctr]=rand()%80][bombx[tmp_ctr]=rand()%25]=1;
	}
    //end generate bombs
	int userx,usery;
	do {
		system("cls");
		//diplay bombas
		printf ("\n  Bomb Coordinates\n");
        printf ("  Bomb\tx\ty");
        for(int tmp_ctr=0;tmp_ctr<num_bombs;tmp_ctr++){
            printf("\n  %d\t%d\t%d",tmp_ctr+1,bombx[tmp_ctr],bomby[tmp_ctr]);
        }
        //end display bombas
		printf("\n\t\t\t\tMinesweeper\n\n");
		printf("    0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24\n");
		for (x_counter=0;x_counter<x;x_counter++){
			for(y_counter=0;y_counter<y;y_counter++){
				if(y_counter==0){
                    if (tmp<10){
                        printf("%d  ",tmp);
                    }
                    else{
                        printf("%d ",tmp);
                    }
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
					if(y_counter==24){
						printf("\n");
					}
				}
			}
		}
		tmp=0;
        printf("\nCurrent HP = %d",curr_hp);
        printf("\nAvailable Moves = %d",avail_moves);
		printf("\n\nEnter the x and y coordinate for the block you want to reveal.\n");
		printf("\nX coordinate : ");
		scanf(" %d",&usery);
		printf("Y coordinate : ");
		scanf(" %d",&userx);
		record[userx][usery]=1;
		if (record[userx][usery]==table[userx][usery]){
            curr_hp=curr_hp-1;
		}
		avail_moves=avail_moves-1;
	}while ((curr_hp!=0) && (avail_moves!=0));

	system("cls");
	printf("\n\t\t\t\tMinesweeper\n\n");
		printf("    0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24\n");
		for (x_counter=0;x_counter<x;x_counter++){
			for(y_counter=0;y_counter<y;y_counter++){
				if(y_counter==0){
                    if (tmp<10){
                        printf("%d  ",tmp);
                    }
                    else{
                        printf("%d ",tmp);
                    }
					tmp++;
					if(record[x_counter][0]==0&&table[x_counter][0]==0){
						printf("[?]");
					}
					else if (record[x_counter][0]==1&&table[x_counter][0]==1){
                        printf("[0]");
					}
					else if (record[x_counter][0]==1){
						printf("[ ]");
					}
                    else if(table[x_counter][0]==1){
                        printf("[0]");
                    }
				}
				else {
					if(record[x_counter][y_counter]==0&&table[x_counter][y_counter]==0){
						printf("[?]");
					}
					else if (record[x_counter][y_counter]==1&&table[x_counter][y_counter]==1){
                        printf("[0]");
					}
					else if (record[x_counter][y_counter]==1){
						printf("[ ]");
					}
                    else if(table[x_counter][y_counter]==1){
                        printf("[0]");
                    }
                    if(y_counter==24){
						printf("\n");
					}
				}
			}
		}
	printf("\n\t\t\t\tVoilaaa\n\n");
	exit(0);
}
