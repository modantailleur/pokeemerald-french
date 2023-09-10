AbandonedShip_Corridors_1F_MapScripts::
	.byte 0

AbandonedShip_Corridors_1F_EventScript_Youngster::
	msgbox AbandonedShip_Corridors_1F_Text_IsntItFunHere, MSGBOX_NPC
	end

AbandonedShip_Corridors_1F_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE, AbandonedShip_Corridors_1F_Text_CharlieIntro, AbandonedShip_Corridors_1F_Text_CharlieDefeat
	msgbox AbandonedShip_Corridors_1F_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_1F_Text_CharlieIntro:
	.string "Qu'y a-t-il de si drôle à avoir ma\n"
	.string "chambre à air à bord du navire ?$"

AbandonedShip_Corridors_1F_Text_CharlieDefeat:
	.string "Whoa, tu m'as bouleversé !$"

AbandonedShip_Corridors_1F_Text_CharliePostBattle:
	.string "Pas facile de lancer des POKé BALLS\n"
	.string "en s'accrochant à une chambre à air\p"
	.string "!$"

AbandonedShip_Corridors_1F_Text_IsntItFunHere:
	.string "N'est-ce pas amusant ici ? Je suis\n"
	.string "excité juste d'être ici !$"
