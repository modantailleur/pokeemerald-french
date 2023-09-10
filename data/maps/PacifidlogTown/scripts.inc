PacifidlogTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
	.byte 0

PacifidlogTown_OnTransition:
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	end

PacifidlogTown_OnResume:
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
	end

PacifidlogTown_EventScript_NinjaBoy::
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Girl::
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Fisherman::
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
	end

PacifidlogTown_EventScript_TownSign::
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
	end

PacifidlogTown_Text_FastRunningCurrent:
	.string "La mer entre PACIFIDLOG et\n"
	.string "SLATEPORT a une marée rapide. Si\p"
	.string "vous décidez de SURF, vous pourriez\n"
	.string "vous retrouver emporté ailleurs.$"

PacifidlogTown_Text_NeatHousesOnWater:
	.string "Vous voyez, n'est-ce pas sympa ?\n"
	.string "Ces maisons sont sur l'eau ! Je\p"
	.string "suis né ici!$"

PacifidlogTown_Text_SkyPillarTooScary:
	.string "Le PILIER CELESTE ? …Oh, vous devez\n"
	.string "parler de cette très haute tour un\p"
	.string "peu plus loin. Si vous me le\n"
	.string "demandiez, je ne l'escaladerais\p"
	.string "pas. C'est trop effrayant de monter\n"
	.string "aussi haut. La vie au niveau de la\p"
	.string "mer dans PACIFIDLOG, ça me convient\n"
	.string "bien.$"

PacifidlogTown_Text_TownSign:
	.string "PACIFIVILLE “ Là où le soleil du\n"
	.string "matin sourit sur les eaux. ”$"
