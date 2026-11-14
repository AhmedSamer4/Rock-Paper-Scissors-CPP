#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
using namespace std;

enum typeGame {rock = 1, paper = 2, scissors = 3};
//دالة بداية اللعبة 
void theStart() {
    string stars = "    **************************************************";
    cout << stars << endl << endl;
    cout << "                    WELCOME TO THE GAME" << endl << endl;
    cout << stars << endl << endl;
    
    cout << "    The game instructions are as follows: " << endl;
    cout << "    1) Enter the number of rounds played." << endl;
    cout << "    2) Choose a number from 1 to 3 where \n     1 = rock, 2 = paper, and 3 = scissors." << endl;
    }
    //دالة طلب من اللاعب عدد تكرارات الاختيار 
   int numberRound(string text) {
         
         int num;
         while (true) {
             cout << "    " << text << endl;
         cout << "    "; cin >> num;
         
         if (cin.fail()) {
             cout << "    [Error] Please enter a valid number, not letters or text!" << endl;
             cin.clear();
             cin.ignore(numeric_limits<streamsize>::max(), '\n');
             } else if (num <= 0) {
                 cout << "    [Error] Number of rounds must be greater than 0!\n" << endl;
                 } else {
                     cin.ignore(numeric_limits<streamsize>::max(), '\n');
                     return num;
                     }
   }
   }
   //دالة ارجاع اختيار المستخدم من نوع enum
   typeGame userPlayer() {
       int ur;
       do {
       ur = numberRound("    Enter a number from 1 to 3 Where 1 = rock, 2 = paper, and 3 = scissors: ");
       } while (ur <= 0 || ur >= 4);
       return (typeGame)ur;
       }
       //دالة ارجاع اختيار الكمبيوتر العشوائي ما بين رقم 1 الى 3 من نوع enum
       typeGame computerPlayer() {
           int computerRound;
           computerRound = (rand() % 3) + 1;
           
           return (typeGame)computerRound;
       }
       //دالة نهاية اللعبة 
       void footer(int userW, int computerW, int dra) {
           if (userW > computerW) {
               cout << "    Congratulations, you have won!" << endl;
               
               } else if (computerW > userW) {
        cout << "    ❌ Oops, the computer won the match overall. Better luck next time." << endl;
    } else {
        cout << "    🤝 It's an overall draw match!" << endl;
    }
           cout << "    Congratulations! You have completed all rounds of the game. Here is a summary of the game: " << endl;
           cout << "    Number of times you have won: " << userW << endl;
           cout << "    Number of times the computer has won: " << computerW << endl;
           cout << "    Number of draws: " << dra << endl;
           }
   //دالة اللعبة الاساسيه الصدر
   void tours(int rounds) {
       int userWin = 0;
       int computerWin = 0;
       int draw = 0;
       
       for (int r = 0; r < rounds; r++) {
           typeGame user = userPlayer();
       typeGame computer = computerPlayer();
           
           
           if ((user == rock && computer == scissors) || (user == paper && computer == rock) || (user == scissors && computer == paper)) {
               userWin++;
               cout << "    You have won this round. There are " << rounds - (r +1) << " rounds left." << endl;
               } else if ((user == rock && computer == paper) || (user == paper && computer == scissors) || (user == scissors && computer == rock)) {
                   computerWin++;
                   cout << "    You have lost, " << rounds - (r + 1) << " rounds remain" << endl;;
                   } else {
                       draw++;
                       cout << "    You have drawn this round, " << rounds - (r + 1) << " rounds remain" << endl;
                       }
           
           }
           
           footer(userWin, computerWin, draw);
           cout << endl;
       
       }
      

int main() {
    //تشغيل اللعبة وعند نهاية اللعبة سؤال اعادة اللعب مره اخرى
    srand(time(0));
    int again;
    do {
    typeGame myGame;
    theStart();
    int round = numberRound("    Enter the number of rounds of play: ");
    
    tours(round);
    do {
    cout << "    Do you want to play again? Choose 1 = Yes or 0 = No\n";
    cout << "    "; cin >> again;
    } while (again < 0 || again >= 2);
    cout << "    The game was successfully completed ✅";
    } while (again == 1);
    return 0;
    }