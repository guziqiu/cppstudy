#include "MessageManager.h"
#include "common/ret_value.h"

int MessageManager::Start()
{
	set_cur_user_id(10001);
	set_user_count(0);

	// todo 
	// read users from db
	// read cur_user_id form db
	return SUCCESS;
}

int MessageManager::Proc()
{
	return SUCCESS;
}

int MessageManager::Restart()
{
	return SUCCESS;
}

int MessageManager::Shutdown()
{
	return SUCCESS;
}
