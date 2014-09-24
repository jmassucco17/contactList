/********************************************************************
 Contact List 2014, copyright 2014, Christian Lozano & James Massucco
 Program should be installed in isolated folder (mechanism for this should be developed)
 Program data can persist between uses through use of data file
 Program failures will be logged in log file for specific run
 Program can store up variable number of contactCards (should create mechanism for dynamic growth or shrinkage of # of cards)
 
 ********************************************************************/
#include "contactList.h" //JAMES - put all #include's in contactList.h
using namespace std;
typedef struct ContactCard { //declaring use of ContactCard of type struct
    string firstname;
    string lastname;//JAMES - added seperate first and last names (maybe add nickname and diff types of contact info)
    string contact;
    string wnum;
    string residence;
    int numb;
} contactCard;

int main() {
    int write_index, print_index, action_flag, cardArraySize; // declaring use of integers
    cardArraySize = 12;
    ContactCard contactCards[cardArraySize]; //declaring array of size cardArraySize (default 12)
    action_flag = 0; //assigning value to int action_flag
    write_index = 0; //assigning value to int write_index
    print_index = 0; //assigning value to int print_index
    
    cout << "Any letter to display contacts\n0 to exit module\n\nOr enter 1 to create contact: ";
    cin >> action_flag;
    if (action_flag == 0){
        cout << "\nNo contacts in system, thanks for utilizing my services\n\n";
        return 0;
    }
    
    while ( (action_flag == 1) && (write_index <= (cardArraySize - 1) ) ) { // declaring the conditions under the while loop will operate
        cout << "\nEnter first name: \n"; //storing name, contact, wnumb, role
        cin >> contactCards[write_index].firstname;
        cout << "\nEnter last name: \n"; //storing name, contact, wnumb, role
        cin >> contactCards[write_index].lastname;
        cout << "Prefered contact: \n";
        cin >> contactCards[write_index].contact;
        cout << "Residence: \n";
        cin >> contactCards[write_index].residence;
        cout << "W Number: \n";
        cin >> contactCards[write_index].wnum;
        cout << "\nEnter corresponding number\n1 Student\n2 Faculty\n3 Professor: "; //to bypass 3 seperate cases assign value to numb
        cin >> contactCards[write_index].numb;
        cout << "\n\nYou entered the following:\n\n"; //display the current entry
        cout << "Name: " << contactCards[write_index].firstname << " " << contactCards[write_index].lastname << "\n";
        cout << "Contact: " << contactCards[write_index].contact << "\n";
        cout << "Residence: " << contactCards[write_index].residence << "\n";
        cout << "W-Number: " << contactCards[write_index].wnum << "\n";
        if (contactCards[write_index].numb == 1) {
            //use numb to assign role
            cout << "Role: student\n\n";
        }
        else if (contactCards[write_index].numb == 2) {
            cout << "Role: faculty\n\n";
        }
        else if (contactCards[write_index].numb == 3) {
            cout << "Role: professor\n\n";
        }
        write_index++;
        cout << "Any key to display contacts\nOr enter 1 to create new contact: "; // new contact or display and exit
        cin >> action_flag;
        cout << "\n\n";
    }
    
    cout << "Contact List:\n\n";
    write_index--;
    for (print_index = 0; print_index <= write_index; print_index++) {
        //displays all contacts in array
        cout << "Name: " << contactCards[print_index].name << "\n";
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
    cout << "\nThanks for utilizing my services\n\n";
    return 0;
}​
