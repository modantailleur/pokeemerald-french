BattleFrontier_Lounge2_MapScripts::
	.byte 0

@ This NPC gives hints about a random facility or battle mode.
@ For battle modes he gives generic advice
@ For facilities, depending on how far the player has progressed he will say either
@    The name of the Frontier Brain there
@    The type and description of the 3 pokemon they use in their silver battle
@    The type and description of the 3 pokemon they use in their gold battle
BattleFrontier_Lounge2_EventScript_FrontierManiac::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_MANIAC, BattleFrontier_Lounge2_EventScript_AlreadyMetManiac
	setflag FLAG_MET_BATTLE_FRONTIER_MANIAC
	msgbox BattleFrontier_Lounge2_Text_FrontierManiacIntro, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_AlreadyMetManiac::
	msgbox BattleFrontier_Lounge2_Text_SwingByForTheLatestWord, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_GiveAdvice::
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_SINGLES, BattleFrontier_Lounge2_EventScript_BufferSingle
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_DOUBLES, BattleFrontier_Lounge2_EventScript_BufferDouble
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_MULTIS, BattleFrontier_Lounge2_EventScript_BufferMulti
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BufferMultiLink
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_BufferBattleDome
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_FACTORY, BattleFrontier_Lounge2_EventScript_BufferBattleFactory
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PALACE, BattleFrontier_Lounge2_EventScript_BufferBattlePalace
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_ARENA, BattleFrontier_Lounge2_EventScript_BufferBattleArena
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PIKE, BattleFrontier_Lounge2_EventScript_BufferBattlePike
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PYRAMID, BattleFrontier_Lounge2_EventScript_BufferBattlePyramid
@ <= FRONTIER_MANIAC_TOWER_LINK is any Battle Tower mode
	call_if_le VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BattleTowerNews
@ >= FRONTIER_MANIAC_DOME is any facility other than Battle Tower
	call_if_ge VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_FacilityNews
	special ShowFrontierManiacMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge2_EventScript_BattleTowerNews::
	msgbox BattleFrontier_Lounge2_Text_BattleTowerIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_FacilityNews::
	msgbox BattleFrontier_Lounge2_Text_FacilityIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_BufferSingle::
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	return

BattleFrontier_Lounge2_EventScript_BufferDouble::
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	return

BattleFrontier_Lounge2_EventScript_BufferMulti::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
	return

BattleFrontier_Lounge2_EventScript_BufferMultiLink::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
	return

BattleFrontier_Lounge2_EventScript_BufferBattleDome::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_DOME
	return

BattleFrontier_Lounge2_EventScript_BufferBattleFactory::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_FACTORY
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePalace::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PALACE
	return

BattleFrontier_Lounge2_EventScript_BufferBattleArena::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_ARENA
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePike::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PIKE
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePyramid::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PYRAMID
	return

BattleFrontier_Lounge2_EventScript_Maniac1::
	lock
	msgbox BattleFrontier_Lounge2_Text_NewsGatheringPower, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowersOfObservation, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac3::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_TriathleteF::
	msgbox BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe, MSGBOX_NPC
	end

BattleFrontier_Lounge2_Text_FrontierManiacIntro::
	.string "Salut! En ce qui concerne les\n"
	.string "nouvelles concernant ZONE DE\p"
	.string "COMBAT, je suis non. 1. Vous pouvez\n"
	.string "me considérer comme le FRONTIER\p"
	.string "MANIAC. Je vérifie, mais vous êtes\n"
	.string "un FORMATTHIEUEUR, n'est-ce pas ?\p"
	.string "Je partagerai avec plaisir les\n"
	.string "nouvelles les plus chaudes que j'ai\p"
	.string "recueillies sur ZONE DE COMBAT.$"

BattleFrontier_Lounge2_Text_SwingByForTheLatestWord::
	.string "Salut! Êtes-vous passé me demander\n"
	.string "le dernier mot ? Oh, d'accord !$"

@ Unused
BattleFrontier_Lounge2_Text_MyInformationsBeenUsefulRight::
	.string "Bien? Bien? Bien? Je suis sûr que\n"
	.string "mes informations vous ont été très\p"
	.string "utiles, n'est-ce pas ?$"

BattleFrontier_Lounge2_Text_FacilityIsHottest::
	.string "Voyons voir maintenant… Il semble\n"
	.string "que le {STR_VAR_1} soit l'endroit le\p"
	.string "plus chaud.$"

BattleFrontier_Lounge2_Text_BattleTowerIsHottest::
	.string "Voyons voir maintenant… Il semble\n"
	.string "que BATTLE TOWER {STR_VAR_1} soit le\p"
	.string "plus chaud.$"

BattleFrontier_Lounge2_Text_SalonMaidenIsThere::
	.string "Je parie que vous ne le saviez pas\n"
	.string "! L'un de ces meilleurs\p"
	.string "FORMATTHIEUEURS que SCOTT appelle\n"
	.string "les FRONTIER BRAINS est là. C'est\p"
	.string "ce mystérieux DRESSEUR appelé SALON\n"
	.string "MAIDEN qui dirige les lieux.$"

BattleFrontier_Lounge2_Text_SalonMaidenSilverMons::
	.string "Avez-vous combattu le SALON MAIDEN\n"
	.string "? Lorsqu'elle mesure son\p"
	.string "adversaire, elle utilise\n"
	.string "apparemment ces POKéMON : UN\p"
	.string "POKéMON PSI de type PSYCHIQUE, un\n"
	.string "POKéMON VOLCAN de type FEU et un\p"
	.string "POKéMON SOMMEIL de type NORMAL.$"

BattleFrontier_Lounge2_Text_SalonMaidenGoldMons::
	.string "Avez-vous combattu la SALON MAIDEN\n"
	.string "quand elle est sérieuse ?\p"
	.string "Lorsqu'elle se bat à fond, elle\n"
	.string "utilise apparemment ces POKéMON :\p"
	.string "UN POKéMON EON DRAGON GUIDO\n"
	.string "PSYCHIQUE, un POKéMON THUNDER de\p"
	.string "type ÉLECTRIQUE et un POKéMON\n"
	.string "SOMMEIL de type NORMAL.$"

BattleFrontier_Lounge2_Text_DomeAceIsThere::
	.string "Je parie que vous ne le saviez pas\n"
	.string "! L'un de ces meilleurs\p"
	.string "FORMATTHIEUEURS que SCOTT appelle\n"
	.string "les FRONTIER BRAINS est là. C'est\p"
	.string "ce flamboyant DRESSEUR appelé le\n"
	.string "DOME ACE qui gère les lieux.$"

BattleFrontier_Lounge2_Text_DomeAceSilverMons::
	.string "Avez-vous combattu le DOME ACE ?\n"
	.string "Lorsqu'il traite l'adversaire à la\p"
	.string "légère, il utilise ces trois\n"
	.string "POKéMON : UN POKéMON DRAGON GUIDO\p"
	.string "DRAGON VOLANT, un POKéMON POISSON\n"
	.string "EAU GUIDO BOUE SOL et un POKéMON\p"
	.string "FEU GUIDO FLAMME VOLANTE.$"

BattleFrontier_Lounge2_Text_DomeAceGoldMons::
	.string "Avez-vous combattu le DOME ACE\n"
	.string "quand il était sérieux ? Lorsqu'il\p"
	.string "démontre sa stratégie, il utilise\n"
	.string "ces trois POKéMON : UN POKéMON\p"
	.string "DRAGON GUIDO EON VOLANT, un POKéMON\n"
	.string "POISSON EAU GUIDO BOUE SOL et un\p"
	.string "POKéMON JAMBE DE FER de type ACIER\n"
	.string "et PSYCHIQUE.$"

BattleFrontier_Lounge2_Text_FactoryHeadIsThere::
	.string "Je parie que vous ne le saviez pas\n"
	.string "! L'un de ces meilleurs\p"
	.string "FORMATTHIEUEURS que SCOTT appelle\n"
	.string "les FRONTIER BRAINS est là. C'est\p"
	.string "cet DRESSEUR bizarre appelé FACTORY\n"
	.string "HEAD qui dirige l'endroit.$"

BattleFrontier_Lounge2_Text_FactoryHeadSilverMons::
	.string "Avez-vous déjà affronté le FACTORY\n"
	.string "HEAD ? Laissez-moi réfléchir… Quand\p"
	.string "il part au combat, il ne reçoit que\n"
	.string "trois POKéMON de location. Il se\p"
	.string "bat à peu près dans les mêmes\n"
	.string "conditions que vous.$"

BattleFrontier_Lounge2_Text_FactoryHeadGoldMons::
	.string "Avez-vous combattu le CHEF D'USINE\n"
	.string "quand il était sérieux ? Lorsqu'il\p"
	.string "se lance sérieusement au combat, il\n"
	.string "obtient toujours trois POKéMON de\p"
	.string "location. Il se bat pratiquement\n"
	.string "dans les mêmes conditions que\p"
	.string "vous.$"

BattleFrontier_Lounge2_Text_PikeQueenIsThere::
	.string "Je parie que vous ne le saviez pas\n"
	.string "! L'un de ces meilleurs\p"
	.string "FORMATTHIEUEURS que SCOTT appelle\n"
	.string "les FRONTIER BRAINS est là. C'est\p"
	.string "cet effrayant DRESSEUR appelé PIKE\n"
	.string "QUEEN qui gère les lieux.$"

BattleFrontier_Lounge2_Text_PikeQueenSilverMons::
	.string "Avez-vous déjà affronté la PIKE\n"
	.string "QUEEN ? Quand elle est de bonne\p"
	.string "humeur, on dit qu'elle utilise ces\n"
	.string "trois POKéMON : UN POKéMON SERPENT\p"
	.string "CROC de type POISON, un POKéMON BUG\n"
	.string "& MOULE ROCK et un POKéMON TENDRE\p"
	.string "de type EAU.$"

BattleFrontier_Lounge2_Text_PikeQueenGoldMons::
	.string "Avez-vous combattu la PIKE QUEEN\n"
	.string "quand elle est sérieuse ?\p"
	.string "Lorsqu'elle est sérieusement\n"
	.string "ennuyée, on dit qu'elle utilise ces\p"
	.string "trois POKéMON : UN POKéMON SERPENT\n"
	.string "À CROQUES de type POISON, un\p"
	.string "POKéMON SERPENT EN ACIER GUIDO FER\n"
	.string "SOL et un POKéMON ATROCIEUX de type\p"
	.string "EAU GUIDO VOL.$"

BattleFrontier_Lounge2_Text_ArenaTycoonIsThere::
	.string "Je parie que vous ne le saviez pas\n"
	.string "! L'un de ces meilleurs\p"
	.string "FORMATTHIEUEURS que SCOTT appelle\n"
	.string "les FRONTIER BRAINS est là. C'est\p"
	.string "ce mignon DRESSEUR appelé ARENA\n"
	.string "TYCOON qui gère les lieux.$"

BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons::
	.string "Avez-vous déjà affronté ARENA\n"
	.string "TYCOON ? Lorsqu'elle évalue les\p"
	.string "capacités de l'ennemi, elle est\n"
	.string "censée utiliser ces POKéMON : UN\p"
	.string "POKéMON BUG & FIGHTING SINGLE HORN,\n"
	.string "un POKéMON MOONLIGHT de type DARK\p"
	.string "et un POKéMON BUG & GHOST SHED.$"

BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons::
	.string "Avez-vous combattu ARENA TYCOON\n"
	.string "quand elle était sérieuse ?\p"
	.string "Lorsqu'elle se bat pour de bon,\n"
	.string "elle est censée utiliser ces\p"
	.string "POKéMON : un POKéMON MOONLIGHT de\n"
	.string "type DARK, un POKéMON GHOST &\p"
	.string "POISON SHADOW et un POKéMON\n"
	.string "CHAMPIGNON de type HERBE et\p"
	.string "COMBAT.$"

BattleFrontier_Lounge2_Text_PalaceMavenIsThere::
	.string "Je parie que vous ne le saviez pas\n"
	.string "! L'un de ces meilleurs\p"
	.string "FORMATTHIEUEURS que SCOTT appelle\n"
	.string "les FRONTIER BRAINS est là. C'est\p"
	.string "ce sinistre DRESSEUR appelé PALACE\n"
	.string "MAVEN qui dirige les lieux.$"

BattleFrontier_Lounge2_Text_PalaceMavenSilverMons::
	.string "Avez-vous déjà combattu le PALACE\n"
	.string "MAVEN ? Lorsqu'il teste l'esprit de\p"
	.string "l'adversaire, on lui dit qu'il\n"
	.string "utilise ces POKéMON : un POKéMON\p"
	.string "BATEAU de type POISON et VOL, un\n"
	.string "POKéMON PARESSEUX de type NORMAL et\p"
	.string "un POKéMON DE TRANSPORT de type EAU\n"
	.string "et GLACIA.$"

BattleFrontier_Lounge2_Text_PalaceMavenGoldMons::
	.string "Avez-vous combattu le PALACE MAVEN\n"
	.string "quand il est sérieux ? Lorsqu'il\p"
	.string "jette toute sa puissance au combat,\n"
	.string "on dit qu'il utilise ces POKéMON :\p"
	.string "UN POKéMON LÉGENDAIRE de type FEU,\n"
	.string "un POKéMON PARESSEUX de type NORMAL\p"
	.string "et un POKéMON AURORA de type EAU.$"

BattleFrontier_Lounge2_Text_PyramidKingIsThere::
	.string "Je parie que vous ne le saviez pas\n"
	.string "! L'un de ces meilleurs\p"
	.string "FORMATTHIEUEURS que SCOTT appelle\n"
	.string "les FRONTIER BRAINS est là. C'est\p"
	.string "cet DRESSEUR enflammé appelé\n"
	.string "PYRAMID KING qui dirige les lieux.$"

BattleFrontier_Lounge2_Text_PyramidKingSilverMons::
	.string "Avez-vous déjà combattu le PYRAMID\n"
	.string "KING ? Lorsqu'il vérifie la\p"
	.string "puissance de l'ennemi, il utilise\n"
	.string "apparemment ces POKéMON : un\p"
	.string "POKéMON ROCK PEAK de type ROCK, un\n"
	.string "POKéMON ICEBERG de type ICE et un\p"
	.string "POKéMON FER de type ACIER.$"

BattleFrontier_Lounge2_Text_PyramidKingGoldMons::
	.string "Avez-vous combattu le PYRAMID KING\n"
	.string "quand il était sérieux ? Lorsqu'il\p"
	.string "est gonflé à bloc, il utilise\n"
	.string "apparemment ces POKéMON : un\p"
	.string "POKéMON GEL GUIDO VOLANT GEL, un\n"
	.string "POKéMON ÉLECTRIQUE GUIDO VOLANT\p"
	.string "ÉLECTRIQUE et un POKéMON FLAMME de\n"
	.string "type FEU GUIDO VOL.$."

BattleFrontier_Lounge2_Text_DoubleBattleAdvice1::
	.string "Bien sûr, il existe plusieurs\n"
	.string "endroits où vous pouvez participer\p"
	.string "à des DOUBLE BATTLES. Mais les\n"
	.string "DOUBLE SALLES DE COMBAT de la\p"
	.string "BATTLE TOWER sont plutôt basiques !\n"
	.string "C'est là que vous devriez apprendre\p"
	.string "comment les COMBATS DOUBLE se\n"
	.string "jouent ici dans ZONE DE COMBAT.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice2::
	.string "Regardez-vous dans les batailles\n"
	.string "ici. J'ai entendu dire qu'il y a\p"
	.string "des DRESSEURS qui ont développé des\n"
	.string "stratégies uniquement pour les\p"
	.string "DOUBLE BATAILLES.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice3::
	.string "Une fois que vous êtes confiant et\n"
	.string "à l'aise avec les DOUBLE BATTLES\p"
	.string "ici, vous devriez penser à défier\n"
	.string "d'autres endroits proposant des\p"
	.string "DOUBLE BATTLES.$"

BattleFrontier_Lounge2_Text_MultiBattleAdvice::
	.string "Toutes sortes d'DRESSEURS se\n"
	.string "rassemblent dans le SALON DE\p"
	.string "COMBAT. Pensez-y : vous pourriez\n"
	.string "rencontrer vos amis ou vos abonnés\p"
	.string "! Vous devriez regarder\n"
	.string "attentivement !$"

BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice::
	.string "Si vous êtes avec un ami,\n"
	.string "dirigez-vous vers le LINK MULTI\p"
	.string "BATTLE ROOM. Si vous jouez avec un\n"
	.string "ami fort, vous pouvez vous attendre\p"
	.string "à rencontrer des ennemis coriaces\n"
	.string "!$"

BattleFrontier_Lounge2_Text_NewsGatheringPower::
	.string "Quelle incroyable puissance de\n"
	.string "collecte d’informations ! Mon\p"
	.string "mentor ne ressemble à aucun autre\n"
	.string "!$"

BattleFrontier_Lounge2_Text_AmazingPowersOfObservation::
	.string "Quelle puissance d’observation\n"
	.string "étonnante ! Mon mentor ne ressemble\p"
	.string "à aucun autre !$"

BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion::
	.string "Quel incroyable pouvoir de\n"
	.string "persuasion ! Mon mentor ne\p"
	.string "ressemble à aucun autre !$"

BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe::
	.string "…Quel est cet endroit? Ça me fait\n"
	.string "peur…$"
