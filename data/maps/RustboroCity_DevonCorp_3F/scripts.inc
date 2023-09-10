.set LOCALID_DEVON_EMPLOYEE, 2

RustboroCity_DevonCorp_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_3F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RustboroCity_DevonCorp_3F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_DevonCorp_3F_OnFrame
	.byte 0

RustboroCity_DevonCorp_3F_OnTransition:
	call_if_eq VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos
	end

RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos::
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 3, 2
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_LEFT
	return

RustboroCity_DevonCorp_3F_OnWarp:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	end

RustboroCity_DevonCorp_3F_OnFrame:
	map_script_2 VAR_DEVON_CORP_3F_STATE, 0, RustboroCity_DevonCorp_3F_EventScript_MeetPresident
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_MeetPresident::
	lockall
	msgbox RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen
	waitmovement 0
	delay 80
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_FOLLOW_ME, FALSE
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_PleaseGoAhead, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor, MSGBOX_DEFAULT
	giveitem ITEM_LETTER
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_3F_Text_ReceivedPokenav
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare, MSGBOX_DEFAULT
	setflag FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_BRINEY_LOCATION, 1
	clearflag FLAG_HIDE_RUSTBORO_CITY_RIVAL
	setvar VAR_DEVON_CORP_3F_STATE, 1
	setvar VAR_RUSTBORO_CITY_STATE, 6
	releaseall
	end

RustboroCity_DevonCorp_3F_Movement_Unused:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk:
	delay_16
	walk_in_place_faster_down
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

RustboroCity_DevonCorp_3F_EventScript_MrStone::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EXP_SHARE, RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, RustboroCity_DevonCorp_3F_EventScript_GiveExpShare
	msgbox RustboroCity_DevonCorp_3F_Text_CountingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_GiveExpShare::
	msgbox RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_EXP_SHARE
	msgbox RustboroCity_DevonCorp_3F_Text_ExplainExpShare, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor::
	msgbox RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REPEAT_BALL, RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls
	msgbox RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls::
	msgbox RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay::
	msgbox RustboroCity_DevonCorp_3F_Text_RareRocksDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor:
	.string "Je suis M. STONE, le PRÉSIDENT de\n"
	.string "la DEVON CORPORATION. Je venais\p"
	.string "juste d'avoir des nouvelles de toi\n"
	.string "! Vous avez sauvé notre personnel\p"
	.string "non pas une, mais deux ! J'ai une\n"
	.string "faveur à demander à une personne\p"
	.string "extraordinaire comme toi. Je\n"
	.string "comprends que vous livrez un colis\p"
	.string "au chantier naval de SLATEPORT. En\n"
	.string "chemin, pourriez-vous vous arrêter\p"
	.string "à VILLAGE MYOKARA ? J'espérais que\n"
	.string "vous remettriez une LGUIDOTRE à\p"
	.string "PIERRE à DEWFORD.$"

RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis:
	.string "M. STONE : Maintenant, vous devez\n"
	.string "savoir que je suis un grand\p"
	.string "PRÉSIDENT. Donc, je ne serais\n"
	.string "jamais assez radin pour demander\p"
	.string "une faveur sans rien en retour.\n"
	.string "C'est pourquoi je veux que tu aies\p"
	.string "ça !$"

RustboroCity_DevonCorp_3F_Text_ReceivedPokenav:
	.string "{PLAYER} a reçu un POKéNAV.$"

RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp:
	.string "M. STONE : Cet appareil… C'est un\n"
	.string "POKéMON NAVIGATOR, ou POKéNAV en\p"
	.string "abrégé. C'est un outil\n"
	.string "indispensable pour tout\p"
	.string "FORMATTHIEUEUR en aventure. Il\n"
	.string "comporte une carte de la région\p"
	.string "HOENN. Vous pouvez facilement\n"
	.string "vérifier les emplacements de\p"
	.string "DEWFORD et SLATEPORT ! À propos,\n"
	.string "j'ai entendu dire que de sinistres\p"
	.string "criminels -- MAGMA et AQUA, je\n"
	.string "crois -- ont semé le trouble\p"
	.string "partout dans le monde. Je pense\n"
	.string "qu'il serait préférable que vous\p"
	.string "vous reposiez avant de partir.$"

RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare:
	.string "M. STONE : Eh bien, {PLAYER}{KUN},\n"
	.string "vas-y avec prudence !$"

RustboroCity_DevonCorp_3F_Text_CountingOnYou:
	.string "M. STONE : je compte sur toi !$"

RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter:
	.string "M. STONE : Vous avez remis ma\n"
	.string "LGUIDOTRE ? Merci de bien vouloir!\p"
	.string "C'est ma façon de vous remercier.\n"
	.string "Cela devrait vous aider, un\p"
	.string "FORMATTHIEUEUR.$"

RustboroCity_DevonCorp_3F_Text_ExplainExpShare:
	.string "M. PIERRE : Un POKéMON contenant\n"
	.string "cette EXP. SHARE recevra une partie\p"
	.string "des points EXP de la bataille. Il\n"
	.string "obtiendra des points EXP même s'il\p"
	.string "n'a pas réellement combattu. Je\n"
	.string "dirais EXP. SHARE est très utile\p"
	.string "pour élever des POKéMON faibles.$"

RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends:
	.string "M. STONE : Depuis ma jeunesse, je\n"
	.string "me suis plongé dans le travail. Par\p"
	.string "conséquent, je ne connais pas les\n"
	.string "tendances et ce genre de choses.\p"
	.string "Mais est-ce que les jeunes veulent\n"
	.string "tous devenir FORMATTHIEUEURS dans\p"
	.string "la LIGUE POKéMON ?$"

RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere:
	.string "Il s'agit du troisième étage de\n"
	.string "DEVON CORPORATION. Le BUREAU de\p"
	.string "notre PRÉSIDENT se trouve à cet\n"
	.string "étage. Quoi qu'il en soit, je ne\p"
	.string "peux pas vous dire à quel point je\n"
	.string "suis reconnaissant pour ce que vous\p"
	.string "avez fait. Euh… Au fait, ce colis\n"
	.string "que vous nous avez retourné…\p"
	.string "Puis-je vous demander de le livrer\n"
	.string "au CHANTIER NAVAL de SLATEPORT ? Ce\p"
	.string "serait horrible si ces voleurs\n"
	.string "essayaient de s'en emparer à\p"
	.string "nouveau. Euh… Hehehe, alors, euh,\n"
	.string "je peux compter sur toi pour faire\p"
	.string "ça pour moi ? Oh c'est vrai.\n"
	.string "Pourriez-vous attendre ici une\p"
	.string "seconde ?$"

RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe:
	.string "Notre PRESIDENT souhaite\n"
	.string "s'entretenir avec vous. S'il te\p"
	.string "plaît, viens avec moi.$"

RustboroCity_DevonCorp_3F_Text_PleaseGoAhead:
	.string "S'il vous plaît, allez-y.$"

RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard:
	.string "Si vous visitez le CHANTIER NAVAL à\n"
	.string "SLATEPORT, vous devriez aller voir\p"
	.string "le CAPT. POUPE.$"

RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular:
	.string "Les nouveaux produits DEVON, le\n"
	.string "REPEAT BALL et le TIMER BALL, sont\p"
	.string "devenus extrêmement populaires\n"
	.string "parmi les DRESSEURS.$"

RustboroCity_DevonCorp_3F_Text_RareRocksDisplay:
	.string "C'est une collection de roches et\n"
	.string "de pierres rares assemblées par le\p"
	.string "PRÉSIDENT.$"
