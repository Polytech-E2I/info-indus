#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>
#include <unistd.h>

int main(void)
{
    int rs232 = open("/dev/ttyUSB0", O_RDWR);

    if(rs232 < 0)
    {
        fprintf(stderr, "Error %d from %s : %s\n", errno, __FUNCTION__, strerror(errno));
    }

    struct termios serialConfig;
    if(tcgetattr(rs232, &serialConfig) != 0)
    {
        fprintf(stderr, "Error %d from %s : %s\n", errno, __FUNCTION__, strerror(errno));
    }

    serialConfig.c_cflag &= ~(PARENB | CSTOPB | CRTSCTS | CSIZE);
    serialConfig.c_cflag |= (CS8 | CREAD | CLOCAL);

    serialConfig.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHONL | ISIG);

    serialConfig.c_iflag &=
    ~(
        IXON | IXOFF | IXANY |
        IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL
    );

    serialConfig.c_oflag &= ~(OPOST | ONLCR);

    serialConfig.c_cc[VMIN] = 0;
    serialConfig.c_cc[VTIME] = 0;

    cfsetspeed(&serialConfig, B9600);

    if(tcsetattr(rs232, TCSANOW, &serialConfig) != 0)
    {
        fprintf(stderr, "Error %d from %s : %s\n", errno, __FUNCTION__, strerror(errno));
    }


#if 0
    char message[] = "Hello !\r";
    write(rs232, message, sizeof(message));
#endif

#if 1
    char inBuffer[255] = {0};
    char outBuffer = 0;

    while(1)
    {
        outBuffer = getchar();

        if(outBuffer == '\n')
        {
            write(rs232, "\n", 2);
        }
        else
        {
            write(rs232, &outBuffer, sizeof(outBuffer));
        }

        read(rs232, &inBuffer, sizeof(inBuffer));
        printf("%s", inBuffer);
    }

#else

    char outBuffer[] =
    {
        // Sinus
        '0', '0', '\n',
        // Niveau 1.0 V
        '8', '0', ' ', '1', '.', '0', '\n',
        // Fréquence
        '4', '0', ' ', '1', '0', '0', '0', '\n'
    };

    write(rs232, &outBuffer, sizeof(outBuffer));

#endif

#if 1

    char wobulationInitBuffer[] =
    {
        // Sinus
        '0', '0', '\n',
        // Niveau 1.0 V
        '8', '0', ' ', '1', '.', '0', '\n',
    };

    char wobulationLoopBuffer[] =
    {
        // Fréquence
        '4', '0', ' ',
        '0', '0', '0', '0',
        '\n'
    };

    write(rs232, &wobulationInitBuffer, sizeof(wobulationInitBuffer));

    for(int i = 0 ; i < 1000 ; ++i)
    {
        sprintf(&(wobulationLoopBuffer[3]), "%d", i);

        write(rs232, &wobulationLoopBuffer, sizeof(wobulationLoopBuffer));
    }

#endif

    close(rs232);
    return 0;
}