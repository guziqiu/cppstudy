
#ifndef _MESSAGE_MANAGER_H
#define _MESSAGE_MANAGER_H

#include "MessageInfo.h"

class MessageManager
{
public:
	int Start();
	int Proc();
	int Restart();
	int Shutdown();

private:
	MessageInfo users_[1024];
	GETSETVAR(int, user_count)
	GETSETVAR(int, cur_user_id)
};


#endif