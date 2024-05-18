int InsertItems(){
	int ID, Qty, Price, SuppliersMobile,TotalCost, LoopCount,i;
	char ProductName[300], SuppliersName[300];
	FILE *InsertFilePointer, *FileExistData;
	SuppliersData();
	system("cls");
	printf("How many Product your want to insert: ");
	scanf("%d",&LoopCount);
	for (i = 1; i <= LoopCount; i++){
	FileExistData=fopen("Database/Inventory.csv","r");
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
	InsertFilePointer=fopen("Database/Inventory.csv","a");
	fprintf(InsertFilePointer,"\n%d, %s, %d, %d",ID,ProductName,Price,Qty);	
	}else{
	InsertFilePointer=fopen("Database/Inventory.csv","w");
	fprintf(InsertFilePointer,"Inventory ID, Product Name, Price, Qty");	
	fprintf(InsertFilePointer,"\n%d, %s, %d, %d",ID,ProductName,Price,Qty);	
	}
	}
	fclose(FileExistData);
	system("cls");
	printf("\n Congrats Product inserted Sucessfully");
	getch();
	return 0;
}
