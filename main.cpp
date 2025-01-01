#include <iostream>
#include <iomanip>
#include <vector>
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

void displayBooks(const vector<Book> &library) {
    clearScreen();
    cout << "===================================" << endl;
    cout << "           Library Books           " << endl;
    cout << "===================================" << endl;
    if (library.empty()) {
        cout << "No books available in the library!" << endl;
    } else {
        cout << left << setw(5) << "ID"
             << setw(30) << "Title"
             << setw(20) << "Author"
             << setw(10) << "Copies" << endl;
        cout << "-----------------------------------" << endl;
        for (size_t i = 0; i < library.size(); ++i) {
            const Book &book = library[i];
            cout << left << setw(5) << book.id
                 << setw(30) << book.title
                 << setw(20) << book.author
                 << setw(10) << book.copies << endl;
        }
    }
    cout << "===================================" << endl;
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

void addBook(vector<Book> &library, int max_size) {
    clearScreen();
    if (library.size() >= max_size) {
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

    library.push_back({id, title, author, copies});
    cout << "Book added successfully!" << endl;
    pause(2);
}

void updateBookCopies(vector<Book> &library, int id, int new_copies) {
    clearScreen();
    for (size_t i = 0; i < library.size(); ++i) {
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

void removeBook(vector<Book> &library, int id) {
    clearScreen();
    for (auto it = library.begin(); it != library.end(); ++it) {
        if (it->id == id) {
            library.erase(it);
            cout << "Book with ID " << id << " removed from the library." << endl;
            pause(2);
            return;
        }
    }
    cout << "Book not found!" << endl;
    pause(2);
}

void searchBook(const vector<Book> &library, int id) {
    clearScreen();
    for (size_t i = 0; i < library.size(); ++i) {
        const Book &book = library[i];
        if (book.id == id) {
            cout << "Book Found!" << endl;
            cout << "ID: " << book.id << endl;
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            cout << "Copies: " << book.copies << endl;
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
    vector<Book> library;

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
                displayBooks(library);
                break;
            case 2:
                addBook(library, MAX_BOOKS);
                break;
            case 3: {
                int id, new_copies;
                cout << "Enter book ID to update: ";
                cin >> id;
                cout << "Enter new number of copies: ";
                cin >> new_copies;
                updateBookCopies(library, id, new_copies);
                break;
            }
            case 4: {
                int id;
                cout << "Enter book ID to remove: ";
                cin >> id;
                removeBook(library, id);
                break;
            }
            case 5: {
                int id;
                cout << "Enter book ID to search: ";
                cin >> id;
                searchBook(library, id);
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