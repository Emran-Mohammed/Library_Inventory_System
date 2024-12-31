#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
using namespace std;


struct Book {
    int id;
    string title;
    string author;
    int copies;
};

void clearscreen(){
    system("cls");
}
void pause(int seconds){
    Sleep(seconds * 1000);
}


void displayLibrary(Book library[], int no_book){
    clearscreen();
    cout << "===================================" << endl;
    cout << "           Library Books           " << endl;
    cout << "===================================" << endl;
    if (no_book == 0) {
        cout << "No books available in the library!" << endl;
    } else {
        cout << left << setw(5) << "ID"
             << setw(30) << "Title"
             << setw(20) << "Author"
             << setw(10) << "Copies" << endl;
        cout << "-----------------------------------" << endl;
        for (int i = 0; i < no_book; ++i) {
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
void addBook(Book library[], int &no_book, int MAX_BOOK){
    clearscreen();
    if (no_book >= MAX_BOOK) {
        cout << "Library is full!" << endl;
        pause(2);
        return;
    }

    int id, copies;
    string title, author;

    cout << "Enter book ID: ";
    cin >> id;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter book author: ";
    getline(cin, author);
    cout << "Enter number of copies: ";
    cin >> copies;

    library[no_book] = {id, title, author, copies};
    no_book++;
    cout << "Book added successfully!" << endl;
    pause(2);

}
void updateBookCopies(Book library[], int id, int new_copies){
    clearscreen();
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
void removeBook(Book library[], int &no_book, int id ){
    clearscreen();


}
void searchBook(Book library[] , int no_book, int id){
    clearscreen();
    for (int i = 0; i < no_book; ++i) {
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




int main(){
    int choice;
    const int MAX_BOOK = 100;
    Book library[MAX_BOOK];
    int no_book;


    do {
        clearscreen();
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

        if (cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<"The input is wrong, Please enter a number!"<<endl;
            cin >> choice;
        }
        switch(choice){
            case 1:
                displayLibrary(library, no_book);
                break;
            case 2:
                addBook(library, no_book, MAX_BOOK);
                break;
            case 3:
                updateBookCopies();
                break;
            case 4:
                removeBook();
                break;
            case 5:
                searchBook();
                break;
            case 6:
                cout << "Thank you for using our Libray system"<<endl;
                break;
            default:
                cout << "invalid number, try 1 - 6" << endl;
                pause(2);
                break;


        }

    }while(choice != 6);
    return 0;
}
