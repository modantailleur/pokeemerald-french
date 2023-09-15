.set LOCALID_GRUNT, 3
.set LOCALID_DEVON_EMPLOYEE, 4

PetalburgWoods_MapScripts::
	.byte 0

PetalburgWoods_EventScript_DevonResearcherLeft::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherRight::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherIntro::
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
	waitmovement 0
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_DevonResearcherPostBattle::
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaRunAway
	waitmovement 0
	removeobject LOCALID_GRUNT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_BagFull::
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_DevonResearcherFinish::
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
	waitmovement 0
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_RemoveDevonResearcher::
	removeobject LOCALID_DEVON_EMPLOYEE
	setvar VAR_PETALBURG_WOODS_STATE, 1
	releaseall
	end

PetalburgWoods_Movement_DevonResearcherLookAround:
	face_up
	delay_16
	delay_4
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	step_end

PetalburgWoods_Movement_DevonResearcherExitLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
	delay_16
	face_player
	walk_down
	walk_down
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
	delay_16
	face_player
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PetalburgWoods_Movement_DevonResearcherExitRight:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_WatchResearcherLeave:
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherStartExit:
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	step_end

PetalburgWoods_Movement_AquaApproachResearcherLeft:
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaBackOff:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PetalburgWoods_Movement_AquaRunAway:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachResearcherRight:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaEntrance:
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachPlayer:
	walk_down
	step_end

PetalburgWoods_EventScript_Boy1::
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Boy2::
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MIRACLE_SEED
	release
	end

PetalburgWoods_EventScript_ExplainMiracleSeed::
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_Sign1::
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign2::
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_James::
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
	setvar VAR_0x8004, TRAINER_JAMES_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_TryRegisterJames::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
	release
	end

PetalburgWoods_EventScript_RegisterJames::
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_TryRegisterJames2::
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_RegisterJames2::
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_JamesRematch::
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_Text_NotAOneToBeFound:
	.string "Hmmm… Pas un seul à trouver…$"

PetalburgWoods_Text_HaveYouSeenShroomish:
	.string "Bonjour, avez-vous vu un POKéMON\n"
	.string "appelé SHROOMISH par ici ? J'adore\p"
	.string "vraiment ce POKéMON.$"

PetalburgWoods_Text_IWasGoingToAmbushYou:
	.string "J'allais te tendre une embuscade,\n"
	.string "mais tu as dû traîner dans\p"
	.string "PGUIDOALBURG WOODS pour toujours,\n"
	.string "n'est-ce pas ? J'en ai eu marre\p"
	.string "d'attendre, alors me voilà !$"

PetalburgWoods_Text_HandOverThosePapers:
	.string "Toi! CHERCHEUR DU DEVON ! Remettez\n"
	.string "ces papiers !$"

PetalburgWoods_Text_YouHaveToHelpMe:
	.string "Aiyeeeh ! Vous êtes un DRESSEUR DE\n"
	.string "POKéMON, n'est-ce pas ? Vous devez\p"
	.string "m'aider, s'il vous plaît !$"

PetalburgWoods_Text_NoOneCrossesTeamAqua:
	.string "Hein ? Qu'est ce que tu crois\n"
	.string "faire? Quoi, tu vas le protéger ?\p"
	.string "Personne qui croise TEAM AQUA n'a\n"
	.string "de pitié, pas même un enfant !\p"
	.string "Allez et combattez-moi !$"

PetalburgWoods_Text_YoureKiddingMe:
	.string "Vous plaisantez! Tu es dur !$"

PetalburgWoods_Text_YouveGotSomeNerve:
	.string "Grrr… Vous avez du culot de vous\n"
	.string "mêler de la TEAM AQUA ! Allez et\p"
	.string "combattez-moi à nouveau !\n"
	.string "J'aimerais pouvoir dire ça, mais je\p"
	.string "n'ai plus de POKéMON… Et, hé, nous\n"
	.string "de TEAM AQUA recherchons également\p"
	.string "quelque chose à RUSTBORO. Je te\n"
	.string "laisse partir aujourd'hui !$"

PetalburgWoods_Text_ThatWasAwfullyClose:
	.string "Ouf… C'était terriblement proche !\n"
	.string "Grâce à vous, il ne m'a pas volé\p"
	.string "ces papiers importants. Je sais, je\n"
	.string "vais te donner une GRANDE BALLE en\p"
	.string "guise de remerciement !$"

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
	.string "Ce voyou de la TEAM AQUA n'a-t-il\n"
	.string "pas dit qu'ils cherchaient aussi\p"
	.string "quelque chose à RUSTBORO ?$"

PetalburgWoods_Text_ICantBeWastingTime:
	.string "Oh-oh ! C'est une crise ! Je ne\n"
	.string "peux pas perdre de temps !$"

PetalburgWoods_Text_YoureLoadedWithItems:
	.string "Vous êtes chargé d'objets. Je ne\n"
	.string "peux pas te donner cette GRANDE\p"
	.string "BALLE.$"

PetalburgWoods_Text_GoBugPokemonTeam:
	.string "J'ai attrapé tout un tas de POKéMON\n"
	.string "! Allez! Allez! Allez! Mon équipe\p"
	.string "BUG POKéMON !$"

PetalburgWoods_Text_ICouldntWin:
	.string "J'ai tous ces POKéMON, mais je n'ai\n"
	.string "pas pu gagner…$"

PetalburgWoods_Text_ImOutOfPokeBalls:
	.string "J'ai attrapé un tas de POKéMON.\n"
	.string "Maintenant, je n'ai plus de POKé\p"
	.string "BALLS.$"

PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
	.string "Si vous emmenez BUG POKéMON à\n"
	.string "l'école, vous deviendrez\p"
	.string "instantanément populaire !$"

PetalburgWoods_Text_CantBePopularIfILose:
	.string "Je ne peux pas être populaire si je\n"
	.string "perds.$"

PetalburgWoods_Text_PeopleRespectYou:
	.string "Si vous avez un gros POKéMON BUG,\n"
	.string "les gens vous respectent pour\p"
	.string "cela.$"

PetalburgWoods_Text_IWantRematch1:
	.string "Je veux une revanche quand mon BUG\n"
	.string "POKéMON grandira ! Je t'inscris\p"
	.string "dans mon POKéNAV!$"

PetalburgWoods_Text_IWantRematch2:
	.string "Je veux une revanche quand mon BUG\n"
	.string "POKéMON grandira ! Je t'inscris\p"
	.string "dans mon POKéNAV!$"

PetalburgWoods_Text_MyPokemonHaveGrown:
	.string "Mes POKéMON BUG ont grandi. Je\n"
	.string "serai à nouveau populaire.$"

PetalburgWoods_Text_CantBePopularIfLose:
	.string "Je ne peux pas être populaire si je\n"
	.string "perds.$"

PetalburgWoods_Text_IveBeenTrainingHard:
	.string "Vous devenez populaire si vous\n"
	.string "possédez un POKéMON fort, n'est-ce\p"
	.string "pas ? Donc, je me suis entraîné\n"
	.string "dur.$"

PetalburgWoods_Text_StayOutOfTallGrass:
	.string "Yo, là ! Votre POKéMON va bien ? Si\n"
	.string "vos POKéMON sont faibles et que\p"
	.string "vous souhaitez éviter les combats,\n"
	.string "vous devez rester en dehors des\p"
	.string "herbes hautes.$"

PetalburgWoods_Text_HiddenItemsExplanation:
	.string "Parfois, il y a des choses au sol\n"
	.string "même si on ne les voit pas. C'est\p"
	.string "pourquoi je vérifie toujours où je\n"
	.string "marche.$"

PetalburgWoods_Text_TryUsingThisItem:
	.string "Oh, chouette ! C'est le BADGE de\n"
	.string "RUSTBORO GYM ! Vous devez être\p"
	.string "DRESSEUR. Vous devriez\n"
	.string "essayer d'utiliser cet article.$"

PetalburgWoods_Text_MiracleSeedExplanation:
	.string "C'est une GRAINE MIRACLE. Si un\n"
	.string "POKéMON détient cet objet, ses\p"
	.string "mouvements de type HERBE deviennent\n"
	.string "plus forts. En plus de MIRACLE\p"
	.string "SEED, je pense qu'il existe\n"
	.string "d'autres objets pratiques que\p"
	.string "POKéMON peut contenir.$"

PetalburgWoods_Text_TrainerTipsExperience:
	.string "CONSEILS D'DRESSEUR Tout POKéMON\n"
	.string "qui apparaît ne serait-ce qu'une\p"
	.string "seule fois au cours d'une bataille\n"
	.string "reçoit des points EXP. Pour élever\p"
	.string "un POKéMON faible, placez-le à\n"
	.string "gauche de la liste des équipes. Dès\p"
	.string "qu'une bataille commence,\n"
	.string "éteignez-la. Il gagnera des points\p"
	.string "EXP sans être exposé à aucun\n"
	.string "dommage.$"

PetalburgWoods_Text_TrainerTipsPP:
	.string "CONSEILS POUR L'DRESSEUR En plus\n"
	.string "des points de vie (HP), les POKéMON\p"
	.string "disposent de points de pouvoir (PP)\n"
	.string "qui sont utilisés pour effectuer\p"
	.string "des mouvements pendant la bataille.\n"
	.string "Si un POKéMON manque de PP, il doit\p"
	.string "être amené dans un POKéMON CENTER.$"
