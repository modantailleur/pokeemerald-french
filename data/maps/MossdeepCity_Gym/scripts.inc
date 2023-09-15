MossdeepCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_Gym_OnLoad
	.byte 0

@ NOTE: Mossdeep Gym was redesigned between R/S and E. Leftover (and now functionally unused) scripts are commented below

@ All the below checks are leftover from RS. FLAG_MOSSDEEP_GYM_SWITCH_X is never set
MossdeepCity_Gym_OnLoad:
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_SetSwitch1Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_CheckSwitch2::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_SetSwitch2Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_CheckSwitch3::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_SetSwitch3Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_CheckSwitch4::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_SetSwitch4Metatiles
	end

@ All the below set metatile scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_SetSwitch1Metatiles::
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_SetSwitch2Metatiles::
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_SetSwitch3Metatiles::
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_SetSwitch4Metatiles::
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	end

MossdeepCity_Gym_EventScript_TateAndLiza::
	trainerbattle_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaIntro, MossdeepCity_Gym_Text_TateAndLizaDefeat, MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons, MossdeepCity_Gym_EventScript_TateAndLizaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_Gym_EventScript_TateAndLizaRematch
	goto_if_unset FLAG_RECEIVED_TM_CALM_MIND, MossdeepCity_Gym_EventScript_GiveCalmMind2
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_TateAndLizaDefeated::
	message MossdeepCity_Gym_Text_ReceivedMindBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
	setflag FLAG_BADGE07_GET
	setflag FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
	clearflag FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY
	clearflag FLAG_UNKNOWN_0x393
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	clearflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
	setvar VAR_MOSSDEEP_CITY_STATE, 1
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	call MossdeepCity_Gym_EventScript_GiveCalmMind
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MossdeepCity_Gym_Text_RegisteredTateAndLiza, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind2::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	return

MossdeepCity_Gym_EventScript_TateAndLizaRematch::
	trainerbattle_rematch_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaPreRematch, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat, MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostRematch, MSGBOX_AUTOCLOSE
	end

@ All the below switch scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_ClearSwitch1
	setflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed::
	special DrawWholeMapView
	playse SE_CLICK
	releaseall
	end

MossdeepCity_Gym_EventScript_ClearSwitch1::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_ClearSwitch2
	setflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch2::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Down, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_ClearSwitch3
	setflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch3::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_ClearSwitch4
	setflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch4::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_WarpToEntrance::
	lockall
	warpmossdeepgym MAP_MOSSDEEP_CITY_GYM, 7, 30
	waitstate
	releaseall
	end

MossdeepCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_PRESTON, MossdeepCity_Gym_Text_PrestonIntro, MossdeepCity_Gym_Text_PrestonDefeat
	msgbox MossdeepCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Virgil::
	trainerbattle_single TRAINER_VIRGIL, MossdeepCity_Gym_Text_VirgilIntro, MossdeepCity_Gym_Text_VirgilDefeat
	msgbox MossdeepCity_Gym_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Blake::
	trainerbattle_single TRAINER_BLAKE, MossdeepCity_Gym_Text_BlakeIntro, MossdeepCity_Gym_Text_BlakeDefeat
	msgbox MossdeepCity_Gym_Text_BlakePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Hannah::
	trainerbattle_single TRAINER_HANNAH, MossdeepCity_Gym_Text_HannahIntro, MossdeepCity_Gym_Text_HannahDefeat
	msgbox MossdeepCity_Gym_Text_HannahPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Samantha::
	trainerbattle_single TRAINER_SAMANTHA, MossdeepCity_Gym_Text_SamanthaIntro, MossdeepCity_Gym_Text_SamanthaDefeat
	msgbox MossdeepCity_Gym_Text_SamanthaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Maura::
	trainerbattle_single TRAINER_MAURA, MossdeepCity_Gym_Text_MauraIntro, MossdeepCity_Gym_Text_MauraDefeat
	msgbox MossdeepCity_Gym_Text_MauraPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Sylvia::
	trainerbattle_single TRAINER_SYLVIA, MossdeepCity_Gym_Text_SylviaIntro, MossdeepCity_Gym_Text_SylviaDefeat
	msgbox MossdeepCity_Gym_Text_SylviaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nate::
	trainerbattle_single TRAINER_NATE, MossdeepCity_Gym_Text_NateIntro, MossdeepCity_Gym_Text_NateDefeat
	msgbox MossdeepCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Macey::
	trainerbattle_single TRAINER_MACEY, MossdeepCity_Gym_Text_MaceyIntro, MossdeepCity_Gym_Text_MaceyDefeat
	msgbox MossdeepCity_Gym_Text_MaceyPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Clifford::
	trainerbattle_single TRAINER_CLIFFORD, MossdeepCity_Gym_Text_CliffordIntro, MossdeepCity_Gym_Text_CliffordDefeat
	msgbox MossdeepCity_Gym_Text_CliffordPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nicholas::
	trainerbattle_single TRAINER_NICHOLAS, MossdeepCity_Gym_Text_NicholasIntro, MossdeepCity_Gym_Text_NicholasDefeat
	msgbox MossdeepCity_Gym_Text_NicholasPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Kathleen::
	trainerbattle_single TRAINER_KATHLEEN, MossdeepCity_Gym_Text_KathleenIntro, MossdeepCity_Gym_Text_KathleenDefeat
	msgbox MossdeepCity_Gym_Text_KathleenPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MOSSDEEP_GYM, MossdeepCity_Gym_EventScript_GymGuidePostVictory
	msgbox MossdeepCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MossdeepCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

@ Leftover from RS, functionally unused
MossdeepCity_Gym_Movement_WaitAfterSwitchUse:
	delay_16
	delay_16
	step_end

MossdeepCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_GymStatueCertified::
	msgbox MossdeepCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_GymStatue::
	msgbox MossdeepCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_YellowFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 0
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_BlueFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 1
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_GreenFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 2
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_PurpleFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 3
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_RedFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 4
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_Text_GymGuideAdvice:
	.string "Yo, comment ça va, {PLAYER} en route\n"
	.string "vers CHAMPION ? Les GYM LEADERS\p"
	.string "utilisent ici des POKéMON de type\n"
	.string "PSYCHIQUE. Si vous les affrontez\p"
	.string "avec des POKéMON de type COMBAT ou\n"
	.string "POISON, ils vous infligeront\p"
	.string "d'horribles dégâts ! De plus, ils\n"
	.string "vous attaqueront avec des attaques\p"
	.string "combinées exceptionnelles. Si vous\n"
	.string "voulez gagner, vous devrez leur\p"
	.string "montrer à quel point vous êtes\n"
	.string "serré avec votre POKéMON. Allez-y\p"
	.string "!$"

MossdeepCity_Gym_Text_GymGuidePostVictory:
	.string "Wow, tu es incroyable ! Vous êtes\n"
	.string "un excellent DRESSEUR !$"

MossdeepCity_Gym_Text_PrestonIntro:
	.string "Les batailles dépendent de la force\n"
	.string "de votre esprit ! Les faibles\p"
	.string "d’esprit ne gagneront jamais !$"

MossdeepCity_Gym_Text_PrestonDefeat:
	.string "J'ai perdu! Je dois encore tempérer\n"
	.string "mon esprit !$"

MossdeepCity_Gym_Text_PrestonPostBattle:
	.string "Les indécis perdent. C'est mon\n"
	.string "avertissement pour vous.$"

MossdeepCity_Gym_Text_VirgilIntro:
	.string "Montre-moi ton talent !$"

MossdeepCity_Gym_Text_VirgilDefeat:
	.string "Vous possédez un talent\n"
	.string "spectaculaire !$"

MossdeepCity_Gym_Text_VirgilPostBattle:
	.string "S’il y a des prodiges dans le\n"
	.string "monde, alors nos GYM LEADERS sont\p"
	.string "bien eux ! Cependant, vous êtes\n"
	.string "peut-être encore plus talentueux\p"
	.string "qu’eux…$"

MossdeepCity_Gym_Text_BlakeIntro:
	.string "Fufufufu… Regardez-moi faire\n"
	.string "léviter une POKé BALL par\p"
	.string "télékinésie ! Wrooooooooaaaar ! … …\n"
	.string "… … … … … Parfois, je ne suis pas\p"
	.string "synchronisé…$"

MossdeepCity_Gym_Text_BlakeDefeat:
	.string "Mes compétences de combat POKéMON\n"
	.string "sont également désynchronisées !$"

MossdeepCity_Gym_Text_BlakePostBattle:
	.string "Une POKé BALL était trop lourde\n"
	.string "pour être soulevée psychiquement.\p"
	.string "Mais ce lapin de poussière…\n"
	.string "Whoooooooooooooooh ! … … … … … …\p"
	.string "Non, je ne triche pas ! Je n'ai pas\n"
	.string "soufflé dessus ! Honnêtement !$"

MossdeepCity_Gym_Text_HannahIntro:
	.string "Quand tu perds contre moi, ne sois\n"
	.string "pas trop dur avec toi-même. Ce\p"
	.string "n'est pas que tu sois faible, je\n"
	.string "suis juste trop fort !$"

MossdeepCity_Gym_Text_HannahDefeat:
	.string "Tu es tout simplement trop fort !$"

MossdeepCity_Gym_Text_HannahPostBattle:
	.string "Je ne vais pas m'en vouloir d'avoir\n"
	.string "perdu. J'ai juste besoin de\p"
	.string "m'entraîner plus dur. La pensée\n"
	.string "positive, c'est mon point fort !$"

MossdeepCity_Gym_Text_SamanthaIntro:
	.string "Je le vois… Je vois ton avenir… Si\n"
	.string "tu peux me battre, je te dirai ton\p"
	.string "avenir !$"

MossdeepCity_Gym_Text_SamanthaDefeat:
	.string "Je me rends !$"

MossdeepCity_Gym_Text_SamanthaPostBattle:
	.string "Vous mènerez une bataille\n"
	.string "terriblement intense avec nos GYM\p"
	.string "LEADERS… Le résultat… Vous n'en\n"
	.string "entendrez rien de ma part !$"

MossdeepCity_Gym_Text_MauraIntro:
	.string "Les routes que vous avez\n"
	.string "parcourues… Ce que vous avez vécu…\p"
	.string "Venez me voir avec tout ce que vous\n"
	.string "avez appris !$"

MossdeepCity_Gym_Text_MauraDefeat:
	.string "Vous avez parcouru un chemin de\n"
	.string "grandeur !$"

MossdeepCity_Gym_Text_MauraPostBattle:
	.string "Un avenir radieux attend ceux qui\n"
	.string "ont travaillé avec diligence. Pour\p"
	.string "ceux qui ont paressé, il n’y a que\n"
	.string "le désespoir à la fin. Ce qui se\p"
	.string "passe revient…$"

MossdeepCity_Gym_Text_SylviaIntro:
	.string "Même au péril de ma vie, je\n"
	.string "gagnerai cette bataille !$"

MossdeepCity_Gym_Text_SylviaDefeat:
	.string "Ce que tu fais… Ça me fait\n"
	.string "horreur…$"

MossdeepCity_Gym_Text_SylviaPostBattle:
	.string "Comment oses-tu me battre… Ce ne\n"
	.string "sera pas de ma faute si quelque\p"
	.string "chose d'horrible t'arrive…$"

MossdeepCity_Gym_Text_NateIntro:
	.string "Ho ho ho. Vous avez besoin que je\n"
	.string "vous montre à quel point le type\p"
	.string "PSYCHIQUE peut être tenace.$"

MossdeepCity_Gym_Text_NateDefeat:
	.string "Oh! Oh la la! Votre style de combat\n"
	.string "est fantastique !$"

MossdeepCity_Gym_Text_NatePostBattle:
	.string "Je… je ne laisse pas la défaite me\n"
	.string "secouer, même si c'est grave.$"

MossdeepCity_Gym_Text_KathleenIntro:
	.string "Laissez-moi vous montrer une\n"
	.string "période parfaitement horrible et\p"
	.string "horrible !$"

MossdeepCity_Gym_Text_KathleenDefeat:
	.string "N-nooooo!$"

MossdeepCity_Gym_Text_KathleenPostBattle:
	.string "Votre vitalité est contagieuse !\n"
	.string "Éloigne-toi de moi vite !$"

MossdeepCity_Gym_Text_CliffordIntro:
	.string "J'ai peut-être dépassé mon apogée,\n"
	.string "mais je vous suggère de ne pas me\p"
	.string "prendre avec condescendance.$"

MossdeepCity_Gym_Text_CliffordDefeat:
	.string "Ah, tu débordes du pouvoir de la\n"
	.string "jeunesse !$"

MossdeepCity_Gym_Text_CliffordPostBattle:
	.string "Il semble que je n'ai pas pu\n"
	.string "vaincre votre énergie juvénile.$"

MossdeepCity_Gym_Text_MaceyIntro:
	.string "Vous n'allez pas jusqu'au bout !\n"
	.string "Pas si je peux l'aider !$"

MossdeepCity_Gym_Text_MaceyDefeat:
	.string "Comment as-tu pu être si\n"
	.string "ridiculement fort ?$"

MossdeepCity_Gym_Text_MaceyPostBattle:
	.string "Hum ! Vous êtes peut-être fort,\n"
	.string "mais vous n'êtes pas adapté au type\p"
	.string "PSYCHIQUE ! La façon dont vous vous\n"
	.string "battez est en quelque sorte brutale\p"
	.string "!$"

MossdeepCity_Gym_Text_NicholasIntro:
	.string "Waouh ! Goûtez à mon pouvoir de\n"
	.string "combat acharné de super POKéMON !$"

MossdeepCity_Gym_Text_NicholasDefeat:
	.string "Oh! Terminé!$"

MossdeepCity_Gym_Text_NicholasPostBattle:
	.string "D'accord! Je pense que je\n"
	.string "développerai ensuite un pouvoir\p"
	.string "POKéMON invincible spécial.$"

MossdeepCity_Gym_Text_TateAndLizaIntro:
	.string "LÉVY : Héhéhé… Avez-vous été\n"
	.string "surpris ? LIZA : Fufufu… As-tu été\p"
	.string "surpris ? LÉVY : Qu'il y a deux GYM\n"
	.string "LEADERS ? LIZA : Qu’il y a deux GYM\p"
	.string "LEADERS ? LÉVY : Nous sommes\n"
	.string "jumeaux ! LIZA : Nous sommes\p"
	.string "jumelles ! LÉVY : Nous n'avons pas\n"
	.string "besoin de parler parce que… LIZA :\p"
	.string "Nous pouvons chacun déterminer\n"
	.string "quoi… LÉVY : L'autre réfléchit…\p"
	.string "LIZA : Tout cela est dans nos\n"
	.string "esprits ! LÉVY : Notre combinaison…\p"
	.string "LIZA : Pouvez-vous la battre ?$"

MossdeepCity_Gym_Text_TateAndLizaDefeat:
	.string "LÉVY : Quoi ?! Notre combinaison…\n"
	.string "LIZA : A été brisée ! LÉVY : On n’y\p"
	.string "peut rien. Vous avez gagné… LIZA :\n"
	.string "Alors, en guise de reconnaissance,\p"
	.string "prenez ceci.$"

MossdeepCity_Gym_Text_ReceivedMindBadge:
	.string "{PLAYER} a reçu le MIND BADGE de LÉVY\n"
	.string "et LIZA.$"

MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis:
	.string "LÉVY : Le MIND BADGE améliore le\n"
	.string "SP. ATK et SP. DEF de POKéMON. LIZA\p"
	.string ": Il vous permet également\n"
	.string "d'utiliser le mouvement HM DIVE en\p"
	.string "dehors du combat. LÉVY : Tu devrais\n"
	.string "aussi prendre ça aussi.$"

MossdeepCity_Gym_Text_ExplainCalmMind:
	.string "LÉVY : Ce TM04 contient… LIZA :\n"
	.string "ESPRIT CALME ! LÉVY : Cela augmente\p"
	.string "SP. ATK et… LIZA : Cela soulève SP.\n"
	.string "DÉF ! LÉVY : C'est un mouvement\p"
	.string "parfait… LIZA : Pour POKéMON\n"
	.string "PSYCHIQUE ! … … … … … …$"

MossdeepCity_Gym_Text_RegisteredTateAndLiza:
	.string "LÉVY & LIZA, GYM LEADERS inscrits\n"
	.string "dans le POKéNAV.$"

MossdeepCity_Gym_Text_TateAndLizaPostBattle:
	.string "LÉVY : On dirait que le lien entre\n"
	.string "vous et votre POKéMON est bien plus\p"
	.string "fort que le lien que nous\n"
	.string "partageons en tant que jumeaux.\p"
	.string "LIZA : Vous deviendrez encore plus\n"
	.string "fort ! Nous vous avons combattu,\p"
	.string "donc nous le savons.$"

MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons:
	.string "LÉVY : Héhéhé… Avez-vous été\n"
	.string "surpris ? LIZA : Qu’il y a deux GYM\p"
	.string "LEADERS ? LÉVY : Oups, tu n'en as\n"
	.string "qu'un... LIZA : POKéMON qui peut\p"
	.string "combattre. LÉVY : Nous ne pouvons\n"
	.string "pas combattre de cette façon ! LIZA\p"
	.string ": Si vous voulez nous défier,\n"
	.string "apportez encore quelques POKéMON.$"

MossdeepCity_Gym_Text_GymStatue:
	.string "ALGATIA POKéMON GYM$"

MossdeepCity_Gym_Text_GymStatueCertified:
	.string "ALGATIA POKéMON GYM DRESSEURS\n"
	.string "CERTIFIÉS DE LIZA GUIDO LÉVY :\p"
	.string "{PLAYER}$"

MossdeepCity_Gym_Text_TateAndLizaPreRematch:
	.string "LÉVY : POKéMON… LIZA : POKéMON…\n"
	.string "LÉVY : En changeant le mix du\p"
	.string "groupe… LIZA : Le style de combat\n"
	.string "change. LÉVY : Mais moi… LIZA :\p"
	.string "Mais moi… LÉVY : Je serai toujours\n"
	.string "avec LIZA ! LIZA : Je serai\p"
	.string "toujours avec LÉVY ! LÉVY : Notre\n"
	.string "combinaison… LIZA : Nous vous la\p"
	.string "montrerons encore et encore !$"

MossdeepCity_Gym_Text_TateAndLizaRematchDefeat:
	.string "LÉVY : Toi et ton POKéMON… LIZA :\n"
	.string "C'est comme si vous étiez frères et\p"
	.string "sœurs !$"

MossdeepCity_Gym_Text_TateAndLizaPostRematch:
	.string "LÉVY : Vous pouvez nous faire\n"
	.string "tomber, mais nous ne resterons\p"
	.string "jamais à terre ! LIZA : Parce que\n"
	.string "nous deux, on se soutient toujours\p"
	.string "!$"

MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons:
	.string "LÉVY : Vous êtes de retour… LIZA :\n"
	.string "Vous êtes de retour… LÉVY : Pour\p"
	.string "nous donner une revanche. LIZA :\n"
	.string "Pour nous offrir une revanche. LÉVY\p"
	.string ": Mais… LIZA : Pour notre match…\n"
	.string "LÉVY : Tu n'as apporté qu'un seul\p"
	.string "POKéMON ! LIZA : Vous n'avez\n"
	.string "apporté qu'un seul POKéMON ! LÉVY :\p"
	.string "Nous avons besoin que tu apportes\n"
	.string "au moins… LIZA : Deux POKéMON à ton\p"
	.string "retour.$"
