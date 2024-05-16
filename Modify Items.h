int ModifyItems(){
	int SearchID,ID, Qty, Price,FileExistData;
	char ProductName[300];
	FILE *SearchFilePointer;
	system("cls");
	FileExistData=fopen("Inventory.csv","r");
	if(FileExistData != NULL){
	printf("Search inventory by ID: ");
	scanf("%d",&SearchID);
	SearchFilePointer=fopen("Inventory.csv","r");
	while (SearchFilePointer != EOF){
		fscanf(SearchFilePointer,"\n%d",&ID);
		system("cls");
		printf("The ID id %d",ID);
	}
	
	}else{
	system("cls");	
	printf("Something went wrong!\nFile Not Found!");
	getch();
	}
	return 0;
}
