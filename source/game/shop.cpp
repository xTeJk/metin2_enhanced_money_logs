//FIND:
			snprintf(buf, sizeof(buf), "%s %u(%s) %u %u", pkNewItem->GetName(), mpid, m_pkPC->GetName(), dwPrice, pkNewItem->GetCount());
			LogManager::instance().ItemLog(ch, pkNewItem, "SHOP_BUY", buf);
			snprintf(buf, sizeof(buf), "%s %u(%s) %u %u", pkNewItem->GetName(), ch->GetPlayerID(), ch->GetName(), dwPrice, pkNewItem->GetCount());
			LogManager::instance().ItemLog(m_pkPC, pkNewItem, "SHOP_SELL", buf);

//REPLACE WITH:
#ifdef TAKE_ENHANCED_MONEY_LOGS
			snprintf(PLAYERshopLog, sizeof(PLAYERshopLog), "item_count: %u", pkNewItem->GetCount());
			LogManager::instance().NEWMoneyLog(ch->GetPlayerID(), ch->GetName(), "PLAYER_SHOP_BUY", PLAYERshopLog, pkNewItem->GetVnum(), m_pkPC->GetPlayerID(), m_pkPC->GetName(), -dwPrice, ch->GetGold(), ch->GetGold()-dwPrice);

			snprintf(PLAYERshopLog, sizeof(PLAYERshopLog), "item_count: %u", pkNewItem->GetCount());
			LogManager::instance().NEWMoneyLog(m_pkPC->GetPlayerID(), m_pkPC->GetName(), "PLAYER_SHOP_SELL", PLAYERshopLog, pkNewItem->GetVnum(), ch->GetPlayerID(), ch->GetName(), dwPrice, m_pkPC->GetGold(), m_pkPC->GetGold()+dwPrice);
#else
			snprintf(buf, sizeof(buf), "%s %u(%s) %u %u", pkNewItem->GetName(), mpid, m_pkPC->GetName(), dwPrice, pkNewItem->GetCount());
			LogManager::instance().ItemLog(ch, pkNewItem, "SHOP_BUY", buf);
			snprintf(buf, sizeof(buf), "%s %u(%s) %u %u", pkNewItem->GetName(), ch->GetPlayerID(), ch->GetName(), dwPrice, pkNewItem->GetCount());
			LogManager::instance().ItemLog(m_pkPC, pkNewItem, "SHOP_SELL", buf);
#endif


//FIND:
		LogManager::instance().ItemLog(ch, item, "BUY", item->GetName());

//REPLACE WITH:
#ifdef TAKE_ENHANCED_MONEY_LOGS
		char NPCShopLog[512];
		snprintf(NPCShopLog, sizeof(NPCShopLog), "item_count: %u", item->GetCount());
		LogManager::instance().NEWMoneyLog(ch->GetPlayerID(), ch->GetName(), "NPC_SHOP_BUY", NPCShopLog, item->GetVnum(), 0, "", -dwPrice, ch->GetGold(), ch->GetGold()-dwPrice);
#else
		LogManager::instance().ItemLog(ch, item, "BUY", item->GetName());
#endif