#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct name
{
char username[30];
char phonenumber[50];
char accountnumber[50];
char passcode[50];
float balance;
float rewardPoints;
};

int main()
{
struct name cus,bnk;
char username[30],dataname[50],phonenumber[50],passcode[50],phone2[50];
FILE *fp,*fptr;
int option,select;
int cash;
char condition = 'y';
printf("\nSelect the Choice");
printf("\n\n1.Account Registration");
printf("\n2.Account Login");

printf("\n\nPlease Provid your choice:\t");
scanf("%d",&option);
if(option == 1)
{
system("clear");
printf("\nProvide your Name as in Aadhar:\t");
scanf("%s",cus.username);
printf("\nProvide your Account Number:\t");
scanf("%s",cus.accountnumber);
printf("\nProvide your Phone Number:\t");
scanf("%s",cus.phonenumber);
printf("\nProvide your new Passcode:\t");
scanf("%s",cus.passcode);
cus.balance=0;
stpcpy(dataname,cus.phonenumber);
fp=fopen(strcat(dataname,".info"),"w");
fwrite(&cus,sizeof(cus),1,fp);
if(fwrite != 0){
printf("Accounr Registration Successful");
}
}
else if(option == 2){
system("clear");
printf("\nPhonenumber.:\t");
scanf("%s",phonenumber);
printf("Passcode:\t");
scanf("%s",passcode);
fp = fopen(strcat(phonenumber,".info"),"r");
if(fp == NULL) printf("Account Details Wrong. Provide valid Account Details");
else {
fread(&cus,sizeof(struct name),1,fp);
fclose(fp);
if(!strcmp(passcode,cus.passcode)){
while(condition == 'y'){
system("clear");
printf("\n\tHELLO %s",cus.username);
printf("\nEnter 1 for Balance Check");
printf("\nEnter 2 for Deposit Cash");
printf("\nEnter 3 for Withdraw Cash");
printf("\nEnter 4 for Show My Reward Points");
printf("\nEnter 5 for Transfer Money");
printf("\nEnter 6 for Change Password\n\n");
scanf("%d",&select);
switch(select){
case 1:
printf("Balance in your Account Rs. %.2f",cus.balance);
break;

case 2:
system("clear");
printf("Enter the Cash to Deposit:\t");
scanf("%d",&cash);
cus.balance += cash;
cus.rewardPoints += cash * 1/ 100;
fp = fopen(phonenumber,"w");
fwrite(&cus,sizeof(struct name),1,fp);
if(fwrite !=0) printf("\n\nRs.%d Cash Added Successfully",cash);
fclose(fp);
break;

case 3:
system("clear");
printf("Provide the Cash for withdrawal:\t");
scanf("%d",&cash);
if(cash % 500 != 0) printf("\nEnter cash in multiple of 500's");
else if(cash>cus.balance) printf("\nYou Don't have that much Cash");
else {
cus.balance -= cash;
fp = fopen(phonenumber,"w");
fwrite(&cus,sizeof(struct name),1,fp);
if(fwrite !=0) printf("\n\nYou Taken Rs.%d",cash);
fclose(fp);
}
break;

case 4:
printf("Your Reward Point is . %.2f",cus.rewardPoints);
break;


case 5:
printf("Provide Account Hoder phonenumber to Trasnfer Cash:\t");
scanf("%s",phonenumber);
printf("Enter the cash to transfer:\t");
scanf("%d",&cash);
if(cash > cus.balance) printf("\n insufficent balance");
else {
fptr = fopen(strcat(phonenumber,".info"),"r");
if(fptr==NULL) printf("User not found . Check Account Holder phone number");
else {
fread(&bnk,sizeof(struct name),1,fptr);
fclose(fptr);

bnk.balance += cash;

fptr = fopen(phonenumber,"w");
fwrite(&bnk,sizeof(struct name),1,fptr);
if(fwrite != 0){
printf("Cash Transaction Done. You have trasnfered Rs.%d to %s",cash,bnk.phonenumber);
fclose(fptr);
cus.balance -= cash;
strcpy(dataname,cus.phonenumber);
fp = fopen(strcat(dataname,".info"),"w");
fwrite(&cus,sizeof(struct name),1,fp);
fclose(fp);
}
}
}
break;
case 6:
printf("\n\nYour old passcode:\t");
scanf("%s",passcode);
if(!strcmp(passcode,cus.passcode)){
printf("\n\nProvide new passcode:\t");
scanf("%s",passcode);
strcpy(cus.passcode,passcode);
strcpy(dataname,cus.phonenumber);
fp = fopen(strcat(dataname,".info"),"w");
fwrite(&cus,sizeof(struct name),1,fp);
fclose(fp);
printf("\n New Passcode updated");
}else printf("\n passcode Missatch. Provide a valid one.");

default:
break;
}
printf("\n\nNeed More service?[y/n]:\t");
scanf("%s",&condition);
}
}
else {
printf("Invalid passcode");
}
}
printf("\n\n*Thank you for using A_B_I INTERNET BANKING SYSTEM*\n\n");
}

return 0;
}