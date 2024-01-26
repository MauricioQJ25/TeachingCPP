// c++ program to demonstrate the working of shared_ptr
// here both smart pointer P! and P2 are pointing to the 
// object Addition to which they both maintain a reference 
// of the object 
#include <iostream>

using namespace std;

// Dinamic Memory management library

#include <memory>

class Rectangle {
    int length;
    int breadth;

    public:
        Rectangle(int l, int b){
            length = l;
            breadth = b;
        }
        int area(){ 
        return length * breadth;
        }
    ~Rectangle(){
        std::cout << "Good Bye rectangle" << std::endl;
    }
};

int main(){
    //---\/ Smart Pointer
    shared_ptr<Rectangle> P1(new Rectangle(10, 5));
    //shared_ptr<Rectangle>
    // This'll print 50
    cout << P1->area() << endl;

    shared_ptr<Rectangle> P2;
    P2 = P1;

    // This'll now not give an error, 
    cout << P2->area() << endl;
    // This'll print 50
    cout << P1->area() << endl;

    // This'll also print 50 now
    // This'll print 2 as Reference Counter is 2

    weak_ptr<Rectangle> P3;
    P3 = P2;
    P2.reset();
    P1.reset();
    if (auto tempSharedPtr =  P3.lock())
    {
        cout << tempSharedPtr->area() << endl;
    }
    else
    {
        cout << "P3 out of scope" << endl;
    }    

    cout << P1.use_count() << endl;
    return 0;

}