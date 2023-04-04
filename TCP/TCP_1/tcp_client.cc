#include"tcp_client.hpp"

void Usage(std::string proc)
{
	std::cout << "Usage: " << proc << "server_ip server_port" << std::endl;
}

int main(int argc, char* argv[])
{
	if (argc != 3){
		Usage(argv[0]);
		exit(1);
	}
	std::string server_ip = argv[1];
	uint16_t server_port = atoi(argv[2]);
	TCP::TcpClient Client( server_port, server_ip);
	Client.Start();
	return 0;
}
