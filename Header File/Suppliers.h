void SuppliersData(){
    int  FileExistData, LoopCount,i;
	long long SuppliersMobile,TotalCost;
	char  SuppliersName[300], line[100];
	FILE *SuppliersFilePointer;
	system("cls");
	printf("Enter the suppliers name: ");
	scanf("%s",SuppliersName);
	system("cls");
	printf("Enter Suppliers Mobile: ");
	scanf("%lld",&SuppliersMobile);
	system("cls");
	printf("Enter Total Purchase Cost: ");
	scanf("%lld",&TotalCost);
	FileExistData=fopen("Database/Suppliers.csv","r");
	if(FileExistData != NULL){
		int tempID, maxID=1;
	while (fgets(line, sizeof(line),FileExistData)){
			sscanf(line,"%d",&tempID);
		    if (tempID >= maxID) {
            maxID = tempID;
        }
	}
	SuppliersFilePointer=fopen("Database/Suppliers.csv","a");
	fprintf(SuppliersFilePointer,"\n%d, %s, %lld, %lld",tempID+1,SuppliersName,SuppliersMobile,TotalCost);
	}else{
	SuppliersFilePointer=fopen("Database/Suppliers.csv","w");
	fprintf(SuppliersFilePointer,"ID, Suppliers Name, Suppliers Mobile, Total Cost");	
	fprintf(SuppliersFilePointer,"\n1, %s, %lld, %lld",SuppliersName,SuppliersMobile,TotalCost);
	}
	fclose(FileExistData);
    }