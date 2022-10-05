#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int menu();
void create_account();
void login();

struct User
{
    char pass[50];
    char user_name[50];
    char first_name[50];
    char last_name[50];
}u;

int main()
{
    while(1)
    {
        switch (menu())
        {
            case 1:
                create_account();
                break;

            case 2:
                login();
                break;

            case 3:
                exit(0);
                break;

            default:
                printf("Please Enter Valid Choice.");
                break;
        }
    }
    return 0;
}
int menu()
{
    int ch;
    system("cls");
    printf("**********Menu**********\n");
    printf("\n1....Create Account: ");
    printf("\n2....Login: ");
    printf("\n3....Exit: ");

    printf("\n\nEnter Choice: ");
    scanf("%d", &ch);

    return ch;
}

void create_account()
{
    system("cls");
    FILE *fp1;

    fflush(stdin);

    printf("\n**********CREATE ACCOUNT**********\n");
    printf("\nEnter First Name: ");
    gets(u.first_name);
    printf("\nEnter Last Name: ");
    gets(u.last_name);
    printf("\nEnter Username: ");
    gets(u.user_name);
    printf("\nEnter Password: ");
    gets(u.pass);

    fp1 = fopen("Username.txt", "wb+");
    fwrite(&u, sizeof(struct User), 1, fp1);
    fclose(fp1);
    
    printf("\nWait Just A Moment\n");
    sleep(1);
    system("cls");
    
    printf("\nAccount Created Successfully\n\n");
    system("pause");
}

void login()
{
    char u_name[50], u_pass[50];

    FILE *fp1;

    system("cls");
    fflush(stdin);

    printf("\n**********LOGIN TO YOUR ACCOUNT**********\n");
    printf("\nEnter Username: ");
    gets(u_name);
    printf("\nEnter Password: ");
    gets(u_pass);
    fp1 = fopen("Username.txt", "r");

    while(fread(&u, sizeof(struct User), 1, fp1))
    {
        if(strcmp(u_name, u.user_name) == 0 && strcmp(u_pass, u.pass) == 0)
        {
            printf("\nLogin Successful.\n");
            printf("\nWelcome %s %s\n\n", u.first_name, u.last_name);
            system("pause");
        }
        else
        {
            printf("\nInvalid Username/Password\n\n");
            system("pause");
        }
    }
    fclose(fp1);
}
