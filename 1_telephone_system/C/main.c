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
	char time_code,day_code;
	printf("\nDestination of your call");
	printf("    1. American Region");
	printf("    2. Asian Region");
	printf("    3. African Region");
	printf("    4. European Region");
	printf("Enter your choice : ");
	scanf("%d",&destination_code);
	printf("\nTime Code : ");
	printf("    A. Daytime");
	printf("    B. Nighttime");
	printf("Enter your choice : ");
	scanf("%c",&time_code);
	printf("\nDay Code : ");
	printf("    X. Weekdays");
	printf("    Y. Weekends");
	printf("Enter your choice : ");
	scanf("%c",&day_code);
	printf("Enter your available load/credits : ");
	scanf("%d",&cust_creds);
	
	system("clear");
	printf("\nCustomer Name : %s",cust_name);
	printf("\nCustomer Number : %s",cust_num);	
	

	return 0;
}
