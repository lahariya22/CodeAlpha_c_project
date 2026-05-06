#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int id;
    char name[50];
    float marks;
};

void add() {
    FILE *fp = fopen("students.dat", "ab");
    struct student s;

    printf("Enter ID, Name, Marks: ");
    scanf("%d %s %f", &s.id, s.name, &s.marks);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
}

void display() {
    FILE *fp = fopen("students.dat", "rb");
    struct student s;

    while(fread(&s, sizeof(s), 1, fp)) {
        printf("%d %s %.2f\n", s.id, s.name, s.marks);
    }
    fclose(fp);
}

void search() {
    FILE *fp = fopen("students.dat", "rb");
    struct student s;
    int id, found=0;

    printf("Enter ID to search: ");
    scanf("%d", &id);

    while(fread(&s, sizeof(s), 1, fp)) {
        if(s.id == id) {
            printf("Found: %d %s %.2f\n", s.id, s.name, s.marks);
            found = 1;
        }
    }
    if(!found) printf("Record not found!\n");
    fclose(fp);
}

int main() {
    int ch;

    while(1) {
        printf("\n1.Add 2.Display 3.Search 4.Exit\n");
        scanf("%d", &ch);

        switch(ch) {
            case 1: add(); break;
            case 2: display(); break;
            case 3: search(); break;
            case 4: exit(0);
        }
    }
}