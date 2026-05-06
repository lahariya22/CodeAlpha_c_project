#include <stdio.h>
#include <stdlib.h>

struct account {
    int accNo;
    char name[50];
    float balance;
};

void create() {
    FILE *fp = fopen("bank.dat", "ab");
    struct account a;

    printf("Enter Account No, Name, Balance: ");
    scanf("%d %s %f", &a.accNo, a.name, &a.balance);

    fwrite(&a, sizeof(a), 1, fp);
    fclose(fp);
}

void display() {
    FILE *fp = fopen("bank.dat", "rb");
    struct account a;

    while(fread(&a, sizeof(a), 1, fp)) {
        printf("%d %s %.2f\n", a.accNo, a.name, a.balance);
    }
    fclose(fp);
}

void deposit() {
    FILE *fp = fopen("bank.dat", "rb+");
    struct account a;
    int acc;
    float amt;

    printf("Enter Account No: ");
    scanf("%d", &acc);

    while(fread(&a, sizeof(a), 1, fp)) {
        if(a.accNo == acc) {
            printf("Enter amount: ");
            scanf("%f", &amt);
            a.balance += amt;

            fseek(fp, -sizeof(a), SEEK_CUR);
            fwrite(&a, sizeof(a), 1, fp);
            break;
        }
    }
    fclose(fp);
}

void withdraw() {
    FILE *fp = fopen("bank.dat", "rb+");
    struct account a;
    int acc;
    float amt;

    printf("Enter Account No: ");
    scanf("%d", &acc);

    while(fread(&a, sizeof(a), 1, fp)) {
        if(a.accNo == acc) {
            printf("Enter amount: ");
            scanf("%f", &amt);

            if(a.balance >= amt)
                a.balance -= amt;
            else
                printf("Insufficient balance!\n");

            fseek(fp, -sizeof(a), SEEK_CUR);
            fwrite(&a, sizeof(a), 1, fp);
            break;
        }
    }
    fclose(fp);
}

int main() {
    int ch;

    while(1) {
        printf("\n1.Create 2.Display 3.Deposit 4.Withdraw 5.Exit\n");
        scanf("%d", &ch);

        switch(ch) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: deposit(); break;
            case 4: withdraw(); break;
            case 5: exit(0);
        }
    }
}