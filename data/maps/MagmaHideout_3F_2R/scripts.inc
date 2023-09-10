MagmaHideout_3F_2R_MapScripts::
	.byte 0

MagmaHideout_3F_2R_EventScript_Grunt10::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_10, MagmaHideout_3F_2R_Text_Grunt10Intro, MagmaHideout_3F_2R_Text_Grunt10Defeat
	msgbox MagmaHideout_3F_2R_Text_Grunt10PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_2R_Text_Grunt10Intro:
	.string "Je comprends tout ce que dit notre\n"
	.string "chef. Mais tu sais quoi? Faire des\p"
	.string "trucs comme déterrer un POKéMON\n"
	.string "super-ancien et arracher la\p"
	.string "MÉTÉORITE de quelqu'un… Je pense\n"
	.string "qu'on va un peu trop loin. Qu'en\p"
	.string "pensez-vous ?$"

MagmaHideout_3F_2R_Text_Grunt10Defeat:
	.string "Ouais, je pense que nous faisons\n"
	.string "quelque chose de mal d'une manière\p"
	.string "ou d'une autre.$"

MagmaHideout_3F_2R_Text_Grunt10PostBattle:
	.string "Tu sais, perdre contre toi m'a\n"
	.string "éclairci l'esprit. La prochaine\p"
	.string "fois que je verrai notre chef, je\n"
	.string "lui demanderai ce que nous\p"
	.string "faisons.$"
