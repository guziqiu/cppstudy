#ifndef _USER_MANAGER_H
#define _USER_MANAGER_H

#include "common/macro.h"
#include "UserInfo.h"

class UserManager
{
public:
	int Start();
	int Proc();
	int Restart();
	int Shutdown();

public:
	UserInfo *GetUser(int user_id);
	int CheckExit(int user_id);
	int CreateUser(const char *user_name, const char *password, int from, int reg_time);
	int DeleteUser(int user_id);
	int SaveUser(); // TODO
	int LoginCheck(const char *user_name, const char *password);
	int UserLogout(int user_id, int time_now);
	int GetUserIdByName(const char *user_name);
	int UpdateUserLoginTime(int user_id, int time_now);
	int UpdateuserLogout(int user_id, int time_now);
	int UpdateUserFreshTime(int user_id, int time_now);

private:
	UserInfo users_[1024];
	GETSETVAR(int, user_count)
	GETSETVAR(int, cur_user_id)
};


#endif