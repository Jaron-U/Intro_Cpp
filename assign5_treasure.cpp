#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cstdlib>

using namespace std;

//make struct of model_car
struct model_car
{
    string brand; // brand is a word, so i choose string.
    string color; // color is a word, so i choose string.
    float length; // length have float. 
    float price;  // price is a float. 
};

bool user_choose_input (char n) //check the select users input.
{
    if ( n>=1 && n<=6) //use ASKLL, make sure the numebr in the region[1,6].
    return true;
    else
    return false;
}

//check users' input whether is a invalid number(for float) or not. 
void i_check(std::istream &is = cin, float *value = NULL) 
{
  is >> *value;
  if (is.fail()) 
  {
    is.clear();
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "invalid input, please input proper val." << endl;
    i_check(is, value);
  }
}
//check users' input whether is a invalid number(for int) or not. 
void i_check(std::istream &is = cin, int *value = NULL) 
{
  is >> *value;
  if (is.fail()) 
  {
    is.clear();
    is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "invalid input, please input proper val." << endl;
    i_check(is, value);
  }
}

//chack the place user want to move whether have car already or not. 
bool check_move(int row, int col, model_car** car)
{
    int i_row = row - 1; // convert the row and col to the index.
    int i_col = col - 1;
    if (car[i_row][i_col].brand == "")
    return true;
    else 
    return false;
}

//generate treasure chart.
void creat_chart(int row, int col, model_car** car)
{
    float sum_price = 0;
    for(int i=0; i<row; i++)
    {
        cout << "|";
        for (int j =0; j<col; j++)
        {
            if (car[i][j].brand != "")
            {
                cout << car[i][j].brand[0];
                sum_price += car[i][j].price;
            }
            else
            {
                cout << "_";
            }
            cout <<"|";
        }
        cout << endl;
    }
    cout << "total price is: " << sum_price << endl;
}

//add a new car to the chart.
void add_car(int row, int col, int t_row, int t_col, model_car** car)
{
    model_car c; // make a new car
    int i_row = t_row - 1; // convert the row and col to the index.
    int i_col = t_col - 1;
    
    
    cout << "Enter brand(string): ";
    cin >> c.brand;
    cout << "Enter color(string): ";
    cin >> c.color;
    cout << "Enter length(float): ";
    cin >> c.length;
    cout << "Enter value($, float): ";
    cin >> c.price;

    car[i_row][i_col] = c;
    creat_chart (row, col, car);
}

//remove item.
void remove_car(int row, int col, int t_row, int t_col, model_car** car)
{
    int i_row = t_row - 1; // convert the row and col to the index.
    int i_col = t_col - 1;
    //if there is no model will remind user.
    if(check_move(t_row, t_col, car) == 1)
    {
        cout << "There is no model car can be remove" << endl;
    }
    else //to make a new null model to replace this model.
    {
        model_car c;
        car [i_row][i_col] = c;
        creat_chart(row, col, car);
    }
}

//generate a random model car.
void random_car(int row, int col, int t_row, int t_col, model_car** car)
{
    int i_row = t_row - 1; // convert the row and col to the index.
    int i_col = t_col - 1;
    
    //use arrary to store the brand and color.
    const string brands[] = {"BMW", "Porsche", "Lamborghini", "Ferrari"};
    const string colors[] = {"red", "yellow", "blue", "orange", "green"};
    srand(time(NULL));
    int r_color = rand() % 3;
    int r_brand = rand() % 4;
    float length =  ((float)(rand()%18))/10 + 2.3;
    float price =  ((float)(rand()%18))/10 + 2.3;
    //store the new element to this model.
    car[i_row][i_col].brand = brands[r_brand];
    car[i_row][i_col].color = colors[r_color];
    car[i_row][i_col].length = length;
    car[i_row][i_col].price = price;

    creat_chart(row, col, car);
    
}

//show the item.
void show_cars(int row, int col, int t_row, int t_col, model_car** car)
{
    int i_row = t_row - 1; // convert the row and col to the index.
    int i_col = t_col - 1;
    //to show propertries of this model.
     if(check_move(t_row, t_col, car) == 1)//check the coordinate.
    {
        cout << "There is no model car can be show." << endl;
    }
    else //to show this car.
    {
      cout << "car's brand is: " << car[i_col][i_row].brand << 
    "."<< endl;
    cout << "car's color is: " << car[i_col][i_row].color << 
    "." << endl;
    cout << "car's length is: " << car[i_col][i_row].length << 
    "cm." << endl;
    cout << "car's price is: $"<< car[i_col][i_row].price <<
    "." <<endl;
    }
}

//change the car's color.
void change_color(int row, int col, int t_row, int t_col, model_car** car)
{
    string color1 = "";
    int i_row = t_row - 1;
    int i_col = t_col - 1;
    if(check_move(t_row, t_col, car) == 1)//check the coordinate.
    {
        cout << "There is no model car can be change." << endl;
    }
    else //to do this part
    {
    cout <<"This car's color is: " << car[i_col][i_row].color<< endl;
    cout <<"What color you want to change: "<< endl;
    cin >> color1;
    car[i_col][i_row].color = color1;
    }
}

int main()
{
    int row1, col1; 
    cout << "Enter number of rows: ";
    i_check(cin, &row1); //check users' input.
    cout << "enter number of columns: ";
    i_check(cin, &col1);//check users' input.

    model_car** car = new model_car*[row1];
    for(int i=0; i<row1; i++) //to generate new chart.
    {
        car[i] = new model_car[col1];
    }
    creat_chart(row1, col1, car);
    
    do{
        int choice = 0;
        cout << "1) Add car, 2) Remove car, 3) Randomly generate a car," 
        "4)Show an individual car, 5) Change the car's color, 6) Exit game." 
             << endl;
        i_check(cin,&choice); //check users' input.
        while (!user_choose_input(choice))
        {
            cout << "place input vaild number!" << endl;
            cin >> choice;
        }
        if (choice == 1) //add a car.
        {
            int row2;
            int col2;
            cout << "Enter row: ";
            i_check(cin,&row2);//check users' input.
            cout << "Enter col: ";
            i_check(cin,&col2);//check users' input.
            add_car(row1, col1, row2, col2, car);
        }
        else if (choice == 2) //remove a car.
        {
            int row3, col3;
            cout << "Enter row: ";
            i_check(cin,&row3);//check users' input.
            while(row3 > row1)
            {
                cout << "invalid input!" << endl;
                cin >> row3;
            }
            cout << "Enter col: ";
            i_check(cin,&col3);
            while(col3 > col1)
            {
                cout << "invalid input!" << endl;
                cin >> col3;
            }
            remove_car(row1, col1, row3, row3, car);
        }
        else if (choice == 3) // generate a car.
        {
            int row4, col4;
            cout << "Enter row: ";
            i_check(cin,&row4);
            while(row4 > row1)
            {
                cout << "invalid input!" << endl;
                cin >> row4;
            }
            cout << "Enter col: ";
            i_check(cin,&col4);
            while(col4 > col1)
            {
                cout << "invalid input!" << endl;
                cin >> col4;
            }
            random_car(row1, col1, row4, row4, car);
            show_cars(row1, col1, row4, col4, car);
        }
        else if (choice == 4) //show item;
        {
            int row5, col5;
            cout << "Enter row: ";
            i_check(cin,&row5);
            while(row5 > row1)
            {
                cout << "invalid input!" << endl;
                cin >> row5;
            }
            cout << "Enter col: ";
            i_check(cin,&col5);
            while(col5 > col1)
            {
                cout << "invalid input!" << endl;
                cin >> col5;
            }
            show_cars(row1, col1, row5, col5, car);
        }
        else if (choice == 5) //change the color
        {
            int row6, col6;
            cout << "Enter row: ";
            i_check(cin,&row6);//check users' input.
            while(row6 > row1)
            {
                cout << "invalid input!" << endl;
                cin >> row6;
            }
            cout << "Enter col: ";
            i_check(cin,&col6);
            while(col6 > col1)
            {
                cout << "invalid input!" << endl;
                cin >> col6;
            }
            change_color(row1, col1, row6, col6, car);
            show_cars(row1, col1, row6, col6, car);
        }
        else if (choice == 6) //exit game.
        {
            return 0;
        }
    }while(true); //to repeat this part.

    //to free the memory. 
    for(int i=0; i< col1; i++)
    {
        delete[]car[i];
    }
    delete[]car;
    
    return 0;
}
