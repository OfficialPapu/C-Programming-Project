struct GenerateReport
{
    int ProductID;
    char DBProductName[300];
    long long DBProductPrice;
};
int GenerateReport()
{
    struct GenerateReport Product[100];
    FILE *SalesReport, *CreageSalesReport, *InventoryFilePointer;
    int RandNum, i, DBCustID, InventoryID, DBInventoryIDArray[100], *ptr = DBInventoryIDArray, ProductID, ProductPrice, ProductQty;
    char FileName[100] = "Report/Sales-Report-", Line[400], ProductName[400];
    srand(time(0));
    RandNum = rand() % 10000 + 1;
    sprintf(FileName, "%s%d.html", FileName, RandNum);
    SalesReport = fopen("Database/Invoice Receipt.csv", "r+");
    int count = 0;
    while (fgets(Line, sizeof(Line), SalesReport))
    {
        sscanf(Line, "%d, %d", &DBCustID, &InventoryID);
        *ptr = InventoryID;
        ptr++;
        count++;
    }
    fclose(SalesReport);
    if (count == 0)
    {
        system("cls");
        printf("You haven't sold anything today");
        getch();
        return 0;
    }
    ptr = DBInventoryIDArray;
    for (i = 0; i < count; i++)
    {
        DBInventoryIDArray[i] = *ptr;
        ptr++;
    }
    int ProductIndex = 0;
    for (i = 0; i < count; i++)
    {
        InventoryFilePointer = fopen("Database/Inventory.csv", "r");
        int LoopCount = 0;
        while (fgets(Line, sizeof(Line), InventoryFilePointer))
        {
            LoopCount++;
            sscanf(Line, "%d, %299[^,], %d, %d", &ProductID, ProductName, &ProductPrice, &ProductQty);
            if (ProductID == DBInventoryIDArray[i] && LoopCount != 1)
            {
                Product[ProductIndex].ProductID = ProductID;
                strcpy(Product[ProductIndex].DBProductName, ProductName);
                Product[ProductIndex].DBProductPrice = ProductPrice;
                ProductIndex++;
            }
        }
        fclose(InventoryFilePointer);
    }
    int TotalDue=0;
    for (i = 0; i < ProductIndex; i++){
       TotalDue += Product[i].DBProductPrice;
    }
    CreateDirectory("Report", NULL);
    CreageSalesReport = fopen(FileName, "w");
    fprintf(CreageSalesReport,
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
            "        .total-revenue {text-align: right; font-size: 1.5rem; font-weight: bold;}\n"
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
            "        <h1>Today's Sales Report</h1>\n"
            "        <table>\n"
            "            <thead>\n"
            "                <tr>\n"
            "                    <th>ID</th>\n"
            "                    <th>Product Name</th>\n"
            "                    <th>Price</th>\n"
            "                    <th>Quantity</th>\n"
            "                </tr>\n"
            "            </thead>\n"
            "            <tbody>\n",
            "100%");

    for (i = 0; i < ProductIndex; i++)
    {
        fprintf(CreageSalesReport,
                "<tr>\n"
                " <td>%d</td>\n"
                " <td>%s</td>\n"
                " <td>Rs. %lld.00</td>\n"
                " <td>1</td>\n"
                "</tr>\n",
                i+1, Product[i].DBProductName, Product[i].DBProductPrice);
    }

    fprintf(CreageSalesReport,
            "            </tbody>\n"
            "        </table>\n"
            "<div class='total-revenue'>"
            "Total Revenue: Rs. %d.00"
            " </div>"
            "    </div>\n"
            "</body>\n"
            "</html>\n",TotalDue);

    fclose(CreageSalesReport);
    system("cls");
    printf("Report is Generated: %s",FileName);
    getch();
    return 0;
}