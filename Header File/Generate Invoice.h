struct ProductStruct {
    int ProductID;
    char DBProductName[300];
    long long DBProductPrice;
    int ProductQty;
};
int GenerateInvoice(){
    struct ProductStruct Product[100];
    long long Mobile, CustMobile;
    int ID[100],ProductID ,Counter = 0, InvoiceID, LoopCount,i, CustomerID, CustID;
    char Invoice[50]="Invoice/Invoice-", InvoiceName[100],line[400], ProductName[300],CompanyName[300], Address[100], Line2[300], Line3[300], CustName[200], CustAddress[300];
    srand(time(0));
    InvoiceID = rand()%10000 + 1;
    sprintf(InvoiceName, "%s%d.html", Invoice, InvoiceID);
    FILE *InventoryFilePointer, *InvoiceFilePointer, *InvoiceNameFilePointer, *ExistInvoiceFilePointer, *CompanyFilePointer, *CustomerFilePointer;
    InventoryFilePointer=fopen("Database/Inventory.csv","r");
    ExistInvoiceFilePointer=fopen("Database/Invoice Receipt.csv","r");
    printf("Your Products are: ");
    while (fgets(line, sizeof(line), InventoryFilePointer)){
        Counter++;
        if (Counter == 1){
        printf("\n\nID\tProductName\n");
        }else{
        sscanf(line,"\n%d,%299[^,]",&ProductID,ProductName);
        printf("\n%d\t%s",ProductID,ProductName);
        }
    }
    fclose(InventoryFilePointer);
    printf("\n\nEnter how many product you want to sell (Max 100): ");
    scanf("%d",&LoopCount);
    for(i=0;i<LoopCount;i++){
    
    printf("\nEnter product %d by their ID: ",i+1);
    scanf("%d",&ID[i]);
    }

    CustomerID=CustomerInfo();
    CustomerFilePointer=fopen("Database/Customer.csv","r");
     while (fgets(Line3, sizeof(Line3), CustomerFilePointer)) {
        sscanf(Line3, "\n%d,%299[^,],%lld,%299[^,]", &CustID, CustName, &CustMobile, CustAddress);
        if(CustomerID == CustID){
            break;
        }
     }

    if(ExistInvoiceFilePointer != NULL){
    InvoiceFilePointer=fopen("Database/Invoice Receipt.csv","a");
    for (i = 0; i < LoopCount; i++){
        fprintf(InvoiceFilePointer,"\n%d, %d",CustomerID,ID[i]);
    }
    }else{
    InvoiceFilePointer=fopen("Database/Invoice Receipt.csv","w");
    fprintf(InvoiceFilePointer,"Customer ID, Inventory ID");
    for (i = 0; i < LoopCount; i++){
        fprintf(InvoiceFilePointer,"\n%d, %d",CustomerID,ID[i]);
    }
    }
    fclose(InvoiceFilePointer);
    int StructLength=GetProductByCustomer(CustID, Product, 100);

    if(StructLength != -1){
    int TotalDue=0;
    for (i = 0; i < StructLength; i++){
       TotalDue += Product[i].DBProductPrice;
    }
    CreateDirectory("Invoice", NULL);
    InvoiceNameFilePointer = fopen(InvoiceName, "w");

      time_t t;
      struct tm *tm_info;
      char date[11]; 
      time(&t);
      tm_info = localtime(&t);
      strftime(date, sizeof(date), "%Y-%m-%d", tm_info);

    CompanyFilePointer=fopen("Database/Company Config.csv","r");
    fgets(Line2, sizeof(Line2), CompanyFilePointer);
    sscanf(Line2,"%299[^,],%lld,%299[^,]",CompanyName,&Mobile,Address);
    fprintf(InvoiceNameFilePointer,
        "<!DOCTYPE html>\n"
        "<html lang='en'>\n"
        "<head>\n"
        "    <meta charset='UTF-8'>\n"
        "    <meta name='viewport' content='width=device-width, initial-scale=1.0'>\n"
        "    <title>Invoice</title>\n"
        "    <style>\n"
        "        body { font-family: Arial, sans-serif; }\n"
        "        .invoice-box { max-width: 800px; margin: auto; padding: 30px; border: 1px solid #eee; box-shadow: 0 0 10px rgba(0, 0, 0, 0.15); font-size: 16px; line-height: 24px; color: #555; }\n"
        "        .invoice-box table { width: %s; line-height: inherit; text-align: left; }\n"
        "        .invoice-box table td { padding: 5px; vertical-align: top; }\n"
        "        .invoice-box table tr td:nth-child(2) { text-align: right; }\n"
        "        .invoice-box table tr.top table td { padding-bottom: 20px; }\n"
        "        .invoice-box table tr.top table td.title { font-size: 45px; line-height: 45px; color: #333; }\n"
        "        .invoice-box table tr.information table td { padding-bottom: 40px; }\n"
        "        .invoice-box table tr.heading td { background: #eee; border-bottom: 1px solid #ddd; font-weight: bold; }\n"
        "        .invoice-box table tr.details td { padding-bottom: 20px; }\n"
        "        .invoice-box table tr.item td { border-bottom: 1px solid #eee; }\n"
        "        .invoice-box table tr.item.last td { border-bottom: none; }\n"
        "        .invoice-box table tr.total td:nth-child(2) { border-top: 2px solid #eee; font-weight: bold; }\n"
        "    </style>\n"
        "</head>\n"
        "<body>\n"
        "    <div class='invoice-box'>\n"
        "        <table cellpadding='0' cellspacing='0'>\n"
        "            <tr class='top'>\n"
        "                <td colspan='2'>\n"
        "                    <table>\n"
        "                        <tr>\n"
        "                            <td class='title'>\n"
        "                                <h1>Invoice</h1>\n"
        "                            </td>\n"
        "                            <td>\n"
        "                                Invoice : #%d<br>\n"
        "                                Created: %s<br>\n"
        "                                Due: Rs. %d.00\n"
        "                            </td>\n"
        "                        </tr>\n"
        "                    </table>\n"
        "                </td>\n"
        "            </tr>\n"
        "            <tr class='information'>\n"
        "                <td colspan='2'>\n"
        "                    <table>\n"
        "                        <tr>\n"
        "                            <td>\n"
        "                                Company Name<br>\n"
        "                                %s<br>\n"
        "                                %s\n"
        "                            </td>\n"
        "                            <td>\n"
        "                               Customer Name<br>\n"
        "                               %s<br>\n"
        "                               %lld<br>\n"
        "                            </td>\n"
        "                        </tr>\n"
        "                    </table>\n"
        "                </td>\n"
        "            </tr>\n"
        "            <tr class='heading'>\n"
        "                <td>Item</td>\n"
        "                <td>Price</td>\n"
        "            </tr>\n","100%",InvoiceID,date,TotalDue,CompanyName,Address,CustName,CustMobile);
             
                for (i = 0; i < StructLength; i++){
                fprintf(InvoiceNameFilePointer,
        "            <tr class='item'>\n"
        "                <td>%s</td>\n"
        "                <td>Rs. %d.00</td>\n"
        "            </tr>\n",Product[i].DBProductName,Product[i].DBProductPrice);
                }

            fprintf(InvoiceNameFilePointer,
        "            <tr class='total'>\n"
        "                <td></td>\n"
        "                <td>Total: Rs. %d.00</td>\n"
        "            </tr>\n"
        "        </table>\n"
        "    </div>\n"
        "</body>\n"
        "</html>",TotalDue);

    fclose(InvoiceNameFilePointer);
    fclose(ExistInvoiceFilePointer);
    fclose(CompanyFilePointer);
    system("cls");
    printf("Invoice is Generated: %s",InvoiceName);
    getch();
    }
    return 0;
}