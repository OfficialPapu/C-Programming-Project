
void printCentered(const char *text) {
    int length = strlen(text);
    int spaces = (150 - length) / 2;
    for (int i = 0; i < spaces; i++) {
        printf(" ");
    }
    printf("%s\n", text);
    Sleep(500); 
}

int FrontPage() {
    Sleep(2000); 
    printf("\n\n");

    printCentered("--------------------------------------------------");
    printCentered("A Project Proposal on");
    printCentered("\"Inventory Management System\"");
    printCentered("--------------------------------------------------");
    printf("\n");
    
    printCentered("Submitted in partial fulfillment of the");
    printCentered("requirements for the degree of \"Bachelor of");
    printCentered("Computer Application\" under");
    printCentered("Pokhara University");
    printf("\n");
    
    printCentered("--------------------------------------------------");
    printf("\n");
    
    printCentered("Submitted by:");
    printCentered("Name: Papu Yadav");
    printCentered("Subject: C - Programming");
    printCentered("Roll. No: 232026");
    printf("\n");
    
    printCentered("--------------------------------------------------");
    printf("\n");
    
    printCentered("Under the supervision of:");
    printCentered("Hem Raj Bhattrai");
    printf("\n");
    
    printCentered("--------------------------------------------------");
    printf("\n");
    
    printCentered("Date: May 16, 2024");
    printf("\n\n");
    
    getch(); 
    return 0;
}
