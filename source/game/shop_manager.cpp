//FIND:
	DBManager::instance().SendMoneyLog(MONEY_LOG_SHOP, item->GetVnum(), dwPrice);

//REPLACE WITH:
#ifdef TAKE_ENHANCED_MONEY_LOGS
	char NPCShopSellLog[512];
	snprintf(NPCShopSellLog, sizeof(NPCShopSellLog), "item_count: %u", item->GetCount());
	LogManager::instance().NEWMoneyLog(ch->GetPlayerID(), ch->GetName(), "NPC_SHOP_SELL", NPCShopSellLog, item->GetVnum(), 0, "", dwPrice, ch->GetGold(), ch->GetGold()+dwPrice);
#else
	DBManager::instance().SendMoneyLog(MONEY_LOG_SHOP, item->GetVnum(), dwPrice);
#endif
