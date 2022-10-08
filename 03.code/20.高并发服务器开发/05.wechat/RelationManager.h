#ifndef _RELATION_MANAGER_H
#define _RELATION_MANAGER_H

#include "RelationInfo.h"

class RelationManger
{
public:
	int Start();
	int Proc();
	int Restart();
	int Shutdown();

public:
	int UserRelationInit(int user_id);
	RelationInfo *GetRelation(int user_id);
	int AddFriend(int user_id, int other_id);
	int DelFriend(int user_id, int other_id);
	// addblack
	// del black

private:
	RelationInfo relations_[10240];
	GETSETVAR(int, relation_count)
};

#endif
