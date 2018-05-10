#include<iostream>
using namespace std;
class complex
{
private:
float real,img;
public:
complex()
{ 
img=0;
real=0;
}
friend complex operator+(complex,complex);
friend complex operator-(complex,complex);
complex operator*(complex c2);
complex operator/(complex c2);
void getdata();
void display();
};

void complex::getdata() 
//function to accept complex numbers
{
cout<<"\n Enter complex no:";
cout<<"\n Enter real part value of no:";
cin>>real;
cout<<"\n Enter Imaginary part value of no:";
cin>>img;
}

void complex::display()
//function to display complex numbers
{
cout<<"\n Complex no is:"<<real<<"+"<<img<<"i";
}

complex operator+(complex a, complex b)
//Overloading '+' using friend function
{ 
complex c3;
c3.real=a.real+b.real;
c3.img=a.img+b.img;
return(c3);
}

complex operator-(complex a, complex b)
//Overloading '-' using friend function
{ 
complex c3;
c3.real=a.real-b.real, 
c3.img=a.img-b.img;
return(c3);
}


complex complex::operator*(complex c2) 
//Overloading using member function 
{ 
complex c3;
c3.real=(real*c2.real)-(img*c2.img); 
c3.img=(real*c2.img)+(img*c2.real);
return(c3);
}

complex complex::operator/(complex c2)
//Overloading using member function
{ 
complex c3;
c3.real=((real*c2.real)+(img*c2.img))/((c2.real*c2.real)+(c2. img* c2.img));
c3.img=(-(real*c2.img)+(img*c2.real))/((c2.real*c2.real)+(c2.img*c2.img));
return(c3);
}

int main()
{ 
  int ch;
  complex c1,c2,c3; 
  do
{
cout<<"\n\n\t\t 1.Accept";
cout<<"\n\n\t\t 2.Display";
cout<<"\n\n\t\t 3.+ operation";
cout<<"\n\n\t\t 4.- operation";
cout<<"\n\n\t\t 5.* operation";
cout<<"\n\n\t\t 6./ operation";
cout<<"\n\n\t\t 7.Exit";
cout<<"\n\n Enter your choice:";
cin>>ch;
switch(ch)
{
case 1:	c1.getdata(); 
        c2.getdata(); 
        break;
case 2:	c1.display();
        c2.display();
        break;
case 3:	c3=c1+c2;
        c3.display();
        break;
case 4:	c3=c1-c2;
        c3.display();
        break;
case 5:	c3=c1*c2;
        c3.display();
        break; 
case 6:	c3=c1/c2;
        c3.display();
        break; 
case 7: break;

default:cout<<"\n Wrong choice entered"; 
   }

}while(ch<7); 

return (0);
}


