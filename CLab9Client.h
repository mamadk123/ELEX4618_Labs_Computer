#pragma once

#include "Client.h"
#include <string>
#include <opencv2/opencv.hpp>

class CLab9Client
{
public:
    CLab9Client();
    void run();

private:
    void print_menu();
    void connect_to_pi();

    void auto_on();
    void auto_off();

    void sort_blue();
    void sort_yellow();
    void sort_red();
    void sort_green();

    void get_blue_count();
    void get_yellow_count();
    void get_red_count();
    void get_green_count();

    void get_auto_status();
    void stream_image();

private:
    CClient _client;
    std::string _ip_addr;
    int _port = 4618;
};