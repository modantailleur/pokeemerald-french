BattleFrontier_Lounge6_MapScripts::
	.byte 0

BattleFrontier_Lounge6_EventScript_Trader::
	lock
	faceplayer
	goto_if_set FLAG_BATTLE_FRONTIER_TRADE_DONE, BattleFrontier_Lounge6_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_MEOWTH
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox BattleFrontier_Lounge6_Text_WouldYouLikeToTrade, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge6_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge6_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, BattleFrontier_Lounge6_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt, MSGBOX_DEFAULT
	setflag FLAG_BATTLE_FRONTIER_TRADE_DONE
	release
	end

BattleFrontier_Lounge6_EventScript_DeclineTrade::
	msgbox BattleFrontier_Lounge6_Text_WellThatsFineToo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_NotRequestedMon::
	bufferspeciesname STR_VAR_1, VAR_0x8009
	msgbox BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_EventScript_TradeCompleted::
	msgbox BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge6_Text_WouldYouLikeToTrade:
	.string "Mon POKéMON est un {STR_VAR_2}. Le\n"
	.string "savez-vous ? C'est assez mignon et\p"
	.string "plutôt sympa. Ce petit, je pourrais\n"
	.string "l'échanger avec fierté !\p"
	.string "Souhaitez-vous m'échanger un {STR_VAR_1}\n"
	.string "contre mon {STR_VAR_2} ?$"

BattleFrontier_Lounge6_Text_PromiseIllBeGoodToIt:
	.string "Oh, c'est adorable ! Merci! Je\n"
	.string "promets que je serai bon avec ça !\p"
	.string "Oh! J'espère que vous serez\n"
	.string "également gentil avec mon {STR_VAR_2} !$"

BattleFrontier_Lounge6_Text_DontTradeForAnythingButMon:
	.string "Oh je suis désolé! Je n'ai pas\n"
	.string "l'intention d'échanger contre autre\p"
	.string "chose qu'un {STR_VAR_1}.$"

BattleFrontier_Lounge6_Text_WellThatsFineToo:
	.string "Oh, tu ne le feras pas ? Eh bien,\n"
	.string "c'est bien aussi. S'il vous plaît,\p"
	.string "revenez nous rendre visite.$"

BattleFrontier_Lounge6_Text_SkittySoMuchCuterThanImagined:
	.string "Pouffer de rire! Un SKITTY est\n"
	.string "tellement plus mignon que je ne\p"
	.string "l’avais imaginé. Je suis ravie!$"
