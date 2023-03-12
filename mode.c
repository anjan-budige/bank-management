#include <string.h>
#include <stdlib.h>
#include "adminfun.c"


void admin(){
  system("cls");
  char user[20];
  char pass[20];
  char pass2[20];
  int flag = 0;
	printf("\n--- Admin Login ----\n");
	printf("Enter Username: ");
	scanf("%s",user);
	char file[10] = ".txt";
	strcat(user,file);
	
	FILE *fp;
	fp = fopen(user, "r");
	if(fp != NULL){
	  printf("Enter Password: ");
	  scanf("%s",pass);
	  fgets(pass2,10,fp);
	  if(strcmp(pass2,pass)==0){
	    printf("Login Successful\n");
	    flag =1;
	    fclose(fp);
	  }
	  else{
	    printf("Password Wrong Please Check It\n");
	  }
	  
	  
	  
	  
	}
	else{
	  printf("User Not Found");
	}
	
	
	if(flag==1){
	printf("1. Add Account\n2. Delete Account \n3. Check All Account\n4. Edit Account\n5. Exit\n");
	
	int a;
	printf("Enter Your Option: ");
	scanf("%d",&a);
	switch(a){
	  case 1:{
	    add_acc();
	    break;
	  }
	  case 2:{
	    //delete_acc();
	    break;
	  }
	  case 3:{
	    //check_all();
	    break;
	  }
	  case 4:
	  {
	    //edit_acc();
	    break;
	  }
	  case 5:{
	    //exit(0);
	    
	  }
	  default:{
	    printf("Invalid Option\n");
	  }
	 
	  
	}
	
	
	}
	

	
	
}
void staff(){
  char user[20];
  char pass[20];
  char pass2[20];
  int flag = 0;
	printf("\n--- Staff Login ----\n");
	printf("Enter Username: ");
	scanf("%s",user);
	char file[20] = "staff_acc/";
	strcat(file,user);
	char file2[20] = ".txt";
	strcat(file,file2);
	char filen[20];
	strcpy(filen,file);
	FILE *fp;
	fp = fopen(filen, "r");
	if(fp != NULL){
	  printf("Enter Password: ");
	  scanf("%s",pass);
	  fgets(pass2,10,fp);
	  if(strcmp(pass2,pass)==0){
	    printf("Login Successful\n");
	    flag =1;
	    fclose(fp);
	  }
	  else{
	    printf("Password Wrong Please Check It\n");
	  }
	  
	  
	  
	  
	}
	else{
	  printf("User Not Found");
	}
	
	
	if(flag==1){
	printf("1. Withdraw\n2. Deposit \n3. User Balance Check\n4. Edit Account\n5. Exit\n");
	}
	
}
void customer(){
	printf("--- Customer Login----");
}
