int CompanyInfo(){
    if(CreateDirectory("Database", NULL)){
    long long Mobile;
    char CompanyName[300], Address[100];
    FILE *CompanyFIlePointer;
	system("cls");
    printf("Enter your Company Name: ");
    scanf("%s",CompanyName);
    system("cls");
    printf("Enter your Company Mobile: ");
    scanf("%lld",&Mobile);
    system("cls");
    printf("Enter your Company Address: ");
    scanf("%s",Address);
    CompanyFIlePointer=fopen("Database/Company Config.csv","w");
    fprintf(CompanyFIlePointer,"%s,%lld,%s",CompanyName,Mobile,Address);
    }
    return 0;
}