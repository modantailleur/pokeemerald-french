MagmaHideout_2F_2R_MapScripts::
	.byte 0

MagmaHideout_2F_2R_EventScript_Grunt15::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_15, MagmaHideout_2F_2R_Text_Grunt15Intro, MagmaHideout_2F_2R_Text_Grunt15Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt15PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_6, MagmaHideout_2F_2R_Text_Grunt6Intro, MagmaHideout_2F_2R_Text_Grunt6Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_7, MagmaHideout_2F_2R_Text_Grunt7Intro, MagmaHideout_2F_2R_Text_Grunt7Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt7PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_8, MagmaHideout_2F_2R_Text_Grunt8Intro, MagmaHideout_2F_2R_Text_Grunt8Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_Text_Grunt15Intro:
	.string "Je n'ai rien à régler avec toi. Je\n"
	.string "ne fais que suivre les commandes !$"

MagmaHideout_2F_2R_Text_Grunt15Defeat:
	.string "J'ai peut-être perdu, mais…$"

MagmaHideout_2F_2R_Text_Grunt15PostBattle:
	.string "Nous avons déterré quelque chose\n"
	.string "au-delà de toute croyance ! Et nous\p"
	.string "avons obtenu l'ORBE BLEU ! Il ne\n"
	.string "reste plus qu'à notre chef de…\p"
	.string "Fufufu… Fwahahaha !$"

MagmaHideout_2F_2R_Text_Grunt6Intro:
	.string "Je ne supporte pas la chaleur.\n"
	.string "J'aurais peut-être dû rejoindre\p"
	.string "TEAM AQUA à la place…$"

MagmaHideout_2F_2R_Text_Grunt6Defeat:
	.string "Ouais, je n'ai peut-être vraiment\n"
	.string "pas raison pour TEAM MAGMA…$"

MagmaHideout_2F_2R_Text_Grunt6PostBattle:
	.string "Ne vous sentez-vous pas seul à\n"
	.string "cause de la mer dans un endroit\p"
	.string "comme celui-ci ?$"

MagmaHideout_2F_2R_Text_Grunt7Intro:
	.string "On entend parfois des tremblements\n"
	.string "ici. Serait-ce le volcan qui\p"
	.string "tremble ? Ou est-ce GROU… Oups !\n"
	.string "Non, non, peu importe !$"

MagmaHideout_2F_2R_Text_Grunt7Defeat:
	.string "Vous êtes un combattant fougueux.\n"
	.string "Comme un volcan !$"

MagmaHideout_2F_2R_Text_Grunt7PostBattle:
	.string "Cette fois, vous venez de gagner,\n"
	.string "mais cela n'a pas d'importance.\p"
	.string "L'objectif de la TEAM MAGMA est sur\n"
	.string "le point d'être atteint !$"

MagmaHideout_2F_2R_Text_Grunt8Intro:
	.string "Un de nos gars paniquait à l'idée\n"
	.string "d'avoir perdu son EMBLÈME MAGMA…\p"
	.string "Attendez une minute ! C'est toi qui\n"
	.string "l'as trouvé ?$"

MagmaHideout_2F_2R_Text_Grunt8Defeat:
	.string "J'ai du mal à y croire…$"

MagmaHideout_2F_2R_Text_Grunt8PostBattle:
	.string "J'ai le sentiment que notre plan va\n"
	.string "se terminer par un échec…$"
