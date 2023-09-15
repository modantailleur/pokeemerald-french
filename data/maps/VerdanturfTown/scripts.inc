.set LOCALID_TWIN, 2

VerdanturfTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
	.byte 0

VerdanturfTown_OnTransition:
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	end

VerdanturfTown_EventScript_Twin::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_TwinTunnelOpen
	msgbox VerdanturfTown_Text_ManTryingToDigTunnel, MSGBOX_DEFAULT
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_TwinTunnelOpen::
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_Man::
	msgbox VerdanturfTown_Text_AirCleanHere, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Camper::
	msgbox VerdanturfTown_Text_MakeBattleTentDebut, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_BoyTunnelOpen
	msgbox VerdanturfTown_Text_GuyTryingToBustThroughCave, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_BoyTunnelOpen::
	msgbox VerdanturfTown_Text_EasyToGetToRustboroNow, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_TownSign::
	msgbox VerdanturfTown_Text_TownSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_WandasHouseSign::
	msgbox VerdanturfTown_Text_WandasHouse, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_BattleTentSign::
	msgbox VerdanturfTown_Text_BattleTentSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_RusturfTunnelSign::
	msgbox VerdanturfTown_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

VerdanturfTown_Text_ManTryingToDigTunnel:
	.string "Mon papa me l'a dit. Il dit que ce\n"
	.string "tunnel est rempli de POKéMON\p"
	.string "timides. Ils ont tous peur du bruit\n"
	.string "et font un grand tumulte. Ils ont\p"
	.string "donc dû arrêter le grand projet de\n"
	.string "tunnel. Mais il y a un homme. Il\p"
	.string "essaie de creuser le tunnel tout\n"
	.string "seul !$"

VerdanturfTown_Text_ManDugTunnelForLove:
	.string "Il y avait un homme qui creusait un\n"
	.string "tunnel pour une femme qu'il aimait.\p"
	.string "Je ne comprends pas vraiment, mais\n"
	.string "bon !$"

VerdanturfTown_Text_AirCleanHere:
	.string "De la manière dont soufflent les\n"
	.string "vents, les cendres volcaniques ne\p"
	.string "sont jamais soufflées dans cette\n"
	.string "direction. L'air est pur et\p"
	.string "délicieux ici. Vivre ici devrait\n"
	.string "faire des merveilles, même pour les\p"
	.string "personnes fragiles et malades.$"

VerdanturfTown_Text_MakeBattleTentDebut:
	.string "Mon POKéMON et moi avons connu une\n"
	.string "superbe séquence de victoires. J'ai\p"
	.string "donc décidé de faire mes débuts\n"
	.string "avec BATTLE TENT dans cette ville.$"

VerdanturfTown_Text_GuyTryingToBustThroughCave:
	.string "Avez-vous vu la grotte à côté du\n"
	.string "POKéMON MART ? Il y a un gars\p"
	.string "là-dedans qui essaie de briser des\n"
	.string "rochers pour pouvoir passer de\p"
	.string "l'autre côté. Ce serait génial si\n"
	.string "nous pouvions passer par là… Cela\p"
	.string "facilitera la visite de RUSTBORO.$"

VerdanturfTown_Text_EasyToGetToRustboroNow:
	.string "Cette grotte à côté du POKéMON MART\n"
	.string "est maintenant un tunnel vers\p"
	.string "l'autre côté. C'est génial : il est\n"
	.string "facile d'aller acheter les nouveaux\p"
	.string "produits DEVON à RUSTBORO\n"
	.string "maintenant.$"

VerdanturfTown_Text_TownSign:
	.string "VERGAZON “ Les hautes\n"
	.string "terres balayées par le vent avec le\p"
	.string "doux parfum de l'herbe. ”$"

VerdanturfTown_Text_WandasHouse:
	.string "MAISON DE WANDA$"

VerdanturfTown_Text_BattleTentSign:
	.string "SITE DE TENTE DE BATAILLE\n"
	.string "VERGUIDOTURF “ Régalez vos yeux des\p"
	.string "batailles ! ”$"

VerdanturfTown_Text_RusturfTunnelSign:
	.string "TUNNEL RUSTURF “ Reliant RUSTBORO\n"
	.string "et VERGUIDOTURF “ Le projet de\p"
	.string "tunnel a été annulé. ”$"
