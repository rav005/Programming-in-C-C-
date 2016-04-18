#pragma once

#include <iostream>
#include <string>
#include "iMessage.h"

namespace w5{
	class Twitter : public iMessage{
		std::string msg_type;
		std::string msg_user;
		std::string msg_reply;
		std::string msg;
		
		public:
			Twitter();
			Twitter(std::string ty, std::string u, std::string r, std::string m);
			Twitter(std::string ty, std::string u, std::string m);
			void display(std::ostream& os) const;
			Twitter* clone() const;
			bool empty() const;
	};

	class eMail : public iMessage{
		std::string email_type;
		std::string email_from;
		std::string email_to;
		std::string email_date;
		std::string email_body;
		
		public:
			eMail();
			eMail(std::string ty, std::string f, std::string to, std::string d, std::string b);
			void display(std::ostream& os) const;
			eMail* clone() const;
			bool empty() const;
	};
}
