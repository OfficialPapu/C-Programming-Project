int GetAllProduct(struct ProductStruct *Product, int maxProducts){
    char Line[400], Line2[400], ProductName[200];
    int InventoryID, ProductPrice, ProductQty;
    int DBInventoryIDArray[100], ProductID, i, ProductIndex = 0, count = 0;
    FILE *InventoryFilePointer;
    InventoryFilePointer = fopen("Database/Inventory.csv", "r+");
    while (fgets(Line, sizeof(Line), InventoryFilePointer)){
        sscanf(Line, "%d, %299[^,], %d, %d", &ProductID, ProductName, &ProductPrice, &ProductQty);
        Product[ProductIndex].ProductID = ProductID;
        strcpy(Product[ProductIndex].DBProductName, ProductName);
        Product[ProductIndex].DBProductPrice = ProductPrice;
        Product[ProductIndex].ProductQty = ProductQty;
        ProductIndex++;
    }
    return ProductIndex;
}