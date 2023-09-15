.set LOCALID_GREETER, 1
.set LOCALID_GUIDE, 2
.set LOCALID_SCOTT, 4

BattleFrontier_ReceptionGate_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_ReceptionGate_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_ReceptionGate_OnTransition
	.byte 0

BattleFrontier_ReceptionGate_OnTransition:
	setflag FLAG_LANDMARK_BATTLE_FRONTIER
	end

BattleFrontier_ReceptionGate_OnFrame:
	map_script_2 VAR_HAS_ENTERED_BATTLE_FRONTIER, 0, BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering
	.2byte 0

BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering::
	lockall
	setvar VAR_HAS_ENTERED_BATTLE_FRONTIER, 1
	playse SE_PIN
	applymovement LOCALID_GREETER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_GREETER, Common_Movement_Delay48
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter
	waitmovement 0
	goto BattleFrontier_ReceptionGate_EventScript_ScottScene
	end

BattleFrontier_ReceptionGate_EventScript_ScottScene::
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IssueFrontierPass, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass
	waitfanfare
	waitmessage
	msgbox BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass, MSGBOX_DEFAULT
	setflag FLAG_SYS_FRONTIER_PASS
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GREETER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_GUIDE, Common_Movement_WalkInPlaceFasterUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_GREETER, Common_Movement_ExclamationMark
	applymovement LOCALID_GUIDE, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GREETER, BattleFrontier_ReceptionGate_Movement_GreeterFaceScott
	applymovement LOCALID_GUIDE, BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerFaceScott
	applymovement LOCALID_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottEnter
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_SCOTT
	releaseall
	end

BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter:
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_PlayerFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

@ Unused
BattleFrontier_ReceptionGate_Movement_WalkDown:
	walk_down
	walk_down
	step_end

BattleFrontier_ReceptionGate_Movement_ScottEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_ScottExit:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_ReceptionGate_Movement_GreeterFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

BattleFrontier_ReceptionGate_EventScript_Greeter::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FacilityGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFacilities, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich2
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BF_RECEPTIONIST
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_BattleTower
	case 1, BattleFrontier_ReceptionGate_EventScript_BattleDome
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePalace
	case 3, BattleFrontier_ReceptionGate_EventScript_BattleArena
	case 4, BattleFrontier_ReceptionGate_EventScript_BattleFactory
	case 5, BattleFrontier_ReceptionGate_EventScript_BattlePike
	case 6, BattleFrontier_ReceptionGate_EventScript_BattlePyramid
	case 7, BattleFrontier_ReceptionGate_EventScript_RankingHall
	case 8, BattleFrontier_ReceptionGate_EventScript_ExchangeCorner
	case 9, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	end

BattleFrontier_ReceptionGate_EventScript_BattleTower::
	msgbox BattleFrontier_ReceptionGate_Text_BattleTowerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleDome::
	msgbox BattleFrontier_ReceptionGate_Text_BattleDomeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePalace::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePalaceInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleArena::
	msgbox BattleFrontier_ReceptionGate_Text_BattleArenaInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleFactory::
	msgbox BattleFrontier_ReceptionGate_Text_BattleFactoryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePike::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePikeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePyramid::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePyramidInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RankingHall::
	msgbox BattleFrontier_ReceptionGate_Text_RankingHallInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExchangeCorner::
	msgbox BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_RulesGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToRules, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhat
	waitmessage
	multichoice 15, 0, MULTI_FRONTIER_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_LevelMode
	case 1, BattleFrontier_ReceptionGate_EventScript_Level50
	case 2, BattleFrontier_ReceptionGate_EventScript_OpenLevel
	case 3, BattleFrontier_ReceptionGate_EventScript_MonEntry
	case 4, BattleFrontier_ReceptionGate_EventScript_HoldItems
	case 5, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	end

BattleFrontier_ReceptionGate_EventScript_LevelMode::
	msgbox BattleFrontier_ReceptionGate_Text_LevelModeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_Level50::
	msgbox BattleFrontier_ReceptionGate_Text_Level50Info, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_OpenLevel::
	msgbox BattleFrontier_ReceptionGate_Text_OpenLevelInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_MonEntry::
	msgbox BattleFrontier_ReceptionGate_Text_MonEntryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_HoldItems::
	msgbox BattleFrontier_ReceptionGate_Text_HoldItemsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FrontierPassGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich1
	waitmessage
	multichoice 16, 4, MULTI_FRONTIER_PASS_INFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_Symbols
	case 1, BattleFrontier_ReceptionGate_EventScript_RecordBattle
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePoints
	case 3, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	end

BattleFrontier_ReceptionGate_EventScript_Symbols::
	msgbox BattleFrontier_ReceptionGate_Text_SymbolsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RecordBattle::
	msgbox BattleFrontier_ReceptionGate_Text_RecordedBattleInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePoints::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePointsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay:
	.string "Est-ce votre première fois ici ?\n"
	.string "S'il vous plaît, passez par là !$"

BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier:
	.string "Les premières lignes des combats\n"
	.string "POKéMON ! Bienvenue à la ZONE DE\p"
	.string "COMBAT !$"

BattleFrontier_ReceptionGate_Text_IssueFrontierPass:
	.string "Pour un premier visiteur, nous\n"
	.string "délivrons le FRONTIER PASS. Il est\p"
	.string "destiné à être utilisé dans toutes\n"
	.string "les installations de ZONE DE\p"
	.string "COMBAT. Vous y êtes !$"

BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass:
	.string "{PLAYER} a obtenu le FRONTIER PASS.$"

BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass:
	.string "{PLAYER} a placé la CARTE D'DRESSEUR\n"
	.string "dans le PASS FRONTIÈRE.$"

BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier:
	.string "Nous espérons que vous apprécierez\n"
	.string "tout ce que ZONE DE COMBAT a à\p"
	.string "offrir !$"

BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame:
	.string "??? : Eh bien, si ce n'est pas\n"
	.string "{PLAYER}{KUN} ! Vous êtes venu ici\p"
	.string "!$"

BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay:
	.string "GUIDE : Oh ! M. SCOTT, monsieur !\n"
	.string "Bonne journée à vous, monsieur !$"

BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere:
	.string "SCOTT : C'est génial de vous voir\n"
	.string "ici, c'est vraiment le cas !\p"
	.string "J'espère que vous prendrez votre\n"
	.string "temps et explorerez partout.\p"
	.string "Naturellement, j’espère que vous\n"
	.string "ferez également l’expérience de la\p"
	.string "pure essence du combat. J'ai aussi\n"
	.string "mes quartiers ici, alors n'hésitez\p"
	.string "pas à venir me rendre visite si\n"
	.string "vous avez le temps.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFacilities:
	.string "Je suis votre guide pour les\n"
	.string "différentes installations de ZONE\p"
	.string "DE COMBAT.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich2:
	.string "Sur quoi aimeriez-vous en savoir\n"
	.string "plus ?$"

BattleFrontier_ReceptionGate_Text_BattleTowerInfo:
	.string "C'est la tour gigantesque\n"
	.string "considérée comme le symbole de ZONE\p"
	.string "DE COMBAT. Il existe quatre types\n"
	.string "de SALLES DE COMBAT dans la tour\p"
	.string "pour les COMBATS SIMPLES, DOUBLE,\n"
	.string "MULTI et LINK MULTI.$"

BattleFrontier_ReceptionGate_Text_BattleDomeInfo:
	.string "Le BATTLE DOME est le grand\n"
	.string "bâtiment en forme d'œuf énorme. Des\p"
	.string "événements nommés Battle Tourneys\n"
	.string "ont lieu dans cette installation.\p"
	.string "Les tournois de bataille sont\n"
	.string "proposés en deux parcours : pour\p"
	.string "les BATAILLES SIMPLES et DOUBLE.$"

BattleFrontier_ReceptionGate_Text_BattlePalaceInfo:
	.string "Le BATTLE PALACE est le bâtiment\n"
	.string "rouge à droite de ZONE DE COMBAT.\p"
	.string "Il existe deux types de SALLES DE\n"
	.string "BATAILLE pour les BATAILLES SIMPLES\p"
	.string "et DOUBLE.$"

BattleFrontier_ReceptionGate_Text_BattleArenaInfo:
	.string "La BATTLE ARENA est le bâtiment\n"
	.string "semblable à un dojo situé au centre\p"
	.string "droit de ZONE DE COMBAT. Un\n"
	.string "événement appelé Set KO Tourney a\p"
	.string "lieu au BATTLE ARENA.$"

BattleFrontier_ReceptionGate_Text_BattleFactoryInfo:
	.string "La BATTLE FACTORY est le grand\n"
	.string "bâtiment le plus proche de nous. Un\p"
	.string "événement appelé Battle Swap y est\n"
	.string "organisé. L'événement Battle Swap\p"
	.string "est proposé en deux parcours pour\n"
	.string "les BATAILLES SIMPLES et DOUBLE.$"

BattleFrontier_ReceptionGate_Text_BattlePikeInfo:
	.string "Le BATTLE PIKE est le bâtiment en\n"
	.string "forme de POKéMON au centre gauche\p"
	.string "de ZONE DE COMBAT. Un événement\n"
	.string "appelé Battle Choice y est\p"
	.string "organisé.$"

BattleFrontier_ReceptionGate_Text_BattlePyramidInfo:
	.string "La PYRAMIDE DE BATAILLE est\n"
	.string "l’énorme pyramide. Un événement\p"
	.string "appelé Battle Quest y est\n"
	.string "organisé.$"

BattleFrontier_ReceptionGate_Text_RankingHallInfo:
	.string "La SALLE DE CLASSEMENT est située\n"
	.string "près de la TOUR DE BATAILLE. Vous\p"
	.string "pourrez y voir les records les plus\n"
	.string "fantastiques laissés par les\p"
	.string "DRESSEURS qui ont relevé les\n"
	.string "nombreux défis du ZONE DE COMBAT.$"

BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo:
	.string "Le COIN DES SERVICES D’ÉCHANGE se\n"
	.string "trouve à proximité de la TOUR DE\p"
	.string "BATAILLE. Les points de bataille\n"
	.string "que vous avez gagnés dans ZONE DE\p"
	.string "COMBAT peuvent y être échangés\n"
	.string "contre de fabuleux prix.$"

BattleFrontier_ReceptionGate_Text_YourGuideToRules:
	.string "Je suis votre guide des règles de\n"
	.string "base communes à tous les défis\p"
	.string "proposés par les installations de\n"
	.string "ZONE DE COMBAT.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhat:
	.string "Qu’aimeriez-vous apprendre?$"

BattleFrontier_ReceptionGate_Text_LevelModeInfo:
	.string "Tous les défis des installations de\n"
	.string "ZONE DE COMBAT se déclinent en deux\p"
	.string "cours : niveau 50 et niveau\n"
	.string "ouvert.$"

BattleFrontier_ReceptionGate_Text_Level50Info:
	.string "Le cours de niveau 50 est ouvert\n"
	.string "aux POKéMON jusqu'au niveau 50\p"
	.string "inclus. Veuillez toutefois garder à\n"
	.string "l'esprit qu'aucun DRESSEUR que vous\p"
	.string "affronterez n'aura de POKéMON\n"
	.string "inférieur au niveau 50. Ce cours\p"
	.string "est le niveau d'entrée pour les\n"
	.string "batailles à ZONE DE COMBAT. Pour\p"
	.string "commencer, nous espérons que vous\n"
	.string "contesterez ce cours.$"

BattleFrontier_ReceptionGate_Text_OpenLevelInfo:
	.string "Le cours Open Level n'impose aucune\n"
	.string "limite aux niveaux de POKéMON pour\p"
	.string "participer aux défis. Les niveaux\n"
	.string "de vos adversaires seront ajustés\p"
	.string "pour correspondre aux niveaux de\n"
	.string "votre POKéMON. Cependant, aucun\p"
	.string "DRESSEUR que vous affronterez\n"
	.string "n'aura de POKéMON inférieur au\p"
	.string "niveau 60.$"

BattleFrontier_ReceptionGate_Text_MonEntryInfo:
	.string "Pratiquement n'importe quel type de\n"
	.string "POKéMON peut relever les défis dans\p"
	.string "toutes les installations. Les OEUFS\n"
	.string "et certains types de POKéMON ne\p"
	.string "sont cependant pas autorisés. Le\n"
	.string "nombre de POKéMON requis pour les\p"
	.string "défis dépendra de l'installation.\n"
	.string "Cependant, dans toutes les\p"
	.string "installations, deux ou plusieurs\n"
	.string "POKéMON du même type ne sont pas\p"
	.string "autorisés.$"

BattleFrontier_ReceptionGate_Text_HoldItemsInfo:
	.string "Lorsque vous participez à un défi\n"
	.string "dans une installation ZONE DE\p"
	.string "COMBAT, POKéMON peut ne pas\n"
	.string "contenir le même type d'objet.\p"
	.string "Veuillez vous assurer que tous les\n"
	.string "POKéMON participant à un défi\p"
	.string "contiennent des objets différents.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass:
	.string "Je suis votre guide du FRONTIER\n"
	.string "PASS.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich1:
	.string "Sur quoi aimeriez-vous en savoir\n"
	.string "plus ?$"

BattleFrontier_ReceptionGate_Text_SymbolsInfo:
	.string "Il y a sept installations au ZONE\n"
	.string "DE COMBAT. LES DRESSEURS dont\p"
	.string "les capacités sont reconnues\n"
	.string "peuvent être récompensés par des\p"
	.string "symboles de chacune des\n"
	.string "installations. Pour gagner un\p"
	.string "symbole, les DRESSEURS\n"
	.string "devront peut-être vaincre d'autres\p"
	.string "DRESSEURS d'affilée et\n"
	.string "devront peut-être remporter des\p"
	.string "événements à plusieurs reprises. Ce\n"
	.string "n'est certainement pas facile de\p"
	.string "gagner des symboles. Je te souhaite\n"
	.string "bonne chance !$"

BattleFrontier_ReceptionGate_Text_RecordedBattleInfo:
	.string "Il est possible d'enregistrer une\n"
	.string "bataille sur votre FRONTIER PASS.\p"
	.string "Vous pouvez enregistrer une\n"
	.string "bataille que vous avez menée avec\p"
	.string "un ou plusieurs amis. Vous pouvez\n"
	.string "également enregistrer une bataille\p"
	.string "menée au ZONE DE COMBAT, à\n"
	.string "l'exclusion des matchs au BATTLE\p"
	.string "PIKE ou à la BATTLE PYRAMID. Vous\n"
	.string "pouvez choisir d'enregistrer votre\p"
	.string "match à la fin d'une bataille.$"

BattleFrontier_ReceptionGate_Text_BattlePointsInfo:
	.string "Les Battle Points sont des\n"
	.string "récompenses décernées aux DRESSEURS\p"
	.string "qui se sont battus de manière\n"
	.string "exceptionnelle à la ZONE DE COMBAT.\p"
	.string "Vous pouvez échanger vos points de\n"
	.string "combat contre des prix au COIN DU\p"
	.string "SERVICE D'ÉCHANGE.$"
