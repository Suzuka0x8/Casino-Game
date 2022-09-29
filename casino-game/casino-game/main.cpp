#include <iostream>
#include <string>
#include <cstdlib> // Lesen sie sich random durch kappa
#include <ctime>
#include <Windows.h>

using namespace std;

void drawLine(int n, char symbol);
void rules();

int main()
{
	SetConsoleTitleA("Casino Spiel");
	string playerName;
	int amount; // Guthaben vom Spieler
	int bettingAmount;
	int guess;
	int dice; // Random nummer { Herr Schulz }
	char choice;

	srand(time(0)); // "Seed" Random nummer

	drawLine(120, '_');
	cout << "\n\n\n\t\tCASINO SPIEL\n\n\n\n";
	drawLine(120, '_');

	cout << "\n\n Gebe Deinen Namen Ein : ";
	getline(cin, playerName);

	cout << "\n\n Geben Sie den Einzahlungsbetrag ein, um das Spiel zu spielen : $";
	cin >> amount;

	do
	{
		system("cls");
		rules();
		cout << "\n\nIhr aktuelles Guthaben betraegt $ " << amount << "\n";

				// Einsatzbetrag des Spielers
		do
		{
			cout << playerName << " , geben Sie das zu setzende Geld ein : $";
			cin >> bettingAmount;
			if (bettingAmount > amount)
				cout << "Ihr Einsatzbetrag ist hoeher als Ihr aktuelles Guthaben\n"
					<< "\nDaten bitte neu eingeben\n ";
		} while (bettingAmount > amount);

				// Nummer vom spieler
		do
		{
			cout << "Erraten Sie Ihre Zahl, um zwischen 1 und 10 zu wetten : ";
			cin >> guess;
			if (guess <= 0 || guess > 10)
				cout << "\nBitte überpruefen Sie die Nummer!! Sie sollte zwischen 1 und 10 liegen\n"
				<< "\nDaten bitte neu eingeben\n ";
		} while (guess <= 0 || guess > 10);

		dice = rand() % 10 + 1; // Enthält die zufällig generierte Ganzzahl zwischen 1 und 10

		if (dice == guess)
		{
			cout << "\n\nViel Glueck!! Du hast Gewonnen : $ " << bettingAmount * 10;
			amount = amount + bettingAmount * 10;
		}
		else
		{
			cout << "\nNaechstes mal vielleicht !! Du hast Verloren : $ " << bettingAmount << "\n";
			amount = amount + bettingAmount;
		}

		cout << "\nDie Gewinnerzahl war : " << dice << "\n";
		cout << "\n" << playerName << ", Du hast : $ " << amount << "\n";
		if (amount == 0)
		{
			cout << "Du hast kein Geld mehr um zu spielen ";
			break;
		}
		cout << "\n\n-->Moechtest du nochmal spielen (j/n)? ";
		cin >> choice;
	} while (choice == 'J' || choice == 'j');

		cout << "\n\n\n";
		drawLine(120, '=');
		cout << "\n\nDanke fuers spielen. Dein Guthaben betraegt $ " << amount << "\n\n";
		drawLine(120, '=');

		return 0;
}

void drawLine(int n, char symbol)
{
	for (int i = 0; i < n; i++)
		cout << symbol;
	cout << "\n";
}

void rules()
{
	system("cls");
	cout << "\n\n";
	drawLine(120, '-');
	cout << "\t\tREGELN VOM SPIEL\n";
	drawLine(120, '-');
	cout << "\t1. Waehle eine nummer zwischen 1 bis 10\n";
	cout << "\t2. Wenn du gewinnst, kriegst du das 10 fache zurueck\n";
	cout << "\t3. Wenn du auf die falsche zahl wettest, wirst du dein Einsatzbetrag verlieren\n\n";
	drawLine(120, '-');
}
