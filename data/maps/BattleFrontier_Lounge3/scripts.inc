BattleFrontier_Lounge3_MapScripts::
	.byte 0

	.set BET_AMOUNT_5,  5
	.set BET_AMOUNT_10, 10
	.set BET_AMOUNT_15, 15

BattleFrontier_Lounge3_EventScript_Gambler::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_GAMBLER, BattleFrontier_Lounge3_EventScript_AlreadyMetGambler
	call BattleFrontier_Lounge3_EventScript_CountSilverSymbols
	goto_if_le VAR_0x8004, 2, BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols
	setflag FLAG_MET_BATTLE_FRONTIER_GAMBLER
	msgbox BattleFrontier_Lounge3_Text_YouLookToughExplainGambling, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_AskToEnterChallenge::
	special ShowFrontierGamblerLookingMessage
	waitmessage
	waitbuttonpress
	msgbox BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	msgbox BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	special ShowBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_ChooseBetAmount::
	multichoice 20, 4, MULTI_FRONTIER_GAMBLER_BET, FALSE
	copyvar VAR_FRONTIER_GAMBLER_AMOUNT_BET, VAR_RESULT
	switch VAR_RESULT
	case FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_Bet5
	case FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_Bet10
	case FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_Bet15
	case FRONTIER_GAMBLER_BET_CANCEL, BattleFrontier_Lounge3_EventScript_CancelBet
	case MULTI_B_PRESSED, BattleFrontier_Lounge3_EventScript_CancelBet
	end

BattleFrontier_Lounge3_EventScript_Bet5::
	setvar VAR_0x8008, BET_AMOUNT_5
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet10::
	setvar VAR_0x8008, BET_AMOUNT_10
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet15::
	setvar VAR_0x8008, BET_AMOUNT_15
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_TryPlaceBet::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge3_EventScript_PlaceBet
	msgbox BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints, MSGBOX_DEFAULT
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_PlaceBet::
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_Lounge3_Text_ThanksOffYouGo, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FinishBet
	end

BattleFrontier_Lounge3_EventScript_FinishBet::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge3_EventScript_CountSilverSymbols::
	setvar VAR_0x8004, 0
	call_if_set FLAG_SYS_TOWER_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_DOME_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PALACE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_ARENA_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_FACTORY_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PIKE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PYRAMID_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	return

BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount::
	addvar VAR_0x8004, 1
	return

BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols::
	msgbox BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_AlreadyMetGambler::
	msgbox BattleFrontier_Lounge3_Text_Oh, MSGBOX_DEFAULT
	goto_if_ge VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_CheckBetResults
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_CheckBetResults::
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WON, BattleFrontier_Lounge3_EventScript_WonChallenge
	goto BattleFrontier_Lounge3_EventScript_LostChallenge
	end

BattleFrontier_Lounge3_EventScript_WonChallenge::
	msgbox BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints, MSGBOX_DEFAULT
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_RewardBet5
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_RewardBet10
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_RewardBet15
	msgbox BattleFrontier_Lounge3_Text_ObtainedBattlePoints, MSGBOX_GETPOINTS
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_LostChallenge::
	msgbox BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_RewardBet5::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_5 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_5 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet10::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_10 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_10 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet15::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_15 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_15 * 2)
	return

BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge3_EventScript_DeclineChallenge::
	msgbox BattleFrontier_Lounge3_Text_NotInterested, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge3_EventScript_CancelBet::
	special CloseBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_DeclineChallenge
	end

BattleFrontier_Lounge3_EventScript_Man::
	msgbox BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges, MSGBOX_NPC
	end

BattleFrontier_Lounge3_EventScript_Woman::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_BackedWrongTrainer, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FatMan::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_TrainerGoodButRattled, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere::
	.string "… Qu'est-ce que tu veux ? Ne\n"
	.string "vois-tu pas que nous sommes plutôt\p"
	.string "occupés ici ? Votre entreprise ne\n"
	.string "peut-elle pas attendre plus tard ?$"

BattleFrontier_Lounge3_Text_YouLookToughExplainGambling::
	.string "…Hein? Vous me ressemblez comme un\n"
	.string "DRESSEUR coriace. Heheh… Écoute,\p"
	.string "j'ai cette proposition. Nous avons\n"
	.string "un petit groupe ici, et nous jouons\p"
	.string "à un petit jeu avec ce qui se passe\n"
	.string "dans ZONE DE COMBAT. Les règles\p"
	.string "sont vraiment simples. Tout\n"
	.string "d’abord, nous choisissons l’une des\p"
	.string "installations de ZONE DE COMBAT.\n"
	.string "Ensuite, nous choisissons chacun un\p"
	.string "DRESSEUR différent qui relève le\n"
	.string "défi de cette installation et\p"
	.string "parions avec nos Battle Points. Le\n"
	.string "gars qui a parié sur l'DRESSEUR\p"
	.string "avec le meilleur bilan remporte\n"
	.string "tous les Battle Points de la\p"
	.string "cagnotte. Cela semble simple, hein\n"
	.string "? Alors, de toute façon…$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerSingle::
	.string "Ce que je recherche, c'est un\n"
	.string "DRESSEUR qui va défier les SALLES\p"
	.string "DE COMBAT UNIQUES de la BATTLE\n"
	.string "TOWER. Mais jusqu’à présent, je\p"
	.string "n’ai pas vu d’DRESSEUR possédant\n"
	.string "cette qualité gagnante.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerDouble::
	.string "Ce que je recherche, c'est un\n"
	.string "DRESSEUR qui va défier les DOUBLE\p"
	.string "SALLES DE COMBAT de la BATTLE\n"
	.string "TOWER. Mais jusqu’à présent, je\p"
	.string "n’ai pas vu d’DRESSEUR possédant\n"
	.string "cette qualité gagnante.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerMulti::
	.string "Ce que je recherche, c'est un\n"
	.string "DRESSEUR qui va défier les MULTI\p"
	.string "SALLES DE COMBAT de la BATTLE\n"
	.string "TOWER. Mais jusqu’à présent, je\p"
	.string "n’ai pas vu d’DRESSEUR possédant\n"
	.string "cette qualité gagnante.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeSingle::
	.string "Ce que je recherche, c'est un\n"
	.string "DRESSEUR qui participera au tournoi\p"
	.string "SINGLE BATTLE du BATTLE DOME. Mais\n"
	.string "jusqu’à présent, je n’ai pas vu\p"
	.string "d’DRESSEUR possédant cette qualité\n"
	.string "gagnante.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeDouble::
	.string "Ce que je recherche, c'est un\n"
	.string "DRESSEUR qui va participer au\p"
	.string "tournoi DOUBLE BATTLE du BATTLE\n"
	.string "DOME. Mais jusqu’à présent, je n’ai\p"
	.string "pas vu d’DRESSEUR possédant cette\n"
	.string "qualité gagnante.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactorySingle::
	.string "Ce que je recherche, c'est un\n"
	.string "DRESSEUR qui participera au tournoi\p"
	.string "Battle Swap Single Tourney de\n"
	.string "BATTLE FACTORY. Mais jusqu’à\p"
	.string "présent, je n’ai pas vu d’DRESSEUR\n"
	.string "possédant cette qualité gagnante.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactoryDouble::
	.string "Ce que je recherche, c'est un\n"
	.string "DRESSEUR qui va participer au\p"
	.string "Battle Swap Double Tourney de\n"
	.string "BATTLE FACTORY. Mais jusqu’à\p"
	.string "présent, je n’ai pas vu d’DRESSEUR\n"
	.string "possédant cette qualité gagnante.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceSingle::
	.string "Ce que je recherche, c'est un\n"
	.string "DRESSEUR qui va défier les SALLES\p"
	.string "DE BATAILLE UNIQUES du BATTLE\n"
	.string "PALACE. Mais jusqu’à présent, je\p"
	.string "n’ai pas vu d’DRESSEUR possédant\n"
	.string "cette qualité gagnante.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceDouble::
	.string "Ce que je recherche, c'est un\n"
	.string "DRESSEUR qui va défier les DOUBLE\p"
	.string "SALLES DE COMBAT du BATTLE PALACE.\n"
	.string "Mais jusqu’à présent, je n’ai pas\p"
	.string "vu d’DRESSEUR possédant cette\n"
	.string "qualité gagnante.$"

BattleFrontier_Lounge3_Text_ChallengeBattleArena::
	.string "Ce que je recherche, c'est un\n"
	.string "DRESSEUR qui va participer au\p"
	.string "tournoi Set KO de BATTLE ARENA.\n"
	.string "Mais jusqu’à présent, je n’ai pas\p"
	.string "vu d’DRESSEUR possédant cette\n"
	.string "qualité gagnante.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePike::
	.string "Ce que je recherche, c'est un\n"
	.string "DRESSEUR qui entrera dans le Battle\p"
	.string "Choice de BATTLE PIKE. Mais jusqu’à\n"
	.string "présent, je n’ai pas vu d’DRESSEUR\p"
	.string "possédant cette qualité gagnante.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePyramid::
	.string "Ce que je recherche, c'est un\n"
	.string "DRESSEUR qui va participer à la\p"
	.string "quête de combat de BATTLE PYRAMID.\n"
	.string "Mais jusqu’à présent, je n’ai pas\p"
	.string "vu d’DRESSEUR possédant cette\n"
	.string "qualité gagnante.$"

BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe::
	.string "Je veillerai à ce que vous en\n"
	.string "profitiez également. Et alors ? Que\p"
	.string "diriez-vous de participer à cet\n"
	.string "événement pour moi ?$"

BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints::
	.string "Très bien, c'est parfait. Alors,\n"
	.string "euh… Que diriez-vous de me repérer\p"
	.string "certains de vos Battle Points ?\n"
	.string "Faites-moi confiance, je vous\p"
	.string "montrerai ma gratitude après.$"

BattleFrontier_Lounge3_Text_HowMuchCanYouSpot::
	.string "Bien bien! Alors, à quel point\n"
	.string "pouvez-vous me repérer ?$"

BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints::
	.string "Oh non, non, non ! Vous n'avez pas\n"
	.string "assez de points de combat !\p"
	.string "J'aimerais que tu ne fasses pas de\n"
	.string "singes et que tu ne fasses pas\p"
	.string "perdre le temps à tout le monde !$"

BattleFrontier_Lounge3_Text_ThanksOffYouGo::
	.string "Héhé ! Merci beaucoup! Faites-le,\n"
	.string "c'est parti !$"

BattleFrontier_Lounge3_Text_GetToBattleTowerSingle::
	.string "Rendez-vous pronto dans les SALLES\n"
	.string "DE COMBAT UNIQUES de la BATTLE\p"
	.string "TOWER ! C'est une situation\n"
	.string "incontournable ! Ne gâchez pas\p"
	.string "votre chance ! Notre avenir dépend\n"
	.string "de vous !$"

BattleFrontier_Lounge3_Text_GetToBattleTowerDouble::
	.string "Rendez-vous pronto dans les SALLES\n"
	.string "DE COMBAT DOUBLE DE LA BATTLE TOWER\p"
	.string "! C'est une situation\n"
	.string "incontournable ! Ne gâchez pas\p"
	.string "votre chance ! Notre avenir dépend\n"
	.string "de vous !$"

BattleFrontier_Lounge3_Text_GetToBattleTowerMulti::
	.string "Rendez-vous immédiatement dans les\n"
	.string "SALLES DE COMBAT MULTIPLES de la\p"
	.string "BATTLE TOWER ! C'est une situation\n"
	.string "incontournable ! Ne gâchez pas\p"
	.string "votre chance ! Notre avenir dépend\n"
	.string "de vous !$"

BattleFrontier_Lounge3_Text_GetToBattleDomeSingle::
	.string "Rendez-vous pronto au tournoi\n"
	.string "SINGLE BATTLE du BATTLE DOME !\p"
	.string "C'est une situation incontournable\n"
	.string "! Ne gâchez pas votre chance !\p"
	.string "Notre avenir dépend de vous !$"

BattleFrontier_Lounge3_Text_GetToBattleDomeDouble::
	.string "Rendez-vous pronto au DOUBLE BATTLE\n"
	.string "Tourney du BATTLE DOME ! C'est une\p"
	.string "situation incontournable ! Ne\n"
	.string "gâchez pas votre chance ! Notre\p"
	.string "avenir dépend de vous !$"

BattleFrontier_Lounge3_Text_GetToBattleFactorySingle::
	.string "Accédez pronto au Battle Swap\n"
	.string "Single Tourney de BATTLE FACTORY !\p"
	.string "C'est une situation incontournable\n"
	.string "! Ne gâchez pas votre chance !\p"
	.string "Notre avenir dépend de vous !$"

BattleFrontier_Lounge3_Text_GetToBattleFactoryDouble::
	.string "Accédez pronto au Battle Swap\n"
	.string "Double Tourney de BATTLE FACTORY !\p"
	.string "C'est une situation incontournable\n"
	.string "! Ne gâchez pas votre chance !\p"
	.string "Notre avenir dépend de vous !$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceSingle::
	.string "Rendez-vous pronto dans les SALLES\n"
	.string "DE COMBAT UNIQUES du BATTLE PALACE\p"
	.string "! C'est une situation\n"
	.string "incontournable ! Ne gâchez pas\p"
	.string "votre chance ! Notre avenir dépend\n"
	.string "de vous !$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceDouble::
	.string "Rendez-vous pronto dans les DOUBLE\n"
	.string "SALLES DE COMBAT du BATTLE PALACE !\p"
	.string "C'est une situation incontournable\n"
	.string "! Ne gâchez pas votre chance !\p"
	.string "Notre avenir dépend de vous !$"

BattleFrontier_Lounge3_Text_GetToBattleArena::
	.string "Rendez-vous pronto au Set KO\n"
	.string "Tourney de BATTLE ARENA ! C'est une\p"
	.string "situation incontournable ! Ne\n"
	.string "gâchez pas votre chance ! Notre\p"
	.string "avenir dépend de vous !$"

BattleFrontier_Lounge3_Text_GetToBattlePike::
	.string "Accédez pronto au Battle Choice de\n"
	.string "BATTLE PIKE ! C'est une situation\p"
	.string "incontournable ! Ne gâchez pas\n"
	.string "votre chance ! Notre avenir dépend\p"
	.string "de vous !$"

BattleFrontier_Lounge3_Text_GetToBattlePyramid::
	.string "Accédez pronto à la quête de combat\n"
	.string "de BATTLE PYRAMID ! C'est une\p"
	.string "situation incontournable ! Ne\n"
	.string "gâchez pas votre chance ! Notre\p"
	.string "avenir dépend de vous !$"

BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints::
	.string "Oh, c'est toi… Bien essayé… Je\n"
	.string "déteste te l'annoncer, mais je ne\p"
	.string "peux pas te rendre tes points de\n"
	.string "combat… Je suppose que nous devrons\p"
	.string "laisser cela nous motiver à faire\n"
	.string "plus d'efforts la prochaine fois !$"

BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints::
	.string "Oh oui! Bonjour, champion ! Je\n"
	.string "savais que tu pouvais ! Je savais\p"
	.string "que tu le ferais ! Nous sommes tous\n"
	.string "les deux de grands gagnants ! Je\p"
	.string "vous rendrai vos Battle Points et,\n"
	.string "bien sûr, un petit extra de ma part\p"
	.string "!$"

BattleFrontier_Lounge3_Text_ObtainedBattlePoints::
	.string "{PLAYER} a obtenu {STR_VAR_1} points de\n"
	.string "bataille.$"

BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge::
	.string "Si vous êtes prêt à relever un\n"
	.string "autre défi, pensez à moi !$"

BattleFrontier_Lounge3_Text_NotInterested::
	.string "Pas intéressé?! Vous ne devriez pas\n"
	.string "avoir si peur de tenter votre\p"
	.string "chance !$"

BattleFrontier_Lounge3_Text_Oh::
	.string "Ah…$"

BattleFrontier_Lounge3_Text_BackedWrongTrainer::
	.string "J'ai encore soutenu le mauvais\n"
	.string "DRESSEUR ! Peut-être que je devrais\p"
	.string "me battre normalement comme tout le\n"
	.string "monde…$"

BattleFrontier_Lounge3_Text_TrainerGoodButRattled::
	.string "Cet DRESSEUR… Il est bon, mais il\n"
	.string "se laisse ébranler trop facilement\p"
	.string "pour survivre au BATTLE DOME…$"

BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne::
	.string "Pouffer de rire! Je reconnais un\n"
	.string "gagnant quand j'en vois un !$"

BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges::
	.string "Ces FORMATTHIEUEURS… Que font-ils ?\n"
	.string "Ils devraient relever des défis.$"
