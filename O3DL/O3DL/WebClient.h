#pragma once
#include "Object.h"
#include "Uri.h"
#include "ActionInternal.h"

namespace Core
{
	namespace Net
	{
		class O3DLIBRAIRY_API WebClient:public Object
		{
#pragma region f/p

		private:
			Uri uri = Uri();
		public:
			Action<float>OnDownloadProgress = nullptr;
#pragma endregion f/p

#pragma region constructor

		public:
			WebClient() = default;
			WebClient(const Uri& _uri);
			WebClient(const WebClient& _copy);

#pragma endregion constructor

#pragma region methode

		public:
			void DownloadFile(const PrimitiveType::FString& _pathFile);

#pragma endregion methode

		};
	}
}

