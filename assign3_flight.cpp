//**********************************************************
//** Program: assign3_flight.cpp
//** Author: Jianglong Yu
//** Date: 02/09/2020
//** Description: A flight animation
//** Input:Follow the prompts to enter some aircraft flight parameters.
//** Output: flight time, cost perperson and flight animation
//           (include the back trip).
//***********************************************************//
#include <iostream>
#include <cmath> 
#include <unistd.h> //use in the sleep in the nimateFlight
#include <iomanip> 
#include <limits>
using namespace std;

/******************************************************************
** Function: input_check
** Description: check whether the character user input is a valid number.
   for double.  
** Parameters: a character.
** Pre-conditions: the character should is a number. 
** Post-conditions: return true if number is a valid number and otherwise false
******************************************************************/
void input_check(std::istream &is = cin, double *value = NULL) 
{
  is >> *value;
  if (is.fail()) 
  {
    is.clear();
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "the input is invalid, please input proper value." << endl;
    input_check(is, value);
  }
}
/******************************************************************
** Function: input_check
** Description: check whether the character user input is a valid 
   number.for int.
** Parameters: a character.
** Pre-conditions: the character should is a number. 
** Post-conditions: return true if number is a valid number and otherwise false
******************************************************************/
void input_check(std::istream &is = cin, int *value = NULL) 
{
  is >> *value;
  if (is.fail()) 
  {
    is.clear();
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "the input is invalid, please input proper value." << endl;
    input_check(is, value);
  }
}
/******************************************************************
** Function: userinputdouble
** Description: check whether the character user input is a valid number.  
** Parameters: a number.
** Pre-conditions: number is more than 0, and less than 40000.
** Post-conditions: return true if number is a valid number and otherwise false
******************************************************************/
bool usersinputdouble (double number) // i choose double because the number user 
//input whould not more than this interval(min2.2e-308, max1.8e308)
{
//less than 40000, because in this code, 
//i don't think any parameters will more than 40000.
    if (number > 0 && number < 9000000) 
    return true;
    else //if number less than 0 or more than 0000000.
    return false;
}
/******************************************************************
** Function: userinputint
** Description: check whether the character user input is a int  
** Parameters: a number.
** Pre-conditions: number is more than 0, and less than 40000. 
                   And number is an integet. 
** Post-conditions: return true if number is a valid number and otherwise false
******************************************************************/
bool usersinputint (int number) 
//people should input integer in some parameters.the 
//interval(min-2147483648,max2147483647).
{
    if (number > 0 && number < 9000000)
    return true;
    else // if number less than 0 and more than 90000000.
    return false; 
}
/******************************************************************
** Function: userinputwindspeed
** Description: check this number's absolute value shoud 
   less than the planespeed. 
** if not, the windspeed will more than the planespeed, it will have bug. 
** Parameters: a number.
** Pre-conditions: number's absolute value should less than the planespeed. 
** Post-conditions: return true if number is a valid number and otherwise false
******************************************************************/
bool usersinputwindspeed (double number, double planespeed) 
//i choose double because the number user input whould not 
//more than this interval(min2.2e-308, max1.8e308)
{
    if (abs(number) < planespeed)
    return true;
    else //if the number'absoult value user input less than the planespeed. 
    return false;
}
/******************************************************************
** Function: f_time
** Description: to calculate the flight time.
** Parameters: distance, planespeed, windspeed.
** Pre-conditions: these parameters uers input is valid number. 
** Post-conditions: return time. 
******************************************************************/
double f_time(double distance = 0 , double planespeed = 0, double windspeed = 0) 
//i choose double because the number user input whould not 
//more than this interval(min2.2e-308, max1.8e308)
{
    double net_speed = planespeed - windspeed;
    double time = distance / net_speed;
    return time;
}
/******************************************************************
** Function: hours
** Description: convert the time to the hours. 
** Parameters: time
******************************************************************/
int hours (double time = 0)
{
    int hour = time;
    return hour;
}
/******************************************************************
** Function: minutes
** Description: convert the time to the minutes. 
** Parameters: time
******************************************************************/
int minutes (double time = 0)
{

    int hour_i =  time;
    double minute = time-hour_i>0?(time-hour_i)*60:0;
    return minute;
}
/******************************************************************
** Function: cost_per_person
** Description: to calculate the cost perperson time.
** Parameters: fuel_price, flight_time, fuel_burn_rate, passengers
** Pre-conditions: these parameters uers input is valid number.
** Post-conditions: return money people cost. 
******************************************************************/
double cost_per_person(double fuel_price, double flight_time, 
                       double fuel_burn_rate, int passengers) 
//i choose double because the number user input whould 
//not more than this interval(min2.2e-308, max1.8e308)
{
    double fuel_burnt = fuel_burn_rate * flight_time;
    double total_fuel_price = fuel_burnt * fuel_price;
    double cost_person = total_fuel_price / passengers;
    return cost_person;
}
/******************************************************************
** Function: create_back_narrow
** Description: to output the back trip animateflight, to create_back_narrow. 
** Parameters: current_xhcs
** Pre-conditions: these parameters input is valid.
** Post-conditions: return narrow
******************************************************************/
string create_back_narrow(int current_xhcs)
{
    string row = "";
    for (int i = 0; i < current_xhcs+1; i++)
    {
        row+="<= ";
    }
    return row;
}
/******************************************************************
** Function: animateFlight
** Description: to output the flight animateflight
** Parameters: flight_time, seconds_of_anim_per_flight_hour,bool go_trip
** Pre-conditions: these parameters uers input is valid number.
** Post-conditions: return animate
******************************************************************/
void animateFlight(double flight_time, 
                   double seconds_of_anim_per_flight_hour,bool go_trip)
//i use void because void don't need return value. 
{
    float times_f = flight_time * seconds_of_anim_per_flight_hour;
    int times_i = flight_time * seconds_of_anim_per_flight_hour;
    int xun_huan_ci_shu = times_f - times_i > 0 ? times_i + 1 : times_i;
    for (int i = 0; i < xun_huan_ci_shu; i++)
    {
        if (go_trip)
        {
            cout << "=> " << flush;
        }
        else
        {
            cout << right << setw(3 * (xun_huan_ci_shu)) 
            << create_back_narrow(i) 
            << ((i == xun_huan_ci_shu - 1) ? "\n" : "\r") << flush;
        }
        sleep(1);
    }
}

int main()
{
    cout << "Please provide the following flight information: " << endl;
    double distance; 
    // i choose double because the number user input whould 
    // not more than this interval(min2.2e-308, max1.8e308)
    cout << "1) Flight distance (miles): ";
    input_check(cin,&distance);
    while (!usersinputdouble(distance))
    {
        cout << "place input vaild number!" << endl;
        cin >> distance;
    }
    
    double planespeed;
    // i choose double because the number user input whould 
    // not more than this interval(min2.2e-308, max1.8e308)
    cout << "2) Airplane airspeed (miles per hour): ";
    input_check(cin,&planespeed);
    while (!usersinputdouble(planespeed))
    {
        cout << "place input vaild number!" << endl;
        cin >> planespeed;
    }
    
    double windspeed;
    // i choose double because the number user input whould 
    // not more than this interval(min2.2e-308, max1.8e308)
    cout << "3) Wind speed (miles per hour): ";
    input_check(cin,&windspeed);
     while (!usersinputwindspeed(windspeed, planespeed))
    {
        cout << "place input vaild number!" << endl;
        cin >> windspeed;
    }
    
    double fuel_burn_rate;
    //i choose double because the number user input whould 
    //not more than this interval(min2.2e-308, max1.8e308)
    cout << "4) Fuel burn rate (gallons per hour): ";
    input_check(cin,&fuel_burn_rate);
     while (!usersinputdouble(fuel_burn_rate))
    {
        cout << "place input vaild number!" << endl;
        cin >> fuel_burn_rate;
    }
    
    double fuel_price;
    //i choose double because the number user input whould 
    //not more than this interval(min2.2e-308, max1.8e308)
    cout << "5) Fuel price (dollars per gallon): ";
    input_check(cin,&fuel_price);
     while (!usersinputdouble(fuel_price))
    {
        cout << "place input vaild number!" << endl;
        cin >> fuel_price;
    }
    
    int passengers;
    //people should input integer in some parameters.
    //the interval(min-2147483648,max2147483647).
    cout << "6) Number of people onboard: ";
    input_check(cin,&passengers);
     while (!usersinputint(passengers))
    {
        cout << "place input vaild number!" << endl;
        cin >> passengers;
    }
    
    double seconds_of_animper_fight_hour;
    //i choose double because the number user input whould 
    //not more than this interval(min2.2e-308, max1.8e308)
    cout << "7) Seconds of animation per flight hour: ";
    input_check(cin,&seconds_of_animper_fight_hour);
     while (!usersinputdouble(seconds_of_animper_fight_hour))
    {
        cout << "place input vaild number!" << endl;
        cin >> seconds_of_animper_fight_hour;
    }

    double flight_time = 0;
    //i choose double because the number user input whould 
    //not more than this interval(min2.2e-308, max1.8e308)
    flight_time = f_time (distance, planespeed, windspeed);
    
    int hour = 0;
    //people should input integer in some parameters.
    //the interval(min-2147483648,max2147483647).
    hour = hours (flight_time);
    int minute = 0;
    //people should input integer in some parameters.
    //the interval(min-2147483648,max2147483647).
    minute = minutes (flight_time);

    cout << endl; 
    double cost_perperson = cost_per_person (fuel_price, flight_time, 
                                             fuel_burn_rate, passengers);
    //i choose double because the number user input whould not 
    //more than this interval(min2.2e-308, max1.8e308)
    cout << "Your flight will take " << hour << " hours and "
         << minute << " minutes and cost " << fixed << setprecision(2)
    << cost_perperson << "$ per person." << endl;

    cout << endl;
    animateFlight (flight_time, seconds_of_animper_fight_hour, true);

    cout << endl;
    double b_flight_time = 0;//creat a new variable to calculate the back tirp
    // i choose double because the number user input whould 
    // not more than this interval(min2.2e-308, max1.8e308)
    b_flight_time = f_time (distance, planespeed, -windspeed);
    //back tirp the windspeed will become additive inverse.
    
    int b_hour = 0;//to creat a new variable to calculate the back tirp
    // people should input integer in some parameters.
    // the interval(min-2147483648,max2147483647).
    b_hour = hours(b_flight_time);
    int b_minute = 0;//to creat a new variable to calculate the back tirp
    // people should input integer in some parameters.
    // the interval(min-2147483648,max2147483647).
    b_minute = minutes (b_flight_time);

    cout << endl;
    double b_cost_perperson = cost_per_person (fuel_price, 
                                     b_flight_time, fuel_burn_rate, passengers);
    //to creat a new variable to calculate the back tirp
    // i choose double because the number user input whould 
    // not more than this interval(min2.2e-308, max1.8e308)
    cout << "Your flight will take " << b_hour << " hours and "
    << b_minute << " minutes and cost" << fixed << setprecision(2) 
    << b_cost_perperson << "$ per person." << endl;

    cout << endl;
    animateFlight (b_flight_time, seconds_of_animper_fight_hour, false);

return 0;
}
