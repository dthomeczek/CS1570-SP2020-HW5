// Programmer: Devin Thomeczek
// MST Username: djtpfr
// Section: 101
// Date: 2/28/2020
// File: hw5.cpp
// Purpose: To determine and alter the contents of a locker

#include <iostream>
using namespace std;

struct student_info
{
  int m_locker_num; // Holds student's locker number
  string m_student_name; // Holds student's name
  int m_texts; // Holds student's number of textbooks
  float m_stud_money; // Holds student's amount of money
  bool m_occupied_check = false; // Starts the locker as false
};

int main()
{
  const int LOCKER_RANGE = 101; // Range of locker values
  const int HIGHEST_LOCKER = 201; // Highest locker number
  const char OPTION1 = '1'; // Option 1
  const char OPTION2 = '2'; // Option 2   
  const char OPTION3 = '3'; // Option 3  
  const char OPTION4 = '4'; // Option 4  
  const char OPTION5 = '5'; // Option 5  
  const float WILLIE_STEAL = 150.00; // The amount of money Willie starts
                                     // stealing money at
  const int ROBBED = 0; // Resets items or money to none
  const int SINGLE_TEXT = 1; // Assigns the singular word text for one text

  bool quit = false; // Starts the quit value as false
  char menu_input; // The user's menu input
  float total_lock_mon; // Money of all lockers
  float text_avg = 0; // Average number of texts per locker
  float total_texts = 0; // Total number of texts from all lockers
  int current_lockers = 0; // Currently occupied lockers
  int user_lock_num; // The user's input locker number
  int i = 0; // Counting variable
  student_info student_locker[LOCKER_RANGE]; // An array of possible lockers
  
  // Brief introductory message
  cout << "Welcome to the student locker system!" <<
  endl << endl;

  // 
  for (i = 0; i < LOCKER_RANGE; i++)
  {
    student_locker[i].m_locker_num = i + LOCKER_RANGE;
    student_locker[i].m_occupied_check = false;
  }
  
  do
  {
    // Prompt the user with the menu
    cout << endl;
    cout << "   === Menu ===   " << endl;
    cout << "   ------------   " << endl;
    cout << "1. Add a locker" << endl;
    cout << "2. Print contents of a locker" << endl;
    cout << "3. Output all locker contents" << endl;
    cout << "4. Delete a locker" << endl;
    cout << "5. Quit" << endl << endl;
    
    current_lockers = ROBBED;
    total_texts = ROBBED;
    text_avg = ROBBED;
    // Checks for how many occupied lockers and the average number of texts
    for (i = 0; i < LOCKER_RANGE; i++)
    {
      if (student_locker[i].m_occupied_check == true)
      {
        current_lockers++;
        total_texts += student_locker[i].m_texts;
      }
    }

    if (total_texts != ROBBED)
    {
      text_avg = static_cast<float>(total_texts) / current_lockers;
    }

    cout << "There are " << current_lockers << " occupied lockers." << endl;

    // "Magical code we will learn later"
    cout.setf(ios::fixed);
	  cout.setf(ios::showpoint);
	  cout.precision(2);
    cout << "There are " << text_avg << " average texts per locker." <<
    endl << endl;
    
    cout << "Please select an option from above. (1-5)" << endl;
    cin >> menu_input;

    switch (menu_input)
    {
      case OPTION1:

        // Test for a valid locker number
        do
        {
          cout << "Enter a locker number between 101 and 201: " << endl;
          cin >> user_lock_num;
        } while (user_lock_num < LOCKER_RANGE || user_lock_num > 
        HIGHEST_LOCKER);
        
        
        // Check if the locker is occupied
        if (student_locker[user_lock_num - LOCKER_RANGE].m_occupied_check 
        == false)
        {
          cout << "What is the student's last name?" << endl;
          cin >> student_locker[user_lock_num - 
          LOCKER_RANGE].m_student_name;

          do
          {
            cout << "How many textbooks does the locker contain? (Positive ";
            cout << "values or zero only)" << endl; 
            cin >> student_locker[user_lock_num - LOCKER_RANGE].m_texts;
          } while (student_locker[user_lock_num - LOCKER_RANGE].m_texts
          < ROBBED);
          
          do
          {
            cout << "How much money does the locker contain? (Positive ";
            cout << "values or zero only)" << endl;
            cin >> student_locker[user_lock_num - LOCKER_RANGE].m_stud_money;
          } while (student_locker[user_lock_num - LOCKER_RANGE].m_stud_money
          < ROBBED);

          student_locker[user_lock_num - LOCKER_RANGE].m_occupied_check
          = true;
        }
        else
        {
          cout << endl << "That locker is occupied." << endl;
        }

        total_lock_mon = ROBBED;

        for (i = 0; i < LOCKER_RANGE; i++)
        {
          if (student_locker[i].m_occupied_check == true)
            {
              total_lock_mon += student_locker[i].m_stud_money;
            }
        }
        
        if (total_lock_mon > WILLIE_STEAL)
        {
          for (i = 0; i < LOCKER_RANGE; i++)
          {
            if (student_locker[i].m_occupied_check == true)
            {
              student_locker[i].m_stud_money = ROBBED;
            }
          }
        }
        
        break;

      case OPTION2:
        
        // Check for a valid locker
        do
        {
          cout << "Enter a locker number between 101 and 201: " << endl;
          cin >> user_lock_num;
        } while (user_lock_num < LOCKER_RANGE || user_lock_num > 
        HIGHEST_LOCKER);

        // Check if locker is occupied
        if (student_locker[user_lock_num - LOCKER_RANGE].m_occupied_check 
        == true)
        {
          cout << endl;
          cout << "\tLOCKER CONTENTS\t" << endl;
          cout << "\t---------------\t" << endl;
          cout << student_locker[user_lock_num - LOCKER_RANGE].m_locker_num;
          cout << "\t";
          cout << student_locker[user_lock_num - LOCKER_RANGE].m_student_name;
          cout << "\t"; 

          // Checks for singular or plural text(s)
          if (student_locker[user_lock_num - LOCKER_RANGE].m_texts == 
          SINGLE_TEXT)
          {
            cout << student_locker[user_lock_num - LOCKER_RANGE].m_texts;
            cout << " text";
          }
          else
          {
            cout << student_locker[user_lock_num - LOCKER_RANGE].m_texts;
            cout << " texts";
          }
          
          cout << "\t" << "$";

          // "Magical code we will learn later"
          cout.setf(ios::fixed);
	        cout.setf(ios::showpoint);
	        cout.precision(2);
          cout << student_locker[user_lock_num - LOCKER_RANGE].m_stud_money;
          cout << endl;
        }
        else
        {
          cout << endl << "This locker is unoccupied." << endl;
        }
        
        break;

      case OPTION3:
        
        // Output locker contents for all lockers that are occupied
        cout << "\tALL LOCKERS CONTENTS\t" << endl;
        cout << "\t--------------------\t" << endl;
        for (i = 0; i < LOCKER_RANGE; i++)
        {
          if (student_locker[i].m_occupied_check == true)
          {
            cout << student_locker[i].m_locker_num;
            cout << "\t";
            cout << student_locker[i].m_student_name;
            cout << "\t"; 

            // Checks for singular or plural text(s)
            if (student_locker[i].m_texts == 
            SINGLE_TEXT)
            {
              cout << student_locker[i].m_texts;
              cout << " text";
            }
            else
            {
              cout << student_locker[i].m_texts;
              cout << " texts";
            }
          
            cout << "\t" << "$";

            // "Magical code we will learn later"
            cout.setf(ios::fixed);
	          cout.setf(ios::showpoint);
	          cout.precision(2);
            cout << student_locker[i].m_stud_money;
            cout << endl;
          }
        }
        
        break;

      case OPTION4:
        
        // Checks whether a locker is occupied or not, if it is, it empties it
        do
        {
          cout << "Enter a locker to empty between 101 and 201: " << endl;
          cin >> user_lock_num;
        } while (user_lock_num < LOCKER_RANGE || user_lock_num > 
        HIGHEST_LOCKER);

        if (student_locker[user_lock_num - LOCKER_RANGE].m_occupied_check
        == true)
        {
          student_locker[user_lock_num - LOCKER_RANGE].m_student_name = ' ';
          student_locker[user_lock_num - LOCKER_RANGE].m_stud_money = ROBBED;
          student_locker[user_lock_num - LOCKER_RANGE].m_texts = ROBBED;
          student_locker[user_lock_num - LOCKER_RANGE].m_occupied_check = false;
        }
        else
        {
          cout << endl << "This locker is unoccupied." << endl;
        }

        break;

      case OPTION5:
        quit = true;
        break;
      
      // Re-prompts the user for a valid option
      default:
        cout << "Invalid input! Please input a valid menu option! (1-5)" <<
        endl << endl;
        break;
    }
  } while (quit == false);

  cout << "Thank you for using the locker inventory system!" << endl;

  return 0;
}