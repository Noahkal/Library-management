#include <iostream>   // Input/output operations
#include <string>     // String handling
#include <fstream>    // File input/output
#include <sstream>    // String stream processing
#include <iomanip>    // Stream manipulators
#include <cstdlib>    // header for functions such as system("pause") and system("cls")
using namespace std;
struct book  //  book structure
{
    string title;
    string author;
    string book_isbn;
    int copies;
    int MAX_COPIES;
    string genre;
};
struct user // user structure
{
    string fname;
    string sname;
    string password;
    string id_no;
    book borrowed;
};
user arr[10000];
int members = 0; // initializing number of members to zero

int books = 0;  // initializing number of books to zero
book text[10000];

// Function declarations
void rent_file();       // Update rental information to file
void return_file();     // Update return information to file
void delete_user_file();// Delete user information from file
void menu();            // Display the main menu
void delete_user();     // Function to delete user account
void register_User();   // Function to register a new user
void add_Book();        // Function to add and remove a book
void rent_book();        // Function to rent a book
void Return_Book();      // Function to return a book
void display_members();  // Function to display member information
void display_books();    // Function to display book information
void book_managment();   // Function for book managment

int main()
{
	ifstream read1;
    read1.open("default_user");  // open default_user file to read users stored in the file
    if (read1.is_open()) {
    string line1;
    while (getline(read1, line1) && members < 10000) {
        istringstream iss1(line1);
        iss1 >> arr[members].id_no>> arr[members].fname>> arr[members].password>> arr[members].borrowed.copies;   // Read user data line by line
        members++;
                }
        read1.close();
     }
     ifstream read;
     read.open("default_books.txt");  // open default_books.txt file to read books stored in the file
     if (read.is_open()) {
     string line;
     while (getline(read, line) && books < 10000) {
        istringstream iss(line);
        iss >> text[books].title >> text[books].author >> text[books].book_isbn >> text[books].genre >> text[books].copies>>text[books].MAX_COPIES;    // Read books data line by line
        books++;  }
        }
menu();
    return 0;
}

void register_User() {           // function to register a new user
         if (members < 10000)  {
         	bool id_checker=true;
    cout << "Enter your first name: ";
    cin >> arr[members].fname;
    cout << "Enter your last name: ";
    cin >> arr[members].sname;
    cout << "Enter your id number: ";
    cin >> arr[members].id_no;   	
		// Check for duplicate ID numbers
        for(int i=0;i<members;++i) {
            if(arr[members].id_no==arr[i].id_no) {
                id_checker=false;            // id_checker is assigned FALSE if there is someone else with the same ID as the inserted ID number.              
                break;               // Exit loop if a matching ID is found
            }
        }
    if(id_checker){        // Executed if no matching ID number is found
    	
    	    cout << "Enter your password: ";
    cin >> arr[members].password;
    cout << "You have successfully created a user account" << endl << endl;
    ofstream write;
	write.open("default_user",ios::app);     // Save user information to default_user file
    write<<left<<setw(20)<<arr[members].id_no<<setw(20)<<arr[members].fname<<setw(20)<<arr[members].password<<setw(20)<<arr[members].borrowed.copies<<endl;
	write.close();
    members++;
	}
	else
	cout<<" Sorry, this ID belongs to someone else. Please try again."<<endl;
     }
    else
    cout << "Sorry, we are full of customers" << endl;
 }

void add_Book()
{
	int choice;        // integer variable for decision (to add or remove a book)
	int genre_choice;           
    cout<<"Enter 1.To add a Book"<<endl;
    cout<<"      2.To remove a Book"<<endl;
    cin>>choice;
    switch(choice) {
    case 1:{                                 // case to add a book
        if (books < 10000){ 
		here:
        cin.ignore();
        cout<<"Enter Genre : \n1.ROMANCE\n2.ADVENTURE\n3.COMMEDY\n4.NON FICTION"<<endl;
        cin>>genre_choice;    // inserting the genre of the book
        switch(genre_choice){
        case 1:{
            cout<< "Enter title of the book: ";
            cin.ignore();
            getline(cin, text[books].title);

            // loop to change space between words of the title of the book by underscore
            for (int c = 0; c < text[books].title.length(); c++) {
            if (text[books].title[c] == ' ') {
            text[books].title[c] = '_';}
             }
            text[books].genre= "ROMANCE";  // assigning the genre of the book to romance
			break;
	   	}
		case 2:	{
	    	cout << "Enter title of the book: ";
	    	cin.ignore();
            getline(cin, text[books].title);
            for (int c = 0; c < text[books].title.length(); c++) {
            if (text[books].title[c] == ' ') {
            text[books].title[c] = '_';
                  }
             }
            text[books].genre= "ADVENTURE";    // assigning the genre of the book to adventure
			break;
		}
		case 3:{
	    	cout << "Enter title of the book: ";
	        cin.ignore();
            getline(cin, text[books].title);
            for (int c = 0; c < text[books].title.length(); c++) {
            if (text[books].title[c] == ' ') {
            text[books].title[c] = '_';
                }
             }
            text[books].genre= "COMEDY";     // assigning the genre of the book to comedy
			break;
	      }
		case 4:{
		    cout << "Enter title of the book: ";
	    	cin.ignore();
            getline(cin, text[books].title);
            for (int c = 0; c < text[books].title.length(); c++) {
            if (text[books].title[c] == ' ') {
            text[books].title[c] = '_';
                  }
             }
           text[books].genre= "NON_FICTION";   // assigning the genre of the book to non fiction
		   break;
		          }
	       	}
	    cout<<"Enter Author of the book : ";
	    getline(cin,text[books].author);
	    for (int b = 0; b < text[books].author.length(); b++) {
        if (text[books].author[b] == ' ') {
        text[books].author[b] = '_'; }
        }
        cout << "Enter book ISBN (International Standard Book Number): ";
        cin >> text[books].book_isbn;
        cout << "Enter number of copies: ";
        cin >> text[books].copies;
        text[books].MAX_COPIES=text[books].copies;
        ofstream bookss;
        bookss.open("default_books.txt",ios::app);   // adds the new book to default_books file
		string genre;
	    bookss<<left<<setw(40)<<text[books].title<<setw(20)<<text[books].author<<setw(20)<<text[books].book_isbn<<setw(20)<<text[books].genre<<setw(20)<<text[books].copies<<setw(20)<<text[books].MAX_COPIES<<endl;
    	bookss.close();
        books++;
        cout<<"Do you want to add another book "<<endl;
        cout<<"1.YES\n2.NO"<<endl;
        int c;
        cin>>c;
        if(c==1)
        goto here;
        else
        menu();
    }
    else              // executed If the book store's capacity is reached.
    {
        cout << "Sorry, we are facing a shortage of book space" << endl;
    }
	break;
}
    case 2:{    // Case to remove a book if it is considered very old
        bool book_checker=false;                      // boolean varianle to check if the book is available
    	int l;
	    string booktitle;
    	cout<<"Enter the title of the Book : ";
    	cin.ignore();
        getline(cin,booktitle);
        for (int c = 0; c <booktitle.length(); c++) {
        if (booktitle[c] == ' ') {
        booktitle[c] = '_';
              }
          }
       // while loop to find the inserted book
       while(l<books){
	   if(text[l].title==booktitle){
	   book_checker=true;   // assigned true if the book is founded
       break;
	      }
		l++;
       }
       if(book_checker) {   // executed if the book is founded
	   int n;
       cout<<"Are you sure ?"<<endl;
       cout<<"do you want to delete "<<text[l].title<<endl;   // to check if the admin is very sure to delet the book
       cout<<"1.YES\n2.NO"<<endl;
       cin>>n;
       switch(n){
        case 1: {    // case to delete a book
	       for(l;l<books;l++){
	       text[l]=text[l+1];   // Assigning each book by its subsequent book, starting from the chosen book to the last one
	         }
           cout<<"You have succesfully deleted "<<booktitle<<endl;
	       books--;   // decrementing a book from the store

	       ofstream delete_book;
           delete_book.open("default_books.txt"); // opening default_books.txt file to update books in store
		   string genre;
	       for(int r=0;(r<books);r++){
		   if(text[r].copies!=0)
		   delete_book<<left<<setw(40)<<text[r].title<<setw(20)<<text[r].author<<setw(20)<<text[r].book_isbn<<setw(20)<<text[r].genre<<setw(20)<<text[r].copies<<endl;
            	}
	       delete_book.close();
           break;
            }
        case 2:{          // returns to menu function
           	menu();
	        break;}
                               }
                      }
         else {
         	cout<<"Sorry there in no available book by this title. Try again"<<endl;
		 }
              break;
             }
    default: menu(); break;
        }  
}

void rent_book()
{   
    bool valid_password=false; // variable to check whether the password is valid or invalid
    bool author_checker=false;
    bool book_checker=false;
    string user_id;
    string password;
    int c;
    int user=0;  // variable to determine a user
    int n;
	cout<<"Enter your id number : ";
	cin>>user_id;
	    // while loop to find the inserted user id
		while(user<members){
		if(arr[user].id_no==user_id )
		{
		break;
		}
		++user;
	}
	cout<<"Enter your password : ";
	cin>>password;
    if(arr[user].password==password)
      valid_password=true;
	if(valid_password )  // executed if the user is found
	{
		if(arr[user].borrowed.copies<4){
	cout<<"==================================================================="<<endl;
	cout<<"=== Welcome to bookstore "<<arr[user].fname<<" "<<arr[user].sname<<"=========================="<<endl;
	cout<<"==================================================================="<<endl;
	here1:here2:here3:here4:
	cout<<"How do you want to search a book"<<endl;
	cout<<"1. BY TITLE"<<endl<<"2. BY AUTHOR"<<endl<<"3. BACK TO MENU"<<endl;
	cin>>n;
	int a=0;
    switch(n){
        case 1:{
	       string name;
           cin.ignore();
	       cout<<"Enter title of the book : ";
	       getline(cin,name);
		   for (int c = 0; c < name.length(); c++) {
           if (name[c] == ' ') {
           name[c] = '_';  }
             }
		   while(a<books){           // to find the inserted book in the store
		   if(text[a].title==name){
		   book_checker=true;
		   break;}
		   a++; }
           if(book_checker){    //  executed if the book inserted is available in store
           cout<<"Written by : "<<text[a].author<<endl<<endl;
           if(text[a].copies!=0){
        cout<<"|--------------------------------------------------------------------------------|"<<endl;
           cout<<"                    You have succesfully rented "<<text[a].title<<endl;
        cout<<"|--------------------------------------------------------------------------------|"<<endl;
           text[a].copies--;          // decrementing the book in store
           arr[user].borrowed.copies++;      // incrementing number of books brrowed of the individual
           rent_file();
           goto here3;
                 }
           else if (text[a].copies<=0)
	       cout<<"the book has been all rented out"<<endl;
	       rent_book();
            }
           else {  //  executed if the book inserted is not available in store
           cout<<"There is no available book by this title. Please try again"<<endl;
           system ("pause");system("cls");
           goto here1;}
           break;
		}
        case 2:{
	       bool author_checker=false;
           string name1;
           cin.ignore();
	       cout<<"Enter author of the book : ";
		   getline(cin,name1);
		   for (int b = 0; b< name1.length(); b++) {
           if (name1[b] == ' ') {
           name1[b] = '_'; }
              }
	       while(a<books){        // To find the inserted book's author in store.
		   if(text[a].author==name1){
		   author_checker=true;
	       break;}
		   a++;}
           if(author_checker){
           cout<<"The available book by this author is : "<<text[a].title<<endl;
           if(text[a].copies!=0){
        cout<<"|--------------------------------------------------------------------------------|"<<endl;
           cout<<"                    You have succesfully rented "<<text[a].title<<endl;
        cout<<"|--------------------------------------------------------------------------------|"<<endl;
           text[a].copies--;
           arr[user].borrowed.copies++;
           rent_file();
		   goto here4;
		    }
           else if (text[a].copies==0){
	       cout<<"the book has been all rented out"<<endl;
	       	       rent_book();
  }
            }
           else{
           cout<<"There is no available book by this author. Try again "<<endl;
           system ("pause");system("cls");
           goto here2;
            }
           break;
         }
         case 3:system("CLS");menu();break;
        default :{
           cout<<"The value you entered is invalid"<<endl;
           rent_book();
           break;
                 }
            }
         }
    else
   cout<<"You can not borrow more than four books "<<endl;
}
    else {           // executed if the inserted password doesn't match with any of users password
	cout<<"Invalid Id or password. Please try again."<<endl;
    system("pause");system("cls");
	menu();
     }
}

void Return_Book()
{
   int j=0;
   int a=0;
   string id_num;    // variable to check the inserted id
   bool title_checker=false;    // to check if the inserted book is available
   bool check_password=false;    //To check if the inserted password matches one of the user's passwords
   string name3;
   string password3;
   
   	cout<<"Enter your id number : ";
	cin>>id_num;
	    // while loop to find the inserted password user
		while(j<members){
		if(arr[j].id_no==id_num )
		{
		break;
		}
		++j;
	}
	cout<<"Enter your password : ";
	cin>>password3;
    if(arr[j].password==password3)	   // To check if the individual with the inserted ID has a password that matches the inserted password
      check_password=true;

   if(check_password){                 // Executed if there is a user with the inserted password
    cout<<"Welcome "<<arr[j].fname<<" "<<arr[j].sname<<endl;
    cout<<"Enter the name/title of the book you want to return : ";
    cin.ignore();
    getline(cin,name3);
    for(int v=0;v<name3.length();v++) {
    if (name3[v] ==' ') {
    name3[v]='_';}}
	while((text[a].title==name3&&text[a].copies<text[a].MAX_COPIES)){
		title_checker=true;
		break;
	a++;}
	if(title_checker){
    cout<<"Written by : "<<text[a].author<<endl<<endl;
    cout<<"YOU HAVE SUCCESSFULY RETURNED "<<text[a].title<<endl;
    text[a].copies++;
    if(arr[j].borrowed.copies>0)
    arr[j].borrowed.copies--;
    else if(arr[j].borrowed.copies<=0)
    arr[j].borrowed.copies=0;
    return_file();           
}
    else{
    	cout<<"There is no available book named "<<name3<<". OR The book hasn't been yet rented .Please try again."<<endl;
    	system("pause");system("cls");
    	menu();
	}
       }
   else {      // Executed if there is no user with the inserted password
   cout<<"Invalid Id or password. Please try again."<<endl;
   system("pause");system("cls");
  menu();}
}

void display_members(){
	cout<<"------------------------------------------------------------------------------------"<<endl;
	cout<<left<<setw(20)<<"ID"<<setw(20)<<"NAME"<<setw(20)<<"PASSWORD"<<setw(20)<<"NUMBER OF BOOKS BORROWED"<<endl;
	cout<<"------------------------------------------------------------------------------------"<<endl;
	for(int a=0;a<members;a++){
	   if(arr[a+1].fname.empty()){
	    cout<<left<<setw(20)<<arr[a].id_no<<setw(20)<<arr[a].fname<<setw(20)<<arr[a].password<<setw(20)<<arr[a].borrowed.copies<<endl;
	    break;}
		else
		cout<<left<<setw(20)<<arr[a].id_no<<setw(20)<<arr[a].fname<<setw(20)<<arr[a].password<<setw(20)<<arr[a].borrowed.copies<<endl;
	}
}

void display_books()
{
   int display;
   int genre_ide;
   string aut_name;  // string variable to search by author name
   string book_title;        // string variable to search by book title
   cout<<"How do you want to search the Book \n1.By TITLE\n2.By AUTHOR\n3.By GENRE\n4.By DISPLAYING ALL BOOKS\n5.BACK TO MENU"<<endl;
   cin>>display;
   switch(display){
	  case 1:{
		cout<<"Enter book title : ";
		cin.ignore();
		getline(cin,book_title);
		for (int c = 0; c < book_title.length(); c++) {       // for loop to replace space between words by underscore
        if (book_title[c] == ' ') {
            book_title[c] = '_';
                   }
             }
        cout<<"--------------------------------------------------------"<<endl;
		cout<<left<<setw(20)<<"AUTHOR"<<setw(15)<<"ISBN"<<setw(15)<<"GENRE"<<setw(5)<<"COPIES"<<endl;
		cout<<"--------------------------------------------------------"<<endl;
		for(int b=0;b<books;b++){
		if(book_title==text[b].title){
			cout<<left<<setw(20)<<text[b].author<<setw(15)<<text[b].book_isbn<<setw(15)<<text[b].genre<<setw(5)<<text[b].copies<<endl;
		            }
		    }
        cout<<endl; system("pause");
		system("cls");
		display_books();
		break;
	}

	  case 2:{
		cout<<"Enter author name : ";
		cin.ignore();
		getline(cin,aut_name);
		for (int c = 0; c < aut_name.length(); c++) {       // for loop to replace space between words by underscore
        if (aut_name[c] == ' ') {
            aut_name[c] = '_';
                 }
          }
        cout<<"----------------------------------------------------------------------------"<<endl;
		cout<<left<<setw(40)<<"TITLE"<<setw(15)<<"ISBN"<<setw(15)<<"GENRE"<<setw(5)<<"COPIES"<<endl;
		cout<<"----------------------------------------------------------------------------"<<endl;
		for(int b=0;b<books;b++) {    // checking and displaying if there is an author named the inserted author name
		if(aut_name==text[b].author){
			cout<<left<<setw(40)<<text[b].title<<setw(15)<<text[b].book_isbn<<setw(15)<<text[b].genre<<setw(5)<<text[b].copies<<endl;
		}}
		cout<<endl; system("pause");
		system("cls");
		display_books();
		break;
	}
	  case 3:{
	  	string genre_name;
		cout<<"Enter 1.for ROMANCE \n      2.for ADVENTURE\n      3.for COMEDY\n      4.for NON FICTION"<<endl;       // giving choices for the  user to see diiferent books with different genres
		cin>>genre_ide;
		 switch (genre_ide){
		 case 1: genre_name="ROMANCE";break;
		 case 2: genre_name="ADVENTURE";break;
		 case 3: genre_name="COMEDY";break;
		 case 4: genre_name="NON_FICTION";break;
		 }
		 cout<<"---------------------------------------------------------------------------------"<<endl;
		 cout<<left<<setw(40)<<"TITLE"<<setw(20)<<"AUTHOR"<<setw(15)<<"ISBN"<<setw(5)<<"COPIES"<<endl;
		 cout<<"---------------------------------------------------------------------------------"<<endl;
		 for(int b=0;b<books;b++){
		 if(text[b].genre==genre_name)
		 cout<<left<<setw(40)<<text[b].title<<setw(20)<<text[b].author<<setw(15)<<text[b].book_isbn<<setw(5)<<text[b].copies<<endl;
		  }
	     cout<<endl; system("pause");
		 system("cls");
		 display_books();
		 break;
	          }
	  case 4:{   // case that displays all books in the store
		string genre;
	    if(books==0)
	    cout<<" There is no available book"<<endl<<endl;
	    else if(books>0){
	    cout<<"----------------------------------------------------------------------------------------------------------"<<endl;
		cout<<left<<setw(40)<<"TITLE"<<setw(20)<<"AUTHOR"<<setw(20)<<"ISBN"<<setw(20)<<"GENRE"<<setw(20)<<setw(20)<<"COPIES"<<endl;
		cout<<"----------------------------------------------------------------------------------------------------------"<<endl;
    	for(int r=0;(r<books);r++){
		cout<<left<<setw(40)<<text[r].title<<setw(20)<<text[r].author<<setw(20)<<text[r].book_isbn<<setw(20)<<text[r].genre<<setw(20)<<text[r].copies<<endl;
	        }
     	}
		cout<<endl; system("pause");
		system("cls");
     	display_books();
		break;
	  }
	 case 5: menu();break;
     }
}

void delete_user()
{
   bool account_checker=false;
   int n;
   int l=0;
   string name4;
   cout<<"Enter the your password : ";
   cin.ignore();
   getline(cin,name4);
   while(l<members){   // loop to find the user account
   if(arr[l].password==name4){
   account_checker=true;
   break;
	}
   l++;
    }
   if(account_checker){
   if(arr[l].borrowed.copies==0) {      // Executes if the user has returned all books they have rented or if they haven't borrowed a book before
   cout<<"Are you sure ?"<<endl;
   cout<<"do you want to delete your account"<<endl;
   cout<<"1.YES\n2.NO"<<endl;
   cin>>n;
   switch(n){
     case 1: {
	     for(l;l<members;l++){
		 arr[l]=arr[l+1];
        	}
	     cout<<"You have succesfully deleted your account"<<endl;
	     members--;
         delete_user_file();
	     break;
          }
     case 2:{
	     menu();
	     break;
        }
      }
   }
   else if (arr[l].borrowed.copies>=0) {            // Doesn't allow the user to delete their account if they have rented a book
   cout<<"Sorry you didn't returned a book you have rented "<<endl;
         }
    }
   else{
	cout<<"INVALID PASSWORD ";
	cout<<"\nTry again"<<endl;
	menu();     
        }
}

void rent_file()
{
	ofstream rent;
	rent.open("default_user");    // To update member information in the 'default_user' file
	   bool copies_checker=true;
	for(int a=0;a<members;a++)
	{   if(arr[a+1].fname.empty()){
	    rent<<left<<setw(20)<<arr[a].id_no<<setw(20)<<arr[a].fname<<setw(20)<<arr[a].password<<setw(20)<<arr[a].borrowed.copies<<endl;
	    break;}
		else
        rent<<left<<setw(20)<<arr[a].id_no<<setw(20)<<arr[a].fname<<setw(20)<<arr[a].password<<setw(20)<<arr[a].borrowed.copies<<endl;	}
	rent.close();
    ofstream foreal;
    foreal.open("default_books.txt");    // to update books data in default_books file
			string genre;

	for(int r=0;(r<books);r++)
	{
		if(text[r].copies!=0)
			foreal<<left<<setw(40)<<text[r].title<<setw(20)<<text[r].author<<setw(20)<<text[r].book_isbn<<setw(20)<<text[r].genre<<setw(20)<<text[r].copies<<setw(20)<<text[r].MAX_COPIES<<endl;
	}
	foreal.close();
}

void return_file()
{
	ofstream return_book;
	return_book.open("default_user");
	   bool copies_checker=true;
	for(int a=0;a<members;a++)
	{   if(arr[a+1].fname.empty()){
	    return_book<<left<<setw(20)<<arr[a].id_no<<setw(20)<<arr[a].fname<<setw(20)<<arr[a].password<<setw(20)<<arr[a].borrowed.copies<<endl;
	    break;}
		else
		return_book<<left<<setw(20)<<arr[a].id_no<<setw(20)<<arr[a].fname<<setw(20)<<arr[a].password<<setw(20)<<arr[a].borrowed.copies<<endl;
	}
	return_book.close();
    ofstream return_boo;
    return_boo.open("default_books.txt");
			string genre;
	if(books==0)
	return_boo<<" There is no available book"<<endl<<endl;
	else if(books>0){
	for(int r=0;(r<books);r++)
	{
		if(text[r].copies!=0)
		return_boo<<left<<setw(40)<<text[r].title<<setw(20)<<text[r].author<<setw(20)<<text[r].book_isbn<<setw(20)<<text[r].genre<<setw(20)<<text[r].copies<<setw(20)<<text[r].MAX_COPIES<<endl;
	}}
	return_boo.close();
}

void delete_user_file()
{
	ofstream delete_user;
	delete_user.open("default_user");
	   bool copies_checker=true;
	for(int a=0;a<members;a++)
	{   if(arr[a+1].fname.empty()){
	    delete_user<<left<<setw(20)<<arr[a].id_no<<setw(20)<<arr[a].fname<<setw(20)<<arr[a].password<<setw(20)<<arr[a].borrowed.copies<<endl;
	    break;}
		else
		delete_user<<left<<setw(20)<<arr[a].id_no<<setw(20)<<arr[a].fname<<setw(20)<<arr[a].password<<setw(20)<<arr[a].borrowed.copies<<endl;
	}
	delete_user.close();
}

void book_managment(){
	   	here:
		string pass;      // string variable to check the password of admin
		int opt;
		ifstream use_admin;
		use_admin.open("admin.txt");  // open admin file to read admin password

		if(use_admin.is_open()){              // Executed if 'admin.txt' has been created before and contains the admin password
			string admin_pass;
			bool admin_password_check=false;     // To check whether the inserted password is the admin password or not
			use_admin>>admin_pass;
			cout<<"Enter admin password to login : ";
            cin>>pass;
			if(pass==admin_pass){
          	admin_password_check=true;         // Assign true if it matches the admin password

		if(admin_password_check){ her:pick:       // Executed if the inserted password matches the admin password
          	cout<<"ENTER 1. TO ADD OR REMOVE A BOOK FROM STORE "<<endl;
	        cout<<"      2. TO SEE USER STATUS "<<endl;
	        cout<<"      3. BACK TO MENU"<<endl;
	        cin>>opt;
	        switch(opt){
		    case 1: add_Book(); cout<<endl;system("pause");system("cls");goto pick;   break;
	        case 2: display_members(); cout<<endl;system("pause");system("cls");goto her; break;
	        case 3:system("CLS"); menu(); break;
	        default: cout<<"INVALID KEY"<<endl;menu();break;
	             	}
        	}
			  }
        else{      // Executed if the inserted password does not match the admin password.
	    	cout<<"INVALID PASSWORD "<<endl;
           	menu();
			  }
			  use_admin.close();
		}
	else {              //  Executed if the 'admin.txt' file has not been created before, prompting the admin to insert a new password.
		  string admin_password,admin;
			ofstream create_admin;
		    create_admin.open("admin.txt");             // Open the 'admin.txt' file to write the admin password
		    	cout<<"=========================WELCOME TO BOOKSTORE========================="<<endl;
            	cout<<"Enter your(ADMIN) name : ";
            	cin>>admin;
            	cout<<"Enter your new password : ";
	            cin>>admin_password;
	            create_admin<<admin_password;
                create_admin.close();
            	goto here;
		}
}

 void menu()
{
    int opt;
    cout << "============================= MENU =================================" << endl;
    cout << "==                    1. TO CREATE AN ACCOUNT                     ==" << endl;
    cout << "==                    2. TO RENT A BOOK                           ==" <<endl;
    cout<<  "==                    3. TO RETURN A BOOK                         ==" <<endl;
    cout<<  "==                    4. TO DELETE YOUR ACCOUNT                   ==" <<endl;
    cout<<  "==                    5. TO SEARCH BOOKS IN STORE                 ==" <<endl;
    cout<<  "==                    6. FOR BOOK MANAGMENT                       ==" <<endl;
    cout<<  "==                    7. FOR DESCRIPTION OF THE CODE              ==" <<endl;
    cout<<  "==                    ENTER ANY OTHER KEY TO EXIT                 ==" <<endl;
    cout << "====================================================================" << endl;
    cout<<"Enter : ";
    cin >> opt;

    switch(opt){
    	case 1: system("CLS"); register_User(); menu(); break;
    	case 2:	system("CLS"); rent_book(); menu(); break;
    	case 3: system("CLS"); Return_Book(); menu(); break;
    	case 4: system("CLS"); delete_user(); menu(); break;
    	case 5:	system("CLS"); display_books(); menu(); break;
    	case 6: system("CLS"); book_managment(); menu(); break;
    	case 7:{
    		string essay[100];
    		ifstream read;
    		read.open("description.txt");
    		cin.ignore();
    		for(int i=0;!read.eof();i++){
    			getline(read,essay[i]);
    			cout<<essay[i]<<endl;
			}
			read.close();
			cout<<endl;system("pause");
			system("CLS");
			menu();
			break;
		}
    	default:return;break;
	}
}


