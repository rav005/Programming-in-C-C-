#include <functional>
#include "Notifications.h"

namespace w5{
	Notifications::Notifications(){
        msg[0] = nullptr;
        count = 0;
	}

	Notifications::Notifications(const Notifications& source){
        count = source.count;

        for(int i=0; i < count; i++){
            msg[i] = source.msg[i];
        }
	}

	Notifications& Notifications::operator=(const Notifications& source){
        count = source.count;

        for(int i=0; i < count; i++){
            msg[i] = source.msg[i];
        }
    return *this;
	}

	Notifications::Notifications(Notifications&& source){
	    *this = std::move(source);
    }

	Notifications& Notifications::operator=(Notifications&& source){
        if(&source != this){
            count = source.count;
            for(int i=0; i < count; i++){
                msg[i] = source.msg[i];
                source.msg[i] = nullptr;
            }
       }
        return *this;
	}

	Notifications::~Notifications(){
        for(int i=0; i < count; i++)
            delete [] msg[i];
	}

	void Notifications::operator+=(const iMessage& source){
        if(count < MAX){
			msg[count++] = source.clone();
        }else{
            std::cerr << "There is no more space left in Notifications." << std::endl;
        }
	}

	void Notifications::display(std::ostream& os) const{
        for(int i=0; i < count; i++){
            msg[i]->display(os);
        }
	}
}
