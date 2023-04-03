#include "udp_server.hpp"

void RETURN(const std::string &req, std::string *resp)
{
    // //可简单的一条一条回复
    // std::cout << req << std::endl;
    // //std::string str;
    // //std::getline(std::cin, str);
    //  *resp = "Server # req is " + req + '\n';


    //req : 读取到的命令
    *resp = "Server # req is \n";

    //过滤 非法命令
    if(strcasestr(req.c_str(), "rm") != NULL || strcasestr(req.c_str(), "rmdir") != NULL )
    {
        *resp += "非法命令：rm/rmdir\n";
        return ;
    }

    char result[256];

    FILE *fp = popen(req.c_str(), "r");
    if(NULL == fp)
    {
        *resp += "ERROR : popen\n";
        return ;
    }
    while(fgets(result, sizeof(result), fp) != NULL)
    {
        *resp += result;
    }

    fclose(fp);
}

//命令行提示
static void usage(std::string proc)
{
    std::cout << "\nUsage: " << proc << " port\n"
              << std::endl;
}

// ./udp_server port
int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        usage(argv[0]);
    }
    UDP::UdpServer *Server = new UDP::UdpServer(atoi(argv[1]));

    Server->Start(RETURN);

    return 0;
}