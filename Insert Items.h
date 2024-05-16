int InsertItems(){
	SuppliersData();
	int ID, Qty, Price, FileExistData, SuppliersMobile,TotalCost, LoopCount,i;
	char ProductName[300], SuppliersName[300];
	FILE *InsertFilePointer, *SuppliersFilePointer;
	system("cls");
	printf("How many Product your want to insert: ");
	scanf("%d",&LoopCount);
	for (i = 1; i <= LoopCount; i++){
	FileExistData=fopen("Inventory.csv","r");
	system("cls");
	printf("Enter Inventory ID: ");
	scanf("%d",&ID);
	system("cls");
	printf("Enter Product Name: ");
	scanf("%s",ProductName);
	system("cls");
	printf("Enter Product Price: ");
	scanf("%d",&Price);
	system("cls");
	printf("Enter Product Quantity: ");
	scanf("%d",&Qty);
	if(FileExistData != NULL){
	InsertFilePointer=fopen("Inventory.csv","a");
	fprintf(InsertFilePointer,"\n%d,%s,%d,%d",ID,ProductName,Price,Qty);	
	}else{
	InsertFilePointer=fopen("Inventory.csv","w");
	fprintf(InsertFilePointer,"\n\nInventory ID,Product Name,Price,Qty");	
	fprintf(InsertFilePointer,"\n%d,%s,%d,%d",ID,ProductName,Price,Qty);	
	}
	}
	system("cls");
	printf("\n Congrats Product inserted Sucessfully");
	getch();
	return 0;
}
