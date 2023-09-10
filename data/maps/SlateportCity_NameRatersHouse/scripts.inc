SlateportCity_NameRatersHouse_MapScripts::
	.byte 0

SlateportCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox SlateportCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, SlateportCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	msgbox SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, SlateportCity_NameRatersHouse_EventScript_DeclineNameRate
	end

SlateportCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox SlateportCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_ChangeNickname::
	msgbox SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, SlateportCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_EventScript_NewNameDifferent::
	msgbox SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

SlateportCity_NameRatersHouse_Text_PleasedToRateMonNickname:
	.string "Salut, salut ! Je suis l'ÉVALUATEUR\n"
	.string "DE NOM ! Je suis la voyante des\p"
	.string "noms ! Je serai ravi d'évaluer le\n"
	.string "surnom de votre POKéMON.$"

SlateportCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
	.string "Quel surnom de POKéMON dois-je\n"
	.string "critiquer ?$"

SlateportCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
	.string "Hmmm… {STR_VAR_1}, n'est-ce pas ? C'est\n"
	.string "un très beau nom que vous avez\p"
	.string "donné. Mais! Que diriez-vous si je\n"
	.string "devais vous suggérer un nom\p"
	.string "légèrement meilleur ?$"

SlateportCity_NameRatersHouse_Text_WhatShallNewNameBe:
	.string "Ah bien. Alors, quel sera le\n"
	.string "nouveau surnom ?$"

SlateportCity_NameRatersHouse_Text_MonShallBeKnownAsName:
	.string "Fait! Désormais, ce POKéMON sera\n"
	.string "connu sous le nom de {STR_VAR_1} ! C'est\p"
	.string "un meilleur nom qu'avant ! Quelle\n"
	.string "chance pour toi !$"

SlateportCity_NameRatersHouse_Text_DoVisitAgain:
	.string "Je vois. Revenez visiter.$"

SlateportCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
	.string "Fait! Désormais, ce POKéMON sera\n"
	.string "connu sous le nom de {STR_VAR_1} ! Cela\p"
	.string "n’a pas l’air différent d’avant, et\n"
	.string "pourtant, c’est largement supérieur\p"
	.string "! Quelle chance pour toi !$"

SlateportCity_NameRatersHouse_Text_MagnificentName:
	.string "Hmmm… {STR_VAR_1} c'est vrai ! C'est un\n"
	.string "surnom magnifique ! C'est\p"
	.string "impeccablement irréprochable ! Vous\n"
	.string "ferez bien de chérir votre {STR_VAR_1}\p"
	.string "maintenant et au-delà.$"

SlateportCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string "Maintenant maintenant. Ce n'est\n"
	.string "qu'un OEUF !$"
