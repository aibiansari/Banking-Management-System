#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;
//Main Data Structure Linked List Class 1
class db
{
    private:             //Properties of Account Holder
    int acc;
    string name;
    string fname;
    string fone;
    int d, m, y, q;
    string mail;
    char adrs[50];
    string login; 
    string passwd;
    int pin;
    string ans;
    float bal;
    db *next;           //Pointer to store Address of next object
    friend class list;   // to Make class members of class db 'private'
};

//Transaction Activity Data Structure (Dynamic Stack) Class 1
class transac
{
	private:                   //Properties of Transaction Record
	float amnt;
	int sen, rec;
	string dnt;
	transac *prev;             //Pointer to store Address of previous object 
	friend class translist;   // to Make class members of class transac 'private'
};

//Transaction Activity Data Structure (Dynamic Stack) Class 2
class translist
{
	private:               //Head of linked list in Private
	transac *head, *top;
	transac *ptr, *ptrr;
	public:
	translist()
	{
	head = top = NULL;
	}
	
	//Funtion to take appropriate info and make record of a loan or transaction
	void addr(float &amn, int &se, int &re, string &dt)
	{
		transac *tmp = new transac;
		tmp->dnt = dt;
		tmp->amnt = amn;
		tmp->sen = se;
		tmp->rec = re;
		tmp->prev = NULL;
	if(head==NULL)
	{
	head = top = tmp;
    }
    else
    {
	tmp->prev = top;
	top = tmp;
	}
	}
	//Function to show transaction activity of one standard user
	void shoac(int &shoacc)
	{
	int i = 1;
	transac *ptr;
	ptr = top;
    cout << "\n\n\t Showing Transactions \n ==================================" <<endl;
    if(head==NULL)
    {
    	cout << " \n No Transations! \n";
    	return;
	}
	while(ptr!=NULL)
	{
	if(shoacc==ptr->sen || shoacc==ptr->rec)
	{
	cout  << "\n "<< i << ") \n";
	for(int ch=0; ch<36; ch++)
    cout << "-";
    cout << endl;
    cout << " Sender   : " << ptr->sen <<endl;
	cout << " Receiver : " << ptr->rec <<endl;
	cout << " Amount   : Rs. " << ptr->amnt <<endl;
	cout << " Time     : " << ptr->dnt <<endl;
	if(shoacc==ptr->sen)
		cout << " Status   : Sent! ";
	if(shoacc==ptr->rec)
		cout << " Status   : Received! ";
	cout <<endl;
	for(int ch=0; ch<36; ch++)
    cout << "-";
	i++;
	}
	ptr = ptr->prev;
	}
	}
	
	//Function to show all transaction activities for master
	void shom()
	{
	int i = 1;
	transac *ptr;
	ptr = top;
    cout << "\n\n      Showing All Transactions \n ==================================" <<endl;
    if(head==NULL)
    {
    	cout << " \n No Transations! \n";
    	return;
	}
	while(ptr!=NULL)
	{
	cout  << "\n "<< i << ") \n";
	for(int ch=0; ch<36; ch++)
    cout << "-";
    cout << endl;
    cout << " Sender   : " << ptr->sen <<endl;
	cout << " Receiver : " << ptr->rec <<endl;
	cout << " Amount   : Rs. " << ptr->amnt <<endl;
	cout << " Time     : " << ptr->dnt;
	for(int ch=0; ch<36; ch++)
    cout << "-";
	i++;
	ptr = ptr->prev;
	}
	}
};

// Main Data Structure Class 2, This class inherited translist class in order to give info
// to translist class for making transaction activity detail
class list : public translist
{
    private:
    db *head, *tail, *ptr, *chk;  // Head & Tail of main class,a temporary pointer and a pointer for searching list
    char opte;                     // Only one char to be used in whole Class functions and all the menus
    public:

list()  // Constructor of list class to assign head to master account
{
    head = new db;
    head->login = "master";
    head->passwd = "1234";
    head->bal = 10000;
    head->acc = 1234;
    head->next = NULL;
    tail = head;
}

//Registration Module
void reg()
{
    ptr = new db;
    eli:	         //goto statement for re-prompting user after invalid input
    system("CLS");
    cout<< " ********************************** \n";
    cout<< "            Bank System \n";
    cout<< " ********************************** \n\n";
    cout << "\n\t    Registration \n ==================================" <<endl;
    cout << " Enter Your First Name:  ";
    cin >> ptr->name;
    cout << " Enter Your Last Name :  ";
    cin >> ptr->fname;
    cout << " Enter Your Phone No. :  ";
    cin >> ptr->fone;
    cout << " Enter DOB;  Day      :  ";
    cin >> ptr->d;
    cout << "             Month    :  ";
    cin >> ptr->m;
    cout << "             Year     :  ";
    cin >> ptr->y;
    if(ptr->y<=1942 || ptr->y>=2004)
    {
    cout << "\n You are not Eligible ! \n";
    cout << " (1) Try Again   (2) Exit \n =>";
    opte = getche();
    if(opte=='1')
    goto eli; 
    if(opte=='2')
    return;
    goto eli;
    }
    cout << " Enter Your E-mail    :  ";
    cin >> ptr->mail;
    cout << " Enter Your Address   :  ";
    cin.getline(ptr->adrs, 75);             //dev C gives some absurd error so have to use this line twice
    cin.getline(ptr->adrs, 75); 
    cout << "\n Please Confirm Details \n\n";
    cout << " Name    : " << ptr->name << " " << ptr->fname <<endl;
    cout << " Phone   : " << ptr->fone <<endl;
    cout << " DOB     : " << ptr->d << "/" << ptr->m << "/" << ptr->y <<endl;
    cout << " E-Mail  : " << ptr->mail <<endl;
    cout << " Address : "  << ptr->adrs <<endl;
    cout << "\n Press 1 to Continue \n Press 2 to Try again \n =>";
    opte = getche();
    if (opte=='2')
    goto eli;
    ile:
    system("CLS");
    cout<< " ********************************** \n";
    cout<< "            Bank System \n";
    cout<< " ********************************** \n\n";
    cout << "\n\t      Sign Up \n ==================================" <<endl;
    cout << " Enter Your New Username    :  ";
    cin >> ptr->login;
    chk = head;
    while(chk!=NULL)
    {
    if(chk->login==ptr->login)
    {
    cout << " Username Taken! " <<endl;  // this loop checks if entered username already exists in database
    getch();
    goto ile;
    }
    chk = chk->next;
    }
    cout << " Enter Your Login Password  :  ";
    cin >> ptr->passwd;
    cout << " Enter Your 4-digit Pin     :  ";
    cin >> ptr->pin;
    if(ptr->pin<=999 || ptr->pin>9999)           //pin must be 4-digit
    {
    cout << "\n Please Enter a '4-digit' Pin";
    getch();
    goto ile;
    }
    cout << "\n\n Please choose a Security Question \n\n";
    cout << " 1. In what city were you born? \n";
    cout << " 2. What is the name of your Best Friend? \n";
    cout << " 3. What is the name of your favorite Animal? \n";
    cout << " 4. What is your mother's middle name? \n";
    cout << "\n Question no. (1,2,3,4) : ";
    cin  >> ptr->q;
    cout << "\n Answer : ";
    cin >> ptr->ans;
    srand(time(0));                                   //seed for random numbers
    ptr->acc = (rand() % (111111-11111+1)) + 11111;  //a 5-digit random(but not repeating) account number
    ptr->bal = 500;                                 // User is given rs.500 on sign up ;)
    ptr->next = NULL;                              // make place for next object's address
    tail->next = ptr;                             // assigning address of next object to previous
    tail = ptr;
    cout << "\n Please Wait";
    for(int f=0; f<3; f++)
    {
    cout << ".";
    Sleep(600);
    }
    cout <<	"\n\n New Account Registered! " <<endl;
    cout << " Your Account Number   :  " << ptr->acc <<endl <<endl;
    system("PAUSE");
}

//Login Module
int login(string &u, string &p) //Pass by reference used
{
    chk = head;
    while(chk!=NULL)
    {
    if(head->login==u && head->passwd==p)  
    {                                      //Double checks master account
    if(head->acc==1234)                   //First login and passwd and then master account number which is hard coded
    {
    cout << "\n Logged in as Master";
    for(int g=0; g<3; g++)
    {
    cout << ".";
    Sleep(600);
    }
    master();
    return 1234; 	
    }	
    }
    if(chk->login==u && chk->passwd==p)    // Authenticates user after searching for login and passwd in same object
    {
    cout << "\n Logged in Successfully";
    for(int g=0; g<3; g++)
    {
    cout << ".";
    Sleep(600);
    }
    stduser(chk->acc);
    return 1234;
    }
    chk = chk->next;
    }
    cout << "\n Username or Password Incorrect! \n\n";
    Sleep(450);
    return 0;
}

//Master Panel Module
int master()
{
    while(1)
    {
    system("CLS");
    system("Color 0A");
    cout<< " ********************************** \n";
    cout<< "            Bank System \n";
    cout<< " ********************************** \n\n";
    cout << "\n            Master Panel " <<"\n ==================================" <<endl;
    cout<<endl;
    cout<< " 1) Check Bank Reserve " <<endl;            //Master Panel Menu
    cout<< " 2) See all Accounts " <<endl;
    cout<< " 3) See all Transactions " <<endl;
    cout<< " 4) Extend Bank Reserve " <<endl;
    cout<< " 5) Account Settings" <<endl;
    cout<< " 6) Log Out" <<endl;
    cout<< "\n Please choose one of the options : ";
    opte = getche();
    switch (opte) 
    {
    case '1':
    {
    cout << "\n\n * Bank Balance = Rs. " << head->bal <<" *"<<endl;
    getch();
    break;
    }
    
    case '2':
    {
    seelist();         //fn to see all registered accounts
    system("PAUSE");
    break;
    }
    
    case '3':
    {
    translist::shom();   //fn to call show master (shom) fn of inherited class translist
    getch();            //To see all the transactions of all accounts 
    break;
    }
    case '4':
    {
    float depin;
    cout << "\n\n\t     Bank Reserve \n ==================================" <<endl;
    cout << " Deposit Amount = ";
    cin >> depin;
    cout << "\n * Depositing Rs. " << depin << " to Bank Reserve * ";
    cout << "\n\n   (1) Continue \t (2) Cancel \n   => ";
    opte = getche();
    if(opte=='1')
    {
    head->bal += depin;      //Master can add almost infinite amount, limit not applied 
    cout << "\n\n * New Bank Reserve = Rs. " << head->bal << " * ";
    getch();
    }
    break;
    }
    
    case '5':
    {
    system("CLS");
    system("Color 0A");	
    cout<< " ********************************** \n";
    cout<< "            Bank System \n";
    cout<< " ********************************** \n\n";
    cout << "\n\t  Account Settings \n ==================================" <<endl;
    cout<< " 1) Change Password  " <<endl;    //Master can only change its account password
    cout<< " 2) Go Back          " <<endl;
    cout<< " => ";
    opte = getche();
    switch(opte)
    {  
    case '1':
    {
    string pw;
    cout << " Old Password : " << head->passwd <<endl;     //Updates Master's Password
    cout << "\n (1) Change \t (2) Cancel \n => ";
    opte = getche();
    if(opte=='1')
    {
    cout << " New Password : ";
    cin >> pw;
    if(pw == head->passwd)
    {
    	cout << " Same Password! \n Not Changed!" <<endl;
    	getch();
	}
	else
	{
	head->passwd = pw;
    cout << " Password Saved!" <<endl;
    getch();	
    }
    }
    break;
    }
    
    case '2': //Simply goes back into previous menu
    break;
    
    default:
    break;
    }
    break;
    }
    
    case '6':
    {
    cout<< "\n Are you sure (Y/N) \n => ";
    opte = getche();
    if(opte=='Y' || opte=='y')
    return 0;
    break;
    }
    
    default:
    break;
    }
    }
}

//Standard User Panel
int stduser(int std) //Pass by Reference not used because chk->acc is affected during this fn's execution
{
    db *chkr;	    // We already declared a chk pointer for searching but here 2 pointers are needed side by side to search
    int rec;       // and authenticate both sender's and receiver's information
    float depin;  
    int tpw;      //temporary variables to store and confirm input, their lifespan is as long as the fn is called
    time_t dt;
    chk = head;
    while(chk!=NULL)
    {
    if(chk->acc==std)
    {
    while(1)
    {
    system("CLS");
    system("Color 0B");
    cout<< " ********************************** \n";
    cout<< "            Bank System \n";
    cout<< " ********************************** \n\n";
    cout << "\n            Welcome Back " <<"\n ==================================   ";
    cout << " Logged in as : " << chk->name << " " << chk->fname<< endl;
    cout<<endl;
    cout<< " 1) Check Account Balance  " <<endl;
    cout<< " 2) Make a Transaction  \t\t Type 'p' to play" <<endl; // Standard User Main Menu
    cout<< " 3) More Options         \t\t    a game and " <<endl;
    cout<< " 4) Account Settings      \t\t     win Cash!" <<endl;
    cout<< " 5) Log out " <<endl;
    cout<< "\n Please choose one of the options : ";
    opte = getche();
    switch (opte) 
    {
    case '1':
    {
    cout << "\n\n * Your Bank Balance = Rs. " << chk->bal <<" *"<<endl;
    getch();
    break;
    }
    
    case '2':
    {
    depin = 0;
    cout << "\n\n\t  Transaction Panel \n ==================================" <<endl;
    cout << " Enter Receiver Acc # ";
    cin >> rec;
    chkr = head;
    while(chkr!=NULL)
    {
    if(rec==chkr->acc && rec!=head->acc && rec!=chk->acc)  //Confirms that receiver's acc exists and not equal to sender's or master's acc
    {
    cout << " Enter Amount  : ";
    cin >> depin;
    if(depin>=chk->bal || depin<=0)
    {
    cout << "\n Insufficient Funds! \n Your Balance = Rs. " << chk->bal;
    }
    else
    {
    cout << " Receiver Name : " << chkr->name << " " << chkr->fname;
    cout << "\n\n (1) Proceed    (2) Cancel \n =>";
    opte = getche();
    if(opte=='1')
    {
    cout << "\n Enter Your 4-digit Pin : ";
    cin >> tpw;
    if(chk->pin==tpw)
    {
    dt = time(0);           // sets dt = current time
    char *l = ctime(&dt);  // assings char pointer(array of char) to current time with appropriate format
    string str(l);        // assigns a string str to char pointer because parsing string to transac fn is easy
    chk->bal  -= depin;
    chkr->bal += depin; //Amount is deducted from sender's and added to receiver's
    cout << "\n Processing";
    for(int y=0; y<3; y++)
    {
    cout << ".";
    Sleep(500);
    }
    cout << endl;
    for(int ch=0; ch<45; ch++)
    cout << "-";
    cout << endl;
    cout << " * Receiver's Acc  : " << chkr->acc <<endl;          //Transaction Receipt
    cout << " * Receiver's Name : " << chkr->name << " " << chkr->fname <<endl;
    cout << " * Sender's Acc    : " << chk->acc <<endl;
    cout << " * Sender's Name   : " << chk->name << " " << chk->fname <<endl;
    cout << " * Amount          : Rs. " << depin <<endl;
    cout << " * Date & Time     : " << ctime(&dt);
    for(int ch=0; ch<45; ch++)
    cout << "-"; 
    translist::addr(depin, chk->acc, chkr->acc, str); 
    }        //addresses of trx amount, sender, receiver and time passed to add trx record(addr) fn of translsit class
    else
    {
    cout << " Incorrect Transaction Password! ";
    }
    }
    }
    }
    chkr = chkr->next;
    }
    if(depin==0)
    cout << "\n Account Does Not Exist !";
    getch();
    break;
    }
    
    case '3':
    {
    system("CLS");
    system("Color 0B");	
    cout<< " ********************************** \n";
    cout<< "            Bank System \n";
    cout<< " ********************************** \n\n";
    cout << "\n\t    More Options     \n ==================================" <<endl;
    cout << " 1) Transaction Activity " <<endl;         //More Options Menu of Standard User Panel
    cout << " 2) Take Loan From Bank  " <<endl;
    cout << " 3) Order Credit Card    " <<endl;
    cout << " 4) Go Back              " <<endl;
    cout<< "\n Please choose one of the options : ";
    opte = getche();
    switch (opte)
    {
    case '1':
    {
    translist::shoac(chk->acc);        //Show transaction activity (shoac) fn to show trx activity of current user only
    getch();
    break;
    }
    
    case '2':
    {
    int pini;
    cout << "\n\n\t     Bank Loan \n ==================================" <<endl;
    cout << " Loan Amount  = ";
    cin >> depin;
    if(depin>head->bal-500 || depin<=0)           //if amount is more than there is in bank-500, loan wont be given
    {
    cout << " Max Amount = " << head->bal - 500;  //shows max amount user can take loan of 
    getch();
    }
    else
    {
    cout << "\n Taking Loan from Bank : " << depin <<endl;
    cout << "\n (1) Continue \t (2) Cancel \n => ";
    opte = getche();
    if(opte=='1')
    {
    cout << " Enter 4-digit Pin: ";           //4-digit pin confirmation before loan
    cin >> pini;
    if(pini==chk->pin)
    {
    cout << "\n Processing";
    for(int z=0; z<3; z++)
    {
    cout << ".";
    Sleep(500);
    }
    cout <<endl;
    for(int ch=0; ch<41; ch++)
    cout << "-";
    cout << " \n * Account No. : " << chk->acc <<endl;
    cout << " * Loan Amount : Rs. " << depin <<endl;
    head->bal -=depin;
    chk->bal += depin;
    dt = time(0);            //Explained Above
    char *l = ctime(&dt);
    string str(l);
    cout << " * New Balance : Rs. " << chk->bal <<endl;
    cout << " * Date & Time : " << ctime(&dt);
    for(int ch=0; ch<41; ch++)
    cout << "-"; 
    translist::addr(depin, head->acc, chk->acc, str);     //Loan details passed to addr fn for trx activity record
    }
    else
    {
    cout << " Incorrect Pin!";
    }
    getch();
    }
    } 
    break;
    }
    
    case '3':
    {
    ccard(chk->acc);   //calls a fun little funtion of generating a random credit card on every call
    getch();
    break;
    }
    
    case '4':
    break;
    
    default:
    break;
    }
    break;
    }
    
    case '4':
    {
    system("CLS");
    system("Color 0A");	
    cout<< " ********************************** \n";
    cout<< "            Bank System \n";
    cout<< " ********************************** \n\n";
    cout << "\n\t  Account Settings \n ==================================" <<endl;
    cout<< " 1) Change Username  " <<endl;
    cout<< " 2) Change Password  " <<endl;       //Account Settings Menu of Standard User Panel
    cout<< " 3) Change Pin-code     " <<endl;
    cout<< " 4) See Account Info " <<endl;
    cout<< " 5) Close My Account    " <<endl;
    cout<< " 6) Go Back          " <<endl;
    cout<< " => ";
    opte = getche();
    switch(opte)
    {
    case '1':
    {
    string tu;
    bool dne = true;
    cout << "\n Old Username : " << chk->login <<endl;
    cout << "\n (1) Change \t (2) Cancel \n => ";
    opte = getche();
    if(opte=='1')
    {
    cout << " New Username : ";
    cin >> tu;
    chkr = head;
    while(chkr!=NULL)
    {
    if(chkr->login==tu)            //Confirms new username does not exist in db already
    {
    cout << " Username already exists!";
    dne = false;
    getch();
    }
    chkr = chkr->next;
    }
    if(dne == true)
    {
    chk->login = tu;
    cout << " Username Saved!" <<endl;
    getch();
    }
    }
    break;
    }
    
    case '2':
    {
    string pww;
    cout << " Old Password : " << chk->passwd <<endl;
    cout << "\n (1) Change \t (2) Cancel \n => ";
    opte = getche();
    if(opte=='1')
    {
    cout << " New Password : ";
    cin >> pww;
    if(pww == chk->passwd)
    {
    	cout << " \n Same Password! \n Not Changed!" <<endl;
    	getch();
	}
	else
	{
		chk->passwd = pww;
    cout << " Password Saved!" <<endl;
    getch();	
	}
    }
    break;
    }
    
    case '3':
    {
    int tiemp;
    cout << " Old Pin : " << chk->pin <<endl;
    cout << "\n (1) Change \t (2) Cancel \n => ";
    opte = getche();
    if(opte=='1')
    {
    cout << " New Pin : ";
    cin >> tiemp;
    if((tiemp<=999 || tiemp>=9999) || tiemp == chk->pin)          //Confirms if pin if more or less than 4-digit
    {
    cout << "\n Please Enter a different '4-digit' Pin \n";
    cout << " Pin Not Changed !";
    getch();
    }
    else
    {
    chk->pin = tiemp;
    cout << " 4-digit Pin Saved!" <<endl;
    getch();	
    }
    }
    break;
    }
    
    case '4':
    {                                //Shows user his/her basic info
    cout << "\n\t   Account Info \n ==================================" <<endl;
    cout << " Name    : " << chk->name << " " << chk->fname <<endl;
    cout << " Phone   : " << chk->fone <<endl;
    cout << " DOB     : " << chk->d << "/" << chk->m << "/" << chk->y <<endl;
    cout << " E-Mail  : " << chk->mail <<endl;
    cout << " Address : "  << chk->adrs <<endl <<endl;
    system("PAUSE");
    break;
    }
    
    case '5':
    {
    cout << "\n Are You Sure ? (Y/N): ";
    opte = getche();
    if(opte=='Y' || opte=='y')
    {
    close(chk->acc);
    return 0;
    }
    break;
    }	
    
    case '6':
    break; 
    
    default:
    break;	
    }
    break;
    }
    
    case '5':	
    {
    cout<< "\n Are you sure (Y/N) \n => ";
    opte = getche();
    if(opte=='Y' || opte=='y')
    return 0;
    break;
    }
    
    case 'p':
    {
    game(chk->bal);      //if user presses p in main standard user menu, its prompts to a cash-prize game
    break;
    }
  
    
    default:
    break;
    }
    }
    }
    chk = chk->next;
    }
}

//Game present in Standard User Panel
int game(float &accbal) //account balance address passed to game function for earning or losing cash
{
    int no,tr;
    int guess;
    srand(time(0));               //Seed for random number so that random numbers start generating from new point everytime
    guess=(rand() % (10-1)) + 1;  //Generates a no between 1-10
    system("CLS");
    system("Color 0B");	
    cout<< " ********************************** \n";
    cout<< "            Bank System \n";
    cout<< " ********************************** \n\n";
    cout << "\n\t    Guess Game \n ==================================" <<endl;
    cout<<"\n Guess the number between 1 and 10 \n for a chance to win upto Rs. 100 \n => ";
    for(tr=1;tr<=3;tr++)
    {
    cin>>no;
    if(guess==no)
    {
    cout<<"\n Yay! You guessed the number " << guess << " right!";
    cout<<"\n In " << tr << " turns";
    if(tr==1)
    {
    head->bal -= 100;
    accbal += 100;
    cout << " You Won Rs. 100!";
    getch();
    return 0;
    }
    if(tr==2)
    {
    head->bal -= 50;
    accbal += 50;
    cout << " You Won Rs. 50!";
    getch();
    return 0;
    }
    if(tr==3)
    {
    head->bal -= 25;
    accbal += 25;
    cout << " You Won Rs. 25!";
    getch();
    return 0;
    }
    }
    else if(guess>no)
    {
    cout<<"\n Number is Higher, Turns left: "<<3-tr;
    if(3-tr>0)
    {
    cout<<"\n Try again \n => ";
    }
    }
    else if(guess<no)
    {
    cout<<"\n Number is Lower, Turns left: "<< 3-tr;
    if(3-tr>0)
    {
    cout<<"\n Try again \n => ";
    }
    }
    }
    if(guess!=no)
    {
    cout<<"\n\n Better Luck Next Time!";
    cout<<"\n The Number was "<<guess;
    getch();
    }
}
//A function to generate a credit card by random numbers
int ccard(int &ccnn) // Address of user's account(to be printed on card)
{
cout << "\n\n Credit Card for Acc # " << ccnn <<endl;
cout << " "<< char(218);      
for(int i=0; i<21; i++){cout << char(196);}      
cout << char(191) << endl;
cout << " "<< char(179) << "  #" << ccnn << "             "<< char(179) << endl;
cout << " "<< char(179) << "                     " << char(179) << endl;        //Some ASCII characters used to make a single line box
cout << " "<< char(179) << " "<< (rand() % (10000-1000)) + 1000 << " ";
cout << (rand() % (10000-1000)) + 1000 << " ";
cout << (rand() % (10000-1000)) + 1000 << " ";   // Produces 16 random digits
cout << (rand() % (10000-1000)) + 1000 << " ";
cout << char(179) << endl;
cout << " "<< char(179) << "                     " << char(179) << endl;
cout << " "<< char(179) << "           cvv = "<< (rand() % (1000-100)) + 100 << " "<< char(179) << endl;
cout << " "<< char(192);                         //Produces 3 random digits as cvv
for(int i=0; i<21; i++){cout << char(196);}      
cout << char(217) << endl;
}

//Quick Balance Module
int QB(int &acnn, int &pnn) //Reference of entered acc no and pin passed
{
    chk = head;
    while(chk!=NULL)
    {
    if(chk->acc==acnn && chk->pin==pnn && chk->acc!=head->acc)  //Checks if acc and pin exist and match and are not equal to master's acc
    return chk->bal;  //Function takes acc and pin and returns balance
    chk = chk->next;
    }
    cout << "\n Incorrect Details!";
    Sleep(750);
    return 0; 
}

//Function to be called when user forgets Password
int reset()
{
    string uans;
    system("CLS");
    cout<< " ********************************** \n";
    cout<< "            Bank System \n";
    cout<< " ********************************** \n\n";
    cout << "\n\t   Password Reset \n ==================================" <<endl;
    cout << " Enter Username   :  ";
    cin >> uans;
    chk = head;
    while(chk!=NULL)
    {
    if(chk->login==uans && chk->login!=head->login) //Checks if username exists in db and not equal to master's login
    {
    cout << "\n Username Found! \n" <<endl;
    if (chk->q==1)
    cout << " In what city were you born? ";
    if (chk->q==2)
    cout << " What is the name of your Best Friend? ";
    if (chk->q==3)
    cout << " What is the name of your favorite Animal? ";  //The Security Question that user chose on Registration was saved
    if (chk->q==4)                                         //Now that single word answer must be used to recover password
    cout << " What is your mother's middle name? ";          
    takk:
    cout << "\n Answer : ";
    cin >> uans;
    if(uans==chk->ans)        //If answer matches with the answer that was saved during registration New password windows pops
    {
    cout << "\n Enter New Password: ";
    cin >> chk->passwd;
    cout << "\n Password Reset Successfully! \n ";
    cout << "\n Redirecting";
    for(int f=0; f<3; f++)
    {
    cout << ".";
    Sleep(600);
    }
    return 0;
    }
    if(uans!=chk->ans)      //If Answer does not match, user is thrown into Program's Main Menu and not Standard User Menu
    {
    cout << "\n Incorrect Answer! \n";
    cout << " 1 to Try Again \n 2 to Exit \n => ";
    opte = getche();
    if(opte=='1')
    {
    goto takk;
    }
    return 0;
    }
    }
    chk = chk->next;
    }
    cout << " Sorry Username Not Found!";  //After searching whole db, if username is not found
    getch();
}

//A function for master panel only to see all the registered accounts
int seelist()
{
    system("CLS");
    system("Color 0A");
    int i = 1;
    chk = head;
    cout<< " ********************************** \n";
    cout<< "            Bank System \n";
    cout<< " ********************************** \n\n";
    cout << "\n\t   All Accounts \n ==================================" <<endl;
    while(chk!=NULL)
    {
    if(chk->acc== 1234)
    {
    cout << " "<< i << ") \n";
    cout << " Account # " << chk->acc  << endl;
    cout << " Name    : " << chk->login << endl;
    cout << endl;
    i++;
    chk = chk->next;
    if(chk==NULL)
    return 0;                                //Simply the whole database is laid down on screen
    }
    cout << " "<< i << ") \n";
    cout << " Account # " << chk->acc << endl;
    cout << " Name    : " << chk->name << " " << chk->fname << endl;
    cout << " Mail    : " << chk->mail << endl;
    cout << " Phone   : " << chk->fone << endl;
    cout << " Address : " << chk->adrs <<endl;
    i++;
    cout <<endl;
    chk = chk->next;
    } 
}

//Function for standard user only to close account
int close(int ac) //acc number of user is passed
{
    db *del, *tmp;
    tmp = head;
    del = tmp;             //Some temporary pointers
    while(tmp!=NULL)
    {
    if(tmp->acc==ac && tmp->acc!=head->acc)
    {
    system("CLS");
    system("Color 0B");
    string ansi;
    cout<< " ********************************** \n";
    cout<< "            Bank System \n";
    cout<< " ********************************** \n\n";
    cout << "\n\t  Account Deletion \n ==================================" <<endl;
    cout << " Answer your Security Question \n\n";
    if (tmp->q==1)
    cout << " In what city were you born? ";                //Security Question asked as a security measure before closing account
    if (tmp->q==2)
    cout << " What is the name of your Best Friend? ";
    if (tmp->q==3)
    cout << " What is the name of your favorite Animal? ";
    if (tmp->q==4)
    cout << " What is your mother's middle name? ";
    aki:
    cout << "\n Answer : ";
    cin >> ansi;
    if(ansi==tmp->ans)
    {
    head->bal += tmp->bal;
    del->next = tmp->next;
    if(tmp->acc == tail->acc)
    {
    	tail = del;
	}
	delete tmp;
    cout << "\n ACCOUNT CLOSED! We are sorry to see you go...";
    getch();
    return 0;
    }
    if(ansi!=tmp->ans)
    {
    cout << "\n Incorrect Answer! \n";
    cout << " 1 to Try Again \n 2 to Exit \n => ";
    opte = getche();
    if(opte=='1')
    goto aki;
    return 0;
    }
    }
    del = tmp;
    tmp = tmp->next;
    }
}
};

//Main Menu
int main ()
{
    list entri;
    translist tlist;       //Initial objects of both databases 
    char opt;             // One char object to be used in whole main menu for selections
    int ind;             // int ind to be for storing some int values during main menu 
    while(1)
    {
    system("CLS");
    system("Color 0A");
    cout<< " ********************************** \n";
    cout<< "            Bank System \n";
    cout<< " ********************************** \n\n";
    cout << "\n\t     Main Menu \n ==================================" <<endl;
    cout<< " 1) Account Login" <<endl;
    cout<< " 2) Account Sign Up" <<endl;
    cout<< " 3) Quick Balance" <<endl;
    cout<< " 4) About Us" <<endl;
    cout<< " 5) Exit" <<endl;
    cout<< "\n Please choose one of the options : ";
    opt = getche();
    switch (opt) 
    {
    case '1':
    {
    string usr, passwd;
    ind = 0;
    acr:	     //goto statement for trying login again
    system("CLS");
    system("Color 0B");	
    cout<< " ********************************** \n";
    cout<< "            Bank System \n";
    cout<< " ********************************** \n\n";
    cout << "\n\t   Account Login \n ==================================" <<endl;
    cout<< "\n Username = ";
    cin>> usr;
    cout<< " Password = ";
    cin >> passwd;
    ind = entri.login(usr, passwd);      //usr and passwd addresses passed to login fn and ind if returned for confirmation.
    if(ind==0)
    {
    cout << " 1 to Try Again \n 2 to Go to Main Menu \n 3 Forgot Password \n => ";
    opt = getche();
    switch(opt)
    {
    case '1':
    goto acr;
    break;
    case '2':
    break;
    case '3':
    entri.reset();  //Reset Password function
    break;
    default:
    goto acr;
    break;
    }
    }
    break; 
    }
    
    case '2':
    {
    system("CLS");
    system("Color 0B");
    entri.reg();        //Registration Module called
    break;
    }
    
    case '3':
    {
    ind = 0;
    int acn, pn;    //for account number and 4-digit pin
    acnpn:      
    system("CLS");
    system("Color 0B");
    cout<< " ********************************** \n";
    cout<< "            Bank System \n";
    cout<< " ********************************** \n\n";
    cout << "\n\t   Quick Balance   \n ==================================" <<endl;
    cout << " Enter Account # ";
    cin >> acn;
    cout << " Enter Pin no. : ";
    cin >> pn;
    ind = entri.QB(acn, pn);   //acc no and pin addresses passed to QB fn and ind is returned as balance of given account
    if(ind!=0)
    {
    cout << " \n * Your Balance = Rs. " << ind << " *";
    getch();
    }
    if(ind==0)              //Logical error exists e.g if user's balance=0, then the program may act like if user's acc doesnt exist
    {
    cout << "\n 1 to Try Again \n 2 to Go to Main Menu \n => ";
    opt = getche();
    if(opt == '1')
    goto acnpn;
    }
    break;
    }
    
    case '4':
    {
    system("CLS");
    system("Color 0B");
    cout<< " ********************************** \n";
    cout<< "             Bank System \n";
    cout<< " ********************************** \n\n";
    cout << "\n\t      About Us \n ==================================" <<endl;
    cout << "\n Group # 5: \n" <<endl;
    cout << " Member 1  \n Muhammad Abdullah \n https://github.com/aibiansari \n" <<endl;
    cout << " Member 2  \n Inam ul Huq \n Roll # https://github.com/inam101001 \n" <<endl;
    cout << " Member 5  \n Kamran Shahzad \n Roll # https://github.com/iKamranShahzad \n" <<endl;
    system ("PAUSE");
    break;
    }
    
    case '5':
    {
    cout<< "\n Are you sure (Y/N)";
    opt = getche();
    if(opt=='Y' || opt=='y')
    return 0;
    else
    break;
    }
    
    default:
    {
    cout << "\n Invalid Input !";
    getch();
    break;
    }
    }
    }
}


