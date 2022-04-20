#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define NmS 50
#define NbS 15

int main(){

	/*char cust_name[NmS],cust_num[NbS];
	printf("Telephone System\n");
	
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
	
	int destination_code,cust_creds;
	char time_code,day_code,tmp;
	
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
	scanf("%d",&cust_creds);
	
	system("clear");
	printf("\nCustomer Name : %s",cust_name);
	printf("\nCustomer Number : %s",cust_num);
	printf("\nTemp : cust_creds : %d",cust_creds);	
	
	*/
	
	//Calculations
	
	int destination_code=1;
	char time_code='a',day_code='x';
	float cust_creds=152;
	
	// AMERICA - per 3 mins
	float america_weekdays_price_day=50.00;
	float america_weekdays_price_night=45.00;
	float america_weekends_price_day=40.00;
	float america_weekends_price_night=38.00;
	
	// ASIA - per 2 mins
	float asia_weekdays_price_day=30.00;
	float asia_weekdays_price_night=27.00;
	float asia_weekends_price_day=25.00;
	float asia_weekends_price_night=15.00;
	
	// AFRICA - per 3 mins
	float africa_weekdays_price_day=40.00;
	float africa_weekdays_price_night=35.00;
	float africa_weekends_price_day=35.00;
	float africa_weekends_price_night=22.00;

	// EUROPE - per 2 mins
	float europe_weekdays_price_day=35.00;
	float europe_weekdays_price_night=30.00;
	float europe_weekends_price_day=20.00;
	float europe_weekends_price_night=19.00;
	
	switch (destination_code) {
		//AMERICA
		case 1: if (time_code == 'A' || time_code == 'a') {
				if(day_code == 'X' || day_code == 'x'){
					float pricepermin=america_weekdays_price_day/3;
					float mins=cust_creds/pricepermin;
					float sec=mins*60;
					int remaining=(int)sec%60;
					if (remaining==0){
						printf("You have %.0fmins calltime",mins);
					}
					else {
						printf("You have %.0fmins and %dsecs calltime",mins,remaining); 
					}
					
				}
				else if (day_code == 'Y' || day_code == 'y'){
					float pricepermin=america_weekends_price_day/3;
					float mins=cust_creds/pricepermin;
					float sec=mins*60;
					int remaining=(int)sec%60;
					if (remaining==0){
						printf("You have %.0fmins calltime",mins);
					}
					else {
						printf("You have %.0fmins and %dsecs calltime",mins,remaining); 
					}
				}
			}
			else if (time_code == 'B' || time_code =='b'){
				if(day_code == 'X' || day_code == 'x'){
					printf(" tas weekdays");
				}
				else if (day_code == 'Y' || day_code == 'y'){
					printf(" tas weekends");
				}
			}
			break;
		//ASIA
		case 2: if (time_code == 'A' || time_code == 'a') {
				if(day_code == 'X' || day_code == 'x'){
					printf(" tas weekdays");
				}
				else if (day_code == 'Y' || day_code == 'y'){
					printf(" tas weekends");
				}
			}
			else if (time_code == 'B' || time_code =='b'){
				if(day_code == 'X' || day_code == 'x'){
					printf(" tas weekdays");
				}
				else if (day_code == 'Y' || day_code == 'y'){
					printf(" tas weekends");
				}
			}
			break;
		//AFRICA
		case 3: if (time_code == 'A' || time_code == 'a') {
				if(day_code == 'X' || day_code == 'x'){
					printf(" tas weekdays");
				}
				else if (day_code == 'Y' || day_code == 'y'){
					printf(" tas weekends");
				}
			}
			else if (time_code == 'B' || time_code =='b'){
				if(day_code == 'X' || day_code == 'x'){
					printf(" tas weekdays");
				}
				else if (day_code == 'Y' || day_code == 'y'){
					printf(" tas weekends");
				}
			}
			break;
		//EUROPE
		case 4: if (time_code == 'A' || time_code == 'a') {
				if(day_code == 'X' || day_code == 'x'){
					printf(" tas weekdays");
				}
				else if (day_code == 'Y' || day_code == 'y'){
					printf(" tas weekends");
				}
			}
			else if (time_code == 'B' || time_code =='b'){
				if(day_code == 'X' || day_code == 'x'){
					printf(" tas weekdays");
				}
				else if (day_code == 'Y' || day_code == 'y'){
					printf(" tas weekends");
				}
			}
			break;
		default : printf("You've had input the wrong destination choice. Exiting..");break;
	}
	
	printf("\n");
	return 0;
}
