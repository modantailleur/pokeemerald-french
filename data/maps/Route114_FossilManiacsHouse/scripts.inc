Route114_FossilManiacsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsHouse_OnTransition
	.byte 0

Route114_FossilManiacsHouse_OnTransition:
	setflag FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE
	end

Route114_FossilManiacsHouse_EventScript_FossilManiacsBrother::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_DIG, Route114_FossilManiacsHouse_EventScript_ReceivedDig
	msgbox Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother, MSGBOX_DEFAULT
	giveitem ITEM_TM_DIG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_DIG
	release
	end

Route114_FossilManiacsHouse_EventScript_ReceivedDig::
	msgbox Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsHouse_EventScript_RockDisplay::
	msgbox Route114_FossilManiacsHouse_Text_RocksFillDisplayCase, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_EventScript_Bookshelf::
	msgbox Route114_FossilManiacsHouse_Text_CrammedWithBooks, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother:
	.string "Mon grand frère est le FOSSIL\n"
	.string "MANIAC… C'est un gars sympa qui\p"
	.string "adore les FOSSILES… Il adore aussi\n"
	.string "creuser des trous… Il a creusé ce\p"
	.string "trou tout seul… Vous pouvez avoir\n"
	.string "ça, pour pouvoir CREUSER des trous\p"
	.string "comme mon grand frère…$"

Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance:
	.string "Si vous faites un POKéMON DIG à\n"
	.string "l'intérieur d'une grotte, vous\p"
	.string "revenez à l'entrée…$"

Route114_FossilManiacsHouse_Text_RocksFillDisplayCase:
	.string "Des roches aux formes particulières\n"
	.string "remplissent la vitrine…$"

Route114_FossilManiacsHouse_Text_CrammedWithBooks:
	.string "LA COMPOSITION DES STRATES… COMMENT\n"
	.string "LA PLUIE FAÇONNE LA TERRE… LES\p"
	.string "PIERRES, LE SOL GUIDO LA ROCHE…\n"
	.string "C'est rempli de livres.$"
