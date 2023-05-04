#include"TcpServer.hpp"

#include <memory>

static Response calculator(const Request &req)
{
    Response resp(0, 0);
    switch (req.op_)
    {
    case '+':
        resp.result_ = req.x_ + req.y_;
        break;
    case '-':
        resp.result_ = req.x_ - req.y_;
        break;
    case '*':
        resp.result_ = req.x_ * req.y_;
        break;
    case '/':
        if (0 == req.y_)
            resp.code_ = 1;
        else
            resp.result_ = req.x_ / req.y_;
        break;
    case '%':
        if (0 == req.y_)
            resp.code_ = 2;
        else
            resp.result_ = req.x_ % req.y_;
        break;
    default:
        resp.code_ = 3;
        break;
    }
    return resp;
}

void NetCal(Connection* conn, std::string &request)
{
    logMessage(DEBUG, "Netcal been called, requset: %s.", request.c_str());

    //此时，request一定是一个完整报文
    //1. 反序列化
    Request req;
    if(!req.Deserialized(request)) return ;

    //2. 业务处理
    Response resp = calculator(req);

    //3. 先序列化， 再构建应答
    std::string sendstr = resp.Serialize();
    sendstr = Encode(sendstr);

    //4. 交给服务器
    conn->_outBuffer += sendstr;

    //5. 服务器发送 -- 需要开启epoll的写事件权限EPOLLOUT
    //每次打开某个文件的写权限时，都会触发一次epoll
    //通过tsvr指针触发一次epoll模型
    conn->_tsvr->EnableReadWrite(conn, true, true);


}

int main()
{

    std::unique_ptr<TcpServer> tsvr(new TcpServer());
    tsvr->Dispather(NetCal);

    return 0;
}