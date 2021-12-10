//**********************************************************
//** Program: assign2_game.cpp
//** Author: Jianglong Yu
//** Date: 01/25/2020
//** Description: A adventure game
//** Input:some numbers of the game's options.
//** Output:players' score and the final.
//***********************************************************//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

int main()
{
   while (true)
   {
    cout << "Out of the Jungle" << endl << endl;//the game name.
    cout << "Welcome to the game world! In this game, your goal " << endl
         << "is to get out of the jungle!" << endl//introduce the goal of this game.
         << "You were sent to country A to fight. One night, " << endl
         << "due to the fierce fighting, you and your teammates " << endl
         << "lost in the jungle. You don't have any communication " << endl
         << "equipemt. No gunshots are heard in the junle at " << endl
         << "this time, you are ready to: " << endl
         << "(1) Find the way out of the jungle." << endl
         << "(2) Stay here and wait for dawn." << endl;//set two chioce to the players.
    int score = 0; /* set a variable score to store the plays' score.i use int (min -2147483648,
                  max 2147483647.)*/
    short number; /* make a variable, i use short (min -32768, max 32767) cuz people just
                   need to input some small integer. */
    cin >> number;
    
    while (number != 1 || number != 2) /*if the player input the wrong number, it will remind
                                        players input the right number */
    {
        if (number == 1) //the option one.
        {
            cout << "You gain 10 points for a score of 10 points." << endl << endl;
            score += 10;//to record the plays' score.
            cout << "You look at your compass and start walking towards " << endl
                 << "the camp, but you find a figure in front of you. You " << endl
                 << "don't know if it's an enemy or your teammate. you are " << endl
                 << "ready to: " << endl
                 << "(1) Shoot him." << endl
                 << "(2) Try to communicate with him." << endl
                 << "(3) Change the way." << endl; //there are three chioces of step two
            cin >> number;
            
            while (number != 1 || number != 2 || number != 3) //second part of this game.
            {
                if (number == 1) //when player choose option 1 in the part two.
                {
                    cout << "you gain 10 points!" << endl << endl;
  4                  score += 10;
                    cout << "You killed him, Now you decide" << endl
                    << "(1) go and see the body who was killed." << endl
                    << "(2) keep finding the way out of junle." << endl;
                    cin >> number; /*this case have two choies*/
                    
                    while (number != 1 || number != 2)//to prevent players input the wrong number.
                    {
                        if (number == 1) // when player choose 1 in the part three.
                        {
                            cout << "you gain 10 points!" << endl << endl;
                            score += 10;
                            cout << "Congratutions! You find a map of this junle, and you find the way" << endl
                                 << "out of junle." << endl;
                            break;
                        }
                        else if (number == 2) // when players choose 2 in the part three.
                        {
                            cout << "You gain 5 points!" << endl << endl;
                            cout << "Congratutions! You find the way out of the junle!" << endl;
                            break;
                        } 
                        else //if the users input valid character. this step will remind users input 1 or 2.
                        {
                            cout << "place input 1 or 2!" << endl;
                            cin.clear();
                            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                            cin >> number;
                        }
                        
                    }
                    break;

                }
                
                else if (number == 2)  //when player choose 2 in the part two
                {
                    cout << "You lose 4 points!" << endl << endl;
                    score -= 4;
                    cout << "He is enemy, so he shoot you, and you died. Mission failed" << endl
                         << "Game over!" << endl;
                    break;
                }
                else if (number == 3) //when play choose 3 in the part two
                {
                    int probability;// i use the "rand" to random if the enemy sew players or not.
                    srand(time(NULL));
                    rand()%1;
                    if (probability == 1)// case of enemy didn't see players.
                    {
                        cout << "You gain 6 points!" << endl << endl;
                        cout << "Congratutions! He did't see you, you get around him successfully!" << endl
                             << "You out of the jungle successfully!" << endl;
                    }
                    else // case of enemy see players, and this game will exit.
                    {
                        cout << "You lose 6 points!" << endl << endl;
                        score -= 6;
                        cout << "He see you, and he shoots you, you died. Mission failed" << endl
                             << "Game over!" << endl;
                    }
                    break;
                } 
                else // to remind users input the right number if they input invalid number. 
                {
                    cout << "place input 1, 2, or 3." << endl;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    cin >> number;
                }
                
            }
            break;
        }
        else if (number == 2)// the option two of part one.
        {
                cout << "You lose 10 points for a score of -10 points." << endl << endl;
                score -= 10; //to record the plays' score.
                cout << "You are found by the enemies, mission fail and " << endl
                     << "game over!" << endl;//endgame.
                break;
        }
        else // if users input number which not 1 or 2. 
        {
            cout << "place input 1 or 2!" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            cin >> number;
        }
        
    }
    cout << "Your final score is " << score << "." << endl;
    cout << "Do you want try again? (0-no, 1-yes)" << endl;
    
    int is_continue;
    cin >> is_continue;
    while (is_continue > 1)
    {
    cout << "place input right number!" << endl;
    cout << "Do you want try again? (0-no, 1-yes)" << endl;
    cin >> is_continue;
    }
    if(is_continue == 0)
    {
    break;
    }
   }     
    return 0;
 }
