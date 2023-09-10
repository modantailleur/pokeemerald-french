.set LOCALID_SS_TIDAL, 2
.set LOCALID_FERRY_ATTENDANT, 3
.set LOCALID_MANIAC_1, 9
.set LOCALID_MANIAC_2, 10
.set LOCALID_GIRL, 12
.set LOCALID_CAMPER, 14
.set LOCALID_FISHERMAN_2, 18
.set LOCALID_MAN_4, 23

BattleFrontier_OutsideWest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition
	.byte 0

BattleFrontier_OutsideWest_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_FerryAttendant::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_OutsideWest_EventScript_NoSSTicket
	message BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination::
	multichoicedefault 18, 6, MULTI_SSTIDAL_BATTLE_FRONTIER, 2, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_OutsideWest_EventScript_FerryToSlateport
	case 1, BattleFrontier_OutsideWest_EventScript_FerryToLilycove
	case 2, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	case MULTI_B_PRESSED, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	end

BattleFrontier_OutsideWest_EventScript_NoSSTicket::
	msgbox BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToSlateport::
	msgbox BattleFrontier_OutsideWest_Text_SlateportItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToLilycove::
	msgbox BattleFrontier_OutsideWest_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination::
	message BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_BoardFerry::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_FERRY_ATTENDANT, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	return

BattleFrontier_OutsideWest_EventScript_CancelFerrySelect::
	msgbox BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_BattleDomeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattleFactorySign::
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattlePikeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign, MSGBOX_SIGN
	end

@ Unused. Of note, Battle Tower is in the East section in the final release
BattleFrontier_OutsideWest_EventScript_UnusedNPC1::
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC2::
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Boy1::
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman2::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere
	waitmessage
	applymovement LOCALID_FISHERMAN_2, Common_Movement_FaceAwayPlayer
	waitmovement 0
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Man1::
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Maniac1::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_Maniac2::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk::
	applymovement LOCALID_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons, MSGBOX_DEFAULT
	applymovement LOCALID_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper::
	lock
	faceplayer
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_CamperFaceFactory::
	applymovement LOCALID_CAMPER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory::
	return

BattleFrontier_OutsideWest_EventScript_Girl::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper
	waitmessage
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_GirlShudderNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_GirlShudderSouth
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_GirlShudderWest
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_GirlShudderEast
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_GirlShudderNorth::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderSouth::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderWest::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderEast::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast
	waitmovement 0
	return

BattleFrontier_OutsideWest_Movement_GirlShudderNorth:
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderSouth:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderWest:
	walk_in_place_faster_right
	walk_in_place_faster_right
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderEast:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

BattleFrontier_OutsideWest_EventScript_Woman2::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors
	end

BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Fisherman1::
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC3::
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Lass::
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_ExpertM::
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man2::
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman1::
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan1::
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan2::
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Boy2::
	lock
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_OldMan::
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man4::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAN_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_PokefanF::
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_BattleDomeSign:
	.string "C'est le DÔME DE BATAILLE ! Votre\n"
	.string "chemin vers la superstar invincible\p"
	.string "!$"

BattleFrontier_OutsideWest_Text_BattleFactorySign:
	.string "C'est l'USINE DE COMBAT ! Cherchez\n"
	.string "le POKéMON le plus résistant !$"

BattleFrontier_OutsideWest_Text_BattlePikeSign:
	.string "C'est le BROCHGUIDO DE COMBAT !\n"
	.string "Choisissez l'un des trois chemins\p"
	.string "!$"

BattleFrontier_OutsideWest_Text_ThisIsBattleTower:
	.string "C'est la TOUR DE BATAILLE. LES\n"
	.string "DRESSEURS apportent leur POKéMON le\p"
	.string "mieux élevé pour des matchs de type\n"
	.string "élimination.$"

BattleFrontier_OutsideWest_Text_MayISeeYourTicket:
	.string "Bonjour, tu es là pour le ferry ?\n"
	.string "Puis-je voir votre BILLGUIDO ?$"

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard:
	.string "{PLAYER} n'a pas le TICKGUIDO… Je\n"
	.string "suis vraiment désolé. Vous devez\p"
	.string "avoir un BILLGUIDO pour monter à\n"
	.string "bord du traversier.$"

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo:
	.string "{PLAYER} a flashé le TICKGUIDO.\n"
	.string "Parfait! C'est tout ce dont vous\p"
	.string "avez besoin ! Et où aimerais-tu\n"
	.string "aller ?$"

BattleFrontier_OutsideWest_Text_SlateportItIs:
	.string "POIVRESSEL, c'est vrai, alors !$"

BattleFrontier_OutsideWest_Text_LilycoveItIs:
	.string "NENUCRIQUE, c'est vrai, alors !$"

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime:
	.string "S'il vous plaît, naviguez avec nous\n"
	.string "une autre fois !$"

BattleFrontier_OutsideWest_Text_PleaseBoardFerry:
	.string "Veuillez monter à bord du ferry et\n"
	.string "attendre le départ.$"

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo:
	.string "Alors, où aimerais-tu aller ?$"

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends:
	.string "Je suis le meilleur de tous mes\n"
	.string "amis. Mais là… j'ai été inutile !$"

BattleFrontier_OutsideWest_Text_CantFindBattleTower:
	.string "Je veux aller à la BATTLE TOWER,\n"
	.string "mais je ne la trouve pas même si\p"
	.string "j'ai une carte de la ZONE DE\n"
	.string "COMBAT. Cet endroit est tout\p"
	.string "simplement trop grand !$"

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere:
	.string "J’ai eu envie de relever un défi\n"
	.string "dès mon arrivée ici. Mais en\p"
	.string "chemin, j’ai eu le mal de mer…\n"
	.string "Urrrrp…$"

BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere:
	.string "Ce n'est pas comme si n'importe qui\n"
	.string "pouvait venir ici, tu sais ? Seuls\p"
	.string "les FORMATTHIEUEURS reconnus comme\n"
	.string "durs sont amenés ici. C'est\p"
	.string "pourquoi de nombreux DRESSEURS ne\n"
	.string "connaissent même pas ZONE DE\p"
	.string "COMBAT.$"

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons:
	.string "Hé, frérot… Tu es sûr qu'on peut\n"
	.string "relever des défis même si on n'a\p"
	.string "pas de POKéMON ?$"

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons:
	.string "Euh… je suis sûr que tout ira bien.\n"
	.string "Je pense… Mais tu te souviens de ce\p"
	.string "grand type effrayant ? Il a dit : “\n"
	.string "Je vais te prêter POKéMON ! ”$"

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons:
	.string "C'est la BATTLE FACTORY. Vous\n"
	.string "pouvez y louer des POKéMON forts.\p"
	.string "Mais cela me fait réfléchir. Qui\n"
	.string "élève ces POKéMON de location ?$"

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper:
	.string "J'ai peur d'entrer dans le BATTLE\n"
	.string "PIKE à cause de SEVIPER… M-mais je\p"
	.string "suis venu jusqu'ici, alors je vais\n"
	.string "essayer de tout conquérir !\p"
	.string "…Frimir…$"

BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors:
	.string "Jouons à pierre, papier, ciseaux !\n"
	.string "Un deux trois! … … … … … …$"

BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge:
	.string "Yay! J'ai gagné! Je relèverai le\n"
	.string "défi BATTLE PIKE !$"

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge:
	.string "Oh, non… j'ai perdu. Je suppose que\n"
	.string "je n'ai pas beaucoup de chance\p"
	.string "aujourd'hui. Je reporte mon défi\n"
	.string "BATTLE PIKE à demain.$"

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling:
	.string "Je crois que je suis la seule\n"
	.string "personne ici qui, pour une raison\p"
	.string "inconnue, préférerait pêcher plutôt\n"
	.string "que se battre. Hein? Vous ne pouvez\p"
	.string "rien attraper ici ? C'est\n"
	.string "décevant…$"

BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol:
	.string "Aujourd'hui, je vais continuer à me\n"
	.string "battre, quoi qu'il arrive, jusqu'à\p"
	.string "ce que j'obtienne un Symbole.$"

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome:
	.string "Oh? Vous partez défier le BATTLE\n"
	.string "DOME ? Je vous souhaite bonne\p"
	.string "chance. Gagnons tous les deux notre\n"
	.string "chemin et relevons les défis.$"

BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa:
	.string "Grand-père, par ici ! Le BATTLE\n"
	.string "DOME est là ! Va les chercher,\p"
	.string "grand-père !$"

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe:
	.string "Ah, alors voici le BATTLE DOME ? Je\n"
	.string "ne laisserai pas GENTLEMEN me\p"
	.string "battre ! Mais où est l'entrée ?$"

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo:
	.string "Il n’y a pas si longtemps, il n’y\n"
	.string "avait rien ici. Mais maintenant,\p"
	.string "regardez cet endroit ! Incroyable!\n"
	.string "Je vais amener ma mère voir ça.$"

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier:
	.string "Je suis enfin arrivé à ZONE DE\n"
	.string "COMBAT ! Je suis sûr d'attirer\p"
	.string "l'attention avec mon apparence et\n"
	.string "mes capacités !$"

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople:
	.string "Grignotez, mâchez… On dirait que\n"
	.string "cette place est remplie de gens\p"
	.string "coriaces. Grignoter, grignoter…$"

BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike:
	.string "Croquez, grignotez… Il y a quelque\n"
	.string "temps, j'ai rencontré cette fille\p"
	.string "plus âgée au BATTLE PIKE. Elle\n"
	.string "avait des yeux vraiment effrayants\p"
	.string "et méchants. Croquant, grignotant…\n"
	.string "Elle était toute furieuse : “\p"
	.string "Veux-tu arrêter de manger ! Puis\n"
	.string "elle s'est jetée sur moi. C’était\p"
	.string "une sorte d’expérience effrayante,\n"
	.string "bien sûr. Croquer, grignoter…$"

BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet:
	.string "Hein? Allez-vous vous écouter ? Ce\n"
	.string "n'est rien! Eh bien, la dernière\p"
	.string "fois que je l'ai encouragé, nos\n"
	.string "regards se sont croisés et des\p"
	.string "étincelles ont volé !$"

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering:
	.string "Quoi ?! Pfff ! Cela n’est arrivé\n"
	.string "que parce que j’étais assis à côté\p"
	.string "de toi ! Le DOME ACE a regardé dans\n"
	.string "notre direction uniquement parce\p"
	.string "que mes applaudissements étaient si\n"
	.string "forts !$"

BattleFrontier_OutsideWest_Text_DomeAceIsMine:
	.string "Oh, chut ! Arrêtez ce vacarme !\n"
	.string "Vous, les fans du beau temps,\p"
	.string "devriez vous contenter d’encourager\n"
	.string "certains GYM LEADER ! Le DOME ACE\p"
	.string "est à moi ! La seule idole pour moi\n"
	.string "!$"

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers:
	.string "Ces gens qui se chamaillent là-bas…\n"
	.string "C'est difficile à croire, mais ils\p"
	.string "étaient autrefois des\n"
	.string "FORMATTHIEUEURS, et de bons aussi.\p"
	.string "Ils étaient incroyablement durs et\n"
	.string "ils étaient aussi célèbres. Mais\p"
	.string "ils ont été anéantis par ce certain\n"
	.string "DRESSEUR lors d'un tournoi. Ils ont\p"
	.string "été si soigneusement fouettés\n"
	.string "qu'ils ont été frappés par\p"
	.string "l'DRESSEUR. Maintenant, ils ne sont\n"
	.string "que des fans du DRESSEUR. Ils vont\p"
	.string "désormais encourager leur idole au\n"
	.string "BATTLE DOME tous les jours.$"

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier:
	.string "J'ai entendu une rumeur selon\n"
	.string "laquelle quelqu'un aurait vu un\p"
	.string "POKéMON avec une queue\n"
	.string "inhabituellement longue quelque\p"
	.string "part dans la ZONE DE COMBAT. Ça\n"
	.string "doit être adorable. J'en suis sûr…\p"
	.string "Oh, les défis peuvent attendre. Je\n"
	.string "me sens déterminé à trouver la\p"
	.string "charmante créature !$"
