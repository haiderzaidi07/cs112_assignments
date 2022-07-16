#include <iostream>
using namespace std;


struct Book
{
    int ID = 0;
    string bookName = " ";
    string author = " ";
    string ISBN = " ";
    int price = 0;
    int pages = 0;

    void printBook()
    {
        cout << "Book ID: " << ID << endl;
        cout << "Book Name: " << bookName << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN << endl;
        cout << "Price: " << price << endl;
        cout << "Pages: " << pages << endl;
        cout << "---------" << endl;
    }
};

struct BookList
{
    Book books[5];

    void printAll(BookList eachBook)
    {
        for (int i = 0; i < 5; i++)
        {
            eachBook.books[i].printBook();
        }
    }

    void addBook(BookList &eachBook, int index)
    {
        cout << "Enter the Index of New Book location: ";
        cin >> index;
        cout << "Enter the Book ID: ";
        cin >> eachBook.books[index].ID;
        cout << "Enter the Book Name: ";
        cin >> eachBook.books[index].bookName;
        cout << "Enter the Author Name: ";
        cin >> eachBook.books[index].author;
        cout << "Enter the ISBN: ";
        cin >> eachBook.books[index].ISBN;
        cout << "Enter the Price: ";
        cin >> eachBook.books[index].price;
        cout << "Enter the Pages: ";
        cin >> eachBook.books[index].pages;
        cout << "\nBook added successfully!\n\nUse the 'Show All Books' option see to the changes" << endl;
    }

    void sortAsc(BookList &eachBook)
    {
        int min;
        Book temp;

        for (int i = 0; i < 4; i++)
        {
            min = i;
            for (int j = i + 1; j < 5; j++)
            {

                if (eachBook.books[j].ID < eachBook.books[min].ID)
                {
                    min = j;
                }

                temp = eachBook.books[i];
                eachBook.books[i] = eachBook.books[min];
                eachBook.books[min] = temp;
            }
        }
    }

    void sortDes(BookList &eachbook)
    {
        int min;
        Book temp;

        for (int i = 0; i < 4; i++)
        {
            min = i;
            for (int j = i + 1; j < 5; j++)
            {

                if (eachbook.books[j].ID > eachbook.books[min].ID)
                {
                    min = j;
                }
              
                temp = eachbook.books[i];
                eachbook.books[i] = eachbook.books[min];
                eachbook.books[min] = temp;
            }
        }
    }

    void deleteAll(BookList &eachbook)
    {
        for(int i = 0; i < 5; i++)
        {
            eachbook.books[i].ID = 0;
            eachbook.books[i].bookName = " ";
            eachbook.books[i].author = " ";
            eachbook.books[i].ISBN = " ";
            eachbook.books[i].price = 0;
            eachbook.books[i].pages = 0;
        }
    }

    void delBook(BookList &eachbook)
    {
        int del; 
        cout << "Enter Book(ID) to delete: ";
        cin >> del;

        for (int i = 0; i < 5; i++)
        {
            if(del == eachbook.books[i].ID)
            {
                eachbook.books[i].ID = 0;
                eachbook.books[i].bookName = " ";
                eachbook.books[i].author = " ";
                eachbook.books[i].ISBN = " ";
                eachbook.books[i].price = 0;
                eachbook.books[i].pages = 0;
            }
        }
    }

    void searchBook(BookList &eachbook)
    {
        int search; 
        cout << "Enter Book(ID) to display: "; 
        cin >> search;
        cout << endl;

        for (int i = 0; i < 5; i++)
        {
            if(search == eachbook.books[i].ID)
            {
                eachbook.books[i].printBook();
            }
        }
    }
};

struct Student
{
    int ID = 0;
    string studentName = " ";
    int rollNo = 0;

    void printAll()
    {
        cout << "Student ID: " << ID << endl;
        cout << "Student Name: " << studentName << endl;
        cout << "Roll Number: " << rollNo << endl;
        cout << "----------" << endl;
    }
};

struct StudentList
{
    Student std[5];

    void printAll(StudentList eachStudent)
    {

        for (int i = 0; i < 5; i++)
        {
            eachStudent.std[i].printAll();
        }
    }

    void addStudent(StudentList &eachStudent, int index)
    {
        cout << "Enter the Index of New Student location: ";
        cin >> index;
        cout << "Enter the Student ID: ";
        cin >> eachStudent.std[index].ID;
        cout << "Enter the Student Name: ";
        cin >> eachStudent.std[index].studentName;
        cout << "Enter the Roll Number: ";
        cin >> eachStudent.std[index].rollNo;
        cout << "\nStudent added successfully!\n\nUse the 'Show All Students' option see to the changes" << endl;
    }

    void delStudent(StudentList &eachStudent)
    {
        int del; 
        cout << "Enter Student(ID) to Delete: ";
        cin >> del;

        for (int i = 0; i < 5; i++)
        {
            if(del == eachStudent.std[i].ID)
            {
                eachStudent.std[i].ID = 0;
                eachStudent.std[i].studentName = " ";
                eachStudent.std[i].rollNo = 0;
                cout << "\nStudent deleted successfully!\n\nUse the 'Show All Students' option see to the changes" << endl;
            }
        }
    }
};


void retToMenu(char ret)
{
    cout << "\nEnter any key to return to the Main Menu: ";
    cin >> ret;
    cout << endl;
}

int main()
{
    bool loop = true;
    int index;
    char input;
    char key;

    StudentList allStudents;                                // 2 values already initialised 

    allStudents.std[0].ID = 2021638;                            
    allStudents.std[0].studentName = "student1";
    allStudents.std[0].rollNo = 1;

    allStudents.std[1].ID = 2021412;
    allStudents.std[1].studentName = "student2";
    allStudents.std[1].rollNo = 2;

    BookList allBooks;                                      // 3 values already initialised 

    allBooks.books[0].ID = 55;
    allBooks.books[0].bookName = "book1";
    allBooks.books[0].author = "author1";
    allBooks.books[0].ISBN = "23251-13589524-13";
    allBooks.books[0].price = 543;
    allBooks.books[0].pages = 433;

    allBooks.books[1].ID = 43;
    allBooks.books[1].bookName = "book2";
    allBooks.books[1].author = "author2";
    allBooks.books[1].ISBN = "76251-13802324-43";
    allBooks.books[1].price = 312;
    allBooks.books[1].pages = 241;

    allBooks.books[2].ID = 89;
    allBooks.books[2].bookName = "book3";
    allBooks.books[2].author = "author3";
    allBooks.books[2].ISBN = "36212-23456434-38";
    allBooks.books[2].price = 252;
    allBooks.books[2].pages = 236;

    while(loop)
    {    

        cout << "               Main Menu\n\n";
        cout << "Enter the key mentioned in brackets to choose your option\n\n";
        cout << "Add New Student                (1)\n"; 
        cout << "Delete Existing Student        (2)\n"; 
        cout << "Show all Students              (3)\n"; 
        cout << "Add New Book                   (4)\n"; 
        cout << "Delete Existing Books          (5)\n"; 
        cout << "Show particular Book           (6)\n"; 
        cout << "Show all Books                 (7)\n"; 
        cout << "Sort Books in Ascending order  (8)\n"; 
        cout << "Sort Books in Descending order (9)\n"; 
        cout << "Exit                           (0)\n\n";

        cout << "Input: ";
        cin >> input;
        cout << "\n\n";

        switch (input)
        {
        case '1':
            allStudents.printAll(allStudents);
            allStudents.addStudent(allStudents, index);
            retToMenu(key);
            break;

        case '2':
            allStudents.printAll(allStudents);    
            allStudents.delStudent(allStudents);
            retToMenu(key);
            break;
        
        case '3':
            allStudents.printAll(allStudents);
            retToMenu(key);
            break;

        case '4':
            allBooks.printAll(allBooks);
            allBooks.addBook(allBooks, index);
            retToMenu(key);
            break;

        case '5':
            allBooks.deleteAll(allBooks);
            allBooks.printAll(allBooks);
            retToMenu(key);
            break;

        case '6':
            allBooks.searchBook(allBooks);
            retToMenu(key);
            break;

        case '7':
            allBooks.printAll(allBooks);
            retToMenu(key);
            break;

        case '8':
            allBooks.sortAsc(allBooks);
            allBooks.printAll(allBooks);
            retToMenu(key);
            break;

        case '9':
            allBooks.sortDes(allBooks);
            allBooks.printAll(allBooks);
            retToMenu(key);
            break;

        case '0':
            loop = false;
            break;
        
        default:
            cout << "Invalid Input\n\n";
            break;
        }
    }

    
    return 0;
}