#include <string.h>
#include <stdlib.h>
#include <dirent.h>
struct cust{
  char name[20];
  int accno;
  int bal;
  char pass[10];
}cust1;

void add_acc(){
  static int ac = 14334;
  system("clear");
  char name[20];
  char name2[20];
  char cust_name[20];
  printf("----Add Account-----\n\n");
  printf("Enter Customer Name: ");
  scanf("%s",cust1.name);
  strcpy(name,cust1.name);
  strcpy(cust_name,name);
  cust1.accno = ++ac;
  printf("Enter Customer Opening Balance: ");
  scanf("%d",&cust1.bal);
  printf("Enter Customer Password: ");
  scanf("%s",cust1.pass);
  char temp[20] = "cust_acc/";
  strcat(temp,name);
  char temp2[20] = ".txt";
  strcat(temp,temp2);
  FILE *fp;
  fp = fopen(temp,"w");
  fputs(cust1.pass,fp);
  fclose(fp);
  
  char temp3[20] = "cust_details/";
  char temp4[10] = ".txt";
  strcpy(name2,cust1.name);
  strcat(temp3,name2);
  strcat(temp3,temp4);
  
  fp = fopen(temp3, "w");
  fprintf(fp,"---Account Details---\n\n");
  fprintf(fp,"Name : %s\nAccount No: %d\nBalance: %d\n",cust_name,cust1.accno,cust1.bal);
  
  fclose(fp);
  fp = fopen(temp3, "r");
  if(fp){
    printf("\nSuccessful Added Account\n");
    char c;
    c = fgetc(fp);
    while(c != NULL){
      printf("%c",c);
      c = fgetc(fp);
    }
  }
    else{
      printf("Something Went Wrong");
    }
  }
  
  void delete_acc(){
    system("clear");
    char name[30];
    char line[200];
    int a,b;
    char c;
    printf("Delete Customer\n1 For Delete with customer name\n2 for Delete with Account No\n\nSelect Option: ");
    scanf("%d",&a);
    if(a==1){
    printf("Enter Account Name : ");
    scanf("%s",name);
    char folder[20] = "cust_details/";
    char name2[20] = ".txt";
    strcat(name,name2);
    strcat(folder,name);
    printf("%s\n",folder);
    FILE *fp;
    fp = fopen(folder,"r");
    if(fp){
      printf("Account Found\n\n");
      printf("Check Details\n");
      c = fgetc(fp);
      while(c != EOF){
        printf("%c",c);
        c = fgetc(fp);
      }
      printf("\n\n Are you want to delete this account (Enter 1 for yes, 2 for no) : ");
      scanf("%d",&b);
      if(b==1){
        if(remove(name)==0){
          printf("Account Deleted Successfully\n");
        }
        else{
          printf("Unable To Delete\n");
        }
      }
      else{
        printf("Deletion of account cancelled");
      }
      
    }else{
      printf("Error Not Working Please Check Code\n");
    }
    }
    if(a==2){
      printf("Enter Customer Account No: ");
      scanf("%s",name);
      DIR *dr;
      dr = opendir("/cust_details");
      struct dirent *filen;
      char found[20];
      char c;
      int flag = 0;
      if(dr){
        while ((filen = readdir(dr)) != NULL) {
      
          FILE *fp1;
          fp1 = fopen(filen->d_name,"r");
          fgets(line,100,fp1);
          while(line != NULL){
            if(strstr(line,name)){
              strcpy(found,filen);
              flag = 1;
              break;
            }
            }
            if(flag==1){
              printf("Account Found\n");
              break;
          }
          fclose(fp1);
          if(flag==0){
            printf("User Not Found\n");
          }
        }
      }
      else{
        printf("Accouns Files Not Found");
      }
      if(flag==1){
        FILE *fp1;
        fp1 = fopen(found,"r");
        printf("\nCheck Detials\n");
        c = fgetc(fp1);
        while(c!=EOF){
          printf("%c",c);
          c = fgetc(fp1);
        }
        printf("\n\n Are you want to delete this account (Enter 1 for yes, 2 for no) : ");
      scanf("%d",&b);
      if(b==1){
        if(remove(found)==0){
          printf("Account Deleted Successfully\n");
        }
        else{
          printf("Unable To Delete\n");
        }
      }
      else{
        printf("Deletion of account cancelled");
      }
        
      }
      
      
      
      
    }
    
    
    
  }
  
  
  