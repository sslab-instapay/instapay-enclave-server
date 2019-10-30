#ifndef CHANNEL_H
#define CHANNEL_H

#include <map>
#include <util.h>

class Channel {
    public:
        Channel(unsigned int t_id,
                unsigned char *t_address_a,
                unsigned char *t_address_b,
                unsigned int t_deposit_a,
                unsigned int t_deposit_b
                )
                : m_id(t_id)
                , m_deposit_a(t_deposit_a)
                , m_deposit_b(t_deposit_b)
        {
            m_address_a = ::arr_to_bytes(t_address_a, 40);
            m_address_b = ::arr_to_bytes(t_address_b, 40);
        };

    private:
        unsigned int m_id;
        unsigned char *m_address_a;
        unsigned char *m_address_b;
        unsigned int m_deposit_a;
        unsigned int m_deposit_b;

};

using namespace std;

typedef std::map<unsigned int, Channel> map_channel;
typedef map_channel::value_type map_channel_value;

extern map_channel channels;

#endif