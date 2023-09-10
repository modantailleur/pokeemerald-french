Route110_TrickHousePuzzle8_MapScripts::
	.byte 0

Route110_TrickHousePuzzle8_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_8_STATE, 0, Route110_TrickHousePuzzle8_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle8_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_8_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle8_EventScript_Vincent::
	trainerbattle_single TRAINER_VINCENT, Route110_TrickHousePuzzle8_Text_VincentIntro, Route110_TrickHousePuzzle8_Text_VincentDefeat
	msgbox Route110_TrickHousePuzzle8_Text_VincentPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Keira::
	trainerbattle_single TRAINER_KEIRA, Route110_TrickHousePuzzle8_Text_KeiraIntro, Route110_TrickHousePuzzle8_Text_KeiraDefeat
	msgbox Route110_TrickHousePuzzle8_Text_KeiraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_EventScript_Leroy::
	trainerbattle_single TRAINER_LEROY, Route110_TrickHousePuzzle8_Text_LeroyIntro, Route110_TrickHousePuzzle8_Text_LeroyDefeat
	msgbox Route110_TrickHousePuzzle8_Text_LeroyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle8_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} a noté le code secret sur la\n"
	.string "porte. “ TRICK MASTER, j'adore. ” …\p"
	.string "… … … … … … … La serrure s'est\n"
	.string "ouverte !$"

Route110_TrickHousePuzzle8_Text_VincentIntro:
	.string "Peu de FORMATTHIEUEURS sont arrivés\n"
	.string "jusqu’ici.$"

Route110_TrickHousePuzzle8_Text_VincentDefeat:
	.string "Cela doit vouloir dire que tu es\n"
	.string "dur aussi…$"

Route110_TrickHousePuzzle8_Text_VincentPostBattle:
	.string "Vous avez battu le CHAMPION DE LA\n"
	.string "LIGUE POKéMON ? C'est trop !$"

Route110_TrickHousePuzzle8_Text_KeiraIntro:
	.string "Considérez-vous chanceux de me\n"
	.string "battre !$"

Route110_TrickHousePuzzle8_Text_KeiraDefeat:
	.string "Ce n'est pas bien ! Je ne peux pas\n"
	.string "perdre !$"

Route110_TrickHousePuzzle8_Text_KeiraPostBattle:
	.string "C'est un miracle que tu m'aies\n"
	.string "battu. Vous pouvez vous en vanter.$"

Route110_TrickHousePuzzle8_Text_LeroyIntro:
	.string "Vous avez également relevé le défi\n"
	.string "TRICK HOUSE.$"

Route110_TrickHousePuzzle8_Text_LeroyDefeat:
	.string "Je vois… Vous possédez un style\n"
	.string "extraordinaire.$"

Route110_TrickHousePuzzle8_Text_LeroyPostBattle:
	.string "Voir quelqu'un comme vous devrait\n"
	.string "plaire au TRICK MASTER.$"
