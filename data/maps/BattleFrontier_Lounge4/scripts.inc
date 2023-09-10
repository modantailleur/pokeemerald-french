BattleFrontier_Lounge4_MapScripts::
	.byte 0

BattleFrontier_Lounge4_EventScript_Woman::
	msgbox BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Cook::
	msgbox BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Man::
	msgbox BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles, MSGBOX_NPC
	end

BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring:
	.string "Je me demande s'ils vont diffuser\n"
	.string "des interviews avec des\p"
	.string "FORMATTHIEUEURS coriaces\n"
	.string "aujourd'hui ?$"

BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere:
	.string "Si j'ouvrais un restaurant ici,\n"
	.string "cela rapporterait certainement de\p"
	.string "l'argent.$"

BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles:
	.string "Ouf… J'ai besoin de souffler un peu\n"
	.string "après des combats intenses… Mais\p"
	.string "même maintenant, je ne fais jamais\n"
	.string "de pause dans l'élaboration de\p"
	.string "stratégies et de combos.$"
