#include "RelationManager.h"
#include "common/ret_value.h"

int RelationManger::Start()
{
	return SUCCESS;
}


int RelationManger::Proc()
{
	return SUCCESS;
}


int RelationManger::Restart()
{
	return SUCCESS;
}


int RelationManger::Shutdown()
{
	return SUCCESS;
}


int RelationManger::UserRelationInit(int user_id)
{
	if (relation_count_ < 10239)
	{
		relations_[relation_count_].set_user_id(user_id);
		relation_count_++;
		return SUCCESS;
	}

	return RELATION_TO_MUCH;
}


RelationInfo *RelationManger::GetRelation(int user_id)
{
	for (int i = 0; i < relation_count_; ++i)
	{
		if (relations_[i].user_id() == user_id)
		{
			return &relations_[i];
		}
	}

	return NULL;
}


int RelationManger::AddFriend(int user_id, int other_id)
{
	RelationInfo *relation = GetRelation(user_id);
	if (NULL == relation)
	{
		return RELATION_NOT_EXIST;
	}

	return relation->AddFriend(other_id);
}


int RelationManger::DelFriend(int user_id, int other_id)
{
	RelationInfo *relation = GetRelation(user_id);
	if (NULL == relation)
	{
		return RELATION_NOT_EXIST;
	}

	return relation->DeleteFriend(other_id);
}

