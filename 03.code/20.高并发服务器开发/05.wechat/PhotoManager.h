#ifndef _PHOTO_MANAGER_H
#define _PHOTO_MANAGER_H

#include <string.h>

#include "PhotoInfo.h"

class PhotoManager
{
public:
	int Start();
	int Proc();
	int Restart();
	int Shutdown();

	PhotoInfo users_[1024];
	// GETSETVAR(int, user_count)
	// GETSETVAR(int, cur_user_id)
};

#endif