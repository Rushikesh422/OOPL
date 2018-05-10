#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class base1
{
	char dob[10];
	char bg[3];
	public:
		char name[30];
		void get1();
		void disp1();

};

class base2
{
	float ht;
	float wt;
	public:
		void get2();
		void disp2();
};

class base3
{
	char policy[10];
	char address[50];
	public:
		void get3();
		void disp3();
};

class derived : public base1, public base2 ,public base3
{
	char telephone[10];
	char liscence[10];
	public:
		int present;
		derived();
		void get();
		void disp();
};

derived :: derived()
{
	present=0;
}

void base1 :: get1()
{
    cout<<"\nEnter Name: ";
    cin>>name;
    cout<<"\nEnter DOB: ";
    cin>>dob;
    cout<<"\nEnter Blood group: ";
    cin>>bg;
}

void base1 :: disp1()
{
	cout<<"\n"<<name<<"\t"<<dob<<"\t"<<bg;
}

void base2 :: get2()
{
      cout<<"\nEnter height: ";
      cin>>ht;
      cout<<"\nEnter weight: ";
      cin>>wt;
}

void base2 :: disp2()
{
      cout<<"\t"<<ht<<"\t"<<wt;
}

void base3 :: get3()
{
	cout<<"\nEnter policy number: ";
	cin>>policy;
	cout<<"\nEnter address: ";
	cin>>address ;
}

void base3 :: disp3()
{
   cout<<"\t"<<policy<<"\t"<<address;
}

void derived :: get()
{
   base1 :: get1();
   base2 :: get2();
   base3 :: get3();
   present=1;
   cout<<"\nEnter telephone number: ";
   cin>>telephone;
   cout<<"\nEnter liscence number: ";
   cin>>liscence;
}

void derived :: disp()
{
   base1::disp1();
   base2::disp2();
   base3::disp3();
   cout<<"\t"<<telephone<<"\t"<<liscence<<"\t";
}

int main()
{
	derived obj[50],temp;
	int ch,i,j=-1,no,flag=0;
	char key[10],ans;
	
	do
	{
		cout<<"\n\tMenu"
		    <<"\n1.Build Master Table"
		    <<"\n2.Display"
		    <<"\n3.Insert a new entry"
		    <<"\n4.Delete entry"
		    <<"\n5.Edit"
		    <<"\n6.Search for record"
		    <<"\n7.Exit"
		    <<"\nEnter your choice: ";
		cin>>ch;

		switch(ch)
		{
			case 1:
				do
				{
					j++;
					obj[j].get();
					cout<<"\nAdd another.....(y/n)?: ";
					cin>>ans;
				}while(ans=='Y' || ans=='y');
				break;

			case  2:		cout<<"\nName\tDOB\tB.G.\tHeight\tWeight\tPolicy\tAddres\tTeleNo\tLiscNo ";
				cout<<"\n-----------------------------------------------------------------------";
				for(i=0;i<=j;i++)
					obj[i].disp();
				break;

			case 3:
				cout<<"\n Enter the index no.: ";
				cin>>no;
				//if(no<=j)
				//{
					for(i=no;i<=j;i++)
					{
						temp=obj[i];
						obj[i+1]=temp;
					}
					obj[no].get();
					j++;
					cout<<"\nRecord Inserted Successfully.....";
				//}
				//else
				//	cout<<"\nERROR.....";
				break;

			case 4:
				if(j!=-1)
				{
					cout<<"\nEnter the record no. to delete: ";
					cin>>no;
					if(no<=j)
					{
						for(i=no;i<=j;i++)
						{
							temp=obj[i];
							obj[i]=obj[i+1];
						}
						j--;
						cout<<"\nRecord Deleted SuccessFully.....";
					}
					else
						cout<<"\nERROR.....";
				}
				else
						cout<<"\nNo Record to delete.....";
				break;

			case 5:
				if(j!=-1)
				{
					cout<<"\nEnter index no.";
					cin>>no;
					cout<<"\nEnter modified data: ";
					obj[no].get();
					cout<<"\nRecord modified Successfully.....";
				}
				else
						cout<<"\nNo Record to modify.....";
				break;

			case 6:
				if(j!=-1)
				{
					cout<<"Enter the name to be searched:" ;
					cin>>key;
					for(i=0;i<=j;i++)
					{
						if(strcmp(obj[i].name,key)==0)
						{
							cout<<"\nRecord Found.....";
							obj[i].disp();
							flag=1;
						}
					}
					if(flag==0)
						cout<<"\nRecord not found.....";
				}
				else
					cout<<"\nNo Record to search.....";
				break;

			case 7:
				exit(0);
			default:
				cout<<"\nInvalid Choice.....";
		}
	}while(ch!=7);
	return 0;
}



