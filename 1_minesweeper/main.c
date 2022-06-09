/*
 *  Basic Minesweeper in C Language
 *  Author :  Angelo Kim Hui Lim(GNz11)
 *  Purpose : School Assignment
 *  Last Modified : May 31, 2022 4:25PM
 */

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#define y 25
#define x 80
#define num_bombs 5
#define max_hp 3
#define max_moves 10

void zero();
void gen_bomb();
void print_all();

int main(){
    system("Color B");
	int curr_hp=max_hp+1,avail_moves=max_moves;
	int table[y][x],record[y][x],bombx[num_bombs],bomby[num_bombs],userx,usery,tmp=0;
	zero(table,record);
	gen_bomb(table,bombx,bomby);
	print_all(&curr_hp,&avail_moves,table,record,bombx,bomby,&userx,&usery,&tmp);
    exit(0);
}

void zero(int table[y][x],int record[y][x]){
    int tmp1,tmp2;
    //make sure arrays contains zeroes only (seems like some index' before have -3xxxxx value)
	for (tmp1=0;tmp1<y;tmp1++){
		for(tmp2=0;tmp2<x;tmp2++){
			record[tmp1][tmp2]=0;
			table[tmp1][tmp2]=0;
		}
	}
	//end fill arrays with zeroes
}

void gen_bomb(int table[y][x],int bombx[num_bombs],int bomby[num_bombs]){
    srand(time(NULL));
    //generate bombs (mark 1) and get their coordinates
	for (int tmp_ctr=0;tmp_ctr<num_bombs;tmp_ctr++){
        table[bomby[tmp_ctr]=rand()%25][bombx[tmp_ctr]=rand()%80]=1;
	}
    //end generate bombs
}

void print_all(int *curr_hp,int *avail_moves,int table[y][x],int record[y][x],int bombx[num_bombs],int bomby[num_bombs],int *userx,int *usery){
clock_t start = clock();
do {
    system("cls");
    int x_counter,y_counter,tmp;
    //diplay bombas
    printf ("\n  Bomb Coordinates\n");
    printf ("  Bomb\tx\ty");
    for(int tmp_ctr=0;tmp_ctr<num_bombs;tmp_ctr++){
        printf("\n  %d\t%d\t%d",tmp_ctr+1,bombx[tmp_ctr],bomby[tmp_ctr]);
    }
    //end display bombas
    	printf("\n\t\t\t\t\t\t\t\t\t\t\t       _______________________________________________ ");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t      |_______________________________________________|");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t      |                                               |");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t      |               > MINESWEEPER                   |");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t      |_______________________________________________|");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t      |_______________________________________________|");
		printf("\n\n\n\n");
        printf("    0  1  2  3  4  5  6  7  8  9");
        for (int num_line = 10; num_line <= 79 ; num_line++){
            printf(" %d", num_line);
            if(num_line == 79){
                printf(" \n");
            }
        }
        for (y_counter=0;y_counter<y;y_counter++){
            for(x_counter=0;x_counter<x;x_counter++){
                if(x_counter==0){
                    if (tmp<10){
                        printf("%d  ",tmp);
                    }
                    else{
                        printf("%d ",tmp);
                    }
                    tmp=tmp+1;
                    if(record[y_counter][0]==0){
                        printf("[ ]");
                    }
                    else if (record[y_counter][0]==1&&table[y_counter][0]==1){
                        printf("[1]");
                    }
                    else if (record[y_counter][0]==1){
                        printf("[0]");
                }
            }
                else {
                    if(record[y_counter][x_counter]==0){
                        printf("[ ]");
                    }
                    else if (record[y_counter][x_counter]==1&&table[y_counter][x_counter]==1){
                        printf("[1]");
                    }
                    else if (record[y_counter][x_counter]==1){
                        printf("[0]");
                    }
                    if(x_counter==79){
                        printf("\n");
                    }
                }
            }
        }
        if (*curr_hp==1){
            clock_t end = clock();
            double t_time = (double)(end - start) / CLOCKS_PER_SEC;
            printf("Total Time spent : %.2lf seconds.",t_time);
            printf("\nGame Over!");
            getch();
            exit(0);
        }
        tmp=0;
        printf("\n\t\t\t\t\t\t\t\t\t\t\t _______________________________________________________________");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t Current HP = %d",*curr_hp-1);
        printf("\n\t\t\t\t\t\t\t\t\t\t\t Available Moves = %d",*avail_moves);
        printf("\n\t\t\t\t\t\t\t\t\t\t\t Enter the x and y coordinate for the block you want to reveal.\n");
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\tX coordinate : ");
        scanf(" %d",&*userx);
        printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\tY coordinate : ");
        scanf(" %d",&*usery);
        printf("\n\t\t\t\t\t\t\t\t\t\t\t _______________________________________________________________");
        record[*usery][*userx]=1;
        if (record[*usery][*userx]==table[*usery][*userx]){
            *curr_hp=*curr_hp-1;
        }
            *avail_moves=*avail_moves-1;
    }while ((*curr_hp!=0) && (*avail_moves!=0));
}
