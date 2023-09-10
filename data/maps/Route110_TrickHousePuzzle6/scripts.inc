Route110_TrickHousePuzzle6_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle6_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHousePuzzle6_OnWarp
	.byte 0

Route110_TrickHousePuzzle6_OnTransition:
	special RotatingGate_InitPuzzle
	end

Route110_TrickHousePuzzle6_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, Route110_TrickHousePuzzle6_EventScript_InitPuzzle
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_5
Route110_TrickHousePuzzle6_EventScript_InitPuzzle::
	special RotatingGate_InitPuzzleAndGraphics
	end

Route110_TrickHousePuzzle6_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_6_STATE, 0, Route110_TrickHousePuzzle6_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle6_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_6_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle6_EventScript_Sophia::
	trainerbattle_single TRAINER_SOPHIA, Route110_TrickHousePuzzle6_Text_SophiaIntro, Route110_TrickHousePuzzle6_Text_SophiaDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SophiaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Benny::
	trainerbattle_single TRAINER_BENNY, Route110_TrickHousePuzzle6_Text_BennyIntro, Route110_TrickHousePuzzle6_Text_BennyDefeat
	msgbox Route110_TrickHousePuzzle6_Text_BennyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Sebastian::
	trainerbattle_single TRAINER_SEBASTIAN, Route110_TrickHousePuzzle6_Text_SebastianIntro, Route110_TrickHousePuzzle6_Text_SebastianDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SebastianPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} a noté le code secret sur la\n"
	.string "porte. “ TRICK MASTER, c'est ma\p"
	.string "vie. ” … … … … … … … … La serrure\n"
	.string "s'est ouverte !$"

Route110_TrickHousePuzzle6_Text_SophiaIntro:
	.string "Quand j’ai entendu qu’il y avait\n"
	.string "une maison étrange, j’ai dû la\p"
	.string "vérifier.$"

Route110_TrickHousePuzzle6_Text_SophiaDefeat:
	.string "J'ai découvert un DRESSEUR coriace\n"
	.string "!$"

Route110_TrickHousePuzzle6_Text_SophiaPostBattle:
	.string "Je suis sûr que je passerai un bon\n"
	.string "moment à découvrir cet endroit.\p"
	.string "C'est un défi qui mérite d'être\n"
	.string "répété !$"

Route110_TrickHousePuzzle6_Text_BennyIntro:
	.string "Peut-être que je pourrais faire\n"
	.string "voler mon POKéMON OISEAU au-dessus\p"
	.string "du mur…$"

Route110_TrickHousePuzzle6_Text_BennyDefeat:
	.string "Waaaah ! J'ai tout foiré !$"

Route110_TrickHousePuzzle6_Text_BennyPostBattle:
	.string "Ehehehe… Je suppose que j'ai perdu\n"
	.string "parce que j'essayais de tricher.$"

Route110_TrickHousePuzzle6_Text_SebastianIntro:
	.string "J'ai le vertige à cause de ces\n"
	.string "portes tournantes…$"

Route110_TrickHousePuzzle6_Text_SebastianDefeat:
	.string "Tout tourne en rond. Je n'en peux\n"
	.string "plus…$"

Route110_TrickHousePuzzle6_Text_SebastianPostBattle:
	.string "Vous ne semblez pas du tout\n"
	.string "affecté. Ou avez-vous votre visage\p"
	.string "de poker ?$"
