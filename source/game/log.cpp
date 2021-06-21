//FIND:
void LogManager::ItemLog(LPCHARACTER ch, int itemID, int itemVnum, const char * c_pszText, const char * c_pszHint)
{
	ItemLog(ch->GetPlayerID(), ch->GetX(), ch->GetY(), itemID, c_pszText, c_pszHint, ch->GetDesc() ? ch->GetDesc()->GetHostName() : "", itemVnum);
}

//ADD BELOW:
#ifdef TAKE_ENHANCED_MONEY_LOGS
void LogManager::NEWMoneyLog(DWORD chID, const char * player_name, const char * type, const char * info, DWORD vnum, DWORD vID, const char * with_name, long long gold, long long pgold, long long npgold)
{
	/*
	Character ID of Initiator
	Player Name of Initiator
	Transaction Type
	Transaction Time
	Additional Info
	Item VNUM (Possibly)
	With Character ID
	With Player Name
	Gold Count
	Initiator Gold (before transaction
	Initiator New Gold (after transaction)
	*/
	m_sql.EscapeString(__escape_info, sizeof(__escape_info), info, strlen(info));

	Query("INSERT DELAYED INTO new_money_log%s (char_id, player_name, type, time, add_info, vnum, with_id, with_name, transaction_gold, pgold_before_transaction, pgold_after_transaction) VALUES('%u', '%s', '%s', NOW(), '%s', '%u', '%u', '%s', '%lld', '%lld', '%lld')",
			get_table_postfix(), chID, char_name, type, __escape_info, vnum, vID, with_name, gold, pgold, npgold);
}
#endif