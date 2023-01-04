#include "WebClient.h"
#include <exception>
#include <iostream>

WebClient::WebClient(LPCWSTR _adress, LPCWSTR _fileName)
{
	adress=_adress;
	fileName = _fileName;
}

WebClient::WebClient(WebClient& _copy)
{
	adress=_copy.adress;
	fileName = _copy.fileName;
}

void WebClient::DownloadFile(LPCWSTR _adress)
{
	if (_adress == L"")
		throw std::exception("url vide");
	ShellExecute(0, 0, _adress, 0, 0, 0);
}
