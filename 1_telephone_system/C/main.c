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
	
	return 0;
}
