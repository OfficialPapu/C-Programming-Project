#include<stdio.h> 
#include<conio.h>
#include<string.h>
#include "Insert Items.h"
#include "Modify Items.h"
#include "Suppliers.h"
#include "User Input.h"
void CreateInvoice();
void InventoryReport();
int main(){
	int Operation;
	Operation = UserInput();
	while (Operation != 5){	
	if(Operation==1){
		// InsertItems();
SuppliersData();
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
