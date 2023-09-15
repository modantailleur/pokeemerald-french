SlateportCity_House_MapScripts::
	.byte 0

SlateportCity_House_EventScript_PokefanM::
	msgbox SlateportCity_House_Text_NatureToDoWithStatGains, MSGBOX_NPC
	end

SlateportCity_House_EventScript_Girl::
	msgbox SlateportCity_House_Text_MustBeGoingToBattleTent, MSGBOX_NPC
	end

SlateportCity_House_Text_NatureToDoWithStatGains:
	.string "Mon POKéMON est de nature HASTY. Il\n"
	.string "a une VITESSE plus élevée que mon\p"
	.string "autre POKéMON. Peut-être que leur\n"
	.string "nature a quelque chose à voir avec\p"
	.string "les gains de statistiques de\n"
	.string "POKéMON.$"

SlateportCity_House_Text_MustBeGoingToBattleTent:
	.string "Vous êtes un DRESSEUR,\n"
	.string "n'est-ce pas ? Depuis que vous êtes\p"
	.string "arrivé à POIVRESSEL, vous devez\n"
	.string "vous rendre à la TENTE DE COMBAT.$"
