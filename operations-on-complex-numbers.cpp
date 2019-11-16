#include<iostream>
#include<cstdio>
class Complex{
private:
    int a, b;
public:
    void read(int turn){
        std::cout<<"\nenter the real part value of equation "<<turn<<": ";
        fflush(stdin);
        std::cin>>a;
        std::cout<<"\nenter imaginary part value of equation "<<turn<<": ";
        fflush(stdin);
        std::cin>>b;
    }
    void display(){
        std::cout<<"\nFinal equation: "<<a<<" + "<<b<<"i";
    }
    Complex operator + (Complex C){
        Complex temp;
        temp.a = a + C.a;
        temp.b = b + C.b;
        return temp;
    }
    Complex operator - (Complex C){
        Complex temp;
        temp.a = a - C.a;
        temp.b = b - C.b;
        return temp;
    }
};

int main(){
    Complex C1, C2, C3;
    int choice;
    do{
        std::cout<<"\n1 for addition\n2 for substraction\n3 to exit\nEnter your choice: ";
        std::cin>>choice;
        if(choice > 0 && choice < 3){
            std::cout<<"\n\n A complex number looks like 'a + bi' , \n where,\ta = Real Part of the number\n\tb = Imaginary Part and,\n\ti = iota\n\n";
        }
        switch(choice){
        case 1:{
            C1.read(1);
            std::cout<<"\n";
            C2.read(2);
            C3 = C1 + C2;
            C3.display();
            break;
        }
        case 2:{
            C1.read(1);
            std::cout<<"\n";
            C2.read(2);
            C3 = C1 + C2;
            C3.display();
            break;
        }
        case 3:
            std::cout<<"Exited";
            break;
        default:
            std::cout<<"Wrong Key pressed!";
        }
    }while(choice != 3);
    return 0;
}
