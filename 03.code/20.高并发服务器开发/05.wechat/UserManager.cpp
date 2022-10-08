#include "UserManager.h"
#include "common/ret_value.h"

int UserManager::Start()
{
	set_cur_user_id(10001);
	set_user_count(0);

	// todo 
	// read users from db
	// read cur_user_id form db
	return SUCCESS;
}

int UserManager::Proc()
{
	return SUCCESS;
}

int UserManager::Restart()
{
	return SUCCESS;
}

int UserManager::Shutdown()
{
	return SUCCESS;
}

UserInfo *UserManager::GetUser(int user_id)
{
	for (int i = 0; i < user_count_; ++i)
	{
		if (users_[i].user_id() == user_id)
		{
			return &users_[i];
		}
	}

	return NULL;
}

int UserManager::CheckExit(int user_id)
{
	for (int i = 0; i < user_count_; ++i)
	{
		if (users_[i].user_id() == user_id)
		{
			return USER_EXIST;
		}
	}

	return USER_NOT_EXIST;
}

int UserManager::CreateUser(const char *user_name, const char *password, int from, int reg_time)
{
	for (int i = 0; i < user_count_; ++i)
	{
		if (strcmp(users_[i].user_name(), user_name) == 0)
		{
			return USER_EXIST;
		}
	}

	if (user_count_ < 10239)
	{
		users_[user_count_].set_user_id(cur_user_id());
		users_[user_count_].set_user_name(user_name);
		users_[user_count_].set_password(password);
		users_[user_count_].set_from(from);
		users_[user_count_].set_reg_time(reg_time);
		users_[user_count_].set_db_flag(FLAG_INSERT);
		++user_count_;
	}

	set_cur_user_id(cur_user_id() + 1);
	// SaveUser();
	return SUCCESS;
}

int UserManager::DeleteUser(int user_id)
{
	for (int i = 0; i < user_count_; ++i)
	{
		if (users_[i].user_id() == user_id)
		{
			users_[i].set_db_flag(FLAG_DELETE);
			return SUCCESS;
		}
	}

	return USER_NOT_EXIST;
}

int UserManager::SaveUser()
{
	return SUCCESS;
}

int UserManager::LoginCheck(const char *user_name, const char *password)
{
	for (int i = 0; i < user_count_; ++i)
	{
		if (0 == strcmp(users_[i].user_name(), user_name))
		{
			if (strcmp(users_[i].password(), password))
			{
				return SUCCESS;
			}
			else
			{
				return WRONG_PASSWD;
			}
		}
	}

	return USER_NOT_EXIST;
}

int UserManager::UserLogout(int user_id, int time_now)
{
	for (int i = 0; i < user_count_; ++i)
	{
		if (users_[i].user_id() == user_id)
		{
			users_[i].set_logout_time(time_now);
			users_[i].set_db_flag(FLAG_UPDATE);

			return SUCCESS;
		}
	}

	return USER_NOT_EXIST;
}
int UserManager::GetUserIdByName(const char *user_name)
{
	return SUCCESS;
}
int UserManager::UpdateUserLoginTime(int user_id, int time_now)
{
	UserInfo* user=GetUser(user_id);
	if (NULL == user)
	{
		return USER_NOT_EXIST;
	}

	user->set_login_time(time_now);
	user->set_db_flag(FLAG_UPDATE);
	return SUCCESS;
}
int UserManager::UpdateuserLogout(int user_id, int time_now)
{
	return SUCCESS;
}
int UserManager::UpdateUserFreshTime(int user_id, int time_now)
{
	return SUCCESS;
}

