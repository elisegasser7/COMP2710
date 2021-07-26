#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>
using namespace std;

/*
* Input: A_alive indicates Aaron is alive true for alive, false for dead
* B_alive indicates Bob is alive
* C_alive indicates Charlie is alive
* Return: true if at least two are alive otherwise return false
*/
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);
/*
* Call by reference
* Strategy 1: Everyone shoots to kill the highest accuracy player alive
* Input: B_alive indicates Bob is alive or dead
* C_alive indicates Aaron is alive or dead
* Return: Change B_alive into false if Bob is killed
* Change C_alive into false if Charlie is killed
*/
void Aaron_shoots1(bool& B_alive, bool& C_alive);
/*
* Call by reference
* Input: A_alive indicates Aaron is alive or dead
* C_alive indicates Charlie is alive or dead
* Return: Change A_alive into false if Aaron is killed
* Change C_alive into false if Charlie is killed
*/
void Bob_shoots(bool& A_alive, bool& C_alive);
/*
* Call by reference
* Input: A_alive indicates Aaron is alive or dead
* B_alive indicates Bob is alive or dead
* Return: Change A_alive into false if Aaron is killed
* Change B_alive into false if Bob is killed
*/
void Charlie_shoots(bool& A_alive, bool& B_alive);
/*
* Call by reference
* Strategy 2: Aaron intentionally misses if both are alive
* Input: B_alive indicates Bob is alive or dead
* C_alive indicates Aaron is alive or dead
* Return: Change B_alive into false if Bob is killed
* Change C_alive into false if Charlie is killed
*/
void Aaron_shoots2(bool& B_alive, bool& C_alive);


//Function to pause in Linux
void Press_any_key(void);

//Test Properties of each Functions and Test Functions
void test_at_least_two_alive(void);
void test_Aaron_shoots1(void);
void test_Bob_shoots(void);
void test_Charlie_shoots(void);
void test_Aaron_shoots2(void);
bool at_least_two_alive(bool, bool, bool);

//Variables Declared
const int TOTAL_RUNS = 10000;
const int Aaron_probability = 33;
const int Bob_probability = 50;


//Main
int main() {

    //Title
    cout << "*** Welcome to Elise's Duel Simulator ***\n";

    //Variables
    int aaronWins1 = 0;
    int bobWins1 = 0;
    int charlieWins1 = 0;
    int aaronWins2 = 0;
    int bobWins2 = 0;
    int charlieWins2 = 0;

    bool aaronAlive;
    bool bobAlive;
    bool charlieAlive;
    

    //Sets to 0
    srand(time(0));

    //Steps of Game
    test_at_least_two_alive();
    Press_any_key();
    test_Aaron_shoots1();
    Press_any_key();
    test_Bob_shoots();
    Press_any_key();
    test_Charlie_shoots();
    Press_any_key();
    test_Aaron_shoots2();
    Press_any_key();

    //Starts strategy 1 and runs 10000 times
    cout << "Ready to test strategy 1 (run 10000 times):\n";
    Press_any_key();

    for (int i = 0; i < TOTAL_RUNS; i++) {

        aaronAlive = true;
        bobAlive = true;
        charlieAlive = true;

        while(at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
            if (aaronAlive) {
                Aaron_shoots1(bobAlive, charlieAlive);
            }
            if (bobAlive) {
                Bob_shoots(aaronAlive, charlieAlive);
            }
            if (charlieAlive) {
                Charlie_shoots(aaronAlive, bobAlive);
            }
        }

        if (aaronAlive) {
            aaronWins1++;
        }
        if (bobAlive) {
            bobWins1++;
        }
        if (charlieAlive) {
            charlieWins1++;
        }
    }

    cout << "Aaron won " << aaronWins1 << "/10000 duels or " << static_cast<double>(aaronWins1) / TOTAL_RUNS * 100 << "%\n"
        << "Bob won " << bobWins1 << "/10000 duels or " << static_cast<double>(bobWins1) / TOTAL_RUNS * 100 << "%\n"
        << "Charlie won " << charlieWins1 << "/10000 duels or " << static_cast<double>(charlieWins1) / TOTAL_RUNS * 100 << "%\n"
        << endl;

    aaronAlive = true;
    bobAlive = true;
    charlieAlive = true;

    cout << "Ready to test strategy 2 (run 10000 times):\n";
    Press_any_key();

    for (int i = 0; i < TOTAL_RUNS; i++) {

        aaronAlive = true;
        bobAlive = true;
        charlieAlive = true;

        while(at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
            if (aaronAlive) {
                Aaron_shoots2(bobAlive, charlieAlive);
            }
            if (bobAlive) {
                Bob_shoots(aaronAlive, charlieAlive);
            }
            if (charlieAlive) {
                Charlie_shoots(aaronAlive, bobAlive);
            }
        }

        if (aaronAlive) {
            aaronWins2++;
        }
        if (bobAlive) {
            bobWins2++;
        }
        if (charlieAlive) {
            charlieWins2++;
        }
    }

    cout << "Aaron won " << aaronWins2 << "/10000 duels or " << static_cast<double>(aaronWins2) / TOTAL_RUNS * 100 << "%\n"
        << "Bob won " << bobWins2 << "/10000 duels or " << static_cast<double>(bobWins2) / TOTAL_RUNS * 100 << "%\n"
        << "Charlie won " << charlieWins2 << "/10000 duels or " << static_cast<double>(charlieWins2) / TOTAL_RUNS * 100 << "%\n"
        << endl;


    if (aaronWins1 > aaronWins2) {
        cout << "Strategy 1 is better than strategy 2.\n";
    }
    else {
        cout << "Strategy 2 is better than strategy 1.\n";
    }
    return 0;

}

// ^^^FUNCTIONS BELOW^^^

//Function that returns true if two out of three people are still alive
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {

    if (A_alive) {
        if (B_alive || C_alive) {
            return true;
        }
    }
    else if (B_alive) {
        if (C_alive) {
            return true;
        }
    }
    return false;  
}

//Function of Aaron shooting in Strategy #1 (Probability 33%)
void Aaron_shoots1(bool &B_alive,bool &C_alive) {

    int shooting_result = rand()%100;

    if (shooting_result <= Aaron_probability) {
        if (C_alive) {
            C_alive = false;
        }
        else {
            B_alive = false;
        }
    }

}

//Function of Bob shooting (Probability 50%)
void Bob_shoots(bool &A_alive, bool &C_alive) {

    int shooting_result = rand()%100;

    if (shooting_result <= Bob_probability) {
        if (C_alive) {
            C_alive = false;
        }
        else {
            A_alive = false;
        }
    }

}

//Function of Charlie Shooting (Probability 100%)
void Charlie_shoots(bool &A_alive, bool &B_alive) {

    if (B_alive) {
        B_alive = false;
    }
    else {
        A_alive = false;
    }

}

//Function of Aaron shooting in Strategy #1 (Misses 1st shot, second shot Probability 33%)
void Aaron_shoots2(bool &B_alive, bool &C_alive) {
  
    int shooting_result = rand()%100;
    
    if (!B_alive || !C_alive) {
        if (shooting_result <= Aaron_probability) {
            if (C_alive) {
                C_alive = false;
            }
             else {
                B_alive = false;
            }
        }   
    }

}

//Function to continue game
void Press_any_key(void) {

    cout << "Press any key to continue...";
    cin.ignore().get();

}


// ^^^TESTING BELOW^^^

//Test of at_leat_two_aliev
void test_at_least_two_alive(void) {

    cout << "Unit Testing 1: Function - at_least_two_alive()\n";

    cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
    assert(true == at_least_two_alive(true, true, true));
    cout << "\tCase passed ...\n";

    cout<< "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
	assert(true == at_least_two_alive(false, true, true));
	cout << "\tCase passed...\n";
	
	cout<< "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
	assert(true == at_least_two_alive(true, false, true));
	cout << "\tCase passed...\n";
	
	cout<< "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
	assert(true == at_least_two_alive(true, true, false));
	cout << "\tCase passed...\n";
	
	cout<< "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
	assert(false == at_least_two_alive(false, false, true));
	cout << "\tCase passed...\n";
	
	cout<< "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
	assert(false == at_least_two_alive(false, true, false));
	cout << "\tCase passed...\n";
	
	cout<< "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
	assert(false == at_least_two_alive(true, false, false));
	cout << "\tCase passed...\n";
	
	cout<< "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
	assert(false == at_least_two_alive(false, false, false));
	cout << "\tCase passed...\n";
}

//Test of Aaron_shoots1
void test_Aaron_shoots1(void) {

    bool bob_alive;
    bool charlie_alive;

    cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";

    cout << "\tCase 1: Bob alive, Charlie alive\n";
    cout << "\t\tAaron is shooting at Charlie\n";
    bob_alive = true;
    charlie_alive = true;
    Aaron_shoots1(bob_alive, charlie_alive);
    assert(true == bob_alive);
    
    bob_alive = false;
    charlie_alive = true;
    cout << "\tCase 2: Bob dead, Charlie alive\n";
    cout << "\t\tAaron is shooting at Charlie\n";
    Aaron_shoots1(bob_alive, charlie_alive);
    assert(false == bob_alive);

    bob_alive = true;
    charlie_alive = false;
    cout << "\tCase 3: Bob alive, Charlie dead\n";
    cout << "\t\tAaron is shooting at Bob\n";
    Aaron_shoots1(bob_alive, charlie_alive);
    assert(false == charlie_alive);
}

//Test of Bob_shoots
void test_Bob_shoots(void) {

    bool aaron_alive;
    bool charlie_alive;

    cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";

    cout << "\tCase 1: Aaron alive, Charlie alive\n";
    cout << "\t\tBob is shooting at Charlie\n";
    aaron_alive = true;
    charlie_alive = true;
    Bob_shoots(aaron_alive, charlie_alive);
    assert(true == aaron_alive);

    cout << "\tCase 2: Aaron dead, Charlie alive\n";
    cout << "\t\tBob is shooting at Charlie\n";
    aaron_alive = false;
    charlie_alive = true;
    Bob_shoots(aaron_alive, charlie_alive);
    assert(false == aaron_alive);

    cout << "\tCase 3: Aaron alive, Charlie dead\n";
    cout << "\t\tBob is shooting at Charlie\n";
    aaron_alive = true;
    charlie_alive = false;
    Bob_shoots(aaron_alive, charlie_alive);
    assert(false == charlie_alive);
}

//Test of Charlie_shoots
void test_Charlie_shoots(void) {

    bool aaron_alive;
    bool bob_alive;

    cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";

    cout << "\tCase 1: Aaron alive, Bob alive\n";
    cout << "\t\tCharlie is shooting at Bob\n";
    aaron_alive = true;
    bob_alive = true;
    Bob_shoots(aaron_alive, bob_alive);
    assert(true == aaron_alive);

    cout << "\tCase 2: Aaron dead, Bob alive\n";
    cout << "\t\tCharlie is shooting at Bob\n";
    aaron_alive = false;
    bob_alive = true;
    Bob_shoots(aaron_alive, bob_alive);
    assert(false == aaron_alive);

    cout << "\tCase 3: Aaron alive, Bob dead\n";
    cout << "\t\tCharlie is shooting at Aaron\n";
    aaron_alive = true;
    bob_alive = false;
    Bob_shoots(aaron_alive, bob_alive);
    assert(false == bob_alive);
}

//Test of Aaron_shoots2
void test_Aaron_shoots2(void) {

    bool bob_alive;
    bool charlie_alive;

    cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";

    cout << "\tCase 1: Bob alive, Charlie alive\n";
    cout << "\t\tAaron intentionally misses his first shot\n\t\tBoth Bob and Charlie are alive\n";
    bob_alive = true;
    charlie_alive = true;
    Aaron_shoots2(bob_alive, charlie_alive);
    assert(true == bob_alive);
    assert(true == charlie_alive);
    
    bob_alive = false;
    charlie_alive = true;
    cout << "\tCase 2: Bob dead, Charlie alive\n";
    cout << "\t\tAaron is shooting at Charlie\n";
    Aaron_shoots2(bob_alive, charlie_alive);
    assert(false == bob_alive);

    bob_alive = true;
    charlie_alive = false;
    cout << "\tCase 3: Bob alive, Charlie dead\n";
    cout << "\t\tAaron is shooting at Bob\n";
    Aaron_shoots2(bob_alive, charlie_alive);
    assert(false == charlie_alive);
}

