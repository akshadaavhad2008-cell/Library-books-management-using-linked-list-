#include <iostream>
using namespace std;

struct Book
{
    int id;
    string name;
    string author;
    bool issued;
    Book* next;
};

Book* head = NULL;

// Add a book
void addBook()
{
    Book* newBook = new Book;

    cout << "Enter Book ID: ";
    cin >> newBook->id;

    cout << "Enter Book Name: ";
    cin >> newBook->name;

    cout << "Enter Author Name: ";
    cin >> newBook->author;

    newBook->issued = false;
    newBook->next = NULL;

    if (head == NULL)
    {
        head = newBook;
    }
    else
    {
        Book* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newBook;
    }

    cout << "Book added successfully!\n";
}

// Display books
void displayBooks()
{
    if (head == NULL)
    {
        cout << "No books available.\n";
        return;
    }

    Book* temp = head;

    cout << "\n--- Library Books ---\n";

    while (temp != NULL)
    {
        cout << "Book ID: " << temp->id << endl;
        cout << "Book Name: " << temp->name << endl;
        cout << "Author: " << temp->author << endl;

        if (temp->issued)
            cout << "Status: Issued\n";
        else
            cout << "Status: Available\n";

        cout << "-------------------\n";

        temp = temp->next;
    }
}

// Search book
void searchBook()
{
    int id;
    cout << "Enter Book ID to search: ";
    cin >> id;

    Book* temp = head;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << "Book Found!\n";
            cout << "Book Name: " << temp->name << endl;
            cout << "Author: " << temp->author << endl;

            if (temp->issued)
                cout << "Status: Issued\n";
            else
                cout << "Status: Available\n";

            return;
        }

        temp = temp->next;
    }

    cout << "Book not found.\n";
}

// Issue book
void issueBook()
{
    int id;
    cout << "Enter Book ID to issue: ";
    cin >> id;

    Book* temp = head;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            if (temp->issued)
                cout << "Book is already issued.\n";
            else
            {
                temp->issued = true;
                cout << "Book issued successfully!\n";
            }
            return;
        }

        temp = temp->next;
    }

    cout << "Book not found.\n";
}

// Return book
void returnBook()
{
    int id;
    cout << "Enter Book ID to return: ";
    cin >> id;

    Book* temp = head;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            if (!temp->issued)
                cout << "Book is already available.\n";
            else
            {
                temp->issued = false;
                cout << "Book returned successfully!\n";
            }
            return;
        }

        temp = temp->next;
    }

    cout << "Book not found.\n";
}

// Delete book
void deleteBook()
{
    int id;
    cout << "Enter Book ID to delete: ";
    cin >> id;

    Book* temp = head;
    Book* previous = NULL;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            if (previous == NULL)
                head = temp->next;
            else
                previous->next = temp->next;

            delete temp;

            cout << "Book deleted successfully!\n";
            return;
        }

        previous = temp;
        temp = temp->next;
    }

    cout << "Book not found.\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Delete Book\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addBook();
            break;

        case 2:
            displayBooks();
            break;

        case 3:
            searchBook();
            break;

        case 4:
            issueBook();
            break;

        case 5:
            returnBook();
            break;

        case 6:
            deleteBook();
            break;

        case 7:
            cout << "Thank you!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}
