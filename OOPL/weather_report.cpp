#include<iostream>
using namespace std;

class weather
{
	int d_o_m;
	float htemp,ltemp,amt_of_rain,amt_of_snow;
public:
	weather();
	void inputdata(int);
	void display();
	void average(weather *w);
};

weather::weather()
{
	htemp=999;
	ltemp=-999;
	amt_of_rain=0;
	amt_of_snow=0;
	d_o_m=99;
}
void weather::inputdata(int d)
{
	d_o_m=d;
	cout<<"Enter high Temp:";
	cin>>htemp;
	cout<<"\nEnter low Temp:";
	cin>>ltemp;
	cout<<"\nEnter Amt of Rain:";
	cin>>amt_of_rain;
	cout<<"\nEnter Amt of Snow:";
	cin>>amt_of_snow;
}
void weather::display()
{
	cout<<"\t"<<d_o_m;
	cout<<"\t\t"<<htemp;
	cout<<"\t"<<ltemp;
	cout<<"\t"<<amt_of_rain;
	cout<<"\t"<<amt_of_snow;
}
void weather::average(weather w[31])
{
	int train,tsnow,tltemp,thtemp;
	float avghtemp,avgltemp,avgrain,avgsnow;
	train=tsnow=tltemp=thtemp=0;
	int i,count=0;
	for(i=1;i<=31;i++)
     {
	if(w[i].d_o_m==99)
	continue;
	else
	{
		thtemp+=w[i].htemp;
		tltemp+=w[i].ltemp;
		train+=w[i].amt_of_rain;
		tsnow+=w[i].amt_of_snow;
		count++;
	}
     }
avghtemp=thtemp/count;
avgltemp=tltemp/count;
avgrain=train/count;
avgsnow=tsnow/count;
cout<<"\nAverage High Temp:"<<avghtemp;
cout<<"\nAverage Low Temp:"<<avgltemp;
cout<<"\nAverage Amount of Rain:"<<avgrain;
cout<<"\nAverage Amount of Snow:"<<avgsnow;
}

int main()
{
	weather data[12][31],temp[31],obj;
	int ch,i,day,month;
	char ans;
cout<<"\nWEATHER REPORT";
do
{
cout<<"\n Main Menu";
cout<<"\n1.Enter Data.";
cout<<"\n2.Display Report.";
cout<<"\n3.Exit.";
cout<<"\nEnter your choice:";
cin>>ch;
switch(ch)
{
	case 1:
		cout<<"\nEnter the month:";
		cin>>month;
		cout<<"\nEnter the day:";
		cin>>day;
		data[month][day].inputdata(day);
	break;
	case 2:
		cout<<"\nEnter the month:";
		cin>>month;
		cout<<"\n\n\tDay\tDay_o_M\tAmt_Rain\tAmt_Snow\tHigh_temp\tLow_temp";
		for(int i=1;i<=31;i++)
	{
		cout<<"\n"<<i;
		data[month][i].display();
	}
	for(int i=1;i<=31;i++)
    {
	temp[i]=data[month][i];
    }
	obj.average(temp); 
	break;
}
cout<<"\nDo u want to continue?";
cin>>ans;
}while(ans=='y');
return 0;
}



