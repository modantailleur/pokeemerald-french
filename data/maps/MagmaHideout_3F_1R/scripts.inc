MagmaHideout_3F_1R_MapScripts::
	.byte 0

MagmaHideout_3F_1R_EventScript_Grunt9::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_9, MagmaHideout_3F_1R_Text_Grunt9Intro, MagmaHideout_3F_1R_Text_Grunt9Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt9PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_EventScript_Grunt16::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_16, MagmaHideout_3F_1R_Text_Grunt16Intro, MagmaHideout_3F_1R_Text_Grunt16Defeat
	msgbox MagmaHideout_3F_1R_Text_Grunt16PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_1R_Text_Grunt9Intro:
	.string "Qu'ai-je fait pour mériter ce poste\n"
	.string "de garde ? Mon oreille gauche me\p"
	.string "brûle !$"

MagmaHideout_3F_1R_Text_Grunt9Defeat:
	.string "Je souffre d'épuisement dû à la\n"
	.string "chaleur…$"

MagmaHideout_3F_1R_Text_Grunt9PostBattle:
	.string "Pensez-vous que c'est étrange que\n"
	.string "nous portions des cagoules dans ce\p"
	.string "volcan rempli de magma ?$"

MagmaHideout_3F_1R_Text_Grunt16Intro:
	.string "Nous nous sommes joints pour\n"
	.string "pouvoir aider notre leader à\p"
	.string "réaliser sa vision fantastique. Je\n"
	.string "m'en fiche si vous faites partie de\p"
	.string "la TEAM AQUA ou si vous êtes juste\n"
	.string "un enfant de passage. Personne ne\p"
	.string "nous dérange et ne s'en sort pas !$"

MagmaHideout_3F_1R_Text_Grunt16Defeat:
	.string "Oh non! On ne peut pas du tout vous\n"
	.string "faire confiance !$"

MagmaHideout_3F_1R_Text_Grunt16PostBattle:
	.string "Écoutez-moi. L'ÉQUIPE MAGMA a\n"
	.string "raison ! N'écoutez pas TEAM AQUA.\p"
	.string "Ne croyez pas leurs mensonges !$"
