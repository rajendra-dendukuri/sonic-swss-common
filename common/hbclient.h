#ifndef __HBCLIENT__
#define __HBCLIENT__

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include "hbcommon.h"

namespace swss {

class HBClient : public Selectable {
public:
    HBClient(string appName,
             hb_client_sla_t sla);
    ~HBClient() override;

    int getFd() override;
    uint64_t readData() override;

private:

    string             m_appName;
    int32_t            m_socket;
    hb_client_sla_t    m_sla;
    //struct sockaddr_un client_sock_addr, server_sock_addr;
    uint32_t           m_pid;
};

}
#endif /* __HBCLIENT__ */

