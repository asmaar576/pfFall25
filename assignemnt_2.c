// Q1

#include <stdio.h>
#include <string.h>

void Add_new_book(int isbns[], char titles[][50], float prices[], int i, int quantities[]) {
    int z, isbncheck = 0;
    int addisbn;
    printf("ENTER THE ISBN OF THE BOOK : ");
    scanf("%d", &addisbn);

    for (z = 0; z < i; z++) {
        if (isbns[z] == addisbn) {
            isbncheck = 1;
            break;
        }
    }

    if (isbncheck == 1) {
        printf("ERROR: BOOK WITH SAME ISBN ALREADY EXISTS!\n");
        return;
    }

    isbns[i] = addisbn;

    printf("ENTER THE TITLE OF THE BOOK : ");
    getchar();
    fgets(titles[i], 50, stdin);
    titles[i][strcspn(titles[i], "\n")] = '\0';

    printf("ENTER THE PRICE OF THE BOOK : ");
    scanf("%f", &prices[i]);

    printf("ENTER THE QUANTITY : ");
    scanf("%d", &quantities[i]);
}

void process_a_sale(int isbns[], int i, int quantities[]) {
    int z, isbn, sold, found = -1;
    printf("ENTER THE ISBN NUMBER : ");
    scanf("%d", &isbn);

    printf("ENTER THE NUMBER OF COPIES SOLD : ");
    scanf("%d", &sold);

    for (z = 0; z < i; z++) {
        if (isbns[z] == isbn) {
            found = z;
            break;
        }
    }

    if (found == -1) {
        printf("ERROR: BOOK NOT FOUND!\n");
    } else {
        if (quantities[found] >= sold) {
            quantities[found] -= sold;
            printf("SALE PROCESSED SUCCESSFULLY! REMAINING STOCK: %d\n", quantities[found]);
        } else {
            printf("ERROR: NOT ENOUGH STOCK AVAILABLE!\n");
        }
    }
}

void generate_low_Stock_report(int isbns[], char titles[][50], float prices[], int i, int quantities[]) {
    int z, found = 0;
    printf("\n--- LOW STOCK REPORT (LESS THAN 5) ---\n");
    for (z = 0; z < i; z++) {
        if (quantities[z] < 5) {
            printf("ISBN : %d , TITLE : %s , PRICE : %.2f , QUANTITY : %d\n",
                   isbns[z], titles[z], prices[z], quantities[z]);
            found = 1;
        }
    }
    if (!found) {
        printf("ALL BOOKS HAVE SUFFICIENT STOCK.\n");
    }
}

int main() {
    int isbns[100], flag = 0, menu, i = 0;
    char titles[100][50];
    float prices[100];
    int quantities[100];

    while (flag == 0) {
        printf("\nENTER 1 TO ADD A NEW BOOK:\n");
        printf("ENTER 2 TO PROCESS A SALE:\n");
        printf("ENTER 3 TO GENERATE LOW-STOCK REPORT:\n");
        printf("ENTER 0 TO EXIT:\n");
        scanf("%d", &menu);

        switch (menu) {
        case 1:
            Add_new_book(isbns, titles, prices, i, quantities);
            i++;
            break;

        case 2:
            process_a_sale(isbns, i, quantities);
            break;

        case 3:
            generate_low_Stock_report(isbns, titles, prices, i, quantities);
            break;

        case 0:
            flag = 1;
            printf("EXITING PROGRAM...\n");
            break;

        default:
            printf("INVALID CHOICE ENTERED.\n");
            break;
        }
    }
    return 0;
}










//Q2
#include <stdio.h>
#include <string.h>

int price = 0, proceed = 0, cnic;

void customer_information(char name[50]) {
    printf("ENTER YOUR NAME : ");
    getchar();  
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("ENTER YOUR CNIC NUMBER : ");
    scanf("%d", &cnic);
}

void Display_inventory(int product_code[], int quantity_in_stock[], int price_per_product[], int nproducts) {
    int i;
    printf("\nTHE LIST OF THE PRODUCTS INFORMATION ARE AS FOLLOWS\n");
    printf("\nPRODUCT CODE\t|QUANTITY IN STOCK\t|PRICE PER PRODUCT\n");

    for (i = 0; i < nproducts; i++) {
        printf("%d\t\t|%d\t\t\t|%d\n", product_code[i], quantity_in_stock[i], price_per_product[i]);
    }
}

int Update_inventory(int quantity_in_stock[]) {
    int purchase, flag = 1;

    while (flag == 1) {
        printf("\nENTER THE PRODUCT CODE YOU PURCHASED\nENTER 0 IF YOU WANT TO EXIT TO MAIN MENU\n");
        scanf("%d", &purchase);

        if (purchase == 0) {
            flag = 0;
            break;
        } 
        else if (purchase == 1) {
            quantity_in_stock[0] -= 1;
            price += 100;
            printf("\nITEM ADDED TO CART SUCCESSFULLY!!\n");
        } 
        else if (purchase == 2) {
            quantity_in_stock[1] -= 1;
            price += 200;
            printf("\nITEM ADDED TO CART SUCCESSFULLY!!\n");
        } 
        else if (purchase == 3) {
            quantity_in_stock[2] -= 1;
            price += 300;
            printf("\nITEM ADDED TO CART SUCCESSFULLY!!\n");
        } 
        else if (purchase == 4) {
            quantity_in_stock[3] -= 1;
            price += 150;
            printf("\nITEM ADDED TO CART SUCCESSFULLY!!\n");
        } 
        else {
            printf("INVALID!! ---- WRONG PRODUCT CODE ENTERED ----\n");
        }
    }

    proceed = 1;
    return price;
}

void Add_item_to_cart(int product_code[], int quantity_in_stock[], int price_per_product[]) {
    int i = 4, choice, flag = 1;
    while (flag == 1) {
        printf("PRESS 1 TO CONTINUE TO ADD NEW PRODUCT OR ANY OTHER KEY TO RETURN TO MAIN MENU: ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("ENTER THE CODE FOR THE NEW PRODUCT : ");
            scanf("%d", &product_code[i]);
            printf("ENTER THE QUANTITY OF THE NEW PRODUCT : ");
            scanf("%d", &quantity_in_stock[i]);
            printf("ENTER THE PRICE OF THE NEW PRODUCT : ");
            scanf("%d", &price_per_product[i]);
            i++;
            printf("\nPRODUCT ADDED SUCCESSFULLY!\n");
        } 
        else {
            flag = 0;
        }
    }
}

int Display_total_bill() {
    char voucher[20];
    float discount = 0.0;

    printf("\nYOUR TOTAL BILL IS : %d", price);
    printf("\nYou are lucky! We are offering a promocode of Eid2025");
    printf("\nEnter the promocode if you have the voucher: ");
    getchar();  
    fgets(voucher, 20, stdin);
    voucher[strcspn(voucher, "\n")] = '\0';

    if (strcmp("Eid2025", voucher) == 0) {
        discount = price * 0.75; 
        printf("\nPROMOCODE APPLIED SUCCESSFULLY! 25%% DISCOUNT!\n");
    } 
    else {
        printf("\nSORRY, this promocode isn't available\n");
        printf("Please proceed to billing without discount.\n");
        discount = price; 
    }

    return (int)discount;
}

void Show_invoice(int billings, char name[]) {
    printf("\n\n---- BILL ----\n");
    printf("NAME : %s\n", name);
    printf("CNIC : %d\n", cnic);
    printf("Your TOTAL amount is : %d\n", price);
    printf("After discount : %d\n", billings);
}

int main() {
    int product_code[100] = {1, 2, 3, 4};
    int price_per_product[100] = {100, 200, 300, 150};
    int quantity_in_stock[100] = {50, 10, 20, 8};
    int menu, billings = 0, choice;
    char name[50];

    do {
        printf("\n----- MAIN MENU -----\n");
        printf("1. Customer information\n");
        printf("2. Display inventory\n");
        printf("3. Update inventory\n");
        printf("4. Add item to cart\n");
        printf("0. Exit system\n");
        printf("Enter your choice: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                customer_information(name);
                break;
            case 2:
                Display_inventory(product_code, quantity_in_stock, price_per_product, 4);
                break;
            case 3:
                Update_inventory(quantity_in_stock);
                break;
            case 4:
                Add_item_to_cart(product_code, quantity_in_stock, price_per_product);
                break;
            case 0:
                printf("\nExiting system...\n");
                break;
            default:
                printf("\nERROR!! NOT A VALID INPUT\n");
                break;
        }
    } while (menu != 0);

    if (proceed == 1) {
        printf("\nWOULD YOU LIKE TO PROCEED TO CHECKOUT?\n");
        printf("Enter 1 to continue OR any other key to cancel: ");
        scanf("%d", &choice);

        if (choice == 1) {
            billings = Display_total_bill();
            Show_invoice(billings, name);
        }
    }

    return 0;
}






//Q3

#include<stdio.h>
#include<string.h>

#define ROWS 3
#define COLS 4

#define POWER 0
#define OVERLOAD 1
#define MAINT 2


int mask(int bit){
    return 1 << bit;
}

void setFlag(int grid[ROWS][COLS], int row, int col, int bit){
    grid[row][col] = grid[row][col] | mask(bit);
}

void clearFlag(int grid[ROWS][COLS], int row, int col, int bit){
    grid[row][col] = grid[row][col] & (~mask(bit));
}

void toggleFlag(int grid[ROWS][COLS], int row, int col, int bit){
    grid[row][col] = grid[row][col] ^ mask(bit);
}

int isFlagSet(int grid[ROWS][COLS], int row, int col, int bit){
    if (grid[row][col] & mask(bit)){
        return 1;
    }
    else{
        return 0;
    }
}

void showSector(int grid[ROWS][COLS], int row, int col){
    printf("\nSTATUS OF SECTOR (%d,%d):\n", row, col);
    printf("POWER STATUS : %s\n", isFlagSet(grid, row, col, POWER) ? "ON" : "OFF");
    printf("OVERLOAD WARNING : %s\n", isFlagSet(grid, row, col, OVERLOAD) ? "YES" : "NO");
    printf("MAINTENANCE REQUIRED : %s\n", isFlagSet(grid, row, col, MAINT) ? "YES" : "NO");
    printf("RAW VALUE : %d\n", grid[row][col]);
    
    printf("BINARY VALUE : ");
    for (int i = 7; i >= 0; i--){
        if (grid[row][col] & (1 << i)){
            printf("1");
        }
        else{
            printf("0");
        }
    }
    printf("\n");
}

void runDiagnostic(int grid[ROWS][COLS]){
    int overloadCount = 0;
    int maintenanceCount = 0;

    for (int i = 0; i < ROWS; i++){
        for (int j = 0; j < COLS; j++){
            if (isFlagSet(grid, i, j, OVERLOAD)){
                overloadCount++;
            }
            if (isFlagSet(grid, i, j, MAINT)){
                maintenanceCount++;
            }
        }
    }

    printf("\nSYSTEM DIAGNOSTIC REPORT:\n");
    printf("TOTAL SECTORS : %d\n", ROWS * COLS);
    printf("OVERLOADED SECTORS : %d\n", overloadCount);
    printf("SECTORS NEEDING MAINTENANCE : %d\n", maintenanceCount);
}

int main(){
    int grid[ROWS][COLS];
    int menu = 1;
    int row, col, bit, action;

    memset(grid, 0, sizeof(grid)); 

    setFlag(grid, 0, 0, POWER);
    setFlag(grid, 0, 0, OVERLOAD);
    setFlag(grid, 1, 2, MAINT);

    printf("=== IESCO GRID SIMULATION SYSTEM ===\n");

    while (menu != 0){
        printf("\n1. UPDATE SECTOR STATUS (SET / CLEAR / TOGGLE)\n");
        printf("2. QUERY SECTOR STATUS\n");
        printf("3. RUN SYSTEM DIAGNOSTIC\n");
        printf("0. EXIT PROGRAM\n");
        printf("ENTER YOUR CHOICE : ");
        scanf(" %d", &menu);

        if (menu == 1){
            printf("ENTER ROW (0-%d) : ", ROWS - 1);
            scanf(" %d", &row);
            printf("ENTER COLUMN (0-%d) : ", COLS - 1);
            scanf(" %d", &col);

            if (row < 0 || row >= ROWS || col < 0 || col >= COLS){
                printf("INVALID COORDINATES!\n");
                continue;
            }

            printf("0. POWER STATUS (1=ON , 0=OFF)\n");
            printf("1. OVERLOAD WARNING (1=YES , 0=NO)\n");
            printf("2. MAINTENANCE REQUIRED (1=YES , 0=NO)\n");
            printf("ENTER BIT INDEX (0-2) : ");
            scanf(" %d", &bit);

            if (bit < 0 || bit > 2){
                printf("INVALID BIT INDEX!\n");
                continue;
            }

            printf("1. SET FLAG\n");
            printf("2. CLEAR FLAG\n");
            printf("3. TOGGLE FLAG\n");
            printf("ENTER YOUR CHOICE : ");
            scanf(" %d", &action);

            if (action == 1){
                setFlag(grid, row, col, bit);
            }
            else if (action == 2){
                clearFlag(grid, row, col, bit);
            }
            else if (action == 3){
                toggleFlag(grid, row, col, bit);
            }
            else{
                printf("INVALID ACTION!\n");
                continue;
            }

            showSector(grid, row, col);
        }

        else if (menu == 2){
            printf("ENTER ROW (0-%d) : ", ROWS - 1);
            scanf(" %d", &row);
            printf("ENTER COLUMN (0-%d) : ", COLS - 1);
            scanf(" %d", &col);

            if (row < 0 || row >= ROWS || col < 0 || col >= COLS){
                printf("INVALID COORDINATES!\n");
                continue;
            }

            showSector(grid, row, col);
        }

        else if (menu == 3){
            runDiagnostic(grid);
        }

        else if (menu == 0){
            printf("EXITING PROGRAM... THANK YOU!\n");
        }

        else{
            printf("INVALID MENU OPTION! TRY AGAIN.\n");
        }
    }

    return 0;
}








//Q4

#include <stdio.h>

int count = -1;

void push(int arr[]) {
    if (count < 99) {
        count++;
        printf("ENTER A NUMBER IN A STACK : ");
        scanf("%d", &arr[count]);
    } else {
        printf("OVERFLOW!! LIMIT OF STACK EXCEEDED\n");
    }
}

void pop(int arr[]) {
    if (count >= 0) {
        count--;
        printf("ELEMENT POPPED SUCCESSFULLY!\n");
    } else {
        printf("UNDERFLOW!! No elements to pop.\n");
    }
}

void peek(int arr[]) {
    if (count >= 0)
        printf("THE TOP ELEMENT IN STACK IS : %d\n", arr[count]);
    else
        printf("STACK IS EMPTY!! NO ELEMENT TO PEEK.\n");
}

void display(int arr[]) {
    if (count == -1)
        printf("STACK IS EMPTY!\n");
    else {
        printf("THE ELEMENTS YOU ENTERED IN STACK ARE:\n");
        for (int i = 0; i <= count; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, flag = 1;
    int arr[100];

    while (flag == 1) {
        printf("\n\n--- STACK MENU ---\n");
        printf("1. Insert (Push)\n");
        printf("2. Remove (Pop)\n");
        printf("3. Display Top (Peek)\n");
        printf("4. Show All Elements\n");
        printf("0. Terminate the Program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(arr);
                break;
            case 2:
                pop(arr);
                break;
            case 3:
                peek(arr);
                break;
            case 4:
                display(arr);
                break;
            case 0:
                flag = 0;
                break;
            default:
                printf("INVALID! Please enter a valid choice\n");
        }
    }
    return 0;
}











//Q5
#include<stdio.h>
#include<string.h>

#define MAX 200


void reverseString(char str[]){
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++){
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

char toggleBits(char ch){
    ch = ch ^ (1 << 1);  
    ch = ch ^ (1 << 4); 
    return ch;
}

void encodeMessage(char msg[]){
    reverseString(msg); 

    for (int i = 0; msg[i] != '\0'; i++){
        msg[i] = toggleBits(msg[i]); 
    }

    printf("\nENCODED MESSAGE: %s\n", msg);
}

void decodeMessage(char msg[]){
    for (int i = 0; msg[i] != '\0'; i++){
        msg[i] = toggleBits(msg[i]);
    }

    reverseString(msg);

    printf("\nDECODED MESSAGE: %s\n", msg);
}


int main(){
    char msg[MAX];
    int menu = 1;

    printf("=== TCS MESSAGE ENCODING & DECODING SYSTEM ===\n");

    while (menu != 0){
        printf("\n1. ENCODE MESSAGE\n");
        printf("2. DECODE MESSAGE\n");
        printf("0. EXIT PROGRAM\n");
        printf("ENTER YOUR CHOICE : ");
        scanf(" %d", &menu);
        getchar();

        if (menu == 1){
            printf("ENTER THE MESSAGE TO ENCODE: ");
            fgets(msg, MAX, stdin);
            msg[strcspn(msg, "\n")] = '\0'; 
            encodeMessage(msg);
        }

        else if (menu == 2){
            printf("ENTER THE MESSAGE TO DECODE: ");
            fgets(msg, MAX, stdin);
            msg[strcspn(msg, "\n")] = '\0'; 
            decodeMessage(msg);
        }

        else if (menu == 0){
            printf("\nEXITING PROGRAM... THANK YOU!\n");
        }

        else{
            printf("\nINVALID INPUT! PLEASE ENTER 0, 1 OR 2 ONLY.\n");
        }
    }

    return 0;
}
