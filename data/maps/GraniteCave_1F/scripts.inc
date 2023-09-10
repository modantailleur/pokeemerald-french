GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.string "Hey vous. Il fait terriblement\n"
	.string "sombre devant nous. Ce sera\p"
	.string "difficile d'essayer d'explorer. Ce\n"
	.string "type qui est venu plus tôt… PIERRE,\p"
	.string "je pense que oui. Il savait\n"
	.string "utiliser FLASH, donc ça devrait\p"
	.string "aller, mais… Bon, pour nous\n"
	.string "RANDONNEURS, aider ceux que nous\p"
	.string "rencontrons est notre devise.\n"
	.string "Voilà, je vous transmets ça.$"

GraniteCave_1F_Text_ExplainFlash:
	.string "Apprenez ce mouvement caché FLASH à\n"
	.string "un POKéMON et utilisez-le. Il\p"
	.string "illumine même l’obscurité des\n"
	.string "grottes. Mais pour l'utiliser, vous\p"
	.string "avez besoin du GYM BADGE du POKéMON\n"
	.string "GYM de DEWFORD.$"
