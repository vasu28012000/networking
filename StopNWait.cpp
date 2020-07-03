#include<iostream>
#include<conio.h>
#include<cstdlib>
#include <unistd.h>
using namespace std;
string ch[20];
bool sender(int ak)
{
	while(ak)
	{ 
		sleep(2);
		cout<<"\nNEGATIVE ACK\n";
        return false;
    }
	  		
	cout<<"\nPOSITIVE ACK\n";
	return true;
}

int reciever(int data)
{
	int cases = 0+rand()%3;
			
	switch(cases){
		case 0:
			cout<<"RECIEVER RECIEVED ";
			return 0;
		

		case 1:
			cout<<"TIMEOUT ";
			return 1;
		case 2:
			cout<<"RECIEVER RECIEVED ";
		          return 2;
		}	
}

int main(void)
{
	start:
		
	int data=1;  
	cout<<"\nenter the number of data frames : ";
	int data_frames;
	cin>>data_frames;
	cout<<"ENTER STRING ONE BY ONE: \n";
	for(int j=0;j<data_frames;++j)
	{
		cin>>ch[j];
	}
	           int i=0;     
	while(data_frames>0)
	{
	  
	cout<<"\n\n\n\nframe "<<ch[i]<<"  :\n";
	data=(!data);
	label:
          cout<<"\nsending "<<" to receiver,";
	int ak = reciever(data);
 	if (!sender(ak)) goto label;

cout<<"\n\nframe "<<ch[i]<<" sent successfully ";
         --data_frames;
         ++i;
	}
cout<<"RECIEVED STRING: \n";
for(int o=0;o<data_frames;++o)
	cout<<ch[o];

cout<<"\n\nIf you want to exit press 0 : ";
cin>>data_frames;
if(data_frames) goto start;

	getch();
	return 0;
}
