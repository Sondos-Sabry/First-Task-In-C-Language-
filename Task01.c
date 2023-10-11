#include <stdio.h>
#include <string.h>

struct User {
    char username[50];
    char password[50];
};

void RegisterUser(struct User users[], int *userCount) {
    if (*userCount < 10) {
        printf("Enter username: ");
        scanf("%s", users[*userCount].username);
        printf("Enter password: ");
        scanf("%s", users[*userCount].password);
        (*userCount)++;
        printf("Registration successful!\n");
    } else {
        printf("User limit reached. Registration not allowed.\n");
    }
}

int LoginUser(struct User users[], int userCount, char username[], char password[]) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            return i; // Return the index of the authenticated user
        }
    }
    return -1; // Return -1 if authentication fails
}

void clearScreen() {
     printf("\033[H\033[J");
}
int main() {
    struct User users[10]; 
    int userCount = 0;    
    int choice;
    
    do {
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                clearScreen();
                RegisterUser(users, &userCount);
                
                break;
            case 2:
                char username[50];
                char password[50];
                printf("Enter username: ");
                scanf("%s", username);
                printf("Enter password: ");
                scanf("%s", password);
                clearScreen();
                int index = LoginUser(users, userCount, username, password);
                if (index != -1) {
                    printf("Welcome, %s!\n", users[index].username);
                } else {
                    printf("Login failed. Invalid username or password.\n");
                }
                
                break;
            case 3:
                clearScreen();
                printf("Exiting...\n");
                break;
            default:
                clearScreen();
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}
