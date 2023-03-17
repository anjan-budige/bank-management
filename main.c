#include <stdio.h>
#include "mode.c"
int main(){
	printf("Neo Bank Management System V1.0 \n\n");
	printf("1. Admin Login\n2. Staff Login\n3. Customer Login\n4. About Neo\n5. About Neo BMS v1.0\n6. Exit\n");

int a;
printf("Enter Your Choice: ");
scanf("%d",&a);
switch(a){
	case 1: {
		admin();
		break;
	}
	case 2: {
		staff();
		break;
	}
	case 3: {
		customer();
		break;
	}
	case 4:{
		printf("------- Neo Bank-------\n");
		printf("Neo Is an indian banking & financial services company");
		break;
	}
	case 5:{
			printf("------- Neo BMS v1.0-------\n");
		printf("Neo BMS is for Neo Bank Costumers, This offers users to check their balance, transcations, Customer Details & Many More");
		break;
		
	}
	case 6:{
		printf("\nThanks For Using Our Service\n\n DEVELOPED BY ANJAN BUDIGE   \n");	break;
	}
		
	
}



}
