Route116_TunnelersRestHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_TunnelersRestHouse_OnTransition
	.byte 0

Route116_TunnelersRestHouse_OnTransition:
	setflag FLAG_LANDMARK_TUNNELERS_REST_HOUSE
	end

Route116_TunnelersRestHouse_EventScript_Tunneler1::
	msgbox Route116_TunnelersRestHouse_Text_WeHadToStopBoring, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler2::
	msgbox Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler3::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, Route116_TunnelersRestHouse_EventScript_TunnelOpened
	msgbox Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_EventScript_TunnelOpened::
	msgbox Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_Text_WeHadToStopBoring:
	.string "Ce TUNNEL RUSTURF là-bas… Au début,\n"
	.string "nous avions une énorme équipe de\p"
	.string "travail qui creusait la roche avec\n"
	.string "les dernières machines. Mais il a\p"
	.string "fallu arrêter. Il s’avère que nous\n"
	.string "aurions eu un effet négatif sur les\p"
	.string "POKéMON sauvages de la zone. Donc,\n"
	.string "nous n'avons rien d'autre à faire\p"
	.string "que de flâner ici sans rien faire.$"

Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf:
	.string "Il y a un homme qui se fraye un\n"
	.string "chemin jusqu'à VERGUIDOTURF tout\p"
	.string "seul. Il est désespéré de s'en\n"
	.string "sortir. Il dit que s'il creuse\p"
	.string "petit à petit sans utiliser de\n"
	.string "machines, il ne dérangera pas\p"
	.string "POKéMON et évitera de nuire à\n"
	.string "l'environnement naturel. Je me\p"
	.string "demande s'il a déjà réussi.$"

Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel:
	.string "Pour accéder à VERGUIDOTURF sans\n"
	.string "utiliser ce TUNNEL, il faudrait\p"
	.string "traverser la mer jusqu'à DEWFORD,\n"
	.string "naviguer jusqu'à SLATEPORT, puis\p"
	.string "traverser MAUVILLE.$"

Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough:
	.string "As tu entendu? Le TUNNEL vers\n"
	.string "VERGUIDOTURF est franchi ! Parfois,\p"
	.string "si vous espérez suffisamment, les\n"
	.string "rêves deviennent réalité.$"
