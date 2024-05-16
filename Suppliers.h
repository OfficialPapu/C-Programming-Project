void SuppliersData(){
    int  FileExistData, SuppliersMobile,TotalCost, LoopCount,i;
	char  SuppliersName[300], *Data;
	FILE *SuppliersFilePointer;
	system("cls");
	printf("Enter the suppliers name: ");
	scanf("%s",SuppliersName);
	system("cls");
	printf("Enter Suppliers Mobile: ");
	scanf("%d",&SuppliersMobile);
	system("cls");
	printf("Enter Total Purchase Cost: ");
	scanf("%d",&TotalCost);
	FileExistData=fopen("Suppliers.csv","r");
	if(FileExistData != NULL){
		int tempID, maxID=1;
		 char line[256];
        while (fgets(line, sizeof(line), FileExistData)) {
			Data=strtok(line,",");
        }
	SuppliersFilePointer=fopen("Suppliers.csv","a");
	fprintf(SuppliersFilePointer,"\n%d, %s, %d, %d",maxID,SuppliersName,SuppliersMobile,TotalCost);
	}else{
	SuppliersFilePointer=fopen("Suppliers.csv","w");
	fprintf(SuppliersFilePointer,"ID, Suppliers Name, Suppliers Mobile, Total Cost");	
	fprintf(SuppliersFilePointer,"\n1, %s, %d, %d",SuppliersName,SuppliersMobile,TotalCost);
	}
    }