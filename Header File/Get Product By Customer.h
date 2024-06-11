int GetProductByCustomer(int CustomerID, struct ProductStruct *Product, int maxProducts) {
    char Line[400], Line2[400], ProductName[300];
    int DBCustID, InventoryID, ProductPrice, ProductQty;
    int DBInventoryIDArray[100], ProductID,i;
    int *ptr = DBInventoryIDArray;
    FILE *InvoiceFilePointer, *InventoryFilePointer, *TempFilePointer;

    InvoiceFilePointer = fopen("Database/Invoice Receipt.csv", "r");
    if (InvoiceFilePointer == NULL) {
        system("cls");
        perror("Failed to open the file");
        getch();
        return -1;
    }

    int count = 0;
    while (fgets(Line, sizeof(Line), InvoiceFilePointer)) {
        sscanf(Line, "%d, %d", &DBCustID, &InventoryID);
        if (DBCustID == CustomerID) {
            *ptr = InventoryID;
            ptr++;
            count++;
        }
    }
    fclose(InvoiceFilePointer);

    if (count == 0) {
        system("cls");
        printf("Product Not Found Please Enter a Valid ID");
        getch();
        return -1;
    }
    ptr = DBInventoryIDArray;
    for (i = 0; i < count; i++) {
        DBInventoryIDArray[i]=*ptr;
        ptr++;
    }
        int ProductIndex = 0;
        int Errorcount=0;
        
    for ( i = 0; i < count; i++) {
        int ProductFound = 0; 
        InventoryFilePointer=fopen("Database/Inventory.csv","r+");
        TempFilePointer = fopen("Database/TempInventory.csv", "w");
        int LoopCount=0;
        while (fgets(Line2, sizeof(Line2), InventoryFilePointer)){
            LoopCount++;
           sscanf(Line2,"%d, %299[^,], %d, %d",&ProductID,ProductName,&ProductPrice, &ProductQty);
           if(ProductID == DBInventoryIDArray[i] && LoopCount !=1){
            Product[ProductIndex].ProductID=ProductID;
            strcpy(Product[ProductIndex].DBProductName, ProductName);
            Product[ProductIndex].DBProductPrice=ProductPrice;
            Product[ProductIndex].ProductQty = ProductQty;
            ProductQty--;
            fprintf(TempFilePointer, "%d, %s, %d, %d\n", ProductID, ProductName, ProductPrice,ProductQty);
            ProductIndex++;
            ProductFound = 1; 
        }else{
            fprintf(TempFilePointer, "%s",Line2);
        }
        }   
        fclose(InventoryFilePointer);
        fclose(TempFilePointer);
        remove("Database/Inventory.csv");
        rename("Database/TempInventory.csv", "Database/Inventory.csv");
    if (!ProductFound) {
        printf("\nProduct with Inventory ID %d not found. Please enter a valid Inventory ID", DBInventoryIDArray[i]);
        getch();
    }
    }
    return ProductIndex;
}