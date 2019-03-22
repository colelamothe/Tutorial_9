// Tutorial #9 Files
// Cole Lamothe 100711084

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

int main() {
	// Example One:
	/*
	// Variable declaration
	string fileName = "C:\\Users\\100711084\\source\\repos\\Tutorial_9\\numbers.dat";
	int sum = 0;
	int number, nextNumber, counter(0);

	ifstream inFile(fileName); // opens the file and gets the first number
	if (inFile.fail()) {
		cout << "The file was not able to be opened" << endl;
		exit;
	}
	else {
		inFile >> number;
	}
	

	while (!inFile.eof()) { // checks for the end of the file and continues if there still is data
		cout << "Number of items in this set: " << number << endl;
		for (int i = 0; i < number; ++i) { // uses the first number as a register to grab the subsequent set of numbers
			inFile >> nextNumber;
			sum += nextNumber;
			cout <<" " << nextNumber << " ";
			counter++;
		}
		
		cout << "\nThe average is: " << (double)sum / counter << endl; // Calculates the average.
		counter = 0;
		sum = 0;
		inFile >> number;
	}

	inFile.close();
	*/
	// Example Two:

	// Variable Declaration

	string outFilePath("C:\\Users\\100711084\\source\\repos\\Tutorial_9\\leagueGameData.txt");
	ofstream outFile(outFilePath);
	fstream::app; // changes the default file output style to append.
	string champion;
	string win;
	int kills, deaths, assists;
	char entries = 'Y';

	int totalKills(0), totalDeaths(0), totalAssists(0), winCount(0), lossCount(0);
	int counter = 0;

	if (outFile.fail()) { // ends the program if the output file cannot be opened to alert the user there is an issue
		cout << "Output file failed to be opened" << endl;
		exit;
	}
	do {
			
		++counter;
		cout << "Please enter your latest game statistics: " << endl;
		cout << "Enter the name of your champion: " << endl;
		// Since we are looping and using cin later in the program we need to clear the input to receive the string properly
		cin.clear();
		cin.ignore();
		getline(cin, champion);
		cout << "Game result (win/loss) : " << endl;
		getline(cin, win);
		while (win != "win" && win != "loss") { // validates the input for the one string we are checking for statistics. 
			cout << "Invalid game result. Please enter 'win' or 'loss' : " << endl;
			getline(cin, win);
		}
		cout << "Enter number of kills: " << endl;
		cin >> kills;
		cout << "Enter the number of assists: " << endl;
		cin >> assists;
		cout << "Enter the number of deaths: " << endl;
		cin >> deaths;

		// increment global session counters.
		totalKills += kills;
		totalDeaths += deaths;
		totalAssists += assists;
		if (win == "win") {
			winCount += 1;
		}
		else if (win == "loss") {
			lossCount += 1;
		}

		// command line output
		cout << "\nGame " << counter << " summary: " << endl;
		cout << "Champion: " << champion << endl;
		cout << "Number of kills: " << kills << endl;
		cout << "Number of assists: " << assists << endl;
		cout << "Number of deaths: " << deaths << endl;
		cout << "Game result: " << win << endl;

		// file output
		outFile << "\nGame " << counter << " summary: " << endl;
		outFile << "Champion: " << champion << endl;
		outFile << "Number of kills: " << kills << endl;
		outFile << "Number of assists: " << assists << endl;
		outFile << "Number of deaths: " << deaths << endl;
		outFile << "Game result: " << win << endl;
	
		// looping prompt
		cout << "Would you like to enter another set of game data? (Y/N) " << endl;
		cin >> entries;
		entries = toupper(entries);
	} while (entries == 'Y');

	// Command line output
	cout << "\nSession statistics: " << endl;
	cout << "Total games logged: " << counter << endl;
	cout << "Average kills: " << (double)totalKills / counter << endl;
	cout << "Average assists: " << (double)totalAssists / counter << endl;
	cout << "Average deaths: " << (double)totalDeaths / counter << endl;
	cout << "Average win pecentage: " << ((double)winCount / (winCount + lossCount)) * 100 << "%" << endl;

	// File output
	outFile << "\nSession statistics: " << endl;
	outFile << "Total games logged: " << counter << endl;
	outFile << "Average kills: " << (double)totalKills / counter << endl;
	outFile << "Average assists: " << (double)totalAssists / counter << endl;
	outFile << "Average deaths: " << (double)totalDeaths / counter << endl;
	outFile << "Average win pecentage: " << ((double)winCount / (winCount + lossCount)) * 100 << "%" << endl;



	





	system("pause");
	return 0;
}