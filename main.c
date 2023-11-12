#include <stdio.h>
#include <stdbool.h>
#include <string.h>
struct User {
    char name[20];
    char password[20];
    char isActive[10];
};

void registerUser(const char* filename, const struct User* user) {
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    fprintf(file, "Name:%s, Password: %s , isActive: %s \n", user->name, user->password,user->isActive);
    fclose(file);
}


bool loginUser(const char* filename, const char* name, const char* password,const char* isActive) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return false;
    }

    char line[200];
    while (fgets(line, sizeof(line), file) != NULL) {
        char storedName[20];
        char storedPassword[20];
        char storedisActive[10];
        if (sscanf(line, "Name: %s, Password: %s , isActive: %s \n", storedName, storedPassword,storedisActive) == 3) {
            if (strcmp(storedName, name) == 0 && strcmp(storedPassword, password) == 0 && strcmp(storedisActive, isActive) == 0) {
                fclose(file);
                return true;
            }
        }
    }

    fclose(file);
    return false;
}


int main() {
    struct User user;
    char name[20];
    char password[20];
    char isActive[10];
    int number;
    printf("please enter 1 to register or 2 to login :\n");
    scanf("%d",&number);
    if(number == 1){
        printf("Registration\n");
        printf("Enter your name: ");
        scanf("%s", user.name);

        printf("Enter your password: ");
        scanf("%s", user.password);


        printf("\nare you an Active user ?");
        scanf("%s",user.isActive);

    // Register the user
        printf("registerd succefully");
        registerUser("users.text", &user);
    }else{
        char loginName[20];
        char loginPassword[20];
        char loginisActive[10];
        printf("\nLogin\n");
        printf("Enter your name: ");
        scanf("%s", loginName);

        printf("Enter your password: ");
        scanf("%s", loginPassword);

    // Check if user login is successful
        if (loginUser("users.text", loginName, loginPassword,loginisActive)) {
            if(loginisActive == "1")
            printf("Login successful!\n");
        }   else {
            printf("Invalid name or password. Login failed.\n");
        }
    }




    return 0;
}
