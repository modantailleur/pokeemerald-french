SeafloorCavern_Room4_MapScripts::
	.byte 0

SeafloorCavern_Room4_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_3, SeafloorCavern_Room4_Text_Grunt3Intro, SeafloorCavern_Room4_Text_Grunt3Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_4, SeafloorCavern_Room4_Text_Grunt4Intro, SeafloorCavern_Room4_Text_Grunt4Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_Text_Grunt3Intro:
	.string "Qui es-tu? D'où viens-tu ?$"

SeafloorCavern_Room4_Text_Grunt3Defeat:
	.string "Je l'ai perdu…$"

SeafloorCavern_Room4_Text_Grunt3PostBattle:
	.string "Je ne trouve pas la sortie ! Je\n"
	.string "n'ai pas peur. Ne vous méprenez pas\p"
	.string "!$"

SeafloorCavern_Room4_Text_Grunt4Intro:
	.string "Qui es-tu? Où penses-tu aller ?$"

SeafloorCavern_Room4_Text_Grunt4Defeat:
	.string "Je n'ai pas réussi à gagner !$"

SeafloorCavern_Room4_Text_Grunt4PostBattle:
	.string "Mon partenaire a oublié la carte\n"
	.string "dans ce sous-marin ! Comment ça,\p"
	.string "c'est d'être inutile ?$"
