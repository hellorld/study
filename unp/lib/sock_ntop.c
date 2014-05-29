#include "unp.h"

char* sock_ntop(const struct sockaddr* sa, socklen_t salen)
{
    char portstr[8] = {0};
    static char str[128] = {0};

    switch (sa->sa_family)
    {
        case AF_INET:
        {
            struct sockaddr_in *sin = (struct sockaddr_in*)sa;
            if (inet_ntop(AF_INET, &sin->sin_addr, str, sizeof(str)) == NULL)
            {
                return NULL;
            }
            if (ntohs(sin->sin_port) != 0)
            {
                snprintf(portstr, sizeof(portstr), ":%d", ntohs(sin->sin_port));
                strcat(str, portstr);
            }
            return str;
        }
        case AF_INET6:
        {
            struct sockaddr_in6 *sin6 = (struct sockaddr_in6*)sa;
            if (inet_ntop(AF_INET6, &sin6->sin6_addr, str, sizeof(str)) == NULL)
            {
                return NULL;
            }
            if (ntohs(sin6->sin6_port) != 0)
            {
                snprintf(portstr, sizeof(portstr), ":%d", ntohs(sin6->sin6_port));
                strcat(str, portstr);
            }
            return str;
        }
    }
    return NULL;
}
