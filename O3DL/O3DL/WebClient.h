#pragma once
#include "Object.h"
#include "Uri.h"

namespace Core
{
	namespace Net
	{
		class O3DLIBRAIRY_API WebClient:public Object
		{
		private:
			Uri uri = Uri();

		public:
			WebClient() = default;
			WebClient(const Uri& _uri);
			WebClient(const WebClient& _copy);

		public:
			void DownloadFile(const PrimitiveType::FString& _pathFile);

		};
	}
}

