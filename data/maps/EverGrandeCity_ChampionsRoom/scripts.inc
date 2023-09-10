.set LOCALID_WALLACE, 1
.set LOCALID_RIVAL, 2
.set LOCALID_BIRCH, 3

EverGrandeCity_ChampionsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_ChampionsRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_ChampionsRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_ChampionsRoom_OnFrame
	.byte 0

EverGrandeCity_ChampionsRoom_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

EverGrandeCity_ChampionsRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_ChampionsRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_EnterRoom
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_EnterRoom::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp4
	waitmovement 0
	delay 40
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace
	waitmovement 0
	setvar VAR_TEMP_1, 1
	goto EverGrandeCity_ChampionsRoom_EventScript_Wallace
	releaseall
	end

EverGrandeCity_ChampionsRoom_Movement_PlayerApproachWallace:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_EventScript_Wallace::
	playbgm MUS_ENCOUNTER_CHAMPION, FALSE
	msgbox EverGrandeCity_ChampionsRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLACE, EverGrandeCity_ChampionsRoom_Text_Defeat
	goto EverGrandeCity_ChampionsRoom_EventScript_Defeated
	end

EverGrandeCity_ChampionsRoom_EventScript_Defeated::
	playse SE_DOOR
	setmetatile 6, 1, METATILE_EliteFour_OpenDoorChampion_Frame, FALSE
	setmetatile 6, 2, METATILE_EliteFour_OpenDoorChampion_Opening, FALSE
	special DrawWholeMapView
	msgbox EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	closemessage
	playse SE_DOOR
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic
	addobject LOCALID_RIVAL
	call EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayAdvice
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice
	end

EverGrandeCity_ChampionsRoom_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, FALSE
	return

EverGrandeCity_ChampionsRoom_EventScript_MayAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BrendanAdvice::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanAdvice, MSGBOX_DEFAULT
	delay 40
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon, MSGBOX_DEFAULT
	goto EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF
	end

EverGrandeCity_ChampionsRoom_EventScript_BirchArrivesExitForHoF::
	closemessage
	addobject LOCALID_BIRCH
	applymovement LOCALID_BIRCH, EverGrandeCity_ChampionsRoom_Movement_BirchArrives
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex, MSGBOX_DEFAULT
	call ProfBirch_EventScript_RatePokedex
	msgbox EverGrandeCity_ChampionsRoom_Text_BirchCongratulations, MSGBOX_DEFAULT
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 20
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalFollows
	waitmovement 0
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside, MSGBOX_DEFAULT
	checkplayergender
	call_if_eq VAR_RESULT, MALE, EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations
	call_if_eq VAR_RESULT, FEMALE, EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations
	closemessage
	applymovement LOCALID_WALLACE, EverGrandeCity_ChampionsRoom_Movement_WallaceExit
	applymovement OBJ_EVENT_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_PlayerExit
	waitmovement 0
	setflag FLAG_HIDE_PETALBURG_GYM_GREETER
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 7, 16
	waitstate
	releaseall
	end

EverGrandeCity_ChampionsRoom_EventScript_MayCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_MayCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_BrendanCongratulations::
	msgbox EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations, MSGBOX_DEFAULT
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalApproachPlayer::
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_EventScript_RivalLookBackAndForth::
	applymovement LOCALID_RIVAL, EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth
	waitmovement 0
	return

EverGrandeCity_ChampionsRoom_Movement_PlayerExitStart:
	walk_up
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_PlayerExit:
	walk_up
	delay_16
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalApproachPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_in_place_faster_right
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalLookBackAndForth:
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_up
	delay_8
	walk_in_place_faster_right
	delay_16
	step_end

EverGrandeCity_ChampionsRoom_Movement_RivalFollows:
	walk_right
	walk_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExitStart:
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

EverGrandeCity_ChampionsRoom_Movement_WallaceExit:
	walk_up
	delay_8
	set_invisible
	step_end

EverGrandeCity_ChampionsRoom_Movement_BirchArrives:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_in_place_faster_left
	step_end

EverGrandeCity_ChampionsRoom_Text_IntroSpeech:
	.string "MARC : Bienvenue, {PLAYER}{KUN}. Cet\n"
	.string "incident à ATALANOPOLIS… C’était un\p"
	.string "travail superbe, mettre fin à cette\n"
	.string "crise tout seul. Oops! Il ne serait\p"
	.string "pas juste de dire que vous seul\n"
	.string "avez mis fin à la crise. Vous avez\p"
	.string "surmonté cette situation difficile\n"
	.string "en travaillant comme un seul homme\p"
	.string "avec votre POKéMON. Nous, les\n"
	.string "DRESSEURS, élevons des POKéMON en\p"
	.string "leur donnant des objets et en leur\n"
	.string "apprenant de nouvelles techniques\p"
	.string "de combat. Mais nous apprenons\n"
	.string "nous-mêmes beaucoup de choses grâce\p"
	.string "à POKéMON. Et c’est là que vos\n"
	.string "réalisations sont mises à l’épreuve\p"
	.string "par rapport à celles d’autres\n"
	.string "personnes comme vous. Maintenant!\p"
	.string "Qui peut danser le plus élégamment\n"
	.string "avec son POKéMON à HOENN ?\p"
	.string "Montre-moi ici et maintenant !$"

EverGrandeCity_ChampionsRoom_Text_Defeat:
	.string "Moi, le CHAMPION, je tombe dans la\n"
	.string "défaite… C'était un travail\p"
	.string "merveilleux. Vous étiez élégant,\n"
	.string "d'une manière exaspérante. Et\p"
	.string "pourtant, c'était absolument\n"
	.string "glorieux ! Félicitations à vous,\p"
	.string "{PLAYER}{KUN} ! Vous êtes un\n"
	.string "véritable dresseur de POKéMON !$"

EverGrandeCity_ChampionsRoom_Text_PostBattleSpeech:
	.string "MARC : Les POKéMON que vous avez\n"
	.string "envoyés au combat… Parfois, ils\p"
	.string "dansaient comme une brise\n"
	.string "printanière, et parfois ils\p"
	.string "frappaient comme un éclair. C'est\n"
	.string "avec une élégance légère mais sûre\p"
	.string "que vous avez dirigé votre POKéMON.\n"
	.string "Même moi, je me suis senti ébloui\p"
	.string "par votre performance magistrale !\n"
	.string "Vous vous trouvez désormais au\p"
	.string "sommet glorieux de la POKéMON\n"
	.string "LEAGUE. Je vous proclame maintenant\p"
	.string "la nouvelle région HOENN…$"

EverGrandeCity_ChampionsRoom_Text_MayAdvice:
	.string "MAI : {PLAYER}{KUN} ! Voici quelques\n"
	.string "conseils avant de défier le\p"
	.string "CHAMPION…$"

EverGrandeCity_ChampionsRoom_Text_MayItsAlreadyOver:
	.string "MAI : Hein ? Quoi quoi quoi?\n"
	.string "{PLAYER}{KUN}… Serait-ce ça… C'est\p"
	.string "déjà fini ?$"

EverGrandeCity_ChampionsRoom_Text_BrendanAdvice:
	.string "BRICE : {PLAYER} ! Souhaitez-vous des\n"
	.string "conseils avant de défier le\p"
	.string "CHAMPION ?…$"

EverGrandeCity_ChampionsRoom_Text_BrendanYouveWon:
	.string "BRICE : {PLAYER}… Essayez-vous de me\n"
	.string "dire… Vous avez battu le CHAMPION\p"
	.string "?$"

EverGrandeCity_ChampionsRoom_Text_BirchArriveRatePokedex:
	.string "PROF. SEKO : Vous voyez ? Qu'est-ce\n"
	.string "que je t'ai dit, {RIVAL} ? Ne vous\p"
	.string "ai-je pas dit que vous n'aviez pas\n"
	.string "à vous soucier de {PLAYER}{KUN} ? …\p"
	.string "… … … … … … … {PLAYER}{KUN}, vous\n"
	.string "avez enfin réussi. Quand j'ai\p"
	.string "appris que vous aviez battu votre\n"
	.string "propre père au PGUIDOALBURG GYM,\p"
	.string "j'ai pensé que vous aviez peut-être\n"
	.string "une chance… Mais dire que vous êtes\p"
	.string "réellement devenu le CHAMPION ! Ah\n"
	.string "oui! Qu'est devenu votre POKéDEX ?\p"
	.string "Tiens, laisse-moi voir.$"

EverGrandeCity_ChampionsRoom_Text_BirchCongratulations:
	.string "PROF. SEKO : Quoi qu'il en soit,\n"
	.string "félicitations ! Maintenant, entrez\p"
	.string "fièrement dans la dernière salle !$"

EverGrandeCity_ChampionsRoom_Text_WallaceComeWithMe:
	.string "MARC : {PLAYER}{KUN}… Non,\n"
	.string "laissez-moi reformuler cela\p"
	.string "correctement. Le nouveau CHAMPION!\n"
	.string "Viens avec moi.$"

EverGrandeCity_ChampionsRoom_Text_WallaceWaitOutside:
	.string "MARC : Je suis désolé, mais… À\n"
	.string "partir de maintenant, seuls les\p"
	.string "DRESSEURS devenus CHAMPIONS peuvent\n"
	.string "participer. Vous devrez attendre\p"
	.string "dehors avec le PROF. SEKO.$"

EverGrandeCity_ChampionsRoom_Text_MayCongratulations:
	.string "FLORA : Gémir… … … … … … … … … … …\n"
	.string "… … … … … … Je plaisante ! C'est\p"
	.string "bon! C'est la règle ! {PLAYER}{KUN}\n"
	.string "! Honnêtement, félicitations !$"

EverGrandeCity_ChampionsRoom_Text_BrendanCongratulations:
	.string "BRICE : Quoi ?! … … … … … … … … … …\n"
	.string "… … On n'y peut rien si telle est\p"
	.string "la règle. {PLAYER}, bravo !\n"
	.string "Félicitations !$"
