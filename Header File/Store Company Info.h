int CompanyInfo() {
    if (CreateDirectory("Database", NULL)) {
        long long Mobile;
        char CompanyName[300], Address[100];
        FILE *CompanyFilePointer;
        system("cls");
        printf("Enter your Company Name: ");
        fgets(CompanyName, sizeof(CompanyName), stdin);
        stripNewline(CompanyName);  
       
        system("cls");
        printf("Enter your Company Mobile: ");
        scanf("%lld", &Mobile);
        clearInputBuffer();
        
        system("cls");
        printf("Enter your Company Address: ");
        fgets(Address, sizeof(Address), stdin);
        stripNewline(Address); 
        CompanyFilePointer = fopen("Database/Company Config.csv", "w");
        if (CompanyFilePointer != NULL) {
            fprintf(CompanyFilePointer, "%s,%lld,%s", CompanyName, Mobile, Address);
            fclose(CompanyFilePointer);
        } else {
            printf("Failed to create file.\n");
        }
    }
    return 0;
}

