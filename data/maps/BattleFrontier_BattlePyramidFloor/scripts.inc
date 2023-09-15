BattleFrontier_BattlePyramidFloor_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidFloor_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidFloor_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidFloor_OnTransition
	.byte 0

BattleFrontier_BattlePyramidFloor_OnFrame:
	map_script_2 VAR_TEMP_D, 1, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight
	map_script_2 VAR_TEMP_PLAYING_PYRAMID_MUSIC, 0, BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName
	.2byte 0

BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight::
	lockall
	@ pyramid_updatelight, cant use macro because it straddles the loop
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, PYRAMID_LIGHT_INCR_RADIUS
	setvar VAR_0x8007, SE_SAVE
	setvar VAR_RESULT, 0
BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop::
	special CallBattlePyramidFunction
	delay 2
	goto_if_ne VAR_RESULT, 2, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop
	setvar VAR_TEMP_D, 0
	releaseall
	end

BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName::
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic::
	playbgm MUS_B_PYRAMID, FALSE
	setvar VAR_TEMP_PLAYING_PYRAMID_MUSIC, 1
	end

BattleFrontier_BattlePyramidFloor_OnResume:
	pyramid_setfloorpal
	frontier_getstatus
	switch VAR_TEMP_CHALLENGE_STATUS
	case 0, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	frontier_isbattletype BATTLE_TYPE_TRAINER  @ VAR_RESULT seems to be ignored here
	setvar VAR_TEMP_D, 1
BattleFrontier_BattlePyramidFloor_EventScript_ResetParty::
	pyramid_resetparty
	end

BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	pyramid_set PYRAMID_DATA_TRAINER_FLAGS, 255
BattleFrontier_BattlePyramid_EventScript_WarpToLobby::
	pyramid_updatelight 0, PYRAMID_LIGHT_SET_RADIUS
	pyramid_clearhelditems
	special HealPlayerParty
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge::
	pyramid_save CHALLENGE_STATUS_SAVING
	special SavePlayerParty
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	pyramid_settrainers
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_OnTransition:
	call BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius::
	pyramid_updatelight 32, PYRAMID_LIGHT_SET_RADIUS
	return

BattlePyramid_WarpToNextFloor::
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Floor number
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	goto_if_eq VAR_RESULT, 7, BattlePyramid_WarpToTop
	pyramid_seedfloor
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	waitstate
	end

BattlePyramid_WarpToTop::
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP, 17, 17
	waitstate
	end

@ TRAINER_PHILLIP is used as a placeholder
BattlePyramid_TrainerBattle::
	trainerbattle TRAINER_BATTLE_PYRAMID, TRAINER_PHILLIP, 0, BattleFacility_TrainerBattle_PlaceholderText, BattleFacility_TrainerBattle_PlaceholderText
	pyramid_showhint
	waitmessage
	waitbuttonpress
	closemessage
	releaseall
	end

BattlePyramid_FindItemBall::
	pyramid_setitem
	callstd STD_FIND_ITEM
	goto_if_eq VAR_0x8007, 0, BattlePyramid_FindItemBallEnd
	pyramid_hideitem
BattlePyramid_FindItemBallEnd::
	end

BattlePyramid_Retire::
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost

@ Also used by Trainer Hill
BattleFacility_TrainerBattle_PlaceholderText:
	.string "Ceci est un exemple de message.$"

gText_BattlePyramidConfirmRest::
	.string "Votre quête BATTLE PYRAMID sera\n"
	.string "enregistrée afin que vous puissiez\p"
	.string "l'arrêter pour le moment. Est-ce\n"
	.string "que ça va ?$"

gText_BattlePyramidConfirmRetire::
	.string "Etes-vous sûr de vouloir quitter\n"
	.string "votre quête PYRAMIDE ?$"

BattlePyramid_Text_ExitHintUp1::
	.string "La sortie de cet étage est dans\n"
	.string "cette direction : {UP_ARROW}$"

BattlePyramid_Text_ExitHintLeft1::
	.string "La sortie de cet étage est dans\n"
	.string "cette direction : {LEFT_ARROW}$"

BattlePyramid_Text_ExitHintRight1::
	.string "La sortie de cet étage est dans\n"
	.string "cette direction : {RIGHT_ARROW}$"

BattlePyramid_Text_ExitHintDown1::
	.string "La sortie de cet étage est dans\n"
	.string "cette direction : {DOWN_ARROW}$"

BattlePyramid_Text_ExitHintUp2::
	.string "La sortie à cet étage est dans la\n"
	.string "direction {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft2::
	.string "La sortie à cet étage est dans la\n"
	.string "direction {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight2::
	.string "La sortie à cet étage est dans la\n"
	.string "direction {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown2::
	.string "La sortie à cet étage est dans la\n"
	.string "direction {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp3::
	.string "La sortie se fait par cette\n"
	.string "direction {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft3::
	.string "La sortie se fait par {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight3::
	.string "La sortie se fait par cette\n"
	.string "direction {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown3::
	.string "La sortie se fait par cette\n"
	.string "direction {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp4::
	.string "À cet étage, la sortie se trouve\n"
	.string "quelque part dans la direction\p"
	.string "{UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft4::
	.string "À cet étage, la sortie se trouve\n"
	.string "quelque part dans la direction\p"
	.string "{LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight4::
	.string "À cet étage, la sortie se trouve\n"
	.string "quelque part dans la direction\p"
	.string "{RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown4::
	.string "À cet étage, la sortie se trouve\n"
	.string "quelque part dans la direction\p"
	.string "{DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp5::
	.string "La sortie? C'est par là que\n"
	.string "{UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft5::
	.string "La sortie? C'est par là que\n"
	.string "{LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight5::
	.string "La sortie? C'est par là que\n"
	.string "{RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown5::
	.string "La sortie? C'est par là {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp6::
	.string "La sortie se trouve dans la\n"
	.string "direction {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft6::
	.string "La sortie se trouve dans la\n"
	.string "direction {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight6::
	.string "La sortie se trouve dans la\n"
	.string "direction {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown6::
	.string "La sortie se trouve dans la\n"
	.string "direction {DOWN_ARROW}.$"

BattlePyramid_Text_EightItemsRemaining1::
	.string "Vous recherchez des articles ? Il\n"
	.string "reste huit objets à trouver.$"

BattlePyramid_Text_SevenItemsRemaining1::
	.string "Vous recherchez des articles ? Il\n"
	.string "reste sept objets à trouver.$"

BattlePyramid_Text_SixItemsRemaining1::
	.string "Vous recherchez des articles ? Il\n"
	.string "reste six objets à trouver.$"

BattlePyramid_Text_FiveItemsRemaining1::
	.string "Vous recherchez des articles ? Il\n"
	.string "reste cinq objets à trouver.$"

BattlePyramid_Text_FourItemsRemaining1::
	.string "Vous recherchez des articles ? Il\n"
	.string "reste quatre objets à trouver.$"

BattlePyramid_Text_ThreeItemsRemaining1::
	.string "Vous recherchez des articles ? Il\n"
	.string "reste trois objets à trouver.$"

BattlePyramid_Text_TwoItemsRemaining1::
	.string "Vous recherchez des articles ? Il\n"
	.string "reste deux objets à trouver.$"

BattlePyramid_Text_OneItemRemaining1::
	.string "Vous recherchez des articles ? Il\n"
	.string "reste un article à trouver.$"

BattlePyramid_Text_ZeroItemsRemaining1::
	.string "Vous recherchez des articles ? Il\n"
	.string "n'y a plus rien à trouver !$"

BattlePyramid_Text_EightItemsRemaining2::
	.string "Parce que tu as gagné, je vais te\n"
	.string "confier un petit secret ! Il y a\p"
	.string "huit objets qui traînent ici.$"

BattlePyramid_Text_SevenItemsRemaining2::
	.string "Parce que tu as gagné, je vais te\n"
	.string "confier un petit secret ! Il reste\p"
	.string "sept objets qui traînent ici.$"

BattlePyramid_Text_SixItemsRemaining2::
	.string "Parce que tu as gagné, je vais te\n"
	.string "confier un petit secret ! Il reste\p"
	.string "six objets qui traînent ici.$"

BattlePyramid_Text_FiveItemsRemaining2::
	.string "Parce que tu as gagné, je vais te\n"
	.string "confier un petit secret ! Il reste\p"
	.string "cinq objets qui traînent ici.$"

BattlePyramid_Text_FourItemsRemaining2::
	.string "Parce que tu as gagné, je vais te\n"
	.string "confier un petit secret ! Il reste\p"
	.string "quatre objets qui traînent ici.$"

BattlePyramid_Text_ThreeItemsRemaining2::
	.string "Parce que tu as gagné, je vais te\n"
	.string "confier un petit secret ! Il reste\p"
	.string "trois objets qui traînent ici.$"

BattlePyramid_Text_TwoItemsRemaining2::
	.string "Parce que tu as gagné, je vais te\n"
	.string "confier un petit secret ! Il reste\p"
	.string "deux objets qui traînent ici.$"

BattlePyramid_Text_OneItemRemaining2::
	.string "Parce que tu as gagné, je vais te\n"
	.string "confier un petit secret ! Il n'y a\p"
	.string "qu'un seul objet qui traîne ici.$"

BattlePyramid_Text_ZeroItemsRemaining2::
	.string "Parce que tu as gagné, je vais te\n"
	.string "confier un petit secret ! Il ne\p"
	.string "reste plus rien ici.$"

BattlePyramid_Text_EightItemsRemaining3::
	.string "Comment se porte votre stock\n"
	.string "d’articles ? Je pense qu'il reste\p"
	.string "huit objets à trouver à cet étage.$"

BattlePyramid_Text_SevenItemsRemaining3::
	.string "Comment se porte votre stock\n"
	.string "d’articles ? Je pense qu'il reste\p"
	.string "sept objets qui attendent d'être\n"
	.string "trouvés à cet étage.$"

BattlePyramid_Text_SixItemsRemaining3::
	.string "Comment se porte votre stock\n"
	.string "d’articles ? Je pense qu'il reste\p"
	.string "six objets qui attendent d'être\n"
	.string "trouvés à cet étage.$"

BattlePyramid_Text_FiveItemsRemaining3::
	.string "Comment se porte votre stock\n"
	.string "d’articles ? Je pense qu'il reste\p"
	.string "cinq objets à trouver à cet étage.$"

BattlePyramid_Text_FourItemsRemaining3::
	.string "Comment se porte votre stock\n"
	.string "d’articles ? Je pense qu'il reste\p"
	.string "quatre objets qui attendent d'être\n"
	.string "trouvés à cet étage.$"

BattlePyramid_Text_ThreeItemsRemaining3::
	.string "Comment se porte votre stock\n"
	.string "d’articles ? Je pense qu'il reste\p"
	.string "trois objets qui attendent d'être\n"
	.string "trouvés à cet étage.$"

BattlePyramid_Text_TwoItemsRemaining3::
	.string "Comment se porte votre stock\n"
	.string "d’articles ? Je pense qu'il reste\p"
	.string "deux objets qui attendent d'être\n"
	.string "trouvés à cet étage.$"

BattlePyramid_Text_OneItemRemaining3::
	.string "Comment se porte votre stock\n"
	.string "d’articles ? Je pense qu'il ne\p"
	.string "reste plus qu'un objet à trouver à\n"
	.string "cet étage.$"

BattlePyramid_Text_ZeroItemsRemaining3::
	.string "Comment se porte votre stock\n"
	.string "d’articles ? Je pense qu'il n'y a\p"
	.string "plus d'objets en attente à cet\n"
	.string "étage. Prenez soin de vous\p"
	.string "maintenant !$"

BattlePyramid_Text_EightItemsRemaining4::
	.string "Vous êtes fort, vous méritez donc\n"
	.string "un indice ! Il semble y avoir huit\p"
	.string "autres objets au sol.$"

BattlePyramid_Text_SevenItemsRemaining4::
	.string "Vous êtes fort, vous méritez donc\n"
	.string "un indice ! Il semble y avoir sept\p"
	.string "autres objets sur le sol.$"

BattlePyramid_Text_SixItemsRemaining4::
	.string "Vous êtes fort, vous méritez donc\n"
	.string "un indice ! Il semble y avoir six\p"
	.string "autres objets sur le sol.$"

BattlePyramid_Text_FiveItemsRemaining4::
	.string "Vous êtes fort, vous méritez donc\n"
	.string "un indice ! Il semble y avoir cinq\p"
	.string "autres objets au sol.$"

BattlePyramid_Text_FourItemsRemaining4::
	.string "Vous êtes fort, vous méritez donc\n"
	.string "un indice ! Il semble y avoir\p"
	.string "quatre autres objets au sol.$"

BattlePyramid_Text_ThreeItemsRemaining4::
	.string "Vous êtes fort, vous méritez donc\n"
	.string "un indice ! Il semble y avoir trois\p"
	.string "autres objets au sol.$"

BattlePyramid_Text_TwoItemsRemaining4::
	.string "Vous êtes fort, vous méritez donc\n"
	.string "un indice ! Il semble y avoir deux\p"
	.string "autres objets au sol.$"

BattlePyramid_Text_OneItemRemaining4::
	.string "Vous êtes fort, vous méritez donc\n"
	.string "un indice ! Il semble n’y avoir\p"
	.string "qu’un seul objet de plus au sol.$"

BattlePyramid_Text_ZeroItemsRemaining4::
	.string "Vous êtes fort, vous méritez donc\n"
	.string "un indice ! Il semble qu’il n’y ait\p"
	.string "plus d’objets au sol.$"

BattlePyramid_Text_EightItemsRemaining5::
	.string "A cet étage de la PYRAMIDE, j'ai\n"
	.string "entendu dire qu'il y avait huit\p"
	.string "objets…$"

BattlePyramid_Text_SevenItemsRemaining5::
	.string "À cet étage de la PYRAMIDE, j’ai\n"
	.string "entendu dire qu’il y avait sept\p"
	.string "objets…$"

BattlePyramid_Text_SixItemsRemaining5::
	.string "A cet étage de la PYRAMIDE, j'ai\n"
	.string "entendu dire qu'il y avait six\p"
	.string "objets…$"

BattlePyramid_Text_FiveItemsRemaining5::
	.string "À cet étage de la PYRAMIDE, j’ai\n"
	.string "entendu dire qu’il y avait cinq\p"
	.string "objets…$"

BattlePyramid_Text_FourItemsRemaining5::
	.string "A cet étage de la PYRAMIDE, j'ai\n"
	.string "entendu dire qu'il y avait quatre\p"
	.string "objets…$"

BattlePyramid_Text_ThreeItemsRemaining5::
	.string "A cet étage de la PYRAMIDE, j'ai\n"
	.string "entendu dire qu'il y avait trois\p"
	.string "objets…$"

BattlePyramid_Text_TwoItemsRemaining5::
	.string "A cet étage de la PYRAMIDE, j'ai\n"
	.string "entendu dire qu'il y avait deux\p"
	.string "objets…$"

BattlePyramid_Text_OneItemRemaining5::
	.string "A cet étage de la PYRAMIDE, j'ai\n"
	.string "entendu dire qu'il y avait un\p"
	.string "objet…$"

BattlePyramid_Text_ZeroItemsRemaining5::
	.string "A cet étage de la PYRAMIDE, j'ai\n"
	.string "entendu dire qu'il n'y avait aucun\p"
	.string "objet…$"

BattlePyramid_Text_EightItemsRemaining6::
	.string "Avez-vous récupéré des objets ? Je\n"
	.string "crois qu'il y a huit autres\p"
	.string "articles à cet étage.$"

BattlePyramid_Text_SevenItemsRemaining6::
	.string "Avez-vous récupéré des objets ? Je\n"
	.string "crois qu'il y a sept autres\p"
	.string "articles à cet étage.$"

BattlePyramid_Text_SixItemsRemaining6::
	.string "Avez-vous récupéré des objets ? Je\n"
	.string "crois qu'il y a six autres articles\p"
	.string "à cet étage.$"

BattlePyramid_Text_FiveItemsRemaining6::
	.string "Avez-vous récupéré des objets ? Je\n"
	.string "crois qu'il y a cinq autres\p"
	.string "articles à cet étage.$"

BattlePyramid_Text_FourItemsRemaining6::
	.string "Avez-vous récupéré des objets ? Je\n"
	.string "crois qu'il y a quatre autres\p"
	.string "articles à cet étage.$"

BattlePyramid_Text_ThreeItemsRemaining6::
	.string "Avez-vous récupéré des objets ? Je\n"
	.string "crois qu'il y a trois autres\p"
	.string "articles à cet étage.$"

BattlePyramid_Text_TwoItemsRemaining6::
	.string "Avez-vous récupéré des objets ? Je\n"
	.string "crois qu'il y a deux autres\p"
	.string "articles à cet étage.$"

BattlePyramid_Text_OneItemRemaining6::
	.string "Avez-vous récupéré des objets ? Je\n"
	.string "crois qu'il y a encore un article à\p"
	.string "cet étage.$"

BattlePyramid_Text_ZeroItemsRemaining6::
	.string "Avez-vous récupéré des objets ? Je\n"
	.string "crois qu'il n'y a plus d'objets à\p"
	.string "cet étage.$"

BattlePyramid_Text_SevenTrainersRemaining1::
	.string "Tu étais vraiment génial ! Mais il\n"
	.string "y a encore sept DRESSEURS\p"
	.string "coriaces à part moi !$"

BattlePyramid_Text_SixTrainersRemaining1::
	.string "Tu étais vraiment génial ! Mais il\n"
	.string "y a encore six DRESSEURS\p"
	.string "coriaces à part moi !$"

BattlePyramid_Text_FiveTrainersRemaining1::
	.string "Tu étais vraiment génial ! Mais il\n"
	.string "y a encore cinq DRESSEURS\p"
	.string "coriaces à part moi !$"

BattlePyramid_Text_FourTrainersRemaining1::
	.string "Tu étais vraiment génial ! Mais il\n"
	.string "y a encore quatre DRESSEURS\p"
	.string "coriaces à part moi !$"

BattlePyramid_Text_ThreeTrainersRemaining1::
	.string "Tu étais vraiment génial ! Mais il\n"
	.string "y a encore trois DRESSEURS\p"
	.string "coriaces à part moi !$"

BattlePyramid_Text_TwoTrainersRemaining1::
	.string "Tu étais vraiment génial ! Mais il\n"
	.string "y a encore deux DRESSEURS\p"
	.string "coriaces à part moi !$"

BattlePyramid_Text_OneTrainersRemaining1::
	.string "Tu étais vraiment génial ! Mais il\n"
	.string "y a encore un DRESSEUR coriace à\p"
	.string "part moi !$"

BattlePyramid_Text_ZeroTrainersRemaining1::
	.string "Tu étais vraiment génial ! Il ne\n"
	.string "reste plus personne qui puisse vous\p"
	.string "battre !$"

BattlePyramid_Text_SevenTrainersRemaining2::
	.string "C'est tellement bouleversant ! Mais\n"
	.string "il reste sept DRESSEURS !\p"
	.string "Quelqu'un vous humiliera !$"

BattlePyramid_Text_SixTrainersRemaining2::
	.string "C'est tellement bouleversant ! Mais\n"
	.string "il reste six DRESSEURS !\p"
	.string "Quelqu'un vous humiliera !$"

BattlePyramid_Text_FiveTrainersRemaining2::
	.string "C'est tellement bouleversant ! Mais\n"
	.string "il reste cinq DRESSEURS !\p"
	.string "Quelqu'un vous humiliera !$"

BattlePyramid_Text_FourTrainersRemaining2::
	.string "C'est tellement bouleversant ! Mais\n"
	.string "il reste quatre DRESSEURS !\p"
	.string "Quelqu'un vous humiliera !$"

BattlePyramid_Text_ThreeTrainersRemaining2::
	.string "C'est tellement bouleversant ! Mais\n"
	.string "il reste trois DRESSEURS !\p"
	.string "Quelqu'un vous humiliera !$"

BattlePyramid_Text_TwoTrainersRemaining2::
	.string "C'est tellement bouleversant ! Mais\n"
	.string "il reste deux DRESSEURS !\p"
	.string "Quelqu'un vous humiliera !$"

BattlePyramid_Text_OneTrainersRemaining2::
	.string "C'est tellement bouleversant ! Mais\n"
	.string "il reste un DRESSEUR ! Je\p"
	.string "suis sûr que vous serez honoré !$"

BattlePyramid_Text_ZeroTrainersRemaining2::
	.string "C'est tellement bouleversant ! Mais\n"
	.string "il n'y a plus de DRESSEURS\p"
	.string "qui peuvent vous engager !$"

BattlePyramid_Text_SevenTrainersRemaining3::
	.string "C'est assez impressionnant ! Mais\n"
	.string "il y a sept autres DRESSEURS\p"
	.string "à cet étage. Pouvez-vous tous les\n"
	.string "battre ?$"

BattlePyramid_Text_SixTrainersRemaining3::
	.string "C'est assez impressionnant ! Mais\n"
	.string "il y a six autres DRESSEURS à\p"
	.string "cet étage. Pouvez-vous tous les\n"
	.string "battre ?$"

BattlePyramid_Text_FiveTrainersRemaining3::
	.string "C'est assez impressionnant ! Mais\n"
	.string "il y a cinq autres DRESSEURS\p"
	.string "à cet étage. Pouvez-vous tous les\n"
	.string "battre ?$"

BattlePyramid_Text_FourTrainersRemaining3::
	.string "C'est assez impressionnant ! Mais\n"
	.string "il y a quatre autres\p"
	.string "DRESSEURS à cet étage.\n"
	.string "Pouvez-vous tous les battre ?$"

BattlePyramid_Text_ThreeTrainersRemaining3::
	.string "C'est assez impressionnant ! Mais\n"
	.string "il y a trois autres DRESSEURS\p"
	.string "à cet étage. Pouvez-vous tous les\n"
	.string "battre ?$"

BattlePyramid_Text_TwoTrainersRemaining3::
	.string "C'est assez impressionnant ! Mais\n"
	.string "il y a deux autres DRESSEURS\p"
	.string "à cet étage. Pouvez-vous les battre\n"
	.string "tous les deux ?$"

BattlePyramid_Text_OneTrainersRemaining3::
	.string "C'est assez impressionnant ! Mais\n"
	.string "il y a encore un DRESSEUR de\p"
	.string "plus à cet étage. Pouvez-vous\n"
	.string "l'emporter ?$"

BattlePyramid_Text_ZeroTrainersRemaining3::
	.string "C'est assez impressionnant ! Vous\n"
	.string "avez parcouru tous les\p"
	.string "DRESSEURS de cet étage.$"

BattlePyramid_Text_SevenTrainersRemaining4::
	.string "Peut-être pourriez-vous balayer les\n"
	.string "sept DRESSEURS restants à cet\p"
	.string "étage.$"

BattlePyramid_Text_SixTrainersRemaining4::
	.string "Peut-être pourriez-vous balayer les\n"
	.string "six DRESSEURS restants à cet\p"
	.string "étage.$"

BattlePyramid_Text_FiveTrainersRemaining4::
	.string "Peut-être pourriez-vous balayer les\n"
	.string "cinq DRESSEURS restants à cet\p"
	.string "étage.$"

BattlePyramid_Text_FourTrainersRemaining4::
	.string "Peut-être pourriez-vous balayer les\n"
	.string "quatre DRESSEURS restants à\p"
	.string "cet étage.$"

BattlePyramid_Text_ThreeTrainersRemaining4::
	.string "Peut-être pourriez-vous balayer les\n"
	.string "trois DRESSEURS restants à\p"
	.string "cet étage.$"

BattlePyramid_Text_TwoTrainersRemaining4::
	.string "Peut-être pourriez-vous balayer les\n"
	.string "deux DRESSEURS restants à cet\p"
	.string "étage.$"

BattlePyramid_Text_OneTrainersRemaining4::
	.string "Peut-être pourriez-vous terminer\n"
	.string "votre balayage avec le seul\p"
	.string "DRESSEUR restant à cet étage.$"

BattlePyramid_Text_ZeroTrainersRemaining4::
	.string "Il ne reste plus personne qui\n"
	.string "puisse vous vaincre maintenant…$"

BattlePyramid_Text_SevenTrainersRemaining5::
	.string "Vous avez peut-être ce qu'il faut\n"
	.string "pour battre les sept\p"
	.string "DRESSEURS experts qui\n"
	.string "restent.$"

BattlePyramid_Text_SixTrainersRemaining5::
	.string "Vous aurez peut-être ce qu'il faut\n"
	.string "pour battre les six DRESSEURS\p"
	.string "experts qui restent.$"

BattlePyramid_Text_FiveTrainersRemaining5::
	.string "Vous avez peut-être ce qu'il faut\n"
	.string "pour battre les cinq DRESSEURS\p"
	.string "experts qui restent.$"

BattlePyramid_Text_FourTrainersRemaining5::
	.string "Vous aurez peut-être ce qu'il faut\n"
	.string "pour battre les quatre DRESSEURS\p"
	.string "experts qui restent.$"

BattlePyramid_Text_ThreeTrainersRemaining5::
	.string "Vous aurez peut-être ce qu'il faut\n"
	.string "pour battre les trois DRESSEURS\p"
	.string "experts qui restent.$"

BattlePyramid_Text_TwoTrainersRemaining5::
	.string "Vous aurez peut-être ce qu'il faut\n"
	.string "pour battre les deux DRESSEURS\p"
	.string "experts qui restent.$"

BattlePyramid_Text_OneTrainersRemaining5::
	.string "Vous avez peut-être ce qu'il faut\n"
	.string "pour battre le seul DRESSEUR expert\p"
	.string "qui reste.$"

BattlePyramid_Text_ZeroTrainersRemaining5::
	.string "Vos compétences sont\n"
	.string "irréprochables. Il n'y a plus\p"
	.string "d'DRESSEURS ici qui ont la moindre\n"
	.string "chance de vous battre.$"

BattlePyramid_Text_SevenTrainersRemaining6::
	.string "Pouvez-vous continuer à gagner\n"
	.string "contre les sept DRESSEURS\p"
	.string "restants ?$"

BattlePyramid_Text_SixTrainersRemaining6::
	.string "Pouvez-vous continuer à gagner\n"
	.string "contre les six DRESSEURS restants\p"
	.string "?$"

BattlePyramid_Text_FiveTrainersRemaining6::
	.string "Pouvez-vous continuer à gagner\n"
	.string "contre les cinq DRESSEURS\p"
	.string "restants ?$"

BattlePyramid_Text_FourTrainersRemaining6::
	.string "Pouvez-vous continuer à gagner\n"
	.string "contre les quatre DRESSEURS\p"
	.string "restants ?$"

BattlePyramid_Text_ThreeTrainersRemaining6::
	.string "Pouvez-vous continuer à gagner\n"
	.string "contre les trois DRESSEURS\p"
	.string "restants ?$"

BattlePyramid_Text_TwoTrainersRemaining6::
	.string "Pouvez-vous continuer à gagner\n"
	.string "contre les deux DRESSEURS restants\p"
	.string "?$"

BattlePyramid_Text_OneTrainersRemaining6::
	.string "Pouvez-vous continuer à gagner\n"
	.string "contre le dernier DRESSEUR restant\p"
	.string "?$"

BattlePyramid_Text_ZeroTrainersRemaining6::
	.string "Il ne reste plus aucun\n"
	.string "DRESSEUR qui puisse vous\p"
	.string "embaucher maintenant…$"
