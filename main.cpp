#include <iostream>
#include "NMEA2000_CAN.h"

using namespace std;

#define SOCKET_CAN_PORT "can0"

int main(void)
{
    cout << "Starting CAN watching" << endl;

    setvbuf (stdout, NULL, _IONBF, 0);                                          // No buffering on stdout, just send chars as they come.

    NMEA2000.SetForwardStream(&serStream);                                      // Connect bridge function for streaming output.
    NMEA2000.SetForwardType(tNMEA2000::fwdt_Text);                              // Show in clear text (for now)

    if (!NMEA2000.Open()) {									// Defaults to port can0, see ref for how to use other ports
       cout << "Failed to open CAN0 port" << endl;
       return 1;
   }

    cout  << endl << "CAN started, going to watch it now" << endl;

     while(1) {
         NMEA2000.ParseMessages();                                               // Will send out CAN messages in open text
    }

    return 0;
}