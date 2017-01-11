/////////////////////////////////////////////////////////////////////////////////////////
//	BOVIL: core
//
//			Author:		Pablo Ramon Soria
//			Date:		2014-05-31
//
/////////////////////////////////////////////////////////////////////////////////////////

#ifndef _BOVIL_CORE_COMM_SOCKETTCP_H_
#define _BOVIL_CORE_COMM_SOCKETTCP_H_

#include "Socket.h"

namespace BOViL{
	namespace comm{
		/** Basic interface of TCP socket type. Define send and reception protocols.
		*/
		class SocketTCP : public Socket{
		public:
			/** \brief send message throught socket.
			*	@param _buffer: buffer array that contains message to be sended.
			*	@param _bufferSize:	size message.
			*/
			int sendMsg(const unsigned char *_buffer, const unsigned _bufferSize);

			/** \brief read message from socket.
			*	@param _buffer: buffer to store received message.
			*	@param _bufferSize: max size of buffer.
			*/
			int receiveMsg(unsigned char *_buffer, const unsigned _bufferSize);
		
		protected:
			SocketTCP() {};

		};	//	class SocketTCP
	}
}


#endif // _BOVIL_CORE_COMM_SOCKETUDP_H_