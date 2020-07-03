#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int reciever(int *window, int winSize)
{
    return rand() % ((winSize - 1) + 4 + 1) - 4;   // random between x and y rand() % (y-x + 1 ) -x
}

void sender(int *window, int winSize, int var)
{
    bool flag = true;
    int prev_ak;        
        
    while (true)
    {
        int ak = reciever(window, winSize);
        
        if (flag)
            for (int i = 0; i < winSize; i++)
                if (i != ak)
                    cout << "\npacket " << (i + var) << " is recieved";

        if (ak < 0 && flag)
        {
          cout<<"\n\nrecieved all packets successfully\n";
          return;
        }
        else if(ak != prev_ak && !flag)
        {
            cout<<"\n\nrecieved packet "<<(prev_ak + var )<<" successfully\n";
            return;
        }

        cout << "\n\npacket " << (ak + var) << " is not recieved ";
        cout << "\nsending packet " << (ak + var) << "  again";
        flag = false;
        prev_ak=ak;
    }
}

int main()
{    srand(time(NULL));
    int noPk,winSize,*winArray,var = 0;

    cout << "\nEnter no of packets to be sent : ";
    cin >> noPk;
    cout << "\nEnter window size : ";
    cin >> winSize;

    while (var < noPk)
    {
        if (noPk - var < winSize)
            winSize = noPk - var;
           
        winArray = new int[winSize];
        for (int i = 0; i < winSize; i++)
            {
                winArray[i] = var;
                ++var;
            }
        
        sender(winArray, winSize, var-winSize);
        free(winArray);
    }

    cout<<"\n\n";
    system("\npause");
    return 0;
}
