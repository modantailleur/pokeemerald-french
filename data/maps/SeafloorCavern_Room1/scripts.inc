SeafloorCavern_Room1_MapScripts::
	.byte 0

SeafloorCavern_Room1_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_1, SeafloorCavern_Room1_Text_Grunt1Intro, SeafloorCavern_Room1_Text_Grunt1Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_2, SeafloorCavern_Room1_Text_Grunt2Intro, SeafloorCavern_Room1_Text_Grunt2Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_Text_Grunt1Intro:
	.string "Nous n'avons pas besoin d'un enfant\n"
	.string "dans les parages ! Rentrez déjà\p"
	.string "chez vous !$"

SeafloorCavern_Room1_Text_Grunt1Defeat:
	.string "Je veux rentrer à la maison…$"

SeafloorCavern_Room1_Text_Grunt1PostBattle:
	.string "Je veux obtenir une promotion pour\n"
	.string "pouvoir diriger les GRUNTS…$"

SeafloorCavern_Room1_Text_Grunt2Intro:
	.string "Ce sous-marin… Il est minuscule à\n"
	.string "l'intérieur. J'ai mal partout !$"

SeafloorCavern_Room1_Text_Grunt2Defeat:
	.string "Perdre me fait mal !$"

SeafloorCavern_Room1_Text_Grunt2PostBattle:
	.string "Ce sous-marin qu'on a détourné,\n"
	.string "mec, c'est brutal comme un voyage.\p"
	.string "C'est beaucoup trop serré là-dedans\n"
	.string "!$"
