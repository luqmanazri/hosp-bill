
#include <iostream>
#include <iomanip>
using namespace std;

//Function prototypes
void displayroomMenu(); //menu for room
void displaySurgeryMenu(); //menu for surgery
void displayMedicationMenu(); //menu for medication
void displayServiceMenu(); //menu for service
char checkValid(char); //validation for user input yes or no
double roomCharges(int);
double surgeryCharges(int);
double pharmacyCharge(int);
double serviceCharge(int);
double hospitalstay(double, double);
void displayBill (int, double, double, double, double, double); 
string Maxname(string[], double[] , int );
double Max (string[], double[], int);
string Minname(string[], double[], int);
double Min (string[] , double[] , int);
double getBill(double, double, double, double);
int totalDays(int[], int );
double cacltotal(double[], int);

int main()
{
	//variable declaration for character data types
	char roomcheck,
		 surgerycheck,
		 pharmacycheck,
		 medicationcheck,
		 servicecheck;
	
	//variable declaration for double data types	 
	double totalhospitalStay=0,
		   totalsurgery=0,
		   totalmedication=0,
		   totalservice=0,
		   minBill,
		   maxBill,
		   averageDays,
		   TotalCharges;
	
	//variable declaration for integer data types	   
	int roomtypes,
		surgerytypes,
		medicationtypes,
		servicetypes,
		total_days,
		totalpatient,
		day;
	
	//variable declaration for string data types	
	string Billmaxname, //name for highest bill
		   Billminname; //name for lowest bill
	
	
	//display the bill	   
	cout << "_______________________________________________________________\n";
	cout << "\t\t  HOSPITAL BILLING SYSTEM"  << endl;
	cout << "_______________________________________________________________\n";
	cout << "" << endl;
	cout << "Total Patient check out today: "; //user input amount of patient on that day
	cin >> totalpatient;
	cout << endl;
		
	//array declaration
	string patientName[totalpatient];
	int days[totalpatient] = {0};
	double  stay_charges[totalpatient] = {0},
			daily_rates[totalpatient] = {0},
			rateSurgery[totalpatient] = {0},
			ratePharmacy[totalpatient] = {0},
			rateService[totalpatient] = {0},
			totalCost[totalpatient] = {0};
	
		
	for (int i=0; i<totalpatient; i++)
	{
		cin.ignore();
		cout << "_______________________________________________________________\n\n";
		cout<<"What is name for Patient " << i +1<<": ";
		getline(cin,patientName[i]);
		cout<<endl;
		cout<< "\nDid the patient stay at room?"<<endl;
		cout<< "Enter Y for YES and N for No : ";
		cin>>roomcheck;
		cout<<endl;
		roomcheck = checkValid(roomcheck);
		
		cout<<"How many days spent in the hospital? ";
		cin>>days[i];
		cout<<endl;
		
		//check validation for room
		if(roomcheck == 'y' || roomcheck == 'Y')
		{
			displayroomMenu();
		}
		
		if(roomcheck != 'N' && roomcheck !='n')
		{
		cout << "Which type of room that the patient stay? ";
		cin>> roomtypes;
		cout<<endl;		
		daily_rates[i] += roomCharges(roomtypes);
		}
		
		//to calculate stay charge
		stay_charges[i] = hospitalstay(daily_rates[i], days[i]);
		cout<<endl<<endl;
		
		cout<< "Did the patient took any surgery? "<<endl; 
		cout<< "Enter Y for YES and N for No : ";
		cin>>surgerycheck;
		cout<<endl;
		surgerycheck = checkValid(surgerycheck);
		
		//check validation for surgery
		if(surgerycheck == 'y' || surgerycheck == 'Y')
		{
			displaySurgeryMenu();
		}
		
		while(surgerycheck != 'N' && surgerycheck !='n')
		{
		cout<< "Which type of surgery that the patient take? ";
		cin>> surgerytypes;
		cout<<endl;
	
		rateSurgery[i] += surgeryCharges(surgerytypes);
		
		cout<< "Has Patient take any other surgery? "<<endl;
		cout<< "Enter Y for YES and N for No : ";
		cin >> surgerycheck;
		cout<<endl;
		}
	
		cout<<endl<<endl;
		
		cout<< "Did the patient take any medicine?"<<endl;
		cout<< "Enter Y for YES and N for No : ";
		cin>> medicationcheck;
		cout<<endl;
		medicationcheck = checkValid(medicationcheck);
		
		//check validation for medicine
		if(medicationcheck == 'Y' || medicationcheck == 'y')
		{
			displayMedicationMenu();
		}
	
		while(medicationcheck != 'N' && medicationcheck != 'n' )
		{
			cout<< "Which type of medicine that the patient take? ";
			cin>> medicationtypes;
			cout<<endl;
		
			ratePharmacy[i] += pharmacyCharge(medicationtypes);
			cout<< "Has Patient take any other medicine? "<<endl;
			cout<< "Enter Y for YES and N for No : ";
			cin>> medicationcheck;
		}
	
		cout<<endl<<endl;
			
		cout<< "Did the patient take any service?"<<endl;
		cout<< "Enter Y for YES and N for No : ";
		cin>> servicecheck;
		cout<<endl;
		servicecheck = checkValid(servicecheck);
	
		//check validation for service
		if(servicecheck == 'Y' || servicecheck =='y')
		{
			displayServiceMenu();
		}
	
		while(servicecheck != 'N' && servicecheck !='n' )
		{
			cout<< "Which type of service that the patient take? ";
			cin>> servicetypes;
			cout<<endl;
		
			rateService[i] += serviceCharge(servicetypes);
			cout<< "Has Patient take any other service? "<<endl;
			cout<< "Enter Y for YES and N for No : ";
			cin>> servicecheck;
			cout<<endl;
			servicecheck = checkValid(servicecheck);
		}
	}
	
	for(int i=0; i<totalpatient;i++)
	{
	 	cout << "_______________________________________________________________" <<endl;
	 	cout << "\t\t  Patient " << i+1 << " " << patientName[i] << " bill " <<endl;
	 	cout << "---------------------------------------------------------------\n";
	 	
	 	//function call to find total bill and display bill
	 	totalCost[i] = getBill(stay_charges[i], rateSurgery[i], ratePharmacy[i], rateService[i]);
	 	displayBill(days[i], totalCost[i], stay_charges[i], rateSurgery[i], ratePharmacy[i], rateService[i]);
	}
	 	cout << endl;
	 	
	 	//function call to get total bill for each category
	 	total_days       =totalDays(days,totalpatient);
	 	totalhospitalStay=cacltotal(stay_charges,totalpatient);
	 	totalsurgery     =cacltotal(rateSurgery,totalpatient);
	 	totalmedication  =cacltotal(ratePharmacy,totalpatient);
	 	totalservice     =cacltotal(rateService,totalpatient);
	 	TotalCharges     =cacltotal(totalCost, totalpatient);
	 	
	 	//to find average of hospital stay
	 	double averageHospitalStay = static_cast<double>(total_days) / totalpatient;
	 	
	 	//function call to find patient
	 	//name for highest and lowest bill
	 	Billmaxname = Maxname(patientName, totalCost, totalpatient);
	 	maxBill =Max(patientName, totalCost, totalpatient);
	 	Billminname= Minname(patientName, totalCost, totalpatient);
	 	minBill = Min(patientName, totalCost, totalpatient);
	 	
	 	//to display total bill for each category 
	 	cout << fixed << showpoint << setprecision(2);
	 	cout << "Total Charges for all patients   : RM" <<TotalCharges<<endl;
	 	cout << "Total Hospital Stay              : RM" <<totalhospitalStay<<endl;
	 	cout << "Total Surgery                    : RM"<<totalsurgery<<endl;
	 	cout << "Total Medication                 : RM" <<totalmedication<<endl;
	 	cout << "Total Service                    : RM" <<totalservice<<endl;
	 	cout << "Average Hospital Stay            : "<<averageHospitalStay<<" days "<<endl<<endl;
	 	
	 	if (totalpatient>1)
		 {
		 	//to display patient with highest and lowest bill
		 	cout << "---------------------------------------------------------------\n";
	 		cout <<"The patient's name that pays the highest bill: "<< Billmaxname << " RM " <<maxBill<<endl<<endl;
	 		cout <<"The patient's name that pays the lowest  bill: "<< Billminname << " RM " <<minBill<<endl<<endl;
	 		cout << "---------------------------------------------------------------\n";
		 }
}
	 	
//function header for room menu		 	
void displayroomMenu()
{
	cout<< "---------------------------------------------------------------\n";	           
	cout<< "\t\t  These are the type of room: " << endl
		<< "\t\t_______________________________" <<endl
		<< "\t\t|Code |Room Type     |Price   |" <<endl
		<< "\t\t|-----|--------------|--------|" <<endl
	    << "\t\t|1.   | FIRST CLASS  | RM 400 |" << endl
	    << "\t\t|2.   | SECOND CLASS | RM 250 |"<< endl
	    << "\t\t|3.   | THIRD CLASS  | RM 150 |" << endl
	    << "\t\t|_____|______________|________|" <<endl<<endl;	
}

//function header for surgery menu
void displaySurgeryMenu()
{
	cout << "---------------------------------------------------------------\n";	        
	cout << "\t\t        These are type of surgery: " << endl
		 << "\t\t____________________________________________" << endl
		 << "\t\t|Code |Type of Surgery           |Price    |" << endl
		 << "\t\t|---- |--------------------------|---------|" << endl
	     << "\t\t|1.   |KIDNEY TRANSPLANT SURGERY |RM  40000|" << endl
	     << "\t\t|2.   |APPENDIX REMOVAL SURGERY  |RM   5000|" << endl
	     << "\t\t|3.   |HEART BYPASS SURGERY      |RM  75000|" << endl
	     << "\t\t|4.   |THYROID SURGERY           |RM  20000|" << endl
	     << "\t\t|5.   |LUNG CANCER SURGERY       |RM 200000|" << endl
	     << "\t\t|_____|__________________________|_________|" << endl<<endl;
}

//function header for medication menu
void displayMedicationMenu()
{
	cout << "---------------------------------------------------------------\n";
	cout << "\t\t   These are the type of medication:" << endl
		 << "\t\t______________________________________"<<endl
		 << "\t\t|Code |Type of medicine |Price       |" <<endl
		 << "\t\t|-----|-----------------|------------|" <<endl
	     << "\t\t|1.   |AZATHIOPRINE     |RM 250      |" << endl
	     << "\t\t|2.   |CEFOTAXIME       |RM 145      |" << endl
	     << "\t\t|3.   |ANTIPLATELET     |RM 650      |" << endl
	     << "\t\t|4.   |LEVOTHYROXINE    |RM 220      |" << endl
	     << "\t\t|5.   |ABRAXANE         |RM 950      |" << endl
	     << "\t\t|_____|_________________|____________|" <<endl<<endl;
}

//function header for service menu
void displayServiceMenu()
{
	cout << "---------------------------------------------------------------\n";	  	           
	cout << "\t\t      Please enter the service:" << endl
		 << "\t\t______________________________________"<<endl
		 << "\t\t|Code |Type of Service    |Price     |"<<endl
		 << "\t\t|-----|-------------------|----------|"<<endl
	     << "\t\t|1.   |X-RAY              |RM  100   |" << endl
		 << "\t\t|2.   |LABORATORY TEST    |RM   30   |" << endl 
		 << "\t\t|3.   |CHEMOTHERAPHY      |RM 9200   |" << endl
		 << "\t\t|4.   |PHYSIOTHERAPHY     |RM   50   |" << endl
		 << "\t\t|_____|___________________|__________|" <<endl<<endl;
}

//to check validation for service
char checkValid(char check)
{
	while (check != 'Y' && check != 'N' && check!= 'y' && check != 'n')
	{
		cout << "Error. Enter Y or N only . Enter again :";
		cin>>check;
	}
	return check;
}

//function header for types of room
double roomCharges(int roomtypes)
{
	double daily_rates;
	
	//to find the daily rate based on type of room
	if (roomtypes == 1) 
	{
		daily_rates += 400;
		
	}
	
	else if (roomtypes == 2)
	{
		daily_rates += 250;
	}
	
	
	else if (roomtypes == 3)
	{
		daily_rates += 150;
	}
	
	//return value function of room type to the main
	return daily_rates;
}

//function header for hospital stay
double hospitalstay (double room_charges, double day)
{
	return room_charges * day;
}

//function header for surgery charge
double surgeryCharges (int surgerytypes)
{
	double rateSurgery;
	
	//to find payment based on type of surgery
	if (surgerytypes = 1)
	{
		rateSurgery += 40000;
	}
	
	if (surgerytypes == 2)
	{
		rateSurgery += 5000;
	}
	
	if (surgerytypes == 3)
	{
		rateSurgery += 75000;
	}
	
	if (surgerytypes == 4)
	{
		rateSurgery += 20000;
	}
	
	if (surgerytypes == 5)
	{
		rateSurgery += 200000;
	}
	
	//return value function of surgery rate to the main
	return rateSurgery;
}

//function header for pharmacy charge
double pharmacyCharge(int medicationtypes)
{
	//declare rate pharmacy
	double ratePharmacy;
	
	if (medicationtypes == 1)
	{
		ratePharmacy += 250 ;
	}
	if (medicationtypes == 2)
	{
		ratePharmacy += 145 ;
	}
	if (medicationtypes == 3)
	{
		ratePharmacy += 650;
	}
	if (medicationtypes == 4)
	{
		ratePharmacy += 220 ;
	}
	if (medicationtypes == 5)
	{
		ratePharmacy += 950 ;
	}
		
	//return value function of pharmacy rate to the main
	return ratePharmacy;         
}

//function header for service charge
double serviceCharge(int servicetypes)
{
	//declare type of service frequency and rate service of patient get the service
	int frequency;
	double rateService;
	
	//to find payment based on type of service	
	if (servicetypes == 1)
	{
	   cout << "How many time you done this service:";
	   cin >> frequency; //input frequency that you have done for the service
	   rateService += 100 * frequency; //to find the total payment for the type of service
	}
	if (servicetypes == 2)
	{
	   cout << "How many time you done this service:";
	   cin >> frequency; //input frequency that you have done for the service
	   rateService += 30 * frequency; //to find the total payment for the type of service  
	}
	if (servicetypes == 3)
	{
	   cout << "How many time you done this service:";
	   cin >> frequency; //input frequency that you have done for the service
	   rateService += 9200 * frequency; //to find the total payment for the type of service
	}
	if (servicetypes == 4)
	{
	   cout << "How many time you done this service:";
	   cin >> frequency; //input frequency that you have done for the service
	   rateService = 50 * frequency; //to find the total payment for the type of service
	}
	
	//return value function of service rate to the main	
	return rateService;      	           
}

//function header for highest name
string Maxname(string array1[], double array2[], int ARRAY_SIZE)
{
	double max = array2[0];
	string max_name = array1[0];
	
	for (int i = 1; i <ARRAY_SIZE ; i++)
	{
		if (array2[i]> max)
		{
			max = array2[i];
			max_name = array1[i];
		}
		else if (array2[i] == max)
		{
			max = array2[i];
			max_name += ",";
			max_name += array1[i];
		}
	}
	//return name of the highest bill
	return max_name;
}

//function header for highest bill
double Max(string array1[], double array2[], int ARRAY_SIZE)
{
	double max = array2[0];
	
	for (int i = 1; i<ARRAY_SIZE; i++)
	{
		if (array2[i]>max)
		{
			max = array2[i];
		}
	}
	
	//return value of the highest bill
	return max;
}

//function header for lowest name
string Minname(string array1[], double array2[], int ARRAY_SIZE)
{
	double min = array2[0];
	string min_name = array1[0];
	
	for (int i = 1; i <ARRAY_SIZE ; i++)
	{
		if (array2[i] < min )
		{
			min = array2[i];
			min_name = array1[i];
		}
		else if (array2[i] == min)
		{
			min = array2[i];
			min_name += ",";
			min_name += array1[i];
		}
	}
	
	//return name of the lowest bill
	return min_name;
}

//function header for lowest bill
double Min(string array1[], double array2[], int ARRAY_SIZE)
{
	double min = array2[0];
	
	for (int i = 1; i<ARRAY_SIZE; i++)
	{
		if (array2[i]<min)
		{
			min = array2[i];
		}
	}
	
	//return value of the lowest bill
	return min;
}

//function header for get bill
double getBill(double stay_charges, double rateSurgery, double ratePharmacy, double rateService)
{
	double total_cost;
	
	total_cost = stay_charges + rateSurgery + ratePharmacy + rateService;
	
	//return total value of bill
	return total_cost;
}

//function header for display bill
void displayBill (int days, double totalCost, double stay_charges, double rateSurgery, double ratePharmacy, double rateService)                     	                    
{
	cout << "Days Spend in the Hospital    : " << days << endl;
	cout << "Hospital Stay Charges         : " << stay_charges << endl;
	cout << "Surgery Charges               : " << rateSurgery << endl;
	cout << "Pharmacy Charges              : " << ratePharmacy << endl;
	cout << "Service Charges               : " << rateService << endl;
	cout << "_______________________________________________________________" << endl;
	cout << "Total Charges                 :\t" << totalCost <<endl;
	cout << "_______________________________________________________________" << endl;
	
}

//function header for total days
int totalDays(int array[], int ARRAY_SIZE)
{
	int total =0;
	for (int i= 0; i <ARRAY_SIZE; i++)
	{
		total += array[i];
	}
	return total;
}

//function header to calculate total
double cacltotal(double array[], int ARRAY_SIZE)
{
	double total=0;
	for (int i= 0; i<ARRAY_SIZE; i++)
	{
		total += array[i];
	}
	return total;
}
