#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

double calculateRoot(double number, double xOld, int iterations, double error, int errorPower, ofstream& outFile);

int main(){

double userApproxNumber = 0.0;
double userGuess = 0.0;
int maxIT = 0;
int errorPower = 0;
double calculatedRoot = 0.0;
double error = 0.0;
ofstream outFile;


	outFile.open("hw1Results.txt", ios::app);
	
	cout << "Enter number to approximate square root: " << endl;
	cin >> userApproxNumber;
	outFile << "a = " << userApproxNumber << endl;
	cout << "Enter a guess for the square root: " << endl;
	cin >> userGuess;
	outFile << "Guess: " << userGuess << endl;
	cout << "Enter max number of iterations: " << endl;
	cin >> maxIT;
	outFile << "Max Iterations: " << maxIT << endl;
	cout << "Enter the error for the approximation: " << endl;
	cin >> errorPower;
	error = pow(10, (-1) * errorPower);
	outFile << "Error: " << error << endl;

	outFile << endl;
	outFile << endl;
	outFile << "Output:" << endl;
	outFile << fixed << setprecision(errorPower + 1) << userGuess << endl;
	
	calculatedRoot = calculateRoot(userApproxNumber, userGuess, maxIT, error, errorPower, outFile);

	cout << "Root: " << fixed << setprecision(errorPower + 1) << calculatedRoot << endl;

	outFile.close();

	return 0;
}

double calculateRoot(double number, double xOld, int iterations, double error, int errorPower, ofstream& outFile){

	int i = 0;
	double xNew = 0.0;
	double deriv = 0.0;
	double xOldHolder = 0.0;
	
	for(i = 0; i < iterations; i++){
		
		deriv = 2 * xOld;
		
		if(deriv == 0){
			cout << "Program failed due to a singularity (divide by zero)." << endl;
			outFile << "Program failed due to a singularity (divide by zero)." << endl;
			exit(-1);
		}
		
		xNew = xOld - ((pow(xOld,2) - number) / deriv);
		outFile << fixed << setprecision(errorPower + 1) << xNew << endl;
		
		
		if(abs(xOld - xNew) < error){
			outFile << endl;
			outFile << "Root: " << fixed << setprecision(errorPower + 1) << xNew << endl;
			outFile << endl;
			return xNew;
			
		}
		else{
			xOldHolder = xOld;
			xOld = xNew;
		}
	}
	
	
	
		cout << "Newton's method failed to converge in " << iterations << " iterations." << endl;
		outFile << "Newton's method failed to converge in " << iterations << " iterations." << endl;
		outFile << endl;
		return(-1);
	
	
	
	
}
