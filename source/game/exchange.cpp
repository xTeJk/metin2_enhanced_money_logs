//FIND:
		if (m_lGold > 1000)
		{
			char exchange_buf[51];
			snprintf(exchange_buf, sizeof(exchange_buf), "%u %s", GetOwner()->GetPlayerID(), GetOwner()->GetName());
			LogManager::instance().CharLog(victim, m_lGold, "EXCHANGE_GOLD_TAKE", exchange_buf);

			snprintf(exchange_buf, sizeof(exchange_buf), "%u %s", victim->GetPlayerID(), victim->GetName());
			LogManager::instance().CharLog(GetOwner(), m_lGold, "EXCHANGE_GOLD_GIVE", exchange_buf);
		}

//REPLACE WHOLE IF STATEMENT WITH:
#ifdef TAKE_ENHANCED_MONEY_LOGS
		if (m_lGold > TAKE_EML_MIN_EXCHANGE_GOLD)
		{
			LogManager::instance().NEWMoneyLog(GetOwner()->GetPlayerID(), GetOwner()->GetName(), "EXCHANGE_GOLD_TAKE", "", 0, victim->GetPlayerID(), victim->GetName(), m_lGold, GetOwner()->GetGold(), GetOwner()->GetGold()+m_lGold);
			LogManager::instance().NEWMoneyLog(victim->GetPlayerID(), victim->GetName(), "EXCHANGE_GOLD_GIVE", "", 0, victim->GetPlayerID(), victim->GetName(), m_lGold, victim->GetGold(), victim->GetGold()+m_lGold);
		}
#else
		if (m_lGold > 1000)
		{
			char exchange_buf[51];
			snprintf(exchange_buf, sizeof(exchange_buf), "%u %s", GetOwner()->GetPlayerID(), GetOwner()->GetName());
			LogManager::instance().CharLog(victim, m_lGold, "EXCHANGE_GOLD_TAKE", exchange_buf);

			snprintf(exchange_buf, sizeof(exchange_buf), "%u %s", victim->GetPlayerID(), victim->GetName());
			LogManager::instance().CharLog(GetOwner(), m_lGold, "EXCHANGE_GOLD_GIVE", exchange_buf);
		}
#endif