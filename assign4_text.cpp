#include <iostream>
#include <cstring>
#include <string>
using namespace std;

/******************************************************************
** Function: check_vowel_cons
** Description: check the number of vowel whether equal the number 
of consonaats or not.
** Parameters: char array s (a pointer)
** Pre-conditions: s is a string and less than 1027
** Post-conditions: return true and false
******************************************************************/
bool check_vowel_cons(const char* s)
{
    int vowels_number = 0;
    int consonants_number = 0;
    for (int i =0; i < strlen(s); i++)
    {
         if(s[i] == 97 || s[i] == 101 || s[i] == 105 || s[i] == 111 || s[i] == 117)
         {
            vowels_number ++;
         }
         else if((s[i] >= 98 && s[i] <= 101)||(s[i] >= 102 && 
         s[i] <= 104)||(s[i] >= 106 && s[i] <= 110)|| (s[i] >= 112 && s[i] <=116)
         || (s[i] >= 118 && s[i] <= 122))
         {
            consonants_number ++;
         }

    }
    if(vowels_number == consonants_number)
    return true;
    else if(vowels_number != consonants_number)
    return false;
}

/******************************************************************
** Function: function1
** Description: to output the result of check_vowel_cons.
** Parameters: char s (a pointer)
** Pre-conditions: s is a string.
** Post-conditions: return the string.
******************************************************************/
char function1(char* s1)
{
    if (check_vowel_cons(s1)==true)
    {
        cout << "# vowels = # consonants." << endl;
    }
    else if(check_vowel_cons(s1)==false)
    {
        cout << "# vowels != # consonants." << endl;
    }
}

/******************************************************************
** Function: letter_swap
** Description: use one letter uer input to replace another letter
uers input. 
** Parameters: s string(pointer), char a, char b.
** Pre-conditions: two letters. 
** Post-conditions: an array will be output. 
******************************************************************/
void letter_swap (char* s, const char a, const char b)
{
    for (int i =0; i< strlen(s); i++)
    {
        if(s[i] == a)
        {
            s[i] = b;
        }
    }
}

/******************************************************************
** Function: flip_str
** Description: to reverse the input.
** Parameters: a char array s
** Pre-conditions: s is a string(pointer)
** Post-conditions: return the new string.
******************************************************************/
char* flip_str(const char* s)
{
    char* str= new char[1024];
    int len = strlen(s);
    for(int i=0; i<len;i++)
    {
        str[i] = s[len-i-1];
    }

    return str;
}

/******************************************************************
** Function: swap_case
** Description: the lower_case letter in the string will change to the 
upper_case.
** Parameters: a array string(pointer)
** Pre-conditions: s is a string.
** Post-conditions: return a string.
******************************************************************/
char* swap_case(char* s)
{
    int length = strlen(s);
    for(int j = 0; j< length; j++)
    {
        if ((s[j] >= 65) && (s[j] <= 90))
        {
            s[j] = s[j] + 32;
        }
        else if ((s[j] >= 97) && (s[j] <= 122))
        {
            s[j] = s[j] - 32;
        }

    }
    return s;
}

int* count_chars(const char* s, const char* chars)
{
    int length1 = strlen(s);
    int length2 = strlen(chars);
    int count = 0;
    for (int i = 0; i < length2; i ++)
    {
     for (int j=0; j< length; j++)
     {
        if (chars[i] == s[j])
        {
        count ++;
        }
     }
     cout << chars[i] << endl; 
    }
}

int main()
{
     //to declare a new char string. 
    char * str = new char[1027];
    cout << "place input a sentence. (less than 1027 charcters)" << endl;
    //use getline to recive the users input. and the max length is 1027;
    cin.getline(str, 1027);
    //to declare a int type choice which decide the users choice.
    int choice = 0;
    //use do-while to repeat do this program.
    do
    {
        cout << "place input a number (1-5; 1 for check if consonants = vowels "<< endl;
        cout << "2 for swap one letter for anoter. the first letter you input will" <<endl;
        cout << "be replaced by the second letter. 3 for reverse the input."<< endl; 
        cout << "4 for swap the letter case to the opposite case." <<endl;
        cout << "5 for exit game!" << endl;
        cin >> choice;
        //use if-else to judge the uers input and to use the right function.
        if (choice == 1)
        {
            function1(str);
        }
        //if users choose the second function.
        else if(choice == 2)
        {
            char a = 0;
            char b = 0;
            cout << "place input two letters" << endl;
            cin >> a >> b;
            letter_swap(str, a, b);
            cout  << str << endl;
        }
        //if users choose the third function.
        else if(choice == 3)
        {
            cout << flip_str(str) << endl;
        }
        //if uers choose the fourth function.
        else if(choice == 4)
        {
            cout << swap_case(str) << endl;
        }
        //if user what exit the game. 
        else if(choice == 5)
        {
           char* lett = new char[4];
           cout <<"input" << endl;
           cin >> lett;
           cout << count_chars(str, lett)<< endl;
        }
        
    }
    //if users input the invalid sentence. this will make the uers reinput.
    while(choice || choice>4);
    //make the pointer str to NULL.prevent exceptions.
        str = NULL;
        //to free the new char array str.
        delete []str;
    return 0; 
}
