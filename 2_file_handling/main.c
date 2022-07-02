/* File Handling Class Record
 * Created by : Angelo Kim Hui V. Lim
 * VERY Inefficient but will do the job
*/
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#define NUMBR_SZ 11
#define SURNM_SZ 16
#define FSTNM_SZ 31
#define FILE_SZ 60
#define STUD_ARR 30
#define BUFFR_SZ 200

typedef struct information {
	int num;
	char surnm[SURNM_SZ];
	char fstnm[FSTNM_SZ];
	char gender;
} info;

void db_init();
char menu();
void reset();
void user_input();
void db_write();
void db_read();

int main(){
	int choice,approve=0;
	char click;
	info student[STUD_ARR];
	FILE *filemain,*tmpfile;
	filemain=fopen("LIM.txt","r+"); 															// load file in r+ mode to not overwrite the file.
	tmpfile=fopen("tmp","w");
	db_init(filemain,tmpfile);
	click=menu();
	if(click=='w'||click=='W'){
		user_input(&student,&choice);
		db_write(filemain,tmpfile,&choice,&student);
	}
	else{
		db_read(filemain,tmpfile,&student);
	}
}

char menu(){
	char click;
	system("clear"); //CLEAR SCR FOR LINUX
	printf("\tWelcome to the class record!\n\n");
	printf("\tWhat do you want to do? :\n\t- (W)rite to the database?\n\t- (R)ead from the database? : ");
	scanf(" %c",&click);
	switch(click){
		case 'w' : case 'W' : case 'R' : case 'r' : return click; break;
		default : printf("\nInvalid input! Please try again.\n"); sleep(1);system("clear");return main();
	}

}

void db_read(FILE *filemain,FILE *tmpfile,info *student){
	int ctr_read=0,ctr_db=0;
	char buffer[BUFFR_SZ];
	filemain=fopen("LIM.txt","r");
	system("clear");
	printf("\n\t\tDatabase record list\n");
    while ((fgets(buffer, BUFFR_SZ, filemain))!=NULL)
    {
        ctr_read++;
        if (ctr_read > 2){
        	//printf("%s",buffer);
        	sscanf(buffer,"%i %s %s %c",&student[ctr_db].num, student[ctr_db].surnm, student[ctr_db].fstnm, &student[ctr_db].gender);
        	printf("\n\tEntry Number %d",ctr_db+1);
        	printf("\n\tStudent ID Number : %d",student[ctr_db].num);
        	printf("\n\tStudent Surname   : %s",student[ctr_db].surnm);
        	printf("\n\tStudent Firstname : %s",student[ctr_db].fstnm);
        	printf("\n\tStudent Gender    : %c\n",student[ctr_db].gender);
        	ctr_db++;
        }
    }
    printf("\n");
    if (ctr_read == 2){
    	system("clear");
    	printf("\tDatabase is empty. Please write some entries first!\n\n");
    	sleep(2);
    	main();
    }
    fclose(filemain);
    remove("tmp");
    printf("   Press enter to continue.\n");
	int enter = 0;
	getchar();
	while (enter != '\r' && enter != '\n') { enter = getchar(); }
    main();
}

void db_init(FILE *filemain, FILE *tmpfile){
	char file_init_var[FILE_SZ],init_txt[FILE_SZ]; 												// initialize variables to hold fscanf then the constant needed in file respectively.
	if(filemain==NULL){
		printf("File does not exist! Initializing new file.\n");
		sleep (1); 																				// for fun XD
		filemain=fopen("LIM.txt","w"); 															// now to create new file, well load fopen with "w" parameter
		if(filemain==NULL){ 																	// check now if we really have the file, otherwise it's user's problem not the program.
			printf("Failed to initialize file. Invalid input/directory.\n");
			exit(1); 																			// yeeet mode
		}
	}
	fscanf(filemain,"%s",file_init_var); 														// read our first line where we expect "#initialized" text.
	strcpy(init_txt,"#initialized_database\n#NUM #SURNME #FRSTNM #GENDER");
	if(strcmp(file_init_var, "#initialized_database")!=0){												// if strcmp can't find the expected text then we create it.
		fprintf(filemain,"%s",init_txt);
		fclose(filemain);																		// close it to save															// then reopen cause we still need it haha.
	}
}

void reset(int *approve){
	*approve=0;
}

void user_input(info *student, int *choice) {
	int approve;
	char stud_num_str[11];
	system("clear");
	printf("How many students will be added? : ");
	scanf("%d",choice);
	getchar();

	for (int ctr=0;ctr<*choice;ctr++){
		do {
			printf("\nEnter Student %d ID Number     : ",ctr+1);
			scanf("%d",&student[ctr].num);
			sprintf(stud_num_str, "%d" , student[ctr].num);
			if (strlen(stud_num_str)<=10){
				approve=1;
			}
			else {
				printf("You are beyond the maximum character limit, please try again.\n");
			}
		} while (approve!=1);
		getchar();
		//printf("DEBUG : STUDENT %d NUMBER : %d\n",ctr+1,student[ctr].num);
		reset(&approve);

		printf("Enter Student %d Surname    : ",ctr+1);
		fgets(student[ctr].surnm, SURNM_SZ, stdin);
		printf("SURNAME : %s",student[ctr].surnm);
		if ((strlen(student[ctr].surnm) > 0) && (student[ctr].surnm[strlen (student[ctr].surnm) - 1] == '\n')){
        	student[ctr].surnm[strlen (student[ctr].surnm) - 1] = '\0';
		}

		printf("Enter Student %d First Name : ",ctr+1);
		fgets(student[ctr].fstnm, FSTNM_SZ, stdin);
		if ((strlen(student[ctr].fstnm) > 0) && (student[ctr].fstnm[strlen (student[ctr].fstnm) - 1] == '\n')){
        	student[ctr].fstnm[strlen (student[ctr].fstnm) - 1] = '\0';
		}

		do {
			printf("Enter Student %d Gender : ",ctr+1);
			scanf("%c",&student[ctr].gender);
			getchar();
			if (student[ctr].gender=='M'||student[ctr].gender=='m'||student[ctr].gender=='F'||student[ctr].gender=='f'){
				approve=1;
			}
			else {
				printf("Please enter (M)ale or (F)emale only!\n");
			}
		}while (approve!=1);
		reset(&approve);
	}
}

void db_write(FILE *filemain,FILE *tmpfile,int *choice,info *student){
	// WRITE INFORMATIONS TO FILE
	filemain=fopen("LIM.txt","r");
	char buffer;
	buffer=fgetc(filemain);
	while (buffer!=EOF)
    {
        fputc(buffer,tmpfile);
        buffer=fgetc(filemain);
    }
    rewind(filemain);
	for (int ctr_write=0;ctr_write<*choice;ctr_write++){
		fprintf(tmpfile,"\n%d ",student[ctr_write].num);
		fprintf(tmpfile,"%s ",student[ctr_write].surnm);
		fprintf(tmpfile,"%s ",student[ctr_write].fstnm);
		fprintf(tmpfile,"%c",student[ctr_write].gender);
	}
	fclose(filemain);
	fclose(tmpfile);
	remove("LIM.txt");
	rename("tmp","LIM.txt");
	printf("\nInput finished, returning to main menu..\n");
	sleep(2);
	main();
}