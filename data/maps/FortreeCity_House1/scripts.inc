FortreeCity_House1_MapScripts::
	.byte 0

FortreeCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_FORTREE_NPC_TRADE_COMPLETED, FortreeCity_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_PLUSLE
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox FortreeCity_House1_Text_YouWillTradeWontYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FortreeCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FortreeCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, FortreeCity_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_MonYouTakeCare, MSGBOX_DEFAULT
	setflag FLAG_FORTREE_NPC_TRADE_COMPLETED
	release
	end

FortreeCity_House1_EventScript_DeclineTrade::
	msgbox FortreeCity_House1_Text_YouWontTradeMe, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox FortreeCity_House1_Text_ThisIsntAMon, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_TradeCompleted::
	msgbox FortreeCity_House1_Text_GoingToMakeVolbeatStrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House1_EventScript_ExpertF::
	msgbox FortreeCity_House1_Text_TradingMemoriesWithOthers, MSGBOX_NPC
	end

FortreeCity_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House1_Text_YouWillTradeWontYou:
	.string "Wrooooaaar ! J'en ai besoin! Je\n"
	.string "dois me procurer un {STR_VAR_1} ! Je\p"
	.string "ferai n'importe quoi pour ça !\n"
	.string "…Euh… Tu as entendu ça ? Mon cri du\p"
	.string "fond du cœur ? Après avoir entendu\n"
	.string "cela, vous échangerez votre {STR_VAR_1}\p"
	.string "contre mon {STR_VAR_2}, n'est-ce pas ?$"

FortreeCity_House1_Text_MonYouTakeCare:
	.string "Oh, ouais, c'est vrai ! {STR_VAR_1},\n"
	.string "bienvenue ! {STR_VAR_2}, faites\p"
	.string "attention !$"

FortreeCity_House1_Text_ThisIsntAMon:
	.string "Euh non, je ne pense pas. Ce n'est\n"
	.string "pas un {STR_VAR_1}.$"

FortreeCity_House1_Text_YouWontTradeMe:
	.string "Non? Tu ne m'échangeras pas ? Même\n"
	.string "après t'avoir dévoilé mon cœur ?$"

FortreeCity_House1_Text_GoingToMakeVolbeatStrong:
	.string "Je vais rendre VOLBEAT super fort à\n"
	.string "partir de maintenant ! J'espère que\p"
	.string "vous ferez de même avec PLUSLE !$"

FortreeCity_House1_Text_TradingMemoriesWithOthers:
	.string "Échanger POKéMON avec d'autres…\n"
	.string "C'est comme si vous échangez vos\p"
	.string "propres souvenirs avec d'autres\n"
	.string "personnes.$"

FortreeCity_House1_Text_Zigzagoon:
	.string "ZIGZAGOON : Gumomoh ?$"
