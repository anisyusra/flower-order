SOURCE CODE
//NAME: ANIS YUSRA BINTI MD YUSOF(2020828602)
//CLASS: CS2512A
//A PROGRAM TO TAKE FLOWER'S ORDER FROM CUSTOMER, DISPLAY THE RECEIPT AND
DISPLAY SALE
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

struct Flowers //struct for Flowers
{
string flowerName; //declare variable flowerName
float price; //declare variable price
int stalk; //declare variable stalk
string freeGift; //declare variable freeGift
};

struct CustomerOrder //struct for CustomerOrder
{
int choice; //declare variable choice
string custName; //declare variable custName
int quantity; //declare variable quantity
float totalPay; //declare variable totalPay
string flower; //declare variable flower
string free; //declare variable free
};

void displayCatalogue(Flowers[]); //function prototype
for displayCatalogue
void inputCatalogue(ifstream&, Flowers[]); //function prototype
inputCatalogue
void displayReceipt(ofstream&, CustomerOrder[], int); //function prototype
for displayReceipt
void avgNtotal(ofstream&, CustomerOrder[], int); //function prototype
for avgNtotal
void maxmin(ofstream&, CustomerOrder[], int); //function prototype
for maxmin
void flowerSale(ofstream&, int[]); //function prototype
for flowerSale

int main()
{
//declare struct variable into array
CustomerOrder customer[200];
Flowers bouquet[6];

int totalCust=0; //declare variable totalCust
int *p; //declare variable pointer
p = &totalCust; //assign address to variable pointer
char askUser; //declare variable askUser
int totalQty[6]={}; //declare 1d array [6]-flower set

//reading data and open the input file
ifstream order;
order.open("FlowerPriceList.txt");

//writing data and open the output file
ofstream receipt;
receipt.open("Receipt.txt");

ofstream sales;
sales.open("SalesReport.txt");

inputCatalogue(order, bouquet);
displayCatalogue(bouquet);

//input data from user
//getting order from customer
for(int x=0; x<200; x++)
{
cout << "Which set would you like to order?";
cout << "\nSet: "; //prompt user to enter set
cin >> customer[x].choice;

cout << "Your name: "; //prompt user to enter name
cin >> customer[x].custName;

cout << "Quantity order: "; //prompt user to enter quantity

cin>> customer[x].quantity;

//flower and total pay are based on customer choice on set
if(customer[x].choice == 1)
{
totalQty[0] = totalQty[0] + customer[x].quantity;
customer[x].flower = bouquet[0].flowerName;
customer[x].free = bouquet[0].freeGift;
customer[x].totalPay = bouquet[0].price *
customer[x].quantity;
}

else if (customer[x].choice == 2)
{
totalQty[1] = totalQty[1] + customer[x].quantity;
customer[x].flower = bouquet[1].flowerName;
customer[x].free = bouquet[1].freeGift;
customer[x].totalPay = bouquet[1].price *
customer[x].quantity;
}

else if (customer[x].choice == 3)
{
customer[x].flower = bouquet[2].flowerName;
customer[x].free = bouquet[2].freeGift;

totalQty[2] = totalQty[2] + customer[x].quantity;
customer[x].totalPay = bouquet[2].price *
customer[x].quantity;
}

else if (customer[x].choice == 4)
{
totalQty[3] = totalQty[3] + customer[x].quantity;
customer[x].flower = bouquet[3].flowerName;
customer[x].free = bouquet[3].freeGift;
customer[x].totalPay = bouquet[3].price *
customer[x].quantity;
}

else if (customer[x].choice == 5)
{
totalQty[4] = totalQty[4] + customer[x].quantity;
customer[x].flower = bouquet[4].flowerName;
customer[x].free = bouquet[4].freeGift;
customer[x].totalPay = bouquet[4].price *
customer[x].quantity;
}

else if (customer[x].choice == 6)
{
totalQty[5] = totalQty[5] + customer[x].quantity;

customer[x].flower = bouquet[5].flowerName;
customer[x].free = bouquet[5].freeGift;
customer[x].totalPay = bouquet[5].price *
customer[x].quantity;
}

else
cout << "This bouquet does not exist in our catalogue.";
cout << endl; //display if the set is not in catalogue

cout << "Total pay: RM "<<fixed<<setprecision(2);
cout << customer[x].totalPay << endl; //display totalPay
totalCust++; // count total customer

//ask user whether want to continue or not
cout << "Next customer? [Y-Yes || N-No]"<<endl;
cin >> askUser;

if (askUser=='N'||askUser=='n') //condition for No answer
break; //to stop the program

cout << endl << endl;
}

//display total customer in file Receipt.txt
sales << "TOTAL CUSTOMER OF MAI FLOWER SHOP FOR TODAY IS ";
sales << totalCust <<endl;
sales << "-------------------------------------------------";
sales << endl;

displayReceipt(receipt, customer, *p); //function call for
displayReceipt function
avgNtotal(sales, customer, *p); //function call for
avgNtotal function
maxmin(sales, customer, *p); //function call for maxmin
function
flowerSale(sales, totalQty); //function call for
flowerSale

order.close();
receipt.close();
sales.close();

return 0;
}

//function definition for displayCatalogue
void displayCatalogue(Flowers bouquet[])
{
cout << " ---------------------------- " << endl;
cout << " |WELCOME TO MAI FLOWER SHOP|" << endl;
cout << " ---------------------------- " << endl << endl;
cout << setw(15) << "SET" << setw(19) << "FLOWER NAME" << setw(15);
cout << "STALK" << setw(18) << "PRICE(RM)" << setw(17) << "FREE";
cout << endl;
cout << setw(15) << "---" << setw(20) << "-------------";
cout << setw(14) << "-----" << setw(18) << "---------" << setw(21);
cout << "-----------" << endl;

for (int i=0; i<6; i++)
{
cout << setw(14) << i+1 ;
cout << setw(20)<<bouquet[i].flowerName << setw(13); //display
flowerName
cout << bouquet[i].stalk << setw(18); //display
stalk
cout << fixed << setprecision(2)<<bouquet[i].price;
cout << setw(22); //display
price
cout << bouquet[i].freeGift << endl << endl; //display
free gift
}
}

//function definition for inputCatalogue function
void inputCatalogue(ifstream &order, Flowers bouquet[])
{
int j=0;
while(!order.eof())
{
getline(order, bouquet[j].flowerName, ';');
order>>bouquet[j].stalk;
order.ignore(1,';');
order>>bouquet[j].price;
order.ignore(1,';');
getline(order, bouquet[j].freeGift);
j++;
}
}

//function definition for displayReceipt
void displayReceipt(ofstream &receipt, CustomerOrder customer[], int
totalCust)
{
for(int i=0; i<totalCust; i++)
{
receipt << "\n----------------------------------------------";
receipt << "------------------------------" << endl;
receipt << "THANK YOU " << customer[i].custName;
receipt << " \nTHIS IS YOUR RECEIPT." << endl;

receipt << setw(15) << "CHOICE"<< setw(18) <<"FLOWER";
receipt << setw(15) << "FREE" << setw(25) << "QUANTITY";
receipt << endl;
receipt << setw(15) << "------" << setw(18) << "------";
receipt << setw(20) << "---------" << setw(20) << "--------";
receipt << endl;

receipt << setw(10)<<customer[i].choice;
receipt << setw(23)<<customer[i].flower;
receipt << setw(20)<<customer[i].free;
receipt << setw(15)<<customer[i].quantity;
receipt << endl << endl << "TOTAL PAY : RM ";
receipt << fixed << setprecision(2) << customer[i].totalPay;
receipt << endl;
receipt << "PLEASE COME AGAIN :) " << endl;
receipt << "------------------------------------------------";
receipt << "-----------------------------" << endl<<endl;
}
}

//function definition avgNtotal function
void avgNtotal(ofstream &sales, CustomerOrder customer[], int totalCust)
{
sales << endl<< endl << "Calculating total sale and sale average";
sales << "for today... "<< endl;
sales << "----------------------------------------------------";
sales << endl << endl;

float totalSale=0;
float average=0;
for(int i=0; i<totalCust; i++)
{
totalSale = totalSale+customer[i].totalPay;
}

sales << "Total sale for today is RM " << fixed << setprecision(2);
sales << totalSale << endl;

average = totalSale/totalCust;
sales << "Average sales per day is RM " << average << endl;
}

//function definition for maxmin function
void maxmin(ofstream &sales, CustomerOrder customer[], int totalCust)
{
float max = 0;
float min = 999;

for (int i=0; i<totalCust; i++)
{
if(customer[i].totalPay > max)
{
max = customer[i].totalPay;
}

if(customer[i].totalPay < min)
{
min = customer[i].totalPay;
}
}

sales << endl << endl << "Searching for the highest and the lowest";
sales << " total payment for today... " << endl;
sales << "--------------------------------------------------------";
sales << "-----------" << endl << endl;
sales << "The highest total payment for today is RM" << max << endl;
sales << "The lowest total payment for today is RM" << min << endl;
}

//function definition for flowerSale
void flowerSale(ofstream &sales, int total[6])
{
sales << endl << endl << "Calculating total sale for every set for";
sales << " today... " << endl;
sales << "-------------------------------------------------";
sales << endl << endl;

for (int i=0; i<6; i++)
{
if (i==0)
sales << "\tSet 1 : " << total[i] << endl;
else if (i==1)
sales << setw(16) << "Set 2 : " << total[i] << endl;
else if (i==2)
sales << setw(16) << "Set 3 : " << total[i] << endl;
else if (i==3)
sales << setw(16) << "Set 4 : " << total[i] << endl;
else if (i==4)
sales << setw(16) << "Set 5 : " << total[i] << endl;
else if (i==5)
sales << setw(16) << "Set 6 : " << total[i] << endl;

}
}