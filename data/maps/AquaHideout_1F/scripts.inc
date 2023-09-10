AquaHideout_1F_MapScripts::
	.byte 0

@ The below two entrance guards give hints about what to do to progress the story
AquaHideout_1F_EventScript_HideoutEntranceGrunt1::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint1
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint1
	msgbox AquaHideout_1F_Text_OurBossIsSnatchingSomething, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint1::
	msgbox AquaHideout_1F_Text_WhereMightMagmaHideoutBe, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint1::
	msgbox AquaHideout_1F_Text_BossWentToJackASubmarine, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_HideoutEntranceGrunt2::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint2
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint2
	msgbox AquaHideout_1F_Text_BossIsOnRoute122, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint2::
	msgbox AquaHideout_1F_Text_TeamMagmaAtMtChimney, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint2::
	msgbox AquaHideout_1F_Text_BossIsInSlateportCity, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_1, AquaHideout_1F_Text_Grunt1Intro, AquaHideout_1F_Text_Grunt1Defeat, AquaHideout_1F_EventScript_Grunt1Defeated
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_1F_EventScript_Grunt1Defeated::
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_Text_OurBossIsSnatchingSomething:
	.string "Quoi? Quoi? Que voulez-vous avec\n"
	.string "TEAM AQUA ? Notre BOSS n'est pas là\p"
	.string "! Il est parti récupérer quelque\n"
	.string "chose d'important ! … … Où est-il\p"
	.string "allé? Wahaha ! Pensez-vous vraiment\n"
	.string "que je vous dirais quelque chose\p"
	.string "d'aussi crucial ?$"

AquaHideout_1F_Text_WhereMightMagmaHideoutBe:
	.string "Quoi? Quoi? Êtes-vous un grognement\n"
	.string "de la TEAM MAGMA ? J'ai entendu\p"
	.string "dire que l'ÉQUIPE MAGMA essaie de\n"
	.string "réveiller un POKéMON génial dans sa\p"
	.string "CACHE. Mais où pourrait être leur\n"
	.string "CACHE ?$"

AquaHideout_1F_Text_BossWentToJackASubmarine:
	.string "Quoi? Quoi? Que voulez-vous avec\n"
	.string "TEAM AQUA ? Notre BOSS n'est pas là\p"
	.string "! Il est parti pirater un\n"
	.string "sous-marin ! … … Où est-il allé?\p"
	.string "Wahaha ! Pensez-vous vraiment que\n"
	.string "je vous dirais quelque chose\p"
	.string "d'aussi crucial ?$"

AquaHideout_1F_Text_BossIsOnRoute122:
	.string "Quoi? Quoi? Que voulez-vous avec\n"
	.string "TEAM AQUA ? Notre BOSS n'est pas là\p"
	.string "! Il est en route pour MT. PYRE sur\n"
	.string "la ROUTE 122! … … Pourquoi est-il\p"
	.string "parti ? Wahaha ! Pensez-vous\n"
	.string "vraiment que je vous dirais quelque\p"
	.string "chose d'aussi crucial ?$"

AquaHideout_1F_Text_TeamMagmaAtMtChimney:
	.string "Quoi? Quoi? Êtes-vous un grognement\n"
	.string "de la TEAM MAGMA ? J'ai entendu\p"
	.string "dire que TEAM MAGMA recherche un\n"
	.string "POKéMON génial à MONT CHIMNEE. Mais\p"
	.string "à quoi ressemble ce POKéMON ?$"

AquaHideout_1F_Text_BossIsInSlateportCity:
	.string "Quoi? Quoi? Que voulez-vous avec\n"
	.string "TEAM AQUA ? Notre BOSS n'est pas là\p"
	.string "! Il est en route pour POIVRESSEL !\n"
	.string "… … Pourquoi est-il parti ? Wahaha\p"
	.string "! Pensez-vous vraiment que je vous\n"
	.string "dirais quelque chose d'aussi\p"
	.string "crucial ?$"

AquaHideout_1F_Text_Grunt1Intro:
	.string "Ayiyiyi! Personnage suspect repéré\n"
	.string "!$"

AquaHideout_1F_Text_Grunt1Defeat:
	.string "Grrrrr… je l'ai perdu !$"

AquaHideout_1F_Text_Grunt1PostBattle:
	.string "J'ai pris la défaite pour l'ÉQUIPE,\n"
	.string "mais j'ai fait mon travail…$"
