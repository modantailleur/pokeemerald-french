MagmaHideout_2F_1R_MapScripts::
	.byte 0

MagmaHideout_2F_1R_EventScript_Grunt14::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_14, MagmaHideout_2F_1R_Text_Grunt14Intro, MagmaHideout_2F_1R_Text_Grunt14Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt14PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_3, MagmaHideout_2F_1R_Text_Grunt3Intro, MagmaHideout_2F_1R_Text_Grunt3Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_4, MagmaHideout_2F_1R_Text_Grunt4Intro, MagmaHideout_2F_1R_Text_Grunt4Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_5, MagmaHideout_2F_1R_Text_Grunt5Intro, MagmaHideout_2F_1R_Text_Grunt5Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_Text_Grunt14Intro:
	.string "Quoi quoi quoi? Seuls les membres\n"
	.string "de la TEAM MAGMA sont censés être\p"
	.string "ici ! Mais vous n'êtes pas habillé\n"
	.string "avec l'uniforme de la TEAM MAGMA…\p"
	.string "Vous éveillez mes soupçons !\n"
	.string "Battez-vous avec moi !$"

MagmaHideout_2F_1R_Text_Grunt14Defeat:
	.string "Aiyiyi… Ma fierté en tant que\n"
	.string "membre de la TEAM MAGMA…$"

MagmaHideout_2F_1R_Text_Grunt14PostBattle:
	.string "Si vous souffrez de frissons, vous\n"
	.string "devriez rejoindre la TEAM MAGMA.$"

MagmaHideout_2F_1R_Text_Grunt3Intro:
	.string "Tenez-le là ! Tu ne t'attends pas\n"
	.string "vraiment à ce que je ferme mon\p"
	.string "piège et te laisse valser à côté de\n"
	.string "moi ?$"

MagmaHideout_2F_1R_Text_Grunt3Defeat:
	.string "Ouah wow ! Je l'admets !$"

MagmaHideout_2F_1R_Text_Grunt3PostBattle:
	.string "Peut-être que ça aurait été mieux\n"
	.string "si je te laissais partir sans\p"
	.string "contestation…$"

MagmaHideout_2F_1R_Text_Grunt4Intro:
	.string "Ah ! Un intrus !$"

MagmaHideout_2F_1R_Text_Grunt4Defeat:
	.string "Client!$"

MagmaHideout_2F_1R_Text_Grunt4PostBattle:
	.string "J'ai déjà perdu. Dois-je vraiment\n"
	.string "continuer à courir en rond ?$"

MagmaHideout_2F_1R_Text_Grunt5Intro:
	.string "Oh, oh ! Un intrus !$"

MagmaHideout_2F_1R_Text_Grunt5Defeat:
	.string "Mère…$"

MagmaHideout_2F_1R_Text_Grunt5PostBattle:
	.string "En fait, je ne suis pas un expert\n"
	.string "en matière de combat…$"
