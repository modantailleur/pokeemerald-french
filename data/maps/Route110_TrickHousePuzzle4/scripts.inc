Route110_TrickHousePuzzle4_MapScripts::
	.byte 0

Route110_TrickHousePuzzle4_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0, Route110_TrickHousePuzzle4_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle4_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle4_EventScript_Cora::
	trainerbattle_single TRAINER_CORA, Route110_TrickHousePuzzle4_Text_CoraIntro, Route110_TrickHousePuzzle4_Text_CoraDefeat
	msgbox Route110_TrickHousePuzzle4_Text_CoraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Yuji::
	trainerbattle_single TRAINER_YUJI, Route110_TrickHousePuzzle4_Text_YujiIntro, Route110_TrickHousePuzzle4_Text_YujiDefeat
	msgbox Route110_TrickHousePuzzle4_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA, Route110_TrickHousePuzzle4_Text_PaulaIntro, Route110_TrickHousePuzzle4_Text_PaulaDefeat
	msgbox Route110_TrickHousePuzzle4_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} a noté le code secret sur la\n"
	.string "porte. “TRICK MASTER est cool.“ … …\p"
	.string "… … … … … … La serrure s'est\n"
	.string "ouverte !$"

Route110_TrickHousePuzzle4_Text_CoraIntro:
	.string "C'est trop compliqué d'y penser. Je\n"
	.string "voulais seulement me battre !$"

Route110_TrickHousePuzzle4_Text_CoraDefeat:
	.string "Même si j'ai perdu, j'aime toujours\n"
	.string "me battre contre les meilleurs !$"

Route110_TrickHousePuzzle4_Text_CoraPostBattle:
	.string "N'êtes-vous pas d'accord ? Vous\n"
	.string "iriez n'importe où si les\p"
	.string "FORMATTHIEUEURS étaient là.$"

Route110_TrickHousePuzzle4_Text_YujiIntro:
	.string "Il h! Des rochers comme celui-ci,\n"
	.string "je peux les écarter avec un seul\p"
	.string "doigt !$"

Route110_TrickHousePuzzle4_Text_YujiDefeat:
	.string "Je peux pousser des rochers, mais\n"
	.string "je ne peux pas résoudre le puzzle…$"

Route110_TrickHousePuzzle4_Text_YujiPostBattle:
	.string "Il ne suffit pas d'être musclé… Il\n"
	.string "faut utiliser sa tête. Soyez\p"
	.string "intelligent !$"

Route110_TrickHousePuzzle4_Text_PaulaIntro:
	.string "La TRICK HOUSE devient de plus en\n"
	.string "plus délicate, n'est-ce pas ?$"

Route110_TrickHousePuzzle4_Text_PaulaDefeat:
	.string "Désobéissant !$"

Route110_TrickHousePuzzle4_Text_PaulaPostBattle:
	.string "Quelqu'un est-il arrivé jusqu'au\n"
	.string "bout ?$"
