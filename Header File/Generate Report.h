struct GenerateReport{
    int ProductID;
    char DBProductName[300];
    long long DBProductPrice;
    int ProductQty;
};
void GenerateReport(){
    struct GenerateReport Product[100];
    FILE *InventoryPosition, *CreageInventoryPosition;
    int InvoiceID, i;
    char FileName[100] = "Report/Sales-Report-", Line[400];
    srand(time(0));
    InvoiceID = rand() % 10000 + 1;
    sprintf(FileName, "%s%d.html", FileName, InvoiceID);
}