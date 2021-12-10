 /**********************************************************
 ** Program: fortune_teller.cpp
 ** Author: Jianglong Yu
 ** Date: 01/12/2020
 ** Description: first assignment to practise data type
 ** Input: 5 numbers with different typies
 ** Output: a string with the number which the use input
 ***********************************************************/

 #include <iostream>
 using namespace std;

 int main()
 {
 
 /* The interval of unsigned int population is from 0 to 4294967295,
  * there is no country's population more than 4294967295.
  */
 unsigned int population;
 cout << "Place enter a positive whole number: ";
 cin >> population;
 cout << "By 2019, this country has " << population << " people." << endl;

 /* The altitude can be positive or negative and usually don't have fractions,
  * so I am using a short integer (-32768,32768).
  */
 short n_meters;
 cout << "Place enter a whole number: ";
 cin >> n_meters;
 cout << "The altitude of this place is " << n_meters << " meters." << endl;

 /* I assume the thickness of a piece of paper is between 0 and 3.4e38,
  * so I am using a float (1.2e-38).
  */
 float n_thickness;
 cout << "What is the thickness of this paper? ";
 cin >> n_thickness;
 cout << "The thickness of this paper is " << n_thickness << " mm." << endl;

 /* I assum the number of tables and chairs is 0 and 200,
  * so a unsigned short (0,65535) is enough.
  */
 unsigned short n_tables, n_chairs;
 cout << "Place enter two positive whole number: ";
 cin >> n_tables >> n_chairs;
 cout << "This classroom has " << n_tables << " tables and " << n_chairs << " chairs." << endl;

 return 0;
 }
 


