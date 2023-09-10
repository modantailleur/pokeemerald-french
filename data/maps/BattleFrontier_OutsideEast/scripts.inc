.set LOCALID_SUDOWOODO, 14

BattleFrontier_OutsideEast_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_OnTransition
	.byte 0

BattleFrontier_OutsideEast_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

BattleFrontier_OutsideEast_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_ShowSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_ShowSudowoodo::
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
	return

BattleFrontier_OutsideEast_EventScript_BattleTowerSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePalaceSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePalaceSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattleArenaSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleArenaSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePyramidSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePyramidSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_NinjaBoy::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man1::
	msgbox BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Hiker::
	msgbox BattleFrontier_OutsideEast_Text_PyramidTooHarsh, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_HexManiac::
	msgbox BattleFrontier_OutsideEast_Text_ThriveInDarkness, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt1::
	msgbox BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Cook::
	lock
	msgbox BattleFrontier_OutsideEast_Text_BelieveInYouBuddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_OutsideEast_EventScript_RichBoy::
	msgbox BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_ExpertF::
	msgbox BattleFrontier_OutsideEast_Text_OnceBeatGymLeader, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_TriathleteF::
	msgbox BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Twin::
	msgbox BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_TriathleteM::
	msgbox BattleFrontier_OutsideEast_Text_DidScottBringYouHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Sudowoodo::
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	release
	end

BattleFrontier_OutsideEast_EventScript_WaterSudowoodo::
	lock
	faceplayer
	special DoWateringBerryTreeAnim
	waitstate
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	setflag FLAG_DEFEATED_SUDOWOODO
	release
	end

BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo::
	setflag FLAG_DEFEATED_SUDOWOODO
	goto Common_EventScript_RemoveStaticPokemon
	end

BattleFrontier_OutsideEast_Movement_SudowoodoShake:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

BattleFrontier_OutsideEast_EventScript_Maniac1::
	msgbox BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Girl::
	msgbox BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_PsychicM::
	msgbox BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man3::
	msgbox BattleFrontier_OutsideEast_Text_GotWipedOut, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman1::
	msgbox BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman2::
	msgbox BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt2::
	msgbox BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_RankingHallSign::
	msgbox BattleFrontier_OutsideEast_Text_RankingHallSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_ExchangeCornerSign::
	msgbox BattleFrontier_OutsideEast_Text_ExchangeCornerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone
	msgbox BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone::
	msgbox BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Camper::
	msgbox BattleFrontier_OutsideEast_Text_StickyMonWithLongTail, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_Text_BattleTowerSign:
	.string "C'est la TOUR DE BATAILLE !\n"
	.string "Maintenez la séquence de victoires\p"
	.string "en tant qu'DRESSEUR le plus coriace\n"
	.string "!$"

BattleFrontier_OutsideEast_Text_BattlePalaceSign:
	.string "C'est le PALAIS DE BATAILLE !\n"
	.string "Gardez un œil sur les batailles\p"
	.string "POKéMON !$"

BattleFrontier_OutsideEast_Text_BattleArenaSign:
	.string "C'est l'ARÈNE DE COMBAT ! Que les\n"
	.string "équipes les plus coriaces se\p"
	.string "rassemblent !$"

BattleFrontier_OutsideEast_Text_BattlePyramidSign:
	.string "C'est la PYRAMIDE DE BATAILLE !\n"
	.string "Avancez dans la quête de combat !$"

BattleFrontier_OutsideEast_Text_RankingHallSign:
	.string "ZONE DE COMBAT RANKING HALL Visez\n"
	.string "de nouveaux records !$"

BattleFrontier_OutsideEast_Text_ExchangeCornerSign:
	.string "COIN DU SERVICE D'ÉCHANGE DE POINTS\n"
	.string "DE BATAILLE Échangez vos points de\p"
	.string "bataille !$"

BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial:
	.string "Ouah! C'est énorme! La BATTLE TOWER\n"
	.string "est spéciale. C'est différent des\p"
	.string "autres.$"

BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier:
	.string "Ma grande ambition est de conquérir\n"
	.string "à la fois le ZONE DE COMBAT et la\p"
	.string "POKéMON LEAGUE. Et si mon rêve se\n"
	.string "réalise… Je… je vais demander à\p"
	.string "MIMI à côté si elle sera amie avec\n"
	.string "moi !$"

BattleFrontier_OutsideEast_Text_PyramidTooHarsh:
	.string "La PYRAMIDE DE BATAILLE est trop\n"
	.string "dure ! Je n'arrive tout simplement\p"
	.string "pas à atteindre le sommet ! Comme\n"
	.string "je n'ai plus d'options, je peux\p"
	.string "peut-être grimper à l'extérieur…$"

BattleFrontier_OutsideEast_Text_ThriveInDarkness:
	.string "Je m'épanouit dans l'obscurité…\n"
	.string "Oui… Qu'est-ce qui est digne de moi\p"
	.string "? Nul autre que la PYRAMIDE DE\n"
	.string "BATAILLE… Que dites-vous d'errer\p"
	.string "dans l'obscurité et dans un\n"
	.string "désespoir total ?$"

BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam:
	.string "Je n'ai pas dormi pendant une\n"
	.string "semaine, puis j'ai constitué\p"
	.string "l'équipe ultime ! Je ne me vois pas\n"
	.string "perdre, sans blague. Nous prenons\p"
	.string "d'assaut la BATTLE ARENA !$"

BattleFrontier_OutsideEast_Text_DidScottBringYouHere:
	.string "Est-ce que SCOTT vous a amené ici\n"
	.string "aussi ? Qu'est-ce qu'il a avec ce\p"
	.string "type ? On dirait qu'il sait\n"
	.string "vraiment comment repérer des\p"
	.string "DRESSEURS talentueux, mais… je ne\n"
	.string "l'ai jamais vu se battre en\p"
	.string "personne.$"

BattleFrontier_OutsideEast_Text_BelieveInYouBuddy:
	.string "ZIGG ! Je crois en toi, petit\n"
	.string "copain ! Je préparerai à mon petit\p"
	.string "ZIGG toutes les friandises\n"
	.string "préférées que vous aimez si vous\p"
	.string "gagnez !$"

BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant:
	.string "ZIGZAGOON semble vacant…$"

BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody:
	.string "Les gens me traitent de quelqu'un\n"
	.string "de très occupé, mais je n'y peux\p"
	.string "rien. Ton chapeau est de travers !\n"
	.string "Oh non, des déchets par terre !\p"
	.string "Oups, c'est presque l'heure du\n"
	.string "dîner ! Je ne sais pas si je peux\p"
	.string "supporter de regarder au BATTLE\n"
	.string "PALACE…$"

BattleFrontier_OutsideEast_Text_OnceBeatGymLeader:
	.string "Je n’ai peut-être pas l’air si\n"
	.string "impressionnant maintenant, mais\p"
	.string "j’ai déjà battu un GYM LEADER. Qui\n"
	.string "sait, peut-être que je devrais lui\p"
	.string "donner une autre chance de gloire.$"

BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles:
	.string "Je suis rapide sur mon VÉLO, et\n"
	.string "cela vaut aussi pour ma façon de me\p"
	.string "battre. Je gagne des matchs en un\n"
	.string "clin d'œil !$"

BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon:
	.string "Je suis meilleur que mon père chez\n"
	.string "POKéMON.$"

BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy:
	.string "Vas-y, mon bébé chéri ! Allez\n"
	.string "accumuler des victoires pour papa !\p"
	.string "Tu es comme ta mère, donc tu\n"
	.string "domineras !$"

BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena:
	.string "Ce n'était pas facile d'arriver\n"
	.string "ici, mais j'avais entendu parler de\p"
	.string "cette jolie fille au BATTLE ARENA.\n"
	.string "A sa place, tu sais ce que j'ai\p"
	.string "trouvé ? Toute une foule d'artistes\n"
	.string "martiaux en sueur, puants et\p"
	.string "primitifs !$"

BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere:
	.string "Je vois parfois ce vieil homme à\n"
	.string "l'air vraiment important entrer\p"
	.string "là-dedans. Il a ces POKéMON\n"
	.string "vraiment géniaux. Mais il a l'air\p"
	.string "vraiment sympa.$"

BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid:
	.string "Le savez-vous ? La légende de la\n"
	.string "PYRAMIDE DE BATAILLE ? Quand un\p"
	.string "DRESSEUR confiant viendra atteindre\n"
	.string "le sommet d’or, un homme parmi les\p"
	.string "hommes apparaîtra. Vous ne\n"
	.string "connaissez pas cette légende ? Eh\p"
	.string "bien, bien sûr que non ! Je viens\n"
	.string "de l'inventer ! Qu'est-ce que ça\p"
	.string "veut dire ? Ça, mon ami, je ne peux\n"
	.string "pas le dire !$"

BattleFrontier_OutsideEast_Text_GotWipedOut:
	.string "Homme! Oh mec ! Je n'ai jamais\n"
	.string "perdu une seule fois auparavant !\p"
	.string "Mais j’ai été anéanti sans aucune\n"
	.string "grâce salvatrice ! Et puis on me\p"
	.string "dit que je n'ai aucun talent ?! Mec\n"
	.string "!$"

BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower:
	.string "Ce type est tombé sur un DRESSEUR\n"
	.string "horriblement coriace alors qu'il\p"
	.string "participait au défi BATTLE TOWER.\n"
	.string "Maintenant, regardez-le… Vous devez\p"
	.string "être prudent si jamais vous décidez\n"
	.string "d'aller à la BATTLE TOWER.$"

BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll:
	.string "Oui! J'ai enfin assez de points de\n"
	.string "combat ! Je suppose que je vais\p"
	.string "l'échanger contre une autre POUPÉE\n"
	.string "géante en peluche !$"

BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere:
	.string "Oh, ouais, d'accord ! Voici donc le\n"
	.string "SALLE DE CLASSEMENT ! J'aimerais\p"
	.string "entrer dans l'histoire en tant que\n"
	.string "super champion et que mon nom soit\p"
	.string "enregistré ici pour la postérité.$"

BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou:
	.string "Avec toi à mes côtés, je peux tout\n"
	.string "faire.$"

BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome:
	.string "Ooh, chérie, tu es si merveilleuse\n"
	.string "! Ooh, je ne peux plus attendre !\p"
	.string "Allons dans une SALLE DE COMBAT\n"
	.string "MULTI dès maintenant ! Si nous nous\p"
	.string "réunissons au BATTLE SALON, la\n"
	.string "puissance de notre amour vaincra\p"
	.string "tous ceux que nous rencontrons. Eh\n"
	.string "bien, devant nous, chérie, tout va\p"
	.string "basculer comme des dominos !$"

BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers:
	.string "Le ZONE DE COMBAT n'est pas réservé\n"
	.string "exclusivement aux DRESSEURs\p"
	.string "coriaces. De nombreuses personnes\n"
	.string "dotées de capacités spéciales ont\p"
	.string "été invitées, semble-t-il. Cet\n"
	.string "homme SCOTT… Il a peut-être\p"
	.string "construit cet endroit pour servir\n"
	.string "un objectif plus grand…$"

BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle:
	.string "Excusez-moi, mon jeune. Avez-vous\n"
	.string "une bonne vue ? Il y a un arbre\p"
	.string "étrange par ici, et à mes yeux\n"
	.string "fatigués, il semble bouger.$"

BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere:
	.string "Excusez-moi, mon jeune. Avez-vous\n"
	.string "une bonne mémoire ? J'ai\p"
	.string "l'impression qu'il y avait\n"
	.string "autrefois un arbre étrange par\p"
	.string "ici.$"

BattleFrontier_OutsideEast_Text_StickyMonWithLongTail:
	.string "Je… je l'ai vu ! Il y avait une\n"
	.string "sorte de POKéMON collant avec une\p"
	.string "longue queue devant ! Il se cachait\n"
	.string "sous un rocher et il n'arrêtait pas\p"
	.string "de me regarder !$"
