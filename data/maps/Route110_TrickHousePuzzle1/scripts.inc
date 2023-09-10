Route110_TrickHousePuzzle1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route110_TrickHousePuzzle1_OnLoad
	.byte 0

Route110_TrickHousePuzzle1_OnLoad:
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2, Route110_TrickHousePuzzle1_EventScript_OpenDoor
	end

Route110_TrickHousePuzzle1_EventScript_OpenDoor::
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	end

Route110_TrickHousePuzzle1_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0, Route110_TrickHousePuzzle1_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle1_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle1_EventScript_Sally::
	trainerbattle_single TRAINER_SALLY, Route110_TrickHousePuzzle1_Text_SallyIntro, Route110_TrickHousePuzzle1_Text_SallyDefeat
	msgbox Route110_TrickHousePuzzle1_Text_SallyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Eddie::
	trainerbattle_single TRAINER_EDDIE, Route110_TrickHousePuzzle1_Text_EddieIntro, Route110_TrickHousePuzzle1_Text_EddieDefeat
	msgbox Route110_TrickHousePuzzle1_Text_EddiePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Robin::
	trainerbattle_single TRAINER_ROBIN, Route110_TrickHousePuzzle1_Text_RobinIntro, Route110_TrickHousePuzzle1_Text_RobinDefeat
	msgbox Route110_TrickHousePuzzle1_Text_RobinPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} a noté le code secret sur la\n"
	.string "porte. “ TRICK MASTER est fabuleux.\p"
	.string "” … … … … … … … … La serrure s'est\n"
	.string "ouverte !$"

Route110_TrickHousePuzzle1_Text_SallyIntro:
	.string "Je vais me frayer un chemin vers la\n"
	.string "victoire avec le CUT que nous\p"
	.string "venons d'apprendre !$"

Route110_TrickHousePuzzle1_Text_SallyDefeat:
	.string "Pourquoi es-tu si sérieux ?$"

Route110_TrickHousePuzzle1_Text_SallyPostBattle:
	.string "Je ne me lasse jamais de pirater et\n"
	.string "de couper !$"

Route110_TrickHousePuzzle1_Text_EddieIntro:
	.string "Je suis entré dans cette maison\n"
	.string "étrange par accident…$"

Route110_TrickHousePuzzle1_Text_EddieDefeat:
	.string "Et maintenant j'ai perdu…$"

Route110_TrickHousePuzzle1_Text_EddiePostBattle:
	.string "J'ai perdu mon chemin, j'ai perdu\n"
	.string "une bataille, et je suis maintenant\p"
	.string "encore plus perdu… Je ne peux pas\n"
	.string "m'en sortir…$"

Route110_TrickHousePuzzle1_Text_RobinIntro:
	.string "Qui est le TRICK MASTER ?$"

Route110_TrickHousePuzzle1_Text_RobinDefeat:
	.string "J'ai perdu alors que j'étais perdu\n"
	.string "dans mes pensées !$"

Route110_TrickHousePuzzle1_Text_RobinPostBattle:
	.string "Vous êtes fort! Qui es-tu ?$"
