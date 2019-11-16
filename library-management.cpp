#include<fstream>
#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<cstring>

int isBookNoExists(int bookno);

class Library{
private:
    int BookNo;
    char issuedTo[40], authorName[60], bookName[100];
public:
    int read(){
        std::cout<<"\nBook Number: ";
        std::cin>>BookNo;
        if (isBookNoExists(BookNo) == 1){
            fflush(stdin);
            std::cout<<"\nBook Name: ";
            std::cin.getline(bookName, 99);
            fflush(stdin);
            std::cout<<"\nAuthor Name: ";
            std::cin.getline(authorName, 59);
            fflush(stdin);
            strcpy(issuedTo, "N/A");
            return 1;
        }else{
            std::cout<<"\nBook Number already exists!\n";
            return -1;
        }
    }
    void writeData(){
        std::cout<<"\nBook Number: "<<BookNo;
        std::cout<<"\nBook Name: "<<bookName;
        std::cout<<"\nAuthor Name: "<<authorName;
        std::cout<<"\nIssued To: "<<issuedTo;
    }
    char issuingTo(){
        std::cout<<"Book Number: "<<BookNo;
        std::cout<<"\nBook Name: "<<bookName;
        std::cout<<"\nAuthor Name: "<<authorName;
        std::cout<<"\n\nIssue To: ";
        fflush(stdin);
        std::cin.getline(issuedTo, 39);
    }
    int getBookNo(){
        return BookNo;
    }
};
int isBookNoExists(int bookno){
    std::ifstream fin("libraryData.dat");
    Library l;
    while(fin.read((char *)&l, sizeof(Library))){
        if(l.getBookNo() == bookno){
            fin.close();
            return -1;
        }
    }
    fin.close();
    return 1;
}
void IssueNewBook(){
    int tempBookNo;
    int flag = 0;
    std::ifstream fin("libraryData.dat");
    std::ofstream fout("temp.dat");
    Library l;
    std::cout<<"\nEnter the Book Number: ";
    std::cin>>tempBookNo;
    while(fin.read((char *)&l, sizeof(Library))){
        if(l.getBookNo() == tempBookNo){
            l.issuingTo();
            std::cout<<"\nBook Number "<<tempBookNo<<" has been issued";
            flag = 1;
        }
        fout.write((char*)&l, sizeof(Library));
    }
    fout.close();
    fin.close();
    remove("libraryData.dat");
    rename("temp.dat", "libraryData.dat");
    if(flag == 0){
        std::cout<<"\nThis Book is not available";
    }
}
//Add New Book
void AddNewBook(){
    std::ofstream fout("libraryData.dat", std::ios::binary | std::ios::app);
    Library l;
    if(l.read() == 1){
        fout.write((char*)&l, sizeof(Library));
        std::cout<<"\nBook Added\n";
        fout.close();
    }
}
//Show all the books that are in the library
void ReadDataFromFile(){
    std::ifstream fin("libraryData.dat");
    Library l;
    int counter = 0;
    std::cout<<"\nAll The Books present in the Library are\n";
    while(fin.read((char*)&l, sizeof(Library))){
        std::cout<<"\n";
        l.writeData();
        std::cout<<"\n";
        counter++;
    }
    fin.close();
    if(counter == 0){
        std::cout<<"\nNo records yet!";
    }
}
//search for a book
void searchBooks(){
    Library l;
    std::ifstream fin("libraryData.dat");
    int tempBookNo, flag = 0;
    std::cout<<"\nenter the book number: ";
    fflush(stdin);
    std::cin>>tempBookNo;
    while(fin.read((char*)&l, sizeof(Library))){
        if(l.getBookNo() == tempBookNo){
            l.writeData();
            flag = 1;
            break;
        }
    }
    if(flag != 1){
        std::cout<<"Record Not Found!";
    }
}
//Edit a book
void editBookDetails(){
    Library l;
    std::ifstream fin("libraryData.dat");
    std::ofstream fout("temp.dat");
    int tempBookNo, flag;
    std::cout<<"\nenter the book number: ";
    fflush(stdin);
    std::cin>>tempBookNo;
    while(fin.read((char*)&l, sizeof(Library))){
        if(l.getBookNo() == tempBookNo){
            l.writeData();
            std::cout<<"\n";
            l.read();
            flag = 1;
            std::cout<<"\nBook Number "<<tempBookNo<<" information has been updated";
            break;
        }
        fout.write((char*)&l, sizeof(Library));
    }
    if(flag != 1){
        std::cout<<"Book not found!";
    }
    remove("libraryData.dat");
    rename("temp.dat", "libraryData.dat");
}
int main(){
    int choice;
    do{
        std::cout<<"\n1 for adding new book\n2 for Issuing a book\n3 for all the books present in library\n4 to search a book\n5 to edit details for a book\n6 to exit\nenter: ";
        std::cin>>choice;
        switch(choice){
        case 1:
            AddNewBook();
            break;
        case 2:
            IssueNewBook();
            break;
        case 3:
            ReadDataFromFile();
            break;
        case 4:
            searchBooks();
            break;
        case 5:
            editBookDetails();
            break;
        case 6:
            std::cout<<"exited";
            break;
        default:
            std::cout<<"\nYou entered wrong key";
        }
    }while(choice != 6);
    return 0;
}
