#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>
#include <sstream>
using namespace std;

// Global Variables
int num_of_questions = 3;
int total_points = 0;

// Trivia Node Structure
struct trivia_node {
    string question;
    string answer;
    int point;
    trivia_node *next;
};

//Typedef ptr_node ref trivia_node
typedef trivia_node* ptr_node;

//PROTOTYPES
void init_question_list(ptr_node& q_list);
void add_question(ptr_node& q_list);
int ask_question(ptr_node q_list, int num_ask);
void Unit_Test();


// Comment and Uncomment these #defines for different versions

//#define UNIT_TESTING
#define trivia_quiz

//MAIN
int main() {

    //creates ptr_list and initializes first 3 question list
    ptr_node node_list = new trivia_node;
    init_question_list(node_list);

    string continueInput = "";

    //IFDEF #define trivia_quiz version
    #ifdef trivia_quiz
        init_question_list(node_list);
        cout << "*** Welcome to Elise's trivia quiz game ***\n";
        

        do {
            add_question(node_list);
            num_of_questions++;

            cout << "Continue? (Yes/No)";
            getline(cin, continueInput);
        } while (continueInput == "Yes");
        
        ask_question(node_list, num_of_questions);
        cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***";
        return 0;

    #endif

    //IFDEF #define UNIT_TESTING version
    #ifdef UNIT_TESTING
        Unit_Test();
        return 0;

    #endif

}

//Initialize Questions function
void init_question_list(ptr_node& q_list) {

    ptr_node cur_ptr = q_list;
    

    cur_ptr->question = "How long was the shortest war on record? (Hint: how many minutes)";
    cur_ptr->answer = "38";
    cur_ptr->point = 100; 

    cur_ptr->next = new trivia_node;
    cur_ptr = cur_ptr->next;

    cur_ptr->question = "What was the Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
    cur_ptr->answer = "Bank of Italy";
    cur_ptr->point = 20;

    cur_ptr->next = new trivia_node;
    cur_ptr = cur_ptr->next;

    cur_ptr->question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)";
    cur_ptr->answer = "Wii Sports";
    cur_ptr->point = 20;  
}

//Add Questions function
void add_question(ptr_node& q_list) {
    
    ptr_node new_ptr = new trivia_node;
    ptr_node cur_ptr = q_list->next;

    string point_input;
    int point_converted;

    //Find last trivia node (tail)
    while (cur_ptr->next != NULL) {
       cur_ptr = cur_ptr->next;
    }

    cur_ptr->next = new_ptr;
    
    cout << "Enter a question: ";
    getline(cin, new_ptr->question);

    cout << "Enter an answer: ";
    getline(cin, new_ptr->answer);

    cout << "Enter award points: ";

    getline(cin, point_input);
    
    // convert string to int
    stringstream degree(point_input);
    degree >> point_converted;

    new_ptr->point = point_converted;
}

//Ask Question Function
int ask_question(ptr_node q_list, int num_ask) {

    ptr_node cur_ptr = q_list;
    string user_answer;

    
    if (q_list == NULL) {
        return 0;
    }
    if (num_ask < 1) {
        cout << "Warning - the number of trivia to be asked must equal to or be larger than 1.";
    }
    else if (num_of_questions < num_ask) {
        cout << "Warning - There is only " << num_of_questions << " trivia in the list.";
    }
    else {
        for (int x = 0; x < num_ask; x++) {
            cout << "\n\nQuestion: " << cur_ptr->question << endl;
            cout << "Answer: ";
            
            getline(cin, user_answer);

            if (user_answer.compare(cur_ptr->answer) == 0) {
                cout << "Your answer is correct. You recieve " << cur_ptr->point << " points";

                total_points += cur_ptr->point;

                cout << "\nYour total points: " << total_points;
            } 
            else {
                cout << "The answer is wrong. The correct answer is: " << cur_ptr->answer;
                cout << "\nYour total points: " << total_points;
            } 

            cur_ptr = cur_ptr->next; 
        }

    }
    return 0;
}

//UNIT TEST Function
void Unit_Test() {

    ptr_node node_list = new trivia_node;
    init_question_list(node_list);

    cout << "\n*** This is a debugging version ***\n";

    cout << "Unit Test Case 1: Ask no question. The program should give a warning message." << endl;
    ask_question(node_list, 0);
    cout << "\n\nCase 1 Passed\n\n";

    cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer." << endl;
    ask_question(node_list, 1);
    assert(0 == total_points);
    cout << "\n\nCase 2.1 Passed\n\n";
    total_points = 0;

    cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters an correct answer." << endl;
    ask_question(node_list, 1);
    assert(total_points > 0);
    cout << "\n\nCase 2.2 Passed\n\n";
    total_points = 0;

    cout << "Unit Test Case 3: Ask all of the questions of the last trivia in the linked list." << endl;
    ask_question(node_list, num_of_questions);
    assert(total_points == 140);
    cout << "\n\nCase 3 Passed\n\n";
    total_points = 0;

    cout << "Unit Test Case 4: Ask 5 questions in the linked list." << endl;
    ask_question(node_list, 5);
    cout << "\n\nCase 4 Passed\n\n";

    cout << "\n*** End of the Debugging Version ***\n";

}