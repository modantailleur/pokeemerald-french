.set LOCALID_OWNER, 1

LilycoveCity_CoveLilyMotel_1F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_1F_EventScript_MotelOwner::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_BlockingTV::
	lockall
	playse SE_PIN
	applymovement LOCALID_OWNER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_OWNER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV
	applymovement LOCALID_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer
	waitmovement 0
	applymovement LOCALID_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn
	waitmovement 0
	release
	end

LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer:
	walk_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn:
	face_down
	walk_down
	face_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot:
	.string "Hm, alors ils ont doublé le nombre\n"
	.string "d'invités en utilisant POKéMON\p"
	.string "comme attractions ? Hm, eh bien, je\n"
	.string "devrais peut-être créer un joli\p"
	.string "POKéMON pour la mascotte de notre\n"
	.string "auberge. Je me demande si cela\p"
	.string "attirera plus de clients à rester\n"
	.string "avec nous ?$"

LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua:
	.string "Oh, désolé, désolé ! J'étais trop\n"
	.string "occupé à regarder la télévision !\p"
	.string "Depuis que TEAM AQUA est arrivée en\n"
	.string "ville, les touristes restent à\p"
	.string "l'écart.$"

LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV:
	.string "Hé, devant ! Je ne peux pas voir la\n"
	.string "télé !$"

LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem:
	.string "Incroyable! Vous me dites qu'un\n"
	.string "POKéMON a trouvé l'objet perdu de\p"
	.string "quelqu'un ? C'est quelque chose. Si\n"
	.string "nous avions des POKéMON\p"
	.string "intelligents comme celui-là… Nous\n"
	.string "pourrions récupérer tout ce que nos\p"
	.string "invités ont égaré…$"

LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted:
	.string "Oh, désolé, désolé ! J'étais trop\n"
	.string "occupé à regarder la télévision !\p"
	.string "J'ai entendu dire que quelqu'un\n"
	.string "avait détruit la TEAM PLANQUE AQUA.\p"
	.string "Grâce à cela, nous venons de\n"
	.string "réserver une réservation auprès\p"
	.string "d'un grand groupe. C'était une\n"
	.string "société qui s'appelait… Euh… GAME\p"
	.string "quelque chose…$"

LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar:
	.string "Incroyable! Un POKéMON en garde à\n"
	.string "domicile a attrapé un cambrioleur ?\p"
	.string "C'est quelque chose. Si nous avions\n"
	.string "un POKéMON coriace comme agent de\p"
	.string "sécurité… Nous serions en mesure\n"
	.string "d'offrir une plus grande sécurité à\p"
	.string "nos invités.$"

LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner:
	.string "Oh, désolé, désolé ! J'étais trop\n"
	.string "occupé à regarder la télévision. Oh\p"
	.string "oui. Un grand groupe d’invités est\n"
	.string "arrivé il y a peu. Ils ont réservé\p"
	.string "sous le nom de GAME FREAK, donc je\n"
	.string "suppose qu'ils doivent créer des\p"
	.string "jeux. Oh-oh, je ferais mieux de\n"
	.string "préparer leur dîner !$"
