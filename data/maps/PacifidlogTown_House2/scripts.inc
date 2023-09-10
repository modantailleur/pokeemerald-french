PacifidlogTown_House2_MapScripts::
	.byte 0

PacifidlogTown_House2_EventScript_FanClubYoungerBrother::
	lock
	faceplayer
	dotimebasedevents
	call PacifidlogTown_House2_EventScript_UpdateFanClubTMFlag
	goto_if_set FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK, PacifidlogTown_House2_EventScript_ComeBackInXDays
	call_if_set FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_MonAssessment
	call_if_unset FLAG_MET_FANCLUB_YOUNGER_BROTHER, PacifidlogTown_House2_EventScript_FirstMonAssessment
	setflag FLAG_MET_FANCLUB_YOUNGER_BROTHER
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, PacifidlogTown_House2_EventScript_GiveReturn
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_50_TO_99, PacifidlogTown_House2_EventScript_PutInEffort
	goto PacifidlogTown_House2_EventScript_GiveFrustration
	end

PacifidlogTown_House2_EventScript_UpdateFanClubTMFlag::
	goto_if_unset FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK, Common_EventScript_NopReturn
	specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable
	call_if_eq VAR_RESULT, 0, PacifidlogTown_House2_EventScript_ClearReceivedFanClubTM
	return

PacifidlogTown_House2_EventScript_MonAssessment::
	msgbox PacifidlogTown_House2_Text_AhYourPokemon, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_FirstMonAssessment::
	msgbox PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation, MSGBOX_DEFAULT
	msgbox PacifidlogTown_House2_Text_AhYourPokemon, MSGBOX_DEFAULT
	return

PacifidlogTown_House2_EventScript_ClearReceivedFanClubTM::
	clearflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	return

PacifidlogTown_House2_EventScript_GiveReturn::
	msgbox PacifidlogTown_House2_Text_AdoringPokemonTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_RETURN
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_PutInEffort::
	msgbox PacifidlogTown_House2_Text_PutInSomeMoreEffort, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_GiveFrustration::
	msgbox PacifidlogTown_House2_Text_ViciousPokemonTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_FRUSTRATION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FANCLUB_TM_THIS_WEEK
	special SetPacifidlogTMReceivedDay
	msgbox PacifidlogTown_House2_Text_ExplainReturnFrustration, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_ComeBackInXDays::
	specialvar VAR_RESULT, GetDaysUntilPacifidlogTMAvailable
	buffernumberstring STR_VAR_1, VAR_RESULT
	msgbox PacifidlogTown_House2_Text_GetGoodTMInXDays, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_HappyAzurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox PacifidlogTown_House2_Text_Rurii, MSGBOX_DEFAULT
	waitmoncry
	msgbox PacifidlogTown_House2_Text_VeryFriendlyWithTrainer, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_EventScript_UnhappyAzurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_ENCOUNTER
	msgbox PacifidlogTown_House2_Text_Rururi, MSGBOX_DEFAULT
	waitmoncry
	msgbox PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House2_Text_ChairmansYoungerBrotherOnVacation:
	.string "Euh-hem ! Je suis la personne la\n"
	.string "plus importante du POKéMON FAN\p"
	.string "CLUB, le frère cadet du PRÉSIDENT.\n"
	.string "Je suis ici pour profiter de mes\p"
	.string "vacances avec POKéMON, oui,\n"
	.string "effectivement.$"

PacifidlogTown_House2_Text_AhYourPokemon:
	.string "Ah ! Votre POKéMON…$"

PacifidlogTown_House2_Text_AdoringPokemonTakeThis:
	.string "Il est clair que vous lui plaisez\n"
	.string "beaucoup. Un POKéMON adorant et\p"
	.string "adorable mérite une MT comme\n"
	.string "celle-ci, non ?$"

PacifidlogTown_House2_Text_PutInSomeMoreEffort:
	.string "Hmm… Ce n'est pas mal, mais ce\n"
	.string "n'est pas bon non plus. En tant que\p"
	.string "FORMATTHIEUEUR, vous devez faire\n"
	.string "davantage d'efforts.$"

PacifidlogTown_House2_Text_ViciousPokemonTakeThis:
	.string "Il a un air vicieux. Un POKéMON\n"
	.string "effrayant comme celui-là mérite une\p"
	.string "MT comme celle-ci.$"

PacifidlogTown_House2_Text_ExplainReturnFrustration:
	.string "Si un POKéMON vous aime beaucoup,\n"
	.string "la puissance de RGUIDOOUR est\p"
	.string "renforcée. S'il ne vous aime pas,\n"
	.string "le pouvoir de FRUSTRATION\p"
	.string "augmente.$"

PacifidlogTown_House2_Text_GetGoodTMInXDays:
	.string "Oh oui. Dans environ {STR_VAR_1} jours\n"
	.string "environ, je devrais recevoir une ou\p"
	.string "deux bonnes MT. Tu devrais venir me\n"
	.string "voir alors. Je vais vous donner une\p"
	.string "MT adaptée à votre POKéMON.$"

PacifidlogTown_House2_Text_Rurii:
	.string "AZURILLE : Rurii.$"

PacifidlogTown_House2_Text_VeryFriendlyWithTrainer:
	.string "Il semble être très amical avec le\n"
	.string "FORMATTHIEUEUR.$"

PacifidlogTown_House2_Text_Rururi:
	.string "AZURILL : C’est vrai !$"

PacifidlogTown_House2_Text_DoesntLikeTrainerVeryMuch:
	.string "Il ne semble pas beaucoup aimer le\n"
	.string "DRESSEUR.$"
