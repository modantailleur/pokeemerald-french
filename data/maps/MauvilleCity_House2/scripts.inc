MauvilleCity_House2_MapScripts::
	.byte 0

MauvilleCity_House2_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_COIN_CASE, MauvilleCity_House2_EventScript_ReceivedCoinCase
	msgbox MauvilleCity_House2_Text_BuyHarborMailAtSlateport, MSGBOX_DEFAULT
	checkitem ITEM_HARBOR_MAIL
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_House2_EventScript_AskToTradeForHarborMail
	release
	end

MauvilleCity_House2_EventScript_AskToTradeForHarborMail::
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_House2_Text_TradeHarborMailForCoinCase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_House2_EventScript_AcceptTrade
	goto_if_eq VAR_RESULT, NO, MauvilleCity_House2_EventScript_DeclineTrade
	end

MauvilleCity_House2_EventScript_AcceptTrade::
	msgbox MauvilleCity_House2_Text_IllTradeYouCoinCase, MSGBOX_DEFAULT
	removeitem ITEM_HARBOR_MAIL
	giveitem ITEM_COIN_CASE
	setflag FLAG_RECEIVED_COIN_CASE
	goto MauvilleCity_House2_EventScript_ReceivedCoinCase
	end

MauvilleCity_House2_EventScript_ReceivedCoinCase::
	msgbox MauvilleCity_House2_Text_UseCoinCaseAtGameCorner, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_EventScript_DeclineTrade::
	msgbox MauvilleCity_House2_Text_ThatsDisappointing, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House2_Text_BuyHarborMailAtSlateport:
	.string "Si j'avais un VÉLO, il serait\n"
	.string "facile de me rendre à SLATEPORT\p"
	.string "pour faire du shopping. Je pourrais\n"
	.string "acheter HARBOUR MAIL au POKéMON\p"
	.string "MART à SLATEPORT…$"

MauvilleCity_House2_Text_TradeHarborMailForCoinCase:
	.string "Oh! Vous avez HARBOUR MAIL ?\n"
	.string "L’échangerez-vous contre un COIN\p"
	.string "CASE ?$"

MauvilleCity_House2_Text_IllTradeYouCoinCase:
	.string "Oh, je suis si heureuse ! D'accord,\n"
	.string "je t'échange une BOÎTE À PIÈCES !$"

MauvilleCity_House2_Text_UseCoinCaseAtGameCorner:
	.string "Ce COIN CASE peut être utilisé au\n"
	.string "GAME CORNER.$"

MauvilleCity_House2_Text_ThatsDisappointing:
	.string "Oh, c'est décevant. Un COIN CASE\n"
	.string "est nécessaire pour le GAME\p"
	.string "CORNER.$"
