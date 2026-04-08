#include "stdafx.h"
#include "CLab9Client.h"

#include <iostream>

CLab9Client::CLab9Client()
{
    _ip_addr = "192.168.1.100";
}

void CLab9Client::print_menu()
{
    std::cout << "\n===================================";
    std::cout << "\nLab 9 Socket Client";
    std::cout << "\n===================================";
    std::cout << "\n1. Connect to Pi";
    std::cout << "\n2. AUTO ON";
    std::cout << "\n3. AUTO OFF";
    std::cout << "\n4. Sort BLUE";
    std::cout << "\n5. Sort YELLOW";
    std::cout << "\n6. Sort RED";
    std::cout << "\n7. Sort GREEN";
    std::cout << "\n8. Get BLUE count";
    std::cout << "\n9. Get YELLOW count";
    std::cout << "\n10. Get RED count";
    std::cout << "\n11. Get GREEN count";
    std::cout << "\n12. Get AUTO status";
    std::cout << "\n13. Stream image";
    std::cout << "\n0. Exit";
    std::cout << "\nCMD> ";
}

void CLab9Client::connect_to_pi()
{
    std::cout << "\nEnter Raspberry Pi IP address: ";
    std::cin >> _ip_addr;

    _client.connect_socket(_ip_addr, _port);

    std::cout << "\nConnected to " << _ip_addr << ":" << _port << "\n";
}

void CLab9Client::auto_on()
{
    _client.tx_str("S 0 1\n");
    std::cout << "\nAUTO ON command sent\n";
}

void CLab9Client::auto_off()
{
    _client.tx_str("S 0 0\n");
    std::cout << "\nAUTO OFF command sent\n";
}

void CLab9Client::sort_blue()
{
    _client.tx_str("S 1 0\n");
    std::cout << "\nBLUE sort command sent\n";
}

void CLab9Client::sort_yellow()
{
    _client.tx_str("S 1 1\n");
    std::cout << "\nYELLOW sort command sent\n";
}

void CLab9Client::sort_red()
{
    _client.tx_str("S 1 2\n");
    std::cout << "\nRED sort command sent\n";
}

void CLab9Client::sort_green()
{
    _client.tx_str("S 1 3\n");
    std::cout << "\nGREEN sort command sent\n";
}

void CLab9Client::get_blue_count()
{
    std::string rx;
    _client.tx_str("G 1 0\n");

    if (_client.rx_str(rx))
        std::cout << "\nBLUE count = " << rx << "\n";
    else
        std::cout << "\nFailed to get BLUE count\n";
}

void CLab9Client::get_yellow_count()
{
    std::string rx;
    _client.tx_str("G 1 1\n");

    if (_client.rx_str(rx))
        std::cout << "\nYELLOW count = " << rx << "\n";
    else
        std::cout << "\nFailed to get YELLOW count\n";
}

void CLab9Client::get_red_count()
{
    std::string rx;
    _client.tx_str("G 1 2\n");

    if (_client.rx_str(rx))
        std::cout << "\nRED count = " << rx << "\n";
    else
        std::cout << "\nFailed to get RED count\n";
}

void CLab9Client::get_green_count()
{
    std::string rx;
    _client.tx_str("G 1 3\n");

    if (_client.rx_str(rx))
        std::cout << "\nGREEN count = " << rx << "\n";
    else
        std::cout << "\nFailed to get GREEN count\n";
}

void CLab9Client::get_auto_status()
{
    std::string rx;
    _client.tx_str("G 0\n");

    if (_client.rx_str(rx))
    {
        if (rx == "1")
            std::cout << "\nAUTO mode is ON\n";
        else
            std::cout << "\nAUTO mode is OFF\n";
    }
    else
    {
        std::cout << "\nFailed to get AUTO status\n";
    }
}

void CLab9Client::stream_image()
{
    cv::Mat im;

    std::cout << "\nStreaming image... press q to stop.\n";

    while (true)
    {
        _client.tx_str("G 2\n");

        if (_client.rx_im(im))
        {
            if (!im.empty())
            {
                cv::imshow("Remote Pi Image", im);
            }
        }

        int key = cv::waitKey(30);
        if (key == 'q' || key == 'Q')
        {
            break;
        }
    }

    cv::destroyWindow("Remote Pi Image");
}

void CLab9Client::run()
{
    int cmd = -1;

    do
    {
        print_menu();
        std::cin >> cmd;

        switch (cmd)
        {
        case 1: connect_to_pi(); break;
        case 2: auto_on(); break;
        case 3: auto_off(); break;
        case 4: sort_blue(); break;
        case 5: sort_yellow(); break;
        case 6: sort_red(); break;
        case 7: sort_green(); break;
        case 8: get_blue_count(); break;
        case 9: get_yellow_count(); break;
        case 10: get_red_count(); break;
        case 11: get_green_count(); break;
        case 12: get_auto_status(); break;
        case 13: stream_image(); break;
        }
    } while (cmd != 0);
}