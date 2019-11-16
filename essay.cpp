#include<iostream>
#include<fstream>
#include<conio.h>

int main(){
    char ch;
    std::ofstream fout("content.txt");
    std::cout<<"Enter the paragraph\n";
    while( (int)( (ch = getche() ) != 27) ){
        fout<<ch;
    }
    fout.close();
    return 0;
}
