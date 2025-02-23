RustboroCity_House1_MapScripts::
	.byte 0

RustboroCity_House1_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_RUSTBORO_NPC_TRADE_COMPLETED, RustboroCity_House1_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_SEEDOT
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox RustboroCity_House1_Text_IllTradeIfYouWant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_House1_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, RustboroCity_House1_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, RustboroCity_House1_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox RustboroCity_House1_Text_PleaseBeGoodToMyPokemon, MSGBOX_DEFAULT
	setflag FLAG_RUSTBORO_NPC_TRADE_COMPLETED
	release
	end

RustboroCity_House1_EventScript_DeclineTrade::
	msgbox RustboroCity_House1_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox RustboroCity_House1_Text_DoesntLookLikeMonToMe, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_TradeCompleted::
	msgbox RustboroCity_House1_Text_AnyPokemonCanBeCute, MSGBOX_DEFAULT
	release
	end

RustboroCity_House1_EventScript_Hiker::
	msgbox RustboroCity_House1_Text_AllSortsOfPlaces, MSGBOX_NPC
	end

RustboroCity_House1_Text_IllTradeIfYouWant:
	.string "Hein? Mon POKéMON est mignon ? Bien\n"
	.string "sûr, je le savais. Mais si tu le\p"
	.string "veux vraiment, je suis prêt à te\n"
	.string "l'échanger. Je t'échangerai mon\p"
	.string "{STR_VAR_2} contre un {STR_VAR_1} si tu\n"
	.string "veux.$"

RustboroCity_House1_Text_PleaseBeGoodToMyPokemon:
	.string "Eheheh… S'il vous plaît, soyez\n"
	.string "gentil avec mon POKéMON.$"

RustboroCity_House1_Text_DoesntLookLikeMonToMe:
	.string "Hein? Cela ne me ressemble en rien\n"
	.string "à un {STR_VAR_1}.$"

RustboroCity_House1_Text_YouDontWantToThatsOkay:
	.string "Oh, si tu ne veux pas, ce n'est pas\n"
	.string "grave. Mais mon POKéMON est mignon,\p"
	.string "tu sais…$"

RustboroCity_House1_Text_AnyPokemonCanBeCute:
	.string "N'importe quel POKéMON peut être\n"
	.string "mignon si vous l'élevez avec soin\p"
	.string "et gentillesse.$"

RustboroCity_House1_Text_AllSortsOfPlaces:
	.string "Dans toutes sortes d'endroits, il y\n"
	.string "a toutes sortes de POKéMON et de\p"
	.string "personnes. Je trouve ça fascinant,\n"
	.string "alors je vais dans toutes sortes\p"
	.string "d’endroits.$"
