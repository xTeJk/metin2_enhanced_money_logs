//FIND:
			LogManager::instance().CubeLog(ch->GetPlayerID(), ch->GetX(), ch->GetY(), reward_value->vnum, new_item->GetID(), reward_value->count, 1);

//REPLACE WITH:
#ifdef TAKE_ENHANCED_MONEY_LOGS
			if (cube_proto->gold > 0)
			{
				char CUBELog[128];
				snprintf(CUBELog, sizeof(CUBELog), "item_count: %u", new_item->GetCount());
				LogManager::instance().NEWMoneyLog(ch->GetPlayerID(), ch->GetName(), "CUBE_CREATE", CUBELog, new_item->GetVnum(), 0, 0, cube_proto->gold, ch->GetGold(), ch->GetGold()-cube_proto->gold);
			}
#else
			LogManager::instance().CubeLog(ch->GetPlayerID(), ch->GetX(), ch->GetY(), reward_value->vnum, new_item->GetID(), reward_value->count, 1);
#endif