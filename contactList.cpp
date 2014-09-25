/********************************************************************
 Contact List 2014, copyright 2014, Christian Lozano & James Massucco
 Program should be installed in isolated folder (mechanism for this should be developed)
 Program data can persist between uses through use of data file
 Program failures will be logged in log file for specific run
 Program can store up variable number of contactCards (should create mechanism for dynamic growth or shrinkage of # of cards)
 
 Output data file (contactList_data.txt) should be formatted as follows:
 firstname
 lastname
 contact
 wnum
 residence
 
 next contact
 
 -contacts should be inputted into data file in alphabetical order by last name (for now they will be in random order)
 -when parsing data file, int numb (in ContactCard struct) will be assigned based on a tracker that increments with each contact read
 
 ********************************************************************/

#include "contactList.h" //JAMES - put all #include's in contactList.h
using namespace std;

/////////////////////////////////////////////////////////////////////////
//Declare data types
/////////////////////////////////////////////////////////////////////////

typedef struct ContactCard { //declaring use of ContactCard of type struct
    string firstname;
    string lastname; //JAMES - added seperate first and last names (maybe add nickname and diff types of contact info)
    string contact;
    string wnum;
    string residence;
    int numb;
} contactCard;

////////////////////////////////////////////////////////////////////////
//Declare functions
////////////////////////////////////////////////////////////////////////

void logFileName(string * logfilename);

////////////////////////////////////////////////////////////////////////
//Main Function
////////////////////////////////////////////////////////////////////////

int main() {
    //Creates file objects
    std::fstream readFile, tempFile, logFile; //Create file objects for existing data file, temporary data storage file, and current session log file
    readFile.open( "contactList_data.txt", std::fstream::in ); //opens current data file for read only
	tempFile.open( "temp_datafile.txt" , std::fstream::trunc | std::fstream::out | std::fstream::in); //creates temp datafile to truncate (in case of existing file) and for write only
    
    string logfilename;
    string *ptr;
    ptr = &logfilename;
    logFileName(ptr);
    
    logFile.open( logfilename , std::fstream::app | std::fstream::out ); //creates log file with logfilename (has current date and time, see function) for write, appending to end
    
    
    if ( readFile.eof() ) { //Change to something that indicates whether file is empty
        std::cout << "No existing data was found. You may now add contacts to your list." << std::endl;
        logFile << "No data found. Starting new contact list.\n";
    }
    
    if ( !tempFile.is_open() || !logFile.is_open() ) {
        std::cout << "The temp or log file could not be opened. This may result in program errors.\nPlease quit and restart, and contact your bros James & Christian if the problem persists." << std::endl;
    }
    
    //Creates ints
    int write_index, print_index, action_flag, cardArraySize, save_index; // declaring use of integers
//    cardArraySize = 12;
//    ContactCard contactCards[cardArraySize]; //declaring array of size cardArraySize (default 12)
    ContactCard contactCards[12];
    action_flag = 0; //assigning value to int action_flag
    write_index = 0; //assigning value to int write_index
    print_index = 0; //assigning value to int print_index
    save_index = 0; //assigning value to int save_index
    string junk; //intermediate for reading in numb as a string
    
    //Parses readFile for existing contact list
    if ( readFile.is_open() ) {
        while ( !readFile.eof() ) {
            std::getline(readFile , contactCards[write_index].firstname);
            std::getline(readFile , contactCards[write_index].lastname);
            std::getline(readFile , contactCards[write_index].contact);
            std::getline(readFile , contactCards[write_index].residence);
            std::getline(readFile , contactCards[write_index].wnum);
            std::getline(readFile , junk);
            contactCards[write_index].numb = atoi( junk.c_str() );
            std::getline(readFile , junk); //junks newline char between contacts
            
            write_index++;

        }
        
        readFile.close();
    }
    
    
    cout << "Any letter to display contacts\n0 to exit module\n\nOr enter 1 to create contact: ";
    cin >> action_flag;
    if (action_flag == 0){
        cout << "\nNo contacts in system, thanks for utilizing my services\n\n"; //JAMES - Let's put this in a function
        return 0;
    }
    cout << "Write index is " << write_index << endl;
    while ( (action_flag == 1) && (write_index < cardArraySize ) ) { // declaring the conditions under the while loop will operate
        cin.ignore(1, '\n');
        cout << "\nEnter first name: \n"; //storing name, contact, wnumb, role
        std::getline(cin, contactCards[write_index].firstname, '\n');
        cout << "\nEnter last name: \n";
        std::getline(cin, contactCards[write_index].lastname);
        cout << "Prefered contact: \n";
        std::getline(cin, contactCards[write_index].contact);
        cout << "Residence: \n";
        std::getline(cin, contactCards[write_index].residence);
        cout << "W Number: \n";
        std::getline(cin, contactCards[write_index].wnum);
        cout << "\nEnter corresponding number\n1 Student\n2 Faculty\n3 Professor: "; //to bypass 3 seperate cases assign value to numb
        std::getline(cin, junk);
        contactCards[write_index].numb = atoi( junk.c_str() );
        cout << "\n\nYou entered the following:\n\n"; //display the current entry
        cout << "Name: " << contactCards[write_index].firstname << " " << contactCards[write_index].lastname << "\n";
        cout << "Contact: " << contactCards[write_index].contact << "\n";
        cout << "Residence: " << contactCards[write_index].residence << "\n";
        cout << "W-Number: " << contactCards[write_index].wnum << "\n";
        
        switch (contactCards[write_index].numb) {
            case 1:
                cout << "Role: student\n\n";
                break;
            case 2:
                cout << "Role: faculty\n\n";
                break;
            case 3:
                cout << "Role: professor\n\n";
                break;
        }
        
        logFile << "New contact created successfully. Contact first name is " << contactCards[write_index].firstname << ".\n";
        write_index++;
        cout << "Any key to display contacts\nOr enter 1 to create new contact: "; // new contact or display and exit
        cin >> action_flag;
        cout << "\n\n";
    }
    
    cout << "Contact List:\n\n";
    write_index--;
    for (print_index = 0; print_index <= write_index; print_index++) {
        //displays all contacts in array
        cout << "First Name: " << contactCards[print_index].firstname << "\n";
        cout << "Last Name: " << contactCards[print_index].lastname << "\n";
        cout << "Contact: " << contactCards[print_index].contact << "\n";
        cout << "Residence: " << contactCards[print_index].residence << "\n";
        cout << "W-Number: " << contactCards[print_index].wnum << "\n";
        if (contactCards[print_index].numb == 1) {
            cout << "Role: student\n\n";
        }
        else if (contactCards[print_index].numb == 2) {
            cout << "Role: faculty\n\n";
        }
        else if (contactCards[print_index].numb == 3) {
            cout << "Role: professor\n\n";
        }
    }
    cout << "\nThanks for utilizing my services\n\n"; //JAMES - add option to recirculate to adding contacts after viewing all
    
    //Save all data to temp file
    if ( !tempFile.is_open() ) {
        std::cout << "Unable to open temp file, no data will be saved this session" << std::endl; //Make function from this when more frequent data saving is implemented
    } else {
        for (save_index = 0; !contactCards[save_index].firstname.empty(); save_index++) {
            
            cout << "Copying contact to tempfile" << endl;
            tempFile << contactCards[print_index].firstname << "\n";
            tempFile << contactCards[print_index].lastname << "\n";
            tempFile << contactCards[print_index].contact << "\n";
            tempFile << contactCards[print_index].residence << "\n";
            tempFile << contactCards[print_index].wnum << "\n";
            tempFile << contactCards[print_index].numb << "\n";
            tempFile << "\n";
            
        }
    }
    
    //Copy temp file into readFile (including reopening readfile)
    fstream saveFile;
    saveFile.open( "contactList_data.txt" , std::fstream::out | std::fstream::trunc );
    
    tempFile << saveFile.rdbuf();
    logFile << "Temp file copied to contactList_data.txt.\n";
    
    tempFile.close();
    saveFile.close();
    logFile << "Program complete. Return code 0.";
    
    return 0;
} //end of main

////////////////////////////////////////////////////////////////////////
//Definition of logFileName
////////////////////////////////////////////////////////////////////////
             
void logFileName(string * logfilename) {
    time_t rawtime;
    struct tm * timeinfo;
    
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    *logfilename = asctime(timeinfo);
    logfilename->insert(0, "ContactList Log "); //creates name for log file with the current date and time for easy reference
    logfilename->append(".txt");
    
    return;
}
