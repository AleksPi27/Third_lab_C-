// ThirdProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

struct point { int x; int y; };
const int PENTAGON_SIDES_NUMBER = 5;

point* inputPentagonCoords() {
    point* pentagonCoords = new point[PENTAGON_SIDES_NUMBER];

    for (unsigned int i = 0; i < PENTAGON_SIDES_NUMBER; ++i) {
        cout << "Enter x coord of "<<i<<"-th side: ";
        cin >> pentagonCoords[i].x;
        cout << "Enter y coord of " << i << "-th side: ";
        cin >> pentagonCoords[i].y;
    }
    return pentagonCoords;
}

double calculateSideLength(int firstSideX, int firstSideY, int secondSideX, int secondSideY) {
    return sqrt(pow((firstSideX - secondSideX), 2)- pow((firstSideY - secondSideY), 2));
}

double calculateTriangleSquare(point firstSide, point secondSide, point thirdSide) {
    point* trianglePoints = new point[3]{firstSide, secondSide,thirdSide};
    double square = 0;
    for (unsigned int i = 0; i < 3; ++i) {
        square += (trianglePoints[i].x * trianglePoints[(i + 1)%3].y - trianglePoints[(i + 1) % 3].x * trianglePoints[i].y);
    }

    return fabs(square)*0.5;
}

double calculatePentagonSquare(point* pentagonCoords) {
    double firstTriangleSquare = calculateTriangleSquare(pentagonCoords[0], pentagonCoords[1], pentagonCoords[4]);
    cout << "firstTriangleSquare "<<firstTriangleSquare << endl; //2
    double secondTriangleSquare = calculateTriangleSquare(pentagonCoords[1], pentagonCoords[2], pentagonCoords[3]);
    cout << "secondTriangleSquare " << secondTriangleSquare << endl; //1
    double thirdTriangleSquare = calculateTriangleSquare(pentagonCoords[1], pentagonCoords[3], pentagonCoords[4]);
    cout << "thirdTriangleSquare " << thirdTriangleSquare << endl; //3

    return firstTriangleSquare + secondTriangleSquare + thirdTriangleSquare;
}

double simpleCubicRoot(double number) {
    return pow(number, 1.0/3);
}

double iterativeCalculationOfCubicRoot(double number) {
    double x_i_1 = number;
    double x_i = 0;
    while (true) {
        x_i = (1.0 / 3) * (number / pow(x_i_1, 2) + 2 * x_i_1);
        if (abs(x_i_1 - x_i) < pow(10, -5)) {
            break;
        }
        x_i_1 = x_i;
    }
    return x_i;
}

double calculateTriangleSqr(double a) {
    return pow(a, 2) * sqrt(3) / 4;
}

double calculateTriangleSqr(double a, double b, double c) {
    double semiPerimeter = (a + b + c) / 2;
    return sqrt(semiPerimeter * (semiPerimeter - a) * (semiPerimeter - b) * (semiPerimeter - c));
}

void thirdTask() {
    int opt = -1;
    cout << "Enter what type of trianle you are going to work with (0 - equilateral; 1 - versatile): ";
    cin >> opt;

    if (opt == 0) {
        double a;
        cout << "Enter side of equilateral triangle: ";
        cin >> a;
        cout <<"Square of the equilateral triangle: " << calculateTriangleSqr(a);
    }
    else if (opt == 1) {
        double a;
        cout << "Enter the first side of equilateral triangle: ";
        cin >> a;
        double b;
        cout << "Enter the second side of equilateral triangle: ";
        cin >> b;
        double c;
        cout << "Enter the third side of equilateral triangle: ";
        cin >> c;
        cout << "Square of the versatile triangle: " << calculateTriangleSqr(a, b, c);
    }
}

int inputN() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    return n;
}

int seriesSum(int n) {
    if (n == 0) {
        return -1;
    }
   else if (n == 1) {
        return 5;
    }
    else {
        return 5 * n + seriesSum(n - 1);
    }
}

double inputNumberForCubicRoot() {
    double x;
    cout << "Enter a number for cubic root calculation: ";
    cin >> x;
    return x;
}

int decimalToBinary() {
    int x;
    cout << "Enter an integer you want to convert to binary system: ";
    cin >> x;
    return x;
}

string convertation(int n) {
    if (n == 0) { return ""; }
    else return convertation(n / 2) + to_string(n % 2);
}

int main()
{
    //point* pentagonCoords = inputPentagonCoords();
    //std::cout << "Square of the pentagon: "<< calculatePentagonSquare(pentagonCoords)<<endl;

   // double number = inputNumberForCubicRoot();
    //cout << "Cubic root from " << number << " equals to " << simpleCubicRoot(number)<<endl;
   //  cout << "Cubic root from " << number << " equals to " << iterativeCalculationOfCubicRoot(number) << endl;

    //thirdTask();

    //int n = inputN();
    //cout << "Sum of the series: " << seriesSum(n) << endl;

    int n = decimalToBinary();
    cout << "Binary from decimal integer: " << convertation(n) << endl;
}