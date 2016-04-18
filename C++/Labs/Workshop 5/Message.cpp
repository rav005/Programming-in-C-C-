#include <fstream>
#include "iMessage.h"
#include "Message.h"

namespace w5{
	Twitter::Twitter(){
		msg_type = "";
		msg_user = "";
		msg_reply = "";
		msg = "";
	}
	
	Twitter::Twitter(std::string ty, std::string u, std::string r, std::string m){
		msg_type = ty;
		msg_user = u;
		msg_reply = r;
		msg = m;
	}
	
	Twitter::Twitter(std::string ty, std::string u, std::string m){
		msg_type = ty;
		msg_user = u;
		msg_reply = "";
		msg = m;
	}

	void Twitter::display(std::ostream& os) const{
		if(msg_reply != ""){
			os << msg_type << "\n User  : " << msg_user << "\n Reply : " << msg_reply << "\n Tweet : " << msg << std::endl;
		}else{
			os << msg_type << "\n User  : " << msg_user << "\n Tweet : " << msg << std::endl;
		}
	}

	Twitter* Twitter::clone() const{
		Twitter* r = new Twitter(msg_type, msg_user, msg_reply, msg);
		return r;
	}

	bool Twitter::empty() const{
		if(msg_type != "" && msg_user != ""){
			return false;
		}else{
			return true;
		}
	}
	/*-------------------------End Of TWEET Class functions---------------------------------------*/
	eMail::eMail(){
		email_type = "";
		email_from = "";
		email_to = "";
		email_date = "";
		email_body = "";
	}
	
	eMail::eMail(std::string ty, std::string f, std::string to, std::string d, std::string b){
		email_type = ty;
		email_from = f;
		email_to = to;
		email_date = d;
		email_body = b;
	}

	void eMail::display(std::ostream& os) const{
		if(email_from != "" && email_to != "" && email_date != ""){
			os << email_type << "\n From  : " <<  email_from << "\n To    : " << email_to << "\n Date  : " << email_date << "\n Body  : " << email_body << std::endl;
		}
	}

	eMail* eMail::clone() const{
		eMail* r = new eMail(email_type, email_from, email_to, email_date, email_body);
		return r;
	}

	bool eMail::empty() const{
		if(email_type != "" && email_from != "" && email_to != "" && email_date != ""){
			return false;
		}else{
			return true;
		}
	}

    iMessage* getMessage(std::ifstream& source, char s){
		iMessage* ret = nullptr;
		std::string line;
        if(source.is_open()){
			if(!source.eof()){
				std::getline(source,line,s);
				
				if(line.length() == 0) { // read an empty line
						ret = new Twitter();
				}else{
					if(line[0] == 'T'){
						std::string user;
					std::string reply;
					std::string twt;
					for(int i=1; i < line.length(); i++){
						int space = line.find_first_of(' ');
						if(line[i] != ' '){
							if(space >= 0){
								user = line.substr(1,space);
							}
						}
						int newI = space+1;
						if(line[newI] == '@'){
							std::string temp;
							temp = line.substr(newI+1,line.length());
							int space2 = temp.find_first_of(' ');
							reply = temp.substr(0,space2);
							int space3 = temp.find_first_of(' ');
							twt = temp.substr(space3+1,line.length());
						}
						else{
							std::string temp;
							twt = line.substr(newI,line.length());
						}
					}
						if(reply[0] != '\0'){
							ret = new Twitter("Twitter", user, reply, twt);
						}else{
							ret = new Twitter("Twitter", user, twt);
						}
					}else if(line[0] == 'e'){
						std::string from;
					std::string to;
					std::string date;
					std::string body;
			
					for(int i=1; i < line.length(); i++){
						int space = line.find_first_of(' ');
						if(line[i] != ' '){
							if(space >= 0){
								std::string temp = line.substr(0,space);
								int colan = line.find_first_of(':');
								if(colan >= 0){
									from = temp.substr(colan+1,space);
								}
							}
						}
						int newI = space + 1;
						if(line[newI] == 'T'){
							std::string temp = line.substr(newI,line.length());
							int space = temp.find_first_of(' ');
							if(space >= 0){
								std::string temp2 = temp;
								temp = temp.substr(0,space);
								int colan = temp.find_first_of(':');
								if(colan >= 0){
									to = temp.substr(colan+1,space);
								}
								//Date
								std::string temp3;
								int space2 = temp2.find_first_of(' ');
								temp2 = temp2.substr(space2+1,line.length());
								int space3 = temp2.find_first_of(' ');
								temp3 = temp2;
								temp2 = temp2.substr(0,space3);
								int colan2 = temp2.find_first_of(':');
								date = temp2.substr(colan2+1,space3);	
								//Body
								int finalSpace = temp3.find_first_of(' ');
								temp3 = temp3.substr(finalSpace+1,line.length());
								int finalColan = temp2.find_first_of(':');
								body = temp3.substr(finalColan+1,line.length());
							}
						}
					}
						ret = new eMail("eMail", from, to, date, body);
					}else{
						ret = new Twitter();
					}
				}
			}else{
				return new eMail();
			}
        }//is_file.open()
		return ret;
	}
}
