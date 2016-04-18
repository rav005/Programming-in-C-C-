#pragma once

#include <iostream>
#include "iMessage.h"
const int MAX=10;

namespace w5{
    class Notifications{
		iMessage* msg[MAX];
        int count;
        
		public:
            Notifications();
            Notifications(const Notifications& source);
            Notifications& operator=(const Notifications& source);
            Notifications(Notifications&& source);
            Notifications& operator=(Notifications&& source);
            ~Notifications();
            void operator+=(const iMessage& source);
            void display(std::ostream& os) const;
    };
}
