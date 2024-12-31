
#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h> // For Sleep function

using namespace std;

struct Book {
    int id;
    string title;
    string author;
    int copies;
};

void clearScreen() {
    system("cls"); // Clear screen for Windows
}

void pause(int seconds) {
    Sleep(seconds * 1000); // Convert seconds to milliseconds
}

void displayBooks(Book library[], int size) {
    clearScreen();
    cout << "===================================" << endl;
    cout << "           Library Books           " << endl;
    cout << "===================================" << endl;
    if (size == 0) {
        cout << "No books available in the library!" << endl;
    } else {
        cout << left << setw(5) << "ID"
             << setw(30) << "Title"
             << setw(20) << "Author"
             << setw(10) << "Copies" << endl;
        cout << "-----------------------------------" << endl;
        for (int i = 0; i < size; ++i) {
            cout << left << setw(5) << library[i].id
                 << setw(30) << library[i].title
                 << setw(20) << library[i].author
                 << setw(10) << library[i].copies << endl;
        }
    }
    cout << "===================================" << endl;
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

void addBook(Book library[], int &size, int max_size) {
    clearScreen();
    if (size >= max_size) {
        cout << "Library is full!" << endl;
        pause(2);
        return;
    }

    int id, copies;
    string title, author;

    cout << "Enter book ID: ";
    cin >> id;
    cin.ignore();
    cout << "Enter book title: ";
    getline(cin, title);
    cout << "Enter book author: ";
    getline(cin, author);
    cout << "Enter number of copies: ";
    cin >> copies;

    library[size] = {id, title, author, copies};
    size++;
    cout << "Book added successfully!" << endl;
    pause(2);
}

void updateBookCopies(Book library[], int size, int id, int new_copies) {
    clearScreen();
    for (int i = 0; i < size; ++i) {
        if (library[i].id == id) {
            library[i].copies = new_copies;
            cout << "Copies of the book with ID " << id << " updated to " << new_copies << endl;
            pause(2);
            return;
        }
    }
    cout << "Book not found!" << endl;
    pause(2);
}

void removeBook(Book library[], int &size, int id) {
    clearScreen();
    for (int i = 0; i < size; ++i) {
        if (library[i].id == id) {
            for (int j = i; j < size - 1; ++j) {
                library[j] = library[j + 1];
            }
            size--;
            cout << "Book with ID " << id << " removed from the library." << endl;
            pause(2);
            return;
        }
    }
    cout << "Book not found!" << endl;
    pause(2);
}

void searchBook(Book library[], int size, int id) {
    clearScreen();
    for (int i = 0; i < size; ++i) {
        if (library[i].id == id) {
            cout << "Book Found!" << endl;
            cout << "ID: " << library[i].id << endl;
            cout << "Title: " << library[i].title << endl;
            cout << "Author: " << library[i].author << endl;
            cout << "Copies: " << library[i].copies << endl;
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
            return;
        }
    }
    cout << "Book not found!" << endl;
    pause(2);
}

int main() {
    const int MAX_BOOKS = 100;
    Book library[MAX_BOOKS];
    int library_size = 0;


int choice;
    do {
        clearScreen();
        cout << "===================================" << endl;
        cout << "     Library Management System     " << endl;
        cout << "===================================" << endl;
        cout << "1. Display Books" << endl;
        cout << "2. Add Book" << endl;
        cout << "3. Update Book Copies" << endl;
        cout << "4. Remove Book" << endl;
        cout << "5. Search Book" << endl;
        cout << "6. Exit" << endl;
        cout << "===================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayBooks(library, library_size);
                break;
            case 2:
                addBook(library, library_size, MAX_BOOKS);
                break;
            case 3: {
                int id, new_copies;
                cout << "Enter book ID to update: ";
                cin >> id;
                cout << "Enter new number of copies: ";
                cin >> new_copies;
                updateBookCopies(library, library_size, id, new_copies);
                break;
            }
            case 4: {
                int id;
                cout << "Enter book ID to remove: ";
                cin >> id;
                removeBook(library, library_size, id);
                break;
            }
            case 5: {
                int id;
                cout << "Enter book ID to search: ";
                cin >> id;
                searchBook(library, library_size, id);
                break;
            }
            case 6:
                cout << "Exiting the system. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Try again!" << endl;
                pause(2);
                break;
        }
    } while (choice != 6);

    return 0;
}