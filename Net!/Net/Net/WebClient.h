#pragma once
#include <string>
#include <SystemMediaTransportControlsInterop.h>

class WebClient
{
private :
	LPCWSTR adress = L"";
	LPCWSTR fileName = L"C:/Users/PRAIT2401/Desktop/project2/project2/test";

public:
	WebClient() = default;
	WebClient(LPCWSTR _adress, LPCWSTR _filename);
	WebClient(WebClient& _copy);

public:
	void DownloadFile(LPCWSTR _address);
};

