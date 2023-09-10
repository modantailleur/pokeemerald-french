DewfordTown_House2_MapScripts::
	.byte 0

DewfordTown_House2_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_ExplainSilkScarf
	msgbox DewfordTown_House2_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_House2_EventScript_NoRoomForScarf
	setflag FLAG_RECEIVED_SILK_SCARF
	release
	end

DewfordTown_House2_EventScript_NoRoomForScarf::
	msgbox DewfordTown_House2_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_ExplainSilkScarf::
	msgbox DewfordTown_House2_Text_ExplainSilkScarf, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_Boy::
	msgbox DewfordTown_House2_Text_BrawlySoCool, MSGBOX_NPC
	end

DewfordTown_House2_Text_WantYouToHaveSilkScarf:
	.string "Remplis-toi les yeux là-dessus !\n"
	.string "C'est un FOULARD EN SOIE. C'est à\p"
	.string "la pointe de la mode, ouais ! Oh,\n"
	.string "je vois tes yeux pétiller ! Vous\p"
	.string "appréciez mon style éblouissant !\n"
	.string "Oh, tu es un délice ! Voici. Je\p"
	.string "veux que tu l'aies !$"

DewfordTown_House2_Text_NoRoom:
	.string "Oh, tu n'as pas de place ?\n"
	.string "Maintenant, écoutez bien, cette\p"
	.string "ÉCHARPE est un incontournable ! Eh\n"
	.string "bien, je vendrais tous mes articles\p"
	.string "pour l'obtenir !$"

DewfordTown_House2_Text_ExplainSilkScarf:
	.string "Le SILK SCARF augmente la puissance\n"
	.string "des mouvements de type NORMAL.\p"
	.string "C'est une merveilleuse ÉCHARPE qui\n"
	.string "ira avec presque tous les POKéMON\p"
	.string "!$"

DewfordTown_House2_Text_BrawlySoCool:
	.string "Wow, vous avez pris la peine de\n"
	.string "traverser la mer pour visiter\p"
	.string "DEWFORD ? Êtes-vous peut-être venu\n"
	.string "ici parce que vous avez entendu\p"
	.string "parler de BASTIEN ? Il est\n"
	.string "tellement cool… Tout le monde\p"
	.string "l'idolâtre.$"
