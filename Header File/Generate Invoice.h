int GenerateInvoice(){
    int ID, Counter = 0;
    char line[200], ProductName[300];
    FILE *InvoiceFilePointer;
    InvoiceFilePointer=fopen("Database/Inventory.csv","r");
    printf("Your Products are: ");
    while (fgets(line, sizeof(line), InvoiceFilePointer)){
        Counter++;
        if (Counter == 1){
        printf("\n\nID\tProductName\n");
        }else{
        sscanf(line,"\n%d,%299[^,]",&ID,ProductName);
        printf("\n%d\t%s",ID,ProductName);
        }
    }
    printf("\n\nEnter product by their ID: ");
    scanf("%d",&ID);
    getch();
    return 0;
}