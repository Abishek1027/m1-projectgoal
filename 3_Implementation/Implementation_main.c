#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct user
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
struct user user,usr;
char username[30],filename[50],phonenumber[50],passcode[50],phone2[50];
FILE *fp,*fptr;
int opt,choice;
int cash;
char cont = 'y';
printf("\nSelect the Choice");
printf("\n\n1.Account Registration");
printf("\n2.Account Login");

printf("\n\nPlease enter your choice:\t");
scanf("%d",&opt);
if(opt == 1)
{
system("clear");
printf("\nEnter your Name as in Aadhar:\t");
scanf("%s",user.username);
printf("\nEnter your Account Number:\t");
scanf("%s",user.accountnumber);
printf("\nEnter your Phone Number:\t");
scanf("%s",user.phonenumber);
printf("\nEnter your new Passcode:\t");
scanf("%s",user.passcode);
user.balance=0;
stpcpy(filename,user.phonenumber);
fp=fopen(strcat(filename,".dat"),"w");
fwrite(&user,sizeof(user),1,fp);
if(fwrite != 0){
printf("User Registration is Successful");
}
}
else if(opt == 2){
system("clear");
printf("\nPhone No.:\t");
scanf("%s",phonenumber);
printf("Passcode:\t");
scanf("%s",passcode);
fp = fopen(strcat(phonenumber,".dat"),"r");
if(fp == NULL) printf("Account Details not Found. Please enter valid Login Details");
else {
fread(&user,sizeof(struct user),1,fp);
fclose(fp);
if(!strcmp(passcode,user.passcode)){
while(cont == 'y'){
system("clear");
printf("\n\tWelcome %s",user.username);
printf("\nPress 1 for Balance Check");
printf("\nPress 2 for Deposit Cash");
printf("\nPress 3 for Withdraw Cash");
printf("\nPress 4 for Show My Reward Points");
printf("\nPress 5 for Transfer Money");
printf("\nPress 6 for Change Password\n\n");
scanf("%d",&choice);
switch(choice){
case 1:
printf("Your current balance is Rs. %.2f",user.balance);
break;

case 2:
system("clear");
printf("Enter the Cash to Deposit:\t");
scanf("%d",&cash);
user.balance += cash;
user.rewardPoints += cash * 1/ 100;
fp = fopen(phonenumber,"w");
fwrite(&user,sizeof(struct user),1,fp);
if(fwrite !=0) printf("\n\nRs.%d Deposited Successfully",cash);
fclose(fp);
break;

case 3:
system("clear");
printf("Enter the Cash to withdraw:\t");
scanf("%d",&cash);
if(cash % 500 != 0) printf("\nSorry! Enter cash in multiple of 500's");
else if(cash>user.balance) printf("\ninsufficeint Cash");
else {
user.balance -= cash;
fp = fopen(phonenumber,"w");
fwrite(&user,sizeof(struct user),1,fp);
if(fwrite !=0) printf("\n\nYou Taken Rs.%d",cash);
fclose(fp);
}
break;

case 4:
printf("Your Reward Point is . %.2f",user.rewardPoints);
break;


case 5:
printf("Please Enter the phonenumber to Trasnfer Balance:\t");
scanf("%s",phonenumber);
printf("Enter the cash to transfer:\t");
scanf("%d",&cash);
if(cash > user.balance) printf("\n insufficent balance");
else {
fptr = fopen(strcat(phonenumber,".dat"),"r");
if(fptr==NULL) printf("Sorry account not found . Please verify the phone number");
else {
fread(&usr,sizeof(struct user),1,fptr);
fclose(fptr);

usr.balance += cash;

fptr = fopen(phonenumber,"w");
fwrite(&usr,sizeof(struct user),1,fptr);
if(fwrite != 0){
printf("Money transferred succesfullly. You have trasnfered Rs.%d to %s",cash,usr.phonenumber);
fclose(fptr);
user.balance -= cash;
strcpy(filename,user.phonenumber);
fp = fopen(strcat(filename,".dat"),"w");
fwrite(&user,sizeof(struct user),1,fp);
fclose(fp);
}
}
}
break;
case 6:
printf("\n\nYour old passcode:\t");
scanf("%s",passcode);
if(!strcmp(passcode,user.passcode)){
printf("\n\nPlease enter your new passcode:\t");
scanf("%s",passcode);
strcpy(user.passcode,passcode);
strcpy(filename,user.phonenumber);
fp = fopen(strcat(filename,".dat"),"w");
fwrite(&user,sizeof(struct user),1,fp);
fclose(fp);
printf("\nPasscode succesfullly updated in our System");
}else printf("\nSorry your passcode does not Match. Try again.");

default:
break;
}
printf("\n\nDo you want to continue?[y/n]:\t");
scanf("%s",&cont);
}
}
else {
printf("Invalid passcode");
}
}
printf("\n\n***Thank you for banking with Indian bank***\n\n");
}

return 0;
}