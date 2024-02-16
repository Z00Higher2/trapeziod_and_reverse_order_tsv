// Author: Zuhayer Tashin
// Course: CSCI-135
// Instructor: Tong Yi
// Assignment: Lab 4F
// Write a program trapezoid.cpp that prints an upside-down trapezoid of given width and height.

#include<iostream>
using namespace std;

int main(){

int width,height,i,j,s,space;
  
cout << "Input width: ";
cin >> width;

cout << "Input height: ";
cin >> height;

cout << endl;
  
  if(width % 2 == 0 && height > width/2) {

      cout << "Impossible shape!";
    
    }else if (width % 2 != 0 && height > (width/2+1)) {

      cout << "Impossible shape!";
    
    } else {
      space = 0;
        for (i = 1; i <= height; i++) {
          for (s = 0; s < space; s++)

            cout << " ";

            for(j = 1;j <= width; j++)
            
              cout << "*";

cout << endl;

width = width - 2;
  
space++;

}
}
}