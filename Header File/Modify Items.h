int ModifyItems() {
    int SearchID, ID, Qty, Price, found = 0;
    char ProductName[300];
    char line[512];
    FILE *FileExistData, *SearchFilePointer, *TempFilePointer;

    system("cls");
    FileExistData = fopen("Database/Inventory.csv", "r");
    if (FileExistData == NULL) {
        system("cls");    
        printf("Something went wrong!\nFile Not Found!");
        getch();
        return 1;
    }

    printf("Search Inventory by ID: ");
    scanf("%d", &SearchID);

    TempFilePointer = fopen("Database/TempInventory.csv", "w");

    while (fgets(line, sizeof(line), FileExistData)) {
        sscanf(line, "%d,%299[^,],%d,%d", &ID, ProductName, &Qty, &Price);
        if (ID == SearchID) {
            found = 1;
            printf("Product found: %d, %s, %d, %d\n", ID, ProductName, Qty, Price);
            printf("Enter new Quantity: ");
            scanf("%d", &Qty);
            printf("Enter new Price: ");
            scanf("%d", &Price);

            fprintf(TempFilePointer, "%d,%s,%d,%d\n", ID, ProductName, Qty, Price);
        } else {
            fprintf(TempFilePointer, "%s", line);
        }
    }

    fclose(FileExistData);
    fclose(TempFilePointer);

    if (found) {
        remove("Database/Inventory.csv");
        rename("Database/TempInventory.csv", "Database/Inventory.csv");
        printf("Inventory updated successfully.\n");
    } else {
        remove("Database/TempInventory.csv");
        printf("ID %d not Found in Inventory.\n", SearchID);
    }

    getch();
    return 0;
}