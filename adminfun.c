#include <string.h>
#include <stdlib.h>
struct cust{
  char name[20];
  int accno;
  int bal;
  char pass[10];
}cust1;
void add_acc(){
  system("cls");
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
  fp = fopen(temp,"w+");
  fputs(cust1.pass,fp);
  fclose(fp);
  char temp3[20] = "cust_details/";
  char temp4[10] = ".txt";
  strcpy(name2,cust1.name);
  strcat(temp3,name2);
  strcat(temp3,temp4);
  printf("%s",temp3);
  
  /*fp = fopen(temp3, "w+");
  fprintf(fp,"---Account Details---\n\n");
  fprintf(fp,"Name : %s\nAccount No: %d\nBalance: %d\n",cust_name,cust1.accno,cust1.bal);
  
  fclose(fp);
  fp = fopen(temp3, "r");
  if(fp){
    printf("Successful Added Account\n");
    char c;
    c = fgetc(fp);
    while(c!=EOF){
      printf(" %c",c);
      c = fgetc(fp);
    }
  }
    else{
      printf("Something Went Wrong");
    }*/
  }
  