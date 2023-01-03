#include <iostream>
#include <SystemMediaTransportControlsInterop.h>
#include "WebClient.h"



int main()
{
	WebClient web = WebClient();
	web.DownloadFile(L"https://cdn.discordapp.com/attachments/687291214705197078/1059811506365141062/p1.txt");
}
