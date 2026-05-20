#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <winsock2.h>
#include <iostream>

#pragma comment(lib, "ws2_32")

using namespace std;

char Buffer[1024] = { 0, };


int main()
{
	WSAData wsaData;

	WSAStartup(MAKEWORD(2, 2), &wsaData);

	SOCKET ServerSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN ServerSockAddr;
	memset(&ServerSockAddr, 0, sizeof(ServerSockAddr));
	ServerSockAddr.sin_family = AF_INET;
	ServerSockAddr.sin_addr.s_addr = inet_addr("192.168.0.100");
	ServerSockAddr.sin_port = htons(35000);

	connect(ServerSocket, (SOCKADDR*)&ServerSockAddr, sizeof(ServerSockAddr));

	while (true)
	{
		cin.getline(Buffer, sizeof(Buffer));

		int SentBytes = send(ServerSocket, Buffer, sizeof(Buffer), 0);
		if (SentBytes <= 0)
		{
			cout << "send fail." << endl;
			break;
		}

		int RecvBytes = recv(ServerSocket, Buffer, sizeof(Buffer), 0);
		if (RecvBytes <= 0)
		{
			cout << "recv fail " << endl;
			break;
		}

		cout << "server" << Buffer << " send" << endl;
	}

	closesocket(ServerSocket);

	WSACleanup();

	return 0;
}