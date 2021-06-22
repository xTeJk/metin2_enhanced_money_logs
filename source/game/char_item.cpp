//FIND:
			LogManager::instance().ItemLog(this, pkNewItem, "REFINE SUCCESS", pkNewItem->GetName());

//REPLACE WITH:
#ifdef TAKE_ENHANCED_MONEY_LOGS
			char REFINELogSUCCESS[128];
			snprintf(REFINELogSUCCESS, sizeof(REFINELogSUCCESS), "item_count: %u", pkNewItem->GetCount());
			LogManager::instance().NEWMoneyLog(GetPlayerID(), GetName(), "REFINE_LOG_SUCCESS", REFINELogSUCCESS, pkNewItem->GetVnum(), 0, 0, -cost, GetGold(), GetGold()-cost);
#else
			LogManager::instance().ItemLog(this, pkNewItem, "REFINE SUCCESS", pkNewItem->GetName());
#endif


//FIND:
			LogManager::instance().ItemLog(this, pkNewItem, "REFINE FAIL", pkNewItem->GetName());

//REPLACE WITH:
#ifdef TAKE_ENHANCED_MONEY_LOGS
			char REFINELogFAIL[128];
			snprintf(REFINELogFAIL, sizeof(REFINELogFAIL), "count: %u", pkNewItem->GetCount());
			LogManager::instance().NEWMoneyLog(GetPlayerID(), GetName(), "REFINE_LOG_FAIL", REFINELogFAIL, pkNewItem->GetVnum(), 0, 0, -prt->cost, GetGold(), GetGold()-prt->cost);
#else
			LogManager::instance().ItemLog(this, pkNewItem, "REFINE FAIL", pkNewItem->GetName());
#endif


//FIND:
									PointChange(POINT_GOLD, iGold);

//ADD BELOW:
#ifdef TAKE_ENHANCED_MONEY_LOGS
									char ELKLog[128];
									snprintf(ELKLog, sizeof(ELKLog), "item_count: %u", item->GetCount());
									LogManager::instance().NEWMoneyLog(GetPlayerID(), GetName(), "ITEM_USE_GOLD", ELKLog, item->GetVnum(), 0, 0, item->GetSocket(0), GetGold(), GetGold()+item->GetSocket(0));
#endif


//FIND:
		PointChange(POINT_GOLD, dwMyAmount, true);

//ADD BELOW:
#ifdef TAKE_ENHANCED_MONEY_LOGS
		char GGoldParty[128];
		snprintf(GGoldParty, sizeof(GGoldParty), "total_party_gold: %u", iAmount);
		LogManager::instance().NEWMoneyLog(GetPlayerID(), GetName(), "GIVE_GOLD_PARTY", GGoldParty, 0, 0, 0, dwMyAmount, GetGold(), GetGold()+dwMyAmount);
#endif


//FIND:
		PointChange(POINT_GOLD, iAmount, true);

//ADD BELOW:
#ifdef TAKE_ENHANCED_MONEY_LOGS
		LogManager::instance().NEWMoneyLog(GetPlayerID(), GetName(), "GIVE_GOLD_SOLO", "", 0, 0, 0, iAmount, GetGold(), GetGold()+iAmount);
#endif


//FIND:
				PointChange(POINT_GOLD, dwCount);

//ADD BELOW:
#ifdef TAKE_ENHANCED_MONEY_LOGS
				char CHESTLog[128];
				snprintf(CHESTLog, sizeof(CHESTLog), "x: %u // y: %u", GetX(), GetY());
				LogManager::instance().NEWMoneyLog(GetPlayerID(), GetName(), "CHEST_GOLD", CHESTLog, 0, 0, 0, dwCount, GetGold(), GetGold()+dwCount);
#endif
