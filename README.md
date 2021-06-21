# 📋 Metin2 - Enhanced Money Logs
Control the amount of Yang on your Metin2 server with a few simple logs!  
[![Discord](https://img.shields.io/discord/748288505507217428.svg?label=&logo=discord&logoColor=ffffff&color=7389D8&labelColor=6A7EC2)](https://discord.gg/AEfuvwT)
  
## SCREENS
![Preview1](https://i.imgur.com/ujLvCyv.png)
![Preview2](https://i.imgur.com/0XyNjbR.png)
  
## ENGLISH
System of enhanced logs thanks to which you can easily control  
the amount of yangs on the server and their origin.

Logs include all the basic systems of the game, i.e.:
 - » Picking up yangs from the ground:
	- `GIVE_GOLD_PARTY`: number of yangs received / total number of yangs dropped,
	- `GIVE_GOLD_SOLO`: when party doesn't exist;
 - » Upgrading items (including the count of upgraded items):
	- `REFINE_LOG_SUCCESS`: upgrade successful,
	- `REFINE_LOG_FAIL`: upgrade failed;
 - » Opening chests / boxes:
	- `CHEST_GOLD`: if they contain yangs;
 - » Using an ELK type item:
	- `ITEM_USE_GOLD`: item which stores the amount of yangs in `socket0`;
 - » Create in Cube window:
	- `CUBE_CREATE`: along with the number of crafted items, only for crafting where yangs are required;
 - » Exchange between players (at least 1k yang, to be set in `service.h`):
	- `EXCHANGE_GOLD_TAKE`: yangs received by trading with another player,
	- `EXCHANGE_GOLD_GIVE`: yangs given to another player by trading;
 - » Purchase / sale of items from NPC traders (with quantity and item ID):
	- `NPC_SHOP_BUY`: purchase an item from an NPC,
	- `NPC_SHOP_SELL`: selling an item to an NPC;
 - » Purchase / sale of items in players' stores (with quantity and item ID):
	- `PLAYER_SHOP_BUY`: purchase an item in the player's store,
	- `PLAYER_SHOP_SELL`: selling an item in the player's store;
 - » Receiving and losing yang through quests (at least 50k yang, to be set in `service.h`):
	- `QUEST_GIVE_GOLD`: yangs obtained thanks to the function `pc_give_gold`,
	- `QUEST_CHANGE_GOLD`: yangs changed thanks to the function `pc_change_money`;
  
### CONFIGURATION
`service.h`:
 - » `TAKE_EML_MIN_EXCHANGE_GOLD	1000`: min. amount of Yangs to log exchange between players;
 - » `TAKE_EML_MIN_QUEST_GOLD	50000`: min. amount of Yangs to log gold received/lost through quests;
  
### SYSTEM DEVELOPMENT
It is possible to add logs to any system, the simplest will be to use this example: 
```cpp
/*
	GetPlayerID() » Character ID of Initiator
	GetName() » Player Name of Initiator
	"NEW_MONEY_LOG" » Transaction Type
	NOW() » Transaction Time
	NewLog_AdditionalInfo » Additional Info
	item->GetVnum() » Item VNUM (Possibly)
	victim->GetPlayerID() » With Character ID
	victim->GetName() » With Player Name
	item_cost » Yangs Count
	ch->GetGold()» Initiator Yangs (before transaction)
	ch->GetGold()-item_cost » Initiator New Yangs (after transaction)
*/

//in case you want to store additional information, e.g. about the count of the item 
char NewLog_AdditionalInfo[512];
snprintf(NewLog_AdditionalInfo, sizeof(NewLog_AdditionalInfo), "item_count: %u", item->GetCount());
LogManager::instance().NEWMoneyLog(GetPlayerID(), GetName(), "NEW_MONEY_LOG", NewLog_AdditionalInfo, item->GetVnum(), victim->GetPlayerID(), victim->GetName(), item_cost, ch->GetGold(), ch->GetGold()-item_cost);

//when you don't want to store additional information 
LogManager::instance().NEWMoneyLog(GetPlayerID(), GetName(), "NEW_MONEY_LOG", "", item->GetVnum(), victim->GetPlayerID(), victim->GetName(), item_cost, GetGold(), GetGold()+item_cost);
```

### DATA FILTERING 
Thanks to the friendly layout of the columns, you can easily filter the transactions  
and actions of the player we check, e.g. using his nickname and the approximate date of inaccuracies: 
```sql
SELECT * FROM log.new_money_log WHERE 'char_name' = "take2137" and 'time' > "2021-06-21 21:37:00";
```
  
  
  
## POLISH
System rozbudowanych logów dzięki którym w prosty sposób  
można kontrolować ilość yangów na serwerze oraz ich pochodzenie.

Logi obejmują wszystkie podstawowe elementy rozgrywki, tj.:
 - » Podnoszenie yangów z ziemii:
	- `GIVE_GOLD_PARTY`: otrzymana ilość yangów / ogólna ilość dropniętych yangów,
	- `GIVE_GOLD_SOLO`: gdy party nie istnieje; 
 - » Ulepszanie przedmiotów (wraz z ilością ulepszonych przedmiotów):
	- `REFINE_LOG_SUCCESS`: ulepszanie pomyślne,
	- `REFINE_LOG_FAIL`: ulepszanie niepomyślne;
 - » Otwieranie skrzynek:
	- `CHEST_GOLD`: jeżeli takowe zawierają w sobie yangi;
 - » Używanie przedmiotu o typie ELK:
	- `ITEM_USE_GOLD`: item, który przechowuje ilość yang w `socket0`;
 - » Tworzenie w oknie Cube:
	- `CUBE_CREATE`: wraz z ilością wytworzonych przedmiotów, tylko dla tworzenia gdzie wymagane są yangi;
 - » Wymiana pomiędzy graczami (min. 1k yang, do ustawienia w `service.h`):
	- `EXCHANGE_GOLD_TAKE`: Otrzymane yangi poprzez handel z innym graczem,
	- `EXCHANGE_GOLD_GIVE`: Oddane innemu graczowi yangi poprzez handel;
 - » Zakup / sprzedaż przedmiotów u handlarzy NPC (wraz z ilością oraz ID przedmiotu):
	- `NPC_SHOP_BUY`: zakup przedmiotu od NPC,
	- `NPC_SHOP_SELL`: sprzedaż przedmiotu do NPC;
 - » Zakup / sprzedaż przedmiotów w sklepach graczy (wraz z ilością oraz ID przedmiotu):
	- `PLAYER_SHOP_BUY`: zakup przedmiotu w sklepie gracza,
	- `PLAYER_SHOP_SELL`: sprzedaż przedmiotu w sklepie gracza;
 - » Otrzymywanie oraz tracenie yang poprzez questy (min. 50k yang, do ustawienia w `service.h`):
	- `QUEST_GIVE_GOLD`: yangi otrzymane dzięki funkcji `pc_give_gold`,
	- `QUEST_CHANGE_GOLD`: yangi zmienione dzięki funkcji `pc_change_money`;
  
### KONFIGURACJA
`service.h`:
 - » `TAKE_EML_MIN_EXCHANGE_GOLD	1000`: min. ilość yangów do zapisywania logów z transakcji pomiędzy graczami;
 - » `TAKE_EML_MIN_QUEST_GOLD	50000`: min. ilość yangów do zapisywania logów z otrzymywania / tracenia yangów poprzez questy;
  
### ROZWIJANIE SYSTEMU
Istnieje możliwość dopisania logów do dowolnego systemu, najprostszym będzie skorzystanie z tego przykładu:
```cpp
/*
	GetPlayerID() » ID Postaci Inicjatora
	GetName() » Nazwa Postaci Inicjatora
	"NEW_MONEY_LOG" » Typ Transakcji
	NOW() » Data Transakcji
	NewLog_AdditionalInfo » Dodatkowe Informacje
	item->GetVnum() » VNUM Przedmiotu (możliwość)
	victim->GetPlayerID() » ID Postaci z którą odbył transakcję
	victim->GetName() » Nazwa Postaci z którą odbył transakcję
	item_cost » Ilość Yangów
	ch->GetGold()» Ilość Yangów Inicjatora (przed transakcją)
	ch->GetGold()-item_cost » Nowa Ilość Yangów Inicjatora (po transakcji)
*/

//w przypadku gdy chcesz przechować dodatkowe informacje, np o ilości przedmiotu
char NewLog_AdditionalInfo[512];
snprintf(NewLog_AdditionalInfo, sizeof(NewLog_AdditionalInfo), "item_count: %u", item->GetCount());
LogManager::instance().NEWMoneyLog(GetPlayerID(), GetName(), "NEW_MONEY_LOG", NewLog_AdditionalInfo, item->GetVnum(), victim->GetPlayerID(), victim->GetName(), item_cost, ch->GetGold(), ch->GetGold()-item_cost);

//gdy nie chcesz przechowywać dodatkowych informacji
LogManager::instance().NEWMoneyLog(GetPlayerID(), GetName(), "NEW_MONEY_LOG", "", item->GetVnum(), victim->GetPlayerID(), victim->GetName(), item_cost, GetGold(), GetGold()+item_cost);
```

### FILTROWANIE DANYCH
Dzięki przyjaznemu układowi kolumn w łatwy sposób można filtrować transakcje i akcje gracza,  
którego sprawdzamy, np. korzystając z jego nicku i orientacyjnej daty wystąpienia nieścisłości:
```sql
SELECT * FROM log.new_money_log WHERE 'char_name' = "take2137" and 'time' > "2021-06-21 21:37:00";
```
