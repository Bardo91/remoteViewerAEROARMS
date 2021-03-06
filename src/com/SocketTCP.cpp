/////////////////////////////////////////////////////////////////////////////////////////
//	BOVIL: core
//
//			Author:		Pablo Ramon Soria
//			Date:		2014-05-31
//
/////////////////////////////////////////////////////////////////////////////////////////

#include "SocketTCP.h"
#include "Socket.h"

namespace BOViL{
	namespace comm{
		//-----------------------------------------------------------------------------
		int SocketTCP::sendMsg(const unsigned char *_buffer, const unsigned _bufferSize) {
            int len = send(mSocket, (char *)_buffer, _bufferSize, 0);
            if (len == SOCKET_ERROR) {
				std::cout << "Socket Error" << std::endl;
				closeSocket();
				#if defined (_WIN32)
					std::cout << "Send failed with error: " << WSAGetLastError() << std::endl;
					WSACleanup();
				#endif
				return -1;
			}

            return len;
		}

		//-----------------------------------------------------------------------------
		int SocketTCP::receiveMsg(unsigned char *_buffer, const unsigned _bufferSize) {
			return recv(mSocket, (char *)_buffer, _bufferSize, 0);
		}
	}
}




