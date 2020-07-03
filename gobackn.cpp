#include<iostream>
#include<ctime>
#include<cstdlib>
#include<stdio.h>
using namespace std;
int main()
{
 int nf,N;
 int no_tr=0;
 srand(time(NULL));
 cout<<"Enter the number of frames : ";
 cin>>nf;
 char ch[nf];
 cout<<"Enter the values for the frames: \n";
 cin>>ch;
 cout<<"Enter the Window Size : ";
 cin>>N;
 int i=1;
 while(i<=nf)
 {
     int x=0;
     for(int j=i;j<i+N && j<=nf;j++)
     {
         cout<<"Sent Frame"<<j<<" ("<<ch[j-1]<<")"<<endl;
         no_tr++;
     }
     for(int j=i;j<i+N && j<=nf;j++)
     {
         int flag = rand()%2;
         if(!flag)
             {
                 cout<<"Acknowledgment for Frame "<<j<<"( "<<ch[j-1]<<")"<<endl;
                 x++;
             }
         else
             {   cout<<"Frame "<<j<<" ("<<ch[j-1]<<") "<<" Not Received"<<endl;
                 cout<<"Resending Window"<<endl;
                 break;
             }
     }
     cout<<endl;
     i+=x;
 }
 cout<<"Total number of transmissions : "<<no_tr<<endl;
 cout<<"String recieved :"<<ch;
 return 0;
}

