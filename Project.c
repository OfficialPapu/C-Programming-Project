#include<stdio.h> 
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<time.h>
#include<stdlib.h>

#include "Header File/Store Company Info.h"
#include "Header File/Insert Items.h"
#include "Header File/Modify Items.h"
#include "Header File/Suppliers.h"
#include "Header File/Generate Invoice.h"
#include "Header File/User Input.h"
#include "Header File/Manage Buffer Input.h"
#include "Header File/Store Customer Info.h"
#include "Header File/Get Product By Customer.h"
void InventoryReport();
int main(){
	CompanyInfo();
	int Operation;
	Operation = UserInput();
	while (Operation != 5){	
	if(Operation==1){
		InsertItems();
		Operation = UserInput();
	}else if(Operation==2){
		ModifyItems();
		Operation = UserInput();
	}else if(Operation==3){
		GenerateInvoice();
		Operation = UserInput();
	}else if(Operation==4){
		InventoryReport();
		Operation = UserInput();
	}else if(Operation==5){
		return 0;
	}else{
		system("cls");
		printf("Wrong Choice!!");
		getch();
		Operation = UserInput();
	}
	}
	return 0;
}
void InventoryReport(){
	printf("Wrong Choice");
}
