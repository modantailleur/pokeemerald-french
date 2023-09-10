.set LOCALID_ATTENDANT, 1

SlateportCity_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_BattleTentCorridor_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_BattleTentCorridor_OnWarp
	.byte 0

	@ This is Slateport Tent's version of the Battle Factory Pre-Battle Room

SlateportCity_BattleTentCorridor_OnWarp:
	map_script_2 VAR_TEMP_1, 0, SlateportCity_BattleTentCorridor_EventScript_SetUpObjects
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_SetUpObjects::
	setvar VAR_TEMP_1, 1
	goto_if_ne VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth
	setobjectxy LOCALID_ATTENDANT, 2, 2
	turnobject LOCALID_ATTENDANT, DIR_SOUTH
SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

SlateportCity_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, SlateportCity_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_EnterCorridor::
	goto_if_eq VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantEnter
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerEnter
	waitmovement 0
	goto_if_eq VAR_0x8006, 2, SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge
	slateporttent_generaterentalmons
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	slateporttent_rentmons
	waitstate
SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 2, 1
	waitdooranim
	applymovement LOCALID_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantExit
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerExit
	waitmovement 0
	closedoor 2, 1
	waitdooranim
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM, 4, 4
	waitstate
	end

SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle::
	factory_setopponentmons
	factory_resethelditems
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent::
	frontier_get FRONTIER_DATA_BATTLE_NUM
	call_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent
	call_if_eq VAR_RESULT, 2, SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, SlateportCity_BattleTentCorridor_EventScript_AskSwapMon
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge
	case 2, SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge

SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case YES, SlateportCity_BattleTentCorridor_EventScript_PauseChallenge
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case 0, SlateportCity_BattleTent_EventScript_WarpToLobbyLost
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskSwapMon::
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	case YES, SlateportCity_BattleTentCorridor_EventScript_SwapMons
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_SwapMons::
	fadescreen FADE_TO_BLACK
	slateporttent_swapmons
	waitstate
	goto_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_PauseChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait
	waitmessage
	slateporttent_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end

SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge::
	special SavePlayerParty
	factory_setparties 0
	goto SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_Movement_PlayerEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SlateportCity_BattleTentCorridor_Movement_PlayerExit:
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_BattleTentCorridor_Movement_AttendantEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

SlateportCity_BattleTentCorridor_Movement_AttendantExit:
	walk_up
	set_invisible
	step_end

@ Leftover text from when this was a Contest Hall in R/S
@ Unused
SlateportCity_ContestHall_Text_AdviceForContests:
	.string "Envie d’un petit conseil savoureux\n"
	.string "pour les CONCOURS ? Utiliser un\p"
	.string "certain mouvement après un autre\n"
	.string "certain type de mouvement attire\p"
	.string "parfois une attention particulière.\n"
	.string "Si vous savez ce que vous faites,\p"
	.string "vous pouvez gagner gros en attrait.\n"
	.string "Bien sûr, vos adversaires\p"
	.string "pourraient essayer de perturber\n"
	.string "l'affichage de votre POKéMON.$"

@ Unused
SlateportCity_ContestHall_Text_MyPapaIsContestJudge:
	.string "Mon papa, c'est un JUGE DE\n"
	.string "CONCOURS. Je me demande ce que je\p"
	.string "devrais être quand je serai grand,\n"
	.string "un JUGE ou un GYM LEADER ?$"

@ Unused
SlateportCity_ContestHall_Text_ImLikeMajorlyCheesed:
	.string "Hé, mec, je suis comme un gros\n"
	.string "fromage, tu sais. Genre, tu sais,\p"
	.string "je voulais juste savoir pourquoi\n"
	.string "mon POKéMON n'a jamais gagné, tu\p"
	.string "sais, genre, hé ? Alors, j'ai donné\n"
	.string "mes deux cents au JUGE, vous savez,\p"
	.string "ils sont gratuits. Et il ne voulait\n"
	.string "pas m'écouter, genre, hé ! Alors,\p"
	.string "genre, c'est vraiment décevant, mec\n"
	.string "! Hé, comme toi ! Zippe-le, tu sais\p"
	.string "? Juste, tu sais, prends ça !$"

@ Unused
SlateportCity_ContestHall_Text_ExplainTorment:
	.string "C'est genre TM41, tu sais ? Hé,\n"
	.string "c'est TORMENT, tu m'entends ? Par\p"
	.string "exemple, ça ne permettra pas à\n"
	.string "l'autre gars d'utiliser le même\p"
	.string "mouvement deux fois de suite, tu\n"
	.string "vois ? Hé, maintenant, écoutez ici,\p"
	.string "genre, je ne vous inflige pas de\n"
	.string "tourment !$"

@ Unused
SlateportCity_ContestHall_Text_MCStepUpTakePartInContest:
	.string "MC : Oh, mon Dieu ! N'est-ce pas un\n"
	.string "superbe POKéMON ? S'il te plaît!\p"
	.string "N'hésitez pas et participez à nos\n"
	.string "splendides CONCOURS ! Vous ferez\p"
	.string "bien ! Je suis sur et certain! Mes\n"
	.string "yeux ne m'ont jamais fait défaut !$"

@ Unused
SlateportCity_ContestHall_Text_JudgeWouldntDoToMissContest:
	.string "JUGE : Eh bien, bonjour ! Je vois\n"
	.string "que tu es FORMATTHIEUEUR ! Alors,\p"
	.string "il ne faudrait pas que vous\n"
	.string "manquiez un CONCOURS POKéMON !\p"
	.string "Obtenez un PASS CONCOURS à\n"
	.string "VERGUIDOTURF CITY et participez à\p"
	.string "tout moment !$"

@ Unused
SlateportCity_ContestHall_Text_ItsAppealTime:
	.string "C'est l'heure de l'appel ! Avec\n"
	.string "quoi dois-je commencer ?$"

@ Unused
SlateportCity_ContestHall_Text_DidntPayAttentionToAppeal:
	.string "Ils n'ont pas prêté beaucoup\n"
	.string "d'attention à l'attrait de mon\p"
	.string "POKéMON… Humph, ce JUGE, il ne sait\n"
	.string "rien de bon quand il le voit.$"

@ Unused
SlateportCity_ContestHall_Text_RewardWithSageAdvice:
	.string "Oh salut! Vous devez être un fan\n"
	.string "sérieux pour être aussi proche de\p"
	.string "l'action. Je récompenserai votre\n"
	.string "enthousiasme avec ce sage conseil.\p"
	.string "Si un mouvement se passe vraiment\n"
	.string "bien, le public sera enthousiasmé.\p"
	.string "Le POKéMON qui fait son apparition\n"
	.string "quand tout le monde est excité… Eh\p"
	.string "bien, on pourrait penser que\n"
	.string "quelque chose de bien doit arriver\p"
	.string "!$"

@ Unused
SlateportCity_ContestHall_Text_MoreFreakedOutThanMon:
	.string "Je ne peux pas faire ça ! Je suis\n"
	.string "plus paniqué que mon POKéMON. Je\p"
	.string "frissonne et mon cœur bat la\n"
	.string "chamade !$"

@ Unused
SlateportCity_ContestHall_Text_BattleAndContestAlike:
	.string "Une bataille et un CONCOURS ne sont\n"
	.string "pas identiques, mais ils se\p"
	.string "ressemblent aussi. Vous devez\n"
	.string "travailler dur et croire au POKéMON\p"
	.string "que vous avez collecté.$"

@ Unused
SlateportCity_ContestHall_Text_MonLooksOnTopOfGame:
	.string "Ce POKéMON a l'air d'être au top de\n"
	.string "sa forme, hein ? Un POKéMON qui\p"
	.string "fait du bien dans le jugement\n"
	.string "secondaire semble être plus détendu\p"
	.string "lorsqu'il fait appel.$"

@ Unused
SlateportCity_ContestHall_Text_MyMonBetterThanThatLot:
	.string "Allez-vous regarder ce triste\n"
	.string "spectacle ? Heh, mon POKéMON est\p"
	.string "absolument meilleur que ça !$"

@ Unused
SlateportCity_ContestHall_Text_GetUrgeToMoveWithMon:
	.string "N'avez-vous pas envie de bouger\n"
	.string "avec POKéMON s'ils lancent un appel\p"
	.string "énergique ?$"

@ Unused
SlateportCity_ContestHall_Text_HyperRankStage:
	.string "CONCOURS POKéMON STAGE HYPER RANG\n"
	.string "!$"
