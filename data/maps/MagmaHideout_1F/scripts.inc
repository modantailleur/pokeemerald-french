MagmaHideout_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MagmaHideout_1F_OnTransition
	.byte 0

MagmaHideout_1F_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	end

MagmaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_1, MagmaHideout_1F_Text_Grunt1Intro, MagmaHideout_1F_Text_Grunt1Defeat
	msgbox MagmaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_2, MagmaHideout_1F_Text_Grunt2Intro, MagmaHideout_1F_Text_Grunt2Defeat
	msgbox MagmaHideout_1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_Text_Grunt1Intro:
	.string "Lorsque l'ÉQUIPE MAGMA fait un\n"
	.string "appel nominal, nous recevons des\p"
	.string "missions de garde importantes dans\n"
	.string "l'ordre dans lequel nous nous\p"
	.string "alignons. C'est pour ça que je suis\n"
	.string "coincé dans ce coin. Je suis\p"
	.string "toujours en retard à l'appel !$"

MagmaHideout_1F_Text_Grunt1Defeat:
	.string "Moi aussi, je suis toujours en\n"
	.string "retard aux entraînements ! Je\p"
	.string "déteste le dire, mais je suis nul…$"

MagmaHideout_1F_Text_Grunt1PostBattle:
	.string "D'accord, je vais essayer de faire\n"
	.string "un peu plus d'efforts à partir de\p"
	.string "maintenant…$"

MagmaHideout_1F_Text_Grunt2Intro:
	.string "Notre chef nous a dit de creuser\n"
	.string "dans MONT CHIMNEE, alors nous avons\p"
	.string "creusé et creusé. Et en creusant,\n"
	.string "nous sommes tombés sur quelque\p"
	.string "chose qui nous a époustouflé !\n"
	.string "Qu'avons-nous trouvé ? Fuhahaha !\p"
	.string "Je te le dirai si tu me bats !$"

MagmaHideout_1F_Text_Grunt2Defeat:
	.string "Arrgh! Démonté !$"

MagmaHideout_1F_Text_Grunt2PostBattle:
	.string "Je ne vous le dirai pas après tout.\n"
	.string "Vous le saurez en arrivant sur\p"
	.string "place ! Ce serait mieux si tu\n"
	.string "gardais les surprises jusqu'à la\p"
	.string "fin, tu ne penses pas ?$"
