#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define NmS 50
#define NbS 15

int main(){

	char cust_name[NmS],cust_num[NbS];
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
	
	printf("\n");
	return 0;
}
