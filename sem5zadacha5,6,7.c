#include <stdio.h>
#include <string.h>


void zadacha5(){
        char word[] = "concatenation";  
    int len = strlen(word);

    char guessed[50];
    for (int i = 0; i < len; i++) {
        guessed[i] = '_';
    }
    guessed[len] = '\0';

    int attempts = 0;
    int maxAttempts = len + 2;

    char letter;
    int completed = 0;

    while (!completed && attempts < maxAttempts) {
        printf("%s\n", guessed);
        printf("Enter letter: ");
        scanf(" %c", &letter);

        attempts++;

        for (int i = 0; i < len; i++) {
            if (word[i] == letter) {
                guessed[i] = letter;
            }
        }

        completed = 1;
        for (int i = 0; i < len; i++) {
            if (guessed[i] == '_') {
                completed = 0;
                break;
            }
        }
    }

    if (completed) {
        printf("You win! Word: %s\n", word);
        printf("Attempts: %d\n", attempts);
    } else {
        printf("You lose! Word was: %s\n", word);
    }

}

void zadacha6(){
char word1[50], word2[50];
scanf("%s %s", word1, word2);

if (strlen(word1) != strlen(word2)){
    printf("Not anagrams\n");
    return;

}
for (int i = 0; i < strlen(word1);i++){
    int found = 0;
    for(int j = 0; j< strlen(word2); j++){
        if (word1[i]==word2[j]){
            found = 1;
            word2[j] = '*';
            break;
        }
    }
    if(!found){
        printf("Not anagrams\n");
        return;
    }

}

printf("Anagrams\n");

}






//zadacha7
#define MAX_EMPLOYEES 30
#define FILENAME "employees.dat"

typedef struct {
    int id;
    float hourlyPay;
    int hoursWorked;
    float weeklySalary;
} Employee;

float calculateWeeklySalary(float hourlyPay, int hoursWorked) {
    float salary = 0.0;

    if (hoursWorked <= 40) {
        salary = hourlyPay * hoursWorked;
    } else {
        int overtime = hoursWorked - 40;
        salary = hourlyPay * 40 + overtime * hourlyPay * 1.5;
    }

    salary -= salary * 0.0365; 
    return salary;
}

int countEmployees() {
    FILE *fp = fopen(FILENAME, "rb");
    if (!fp) return 0;

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fclose(fp);

    return size / sizeof(Employee);
}

void addEmployee() {
    if (countEmployees() >= MAX_EMPLOYEES) {
        printf("Достигнат е максималният брой от 30 сътрудници.\n");
        return;
    }

    Employee e;

    printf("Въведете ID: ");
    scanf("%d", &e.id);

    printf("Почасово заплащане: ");
    scanf("%f", &e.hourlyPay);

    printf("Отработени часове: ");
    scanf("%d", &e.hoursWorked);

    e.weeklySalary = calculateWeeklySalary(e.hourlyPay, e.hoursWorked);

    FILE *fp = fopen(FILENAME, "ab");
    if (!fp) {
        printf("Грешка при отваряне на файла.\n");
        return;
    }

    fwrite(&e, sizeof(Employee), 1, fp);
    fclose(fp);

    printf("Записът е добавен успешно.\n");
}

void printSalaries() {
    FILE *fp = fopen(FILENAME, "rb");
    if (!fp) {
        printf("Файлът не съществува.\n");
        return;
    }

    Employee e;
    printf("\n--- Седмични заплати ---\n");

    while (fread(&e, sizeof(Employee), 1, fp)) {
        printf("ID: %d | Заплата: %.2f лв.\n", e.id, e.weeklySalary);
    }

    fclose(fp);
}

int main() {
    int choice;

    do {
        printf("\n=== М Е Н Ю ===\n");
        printf("1. Добавяне на сътрудник\n");
        printf("2. Извеждане на седмични заплати\n");
        printf("3. Изход\n");
        printf("Изберете опция: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: printSalaries(); break;
            case 3: printf("Изход...\n"); break;
            default: printf("Невалиден избор.\n");
        }

    } while (choice != 3);

    return 0;
}

