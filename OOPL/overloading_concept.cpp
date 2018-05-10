#include<iostream>
using namespace std;
class shape
	{
	    protected:
	    float data1,data2;
	    public:
	    virtual void getdata()=0;
	    virtual float compute_area()=0;
	    
	};
class traingle: public shape
	{
	   public:
	   void getdata()
	   {
	      cout<<"Enter base & height ";
	      cin>>data1>>data2;
	   }
	   float compute_area()
	    {
	       return 0.5*data1*data2;
	    }
	};
class rectangle: public shape
	{
	   public:
	   void getdata()
	   {
	      cout<<"Enter length & width  ";
	     cin>>data1>>data2;
	   }
	   float compute_area()
	    {
	       return data1*data2;
	    }
	};

int main()
{
	shape *S;
	traingle T;
	rectangle R;
	int ch;
	do
	{
	  cout<<"\ncalculate 1: Traigle   2:Rectangle    3:Exit\nEnter your choice: ";
	  cin>>ch;
	  switch(ch)
	         {
		case 1: S=&T;
		        S->getdata();
		        cout<<"\nArear of Traingle: "<<S->compute_area();	         
		        break;
                                       
		case 2: S=&R;
                        S->getdata();
		        cout<<"\nArear of Rectangle: "<<S->compute_area();	         
	                break;
		default: cout<<"\nWrong Choice ";              
	         }
	 }
	while(ch<3);
	return 1;
}		
