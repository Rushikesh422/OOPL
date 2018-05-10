#include<iostream>
using namespace std;
class ass
{
double x,y;
public:
void accept()
{
  cout<<"Enter two numbers";
  cin>>x>>y;
}
 
double divide()
 {
   try
   {
    	if(y==0)
    	throw(y);
  	cout<<"Division is:"<<x/y;
    } 
    	catch(double p)
    	{
    	cout<<"Divide by zero exception"<<p;
    	}
    }
 };
    
	int main()
    	{
     		ass e;
     		e.accept();
     		e.divide();
     
     return 0;
     }
     
