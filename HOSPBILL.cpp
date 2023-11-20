/*
This program has develop for hospital billing system for patients.

				Developer 1: Luqman Azri
				Developer 2: Nur Fatihah
				Developer 3: Fatin Shahirah
*/


#include <iostream>
using namespace std;


// function header for not valid input for number of days 
double inputValidate (double num)
{

	while (num < 0)
	{
		cout << "Please enter again. Number must be a positive number." << endl; //not valid for negative integer
		cout << "Enter how many days spent in the hospital: ";
		cin >> num; //input new number for days spent at hospital
		cout << endl;
	}
	
	//return value function of new number of days to the main
	return num;
}

// function header for hospital stay 
double hospitalStay()
{
	//declare type of room
	char roomtype;	
	double daily_rate;
	
	// constant menu for type of room
	const char FIRST_CLASS = 'A',
	           SECOND_CLASS = 'B',
	           THIRD_CLASS = 'C';
	
	//display the menu of type of room
	cout << "---------------------------------------------------------------\n";	           
	cout<< "\t\t   These are the type of room " << endl
		<< "\t\t_______________________________" <<endl
		<< "\t\t|Code |Room Type     |Price   |" <<endl
		<< "\t\t|-----|--------------|--------|" <<endl
	    << "\t\t|A.   | FIRST CLASS  | RM 400 |" << endl
	    << "\t\t|B.   | SECOND CLASS | RM 250 |"<< endl
	    << "\t\t|C.   | THIRD CLASS  | RM 150 |" << endl
	    << "\t\t|_____|______________|________|" <<endl<<endl
	    << "Please enter your room type: " ;
	cin >> roomtype; //input your choice of room type
	cout << "---------------------------------------------------------------\n";
	cout << "Please note that the room price has been already included with"<<endl
		 << "                       food charges                           "<<endl;	
	
	//to find the daily rate based on type of room
	if (roomtype == 'A'|| roomtype == 'a') 
	{
		daily_rate = 400 ;
		cout << "Daily rate for first class room is : RM " << daily_rate << endl; //display the price per day of room type
	}
	
	if (roomtype == 'B' || roomtype == 'b')
	{
		daily_rate = 250;
		cout << "Daily rate for second class room is : RM " << daily_rate << endl; //display the price per day of room type
	}
	
	if (roomtype == 'C' || roomtype == 'c')
	{
		daily_rate = 150;
		cout << "Daily rate for third class room is : RM " << daily_rate << endl; //display the price per day of room type
	}
	
	//return value function of room type to the main
	return daily_rate;
}


//function header for surgery charge
double surgeryCharge()
{
	//declare type of surgery and rate surgery
	char surgerytype;
	double rateSurgery;
	bool surgery;
	
	//constant menu for type of surgery
	const char KIDNEY_TRANSPLANT = 'A',
	           APPENDIX = 'B',
	           CARDIAC = 'C',
	           THYROID = 'D',
	           LUNG_CANCER = 'E';
	
	cout << "\nDid the patient do surgery? : "<<endl;
	cout << "Enter 1 for (YES) Or 0 for (NO) :";
	cin >> surgery;
	
	//to find patient has done the surgery or not
	if (surgery == 1){
	//display the menu of type of surgery 
	cout << "---------------------------------------------------------------\n";	        
	cout << "\t\t        These are type of surgery " << endl
		 << "\t\t____________________________________________" << endl
		 << "\t\t|Code |Type of Surgery           |Price    |" << endl
		 << "\t\t|---- |--------------------------|---------|" << endl
	     << "\t\t|A.   |KIDNEY TRANSPLANT SURGERY |RM  40000|" << endl
	     << "\t\t|B.   |APPENDIX REMOVAL SURGERY  |RM   5000|" << endl
	     << "\t\t|C.   |HEART BYPASS SURGERY      |RM  75000|" << endl
	     << "\t\t|D.   |THYROID SURGERY           |RM  20000|" << endl
	     << "\t\t|E.   |LUNG CANCER SURGERY       |RM 200000|" << endl
	     << "\t\t|_____|__________________________|_________|" << endl<<endl
	     << "Please enter your type of surgery: ";
	cin >> surgerytype; //input your choice of surgery type
	cout << "---------------------------------------------------------------\n";	

	//to find payment based on type of surgery
	if (surgerytype == 'A' || surgerytype == 'a')
	{
		rateSurgery = 40000;
		cout << "The total cost for the Kidney Transplant Surgery is: RM " << rateSurgery << endl; //display the price of surgery type
	}
	
	if (surgerytype == 'B'|| surgerytype == 'b')
	{
		rateSurgery = 5000;
		cout << "The total cost for the Appendix Removal Surgery is: RM " << rateSurgery << endl;//display the price of surgery type
	}
	
	if (surgerytype == 'C' || surgerytype == 'c')
	{
		rateSurgery = 75000;
		cout << "The total cost for the Heart bypass Surgery is: RM " << rateSurgery << endl;//display the price of surgery type
	}
	
	if (surgerytype == 'D' || surgerytype == 'd')
	{
		rateSurgery = 20000;
		cout << "The total cost for the Thyroid Surgery is: RM " << rateSurgery << endl;//display the price of surgery type
	}
	
	if (surgerytype == 'E'|| surgerytype == 'e')
	{
		rateSurgery = 200000;
		cout << "The total cost for the Lung Cancer Surgery is: RM " << rateSurgery << endl;//display the price of surgery type
	}
	}
	else
	{
		rateSurgery = 0; //because no surgery 
	}
	//return value function of surgery type to the main
	return rateSurgery;
}

//function header for pharmacy charge
double pharmacyCharge()
{
	//declare type of medication and rate pharmacy
	char medicationtype;
	double ratePharmacy;
	bool med;
	
	//constant menu for type of medication
	const char AZATHIOPRINE = 'A', // medicine for kidney problem
	           CEFOTAXIME = 'B' ,  // Medicine for appendix surgery
	           ANTIPLATELET = 'C', // Medicine after heart bypass surgery
	           LEVOTHYROXINE = 'D', // medicine after thyroid removal 
	           ABRAXANE = 'E'; // medicine for lung cancer
	
	cout << "\nDid the patient took medicine ? :"<<endl;
	cout << "Enter 1 for (YES) OR 0 for (NO) : ";
	cin >> med;
	
	//to find patient take medicine at pharmacy or not
	if (med == 1){
	//display the menu of type of medication 
	cout << "---------------------------------------------------------------\n";	           
	cout << "\t\t   These are the type of medication" << endl
		 << "\t\t______________________________________"<<endl
		 << "\t\t|Code |Type of medicine |Price       |" <<endl
		 << "\t\t|-----|-----------------|------------|" <<endl
	     << "\t\t|A.   |AZATHIOPRINE     |RM 250      |" << endl
	     << "\t\t|B.   |CEFOTAXIME       |RM 145      |" << endl
	     << "\t\t|C.   |ANTIPLATELET     |RM 650      |" << endl
	     << "\t\t|D.   |LEVOTHYROXINE    |RM 220      |" << endl
	     << "\t\t|E.   |ABRAXANE         |RM 950      |" << endl
	     << "\t\t|_____|_________________|____________|" <<endl<<endl
	     << "Please enter your choice: ";
	cin >> medicationtype; //input your choice of medication type
	cout << "---------------------------------------------------------------\n";	
	
	//to find payment based on type of medication
	if (medicationtype == 'A'|| medicationtype == 'a')
	{
		ratePharmacy = 250 ;
		cout << "The pharmacy charge is: RM " << ratePharmacy << endl; //display the price of medication type
	}
	
	if (medicationtype == 'B'|| medicationtype == 'b')
	{
		ratePharmacy = 145 ;
		cout << "The pharmacy charge is: RM " << ratePharmacy << endl; //display the price of medication type
	}
	
	if (medicationtype == 'C'|| medicationtype == 'c')
	{
		ratePharmacy = 650;
		cout << "The pharmacy charge is: RM " << ratePharmacy << endl; //display the price of medication type 
	}
	
	if (medicationtype == 'D'|| medicationtype == 'd')
	{
		ratePharmacy = 220 ;
		cout << "The pharmacy charge is: RM " << ratePharmacy << endl; //display the price of medication type
	}
	
	if (medicationtype == 'E'|| medicationtype == 'e')
	{
		ratePharmacy = 950 ;
		cout << "The pharmacy charge is: RM " << ratePharmacy << endl; //display the price of medication type
	}
	}
	else
	{
		ratePharmacy = 0; //because no medicine
	}
	
	//return value function of medication type to the main
	return ratePharmacy;         
}

//function header for service charge
double serviceCharge( )
{
	//declare type of service frequency and rate service of patient get the service
	char servicetype;
	double frequency;
	double rateService;
	bool srvc;
	
	//constant menu for type of service
	const char XRAY = 'A',
	           LABORATARY_TEST = 'B',
	           CHEMOTHERAPHY = 'C',
	           PHISIOTHERAPHY = 'D';
	
	cout << "\nDid the patient take Service? :"<<endl
		 << "Enter 1 for (YES) OR 0 for (NO): ";
	cin >> srvc;
	
	//to find patient has done the service or not
	if (srvc == 1){   
	//display the menu of type of service
	cout << "---------------------------------------------------------------\n";	  	           
	cout << "\t\t     Please enter the service" << endl
		 << "\t\t______________________________________"<<endl
		 << "\t\t|Code |Type of Service    |Price     |"<<endl
		 << "\t\t|-----|-------------------|----------|"<<endl
	     << "\t\t|A.   |X-RAY              |RM  100   |" << endl
		 << "\t\t|B.   |LABORATORY TEST    |RM   30   |" << endl 
		 << "\t\t|C.   |CHEMOTHERAPHY      |RM 9200   |" << endl
		 << "\t\t|D.   |PHYSIOTHERAPHY     |RM   50   |" << endl
		 << "\t\t|_____|___________________|__________|" <<endl<<endl
		 << "Please enter your choice: " ;
	cin >> servicetype;
	cout << "---------------------------------------------------------------\n";
	
	//to find payment based on type of service	
	if (servicetype == 'A' || servicetype == 'a')
	{
	   cout << "How many time you done this service:";
	   cin >> frequency; //input frequency that you have done for the service
	   rateService = 100 * frequency; //to find the total payment for the type of service
	   cout << "The rate service is: RM " << rateService << endl; //display the price of service type
	}
	
	if (servicetype == 'B' || servicetype == 'b')
	{
	   cout << "How many time you done this service:";
	   cin >> frequency; //input frequency that you have done for the service
	   rateService = 30 * frequency; //to find the total payment for the type of service
	   cout << "The rate service is: RM " << rateService << endl;  //display the price of service type
	}
	
	if (servicetype == 'C' || servicetype == 'c')
	{
	   cout << "How many time you done this service:";
	   cin >> frequency; //input frequency that you have done for the service
	   rateService = 9200 * frequency; //to find the total payment for the type of service
	   cout << "The rate service is: RM " << rateService << endl;  //display the price of service type
	}
	
	if (servicetype == 'D' || servicetype == 'd')
	{
	   cout << "How many time you done this service:";
	   cin >> frequency; //input frequency that you have done for the service
	   rateService = 50 * frequency; //to find the total payment for the type of service
	   cout << "The rate service is: RM " << rateService << endl;  //display the price of service type
	}
	}
	else
	{
		rateService = 0; //because no service
	}
	//return value function of service type to the main	
	return rateService;      	           
}

//function header for calculate the total bill
double getBill (double days, double daily_rate, double rateSurgery, double ratePharmacy, double rateService)                     	                    
{
	//calculate the total bill
	double totalBill = (days * daily_rate) + rateSurgery + ratePharmacy + rateService ;
	
	//return value function of getBill to the main
	return totalBill;
}

// function header for display total bill
void displayBill  (double totalBill)
{
	cout << "_______________________________________________________________\n";
	cout << "\t\t\t\t\tTotal payment: RM" << totalBill <<endl;
	cout << "_______________________________________________________________\n";	    
}




int main ()
{
	double days; // declare variable days
	cout << "_______________________________________________________________\n";
	cout << "\t\t  HOSPITAL BILLING SYSTEM"  << endl;
	cout << "_______________________________________________________________\n";
	cout << "" << endl;
	
	// to get the number of days patient stay in the hospital    
	cout << "How many days spent in the hospital: " ;
	cin >> days;
	cout << endl;
	
	inputValidate(days); // function call for input Validation
	double total_rate = hospitalStay(); // function call for cost of daily rate 
	double surgery = surgeryCharge(); // function call for surgery charge
	double pharmacy = pharmacyCharge(); // function call for pharmacy charge
	double service = serviceCharge(); // function call for service charge
	double totalBill = getBill (days, total_rate, surgery, pharmacy, service); // function call for calculate the hospital bill
	displayBill (totalBill); // function call for display the hospital bill

	return 0;
	
}

