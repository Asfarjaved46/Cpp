// This exercise and the next few require you to design and implement a Book class, such as you
// can imagine as part of software for a library. Class Book should have members for the ISBN,
// title, author, and copyright date. Also store data on whether or not the book is checked out.
// Create functions for returning those data values. Create functions for checking a book in and
//
//Class Book should have members for the ISBN,
// title, author, and copyright date. Also store data on whether or not the book is checked out.
// Create functions for returning those data values. 
// out. Do simple validation of data entered into a Book; for example, accept ISBNs only of the
// form n!n!n!x where n is an integer and x is a digit or a letter. Store an ISBN as a string.

#include <iostream>
using namespace std;
#include<vector>


enum Genre
{
    fiction,
    nonfiction,
    periodical,
    biography,
    children
};

class Book{
    private:
        string ISBN;
        string title;
        string author;
        int copyright_date;
        bool checked_out;
        Genre genre;

      bool validISBN(string s){
        int dashCount = 0;
        string part = "";
        int partNumber = 1;

        for (int i = 0; i <= s.length(); i++){
    
        if (i == s.length() || s[i] == '-'){
        
            if (partNumber <= 3){
            
                if (part.length() == 0)
                    return false;
                for (int j = 0; j < part.length(); j++){
                
                    if (!(part[j] >= '0' && part[j] <= '9'))
                        return false;
                }
            }
            else if (partNumber == 4)
            {
                if (part.length() != 1)
                    return false;

                char x = part[0];

                if (!((x >= '0' && x <= '9') ||
                      (x >= 'A' && x <= 'Z') ||
                      (x >= 'a' && x <= 'z')))
                    return false;
            }

            part = "";
            partNumber++;

            if (i < s.length())
                dashCount++;
        }
        else
        {
            part += s[i];
        }
    }

    if (dashCount != 3)
        return false;

    if (partNumber != 5)
        return false;

    return true;
}
    public:
        Book(string i, string t, string a, int c,Genre g) {
            if (validISBN(i))
                ISBN = i;
            else
                ISBN = "Invalid";

            title = t;
            author = a;
            copyright_date = c;
            checked_out = false;
            genre = g;
        }

        string getISBN(){
            return ISBN;
        }
        string getAuthor(){
            return author;
        }
        string getTtitle(){
            return title;
        }
        Genre getGenre(){
            return genre;
        }
        void checkOut(){
            checked_out = false;
        }
        void checkedIN(){
            checked_out = true;
        }
        bool isCheckedOut(){
            return checked_out;
        }

        bool operator==(const Book& other) const {
            return ISBN == other.ISBN;
        }

        bool operator!=(const Book& other) const {
            return !(*this == other);
        }

        friend ostream& operator<<(ostream& os, const Book& b) {
            os<< "Title: " << b.title << endl;
            os<< "Author: " << b.author << endl;
            os<< "ISBN: " << b.ISBN << endl;
            return os;
        }
};

class Patron{
    private:
        string name;
        int cardNumber;
        double fee;

    public:
        Patron(string n, int c, double f){
    
        name = n;
        cardNumber = c;
        fee = f;
    }

    string getName(){
        return name;
    }

    int getCardNumber(){
        return cardNumber;
    }

    double getFee(){
        return fee;
    }

    void setFee(double f){
        fee = f;
    }

    bool owesFee()
    {
        if (fee > 0)
            return true;
        else
            return false;
    }
};
class library{
    private:
        struct Transaction{
            Book book;
            Patron patron;
            string date;
            public:
                Transaction(Book b, Patron p, string d): book(b), patron(p), date(d){}
        };
        vector<Book> books;
        vector<Patron> patrons;
        vector<Transaction> transactions;
    public:
        void addbook(Book b){
            books.push_back(b);
        }
        void addpatron(Patron p){
            patrons.push_back(p);
        }
        void checkout(Book b,Patron p,string d){
            bool BookFound = false;
            bool PatronFound = false;

            for(int i =0; i< books.size(); i++){
                if(books[i] == b){
                    BookFound = true;
                }
            }
            for(int i = 0; i < patrons.size();i++){
                if(patrons[i].getCardNumber() == p.getCardNumber()){
                    PatronFound = true;
                }
            }
        

            if (!BookFound){
            cout << "Book not found in library." << endl;
            return;
        }

            if(!PatronFound){
        
            cout << "Patron not found in library." << endl;
            return;
        }

        if (p.owesFee())
        {
            cout << "Patron owes library fees." << endl;
            return;
        }

        Transaction t(b, p, d);
        transactions.push_back(t);

        cout << "Book checked out successfully." << endl;
    }
      vector<string> patronsWithFees()
    {
        vector<string> names;

        for (int i = 0; i < patrons.size(); i++)
        {
            if (patrons[i].owesFee())
            {
                names.push_back(patrons[i].getName());
            }
        }

        return names;
    }
};

int main()
{
    library lib;

    Book b1("123-456-789-A", "C++ Programming", "Bjarne", 2020, nonfiction);
    Book b2("111-222-333-B", "Harry Potter", "J.K. Rowling", 1997, fiction);

    Patron p1("Ali", 101, 0);
    Patron p2("Ahmed", 102, 150);

    lib.addbook(b1);
    lib.addbook(b2);

    lib.addpatron(p1);
    lib.addpatron(p2);

    lib.checkout(b1, p1, "20-05-2026");

    lib.checkout(b2, p2, "21-05-2026");

    vector<string> names = lib.patronsWithFees();

    cout << "\nPatrons who owe fees:\n";

    for (int i = 0; i < names.size(); i++)
    {
        cout << names[i] << endl;
    }

    return 0;
}