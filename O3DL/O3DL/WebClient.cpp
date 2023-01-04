#include "WebClient.h"
#include "Exception.h"
#include "Process.h"
#include "WebCallBack.h"
#pragma comment(lib,"Urlmon.lib")
#include <Urlmon.h>

Core::Net::WebClient::WebClient(const Uri& _uri)
{
	uri = _uri;
}

Core::Net::WebClient::WebClient(const WebClient& _copy)
{
	uri = _copy.uri;
}


void Core::Net::WebClient::DownloadFile(const PrimitiveType::FString& _pathFile)
{
	const std::wstring _uriWstr = uri.Path().ToWString();
	const LPCWSTR _uri = _uriWstr.c_str();
	const std::wstring _pathWstr = _pathFile.ToWString();
	const LPCWSTR _path = _pathWstr.c_str();
	WebCallBack* _callback = new WebCallBack();
	_callback->OnDownloadProgress.AddDynamic(&OnDownloadProgress, &Event::ActionInternal<void, float>::Invoke);
	const HRESULT _result = URLDownloadToFile(nullptr, _uri, _path, 0, _callback);
	if (_result !=S_OK)throw Exception("[webClient] => uri doesn't valid !");
	else
	{
		Diagnostics::Process::Start(_pathFile,"");
	}
}
