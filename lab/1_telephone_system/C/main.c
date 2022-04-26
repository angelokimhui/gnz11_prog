/* Basic Calltime Calculator by GNz11(angelolim)
 * Using KISS principle
 * April 27, 2022
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NmS 50
#define NbS 15

float total_sec,cust_creds;
int destination_code,min,seconds;
char time_code,day_code,tmp;

void output();
void calculation();

int main(){
	char cust_name[NmS],cust_num[NbS];
	printf("\n Telephone System\n");
	printf("==================\n");
	printf("Customer Name : ");
	fgets(cust_name, NmS, stdin);
	if ((strlen(cust_name) > 0) && (cust_name[strlen (cust_name) - 1] == '\n')){
        	cust_name[strlen (cust_name) - 1] = '\0';
	}
	printf("Customer Number : ");
	scanf("%14s",cust_num);
	if (strlen(cust_num)>13){
		printf("You entered beyond the character limit, please try again.\n");
		return 1;
	}
	printf("\nDestination of your call");
	printf("\n    1. American Region");
	printf("\n    2. Asian Region");
	printf("\n    3. African Region");
	printf("\n    4. European Region");
	printf("\nEnter your choice : ");
	scanf("%i",&destination_code);
	printf("\nTime Code : ");
	printf("\n    A. Daytime");
	printf("\n    B. Nighttime");
	printf("\nEnter your choice : ");
	scanf(" %c",&time_code); // added space before %c as the buffer from scanf above causes newline which this syntax assumes as user input "enter".
	printf("\nDay Code : ");
	printf("\n    X. Weekdays");
	printf("\n    Y. Weekends");
	printf("\nEnter your choice : ");
	scanf(" %c",&day_code);	// same as line 41.
	printf("\nEnter your available load/credits : ");
	scanf(" %f",&cust_creds);
	output(&cust_name,&cust_num);
	printf("\n");
	exit(0);
}

void output(char *name,char *num){
    system("cls");
	printf("\n Telephone System\n");
	printf("==================\n");
	printf("\nCustomer Name : %s\n",name);
	printf("Customer Number : %s\n",num);
    calculation();
    if (seconds==0){
        printf("You have %d mins calltime.\n",min);
    }
    else {
        printf("You have %d mins and %d secs of calltime.",min,seconds);
    }
    printf("\nTotal Charges : %.2f",cust_creds);
	printf("\n\n==================");
}

void calculation(){
    //Rate (could be integrated to formula immediately but I decided to add something to the memory instead, exit(0) will take care of it tho)
	// AMERICA - per 3 mins
	int america_weekdays_price_day=50;
	int america_weekdays_price_night=45;
	int america_weekends_price_day=40;
	int america_weekends_price_night=38;
	// ASIA - per 2 mins
	int asia_weekdays_price_day=30;
	int asia_weekdays_price_night=27;
	int asia_weekends_price_day=25;
	int asia_weekends_price_night=15;
	// AFRICA - per 3 mins
	int africa_weekdays_price_day=40;
	int africa_weekdays_price_night=35;
	int africa_weekends_price_day=35;
	int africa_weekends_price_night=22;
	// EUROPE - per 2 mins
	int europe_weekdays_price_day=35;
	int europe_weekdays_price_night=30;
	int europe_weekends_price_day=20;
	int europe_weekends_price_night=19;
    if (destination_code==1){
        if(time_code=='A'||time_code=='a'){
            if(day_code == 'X' || day_code == 'x'){
                    total_sec = (cust_creds/america_weekdays_price_day)*180;
            }
            else if(day_code == 'Y' || day_code == 'y'){
                    total_sec = (cust_creds/america_weekends_price_day)*180;
            }
        }
        if(time_code=='B'||time_code=='b'){
            if(day_code == 'X' || day_code == 'x'){
                    total_sec = (cust_creds/america_weekdays_price_night)*180;
            }
            else if(day_code == 'Y' || day_code == 'y'){
                    total_sec = (cust_creds/america_weekends_price_night)*180;
            }
        }
    }
    if (destination_code==2){
        if(time_code=='A'||time_code=='a'){
            if(day_code == 'X' || day_code == 'x'){
                    total_sec = (cust_creds/asia_weekdays_price_day)*120;
            }
            else if(day_code == 'Y' || day_code == 'y'){
                    total_sec = (cust_creds/asia_weekends_price_day)*120;
            }
        }
        if(time_code=='B'||time_code=='b'){
            if(day_code == 'X' || day_code == 'x'){
                    total_sec = (cust_creds/asia_weekdays_price_night)*120;
            }
            else if(day_code == 'Y' || day_code == 'y'){
                    total_sec = (cust_creds/asia_weekends_price_night)*120;
            }
        }
    }
    if (destination_code==3){
        if(time_code=='A'||time_code=='a'){
            if(day_code == 'X' || day_code == 'x'){
                    total_sec = (cust_creds/africa_weekdays_price_day)*180;
            }
            else if(day_code == 'Y' || day_code == 'y'){
                    total_sec = (cust_creds/africa_weekends_price_day)*180;
            }
        }
        if(time_code=='B'||time_code=='b'){
            if(day_code == 'X' || day_code == 'x'){
                    total_sec = (cust_creds/africa_weekends_price_night)*180;
            }
            else if(day_code == 'Y' || day_code == 'y'){
                    total_sec = (cust_creds/america_weekends_price_night)*180;
            }
        }
    }
    if (destination_code==4){
        if(time_code=='A'||time_code=='a'){
            if(day_code == 'X' || day_code == 'x'){
                    total_sec = (cust_creds/europe_weekdays_price_day)*120;
            }
            else if(day_code == 'Y' || day_code == 'y'){
                    total_sec = (cust_creds/europe_weekdays_price_day)*120;
            }
        }
        if(time_code=='B'||time_code=='b'){
            if(day_code == 'X' || day_code == 'x'){
                    total_sec = (cust_creds/europe_weekends_price_night)*120;
            }
            else if(day_code == 'Y' || day_code == 'y'){
                    total_sec = (cust_creds/europe_weekends_price_night)*120;
            }
        }
    }
    min = (int)total_sec/60;
    seconds=(int)total_sec%60;
}
