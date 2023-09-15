RustboroCity_PokemonSchool_MapScripts::
	.byte 0

RustboroCity_PokemonSchool_EventScript_Blackboard::
	lockall
	msgbox RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic::
	message RustboroCity_PokemonSchool_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_PokemonSchool_EventScript_Poison
	case 1, RustboroCity_PokemonSchool_EventScript_Paralysis
	case 2, RustboroCity_PokemonSchool_EventScript_Sleep
	case 3, RustboroCity_PokemonSchool_EventScript_Burn
	case 4, RustboroCity_PokemonSchool_EventScript_Freeze
	case 5, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	case MULTI_B_PRESSED, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	end

RustboroCity_PokemonSchool_EventScript_Poison::
	msgbox RustboroCity_PokemonSchool_Text_ExplainPoison, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Paralysis::
	msgbox RustboroCity_PokemonSchool_Text_ExplainParalysis, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Sleep::
	msgbox RustboroCity_PokemonSchool_Text_ExplainSleep, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Burn::
	msgbox RustboroCity_PokemonSchool_Text_ExplainBurn, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Freeze::
	msgbox RustboroCity_PokemonSchool_Text_ExplainFreeze, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ExitTopicSelect::
	releaseall
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid1::
	msgbox RustboroCity_PokemonSchool_Text_TradingRightNow, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid2::
	msgbox RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_RichBoy::
	msgbox RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_Lass::
	msgbox RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_SchoolKidM::
	msgbox RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_StudentNotebook::
	msgbox RustboroCity_PokemonSchool_Text_StudentsNotes, MSGBOX_SIGN
	end

RustboroCity_PokemonSchool_EventScript_Teacher::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, RustboroCity_PokemonSchool_EventScript_GaveQuickClaw
	call_if_eq VAR_FACING, DIR_EAST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast
	call_if_eq VAR_FACING, DIR_WEST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest
	msgbox RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setflag FLAG_RECEIVED_QUICK_CLAW
	release
	end

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_GaveQuickClaw::
	msgbox RustboroCity_PokemonSchool_Text_ExplainQuickClaw, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	release
	end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	step_end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

RustboroCity_PokemonSchool_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE, RustboroCity_PokemonSchool_EventScript_ScottWatchStudents
	goto_if_set FLAG_MET_SCOTT_RUSTBORO, RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_RUSTBORO
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready::
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge::
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottWatchStudents::
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges:
	.string "Le tableau noir répertorie les\n"
	.string "changements de statut qui peuvent\p"
	.string "affecter POKéMON en combat.$"

RustboroCity_PokemonSchool_Text_ReadWhichTopic:
	.string "Quel sujet veux-tu lire ?$"

RustboroCity_PokemonSchool_Text_ExplainPoison:
	.string "Si un POKéMON est empoisonné, il\n"
	.string "perdra progressivement des PV. Les\p"
	.string "effets du poison persistent après\n"
	.string "une bataille. Les PV d'un POKéMON\p"
	.string "empoisonné chuteront pendant son\n"
	.string "voyage. Guérissez d'un\p"
	.string "empoisonnement en utilisant un\n"
	.string "ANTIDOTE.$"

RustboroCity_PokemonSchool_Text_ExplainParalysis:
	.string "Si un POKéMON devient paralysé, sa\n"
	.string "VITESSE diminue. Il se peut\p"
	.string "également qu'il ne soit pas capable\n"
	.string "de bouger pendant qu'il est en\p"
	.string "combat. La paralysie persiste après\n"
	.string "la bataille. Guérissez-le en\p"
	.string "utilisant un PARLYZ HEAL.$"

RustboroCity_PokemonSchool_Text_ExplainSleep:
	.string "Si un POKéMON s'endort, il ne\n"
	.string "pourra plus attaquer. Un POKéMON\p"
	.string "peut se réveiller tout seul, mais\n"
	.string "si un combat se termine alors qu'il\p"
	.string "dort, il restera endormi.\n"
	.string "Réveillez-le en utilisant un\p"
	.string "AWAKENING.$"

RustboroCity_PokemonSchool_Text_ExplainBurn:
	.string "Une brûlure réduit la puissance\n"
	.string "d'ATTAQUE et réduit progressivement\p"
	.string "les PV de la victime. Une brûlure\n"
	.string "persiste après la bataille.\p"
	.string "Guérissez une brûlure à l'aide d'un\n"
	.string "BURN HEAL.$"

RustboroCity_PokemonSchool_Text_ExplainFreeze:
	.string "Si un POKéMON est gelé, il devient\n"
	.string "complètement impuissant. Il restera\p"
	.string "gelé après la bataille.\n"
	.string "Décongelez-le à l'aide d'un ICE\p"
	.string "HEAL.$"

RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw:
	.string "Les étudiants qui n'étudient pas\n"
	.string "ont un petit avant-goût de ma QUICK\p"
	.string "CLAW. Que vous soyez ou non un bon\n"
	.string "élève sera évident à la manière\p"
	.string "dont vous utiliserez cet article.$"

RustboroCity_PokemonSchool_Text_ExplainQuickClaw:
	.string "Un POKéMON tenant la GRIFFE RAPIDE\n"
	.string "accélérera occasionnellement et\p"
	.string "pourra se déplacer avant son\n"
	.string "adversaire. Il existe de nombreux\p"
	.string "autres objets destinés à être\n"
	.string "détenus par POKéMON. Rien que\p"
	.string "ceux-là vous donneront de nombreux\n"
	.string "sujets à étudier !$"

RustboroCity_PokemonSchool_Text_TradingRightNow:
	.string "J'échange POKéMON avec mon ami en\n"
	.string "ce moment.$"

RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot:
	.string "J'ai toujours voulu un SEEDOT, et\n"
	.string "j'en ai enfin un !$"

RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems:
	.string "POKéMON peut contenir des objets,\n"
	.string "mais ils ne savent pas quoi faire\p"
	.string "avec des objets fabriqués par\n"
	.string "l'homme comme POTION et ANTIDOTE.$"

RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself:
	.string "Vous savez à quel point certains\n"
	.string "mouvements de POKéMON peuvent\p"
	.string "dérouter un POKéMON ? UN POKéMON\n"
	.string "confus s'attaque parfois sans le\p"
	.string "vouloir. Mais une fois qu'il aura\n"
	.string "quitté la bataille, il reviendra à\p"
	.string "la normale.$"

RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry:
	.string "Un POKéMON tenant une BAIE se\n"
	.string "guérira tout seul… Il existe de\p"
	.string "nombreux types d'objets que POKéMON\n"
	.string "peut contenir… Bon sang, c'est\p"
	.string "vraiment difficile de prendre des\n"
	.string "notes…$"

RustboroCity_PokemonSchool_Text_StudentsNotes:
	.string "C'est le cahier de cet élève… Les\n"
	.string "POKéMON sont à attraper à l'aide de\p"
	.string "POKé BALLS. Jusqu'à six POKéMON\n"
	.string "peuvent accompagner un dresseur. Un\p"
	.string "DRESSEUR est quelqu'un qui attrape\n"
	.string "des POKéMON, les élève et se bat\p"
	.string "avec eux. La mission d'un DRESSEUR\n"
	.string "est de vaincre les DRESSEURS forts\p"
	.string "qui attendent les challengers dans\n"
	.string "POKéMON GYMS.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut:
	.string "Bonjour? Ne nous sommes-nous pas\n"
	.string "déjà rencontrés ? Je repense à\p"
	.string "CLEMENTI-VILLE. Laisse moi me\n"
	.string "présenter. Je m'appelle SCOTT. J'ai\p"
	.string "voyagé partout à la recherche de\n"
	.string "DRESSEURS exceptionnels. Plus\p"
	.string "précisément, je recherche des\n"
	.string "experts en combat POKéMON. Alors,\p"
	.string "qu’est-ce qui vous amène dans cette\n"
	.string "ÉCOLE ? Êtes-vous aussi\p"
	.string "DRESSEUR ? La première chose\n"
	.string "à faire est de faire apprendre à un\p"
	.string "POKéMON le mouvement CUT. Si je me\n"
	.string "souviens bien, quelqu'un dans cette\p"
	.string "ville a COUPÉ.$"

RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown:
	.string "SCOTT : Hmm… Les niveaux de talent\n"
	.string "des étudiants ici sont inconnus. Le\p"
	.string "potentiel est là.$"

RustboroCity_PokemonSchool_Text_ScottStoneBadge:
	.string "SCOTT : Oh, qu'est-ce que c'est ?\n"
	.string "C'est un BADGE EN PIERRE, n'est-ce\p"
	.string "pas ? C'est assez impressionnant,\n"
	.string "je dirais. Mais tu sais, j'aurais\p"
	.string "adoré te voir au combat. Il est\n"
	.string "difficile de distinguer à quoi vous\p"
	.string "ressemblez en tant qu'DRESSEUR à\n"
	.string "partir d'un BADGE DE LIGUE.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge:
	.string "Bonjour? Ne nous sommes-nous pas\n"
	.string "déjà rencontrés ? Je repense à\p"
	.string "CLEMENTI-VILLE. Laisse moi me\n"
	.string "présenter. Je m'appelle SCOTT. J'ai\p"
	.string "voyagé partout à la recherche de\n"
	.string "DRESSEURS exceptionnels. Plus\p"
	.string "précisément, je recherche des\n"
	.string "experts en combat POKéMON. Oh,\p"
	.string "qu'est-ce que c'est ? C'est un\n"
	.string "BADGE EN PIERRE, n'est-ce pas ?\p"
	.string "C'est assez impressionnant, je\n"
	.string "dirais, pour un DRESSEUR\p"
	.string "débutant comme vous. Mais tu sais,\n"
	.string "j'aurais adoré te voir au combat.\p"
	.string "Il est difficile de distinguer à\n"
	.string "quoi vous ressemblez en tant\p"
	.string "qu'DRESSEUR à partir d'un BADGE DE\n"
	.string "LIGUE.$"
