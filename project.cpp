#include <iostream>
#include <fstream>
#include <vector>
#include <conio.h>

using namespace std;

class User {
	private:
		string username;
		string password;

	public:
		User() {}
		User(const string& uname, const string& pass) {
			username = uname;
			password = pass;
		}

		const string& getUsername() const {
			return username;
		}

		bool authenticate(const string& uname, const string& pass) const {
			return (username == uname && password == pass);
		}

		void displayWelcomeMessage() const {
			cout << "\t---------------- Welcome To User Home Screen ----------------" << endl << endl;
			cout << "\t Press 1 to Book Ticket" << endl;
			cout << "\t press 2 to view Ticketing History" << endl;
			cout << "\t Press 3 to Logout" << endl;
			cout << endl << "Enter The Number of Your choice : ";
		}
};

class Ticket {
	private:
		string from;
		string to;
		string airline;
		int fare;

	public:
		Ticket() {}
		Ticket(const string& src, const string& dest, const string& air, int price) {
			from = src;
			to = dest;
			airline = air;
			fare = price;
		}

		const string& getFrom() const {
			return from;
		}
		const string& getTo() const {
			return to;
		}
		const string& getAirline() const {
			return airline;
		}
		int getFare() const {
			return fare;
		}
};

class FlightManager {
	public:
		static vector<Ticket> getAvailableFlights(const string& from, const string& to) {
			vector<Ticket> availableFlights;
			ifstream file("flights.txt");
			string src, dest, air;
			int price;
			while (file >> src >> dest >> air >> price) {
				if (to == dest && from == src) {
					Ticket ticket(src, dest, air, price);
					availableFlights.push_back(ticket);
				}
			}
			file.close();

			return availableFlights;
		}
};

class TicketingSystem {
	public:
		void displayCities() {
			ifstream file("cities.txt");
			int count = 0;
			string city;

			while (file >> city) {
				cout << count + 1 << " " << city << endl;
				count++;
			}
			file.close();
		}

		static void displayHistory(const string& username) {
			ifstream file("history.txt");
			string line;
			bool isfound = false;

			cout << "\t---------------- Purchase History ----------------" << endl << endl;
			while (getline(file, line)) {
				if (line.find(username) != string::npos) {
					cout << "\t" << line << endl;
					isfound = true;
				}
			}

			if (!isfound) {
				cout << "No Purchase History found" << endl;
			}

			file.close();
		}
};

class App {
	private:
		User currentUser;
		TicketingSystem ticketingSystem;

	public:
		void startApp() {
			displayIntro();
		}

		void displayIntro() {
			int choice;
			system("cls");
			system("Color 0C");

			cout << "\t---------------- Welcome To Airline Ticketing Software ----------------" << endl << endl;
			cout << "\tPress 1 for Login" << endl;
			cout << "\tpress 2 for Registration" << endl;
			cout << "\tPress 4 to Quit App" << endl;
			cout << endl << "Enter Number of Your choice : ";
			cin >> choice;

			if (choice == 1) {
				login();
			} else if (choice == 2) {
				registration();
			} else if (choice == 4) {
				cout << endl << "\t Thank you for using our service. Visit us again!" << endl;
			} else {
				cout << endl << "\t Invalid Input";
				displayIntro();
			}
		}

		void login() {
			string username, password;
			system("cls");
			cout << "\t---------------- Welcome To User Login Page ----------------" << endl << endl;
			cout << "\tEnter Your username : ";
			cin >> username;
			cout << "\tEnter Your Password : ";

			int ch = getch();
			while (ch != 13) {
				if (ch == 8) {
					if (!password.empty()) {
						cout << "\b \b";
						password.erase(password.size() - 1);
					}
				} else {
					password.push_back(ch);
					cout << '*';
				}
				ch = _getch();
			}

			ifstream file("registered.txt");
			bool isfound = false;
			string un, pw;
			while (file >> un >> pw) {
				if (currentUser.authenticate(username, password)) {
					isfound = true;
					break;
				}
			}
			file.close();

			if (isfound) {
				home(username);
			} else {
				cout << endl << "\tWrong Username Or Password. Try Again" << endl;
				displayRedirectOptions();
			}
		}

		void registration() {
			string username, password;
			system("cls");
			cout << "\t---------------- Welcome To User Registration Page ----------------" << endl << endl;
			cout << "\tEnter Your username : ";
			cin >> username;
			cout << "\tEnter Your Password : ";

			int ch = getch();
			while (ch != 13) {
				if (ch == 8) {
					if (!password.empty()) {
						cout << "\b \b"; // Erase the character from the screen
						password.erase(password.size() - 1);
					}
				} else {
					password.push_back(ch);
					cout << '*';
				}
				ch = _getch();
			}

			ifstream file("registered.txt");
			bool isfound = false;
			string un, pw;
			while (file >> un >> pw) {
				if (un == username) {
					isfound = true;
					break;
				}
			}
			file.close();

			if (isfound) {
				cout << endl << "You are already registered." << endl;
				displayRedirectOptions();
			} else {
				ofstream files("registered.txt", ios::app);
				files << username << " " << password << endl;
				files.close();
				cout << endl;
				cout << "\tRegistration Successful! Now you can login and enjoy our services." << endl;
				displayRedirectOptions();
			}
		}

		void home(const string& username) {
			int c;
			currentUser = User(username, "");
			currentUser.displayWelcomeMessage();
			cin >> c;
			if (c == 1) {
				bookTicket(username);
			} else if (c == 2) {
				TicketingSystem::displayHistory(username);
				displayRedirectOptions();
			} else if (c == 3) {
				displayIntro();
			}
		}

		void bookTicket(const string& username) {
			int c, count;
			system("cls");
			cout << "\t---------------- Welcome To Ticket Booking ----------------" << endl << endl;
			cout << "\tAvailable Flights:" << endl;
			TicketingSystem ts;
			ts.displayCities();
			cout << "\n\tSelect Source City (enter the number): ";
			cin >> c;

			if (c < 1 || c > count) {
				cout << "\tInvalid Input" << endl;
				bookTicket(username);
				return;
			}

			string sourceCity;
			ifstream file("cities.txt");
			for (int i = 0; i < c; ++i) {
				file >> sourceCity;
			}
			file.close();

			cout << "\n\tAvailable Destinations from " << sourceCity << ":" << endl;

			ts.displayCities();
			cout << "\n\tSelect Destination City (enter the number): ";
			cin >> c;
			if (c < 1 || c > count) {
				cout << "\tInvalid Input" << endl;
				bookTicket(username);
				return;
			}

			string destCity;
			file.open("cities.txt");
			for (int i = 0; i < c; ++i) {
				file >> destCity;
			}
			file.close();
			vector<Ticket> availableFlights = FlightManager::getAvailableFlights(sourceCity, destCity);
			cout << "\n\tAvailable Flights from " << sourceCity << " to " << destCity << ":" << endl;
			for (vector<Ticket>::const_iterator it = availableFlights.begin(); it != availableFlights.end(); ++it) {
				const Ticket& flight = *it;
				cout << "\t" << flight.getAirline() << "\tFare: $" << flight.getFare() << endl;
			}

			cout << "\n\tSelect a Flight (enter the number): ";
			cin >> c;
			if (c < 1 || c > availableFlights.size()) {
				cout << "\tInvalid Input" << endl;
				bookTicket(username);
				return;
			}

			Ticket selectedFlight = availableFlights[c - 1];
			cout << "\n\tBooking Confirmation:" << endl;
			cout << "\tFrom: " << selectedFlight.getFrom() << endl;
			cout << "\tTo: " << selectedFlight.getTo() << endl;
			cout << "\tAirline: " << selectedFlight.getAirline() << endl;
			cout << "\tFare: $" << selectedFlight.getFare() << endl;
			ofstream historyFile("history.txt", ios::app);
			historyFile << username << "\t" << selectedFlight.getFrom() << " to " << selectedFlight.getTo()
			            << "\t" << selectedFlight.getAirline() << "\t" << selectedFlight.getFare() << endl;
			historyFile.close();

			displayRedirectOptions();
		}

		void displayRedirectOptions() {
			int choice;
			cout << "\n\tPress 1 to go back to the main menu" << endl;
			cout << "\tPress 2 to quit the application" << endl;
			cout << "\n\tEnter Number of Your choice : ";
			cin >> choice;

			if (choice == 1) {
				displayIntro();
			} else if (choice == 2) {
				cout << endl << "\t Thank you for using our service. Visit us again!" << endl;
			} else {
				cout << endl << "\tInvalid Input" << endl;
				displayRedirectOptions();
			}
		}
};

int main() {
	App app;
	app.startApp();

}
