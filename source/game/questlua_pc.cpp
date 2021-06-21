//FIND:
		DBManager::instance().SendMoneyLog(MONEY_LOG_QUEST, ch->GetPlayerID(), iAmount);

//REPLACE WITH:
#ifdef TAKE_ENHANCED_MONEY_LOGS
		if (iAmount >= TAKE_EML_MIN_QUEST_GOLD)
			LogManager::instance().NEWMoneyLog(ch->GetPlayerID(), ch->GetName(), "QUEST_GIVE_GOLD", "", 0, 0, 0, iAmount, ch->GetGold(), ch->GetGold()+iAmount);
#else
		DBManager::instance().SendMoneyLog(MONEY_LOG_QUEST, ch->GetPlayerID(), iAmount);
#endif


//FIND:
			DBManager::instance().SendMoneyLog(MONEY_LOG_QUEST, ch->GetPlayerID(), gold);

//REPLACE WITH:
#ifdef TAKE_ENHANCED_MONEY_LOGS
		if (iAmount >= TAKE_EML_MIN_QUEST_GOLD)
			LogManager::instance().NEWMoneyLog(ch->GetPlayerID(), ch->GetName(), "QUEST_CHANGE_GOLD", "", 0, 0, 0, gold, ch->GetGold(), ch->GetGold()+gold);
#else
			DBManager::instance().SendMoneyLog(MONEY_LOG_QUEST, ch->GetPlayerID(), gold);
#endif