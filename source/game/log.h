//FIND:
		void		ItemLog(DWORD dwPID, DWORD x, DWORD y, DWORD dwItemID, const char * c_pszText, const char * c_pszHint, const char * c_pszIP, DWORD dwVnum);

//ADD BELOW:
#ifdef TAKE_ENHANCED_MONEY_LOGS
		void		NEWMoneyLog(DWORD chID, const char * player_name, const char * type, const char * info, DWORD vnum, DWORD vID, const char * with_name, long long gold, long long pgold, long long npgold);
#endif