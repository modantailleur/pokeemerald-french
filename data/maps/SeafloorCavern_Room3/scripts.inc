SeafloorCavern_Room3_MapScripts::
	.byte 0

SeafloorCavern_Room3_EventScript_Shelly::
	trainerbattle_single TRAINER_SHELLY_SEAFLOOR_CAVERN, SeafloorCavern_Room3_Text_ShellyIntro, SeafloorCavern_Room3_Text_ShellyDefeat
	msgbox SeafloorCavern_Room3_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_SEAFLOOR_CAVERN_5, SeafloorCavern_Room3_Text_Grunt5Intro, SeafloorCavern_Room3_Text_Grunt5Defeat
	msgbox SeafloorCavern_Room3_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_Text_ShellyIntro:
	.string "Ahahahaha ! Comment avez-vous fait\n"
	.string "pour arriver ici sans sous-marin ?\p"
	.string "Quel enfant impressionnant ! Mais…\n"
	.string "Il ne faut pas que vous vous mêliez\p"
	.string "d'ici. Et je veux vraiment me\n"
	.string "venger de ce qui s'est passé au\p"
	.string "WEATHER INSTITUTE… Je vais vous\n"
	.string "donner un petit avant-goût de la\p"
	.string "douleur ! Résignez-vous!$"

SeafloorCavern_Room3_Text_ShellyDefeat:
	.string "Hahahahaha ! Aïe !$"

SeafloorCavern_Room3_Text_ShellyPostBattle:
	.string "Ahahahaha ! Tu es tellement fort.\n"
	.string "C'est terriblement décevant que\p"
	.string "vous ne soyez pas membre de la TEAM\n"
	.string "AQUA. Vous auriez pu profiter du\p"
	.string "monde fabuleux que notre BOSS a\n"
	.string "promis en tant qu'un des nôtres…$"

SeafloorCavern_Room3_Text_Grunt5Intro:
	.string "Pour que notre rêve devienne\n"
	.string "réalité, nous avons besoin du\p"
	.string "pouvoir de POKéMON. Mais les intrus\n"
	.string "comme vous utilisent le pouvoir de\p"
	.string "POKéMON pour nous embêter, même\n"
	.string "dans un endroit comme celui-ci ! La\p"
	.string "vie ne fonctionne tout simplement\n"
	.string "pas comme nous en avons besoin !$"

SeafloorCavern_Room3_Text_Grunt5Defeat:
	.string "Témoin!$"

SeafloorCavern_Room3_Text_Grunt5PostBattle:
	.string "Vous savez, nous n'osons pas\n"
	.string "remettre en question les\p"
	.string "motivations de notre chef. Mais\n"
	.string "vous voilà, juste un punk,\p"
	.string "affrontant notre BOSS. Peut-être…\n"
	.string "Tu dois être quelque chose…$"
