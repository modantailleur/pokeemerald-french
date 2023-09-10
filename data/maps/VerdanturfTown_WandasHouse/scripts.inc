VerdanturfTown_WandasHouse_MapScripts::
	.byte 0

VerdanturfTown_WandasHouse_EventScript_Wally::
	lock
	faceplayer
	goto_if_set FLAG_WALLY_SPEECH, VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeech, MSGBOX_DEFAULT
	setflag FLAG_WALLY_SPEECH
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech::
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeechShort, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff
	msgbox VerdanturfTown_WandasHouse_Text_WallysNextDoor, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff::
	msgbox VerdanturfTown_WandasHouse_Text_WallySlippedOff, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyGoneThatFar, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandasBoyfriend::
	msgbox VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay, MSGBOX_NPC
	end

VerdanturfTown_WandasHouse_EventScript_Wanda::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WandaDontWorry
	goto_if_set FLAG_DEFEATED_WALLY_MAUVILLE, VerdanturfTown_WandasHouse_EventScript_MeetWanda
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_MeetWanda::
	msgbox VerdanturfTown_WandasHouse_Text_MeetWanda, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandaDontWorry::
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAunt::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande
	goto_if_set FLAG_DEFEATED_LAVARIDGE_GYM, VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen::
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened::
	msgbox VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_Text_StrongerSpeech:
	.string "TIMMY : J'ai perdu contre toi,\n"
	.string "{PLAYER}, mais je ne me sens plus\p"
	.string "déprimé. Parce que j'ai un nouveau\n"
	.string "but dans la vie. Avec mes RALTS, je\p"
	.string "vais défier POKéMON GYMS et devenir\n"
	.string "un grand DRESSEUR. S'il vous plaît,\p"
	.string "surveillez-moi, {PLAYER}. Je vais\n"
	.string "être plus fort que toi. Quand je le\p"
	.string "ferai, je vais vous défier dans une\n"
	.string "autre bataille.$"

VerdanturfTown_WandasHouse_Text_StrongerSpeechShort:
	.string "TIMMY : S'il vous plaît,\n"
	.string "surveillez-moi, {PLAYER}. Je vais\p"
	.string "devenir plus fort que toi. Quand je\n"
	.string "le ferai, je vais vous défier dans\p"
	.string "une autre bataille.$"

VerdanturfTown_WandasHouse_Text_WallysNextDoor:
	.string "ONCLE : Oh ! {PLAYER}{KUN} ! TIMMY\n"
	.string "est à côté. Mais mon garçon, il y a\p"
	.string "quelque chose que je dois te dire.\n"
	.string "Cet environnement naturel fait des\p"
	.string "merveilles pour la santé de TIMMY.\n"
	.string "Ce n'est peut-être pas seulement\p"
	.string "l'environnement. Ce pourrait être\n"
	.string "POKéMON qui donne de l'espoir au\p"
	.string "garçon.$"

VerdanturfTown_WandasHouse_Text_WallySlippedOff:
	.string "TIMMY est parti… Il s'est enfui\n"
	.string "tout seul…$"

VerdanturfTown_WandasHouse_Text_WallyGoneThatFar:
	.string "ONCLE : C'est vrai ? TIMMY est\n"
	.string "parti aussi loin tout seul… Eh\p"
	.string "bien, je dois lui reconnaître le\n"
	.string "mérite : c'est le fils de mon petit\p"
	.string "frère.$"

VerdanturfTown_WandasHouse_Text_MeetWanda:
	.string "WANDA : Vous l'êtes ? Oh, c'est\n"
	.string "vrai, je comprends ! Vous êtes le\p"
	.string "{PLAYER} dont TIMMY me parlait. Je\n"
	.string "suis le cousin de TIMMY. Ravie de\p"
	.string "faire ta connaissance! Je pense que\n"
	.string "TIMMY est devenu beaucoup plus\p"
	.string "vivant et en meilleure santé depuis\n"
	.string "qu'il est arrivé ici.$"

VerdanturfTown_WandasHouse_Text_DontWorryAboutWally:
	.string "WANDA : Ne t'inquiète pas pour\n"
	.string "TIMMY. Il ira très bien. Je connais\p"
	.string "mon petit cousin et il a aussi\n"
	.string "POKéMON avec lui.$"

VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay:
	.string "Grâce à toi, je peux voir ma copine\n"
	.string "tous les jours. Heureux? Vous\p"
	.string "pariez que je le suis !$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven:
	.string "Le petit ami de ma fille est une\n"
	.string "personne très motivée et\p"
	.string "passionnée. Il creuse un tunnel\n"
	.string "sans arrêt juste pour pouvoir voir\p"
	.string "ma fille. Ma fille est un peu\n"
	.string "inquiète, alors elle sort souvent\p"
	.string "dans le tunnel.$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging:
	.string "C'est incroyable. Le copain de ma\n"
	.string "fille creusait le tunnel à la main\p"
	.string "! C'est tellement incroyable !$"

VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally:
	.string "Si quelque chose arrivait à TIMMY,\n"
	.string "je ne pourrais jamais regarder ses\p"
	.string "parents à PGUIDOALBURG dans les\n"
	.string "yeux…$"

VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande:
	.string "TIMMY était dans EVER GRANDE ? Ses\n"
	.string "parents à PGUIDOALBURG seraient\p"
	.string "étonnés d'entendre ça !$"
