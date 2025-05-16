#include<iostream>
using namespace std;
int bookcount = 0;
const int maxsize = 100;
//arrays
int bookids[maxsize];
string booktitles[maxsize];
string bookauthors[maxsize];
bool isborrowed[maxsize];
//finction for adding a book
void add_a_book() {
	if (bookcount >= maxsize)
	{
		cout << "Sorry the library in fulled" << endl;

	}

	cout << "Enter the ID of the book" << endl;
	cin >> bookids[bookcount];
	cout << "Enter the name of the book" << endl;
	cin >> booktitles[bookcount];
	cout << "Enter the author name of" << endl;
	cin >> bookauthors[bookcount];
	isborrowed[bookcount] = false;
	bookcount++;
	cout << "Book added successfully!" << endl;
}
//end of add book function
//function to display all the books
void displaybooks() {

	if (bookcount == 0) {
		cout << "I have no books to display" << endl;
	}

	for (int i = 0; i < bookcount; i++) {
		cout << "Book id is : " << bookids[i] << endl;
		cout << "Book Name is : " << booktitles[i] << endl;
		cout << "Book Author is : " << bookauthors[i] << endl;
		if (isborrowed[i]) {
			cout << "Borrowed";
		}
		else {
			cout << "Available";
		}

		cout << endl;
	}
}
//end display function
// function for borrowing a book
void borrowbook() {
	if (bookcount == 0) {
		cout << "No books in the library." << endl;
		return;
	}
	int id;
	cout << "Enter the id of the book you want to borrow" << endl;
	cin >> id;
	for (int i = 0; i < bookcount; i++) {
		if (bookids[i] == id) {
			if (isborrowed[i])
			{
				cout << " The book is already borrowed" << endl;
			}
			else {
				isborrowed[i] = true;
				cout << "You have borrowed the book." << endl;

			}
		}
	}

}
//end
//start of function returning a book
void returnabook() {
	int id;
	cout << "Enter the id of the book you want to return" << endl;
	cin >> id;
	for (int i = 0; i < bookcount; i++) {
		if (bookids[i] == id) {
			if (isborrowed[i]) {
				isborrowed[i] = false;
				cout << "Book returned!" << endl;
			}
			else {
				cout << "Book is not borrowed" << endl;
			}
			return;
		}
	}
	cout << "Book not found" << endl;
}// end
//menu function
void menu() {
	int choice;
	do {
		cout << "\nLibrary Management System\n";
		cout << "1. Add a new book to the library" << endl;
		cout << "2. Display All Books" << endl;
		cout << "3. Borrow a Book" << endl;
		cout << "4. Return a Book" << endl;
		cout << "5. Exit" << endl;
		cout << "Enter your choice: " << endl;
		cin >> choice;

		switch (choice) {
		case 1: add_a_book(); break;
		case 2: displaybooks(); break;
		case 3: borrowbook(); break;
		case 4: returnabook(); break;
		case 5: cout << "Exiting the system. Goodbye!\n"; break;
		default: cout << "Invalid choice. Please try again.\n";
		}
	} while (choice != 5);
	//end of menu
}
int main() {
	menu();
}