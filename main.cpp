
#include "university.h"
#include <iostream>

using namespace std;

int main() {
    int choice;

  
    cout << "   WELCOME TO UNIVERSITY UTILITY PORTAL" << endl;
    

  
    do {
        
        displayMenu();
        cin >> choice;


        switch(choice) {
            case 1:
                
                feeStatusFunction();
                break;

            case 2:
               
                attendanceStatusFunction();
                break;

            case 3:
              
                gpaStatusFunction();
                break;

            case 4:
            
              ;
                cout << " Thank you for using the University Utility Portal." << endl;
                cout << "                   Goodbye!" << endl;
                n" << endl;
                break;

            default:
                // Invalid choice handling
                cout << "Invalid choice! Please enter a number between 1 and 4.\n" << endl;
                break;
        }

    } while(choice != 4);  

    return 0;
}
