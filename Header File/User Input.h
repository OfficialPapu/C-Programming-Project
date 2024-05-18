int UserInput(){
	int Operation;
	system("cls");
	printf("1. Insert Items\n2. Modify Items\n3. Generate Invoice\n4. Inventory Report\n5. Exit\n\n Enter Your Choice: ");
	scanf("%d",&Operation);
	system("cls");
	return Operation;
}