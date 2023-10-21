#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct User{
    char userName[1000], email[1000], password[1000]; 
    union Active{
        int num;
        char isActive [1000];
    }accountState;
}currentUser;

struct User usersInfo[1000];
int usersInfoIndx = 0;

void registerUser(){
 //   struct User currentUser; 
    printf("Enter your username: ");
    scanf("%s", &currentUser.userName);
    printf("Enter your email: ");
    scanf("%s", &currentUser.email);
    printf("Enter your password: ");
    scanf("%s", &currentUser.password);
    printf("Enter 1 or true if your account will be active. Otherwise, Enter 0 or false: ");
    char str[1000];
    scanf("%s", str);
    if(!strcmp(str, "0"))  currentUser.accountState.num = 0;
    else if(!strcmp(str, "1"))  currentUser.accountState.num = 1;
    else if(!strcmp(str, "false"))  strcpy(currentUser.accountState.isActive, "false");
    else  strcpy(currentUser.accountState.isActive, "true");
   // if(!strcmp(str, "0") || !strcmp(str, "false"))  strcpy(currentUser.accountState.isActive, "false");
  //  else  strcpy(currentUser.accountState.isActive, "true");
    bool found = 0;
    for(int i=0; i<usersInfoIndx; i++){
        if(!strcmp(currentUser.email, usersInfo[i].email)){
            printf("You already registered before!\n");
            found = 1;
            break;
        }
    }
    if(!found){
        usersInfo[usersInfoIndx] = currentUser;
        usersInfoIndx++;
        printf("Registration is completed!\n");
    }
}

void loginUser(char userName[], char email[], char password[]){
    bool found = 0;
    for(int i=0; i<usersInfoIndx; i++){
        if(!strcmp(userName, usersInfo[i].userName) && !strcmp(email, usersInfo[i].email) && !strcmp(password, usersInfo[i].password)){
            if(!strcmp(usersInfo[i].accountState.isActive, "false") || !usersInfo[i].accountState.num){  
                printf("Sorry you can't login as your account is not active!\n");
                return;
            } 
            printf("Login successfuly Welcome, %s\n", userName);
            found = 1;
            break;
        }
    }
    if(!found)  printf("Invalid Information!, Try again!\n");
}

int main(){
    printf("Select a choice: \n1.Rgister\n2.Login\n3.Exit\n");
    while(true){
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
        switch(choice){
            case 1: 
                registerUser();
                break;
            case 2:
                char userName[1000], email[1000], password[1000]; 
                printf("Enter your username: ");
                scanf("%s", &userName);
                printf("Enter your email: ");
                scanf("%s", &email);
                printf("Enter your password: ");
                scanf("%s", &password);
                loginUser(userName, email, password);
                break;
            case 3:
                printf("You exit the system!");
                return 0;
            default:
                printf("No such a choice found! Please, Select a corrcet choice!\n");
                break;
        }
    }
    return 0;
}