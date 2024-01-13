#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>

void customerDashboard(char customer[]);
void shopkeeperDashboard(char username[]);
void byItemName(char customer[]);
int signup();
int login();
void addItem(char username[]);
void generateReport(char username[]);

struct User {
    char username[50];
    char password[50];
    char phn_no[15];
    char city[50];
}; 

struct Item {
    char username[50];
    char name[50];
    char price[15];
    char quantity[5];
    char description[50];
    char company[50];
}; 

struct transaction {
    char username[50];
    char customer[50];
    char name[50];
    char price[15];
    char quantity[5];
    char description[50];
    char company[50];
};

void customerDashboard(char customer[])
{
    int choice;
    printf("Choose one from following options: \n");
    printf("1) by name of item\n");
    printf("2) by shop username\n");
    printf("3) exit the application");
    scanf("%d", &choice);
    if(choice == 1)
    {
        byItemName(customer);
    }
    else if(choice == 2)
    {
        byShopName(customer);
    }
    else if(choice == 3)
    {
        exit(0);
    }
    else
    {
        printf("Enter a valid option");
    }

    return 0;
}

void shopkeeperDashboard(char username[])
{
        int choice;
        printf("1) Enter 1 to add item");
        printf("1) Enter 2 to generate report");
        scanf("%d", &choice);
        if(choice == 1)
        {
            addItem(username);
        }
        else if(choice == 2)
        {
            generateReport(username);
        }
        else
        {
            printf("Enter valid input");
        }
        return 0;
}

void byItemName(char customer[])
{
    char itemName[50];
    printf("Enter the name of the item to search: ");
    scanf("%s", &itemName);
    
    
    FILE *file = fopen("items.txt", "r");
    if (file == NULL) 
    {
        printf("Error opening file for writing!\n");
        exit(0); // Return an error code
    }
        struct Item tempItem;
        while (fscanf(file, "%s    %s    %s    %s    %s    %s\n", tempItem.username, tempItem.name, tempItem.company, tempItem.price, tempItem.quantity, tempItem.description) != EOF) {
        if (strcmp(itemName, tempItem.name) == 0) 
        {
        printf(file, "%s    %s    %s    %s    %s    %s\n", tempItem.username, tempItem.name, tempItem.company, tempItem.price, tempItem.quantity, tempItem.description);
        }
    }
    // Close the file
    fclose(file);

    
    return 0;
}

int signup()
{
    printf("Enter the following choice: \n");
    printf("1) customer \n");
    printf("2) shop keeper \n");

    int choice = 1;
    scanf("%d", &choice);
    if(choice == 1)
    {
        char username[15];
        char password[15];
        char phn_no[15];
        printf("Enter the following details: \n");
        printf("username: ");
        scanf("%s", username);
        printf("password:");
        scanf("%s", password);
        printf("phone number:");
        scanf("%s", phn_no);
        
        FILE *file = fopen("customers.txt", "w");
        if (file == NULL) 
        {
        printf("Error opening file for writing!\n");
        return 1;
        }
        struct User tempUser;
         while (fscanf(file, "%s    %s    %s", tempUser.username, tempUser.password, tempUser.phn_no) != EOF) {
        if (strcmp(username, tempUser.username) == 0) {
            printf("username already exixts!");
            fclose(file);
            return 0;
        }
    }

        fprintf(file, "%s   %s  %s\n", username, password, phn_no);

        fclose(file);
    }
    else if(choice = 2)
    {
        char username[15];
        char password[15];
        char phn_no[15];
        char city[15];
        printf("Enter the following details: \n");
        printf("username: ");
        scanf("%s", username);
        printf("password:");
        scanf("%s", password);
        printf("phone number:");
        scanf("%s", phn_no);
        printf("city:");
        scanf("%s", city);

        FILE *file = fopen("shops.txt", "w");
        if (file == NULL) 
        {
        printf("Error opening file for writing!\n");
        return 1; // Return an error code
        }
        struct User tempUser;
         while (fscanf(file, "%s    %s    %s    %s\n", tempUser.username, tempUser.password, tempUser.phn_no, tempUser.city) != EOF) {
        if (strcmp(username, tempUser.username) == 0) {
            printf("username already exixts!");
            fclose(file);
            return 0;
        }
    }

        fprintf(file, "%s   %s  %s  %s\n", username, password, phn_no, city);

        // Close the file
        fclose(file);
    }
    else
    {
        printf("Enter a valid input.");
    }
}

int login() {
    char enteredUsername[15];
    char enteredPassword[15];
    int choice;

    printf("Enter 1 for customer and 2 for shopkeeper: ");
    scanf("%d", &choice);
    printf("Enter username: ");
    scanf("%s", enteredUsername);
    printf("Enter password: ");
    scanf("%s", enteredPassword);

    char file_name[20];
    FILE *file;
    struct User tempUser;

    if(choice == 1)
    {
        FILE *file = fopen("customers.txt", "r");
        while (fscanf(file, "%s    %s    %s", tempUser.username, tempUser.password, tempUser.phn_no) != EOF) {
        if (strcmp(enteredUsername, tempUser.username) == 0 && strcmp(enteredPassword, tempUser.password) == 0) {
            printf("Login successful!\n");
            customerDashboard(enteredUsername);
            fclose(file);
            return 1;
        }
    }
    }
    else
    {
        FILE *file = fopen("shops.txt", "r");
        while (fscanf(file, "%s    %s    %s    %s", tempUser.username, tempUser.password, tempUser.phn_no, tempUser.city) != EOF) {
        if (strcmp(enteredUsername, tempUser.username) == 0 && strcmp(enteredPassword, tempUser.password) == 0) {
            printf("Login successful!\n");
            shopkeeperDashboard(enteredUsername);
            fclose(file);
            return 1;
        }
    }
    }

    

    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }
    printf("Invalid username or password. Login failed.\n");
    fclose(file);
    return 0;
}


void addItem(char username[])
{
    char name[50];
    char company[50];
    char price[50];
    char description[50];
    char quantity[5];
    printf("Enter product details: ");
    printf("Name: ");
    scanf("%s", &name);
    printf("company: ");
    scanf("%s", &company);
    printf("price: ");
    scanf("%s", &price);
    printf("quantity: ");
    scanf("%s", &quantity);
    printf("description: ");
    scanf("%s", &description);

    FILE *file = fopen("items.txt", "w");
    if (file == NULL) 
    {
        printf("Error opening file for writing!\n");
        return 1; // Return an error code
    }
        struct Item tempItem;
         while (fscanf(file, "%s    %s    %s    %s    %s    %s\n", tempItem.username, tempItem.name, tempItem.company, tempItem.price, tempItem.quantity, tempItem.description) != EOF) {
        if (strcmp(username, tempItem.username) == 0) 
        {
            printf("product already exixts!");
            fclose(file);
            return 0;
        }
    }

    fprintf(file, "%s    %s    %s    %s    %s    %s\n", tempItem.username, tempItem.name, tempItem.company, tempItem.price, tempItem.quantity, tempItem.description);
    // Close the file
    fclose(file);
}
void generateReport(char username[])
{
    int total;
    FILE *file = fopen("transactions.txt", "r");
    if (file == NULL) 
    {
        printf("Error opening file for writing!\n");
        return 1; // Return an error code
    }
        struct transaction tempItem;
        while (fscanf(file, "%s    %s    %s    %s    %s    %s\n", tempItem.username, tempItem.customer, tempItem.name, tempItem.company, tempItem.price, tempItem.quantity, tempItem.description) != EOF) {
        if (strcmp(username, tempItem.username) == 0) 
        {
            printf("%s    %s    %s    %s    %s\n",tempItem.customer, tempItem.name, tempItem.company, tempItem.price, tempItem.quantity,tempItem.description);
            total =+ atoi(tempItem.price);
        }
        printf("Total amount of items sold by you is: %d", total);
        fclose(file);
        return 0;
    }

    // Close the file
    fclose(file);
    return 0;
}


int main(void)
{
    int input_option = 0;
    while(1)
    {
        printf("Welcome to the e-commerce shopping portal!\n");
        printf("1) login\n");
        printf("2) sign up\n");
        printf("3) exit\n");
        printf("Please enter the choice: \n");
        scanf("%d",&input_option);
        switch (input_option)
        {
        case 1:
            login();
            break;
        
        case 2:
            signup();
            break;

        case 3:
            break;

        default:
            break;
        }
    }
    return 0;
}