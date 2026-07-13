#include <stdio.h>
#include <stdlib.h>

struct Account
{
    int accNo;
    char name[50];
    float balance;
};

void createAccount()
{
    FILE *fp;
    struct Account a;

    fp = fopen("accounts.dat", "ab");

    printf("Enter Account Number: ");
    scanf("%d", &a.accNo);

    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]", a.name);

    printf("Enter Initial Balance: ");
    scanf("%f", &a.balance);

    fwrite(&a, sizeof(a), 1, fp);
    fclose(fp);

    printf("Account created successfully!\n");
}
void deposit()
{
    FILE *fp;
    struct Account a;
    int acc;
    float amount;
    int found = 0;

    fp = fopen("accounts.dat", "rb+");

    if (fp == NULL)
    {
        printf("No accounts found!\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &acc);

    while (fread(&a, sizeof(a), 1, fp))
    {
        if (a.accNo == acc)
        {
            printf("Enter Amount to Deposit: ");
            scanf("%f", &amount);

            a.balance += amount;

            fseek(fp, -sizeof(a), SEEK_CUR);
            fwrite(&a, sizeof(a), 1, fp);

            printf("Deposit Successful!\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Account not found!\n");

    fclose(fp);
}

void withdraw()
{
    FILE *fp;
    struct Account a;
    int acc;
    float amount;
    int found = 0;

    fp = fopen("accounts.dat", "rb+");

    if (fp == NULL)
    {
        printf("No accounts found!\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &acc);

    while (fread(&a, sizeof(a), 1, fp))
    {
        if (a.accNo == acc)
        {
            printf("Enter Amount to Withdraw: ");
            scanf("%f", &amount);

            if (amount > a.balance)
            {
                printf("Insufficient Balance!\n");
            }
            else
            {
                a.balance -= amount;

                fseek(fp, -sizeof(a), SEEK_CUR);
                fwrite(&a, sizeof(a), 1, fp);

                printf("Withdrawal Successful!\n");
            }

            found = 1;
            break;
        }
    }

    if (!found)
        printf("Account not found!\n");

    fclose(fp);
}
void checkBalance()
{
    FILE *fp;
    struct Account a;
    int acc;
    int found = 0;

    fp = fopen("accounts.dat", "rb");

    if (fp == NULL)
    {
        printf("No accounts found!\n");
        return;
    }

    printf("Enter Account Number: ");
    scanf("%d", &acc);

    while (fread(&a, sizeof(a), 1, fp))
    {
        if (a.accNo == acc)
        {
            printf("\nAccount Number : %d\n", a.accNo);
            printf("Account Holder : %s\n", a.name);
            printf("Balance : %.2f\n", a.balance);

            found = 1;
            break;
        }
    }

    if (!found)
        printf("Account not found!\n");

    fclose(fp);
}
void displayAccounts()
{
    FILE *fp;
    struct Account a;

    fp = fopen("accounts.dat", "rb");

    if (fp == NULL)
    {
        printf("No accounts found!\n");
        return;
    }

    printf("\nAcc No\tName\t\tBalance\n");
    printf("-------------------------------------\n");

    while (fread(&a, sizeof(a), 1, fp))
    {
        printf("%d\t%s\t\t%.2f\n",
               a.accNo, a.name, a.balance);
    }

    fclose(fp);
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n===== BANKING SYSTEM =====\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createAccount();
            break;
        case 2:
            deposit();
            break;
        case 3:
            withdraw();
            break;
        case 4:
            checkBalance();
            break;
        case 5:
            displayAccounts();
            break;
        case 6:
            printf("Thank you for using Banking System!\n");
            exit(0);
        default:
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}
