BattleFrontier_Lounge7_MapScripts::
	.byte 0

BattleFrontier_Lounge7_EventScript_LeftMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_1
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor
	msgbox BattleFrontier_Lounge7_Text_LeftTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor::
	msgbox BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_Softboiled::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SeismicToss::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_DreamEater::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaPunch::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaKick::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_BodySlam::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RockSlide::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Counter::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderWave::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SwordsDance::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RightMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_2
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor
	msgbox BattleFrontier_Lounge7_Text_RightTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor::
	msgbox BattleFrontier_Lounge7_Text_RightTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_DefenseCurl::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Snore::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MudSlap::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Swift::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcyWind::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Endure::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_PsychUp::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcePunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderPunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_FirePunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect::
	special CloseBattleFrontierTutorWindow
	special CloseBattlePointsWindow
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge7_EventScript_CancelChooseMon::
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8008 is the price
@ VAR_TEMP_C is the scroll multichoice ID
@ VAR_TEMP_FRONTIER_TUTOR_SELECTION is the move selection
@ VAR_TEMP_FRONTIER_TUTOR_ID is which move tutor was spoken to
BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection::
	copyvar VAR_0x8004, VAR_TEMP_FRONTIER_TUTOR_SELECTION
	copyvar VAR_0x8005, VAR_TEMP_FRONTIER_TUTOR_ID
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	copyvar VAR_0x8004, VAR_TEMP_C
	msgbox BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge7_EventScript_ChooseNewMove
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge7_EventScript_TeachTutorMove
	msgbox BattleFrontier_Lounge7_Text_HaventGotEnoughPoints, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseNewMove
	end

BattleFrontier_Lounge7_EventScript_TeachTutorMove::
	msgbox BattleFrontier_Lounge7_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	special GetBattleFrontierTutorMoveIndex
	fadescreen FADE_TO_BLACK
	special CloseBattlePointsWindow
	special CloseBattleFrontierTutorWindow
	special ChooseMonForMoveTutor
	waitstate
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_Lounge7_EventScript_CancelChooseMon
	msgbox BattleFrontier_Lounge7_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	release
	end

BattleFrontier_Lounge7_EventScript_ChooseNewMove::
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 0, BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove
	goto BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_Sailor::
	msgbox BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong, MSGBOX_NPC
	end

BattleFrontier_Lounge7_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful, MSGBOX_NPC
	end

BattleFrontier_Lounge7_Text_LeftTutorIntro:
	.string "Bouhahaha ! On ne pouvait pas le\n"
	.string "dire en regardant maintenant, mais\p"
	.string "j'étais un DRESSEUR coriace.\n"
	.string "J’avais la réputation d’être la\p"
	.string "BEAUTÉ la plus coriace du moment,\n"
	.string "je vous le dis ! … … … … … … Qu'est\p"
	.string "ce que c'est maintenant? Vous ne me\n"
	.string "croyez pas. Je ne suis pas comme\p"
	.string "cette femme fanfaronne là-bas. En\n"
	.string "fait, je suis talentueux !\p"
	.string "Laissez-moi vous le prouver. Je\n"
	.string "peux enseigner à votre POKéMON des\p"
	.string "mouvements spéciaux et pourtant\n"
	.string "mignons. Mais mes cours ne sont pas\p"
	.string "gratuits. Que diriez-vous de payer\n"
	.string "les mouvements que j'enseigne avec\p"
	.string "un tout petit peu de Battle Points\n"
	.string "?$"

BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack:
	.string "Bouhahaha ! Êtes-vous de retour\n"
	.string "pour apprendre des mouvements\p"
	.string "POKéMON spéciaux et pourtant\n"
	.string "mignons ?$"

BattleFrontier_Lounge7_Text_TeachWhichMove:
	.string "Très bien, très bien, regarde ici !\n"
	.string "Quel mouvement dois-je enseigner ?$"

BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints:
	.string "Le mouvement {STR_VAR_1}, n'est-ce pas ?\n"
	.string "Cela fera {STR_VAR_2} points de\p"
	.string "bataille, d'accord ?$"

BattleFrontier_Lounge7_Text_TeachMoveToWhichMon:
	.string "Très bien, maintenant choisis le\n"
	.string "POKéMON auquel je devrais apprendre\p"
	.string "le mouvement.$"

BattleFrontier_Lounge7_Text_HaventGotEnoughPoints:
	.string "Qu'est-ce que… Vous n'avez pas\n"
	.string "assez de points de combat !$"

BattleFrontier_Lounge7_Text_IllTakeBattlePoints:
	.string "Voyez-vous à quel point je suis\n"
	.string "compétent maintenant ? Je prendrai\p"
	.string "vos Battle Points, merci !$"

BattleFrontier_Lounge7_Text_YouDontWantTo:
	.string "Qu'est ce que c'est? Tu ne veux\n"
	.string "pas… Si tu veux voir à quel point\p"
	.string "je suis compétent, tu viens me voir\n"
	.string "à tout moment !$"

BattleFrontier_Lounge7_Text_RightTutorIntro:
	.string "Ihihihi ! Je sais que c'est\n"
	.string "difficile à voir maintenant, mais\p"
	.string "j'étais un FORMATTHIEUEUR\n"
	.string "fantastique. J'avais la réputation\p"
	.string "d'être le NAGEUR le plus invincible\n"
	.string "du moment, je vous le dis ! … … … …\p"
	.string "… … Qu'est-ce qui ne va pas? Vous\n"
	.string "ne me croyez pas. Je ne suis pas\p"
	.string "comme cette bouffonne là-bas. En\n"
	.string "fait, je suis expérimenté ! Je peux\p"
	.string "vous le prouver. Je peux apprendre\n"
	.string "à votre POKéMON des mouvements\p"
	.string "difficiles mais jolis. Mais mes\n"
	.string "cours ne sont pas gratuits. Que\p"
	.string "diriez-vous de payer les mouvements\n"
	.string "que j'enseigne avec un tout petit\p"
	.string "peu de Battle Points ?$"

BattleFrontier_Lounge7_Text_RightTutorWelcomeBack:
	.string "Ihihihi ! Êtes-vous venu pour\n"
	.string "apprendre des mouvements POKéMON\p"
	.string "difficiles mais jolis ?$"

BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong:
	.string "Ces dames, à la façon dont elles se\n"
	.string "dénigrent, vous pensez probablement\p"
	.string "qu'elles ne s'entendent pas. Mais\n"
	.string "si c'était vrai, ils ne resteraient\p"
	.string "pas ici ensemble, n'est-ce pas ?$"

BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful:
	.string "Quand j’étais tout petit, ces dames\n"
	.string "étaient fortes et belles. Ils\p"
	.string "étaient des idoles parmi nous, les\n"
	.string "FORMATTHIEUEURS. Même aujourd’hui,\p"
	.string "l’âge n’a pas entamé leurs\n"
	.string "capacités. En fait, leurs\p"
	.string "mouvements POKéMON sont devenus\n"
	.string "encore plus perfectionnés. Mais…\p"
	.string "Pour une raison quelconque, je ne\n"
	.string "peux m'empêcher de ressentir ça… Le\p"
	.string "temps est si cruel…$"

BattleFrontier_Lounge7_Text_SoftboiledDesc::
	.string "Récupère jusqu'à la moitié des HP\n"
	.string "maximum de l'utilisateur.$"

BattleFrontier_Lounge7_Text_SeismicTossDesc::
	.string "Inflige des dégâts identiques au\n"
	.string "niveau de l'utilisateur.$"

BattleFrontier_Lounge7_Text_DreamEaterDesc::
	.string "Récupère la moitié des dégâts\n"
	.string "infligés à un ennemi endormi.$"

BattleFrontier_Lounge7_Text_MegaPunchDesc::
	.string "Un coup de poing puissant lancé\n"
	.string "avec une puissance incroyable.$"

BattleFrontier_Lounge7_Text_MegaKickDesc::
	.string "Un coup de pied extrêmement\n"
	.string "puissant avec une force intense.$"

BattleFrontier_Lounge7_Text_BodySlamDesc::
	.string "Un claquement de tout le corps\n"
	.string "pouvant provoquer une paralysie.$"

BattleFrontier_Lounge7_Text_RockSlideDesc::
	.string "De gros rochers sont lancés. Peut\n"
	.string "provoquer des frissons.$"

BattleFrontier_Lounge7_Text_CounterDesc::
	.string "Riposte à tout coup physique avec\n"
	.string "le double de la puissance.$"

BattleFrontier_Lounge7_Text_ThunderWaveDesc::
	.string "Une faible décharge électrique qui\n"
	.string "paralyse l'ennemi.$"

BattleFrontier_Lounge7_Text_SwordsDanceDesc::
	.string "Une danse de combat qui fait monter\n"
	.string "brusquement l'ATTAQUE.$"

BattleFrontier_Lounge7_Text_DefenseCurlDesc::
	.string "Se recroqueville pour dissimuler\n"
	.string "les points faibles et augmenter la\p"
	.string "DÉFENSE.$"

BattleFrontier_Lounge7_Text_SnoreDesc::
	.string "Une attaque forte qui ne peut être\n"
	.string "utilisée que pendant le sommeil.$"

BattleFrontier_Lounge7_Text_MudSlapDesc::
	.string "Projette de la boue au visage de\n"
	.string "l'ennemi pour réduire sa\p"
	.string "précision.$"

BattleFrontier_Lounge7_Text_SwiftDesc::
	.string "Pulvérise des rayons en forme\n"
	.string "d'étoile qui ne manquent jamais.$"

BattleFrontier_Lounge7_Text_IcyWindDesc::
	.string "Une attaque glaciale qui réduit la\n"
	.string "VITESSE de l'ennemi.$"

BattleFrontier_Lounge7_Text_EndureDesc::
	.string "Supporte n'importe quelle attaque\n"
	.string "pendant 1 tour, laissant 1HP.$"

BattleFrontier_Lounge7_Text_PsychUpDesc::
	.string "Copie les effets de l'ennemi et les\n"
	.string "donne à l'utilisateur.$"

BattleFrontier_Lounge7_Text_IcePunchDesc::
	.string "Un coup de poing glacé qui peut\n"
	.string "geler l'ennemi.$"

BattleFrontier_Lounge7_Text_ThunderPunchDesc::
	.string "Un coup de poing électrifié qui\n"
	.string "peut paralyser l'ennemi.$"

BattleFrontier_Lounge7_Text_FirePunchDesc::
	.string "Un coup de poing enflammé qui peut\n"
	.string "brûler l'ennemi.$"
