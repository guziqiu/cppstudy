#ifndef _USERINFO_H
#define _USERINFO_H

#include <string.h>
#include "common/macro.h"


class UserInfo
{
public:
	
private:
	GETSETVAR(int, user_id)
	GETSETSTR(256, user_name)
	GETSETSTR(256, nick_name)
	GETSETVAR(int, reg_time)
	GETSETVAR(int, from)
	GETSETVAR(int, login_time)
	GETSETVAR(int, last_login_name)
	GETSETVAR(int, fresh_time)
	GETSETSTR(256, password)
	GETSETVAR(int, logout_time)
	GETSETVAR(int, db_flag);
};

#endif