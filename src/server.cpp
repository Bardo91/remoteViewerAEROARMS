#include "server.h"
#include "com/Socket.h"


Server::Server(int _port) {
    mPort=_port;
    socket=BOViL::comm::Socket::createSocket(BOViL::comm::eSocketType::serverTCP, std::to_string(_port).c_str(), "0.0.0.0");
    std::cout << "Server socket created"<< std::endl;
}

void Server::send(cv::Mat _img, int _percent) {

    unsigned char buffer[1024];

    // std::cout << "Waiting for take a picture"<< std::endl;
    socket->receiveMsg(buffer,1024);
    // std::cout << "Petition received. Sending picture"<< std::endl;

    std::vector<uchar> buff;
    std::vector<int> params;
    params.push_back(CV_IMWRITE_JPEG_QUALITY);
    params.push_back(_percent);
    cv::imencode(".jpg", _img, buff, params);
    int bufferSize = buff.size();
    // std::cout << bufferSize << std::endl;

    socket->sendMsg((unsigned char*)&bufferSize, sizeof(int));
    socket->receiveMsg(buffer,1024);
    socket->sendMsg(&buff[0], buff.size());

}
