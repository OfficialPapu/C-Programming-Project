int ReportInput(Operation){
    system("cls");
    printf("1. Inventory Position\n2. Today's Profit\n\n Enter Your Choice: ");
    scanf("%d", &Operation);
    return Operation;
}
void Report(){
    int Operation;
    Operation = ReportInput(Operation);
    if (Operation == 1){
        InventoryPositionFun();
    }
    else if (Operation == 2){

    }
    else{
        printf("Wrong Choice!!");
    }
}