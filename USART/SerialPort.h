#pragma once
class SerialPort
{
public:
    int m_Port;
    char szCurPath[256];
    SerialPort();
    ~SerialPort();
    bool OpenPort(int port);
    bool SetPort(DWORD baud, BYTE stop, BYTE data, BYTE parity);
    void ClosePort();
    bool ReadDate(unsigned char* receive, DWORD& receivelen);
    bool WriteDate(unsigned char* send, int sendlen);
private:
    OVERLAPPED ReadovReady, WriteovReady;
    HANDLE hCom;
    bool bOpenCom;
};

