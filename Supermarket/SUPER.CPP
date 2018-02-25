//***************************************************************
//                   Header files used in the Project
//***************************************************************

#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<fstream.h>
#include<iomanip.h>
#include<string.h>

//***************************************************************
//                   Class used in the project
//***************************************************************

class product
{
	int pno;
	char name[50];
	float price,qty,stock,dis;
	public:
	void create_product()
	{
		 cout<<"\n\tEnter the Batch No.: ";
		 cin>>pno;
		 cout<<"\tEnter Name of the vegetable: ";
		 gets(name);
		 cout<<"\tEnter Price of the vegatble(Rs./Kg): ";
		 cin>>price;
		 cout<<"\tEnter Vegetable in stock(in Kg) :";
		 cin>>stock;
		 cout<<"\tEnter the Discount (%): ";
		 cin>>dis;
	}
	void create_product2()
	{
		 cout<<"\tEnter Name of the vegetable: ";
		 gets(name);
		 cout<<"\tEnter Price of the vegatble(Rs./Kg): ";
		 cin>>price;
		 cout<<"\tEnter Vegetable in stock(in Kg) :";
		 cin>>stock;
		 cout<<"\tEnter the Discount (%): ";
		 cin>>dis;
	}
	void show_product()
	{
		 cout<<"\n\tBatch No. : "<<pno;
		 cout<<"\n\tName of the Vegetable : ";
		 puts(name);
		 cout<<"\tPrice of the Vegetable : Rs."<<price;
		 cout<<"\n\tVegetable in stock : "<<stock<<" kg";
		 cout<<"\n\tDiscount : "<<dis<<" %";
	}
	int  retpno()
	{
		return pno;
	}
	float retprice()
	{
		return price;
	}
	char* retname()
	{
		return name;
	}
	float retdis()
	{
		return dis;
	}
	float retstock()
	{
		return stock;
	}
	void modify_stock(float a)
	{
		stock+=a;
	}

};         //class ends here


//***************************************************************
//    	Global declaration for stream object, class object
//***************************************************************

fstream fp;
product pr;


//***************************************************************
//    	Function to write in file
//***************************************************************

void write_product()
{
	gotoxy(1,1);
	cout<<" ****************************************";
	cout<<"************************************** ";
	gotoxy(29,2);
	cout<<"VEGETABLE SUPER MARKET";
	gotoxy(1,3);
	cout<<" ****************************************";
	cout<<"************************************** \n";
	cout<<"\tNEW VEGETABLE\n";
	fp.open("Shop.dat",ios::out|ios::app);
	pr.create_product();
	fp.write((char*)&pr,sizeof(product));
	fp.close();
	cout<<"\n\tThe Vegetable has been added.";
	getch();
}

//***************************************************************
//    	Function to read specific record from file
//***************************************************************


void display_sp(int n)
{
	int flag=0;
	fp.open("Shop.dat",ios::in);
	while(fp.read((char*)&pr,sizeof(product)))
	{
		if(pr.retpno()==n)
		{
			clrscr();
			gotoxy(1,1);
			cout<<" ****************************************";
			cout<<"************************************** ";
			gotoxy(29,2);
			cout<<"VEGETABLE SUPER MARKET";
			gotoxy(1,3);
			cout<<" ****************************************";
			cout<<"************************************** \n";
			cout<<endl;
			pr.show_product();
			flag=1;
		}
	}
	fp.close();
	if(flag==0)
		cout<<"\n\n\\tIncorrect Batch no.";
	getch();
}


//***************************************************************
//    	Function to modify record of file
//***************************************************************

void modify_product()
{
	int no,found=0;
	clrscr();
	gotoxy(1,1);
	cout<<" ****************************************";
	cout<<"************************************** ";
	gotoxy(29,2);
	cout<<"VEGETABLE SUPER MARKET";
	gotoxy(1,3);
	cout<<" ****************************************";
	cout<<"************************************** \n";
	cout<<"\n\tModify Vegetable Details";
	cout<<"\n\n\tEnter The Product No.: ";
	cin>>no;
	fp.open("Shop.dat",ios::in|ios::out);
	while(fp.read((char*)&pr,sizeof(product)) && found==0)
	{
		if(pr.retpno()==no)
		{
			pr.show_product();
			cout<<"\n\n\tEnter The New Details of the vegetable"<<endl;
			pr.create_product2();
			int pos=-1*sizeof(pr);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&pr,sizeof(product));
			cout<<"\n\tVegetable details modified.";
			found=1;
		 }
	}
	fp.close();
	if(found==0)
	{
		cout<<"\n\n\tBatch no. not found.";
		cout<<"\n\tTry again.";
		getch();
	}
	getch();
}

//***************************************************************
//    	Function to update stock
//***************************************************************


void modify_stock()
{
	int no,found=0;
	float a;
	clrscr();
	gotoxy(1,1);
	cout<<" ****************************************";
	cout<<"************************************** ";
	gotoxy(29,2);
	cout<<"VEGETABLE SUPER MARKET";
	gotoxy(1,3);
	cout<<" ****************************************";
	cout<<"************************************** \n";
	cout<<"\n\tModify Vegetable Stock";
	cout<<"\n\n\tEnter the Batch No.: ";
	cin>>no;
	fp.open("Shop.dat",ios::in|ios::out);
	while(fp.read((char*)&pr,sizeof(product)) && found==0)
	{
		if(pr.retpno()==no)
		{
			pr.show_product();
			cout<<"\n\n\tEnter the volume of new stock to be added:";
			cin>>a;
			pr.modify_stock(a);
			int pos=-1*sizeof(pr);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&pr,sizeof(product));
			cout<<"\n\tNew stock has been added.";
			found=1;
		 }
	}
	fp.close();
	if(found==0)
	{
		cout<<"\n\n\tIncorrect Batch no. .";
		cout<<"\n\tTry Again..";
		getch();
	}
	getch();
}

//***************************************************************
//    	function to delete record of file
//***************************************************************


void delete_product()
{
	int no,found=0;
	clrscr();
	gotoxy(1,1);
	cout<<" ****************************************";
	cout<<"************************************** ";
	gotoxy(29,2);
	cout<<"VEGETABLE SUPER MARKET";
	gotoxy(1,3);
	cout<<" ****************************************";
	cout<<"************************************** \n";
	cout<<"\n\tRemove Vegetable";
	cout<<"\n\n\tEnter the Batch No. of the vegetable you want to remove : ";
	cin>>no;
	fp.open("Shop.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&pr,sizeof(product)))
	{
		if(pr.retpno()!=no)
		{
			fp2.write((char*)&pr,sizeof(product));
		}
		if(pr.retpno()==no)
		{
			found=1;
		}

	}
	fp2.close();
	fp.close();
	remove("Shop.dat");
	rename("Temp.dat","Shop.dat");
	if(found==1)
		cout<<"\n\tVegetable removed.";
	else
	{
		cout<<"Vegetable not found..!!";
		getch();
	}
	getch();
}

//***************************************************************
//    	function to display all products price list
//***************************************************************

void menu()
{       clrscr();
	gotoxy(1,1);
	cout<<" ****************************************";
	cout<<"************************************** ";
	gotoxy(29,2);
	cout<<"VEGETABLE SUPER MARKET";
	gotoxy(1,3);
	cout<<" ****************************************";
	cout<<"************************************** \n";
	fp.open("Shop.dat",ios::in);
	if(!fp)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPENED\n\n\n Go To Administrator Menu to create File";
		cout<<"\n\n\n Program is closing ....";
		getch();
		exit(0);
	}

	cout<<"\t\t\t\tLIST OF VEGETABLES\n";
	cout<<" ===================================================";
	cout<<"===========================";
	gotoxy(5,7);
	cout<<"B.NO.";
	gotoxy(15,7);
	cout<<"NAME";
	gotoxy(30,7);
	cout<<"PRICE(Rs/Kg)";
	gotoxy(49,7);
	cout<<"STOCK(Kg)";
	gotoxy(65,7);
	cout<<"Discount(%)";
	gotoxy(1,8);
	cout<<" ===================================================";
	cout<<"===========================";
	int i=9;
	while(fp.read((char*)&pr,sizeof(product)))
	{
		gotoxy(5,i);
		cout<<pr.retpno();
		gotoxy(14,i);
		cout<<pr.retname();
		gotoxy(33,i);
		cout<<pr.retprice();
		gotoxy(52,i);
		cout<<pr.retstock();
		gotoxy(68,i);
		cout<<pr.retdis();
		++i;
	}
	fp.close();
	getch();
}

//***************************************************************
//    	Function to place order and generate bill
//***************************************************************

void place_order()
{
	int  order_arr[50];
	int c=0;
	float quan[50];
	float amt,damt,total=0;		//damt - amount after discount
	char ch='n';
	int x,found=0;
	do
	{
		menu();
		ch='n';
		found=0;
		cout<<"\n ========================================";
		cout<<"====================================== ";
		cout<<"\t\t\t\t PLACE YOUR ORDER\n";
		cout<<" ========================================";
		cout<<"====================================== ";
		cout<<"\tEnter Batch No. of the Vegetable : ";
		cin>>order_arr[c];
		fp.open("Shop.dat",ios::in|ios::out);
		fp.seekg(0,ios::beg);
		while( (!fp.eof()) && found==0)
		{
			long pos=fp.tellg();
			fp.read((char*)&pr,sizeof(product));
			if(pr.retpno()==order_arr[c])
			{

				found=1;
				cout<<"\tEnter Weight of the Vegetable : ";
				cin>>quan[c];
				if(quan[c]>pr.retstock())
				{
					cout<<"\t\tNot Enough Stock.!!Try Again";
					quan[c]=0;
					--c;
				}
				if(quan[c]<=pr.retstock())
				{
					float f=(-quan[c]);
					pr.modify_stock(f);
					fp.seekg(pos);
					fp.write((char*)&pr,sizeof(product));
				}
				c++;
				cout<<"\n\tDo You Want To Order Another Product ? (y/n):";
				cin>>ch;
			}
		}
		fp.close();
		if(found == 0)
		{
			cout<<"\tWrong Batch No. . Please Try Again..";
			getch();
			place_order();

		}
	}while(ch=='y' ||ch=='Y');
	cout<<"\t...........Thank You For Placing The Order...........";
	fp.open("Shop.dat",ios::in|ios::out);
	found=0;
	fp.close();
	getch();
	clrscr();
	gotoxy(1,1);
	cout<<" ****************************************";
	cout<<"************************************** ";
	gotoxy(29,2);
	cout<<"VEGETABLE SUPER MARKET";
	gotoxy(1,3);
	cout<<" ****************************************";
	cout<<"************************************** \n";
	cout<<"\n\t\t\t\t INVOICE\n";
	cout<<" ========================================";
	cout<<"====================================== ";
	gotoxy(2,8);
	cout<<"B.NO.";
	gotoxy(10,8);
	cout<<"NAME";
	gotoxy(22,8);
	cout<<"WEIGHT";
	gotoxy(32,8);
	cout<<"PRICE(per Kg)";
	gotoxy(48,8);
	cout<<"AMOUNT";
	gotoxy(57,8);
	cout<<"AMOUNT AFTER DISCOUNT";
	gotoxy(1,9);
	cout<<" ========================================";
	cout<<"====================================== ";
	int i=10;
	for(x=0;x<=c;x++)
	{
		fp.open("Shop.dat",ios::in);
		fp.read((char*)&pr,sizeof(product));
		while(!fp.eof())
		{
			if(pr.retpno()==order_arr[x])
			{
				amt=pr.retprice()*quan[x];
				damt=amt-(amt*pr.retdis()/100);
				gotoxy(2,i);
				cout<<order_arr[x];
				gotoxy(9,i);
				cout<<pr.retname();
				gotoxy(23,i);
				cout<<quan[x]<<"Kg";
				gotoxy(32,i);
				cout<<"Rs."<<pr.retprice();
				gotoxy(49,i);
				cout<<"Rs."<<amt;
				gotoxy(59,i);
				cout<<"Rs."<<damt;
				++i;

				total+=damt;
			}
			fp.read((char*)&pr,sizeof(product));
		}
		fp.close();
	 }
	 cout<<"\n\n\t\t\t\t\t\tTOTAL = "<<"Rs. "<<total;
	 getch();
	 cout<<"\n\n\tThank You for buying the vegetables.\n";
	 cout<<"\tDo visit again...!!";
	 getch();
}


//***************************************************************
//    	ADMINSTRATOR MENU FUNCTION
//***************************************************************
void intro();
void admin_menu()
{
	clrscr();
	gotoxy(1,1);
	cout<<" ****************************************";
	cout<<"************************************** ";
	gotoxy(29,2);
	cout<<"VEGETABLE SUPER MARKET";
	gotoxy(1,3);
	cout<<" ****************************************";
	cout<<"************************************** \n";
	char ch2;
	cout<<"\tADMINISTRATOR MENU";
	cout<<"\n\n\t1.ENTER NEW VEGETABLE STOCK";
	cout<<"\n\n\t2.UPDATE EXISTING STOCK";
	cout<<"\n\n\t3.QUERY ";
	cout<<"\n\n\t4.MODIFY VEGETABLE DETAILS";
	cout<<"\n\n\t5.REMOVE VEGETABLE STOCK";
	cout<<"\n\n\t6.VIEW ALL VEGETABLES";
	cout<<"\n\n\t7.BACK TO MAIN MENU";
	cout<<"\n\n\tPlease Enter Your Choice (1-7): ";
	cin>>ch2;
	switch(ch2)
	{
		case '1': clrscr();
			  write_product();
			  admin_menu();
			  break;
		case '2': modify_stock();
			  admin_menu();
			  break;
		case '3': int num;
			  clrscr();
			  cout<<" ****************************************";
			  cout<<"************************************** ";
			  gotoxy(29,2);
			  cout<<"VEGETABLE SUPER MARKET";
			  gotoxy(1,3);
			  cout<<" ****************************************";
			  cout<<"************************************** \n";
			  cout<<"\n\n\tEnter the Batch No.: ";
			  cin>>num;
			  display_sp(num);
			  admin_menu();
			  break;
		case '4': modify_product();
			  admin_menu();
			  break;
		case '5': delete_product();
			  admin_menu();
			  break;
		case '6': menu();
			  admin_menu();
			  getch();
		case '7': intro();;
			  break;
		default:  cout<<"\t\t\tWrong Choice!";
			  getch();
			  admin_menu();
	}
}

//****************************************************************************
//    	CUSTOMER MENU FUNCTION
//****************************************************************************

void cust_menu()
{
	clrscr();
	gotoxy(1,1);
	cout<<" ****************************************";
	cout<<"************************************** ";
	gotoxy(29,2);
	cout<<"VEGETABLE SUPER MARKET";
	gotoxy(1,3);
	cout<<" ****************************************";
	cout<<"************************************** \n";
	char ch2;
	cout<<"\tCUSTOMER MENU";
	cout<<"\n\n\t1.DISPLAY ALL VEGETABLES";
	cout<<"\n\n\t2.PURCHASE VEGETABLES AND DISPLAY BILL";
	cout<<"\n\n\t3.RETURN TO MAIN MENU";
	cout<<"\n\n\tPlease Enter Your Choice (1-3): ";
	cin>>ch2;
	switch(ch2)
	{
		case '1': menu();
			  cust_menu();
			  break;
		case '2': place_order();
			  cust_menu();
			  break;
		case '3': intro();
			  break;
		default:  cout<<"\t\t\tWrong Choice!";
			  getch();
			  cust_menu();
	}
}

//***************************************************************
//    	INTRODUCTION FUNCTION
//***************************************************************

void intro()
{
	char ch;
	do
	{
		clrscr();
		gotoxy(1,1);
		cout<<" ****************************************";
		cout<<"************************************** ";
		gotoxy(29,2);
		cout<<"VEGETABLE SUPER MARKET";
		gotoxy(1,3);
		cout<<" ****************************************";
		cout<<"************************************** \n";
		cout<<"\n\n\tMAIN MENU";
		cout<<"\n\n\t01. CUSTOMER";
		cout<<"\n\n\t02. ADMINISTRATOR";
		cout<<"\n\n\t03. EXIT";
		cout<<"\n\n\tPlease Select Your Option (1-3): ";
		cin>>ch;
		switch(ch)
		{
			case '1': clrscr();
				  cust_menu();
				  getch();
				  break;
			case '2': clrscr();
				  gotoxy(1,1);
				  cout<<" ****************************************";
				  cout<<"************************************** ";
				  gotoxy(29,2);
				  cout<<"VEGETABLE SUPER MARKET";
				  gotoxy(1,3);
				  cout<<" ****************************************";
				  cout<<"************************************** \n";
				  cout<<"\n\n\tEnter password: ";
				  char pass[10];
				  for(int i=0;i<9;++i)
				  {
					pass[i]=getch();
					cout<<"*";
				  }
				  getch();
				  pass[9]='\0';
				  if(strcmpi(pass,"VEGETABLE")==0)
				  {
					admin_menu();
				  }
				  else
				  {
					cout<<"\n\n\t\tACCESS DENIED...!!!";
					getch();
					intro();
				  }
				  break;
			case '3': exit(0);
			default : cout<<"\a";
		}
	}while(ch!='3');
	getch();

}

//****************************************************************************
//    	THE MAIN FUNCTION OF PROGRAM
//****************************************************************************


void main()
{
	clrscr();
	gotoxy(1,1);
	cout<<" ****************************************";
	cout<<"************************************** ";
	gotoxy(29,2);
	cout<<"VEGETABLE SUPER MARKET";
	gotoxy(1,3);
	cout<<" ****************************************";
	cout<<"************************************** \n";
	gotoxy(21,13);
	cout<<"MADE BY : AMAN CHAUHAN AND GOPAL AGARWAL";
	gotoxy(24,14);
	cout<<"SCHOOL : MAHARAJA AGRASEN VIDYALAYA";
	getch();
	intro();
	getch();
}

//***************************************************************
//    			END OF PROJECT
//***************************************************************
