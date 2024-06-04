struct GenerateInventoryPosition{
    int ProductID;
    char DBProductName[300];
    long long DBProductPrice;
    int ProductQty;
};
void InventoryPositionFun(){
    struct GenerateInventoryPosition Product[100];
    FILE *InventoryPosition, *CreageInventoryPosition;
    int InvoiceID, i;
    char FileName[100] = "Report/Inventory-Position-", Line[400];
    srand(time(0));
    InvoiceID = rand() % 10000 + 1;
    sprintf(FileName, "%s%d.html", FileName, InvoiceID);
    InventoryPosition = fopen("Database/Inventory.csv", "r+");
    if (InventoryPosition != NULL)
    {
        CreateDirectory("Report", NULL);
        CreageInventoryPosition = fopen(FileName, "w");
        int StructLength = GetAllProduct(Product, 100);
        fprintf(CreageInventoryPosition,
                "<!DOCTYPE html>\n"
                "<html lang=\"en\">\n"
                "<head>\n"
                "    <meta charset=\"UTF-8\">\n"
                "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
                "    <title>Product List</title>\n"
                "    <style>\n"
                "        body {font-family: Arial, sans-serif; margin: 0; padding: 0; background-color: #f4f4f4;}\n"
                "        .container {width: 90%; margin: 20px auto; background: #fff; padding: 20px; box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);}\n"
                "        h1 {text-align: center; color: #333;}\n"
                "        table {width: %s; border-collapse: collapse; margin: 20px 0;}\n"
                "        table, th, td {border: 1px solid #ddd;}\n"
                "        th, td {padding: 20px; text-align: left;}\n"
                "        th {background-color: #f2f2f2;}\n"
                "        tr:nth-child(even) {background-color: #f9f9f9;}\n"
                "        tr:hover {background-color: #f1f1f1;}\n"
                "    </style>\n"
                "</head>\n"
                "<body>\n"
                "    <div class=\"container\">\n"
                "        <h1>Product List</h1>\n"
                "        <table>\n"
                "            <thead>\n"
                "                <tr>\n"
                "                    <th>Product ID</th>\n"
                "                    <th>Product Name</th>\n"
                "                    <th>Price</th>\n"
                "                    <th>Quantity</th>\n"
                "                </tr>\n"
                "            </thead>\n"
                "            <tbody>\n",
                "100%");

        for (i = 1; i < StructLength; i++){
                fprintf(CreageInventoryPosition,
                    "<tr>\n"
                    " <td>%d</td>\n"
                    " <td>%s</td>\n"
                    " <td>Rs. %lld.00</td>\n"
                    " <td>%d</td>\n"
                    "</tr>\n",Product[i].ProductID,Product[i].DBProductName,Product[i].DBProductPrice,Product[i].ProductQty);
            }


        fprintf(CreageInventoryPosition,
        "            </tbody>\n"
        "        </table>\n"
        "    </div>\n"
        "</body>\n"
        "</html>\n");

    fclose(CreageInventoryPosition);
    system("cls");
    printf("Inventory Report is Generated: %s",FileName);
    getch();
    }
    else{
        system("cls");
        printf("Inventory Not Found! Please Insert Inventory First!");
    }
}
