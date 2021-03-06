#include <wiringPiSPI.h>
#include <iostream>
#include <unistd.h>

using namespace std;

static const int SPI_CHANNEL = 0;

int main(void)
{
    int fd;
    unsigned char buffer[100];

    cout << "Initializing" << endl ;

    fd = wiringPiSPISetup(SPI_CHANNEL, 500000);
    if(fd < 0)
    {
        cout << "SPI error";
        return -1;
    }

    while(true)
    {
		sleep(5);
		cout << endl << endl;
        for(int i = 0; i < 180; i++)
        {
            cout << "enviando..." << i << endl;
            buffer[0] = i;
//		buffer[1] = '\n';
            fd = wiringPiSPIDataRW(SPI_CHANNEL, buffer, 1);
            if(fd < 0)
            {
                cout << "SPI error";
                return -1;
            }
            cout << "buf = " << int (buffer[0]) << endl;
            usleep(5000);
        }
        sleep(5);
		cout << endl << endl;
        for(int i = 180; i >0; i--)
        {

            cout << "enviando..." << i << endl;
            buffer[0] = i;
//		buffer[1] = '\n';
            fd = wiringPiSPIDataRW(SPI_CHANNEL, buffer, 1);
            if(fd < 0)
            {
                cout << "SPI error";
                return -1;
            }
            cout << "buf = " << int (buffer[0]) << endl;
            usleep(5000);
        }
    }

    /*
    for(int i = 10; i<190; i++)
    {

    	cout << "enviando..." << i << endl;
    	buffer[0] = i;
    //		buffer[1] = '\n';
        fd = wiringPiSPIDataRW(SPI_CHANNEL, buffer, 1);
        if(fd < 0)
        {
            cout << "SPI error";
            return -1;
        }
    	cout << "buf = " << buffer[0] << endl;
        sleep(2);
    }
    */
    return 0;
}
