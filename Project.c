#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Record {
    char Name[64];
    char Address[128];
    char Number[32];
    char Type[32];
    char Website[32];
    char Budget[10];
}COMP;

int loginForm(){
    char Shajibuser[64]="shajib1998", Amituser[64]="amit";
    char Shajibpass[64]="asdfghjkl", Amitpass[64]="asdfghjkl";
    char user[64], pass[64], c;
    int i=0;
    printf("Please enter your credentials to login to the event management system.\n");
    x:
    printf("Username: ");
    gets(user);
    if(strcmp(user,Shajibuser)==0){
        printf("Password [max 36]: ");
        while (i<36){
            pass[i]=getch();
            c=pass[i];
            if(c==13) break;
            else printf("*");
            i++;
        }
        pass[i]='\0';
        if(strcmp(pass,Shajibpass)==0) return 1;
        else return 0;
    }
    else if(strcmp(user,Amituser)==0){
        printf("Password [max 36]: ");
        while (i<36){
            pass[i]=getch();
            c=pass[i];
            if(c==13) break;
            else printf("*");
            i++;
        }
        pass[i]='\0';
        if(strcmp(pass,Amitpass)==0) return 1;
        else return 0;
    }
    else {printf("Invalid username. Try again.\n"); goto x; }

}

void addRec(int n, int pre){
    FILE *fp;
    fp=fopen("Record.txt", "a");
    if(fp==NULL) {
            printf("File not created.");
            return;
            }
    COMP Rec[n];
    int i;

    for(i=pre;i<n;i++){
        fprintf(fp, "%d\n", i+1);
        printf("Name: ");
        scanf("%s", &Rec[i].Name);
        fprintf(fp, "%s\n", Rec[i].Name);
        printf("Address: ");
        scanf("%s", &Rec[i].Address);
        fprintf(fp, "%s\n", Rec[i].Address);
        printf("Number: ");
        scanf("%s", &Rec[i].Number);
        fprintf(fp, "%s\n", Rec[i].Number);
        printf("Type: ");
        scanf("%s", &Rec[i].Type);
        fprintf(fp, "%s\n", Rec[i].Type);
        printf("Website: ");
        scanf("%s", &Rec[i].Website);
        fprintf(fp, "%s\n", Rec[i].Website);
        printf("Budget: ");
        scanf("%s", &Rec[i].Budget);
        fprintf(fp, "%s\n", Rec[i].Budget);
    }
    fflush(stdin);
    fclose(fp);
    return;
}

void viewRec(){
    char str[128];
    FILE *fp;
    fp=fopen("Record.txt", "r");
        if(fp==NULL) {
            printf("File not found.");
            return;
            }
    while(fgets(str, 128, fp)!=NULL){
      printf("ID: %s", str);
      fgets(str, 128, fp);
      printf("Name: %s", str);
      fgets(str, 128, fp);
      printf("Address: %s", str);
      fgets(str, 128, fp);
      printf("Number: %s", str);
      fgets(str, 128, fp);
      printf("Type: %s", str);
      fgets(str, 128, fp);
      printf("Website: %s", str);
      fgets(str, 128, fp);
      printf("Budget: %s\n", str);
    }
}

void editRec(int n){
    COMP Rec[n];
    int i=0, choice;
    char str[128], o;
    FILE *fp;
    fp=fopen("Record.txt", "r");
        if(fp==NULL) {
            printf("File not found.");
            return;
            }
    while(fgets(str, 128, fp)!=NULL){
      fgets(str, 128, fp);
      strcpy(Rec[i].Name, str);
      fgets(str, 128, fp);
      strcpy(Rec[i].Address, str);
      fgets(str, 128, fp);
      strcpy(Rec[i].Number, str);
      fgets(str, 128, fp);
      strcpy(Rec[i].Type, str);
      fgets(str, 128, fp);
      strcpy(Rec[i].Website, str);
      fgets(str, 128, fp);
      strcpy(Rec[i].Budget, str);
      i++;
    }

    fclose(fp);

    for(i=0; i<n; i++) printf("ID: %d\nName: %sAddress: %sNumber: %sType: %sWebsite: %sBudget: %s\n", i+1, Rec[i].Name, Rec[i].Address, Rec[i].Number, Rec[i].Type, Rec[i].Website, Rec[i].Budget);

    printf("\nWhich ID do you want to edit? \nAns:");
    scanf("%d", &i);
    i--;
    z1:
    printf("What do you want to edit?\n1. Name\n2. Address\n3. Number\n4. Type\n5. Website\n6. Budget.\nAns: ");
    scanf("%d",&choice);
    switch(choice){
    case 1:
        printf("Name: ");
        scanf("%s", &Rec[i].Name);
        break;
    case 2:
        printf("Address: ");
        scanf("%s", &Rec[i].Address);
        break;
    case 3:
        printf("Number: ");
        scanf("%s", &Rec[i].Number);
        break;
    case 4:
        printf("Type: ");
        scanf("%s", &Rec[i].Type);
        break;
    case 5:
        printf("Website: ");
        scanf("%s", &Rec[i].Website);
        break;
    case 6:
        printf("Budget ");
        scanf("%s", &Rec[i].Budget);
        break;
    default:
        printf("Invalid Input. Try Again.\n");
        goto z1;
        break;
        }
    int temp=i;
    printf("\nThe updated version is: \n");
    for(i=0; i<n; i++){
        if(i==temp) {
            switch(choice){
            case 1:
                printf("ID: %d\nName: %s\nAddress: %sNumber: %sType: %sWebsite: %sBudget: %s\n", i+1, Rec[i].Name, Rec[i].Address, Rec[i].Number, Rec[i].Type, Rec[i].Website, Rec[i].Budget);
                break;
            case 2:
                printf("ID: %d\nName: %sAddress: %s\nNumber: %sType: %sWebsite: %sBudget: %s\n", i+1, Rec[i].Name, Rec[i].Address, Rec[i].Number, Rec[i].Type, Rec[i].Website, Rec[i].Budget);
                break;
            case 3:
                printf("ID: %d\nName: %sAddress: %sNumber: %s\nType: %sWebsite: %sBudget: %s\n", i+1, Rec[i].Name, Rec[i].Address, Rec[i].Number, Rec[i].Type, Rec[i].Website, Rec[i].Budget);
                break;
            case 4:
                printf("ID: %d\nName: %sAddress: %sNumber: %sType: %s\nWebsite: %sBudget: %s\n", i+1, Rec[i].Name, Rec[i].Address, Rec[i].Number, Rec[i].Type, Rec[i].Website, Rec[i].Budget);
                break;
            case 5:
                printf("ID: %d\nName: %sAddress: %sNumber: %sType: %sWebsite: %s\nBudget: %s\n", i+1, Rec[i].Name, Rec[i].Address, Rec[i].Number, Rec[i].Type, Rec[i].Website, Rec[i].Budget);
                break;
            case 6:
                printf("ID: %d\nName: %sAddress: %sNumber: %sType: %sWebsite: %sBudget: %s\n\n", i+1, Rec[i].Name, Rec[i].Address, Rec[i].Number, Rec[i].Type, Rec[i].Website, Rec[i].Budget);
                break;
            }
        }
        else printf("ID: %d\nName: %sAddress: %sNumber: %sType: %sWebsite: %sBudget: %s\n", i+1, Rec[i].Name, Rec[i].Address, Rec[i].Number, Rec[i].Type, Rec[i].Website, Rec[i].Budget);
    }

    fp=fopen("Record.txt", "w");
    if(fp==NULL) {
            printf("File not created.");
            return;
            }

    for(i=0;i<n;i++){
        if(i==temp) {
            switch(choice){
            case 1:
                fprintf(fp, "%d\n", i+1);
                fprintf(fp, "%s\n", Rec[i].Name);
                fprintf(fp, "%s", Rec[i].Address);
                fprintf(fp, "%s", Rec[i].Number);
                fprintf(fp, "%s", Rec[i].Type);
                fprintf(fp, "%s", Rec[i].Website);
                fprintf(fp, "%s", Rec[i].Budget);
                break;
            case 2:
                fprintf(fp, "%d\n", i+1);
                fprintf(fp, "%s", Rec[i].Name);
                fprintf(fp, "%s\n", Rec[i].Address);
                fprintf(fp, "%s", Rec[i].Number);
                fprintf(fp, "%s", Rec[i].Type);
                fprintf(fp, "%s", Rec[i].Website);
                fprintf(fp, "%s", Rec[i].Budget);
                break;
            case 3:
                fprintf(fp, "%d\n", i+1);
                fprintf(fp, "%s", Rec[i].Name);
                fprintf(fp, "%s", Rec[i].Address);
                fprintf(fp, "%s\n", Rec[i].Number);
                fprintf(fp, "%s", Rec[i].Type);
                fprintf(fp, "%s", Rec[i].Website);
                fprintf(fp, "%s", Rec[i].Budget);
                break;
            case 4:
                fprintf(fp, "%d\n", i+1);
                fprintf(fp, "%s", Rec[i].Name);
                fprintf(fp, "%s", Rec[i].Address);
                fprintf(fp, "%s", Rec[i].Number);
                fprintf(fp, "%s\n", Rec[i].Type);
                fprintf(fp, "%s", Rec[i].Website);
                fprintf(fp, "%s", Rec[i].Budget);
                break;
            case 5:
                fprintf(fp, "%d\n", i+1);
                fprintf(fp, "%s", Rec[i].Name);
                fprintf(fp, "%s", Rec[i].Address);
                fprintf(fp, "%s", Rec[i].Number);
                fprintf(fp, "%s", Rec[i].Type);
                fprintf(fp, "%s\n", Rec[i].Website);
                fprintf(fp, "%s", Rec[i].Budget);
                break;
            case 6:
                fprintf(fp, "%d\n", i+1);
                fprintf(fp, "%s", Rec[i].Name);
                fprintf(fp, "%s", Rec[i].Address);
                fprintf(fp, "%s", Rec[i].Number);
                fprintf(fp, "%s", Rec[i].Type);
                fprintf(fp, "%s", Rec[i].Website);
                fprintf(fp, "%s\n", Rec[i].Budget);
                break;
            }
        }
        else {
            fprintf(fp, "%d\n", i+1);
            fprintf(fp, "%s", Rec[i].Name);
            fprintf(fp, "%s", Rec[i].Address);
            fprintf(fp, "%s", Rec[i].Number);
            fprintf(fp, "%s", Rec[i].Type);
            fprintf(fp, "%s", Rec[i].Website);
            fprintf(fp, "%s", Rec[i].Budget);

        }
    }
    fflush(stdin);
    fclose(fp);

    return;
}

void searchRec(int n){
    int i=0;
    char str[128];

    FILE *fp;
    fp=fopen("Record.txt", "r");
        if(fp==NULL) {
            printf("File not found.");
            return;
            }

    COMP Rec[n];

    while(fgets(str, 128, fp)!=NULL){
      fgets(str, 128, fp);
      strcpy(Rec[i].Name, str);
      fgets(str, 128, fp);
      strcpy(Rec[i].Address, str);
      fgets(str, 128, fp);
      strcpy(Rec[i].Number, str);
      fgets(str, 128, fp);
      strcpy(Rec[i].Type, str);
      fgets(str, 128, fp);
      strcpy(Rec[i].Website, str);
      fgets(str, 128, fp);
      strcpy(Rec[i].Budget, str);
      i++;
    }

    fclose(fp);

    int choice;
    printf("Enter your Budget: ");
    scanf("%d", &choice);
    for(i=0;i<n;i++){
        if(atoi(Rec[i].Budget)<=choice) printf("ID: %d\nName: %sAddress: %sNumber: %sType: %sWebsite: %sBudget: %s\n", i+1, Rec[i].Name, Rec[i].Address, Rec[i].Number, Rec[i].Type, Rec[i].Website, Rec[i].Budget);
    }

    return;
}

int main(){
    int c;
    printf("Welcome to our Event Management Database.");
    int i=loginForm();
    if(i==1){
        int n, pre=0;
        FILE *fptr;
        y:
        printf("\nPlease select a function from below:\n1. Add Records.\n2. View Records.\n3. Edit Records.\n4. Search Records.\n5. EXIT.\nInput: ");
        scanf("%d", &c);
        switch(c){
            case 1:
                fptr=fopen("No.txt", "r");
                if(fptr=='/0') fptr=fopen("No.txt", "w");
                else fscanf(fptr, "%d", &pre);
                printf("Enter the number of Records: ");
                scanf("%d", &n);
                n=n+pre;
                fptr=fopen("No.txt", "w");
                fprintf(fptr, "%d", n);
                addRec(n, pre);
                fclose(fptr);
                goto y;
                break;
            case 2:
                viewRec();
                goto y;
                break;
            case 3:
                fptr=fopen("No.txt", "r");
                fscanf(fptr, "%d", &n);
                editRec(n);
                fclose(fptr);
                goto y;
                break;
            case 4:
                fptr=fopen("No.txt", "r");
                fscanf(fptr, "%d", &n);
                searchRec(n);
                fclose(fptr);
                goto y;
                break;
            case 5:
                break;
            default:
                goto y;
                break;
        }
    }
    return 0;
}

