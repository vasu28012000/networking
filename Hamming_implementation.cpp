#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int *data, *bits;
	int n,data_bits=0,check_bits=0,count=0,c=0,x=0;
	
	cout<<"Enter length of data stream : ";
	cin>>n;
	data=new int[n];
	
	for(int i=0;i<n;i++)
		if((i+1)==pow(2,c))
		{
			check_bits++;
			c++;
		}

	data_bits=n-check_bits;
	
	cout<<"\nTotal data bits : "<<data_bits<<"\nTotal check bits : "<<check_bits;
	
	bits=new int[data_bits];
	
	cout<<"\n\nEnter data bits one by one : ";
	
	for(int i=0;i<data_bits;i++)
		cin>>bits[i];
	
	c=0;
	for(int i=0;i<n;i++)
	{
		if((i+1)!=pow(2,c))
			data[i]=bits[x++];
			
		else
			c++;
	}
	
	c=0;
	cout<<"1.FOR EVEN PARITY\n2.FOR ODD PARITY:\nENTER CHOICE: ";
	int choice;
	cin>>choice;
	switch(choice)
	{
		case 1:	for(int i=1;i<=n;i=pow(2,++c))
				{
					count=0;
					cout<<"\nFor "<<i<<" : ";
		
					for(int j=i+1;j<=n;j++)
						if((i&j)&&data[i-1]==1)
						count++;
					
				
					cout<<count<<endl<<"FOR EVEN PARITY, PARITY BIT = ";
		
					if(count%2==1)
					x=1;
			
					else
					x=0;
			
					cout<<x<<endl;
					data[i-1]=x;
									
				}
											break;
		case 2:for(int k=1;k<=n;k=pow(2,++c))
				{
					count=0;
					cout<<"\nFor "<<k<<" : ";
		
					for(int l=k+1;l<=n;l++)
					{
						if(((k)&l)&&data[l-1]==1)
						count++;
						
					}
					cout<<count<<endl<<"FOR ODD PARITY, PARITY BIT = ";
		
					if(count%2==1)
					x=0;
			
					else
					x=1;
			
					cout<<x<<endl;
					data[k-1]=x;
				}
										break;
	}
	
	cout<<"\n\nData stream : ";
	
	for(int i=0;i<n;i++)
		cout<<data[i]<<"  ";
		cout<<"Enter the recieved codeword (bit by bit): ";
	int arr1[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr1[i];
	}
	f=0;
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		int c1,c2;
		int u=(pow(2,f));
		if(i==u)
		{
			c1=arr1[i-1];
			int ctr=0;
			for(int j=i+1;j<=n;j++)
			{	
				if((i&j)!=0)
				{
					ctr+=arr1[j-1];
				}
			}
			if(ctr%2==0)
			{
				if(choice==1)
					c2=0;
				else
					c2=1;
			}
			else
			{
				if(choice==1)
					c2=1;
				else
					c2=0;
			}
			f++;
			if(c1!=c2)
			{
				ans+=i;	
			}	
		}		
	}
	
	cout<<"\nCodeword recieved is: ";
	for(int i=0;i<n;i++)
	{
		cout<<arr1[i];	
	}
	
	if(ans==0)
		cout<<"\nCodeword is correct!!!";
	else
	{
		cout<<"\nError at bit: "<<ans;
		if(arr1[ans-1]==0)
			arr1[ans-1]=1;
		else
			arr1[ans-1]=0;
		cout<<endl<<"Corrected Codeword is: ";
		for(int i=0;i<n;i++)
		{
			cout<<arr1[i];	
		}
	}
	
	return 0;
}
