FortreeCity_House2_MapScripts::
	.byte 0

FortreeCity_House2_EventScript_HiddenPowerGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_HIDDEN_POWER, FortreeCity_House2_EventScript_ExplainHiddenPower
	call_if_unset FLAG_MET_HIDDEN_POWER_GIVER, FortreeCity_House2_EventScript_Greeting
	msgbox FortreeCity_House2_Text_CoinInWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 1, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_CorrectTryAgainWhichHand2, MSGBOX_DEFAULT
	multichoice 21, 8, MULTI_RIGHTLEFT, TRUE
	switch VAR_RESULT
	case 0, FortreeCity_House2_EventScript_WrongGuess
	msgbox FortreeCity_House2_Text_YourHiddenPowerHasAwoken, MSGBOX_DEFAULT
	giveitem ITEM_TM_HIDDEN_POWER
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_HIDDEN_POWER
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_Greeting::
	msgbox FortreeCity_House2_Text_HiddenPowersArousedByNature, MSGBOX_DEFAULT
	setflag FLAG_MET_HIDDEN_POWER_GIVER
	return

FortreeCity_House2_EventScript_ExplainHiddenPower::
	msgbox FortreeCity_House2_Text_ExplainHiddenPower, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_EventScript_WrongGuess::
	msgbox FortreeCity_House2_Text_YouGuessedWrong, MSGBOX_DEFAULT
	release
	end

FortreeCity_House2_Text_HiddenPowersArousedByNature:
	.string "Les gens… POKéMON… Leurs pouvoirs\n"
	.string "cachés sont éveillés par le fait de\p"
	.string "vivre dans des environnements\n"
	.string "naturels…$"

FortreeCity_House2_Text_CoinInWhichHand:
	.string "Laisse cette vieille femme voir si\n"
	.string "ton pouvoir caché s’est réveillé…\p"
	.string "Je tiens une pièce de monnaie dans\n"
	.string "ma main. Maintenant, dis-moi,\p"
	.string "est-ce que je l'ai mis dans la main\n"
	.string "droite ? Ou à gauche ?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand:
	.string "Oh! Oui correct! Nous allons\n"
	.string "réessayer. Dans quelle main ai-je\p"
	.string "saisi la pièce ? La droite ou la\n"
	.string "gauche ?$"

FortreeCity_House2_Text_CorrectTryAgainWhichHand2:
	.string "Oh! Oui correct! Nous allons\n"
	.string "réessayer. Dans quelle main ai-je\p"
	.string "saisi la pièce ? La droite ou la\n"
	.string "gauche ?$"

FortreeCity_House2_Text_YourHiddenPowerHasAwoken:
	.string "Oh! Splendide! Votre pouvoir caché\n"
	.string "s'est réveillé ! Tiens, prends ceci\p"
	.string "et réveille le pouvoir caché de ton\n"
	.string "POKéMON.$"

FortreeCity_House2_Text_ExplainHiddenPower:
	.string "HIDDEN POWER est une capacité qui\n"
	.string "change avec le POKéMON.$"

FortreeCity_House2_Text_YouGuessedWrong:
	.string "Pas si mal. Vous avez mal deviné.$"
