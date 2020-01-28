#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double calculateRoot(double number, double xOld, int iterations, double error, int errorPower);

int main(){

double userApproxNumber = 0.0;
double userGuess = 0.0;
int maxIT = 0;
int errorPower = 0;
double calculatedRoot = 0.0;
double error = 0.0;

	cout << "Enter number to approximate square root: " << endl;
	cin >> userApproxNumber;
	cout << "Enter a guess for the square root: " << endl;
	cin >> userGuess;
	cout << "Enter max number of iterations: " << endl;
	cin >> maxIT;
	cout << "Enter the error for the approximation: " << endl;
	cin >> errorPower;
	
	error = pow(10, (-1) * errorPower);
	
	
	calculatedRoot = calculateRoot(userApproxNumber, userGuess, maxIT, error, errorPower);

	cout << "Root: " << fixed<< setprecision(errorPower + 1) << calculatedRoot << endl;

	return 0;
}

double calculateRoot(double number, double xOld, int iterations, double error, int errorPower){

	int i = 0;
	double xNew = 0.0;
	double deriv = 0.0;
	double xOldHolder = 0.0;
	
	for(i = 0; i < iterations; i++){
		
		deriv = 2 * xOld;
		
		if(deriv == 0){
			cout << "Program failed due to a singularity (divide by zero)." << endl;
			exit(-1);
		}
		
		xNew = xOld - ((pow(xOld,2) - number) / deriv);
		
		if(abs(xOld - xNew) < error){
			break;
		}
		else{
			xOldHolder = xOld;
			xOld = xNew;
		}
	}
	
	
	
	if(abs(xOldHolder - xNew) >= error){
		cout << "Newton's method failed to converge in " << iterations << " iterations." << endl;
		exit(-1);
	}
	else{
		return xNew;
	}
	
	
}
