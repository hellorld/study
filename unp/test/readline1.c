#include "unp.h"

// PAINFULLY SLOW VERSION -- example only

ssize_t readline(int fd, void* vptr, size_t maxlen)
{
    ssize_t n, rc;
    char c, *ptr;

    ptr = (char*)vptr;
    for (n = 1; n < maxlen; ++n)
    {
        if ((rc = read(fd, &c, 1)) == 1)
        {
            *ptr++ = c;
            if (c == '\n')
            {
                break;
            }
        }
        else if (rc == 0)
        {
            *ptr = 0;
            return n-1;
        }
        else
        {
            if (errno != EINTR)
            {
                return -1;
            }
        }
    }

    *ptr = 0;
    return n;
}
