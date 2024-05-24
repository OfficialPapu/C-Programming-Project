int CustomerInfo(){
    long long CustMobile;
    char CustName[400],CustAddress[300], line[300];
    FILE *CustomerFilePointer, *ExistCustomerFilePointer;
    ExistCustomerFilePointer=fopen("Database/Customer.csv","r");
    system("cls");
    clearInputBuffer();
    printf("Enter customer name: ");
    fgets(CustName, sizeof(CustName), stdin);
    stripNewline(CustName);

    system("cls");
    printf("Enter customer mobile: ");
    scanf("%lld",&CustMobile);

    system("cls");
    clearInputBuffer();
    printf("Enter customer Address: ");
    fgets(CustAddress, sizeof(CustAddress), stdin);
    stripNewline(CustAddress);

    int tempID, maxID=1;
    if(ExistCustomerFilePointer != NULL){
	while (fgets(line, sizeof(line),ExistCustomerFilePointer)){
		sscanf(line,"%d",&tempID);
		    if (tempID >= maxID) {
            maxID = tempID;
        }
	}
    CustomerFilePointer=fopen("Database/Customer.csv","a");
    fprintf(CustomerFilePointer,"\n%d, %s, %lld, %s",(maxID+1), CustName, CustMobile, CustAddress);
    fclose(CustomerFilePointer);
    fclose(ExistCustomerFilePointer);
    return maxID+1;
    }else{
    CustomerFilePointer=fopen("Database/Customer.csv","w");
    fprintf(CustomerFilePointer,"ID, Name, Mobile, Address");
    fprintf(CustomerFilePointer,"\n%d, %s, %lld, %s", 1, CustName, CustMobile, CustAddress);
    fclose(CustomerFilePointer);
    fclose(ExistCustomerFilePointer);
    return maxID;
    }
}
