#ifndef _RET_VALUE_H
#define _RET_VALUE_H

enum
{
	SUCCESS              = 0,
	USER_NOT_EXIST      = -100,
	USER_EXIST          = -101,
	WRONG_PASSWD        = -102,
	FLAG_INSERT         = -501,
	FLAG_DELETE         = -502,
	FLAG_UPDATE         = -503,
	NOT_FRIEND          = -200,
	ALREADY_FRIEND      = -201,
	FRIEND_TO_MOUCH     = -202,
	FRIEND_INDEX_WRONG  = -203,
	NOT_BLACK           = -211,
	MESSAGE_NOT_EXIST   = -400,

	RELATION_TO_MUCH    = -220,
	RELATION_NOT_EXIST  = -221,
};

#endif