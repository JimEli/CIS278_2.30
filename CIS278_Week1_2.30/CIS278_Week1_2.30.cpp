/*************************************************************************
* Title: Body Mass Index Calculator 
* File: CIS278_Week1_2.30.cpp
* Author: James Eli
* Date: 1/17/2018
*
* Exercise 2.30 on page 71 - (Body Mass Index Calculator)
*   BMI = pounds*703 / inches*inches
* or,
*   BMI = kilos / meters*meters
* Create a BMI calculator application that reds the user’s weight in pounds 
* and height in inches (or kilograms and meters), then calculates and 
* displays the user’s BMI. Also, the application should display the 
* following information from the Department of Health and Human 
* Services/NIH so the user can evaluate his/her BMI:
* 
*   BMI VALUES
*   Underweight: less than 18.5
*   Normal:      between 18.5 and 24.9
*   Overweight:  between 25 and 29.9
*   Obese:       30 or greater
*
* Notes:
*  (1) Compiled with MS Visual Studio 2017 Community (v141).
*
* Submitted in partial fulfillment of the requirements of PCC CIS-278.
*************************************************************************
* Change Log:
*   01/1/2018: Initial release. JME
*************************************************************************/
#include <iostream>  // cin/cout
#include <iomanip>   // fixed/setprecision
#include <cassert>   // assert
#include "input.cpp" // numeric input routines

using namespace std;

int main()
{
	double weight { 0. }; // User input of body weight in pounds.
	double height { 0. }; // User input of body height in inches.
	double bmi{ 0. };     // Calculated Body Mass Index (BMI).

	// Display program purpose.
	cout << "Body Mass Index (BMI) Calculator\n\n";

	if (
		getNumber<double>("Enter your weight in pounds: ", weight, 1., 500.) &&
		getNumber<double>("Enter your height in inches: ", height, 1., 108.)
		) 
	{
		assert(height != 0.); // Prevent division by zero.

		// Calculate and display bmi (to 1 decimal place).
		bmi = weight * 703. / (height * height);
		cout << "\nYour BMI is " << fixed << setprecision(1) << bmi << endl;
	
		// Display HHS/HIH BMI standards.
		cout << "\nBMI VALUES (per US HHS/NIH)\n"
			" Underweight: less than 18.5\n"
			" Normal:      between 18.5 and 24.9\n"
			" Overweight:  between 25 and 29.9\n"
			" Obese:       30 or greater\n\n";
	}
	else
	{
		// Input failed.
		cout << "No valid input received, program terminating.\n";
		return EXIT_FAILURE;
	}

	return 0;
}

