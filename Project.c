#include<stdio.h> 
#include<conio.h>
#include<string.h>
#include<windows.h>
#include "Header File/Store Company Info.h"
#include "Header File/Insert Items.h"
#include "Header File/Modify Items.h"
#include "Header File/Suppliers.h"
#include "Header File/User Input.h"
void CreateInvoice();
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
		CreateInvoice();
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
void CreateInvoice(){
	printf("Wrong Choice");
}
void InventoryReport(){
	printf("Wrong Choice");
}
