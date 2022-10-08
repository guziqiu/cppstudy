#ifndef _MESSAGE_INFO_H
#define _MESSAGE_INFO_H

#include <string.h>

#include "common/macro.h"

class MessageInfo
{
	GETSETVAR(int, user_id)
	GETSETVAR(int, lash_publisher)
	GETSETVAR(int, publish_time)
	GETSETSTR(1024, content)
};


#endif